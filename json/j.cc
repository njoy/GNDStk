
// Code for auto-generating C++ classes from JSON specs.
// Very much a work-in-progress!!

#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

inline const std::string large = "// " + std::string(77,'-');
inline const std::string small = "// " + std::string(24,'-');

inline const std::string directory =
   "/home/kim/xcp5/GNDStk/json/";

inline const std::vector<std::string> files = {
   "gnds.json"
};



// -----------------------------------------------------------------------------
// Functions - miscellaneous
// -----------------------------------------------------------------------------

// className
inline std::string className(const std::string &key)
{
   // capitalize
   std::string ret = key;
   ret[0] = toupper(ret[0]);
   return ret;
}

// GNDSField
inline std::string GNDSField(const std::string &key)
{
   // as-is
   return key;
}

// variableName
inline std::string variableName(const std::string &key)
{
   return key == "double" ? "Double" : key;
}

// read file into json
inline void read(const std::string &file, nlohmann::json &jdoc)
{
   const std::string fullName = directory + file;
   std::cout << "File: \"" << fullName << "\"" << std::endl;

   // read
   std::ifstream ifs(fullName.c_str());
   if (!ifs) {
      log::error("Could not open \"{}\" for input", fullName);
      throw std::exception{};
   }
   ifs >> jdoc;
}



// -----------------------------------------------------------------------------
// Helper constructs for the topological sort
// Adapted from: http://coliru.stacked-crooked.com/a/7c0bf8d3443b804d
// -----------------------------------------------------------------------------

// NameDeps
class NameDeps {
public:
   std::string name;
   std::vector<std::string> dependencies;
};

// VectorNameDeps
using VectorNameDeps = std::vector<NameDeps>;

// insertNDep
void insertNDep(
   const std::string &objectName,
   VectorNameDeps &sourceVec,
   VectorNameDeps &targetVec
) {
   auto iter = std::find_if(
      sourceVec.begin(),
      sourceVec.end(),
      [objectName](const NameDeps &ndep) { return ndep.name == objectName; }
   );

   if (iter != sourceVec.end()) {
      auto ndep = *iter;
      sourceVec.erase(iter);
      for (auto name : ndep.dependencies)
         insertNDep(name, sourceVec, targetVec);
      targetVec.push_back(ndep);
   }
}

// printDepVec
void printDepVec(const std::string &title, const VectorNameDeps &vec)
{
   std::cout << title << std::endl;
   for (const auto &ndep : vec) {
      std::cout << "   " << ndep.name;
      if (ndep.dependencies.size() > 0)
         std::cout << ":";
      for (const auto &dep : ndep.dependencies)
         std::cout << " " << dep;
      std::cout << std::endl;
   }
}



// -----------------------------------------------------------------------------
// check_*
// -----------------------------------------------------------------------------

// check_class
inline void check_class(const nlohmann::json &value, const std::string &key)
{
   (void)key; // std::cout << "Key: " << key << std::endl;

   // each "class" should contain these items
   assert(value.size() == 6 || value.size() == 7);
   assert(value.contains("namespace"));
   assert(value.contains("description"));
   assert(value.contains("attributes"));
   assert(value.contains("childNodes"));
   assert(value.contains("bodyText"));
   assert(value.contains("rootNode"));

   // I'm not sure if/when we'll need this, but it seems perhaps important
   if (value.size() == 7)
      assert(value.contains("childUnique"));
}

// check_metadata
inline void check_metadata(const nlohmann::json &attrs)
{
   for (const auto &field : attrs.items()) {
      // each attribute should contain these items
      assert(field.value().size() == 4);
      assert(field.value().contains("type"));
      assert(field.value().contains("description"));
      assert(field.value().contains("required"));
      assert(field.value().contains("default"));
   }
}

// check_children
inline void check_children(const nlohmann::json &elems)
{
   for (const auto &field : elems.items()) {
      // each child node should contain these items
      assert(field.value().size() == 4);
      assert(field.value().contains("namespace"));
      assert(field.value().contains("description"));
      assert(field.value().contains("occurrence"));
      assert(field.value().contains("required"));

      // consistency check
      const std::string occur = field.value()["occurrence"];
      if (occur == "0+" || occur == "choice" || occur == "choice2")
         assert(!field.value()["required"]);
   }
}



// -----------------------------------------------------------------------------
// Functions - for output
// -----------------------------------------------------------------------------

// ------------------------
// re: output file
// ------------------------

// write_file_prefix
inline void write_file_prefix(std::ostream &os)
{
   os << "\n"
      << "#include \"GNDStk.hpp\"\n"
      << "using namespace njoy::GNDStk::core;\n"
      << "\n"
      << "namespace v_1_9 {\n\n" << std::endl;
}

// write_file_suffix
inline void write_file_suffix(std::ostream &os)
{
   os << "\n"
      << "} // namespace v_1_9\n"
      << "\n\n\n"
      << large << "\n"
      << "// main\n"
      << large << "\n"
      << "\n"
      << "int main()\n"
      << "{\n"
      << "}" << std::endl;
}


// ------------------------
// re: class
// ------------------------

// write_class_prefix
inline void write_class_prefix(
   std::ostream &os,
   const std::string &clname,
   const std::string &nsname
) {
   os << "\n\n\n"
      << large << "\n"
      << "// " << nsname << "::\n"
      << "// class " << clname << "\n"
      << large << "\n"
      << "\n"
      << "namespace " << nsname << " {\n\n"
      << "class " << clname << " : public Component<" << clname << "> {\n"
      << "public:" << std::endl;
}

// write_class_suffix
inline void write_class_suffix(
   std::ostream &os,
   const std::string &clname,
   const std::string &nsname
) {
   os << "\n   " << small;
   os << "\n   // assignment: copy, move";
   os << "\n   " << small << "\n";
   os << "\n   " << clname << " &operator=(const " << clname << " &) = default;";
   os << "\n   " << clname << " &operator=(" << clname << " &&) = default;\n";
   os << "\n}; // class " << clname << "\n";
   os << "\n} // namespace " << nsname << std::endl;
}



// -----------------------------------------------------------------------------
// Helpers - for class content
// -----------------------------------------------------------------------------

// infoMetadata
class infoMetadata {
public:
   std::string fullVarType;
   std::string varType;
   std::string varName;
   bool        hasDefault;
   std::string theDefault;
};

// infoChildren
class infoChildren {
public:
   std::string fullVarType;
   std::string halfVarType;
   std::string varType;
   std::string varName;
   bool        isVector;
};



// -----------------------------------------------------------------------------
// Functions - for class content
// -----------------------------------------------------------------------------

// names and keys for the Component base
inline void write_keys(
   std::ostream &os,
   const std::string &key,
   std::vector<infoMetadata> &vecInfoMetadata,
   std::vector<infoChildren> &vecInfoChildren
) {
   // names
   const std::string name = className(key);
   const std::string gnds = GNDSField(key);

   os << "\n   " << small << "\n";
   os << "   // for Component";
   os << "\n   " << small << "\n\n";
   os << "   static auto className() { return \"" << name << "\"; }\n";
   os << "   static auto GNDSField() { return \"" << gnds << "\"; }\n";

   // keys begin
   os << "   static auto keys()\n";
   os << "   {\n";

   // keys
   const auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   if (total == 0)
      os << "      return std::tuple<>{};\n";
   else {
      // begin
      os << "      return\n";
      std::size_t count = 0;

      // keys for metadata
      //    std::string fullVarType;
      //    std::string varType;
      //    std::string varName;
      //    bool        hasDefault;
      //    std::string theDefault;
      for (const auto &m : vecInfoMetadata) {
         os << "         ";
         os << m.fullVarType << "{";
         os << m.theDefault;
         os << "} / basic::meta::"
            << m.varName;
         os << (++count < total ? " |\n" : "\n");
      }

      // keys for children
      //    std::string fullVarType;
      //    std::string halfVarType;
      //    std::string varType;
      //    std::string varName;
      //    bool        isVector;
      for (const auto &c : vecInfoChildren) {
         os << "         ";
         os << c.halfVarType << "{";
         // doesn't exist now in infoChildren; may or may not ever be needed...
         ///os << c.theDefault;
         os << "} / " << (c.isVector ? "++" : "--") << "basic::child::"
            << c.varName;
         os << (++count < total ? " |\n" : "\n");
      }

      // end
      os << "      ;\n";
   }

   // keys end
   os << "   }\n";
}


// write_metadata
inline void write_metadata(
   std::ostream &os,
   const nlohmann::json &attrs,
   std::vector<infoMetadata> &vecInfoMetadata
) {
   os << "\n   // metadata\n";
   for (const auto &field : attrs.items()) {

      // has default?
      const bool hasDefault = !field.value()["default"].is_null();
      if (hasDefault)
         assert(!field.value()["required"]);

      // optional?
      const bool opt = !field.value()["required"] && !hasDefault;
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // defaulted? (optional with default)
      const bool def = !field.value()["required"] && hasDefault;
      const std::string defPrefix = def ? "Defaulted<" : "";
      const std::string defSuffix = def ? ">" : "";

      // type, name
      std::string varType = field.value()["type"];
      if (varType == "interpolation")
         varType = "interpolation_t";
      const std::string fullVarType =
         optPrefix + defPrefix + varType +
         defSuffix + optSuffix;
      const std::string varName = variableName(field.key());

      // write
      os << "   " << fullVarType << " " << varName << ";" << std::endl;

      // vecInfoMetadata
      vecInfoMetadata.push_back(infoMetadata{});
      vecInfoMetadata.back().fullVarType = fullVarType;
      vecInfoMetadata.back().varType     = varType;
      vecInfoMetadata.back().varName     = varName;
      vecInfoMetadata.back().hasDefault  = hasDefault;
      vecInfoMetadata.back().theDefault  = hasDefault
         ? field.value()["default"]
         : "";
   }
}


// write_children
inline void write_children(
   std::ostream &os,
   const nlohmann::json &elems,
   std::vector<infoChildren> &vecInfoChildren,
   const std::string &clname, NameDeps &ndep
) {
   os << "\n   // children\n";
   for (const auto &field : elems.items()) {

      // optional?
      const bool opt = !field.value()["required"];
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // vector?
      const std::string occur = field.value()["occurrence"];
      const bool vec = occur == "0+" || occur == "1+" || occur == "2+";
      const std::string vecPrefix = vec ? "std::vector<" : "";
      const std::string vecSuffix = vec ? ">" : "";

      // type, name
      const std::string varType =
         std::string(field.value()["namespace"]) + "::" +
         className(field.key());
      const std::string fullVarType =
         optPrefix + vecPrefix + varType +
         vecSuffix + optSuffix;
      const std::string halfVarType = // w/o any std::vector
         optPrefix + varType +
         optSuffix;
      const std::string varName = variableName(field.key());

      // write
      os << "   " << fullVarType << " " << varName << ";" << std::endl;

      // zzz
      // save dependency
      if (varType != clname  // not its own dependency
          ///&& vecPrefix == "" // or else incomplete type is allowable
      )
         ndep.dependencies.push_back(varType);

      // vecInfoChildren
      vecInfoChildren.push_back(infoChildren{});
      vecInfoChildren.back().fullVarType = fullVarType;
      vecInfoChildren.back().halfVarType = halfVarType;
      vecInfoChildren.back().varType     = varType;
      vecInfoChildren.back().varName     = varName;
      vecInfoChildren.back().isVector    = vec;
   }
}


// write_class_ctor
inline void write_class_ctor(
   std::ostream &os,
   const std::string &clname,
   std::vector<infoMetadata> &vecInfoMetadata,
   std::vector<infoChildren> &vecInfoChildren
) {
   // keys for metadata
   //    std::string fullVarType;
   //    std::string varType;
   //    std::string varName;
   //    bool        hasDefault;
   //    std::string theDefault;

   // keys for children
   //    std::string fullVarType;
   //    std::string halfVarType;
   //    std::string varType;
   //    std::string varName;
   //    bool        isVector;

   const auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   std::size_t count;

   // ------------------------
   // ctor: default
   // ------------------------

   os << "\n";
   os << "   // default\n";
   os << "   " << clname << "() :\n";

   // base constructor call
   os << "      Component(\n";
   count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "         this->" << m.varName
         << (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "         this->" << c.varName
         << (++count < total ? ",\n" : "\n");
   os << "      )";

   // these need initialization
   for (const auto &m : vecInfoMetadata)
      if (m.hasDefault)
         os << ",\n      " << m.varName << "(" << m.theDefault << ")";

   os << "\n";
   os << "   {\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: copy
   // ------------------------

   // signature
   os << "   // copy\n";
   os << "   " << clname << "(const " << clname << " &other) :\n";

   // base constructor call
   os << "      Component(\n";
   count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "         this->" << m.varName
         << (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "         this->" << c.varName
         << (++count < total ? ",\n" : "\n");
   os << "      ),\n";

   // fields
   count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "      " << m.varName << "(other." << m.varName << ")"
         << (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "      " << c.varName << "(other." << c.varName << ")"
         << (++count < total ? ",\n" : "\n");
   os << "   {\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: node
   // ------------------------

   os << "   // node\n";
   os << "   " << clname << "(const Node &node) :\n";
   os << "      " << clname << "()\n";
   os << "   {\n";
   os << "      query(node);\n";
   os << "   }\n";

   // ------------------------
   // ctor: fields
   // ------------------------

   if (total > 0) {
      os << "\n";
      os << "   // fields\n";

      // signature
      count = 0;
      os << "   explicit " << clname << "(\n";
      for (const auto &m : vecInfoMetadata)
         os << "      const " << m.fullVarType << " &" << m.varName
            << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "      const " << c.fullVarType << " &" << c.varName
            << (++count < total ? ",\n" : "\n");
      os << "   ) :\n";

      // base constructor call
      os << "      Component(\n";
      count = 0;
      for (const auto &m : vecInfoMetadata)
         os << "         this->" << m.varName
            << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "         this->" << c.varName
            << (++count < total ? ",\n" : "\n");
      os << "      ),\n";

      // fields
      count = 0;
      for (const auto &m : vecInfoMetadata)
         os << "      " << m.varName << "(" << m.varName << ")"
            << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "      " << c.varName << "(" << c.varName << ")"
            << (++count < total ? ",\n" : "\n");

      // body
      os << "   {\n";
      os << "   }\n";
   }
}



// -----------------------------------------------------------------------------
// make_forward
// -----------------------------------------------------------------------------

template<class J>
void make_forward(std::ostream &os, const J &theclass)
{
   const auto key   = theclass.key();
   const auto value = theclass.value();

   assert(value.contains("namespace"));
   const std::string clname = className(key);
   const std::string nsname = value["namespace"];

   os << "namespace " << nsname << " { class " << clname << "; }\n";
}



// -----------------------------------------------------------------------------
// make_class
// -----------------------------------------------------------------------------

// For dependencies: (1) The dependencies themselves. (2) A map from class names
// to their printed code. We compute these pairs first, so that we can print the
// code for each class later - after a dependency-aware ordering is computed.
inline VectorNameDeps classDependencies;
inline std::map<std::string,std::string> classMap;

// make_class
template<class J>
void make_class(const J &theclass)
{
   const auto key   = theclass.key();
   const auto value = theclass.value();
   check_class(value,key);

   const std::string clname = className(key);
   const std::string nsname = value["namespace"];

   // re: ordering
   classDependencies.push_back(NameDeps{});
   auto &last = classDependencies.back();
   last.name = nsname + "::" + clname;

   // class begin
   std::ostringstream oss;
   write_class_prefix(oss, clname, nsname);
   const auto attrs = value["attributes"];
   const auto elems = value["childNodes"];
   check_metadata(attrs);
   check_children(elems);

   std::vector<infoMetadata> vecInfoMetadata;
   std::vector<infoChildren> vecInfoChildren;

   // metadata
   std::ostringstream ossm;
   if (attrs.size() != 0)
      write_metadata(ossm, attrs, vecInfoMetadata);

   // children
   std::ostringstream ossc;
   if (elems.size() != 0)
      write_children(ossc, elems, vecInfoChildren, clname, last);

   // names, keys
   // As needed by the Component base
   write_keys(oss, key, vecInfoMetadata, vecInfoChildren);

   // metadata/children computed earlier
   if (attrs.size() != 0 || elems.size() != 0)
      oss << "\n   " << small
          << "\n   // fields"
          << "\n   " << small
          << "\n";
   oss << ossm.str();
   oss << ossc.str();

   // constructors
   oss << "\n   " << small
       << "\n   // constructors"
       << "\n   " << small
       << "\n";
   write_class_ctor(oss, clname, vecInfoMetadata, vecInfoChildren);

   // class end
   write_class_suffix(oss, clname, nsname);

   // save content
   assert(classMap.insert(std::make_pair(last.name,oss.str())).second);
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main()
{
   // output file begin
   std::ofstream ofs("out.cc");
   write_file_prefix(ofs);

   // json files
   nlohmann::json jdoc;
   for (auto &file : files) {

      // read
      read(file,jdoc);

      // forward declarations of classes; some need others
      ofs << "\n" << large << "\n";
      ofs << "// Forward declarations\n";
      ofs << large << "\n\n";
      for (const auto &theclass : jdoc.items())
         make_forward(ofs,theclass);

      // classes
      for (const auto &theclass : jdoc.items())
         make_class(theclass);
      //printDepVec("OLD", classDependencies);

      // compute an ordering that respects dependencies
      VectorNameDeps sortedClassDependencies;
      while (classDependencies.size() > 0)
         insertNDep((*classDependencies.begin()).name,
                    classDependencies, sortedClassDependencies);

      // print dependencies
      printDepVec("NEW", sortedClassDependencies);

      // print classes, using the computed ordering
      for (auto &obj : sortedClassDependencies) {
         auto iter = classMap.find(obj.name);
         assert(iter != classMap.end());
         ofs << iter->second;
      }
   }

   // output file end
   write_file_suffix(ofs);
}
