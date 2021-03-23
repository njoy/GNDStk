
// Code for auto-generating C++ classes from JSON specs.
// Very much a work-in-progress!

#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

inline const std::string large = "// " + std::string(77,'-');
inline const std::string small = "// " + std::string(24,'-');

/*
inline const std::string directory =
   "/home/kim/xcp5/gnds/";

inline const std::vector<std::string> files = {
   "rs-gpdc.json",
   "rs-transport.json"
};
*/

inline const std::string directory =
   "/home/kim/xcp5/GNDStk/json/summary/";

inline const std::vector<std::string> files = {
   "summary_abstract.json",
   "summary_appData.json",
   "summary_atomic.json",
   ///"summary_basic.json",
   "summary_common.json",
   "summary_covariance.json",
   "summary_cpTransport.json",
   "summary_documentation.json",
   "summary_fissionTransport.json",
   "summary_fpy.json",
   "summary_gpdc.json",
   "summary_pops.json",
   "summary_processed.json",
   "summary_resonance.json",
   "summary_styles.json",
   "summary_transport.json",
   "summary_tsl.json"
};

inline const bool debugging = true;



// -----------------------------------------------------------------------------
// Changes we must apply...
// -----------------------------------------------------------------------------

// In view of some of the comments below, we should probably have a combined
// map that looks at "type" and "default" (in the JSON) simultaneously, as
// well as possibly the name of the metadatum in question.

// to "type"
inline const std::map<std::string,std::string> mapType {
   { "interpolation", "interpolation_t" },
   { "encoding",      "encoding_t" },
   { "frame",         "frame_t" },
   { "Boolean",       "bool" },

   { "", "" }
};


// Note: for the following:
//    "style": {
//        ...
//        "type": "UTF8Text"
//    }
// the description says: "...Allowed values are `none', `points', `boundaries'
// and `parameters'." The given type, as we see, is however UTF8Text. Perhaps
// we should give GNDStk a style enum, and then map UTF8Text to the enum - BUT
// only in the context of the "style" attribute. UTF8Text should probably stay
// UTF8Text in most contexts. Or, there may be other places (with UTF8Text, or
// with other string-like things) where we should similarly change things up.
// Probable examples: "compresson", "markup". Let's see how things hash out.


// to "default"
inline const std::map<std::string,std::string> mapDefault {

   { "ascii", "encoding_t::ascii" },
   { "utf8",  "encoding_t::utf8" },

   { "flat",             "interpolation_t::flat" },
   { "charged-particle", "interpolation_t::charged_particle" },
   { "lin-lin",          "interpolation_t::lin_lin" },
   { "lin-log",          "interpolation_t::lin_log" },
   { "log-lin",          "interpolation_t::log_lin" },
   { "log-log",          "interpolation_t::log_log" },
   { "\\\\attr{lin-lin}",  "interpolation_t::lin_lin" }, // :-/

   { "row-major",        "storage_order_t::row_major" },
   { "column-major",     "storage_order_t::column_major" },

   { "lab",              "frame_t::lab" },
   { "centerOfMass",     "frame_t::centerOfMass" },

   // The JSONs have some strange stuff. Perhaps some of this has utility
   // for the processing of the JSONs into the user manual, but still...
   { "`' (i.e. unitless)", "" }, // what's the `' all about?
   { " \\\\kern-1ex",        "" }, // note the leading space :-/
   { "`' (no label)",      "" }, // so, map to no label
   { "`none'",         "none" }, // lose the `' (perhaps do these generically?)

   { "", "" }
};



// -----------------------------------------------------------------------------
// Functions: general
// -----------------------------------------------------------------------------

// metaType
inline std::string metaType(const std::string &name)
{
   const auto iter = mapType.find(name);
   if (iter != mapType.end())
      return iter->second;
   return name;
}

// className
/// I think this also serves the purpose of "childName"; work on terminology
template<class JSON>
std::string className(const JSON &keyvalue)
{
   // capitalize, per our class naming convention
   assert(keyvalue.value().contains("name"));
   std::string name = keyvalue.value()["name"];
   name[0] = toupper(name[0]);
   return name;
}

// GNDSField
template<class JSON>
std::string GNDSField(const JSON &keyvalue)
{
   // as-is; appears in GNDS files like this
   assert(keyvalue.value().contains("name"));
   std::string name = keyvalue.value()["name"];
   return name;
}

// variableName
template<class JSON>
std::string variableName(const JSON &keyvalue)
{
   // as-is for local data member that corresponds to a GNDS node
   // or metadata name, except that we *must* rename double :-/
   assert(keyvalue.value().contains("name"));
   std::string name = keyvalue.value()["name"];
   if (name == "double")
      return "Double";
   return name;
}



// -----------------------------------------------------------------------------
// Helper constructs for a topological sort
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
   const auto iter = std::find_if(
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
void check_class(const std::string &key, const nlohmann::json &value)
{
   if (debugging)
      std::cout << "Key: " << key << std::endl;

   // each "class" should contain these...
   assert(value.contains("attributes"));
   assert(value.contains("childNodes"));
   assert(value.contains("name"));
}

// check_metadata
void check_metadata(const nlohmann::json &attrs)
{
   for (const auto &field : attrs.items()) {
      if (debugging)
         std::cout << "   Metadatum: " << field.key() << std::endl;

      // each attribute should contain these...
      assert(field.value().contains("default"));
      assert(field.value().contains("name"));
      assert(field.value().contains("required"));
      assert(field.value().contains("type"));
   }
}

// check_children
void check_children(const nlohmann::json &elems)
{
   for (const auto &field : elems.items()) {
      if (debugging)
         std::cout << "   Child Node: " << field.key() << std::endl;

      // each child node should contain these...
      assert(field.value().contains("name"));
      assert(field.value().contains("occurrence"));
      assert(field.value().contains("required"));

      // consistency check
      const std::string occur = field.value()["occurrence"];
      if (occur == "0+" ||
          occur == "choice" ||
          occur == "choice2" ||
          occur == "choice2+")
         assert(!field.value()["required"]); // then not required
   }
}



// -----------------------------------------------------------------------------
// Functions: for output
// -----------------------------------------------------------------------------

// ------------------------
// re: output file
// ------------------------

// write_file_prefix
void write_file_prefix(std::ostream &os)
{
   os << "\n"
      << "#include \"GNDStk.hpp\"\n"
      << "using namespace njoy::GNDStk::core;\n"
      << "\n"
      << "namespace v_1_9 {\n\n" << std::endl;
}

// write_file_suffix
void write_file_suffix(std::ostream &os)
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
void write_class_prefix(
   std::ostream &os,
   const std::string &file_namespace, const std::string &clname
) {
   os << "\n\n\n"
      << large << "\n"
      << "// " << file_namespace << "::\n"
      << "// class " << clname << "\n"
      << large << "\n"
      << "\n"
      << "namespace " << file_namespace << " {\n\n"
      << "class " << clname << " : public Component<" << clname << "> {"
      << std::endl;
}

// write_class_suffix
void write_class_suffix(
   std::ostream &os,
   const std::string &file_namespace, const std::string &clname
) {
   os << "\n   " << small;
   os << "\n   // assignment: copy, move";
   os << "\n   " << small << "\n";
   os << "\n   " << clname << " &operator=(const " << clname << " &) = default;";
   os << "\n   " << clname << " &operator=(" << clname << " &&) = default;\n";

   os << "\n   " << small;
   os << "\n   // custom functionality";
   os << "\n   " << small << "\n";
   os << "\n   #include \"" << file_namespace << "-" << clname << ".hpp\"\n";

   os << "\n}; // class " << clname << "\n";
   os << "\n} // namespace " << file_namespace << std::endl;
}



// -----------------------------------------------------------------------------
// Helpers: for class content
// -----------------------------------------------------------------------------

// infoMetadata
class infoMetadata {
public:
   std::string fullVarType; // with any optional<>, defaulted<>, vector<>
   std::string varType;     // underlying type
   std::string varName;
   bool        hasDefault;
   std::string theDefault;
};

// infoChildren
class infoChildren {
public:
   std::string fullVarType; // with any optional<>, defaulted<>, vector<>
   std::string halfVarType; // withOUT any vector<>
   std::string varType;     // underlying type
   std::string varName;
   bool        isVector;
};



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Functions: for class content
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// write_keys
// -----------------------------------------------------------------------------

// names and keys for the Component base
template<class JSON>
void write_keys(
   std::ostream &os,
   const JSON &keyvalue,
   const std::string &clname,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   const std::string key = keyvalue.key();

   // names
   const std::string name = className(keyvalue);
   const std::string gnds = GNDSField(keyvalue);

   os << "\n";
   os << "   " << small << "\n";
   os << "   // for Component";
   os << "\n";
   os << "   " << small << "\n\n";
   os << "   friend class Component<" << clname << ">;\n\n";
   os << "   static auto className() { return \"" << name << "\"; }\n";
   os << "   static auto GNDSField() { return \"" << gnds << "\"; }\n";

   // keys begin
   os << "   static auto keys()\n";
   os << "   {\n";

   // keys
   const auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   if (total == 0) {
      os << "      return std::tuple<>{};\n";
   } else {
      // begin
      os << "      return\n";
      std::size_t count = 0;

      // metadata
      if (vecInfoMetadata.size())
         os << "         // metadata\n";
      for (const auto &m : vecInfoMetadata) {
         os << "         ";
         os << m.fullVarType << "{";
         os << m.theDefault;
         os << "}\n            / ";
         os << "Meta<>(\"" << m.varName << "\")";
         os << (++count < total ? " |\n" : "\n");
      }

      // children
      if (vecInfoChildren.size())
         os << "         // children\n";
      for (const auto &c : vecInfoChildren) {
         os << "         ";
         os << c.halfVarType << "{"; // halfVarType: w/o any std::vector<>
         os << "}\n            / " << (c.isVector ? "++" : "--");
         os << "Child<>(\"" << c.varName << "\")";
         os << (++count < total ? " |\n" : "\n");
      }

      // end
      os << "      ;\n";
   }

   // keys end
   os << "   }\n\n";
   os << "public:\n";
}



// -----------------------------------------------------------------------------
// write_metadata
// Also *computes* entries in vecInfoMetadata
// -----------------------------------------------------------------------------

// helper
// see: https://github.com/nlohmann/json/issues/642
inline std::string to_string(const nlohmann::json &j)
{
   auto tmp = j.dump();

   if (j.type() == nlohmann::json::value_t::string) {
      return tmp.substr(1, tmp.size()-2);
   } else {
      return tmp;
   }
}

void write_metadata(
   std::ostream &ossm, // in caller, is a temporary ostringstream
   const nlohmann::json &attrs,
   std::vector<infoMetadata> &vecInfoMetadata // output
) {
   // here, we're within the section for raw GNDS content
   ossm << "\n      // metadata\n";
   for (const auto &field : attrs.items()) {

      /**/
      /**/
      /**/
      // re: default?
      ///const bool hasDefault = !field.value()["default"].is_null();
      std::string theDefault;
      if (field.value()["default"].is_null())
         theDefault = "";
      else {
         theDefault = to_string(field.value()["default"]);
         std::cout << "theDefault: \"" << theDefault << '"' << std::endl;
         const auto iter = mapDefault.find(theDefault);
         if (iter != mapDefault.end()) {
            std::cout << "found" << std::endl;
            theDefault = iter->second;
         } else {
            std::cout << "not found" << std::endl;
         }
      };

      const bool hasDefault = theDefault != "";
      if (hasDefault) {
         // I think this is always the case; if not, we can remove the assert
         std::cout << "theDefault: \"" << theDefault << '"' << std::endl;
         assert(!field.value()["required"]);
      }
      /**/
      /**/
      /**/

      // optional? (but use defaulted, below, if it has a default)
      const bool opt = !field.value()["required"] && !hasDefault;
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // defaulted? (optional with default)
      const bool def = !field.value()["required"] && hasDefault;
      const std::string defPrefix = def ? "Defaulted<" : "";
      const std::string defSuffix = def ? ">" : "";

      // type
      const std::string varType = metaType(field.value()["type"]);

      // full type (with optional/defaulted)
      const std::string fullVarType =
         optPrefix + defPrefix +
         varType +
         defSuffix + optSuffix;

      // name
      const std::string varName = variableName(field);

      // write
      ossm << "      " << fullVarType << " " << varName << ";" << std::endl;

      // add to vecInfoMetadata, which is used later
      vecInfoMetadata.push_back(infoMetadata{});

      vecInfoMetadata.back().fullVarType = fullVarType;
      vecInfoMetadata.back().varType     = varType;
      vecInfoMetadata.back().varName     = varName;
      vecInfoMetadata.back().hasDefault  = hasDefault;

      /**/
      /**/
      /*
      std::string theDefault = hasDefault
         ? to_string(field.value()["default"])
         : "";
      {
         const auto iter = mapDefault.find(theDefault);
         if (iter != mapDefault.end())
            theDefault = iter->second;
      }
      */
      vecInfoMetadata.back().theDefault = theDefault;
      /**/
      /**/
      /**/
   }
}



// -----------------------------------------------------------------------------
// write_children
// Also *computes* entries in vecInfoChildren
// -----------------------------------------------------------------------------

void write_children(
   std::ostream &ossc, // in caller, is a temporary ostringstream
   const nlohmann::json &elems,
   std::vector<infoChildren> &vecInfoChildren, // output
   const std::string &file_namespace, const std::string &clname,
   NameDeps &ndep,
   const std::multimap<std::string,std::string> &class2nspace
) {
   // here, we're within the section for raw GNDS content
   ossc << "\n      // children\n";
   for (const auto &field : elems.items()) {

      // optional?
      const bool opt = !field.value()["required"];
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // vector?
      const std::string occur = field.value()["occurrence"];
      const bool vec =
         occur == "0+" ||
         occur == "1+" ||
         occur == "2+" ||
         occur == "choice2+";
      const std::string vecPrefix = vec ? "std::vector<" : "";
      const std::string vecSuffix = vec ? ">" : "";

      // type
      std::string varType = className(field);
      {
         std::string ns;
         const auto value = field.value();

         // determine what namespace it belongs in
         assert(!( value.contains(  "namespace"  ) &&
                   value.contains("__namespace__") ));

         if (value.contains("namespace"))
            ns = value["namespace"];
         else if (value.contains("__namespace__"))
            ns = value["__namespace__"];
         else {

            /*
    for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
      std::cout << ' ' << (*it).second;
            */

            if (class2nspace.count(clname) == 1)
               ns = class2nspace.find(clname)->second;
            else {
               bool found = false;
               for (auto it = class2nspace.equal_range(clname).first;
                    it != class2nspace.equal_range(clname).second;  ++it
               ) {
                  if ((*it).second == file_namespace) {
                     ns = file_namespace;
                     found = true;
                  }
               }
               if (!found)
                  ns = "zzz";
            }
         }
         varType = ns + "::" + varType;
         ///varType = std::string(field.value()["namespace"]) + "::" + varType;
      }

      /*
      const std::string varType = metaType(field.value()["type"]);
      /// remove this c++ block comment
      const std::string varName = variableName(field);
      */

      // full type (with optional/defaulted)
      const std::string fullVarType =
         optPrefix + vecPrefix +
         varType +
         vecSuffix + optSuffix;

      // partial type - without any std::vector<>
      const std::string halfVarType =
         optPrefix +
         varType +
         optSuffix;

      // name
      const std::string varName = variableName(field);

      // write
      ossc << "      " << fullVarType << " " << varName << ";" << std::endl;

      // save dependency
      if (varType != clname  // not its own dependency
          ///&& vecPrefix == "" // or else an incomplete type is allowable
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



// -----------------------------------------------------------------------------
// write_class_getset
// -----------------------------------------------------------------------------

void write_class_getset(
   std::ostream &os,
   std::vector<infoMetadata> &vecInfoMetadata,
   std::vector<infoChildren> &vecInfoChildren
) {
   const auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   if (total == 0)
      return;

   for (const auto &m : vecInfoMetadata) {
      os << "\n";
      os << "   // " << m.varName << "\n";
      os << "   const auto &" << m.varName << "() const\n";
      os << "    { return content." << m.varName << "; }\n\n";
      os << "   const auto &" << m.varName;
      os << "(const " << m.fullVarType << " &obj)\n";
      os << "    { return content." << m.varName << " = obj; }\n";
   }

   for (const auto &c : vecInfoChildren) {
      os << "\n";
      os << "   // " << c.varName << "\n";
      os << "   const auto &" << c.varName << "() const\n";
      os << "    { return content." << c.varName << "; }\n\n";
      os << "   const auto &" << c.varName;
      os << "(const " << c.fullVarType << " &obj)\n";
      os << "    { return content." << c.varName << " = obj; }\n";
   }
}



// -----------------------------------------------------------------------------
// write_class_ctor
// -----------------------------------------------------------------------------

void write_class_ctor(
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
   os << "      Component{\n";
   count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "         content." << m.varName
         << (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "         content." << c.varName
         << (++count < total ? ",\n" : "\n");
   os << "      }";

   // these need initialization
   for (const auto &m : vecInfoMetadata)
      if (m.hasDefault)
         os << ",\n      " << m.varName << "(" << m.theDefault << ")";

   os << "\n";
   os << "   {\n";
   os << "      Component::construct();\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: copy
   // ------------------------

   // signature
   os << "   // copy\n";
   os << "   " << clname << "(const " << clname << " &other) :\n";

   // base constructor call
   os << "      Component{\n";
   count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "         content." << m.varName
         << (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "         content." << c.varName
         << (++count < total ? ",\n" : "\n");
   os << "      }";

   // fields
   os << (total ? ",\n      content{other.content}\n" : "\n");
   os << "   {\n";
   os << "      Component::construct();\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: node
   // ------------------------

   os << "   // node\n";
   os << "   " << clname << "(const Node &node) :\n";
   os << "      " << clname << "{}\n";
   os << "   {\n";
   os << "      Component::query(node);\n";
   os << "      Component::construct();\n";
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
      os << "      Component{\n";
      count = 0;
      for (const auto &m : vecInfoMetadata)
         os << "         content." << m.varName
            << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "         content." << c.varName
            << (++count < total ? ",\n" : "\n");
      os << "      }";

      // fields
      if (total) {
         os << ",\n";
         os << "      content{\n";
         count = 0;
         for (const auto &m : vecInfoMetadata)
            os << "         " << m.varName << (++count < total ? ",\n" : "\n");
         for (const auto &c : vecInfoChildren)
            os << "         " << c.varName << (++count < total ? ",\n" : "\n");
         os << "      }\n";
      } else {
         os << "\n";
      }

      // body
      os << "   {\n";
      os << "      Component::construct();\n";
      os << "   }\n";
   }
}



// -----------------------------------------------------------------------------
// make_forward
// Receives each key/value pair in the outer {...} json level
// -----------------------------------------------------------------------------

// class2nspace;
inline std::multimap<std::string,std::string> class2nspace;


// make_forward
template<class JSON>
void make_forward(
   std::ostream &os,
   const std::string &file_namespace, // value of "__namespace__" in the file
   const JSON &keyvalue
) {
   const auto key = keyvalue.key();
   if (key == "__namespace__") {
      // not a class
      return;
   }

   const auto value = keyvalue.value();
   if (value["__class__"] != "nodes.Node") {
      // not a node class
      return;
   }

   // namespace for this class
   const std::string nsname = file_namespace;
   /*
   // usually file_namespace, but we allow override
   assert(!(value.contains("namespace")) && value.contains("__namespace__"))));
   if (value.contains(  "namespace"  )) nsname = value[  "namespace"  ];
   if (value.contains("__namespace__")) nsname = value["__namespace__"];
   */

   // class name for this class
   const std::string clname = className(keyvalue);

   // write a forward declaration
   os << "namespace " << nsname << " { class " << clname << "; }\n";

   // for future use: map class to namespace(s) in which it's found
   class2nspace.insert(std::make_pair(clname,nsname));
}



// -----------------------------------------------------------------------------
// make_class
// -----------------------------------------------------------------------------

// For dependencies: (1) The dependencies themselves. (2) A map from class names
// to their printed code. We compute these pairs first, so that we can print the
// code for each class later - after a dependency-aware ordering is computed.
inline VectorNameDeps classDependencies;
inline VectorNameDeps sortedClassDependencies;
inline std::map<std::string,std::string> classMap;


// make_class
template<class JSON>
void make_class(
   const JSON &keyvalue,
   const std::string &file_namespace,
   const std::multimap<std::string,std::string> &class2nspace
) {
   const auto key = keyvalue.key();
   if (key == "__namespace__") {
      // not a class
      return;
   }

   const auto value = keyvalue.value();
   if (value["__class__"] != "nodes.Node") {
      // not a node class
      return;
   }

   if (debugging)
      std::cout << "Class: " << className(keyvalue) << std::endl;

   check_class(key,value);
   const std::string clname = className(keyvalue);

   // re: ordering
   classDependencies.push_back(NameDeps{});
   auto &ndep = classDependencies.back();
   ndep.name = file_namespace + "::" + clname;

   // class begin
   std::ostringstream oss;
   write_class_prefix(oss, file_namespace, clname);
   const auto attrs = value["attributes"];
   const auto elems = value["childNodes"];

   check_metadata(attrs);
   check_children(elems);

   // metadata
   std::vector<infoMetadata> vecInfoMetadata;
   std::ostringstream ossm;
   if (attrs.size() != 0)
      write_metadata(ossm, attrs, vecInfoMetadata);

   // children
   std::vector<infoChildren> vecInfoChildren;
   std::ostringstream ossc;
   if (elems.size() != 0)
      write_children(
         ossc, elems, vecInfoChildren,
         file_namespace, clname, ndep,
         class2nspace
      );

   // names, keys
   // As needed by the Component base
   write_keys(oss, keyvalue, clname, vecInfoMetadata, vecInfoChildren);

   // metadata/children (computed earlier)
   if (attrs.size() != 0 || elems.size() != 0) {
      oss << "\n   " << small
          << "\n   // raw GNDS content"
          << "\n   " << small
          << "\n"
          << "\n   struct {"
          << ossm.str()
          << ossc.str()
          << "   } content;\n";
   }

   // get/set
   if (attrs.size() != 0 || elems.size() != 0) {
      oss << "\n   " << small
          << "\n   // get/set"
          << "\n   " << small
          << "\n";
   }
   write_class_getset(oss, vecInfoMetadata, vecInfoChildren);

   // constructors
   oss << "\n   " << small
       << "\n   // constructors"
       << "\n   " << small
       << "\n";
   write_class_ctor(oss, clname, vecInfoMetadata, vecInfoChildren);

   // class end
   write_class_suffix(oss, file_namespace, clname);

   // save content
   std::cout << "ndep.name == " << ndep.name << std::endl;///
   assert(classMap.insert(std::make_pair(ndep.name,oss.str())).second);
}



// -----------------------------------------------------------------------------
// read JSON file
// -----------------------------------------------------------------------------

inline void read(const std::string &file, nlohmann::json &jdoc)
{
   const std::string fullName = directory + file;
   std::cout << "File: \"" << fullName << "\"" << std::endl;

   // read
   std::ifstream ifs(fullName.c_str());
   if (!ifs) {
      log::error("Could not open file \"{}\" for input", fullName);
      throw std::exception{};
   }
   ifs >> jdoc;
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main()
{
   // Output file begin
   std::ofstream ofs("out.cc");
   write_file_prefix(ofs);

   // Scan files to make forward declarations, because some classes will
   // forward-reference others. Also, compute some namespace information.
   nlohmann::json jdoc;
   ofs << "\n" << large << "\n";
   ofs << "// Forward declarations";
   ofs << "\n" << large << "\n";

   for (auto &file : files) {
      read(file,jdoc);
      const std::string file_namespace = jdoc["__namespace__"];
      ofs << "\n";
      for (const auto &keyvalue : jdoc.items())
         make_forward(ofs, file_namespace, keyvalue);
   }

   // fyi
   for (const auto &val : class2nspace)
      std::cout << val.first << ": " << val.second << std::endl;

   // print classes into temporary strings; reordered later for final output
   for (auto &file : files) {
      read(file,jdoc);
      const std::string file_namespace = jdoc["__namespace__"];
      for (const auto &keyvalue : jdoc.items())
         make_class(keyvalue, file_namespace, class2nspace);
   }

   // compute an ordering that respects dependencies
   while (classDependencies.size() > 0)
      insertNDep((*classDependencies.begin()).name,
                 classDependencies, sortedClassDependencies);

   // print dependencies
   printDepVec("NEW", sortedClassDependencies);

   // print classes, using the computed ordering
   for (auto &obj : sortedClassDependencies) {
      const auto iter = classMap.find(obj.name);
      assert(iter != classMap.end());
      ofs << iter->second;
   }

   // output file end
   write_file_suffix(ofs);
}
