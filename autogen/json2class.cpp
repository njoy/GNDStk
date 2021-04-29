
// Code for auto-generating C++ classes from JSON specs.
// Work-in-progress.

#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;
#include <cstdlib>

// re: comments
const std::string large = "// " + std::string(77,'-');
const std::string small = "// " + std::string(24,'-');

// for extra chatter
const bool debugging = false;



// -----------------------------------------------------------------------------
// Version, directories, files
// Note: no "/" at the end of directories here
// -----------------------------------------------------------------------------

// GNDS Version
// This will be one of the "descendants" mentioned above
const std::string Version = "v1.9";

// Base GNDStk directory
// Auto-generated files will be placed into appropriate descendants of this
const std::string GNDSDir = "./testdir";
// const std::string GNDSDir = "./GNDStk";


// ------------------------
// Simple example JSONs for
// a few basic containers,
// plus reactionSuite
// ------------------------

// Directory in which the input JSON files reside
const std::string JSONDir = ".";

// JSON files
const std::vector<std::string> files = {
   "generalPurpose.json",
   "reactionSuite.json"
};


// ------------------------
// "Full" JSON containers
// ------------------------

/*
const std::string JSONDir = "../formats/v1.9";

const std::vector<std::string> files = {
   "summary_abstract.json",
   "summary_appData.json",
   "summary_atomic.json",
   //"summary_basic.json",
   "summary_common.json",
   "summary_covariance.json",
   "summary_cpTransport.json",
   "summary_documentation.json",
   "summary_fissionTransport.json",
   "summary_fpy.json",
   "summary_containers.json",
   "summary_pops.json",
   "summary_processed.json",
   "summary_resonance.json",
   "summary_styles.json",
   "summary_transport.json",
   "summary_tsl.json"
};
*/



// -----------------------------------------------------------------------------
// Miscellaneous functions
// -----------------------------------------------------------------------------

std::string replace(const std::string &str, const char from, const char to)
{
   std::string ret = str;
   for (auto i = ret.size(); i--; )
      if (ret[i] == from)
         ret[i] = to;
   return ret;
}

std::string uppercase(const std::string &str)
{
   std::string ret = str;
   for (auto i = ret.size(); i--; )
      ret[i] = toupper(ret[i]);
   return ret;
}

std::string capitalize(const std::string &str)
{
   if (str.size() == 0)
      return str;
   std::string ret = str;
   ret[0] = toupper(ret[0]);
   return ret;
}



// -----------------------------------------------------------------------------
// Changes to apply...
// -----------------------------------------------------------------------------

// In view of some of the comments below, consider having a combined map that
// looks at the JSON "type" and "default" simultaneously, as well as possibly
// the name of the metadatum in question.

// JSON attributes{} "type" to GNDStk/C++ type
const std::map<std::string,std::string> mapMetaType {
   { "interpolation", "enums::Interpolation" },
   { "interaction",   "enums::Interaction" },
   { "encoding",      "enums::Encoding" },
   { "frame",         "enums::Frame" },
   { "Boolean",       "bool" }
};


// Note: for the following:
//    "style": {
//        ...
//        "type": "UTF8Text"
//    }
// the description says: "...Allowed values are `none', `points', `boundaries'
// and `parameters'." The given type, as we see, is however UTF8Text. Perhaps
// we should give GNDStk a style enum, and then map UTF8Text to the enum - BUT
// ONLY in the context of the "style" attribute. UTF8Text should probably stay
// UTF8Text in most contexts. Or, there may be other places (with UTF8Text, or
// with other string-like things) where we should similarly change things up.
// Probable examples: "compression", "markup". Let's see how things hash out.


// JSON attributes{} "default" to GNDStk default
const std::map<std::string,std::string> mapMetaDefault {
   { "ascii", "Encoding::ascii" },
   { "utf8",  "Encoding::utf8" },

   { "Float64",  "\"Float64\"" },

   // interpolation
   { "flat",              "enums::Interpolation::flat" },
   { "charged-particle",  "enums::Interpolation::chargedparticle" },
   { "lin-lin",           "enums::Interpolation::linlin" },
   { "lin-log",           "enums::Interpolation::linlog" },
   { "log-lin",           "enums::Interpolation::loglin" },
   { "log-log",           "enums::Interpolation::loglog" },
   { "\\\\attr{lin-lin}", "enums::Interpolation::linlin" }, // :-/

   // interaction
   { "nuclear", "Interaction::nuclear" },
   { "atomic",  "Interaction::atomic" },
   { "thermalNeutronScatteringLaw","Interaction::thermalNeutronScatteringLaw" },

   // frame
   { "lab",          "enums::Frame::lab" },
   { "centerOfMass", "enums::Frame::centerOfMass" },

   { "row-major",    "enums::StorageOrder::row_major" },
   { "column-major", "enums::StorageOrder::column_major" },

   { "lab",          "enums::Frame::lab" },
   { "centerOfMass", "enums::Frame::centerOfMass" },

   // Some of this must have utility for processing the JSONs into the manual
   { "`' (i.e. unitless)", "" }, // what's the `' all about?
   { " \\\\kern-1ex",      "" }, // note the leading space :-/
   { "`' (no label)",      "" }, // so, map to no label
   { "`none'",         "none" }  // lose the `...' (perhaps do generically?)
};



// -----------------------------------------------------------------------------
// Functions: general
// -----------------------------------------------------------------------------

// metaType
template<class JSON>
std::string metaType(const JSON &keyvalue)
{
   // value of JSON "type", with mapMetaType (above) applied
   assert(keyvalue.value().contains("type"));
   const std::string type = keyvalue.value()["type"];
   const auto iter = mapMetaType.find(type);
   return iter == mapMetaType.end() ? type : iter->second;
}

// className
// Think "classType" to compare/contrast with metaType above; equivalently,
// gives return value for derived-class className() for Component<DERIVED>.
// Not namespace qualified; that's added elsewhere, if/where it's needed.
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
// Gives return value for derived-class GNDSField() for Component<DERIVED>.
template<class JSON>
std::string GNDSField(const JSON &keyvalue)
{
   // as-is; appears in actual GNDS files like this
   assert(keyvalue.value().contains("name"));
   return keyvalue.value()["name"];
}

// fieldName
// Name for metadata or child-node field in the auto-generated class
template<class JSON>
std::string fieldName(const JSON &keyvalue)
{
   // as-is, except that we need to rename double :-/
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
   // both have {namespace name, class name} in the pair
   std::pair<std::string,std::string> name;
   std::vector<std::pair<std::string,std::string>> dependencies;
};

// insertNDep
void insertNDep(
   const std::pair<std::string,std::string> &objName,
   std::vector<NameDeps> &sourceVec,
   std::vector<NameDeps> &targetVec
) {
   const auto iter = std::find_if(
      sourceVec.begin(),
      sourceVec.end(),
      [objName](const NameDeps &ndep) { return ndep.name == objName; }
   );

   if (iter != sourceVec.end()) {
      auto ndep = *iter;
      sourceVec.erase(iter);
      for (auto &name : ndep.dependencies)
         insertNDep(name, sourceVec, targetVec);
      targetVec.push_back(ndep);
   }
}

// printDepVec
void printDepVec(
   const std::string &title,
   const std::vector<NameDeps> &vec
) {
   if (!debugging)
      return;

   std::cout << title << std::endl;
   for (const auto &ndep : vec) {
      std::cout << "   " << ndep.name.first << "::" << ndep.name.second;
      if (ndep.dependencies.size() > 0)
         std::cout << ":";
      for (const auto &dep : ndep.dependencies)
         std::cout << " " << dep.first << "::" << dep.second;
      std::cout << std::endl;
   }
}



// -----------------------------------------------------------------------------
// check_*
// -----------------------------------------------------------------------------

// check_class
template<class JSON>
void check_class(const JSON &keyvalue)
{
   if (debugging)
      std::cout << "Key: " << keyvalue.key() << std::endl;

   assert(keyvalue.value().contains("name"));
   assert(keyvalue.value().contains("attributes"));
   assert(keyvalue.value().contains("childNodes"));
}

// check_metadata
void check_metadata(const nlohmann::json &attrs)
{
   for (const auto &field : attrs.items()) {
      if (debugging)
         std::cout << "   Metadatum: " << field.key() << std::endl;

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

      assert(field.value().contains("name"));
      assert(field.value().contains("occurrence"));
      assert(field.value().contains("required"));

      // consistency check: for certain "occurence"s, not required
      const std::string occur = field.value()["occurrence"];
      if (occur == "0+" ||
          occur == "choice" ||
          occur == "choice+" ||
          occur == "choice2" ||
          occur == "choice2+")
         assert(!field.value()["required"]);
   }
}



// -----------------------------------------------------------------------------
// Functions: for output
// -----------------------------------------------------------------------------

// ------------------------
// re: output file
// ------------------------

// write_file_autogen
void write_file_autogen(std::ostream &os)
{
   os << "\n// THIS FILE WAS AUTO-GENERATED!"
      << "\n// DO NOT MODIFY!\n";
}

// write_file_prefix
void write_file_prefix(std::ostream &os)
{
   // GNDStk
   os << "\n"
      << "#include \"GNDStk.hpp\"\n"
      << "using namespace njoy::GNDStk::core;\n"
      << "\n";

   // namespace begin
   const std::string VersionNamespace = replace(Version,'.','_');
   os << "namespace " + VersionNamespace + " {\n\n" << std::endl;
}

// write_file_suffix
void write_file_suffix(std::ostream &os)
{
   // namespace end
   const std::string VersionNamespace = replace(Version,'.','_');
   os << "\n"
      << "} // namespace " + VersionNamespace + "\n";

   // main (stub)
   os
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
   // comment introducing class
   os << "\n\n\n"
      << large << "\n"
      << "// " << file_namespace << "::\n"
      << "// class " << clname << "\n"
      << large << "\n"
      << "\n";

   // namespace+class begin
   os
      << "namespace " << file_namespace << " {\n\n"
      << "class " << clname << " : public Component<" << clname << "> {"
      << std::endl;
}

// write_class_suffix
void write_class_suffix(
   std::ostream &os,
   const std::string &file_namespace, const std::string &clname
) {
   // boilerplate assignment operators
   os << "\n   " << small
      << "\n   // assignment: copy, move"
      << "\n   " << small << "\n"
      << "\n   " << clname << " &operator=(const " << clname << " &) = default;"
      << "\n   " << clname << " &operator=(" << clname << " &&) = default;\n";

   // #include for custom code
   os << "\n   " << small
      << "\n   // custom functionality"
      << "\n   " << small << "\n"
      << "\n   #include \"GNDStk/" << Version << "/"
      << file_namespace << "/" << clname << "/src/custom.hpp\"\n";

   // class+namespace end
   os << "\n}; // class " << clname << "\n"
      << "\n} // namespace " << file_namespace << std::endl;
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Functions for in-class content
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

// infoMetadata
class infoMetadata {
public:
   // metadata can end up with:
   //    - optional
   //    - defaulted
   // but not vector
   std::string fullVarType; // with any optional<>, defaulted<>
   std::string varType;     // underlying type
   std::string varName;
   bool        hasDefault;
   std::string theDefault;
   bool        isOptional;
   bool        isDefaulted;
};

// infoChildren
class infoChildren {
public:
   // children can end up with:
   //    - optional
   //    - vector
   // but not defaulted
   std::string fullVarType; // with any optional<> or vector<>
   std::string halfVarType; // withOUT any vector<>
   std::string varType;     // underlying type
   std::string varName;
   bool        isOptional;
   bool        isVector;
};

// to_string
// See: https://github.com/nlohmann/json/issues/642
std::string to_string(const nlohmann::json &j)
{
   const auto tmp = j.dump();
   if (j.type() == nlohmann::json::value_t::string)
      return tmp.substr(1, tmp.size()-2);
   else
      return tmp;
}



// -----------------------------------------------------------------------------
// write_metadata
// Also *computes* entries in vecInfoMetadata, for later use
// -----------------------------------------------------------------------------

void write_metadata(
   std::ostream &ossm, // in caller, this is a temporary ostringstream
   const nlohmann::json &attrs,
   std::vector<infoMetadata> &vecInfoMetadata // output
) {
   // here, we're within the public struct for raw GNDS content
   ossm << "\n      // metadata\n";
   for (const auto &field : attrs.items()) {

      // re: default
      std::string theDefault = "";
      if (!field.value()["default"].is_null()) {
         theDefault = to_string(field.value()["default"]);
         const auto iter = mapMetaDefault.find(theDefault);
         if (iter != mapMetaDefault.end())
            theDefault = iter->second;
      };

      const bool hasDefault = theDefault != "";
      if (hasDefault) {
         if (debugging)
            std::cout << "theDefault: \"" << theDefault << '"' << std::endl;
         // It makes sense that the following would be true. If something is
         // required, then why give it a "default"? The original JSONs actually
         // had a couple of cases for which this wasn't the case. For those, I
         // changed "default" to null. If doing so was wrong, we can revert the
         // files and change or remove the following.
         assert(!field.value()["required"]);
      }

      // optional? (but instead use defaulted, below, if it has a default)
      const bool opt = !field.value()["required"] && !hasDefault;
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // defaulted? (optional with default)
      const bool def = !field.value()["required"] && hasDefault;
      const std::string defPrefix = def ? "Defaulted<" : "";
      const std::string defSuffix = def ? ">" : "";

      // sanity check
      assert(
         (optPrefix == ""  &&  defPrefix == "") || // neither, or...
         (optPrefix == "") != (defPrefix == "")    // XOR
      );

      // type
      const std::string varType = metaType(field);

      // full type (including any optional or defaulted)
      const std::string fullVarType =
         optPrefix + defPrefix +
         varType +
         defSuffix + optSuffix;

      // name
      const std::string varName = fieldName(field);

      // write
      ossm << "      " << fullVarType << " " << varName;
      if (hasDefault)
         ossm << "{" << theDefault << "}";
      ossm << ";" << std::endl;

      // add to vecInfoMetadata, to be used later
      vecInfoMetadata.push_back(infoMetadata{});
      vecInfoMetadata.back().fullVarType = fullVarType;
      vecInfoMetadata.back().varType     = varType;
      vecInfoMetadata.back().varName     = varName;
      vecInfoMetadata.back().hasDefault  = hasDefault;
      vecInfoMetadata.back().theDefault  = theDefault;
      vecInfoMetadata.back().isOptional  = opt;
      vecInfoMetadata.back().isDefaulted = def;
   }
} // write_metadata



// -----------------------------------------------------------------------------
// write_children
// Also *computes* entries in vecInfoChildren, for later use
// -----------------------------------------------------------------------------

void write_children(
   std::ostream &ossc, // in caller, this is a temporary ostringstream
   const nlohmann::json &elems,
   std::vector<infoChildren> &vecInfoChildren, // output

   // additional info, in comparison with write_metadata's signature...
   const std::string &file_namespace, // JSONs file's overall "__namespace__"
   const std::string &clname, // name of enclosing class; plain, no namespace::
   NameDeps &ndep,
   const std::multimap<std::string,std::string> &class2nspace
) {
   // here, we're within the public struct for raw GNDS content
   ossc << "\n      // children\n";
   for (const auto &field : elems.items()) {

      // optional?
      const bool opt = !field.value()["required"];
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // vector?
      const std::string occurence = field.value()["occurrence"];
      const bool vec =
         occurence == "0+" ||
         occurence == "1+" ||
         occurence == "2+" ||
         occurence == "choice2+";
      const std::string vecPrefix = vec ? "std::vector<" : "";
      const std::string vecSuffix = vec ? ">" : "";

      // type
      std::string varType = className(field);
      std::string ns;
      {
         // Determine what namespace varType belongs in. The scenario: we're
         // inside of a file with __namespace__ file_namespace, in a class
         // with name clname, looking at a child node with name varType. The
         // point is to determine varType's namespace.

         const auto value = field.value();

         // we'll recognize either of these, but disallow both together...
         assert(!(value.contains("namespace") &&
                  value.contains("__namespace__")));

         if (value.contains("namespace")) {
            // use the given "namespace"
            ns = value["namespace"];
         } else if (value.contains("__namespace__")) {
            // use the given "__namespace__"
            ns = value["__namespace__"];
         } else if (class2nspace.count(varType) == 0) {
            log::warning(
               "{}::{} has child of unknown type {}.",
               file_namespace, clname, varType
            );
            ns = "unknownNamespace";
         } else if (class2nspace.count(varType) == 1) {
            // child node type is in only one namespace; go ahead and use it
            ns = class2nspace.find(varType)->second;
         } else {
            // child node type is in >= 2 namespaces; one of them must be the
            // current one, or we consider this situation to be ambiguous
            bool found = false;
            for (auto it = class2nspace.equal_range(varType).first;
                 it != class2nspace.equal_range(varType).second; ++it)
               if (it->second == file_namespace)
                  ns = file_namespace, found = true;

            if (!found) {
               std::stringstream warn;
               int count = 0;
               for (auto it = class2nspace.equal_range(varType).first;
                    it != class2nspace.equal_range(varType).second; ++it)
                  warn << (count++ ? ", " : "") << it->second;
               log::warning(
                  "{}::{} has child of ambiguous type {}.\n"
                  "Child type {} appears in all of the following "
                  "namespaces:\n{}",
                  file_namespace, clname, varType, varType, warn.str()
               );
            }
         }

         // prefix varType with the namespace we just determined it to have
         varType = ns + "::" + varType;
      }

      // full type (including any optional or vector)
      // If both, it's a vector<optional>; the reverse would make less sense
      const std::string fullVarType =
         optPrefix + vecPrefix +
         varType +
         vecSuffix + optSuffix;

      // partial type (not including any vector); this is used in the context
      // of this child node's element of the multi-query key, where the Child
      // object's one/many status causes vector to be added voluntarily if and
      // only if it's appropriate
      const std::string halfVarType =
         optPrefix +
         varType +
         optSuffix;

      // name
      const std::string varName = fieldName(field);

      // write
      ossc << "      " << fullVarType << " " << varName << ";" << std::endl;

      // save as a dependency - if it's not its own dependency (in which case
      // presumably a pointer is involved, or we're out of luck in any event)
      if (varType != clname)
         ndep.dependencies.push_back(std::make_pair(ns,className(field)));

      // vecInfoChildren
      vecInfoChildren.push_back(infoChildren{});
      vecInfoChildren.back().fullVarType = fullVarType;
      vecInfoChildren.back().halfVarType = halfVarType;
      vecInfoChildren.back().varType     = varType;
      vecInfoChildren.back().varName     = varName;
      vecInfoChildren.back().isOptional  = opt;
      vecInfoChildren.back().isVector    = vec;
   }
} // write_children



// -----------------------------------------------------------------------------
// write_keys
// Names and keys for the Component base
// -----------------------------------------------------------------------------

template<class JSON>
void write_keys(
   std::ostream &os,
   const JSON &keyvalue,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   // names
   const std::string name = className(keyvalue);
   const std::string gnds = GNDSField(keyvalue);

   os << "\n";
   os << "   " << small << "\n";
   os << "   // for Component\n";
   os << "   " << small << "\n";
   os << "\n";
   os << "   friend class Component<" << name << ">;\n";
   os << "\n";
   os << "   static auto className() { return \"" << name << "\"; }\n";
   os << "   static auto GNDSField() { return \"" << gnds << "\"; }\n";

   // keys begin
   os << "   static auto keys()\n";
   os << "   {\n";

   // keys
   auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   if (total == 0) {
      os << "      return std::tuple<>{};\n";
   } else {
      os << "      return\n";

      // metadata
      if (vecInfoMetadata.size())
         os << "         // metadata\n";
      for (const auto &m : vecInfoMetadata)
         os << "         "
            << m.fullVarType << "{"
            << m.theDefault
            << "}\n            / "
            << "Meta<>(\"" << m.varName << "\")"
            << (--total ? " |\n" : "\n");

      // children
      if (vecInfoChildren.size())
         os << "         // children\n";
      for (const auto &c : vecInfoChildren)
         os << "         "
            << c.halfVarType << "{" // halfVarType: w/o any std::vector<>
            << "}\n            / " << (c.isVector ? "++" : "--")
            << "Child<>(\"" << c.varName << "\")"
            << (--total ? " |\n" : "\n");

      os << "      ;\n";
   }

   // keys end
   os << "   }\n";
   os << "\n";
   os << "public:\n";
}



// -----------------------------------------------------------------------------
// write_getters
// -----------------------------------------------------------------------------

void write_getters(
   std::ostream &os,
   std::vector<infoMetadata> &vecInfoMetadata,
   std::vector<infoChildren> &vecInfoChildren
) {
   os << "\n   " << small
      << "\n   // getters"
      << "\n   " << small
      << "\n";

   if (vecInfoMetadata.size()) {
      for (const auto &m : vecInfoMetadata) {
         // comment
         os << "\n   // " << m.varName << "\n";

         // getter: const
         os << "   const auto &" << m.varName << "() const\n";
         os << "    { return content." << m.varName;
         if (m.isDefaulted) os << ".value()";
         os << "; }\n";
         // getter: non-const
         os << "   auto &" << m.varName << "()\n";
         os << "    { return content." << m.varName;
         if (m.isDefaulted) os << ".value()";
         os << "; }\n";
      }
   }

   if (vecInfoChildren.size()) {
      for (const auto &c : vecInfoChildren) {
         // comment
         os << "\n   // " << c.varName << "\n";

         // getter: const
         os << "   const auto &" << c.varName << "() const\n";
         os << "    { return content." << c.varName;
         os << "; }\n";
         // getter: non-const
         os << "   auto &" << c.varName << "()\n";
         os << "    { return content." << c.varName;
         os << "; }\n";
      }
   }
}



// -----------------------------------------------------------------------------
// write_setters
// -----------------------------------------------------------------------------

/*
------------------------
metadata
------------------------

fullVarType     Want
   T               name(T)
   opt<T>          name(T), name(opt<T>)
   def<T>          name(T), name(def<T>)

------------------------
children
------------------------

fullVarType     Want
   T               name(T)
   vec<T>          name(vec<T>)
   opt<T>          name(opt<T>), name(T)
   opt<vec<T>>     name(opt<vec<T>>), name(vec<T>)

Need to think about variant possibilities too (children case only)
   variant<A,B,...>
   vector<variant<A,B,...>>
*/

void write_setters(
   std::ostream &os,
   std::vector<infoMetadata> &vecInfoMetadata,
   std::vector<infoChildren> &vecInfoChildren
) {
   os << "\n   " << small
      << "\n   // setters"
      << "\n   " << small
      << "\n";

   if (vecInfoMetadata.size()) {
      for (const auto &m : vecInfoMetadata) {
         // comment
         os << "\n   // " << m.varName << "\n";

         // setter(s)
         {
            os << "   auto &" << m.varName;
            os << "(const " << m.varType << " &obj)\n";
            os << "    { content." << m.varName << " = obj; return *this; }\n";
         }
         if (m.fullVarType != m.varType) {
            os << "   auto &" << m.varName;
            os << "(const " << m.fullVarType << " &obj)\n";
            os << "    { content." << m.varName << " = obj; return *this; }\n";
         }
      }
   }

   if (vecInfoChildren.size()) {
      for (const auto &c : vecInfoChildren) {
         // comment
         os << "\n   // " << c.varName << "\n";

         // setter(s)
         if (c.isOptional) {
            if (c.isVector) {
               os << "   auto &" << c.varName;
               os << "(const std::vector<" << c.varType << "> &obj)\n   ";
               os << " { content." << c.varName << " = obj; return *this; }\n";
            } else {
               os << "   auto &" << c.varName;
               os << "(const " << c.varType << " &obj)\n   ";
               os << " { content." << c.varName << " = obj; return *this; }\n";
            }
         }
         {
            os << "   auto &" << c.varName;
            os << "(const " << c.fullVarType << " &obj)\n";
            os << "    { content." << c.varName << " = obj; return *this; }\n";
         }
      }
   }
}



// -----------------------------------------------------------------------------
// write_class_ctor
// -----------------------------------------------------------------------------

// helper
void write_component_base(
   std::ostream &os, const std::size_t total,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   os << "      Component{\n";
   std::size_t count = 0;
   for (const auto &m : vecInfoMetadata)
      os << "         content." + m.varName + (++count < total ? ",\n" : "\n");
   for (const auto &c : vecInfoChildren)
      os << "         content." + c.varName + (++count < total ? ",\n" : "\n");
   os << "      }";
}

void write_class_ctor(
   std::ostream &os,
   const std::string &clname,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   const auto total = vecInfoMetadata.size() + vecInfoChildren.size();
   std::size_t count;

   // ------------------------
   // ctor: default
   // ------------------------

   // signature
   os << "\n";
   os << "   // default\n";
   os << "   " << clname << "() :\n";

   // base constructor call
   write_component_base(os, total, vecInfoMetadata, vecInfoChildren);

   // body
   os << "\n";
   os << "   {\n";
   os << "      construct();\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: copy
   // ------------------------

   // signature
   os << "   // copy\n";
   os << "   " << clname << "(const " << clname << " &other) :\n";

   // base constructor call
   write_component_base(os, total, vecInfoMetadata, vecInfoChildren);

   // copy fields
   if (total)
      os << ",\n      content{other.content}";

   // body
   os << "\n";
   os << "   {\n";
   os << "      construct();\n";
   os << "   }\n";
   os << "\n";

   // ------------------------
   // ctor: node
   // ------------------------

   // signature; and delegate to default ctor
   os << "   // node\n";
   os << "   " << clname << "(const Node &node) :\n";

   // base constructor call
   write_component_base(os, total, vecInfoMetadata, vecInfoChildren);

   // body
   os << "\n";
   os << "   {\n";
   os << "      query(node);\n";
   os << "      construct();\n";
   os << "   }\n";

   // ------------------------
   // ctor: fields
   // ------------------------

   if (total > 0) {
      os << "\n   // fields\n";

      // signature
      // Note: we don't really need "explicit" unless this constructor can be
      // called with one argument. We'll always put it in, however, just in
      // case someone modifies the auto-generator constructor (say, giving its
      // arguments defaults) in such a way that is *can* be called with one
      // argument. (But we'd rather nobody modify the auto-generated classes.)
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
      write_component_base(os, total, vecInfoMetadata, vecInfoChildren);

      // initialize fields
      os << ",\n";
      os << "      content{\n";
      count = 0;
      for (const auto &m : vecInfoMetadata)
         os << "         " << m.varName << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "         " << c.varName << (++count < total ? ",\n" : "\n");
      os << "      }\n";

      // body
      os << "   {\n";
      os << "      construct();\n";
      os << "   }\n";
   }

   // ------------------------
   // ctor: fields but without
   // Defaulted<>, if there
   // are any Defaulted<>s
   // ------------------------

   bool def = false;
   for (const auto &m : vecInfoMetadata)
      if (m.isDefaulted)
         def = true;
   // infoChildren doesn't have isDefaulted, so isn't here

   if (total > 0 && def) {
      os << "\n   // fields, with T replacing Defaulted<T>\n";

      // signature
      count = 0;
      os << "   explicit " << clname << "(\n";
      for (const auto &m : vecInfoMetadata)
         os << "      const " << (m.isDefaulted ? m.varType : m.fullVarType)
            << " &" << m.varName
            << (++count < total ? ",\n" : "\n");
      for (const auto &c : vecInfoChildren)
         os << "      const " << c.fullVarType
            << " &" << c.varName
            << (++count < total ? ",\n" : "\n");
      os << "   ) :\n";

      // base constructor call
      write_component_base(os, total, vecInfoMetadata, vecInfoChildren);

      // initialize fields
      os << ",\n";
      os << "      content{\n";
      count = 0;
      for (const auto &m : vecInfoMetadata) {
         if (m.isDefaulted) {
            os << "         " << m.varName << " == " << m.theDefault << "\n";
            os << "            ? " << m.fullVarType
               << "{" << m.theDefault << "}\n";
            os << "            : " << m.fullVarType
               << "{" << m.theDefault << "," << m.varName << "}";
            os << (++count < total ? ",\n" : "\n");
         } else {
            os << "         " << m.varName << (++count < total ? ",\n" : "\n");
         }
      }
      for (const auto &c : vecInfoChildren)
         os << "         " << c.varName << (++count < total ? ",\n" : "\n");
      os << "      }\n";

      // body
      os << "   {\n";
      os << "      construct();\n";
      os << "   }\n";
   }
}



// -----------------------------------------------------------------------------
// make_forward
// Receives each key/value pair in the outer {...} json level.
// Also computes class2nspace.
// Additionally, creates some of the directory/file structure.
// The last thing is a bit hacky, but was convenient to do here.
// -----------------------------------------------------------------------------

const std::string HPPforVersion = GNDSDir + "/src/GNDStk/" + Version + ".hpp";

// Helpers
class NSFile { // "namespace-specific file"
public:
   std::string filePythonCPP;
};

class CLFile { // "class-specific files"
public:
   std::string fileHPP;
   std::string filePythonCPP;
};

// namespace name, file name (Python CPP for the namespace)
std::map<std::string,NSFile> namespace2file;

// {namespace,class} names, file names (GNDStk HPP and Python CPP for the class)
std::map<std::pair<std::string,std::string>,CLFile> class2files;



// make_forward
template<class JSON>
void make_forward(
   std::ostream &os,
   const std::string &file_namespace, // value of "__namespace__" in the file
   const JSON &keyvalue,
   std::multimap<std::string,std::string> &class2nspace
) {
   // not a class?
   const auto key = keyvalue.key();
   if (key == "__namespace__" || key == "Specifications")
      return;

   // not a node class?
   const auto value = keyvalue.value();
   if (value["__class__"] != "nodes.Node")
      return;

   // class name
   const std::string clname = className(keyvalue);

   // write a forward declaration
   os << "namespace " << file_namespace << " { class " << clname << "; }\n";

   // for later use: map class to namespace(s) in which it's found
   class2nspace.insert(std::make_pair(clname,file_namespace));

   // ------------------------
   // Namespace+class files
   // ------------------------

   {
      const std::string
         nsdir   = GNDSDir + "/src/GNDStk/" + Version + "/" + file_namespace,
         nsdirpy = GNDSDir + "/python/src/" + Version + "/" + file_namespace;
      system(("mkdir -p " + nsdir  ).c_str());
      system(("mkdir -p " + nsdirpy).c_str());

      const std::string src  = nsdir + "/" + clname + "/src";
      const std::string test = nsdir + "/" + clname + "/test";
      system(("mkdir -p " + src ).c_str());
      system(("mkdir -p " + test).c_str());

      // create custom.hpp, but ONLY if it's not already there
      const std::string custom = src + "/custom.hpp";
      std::ifstream cstm(custom);
      if (!cstm) {
         std::cout << "   No file " << custom << std::endl;
         std::cout << "   ...So, creating a blank one" << std::endl;
         std::ofstream cstm(custom,std::ofstream::app);
      }

      const std::string clhpp   = nsdir   + "/" + clname + ".hpp";
      const std::string nscpppy = nsdirpy + ".python.cpp";
      const std::string clcpppy = nsdirpy + "/" + clname + ".python.cpp";
      { std::ofstream ofs(clhpp  ); write_file_autogen(ofs); }
      { std::ofstream ofs(nscpppy); write_file_autogen(ofs); }
      { std::ofstream ofs(clcpppy); write_file_autogen(ofs); }

      namespace2file.insert(std::make_pair(
         file_namespace,
         NSFile{nscpppy}
      ));

      class2files.insert(std::make_pair(
         std::make_pair(file_namespace,clname),
         CLFile{clhpp,clcpppy}
      ));
   }

   // ------------------------
   // For Version.hpp
   // ------------------------

   {
      // Handled after the earlier mkdir system commands, so that
      // the necessary directories are guaranteed to exist
      static bool first = true;
      std::ofstream ofs(
         HPPforVersion,
         first ? std::ofstream::out : std::ofstream::app
      );

      if (first) {
         write_file_autogen(ofs);
         const std::string VERSION = uppercase(replace(Version,'.','_'));
         ofs << "\n#ifndef NJOY_GNDSTK_" << VERSION;
         ofs << "\n#define NJOY_GNDSTK_" << VERSION << "\n";
      }
      static std::string nsname = "";
      if (nsname != file_namespace) {
         nsname = file_namespace;
         ofs << "\n";
      }
      ofs << "#include \"GNDStk/" << Version << "/"
          << file_namespace << "/" << clname << ".hpp\"\n";
      first = false;
   }
}



// -----------------------------------------------------------------------------
// make_class
// -----------------------------------------------------------------------------

// For dependencies: (1) The dependencies themselves. (2) A map from class names
// to their printed code. We compute these pairs first, so that we can print the
// code for each class later - after a dependency-aware ordering is determined.
std::vector<NameDeps> classDependencies;
std::vector<NameDeps> sortedClassDependencies;
std::map<std::pair<std::string,std::string>,std::string> classCodeMap;

std::map<
   std::pair<
      std::string,
      std::string
   >,
   std::pair<
      std::vector<infoMetadata>,
      std::vector<infoChildren>
   >
> class2info;

// make_class
template<class JSON>
void make_class(
   const JSON &keyvalue,
   const std::string &file_namespace,
   const std::multimap<std::string,std::string> &class2nspace
) {
   // not a class?
   const auto key = keyvalue.key();
   if (key == "__namespace__" ||  key == "Specifications")
      return;

   // not a node class?
   const auto value = keyvalue.value();
   if (value["__class__"] != "nodes.Node")
      return;

   // class name; and do some checks
   const std::string clname = className(keyvalue);
   if (debugging)
      std::cout << "Class: " << clname << std::endl;
   check_class(keyvalue);

   // re: ordering
   // Save current namespace-qualified class name; we'll then add dependencies
   classDependencies.push_back(NameDeps{});
   auto &ndep = classDependencies.back();
   ndep.name = std::make_pair(file_namespace,clname);

   // class begin
   std::ostringstream oss;
   write_class_prefix(oss, file_namespace, clname);
   const auto attrs = value["attributes"];
   check_metadata(attrs);
   const auto elems = value["childNodes"];
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
      write_children(ossc, elems, vecInfoChildren,
                     file_namespace, clname, ndep, class2nspace);

   // for later use
   class2info.insert(
      std::make_pair(
         std::make_pair(file_namespace,clname),
         std::make_pair(vecInfoMetadata,vecInfoChildren)
      )
   );

   // names, keys
   // As needed by the Component base
   write_keys(oss, keyvalue, vecInfoMetadata, vecInfoChildren);

   // metadata/children (computed earlier)
   if (vecInfoMetadata.size() || vecInfoChildren.size()) {
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
   if (vecInfoMetadata.size() || vecInfoChildren.size()) {
      write_getters(oss, vecInfoMetadata, vecInfoChildren);
      write_setters(oss, vecInfoMetadata, vecInfoChildren);
   }

   // constructors
   oss << "\n   " << small
       << "\n   // constructors"
       << "\n   " << small
       << "\n";
   write_class_ctor(oss, clname, vecInfoMetadata, vecInfoChildren);

   // class end
   write_class_suffix(oss, file_namespace, clname);

   // save content
   if (debugging)
      std::cout
         << "ndep.name == "
         << ndep.name.first  << "::"
         << ndep.name.second << std::endl;
   const bool inserted =
      classCodeMap.insert(std::make_pair(ndep.name,oss.str())).second;
   assert(inserted);
}



// -----------------------------------------------------------------------------
// read JSON file
// -----------------------------------------------------------------------------

void read(const std::string &file, nlohmann::json &jdoc)
{
   const std::string fullName = JSONDir + "/" + file;
   std::cout << "File: \"" << fullName << '"' << std::endl;

   // read
   std::ifstream ifs(fullName);
   if (!ifs) {
      log::error("Could not open \"{}\"", fullName);
      throw std::exception{};
   }
   ifs >> jdoc;
}



// -----------------------------------------------------------------------------
// file_python_namespace
// -----------------------------------------------------------------------------

void file_python_namespace(
   const std::string &nsname,
   const std::string &filePythonCPP
) {
   std::ofstream cpp(filePythonCPP,std::ofstream::app);

   cpp << "\n";
   cpp << "#include <pybind11/pybind11.h>\n";
   cpp << "#include <pybind11/stl.h>\n";
   cpp << "\n";
   cpp << "namespace python = pybind11;\n";
   cpp << "\n";

   const std::string underver = replace(Version,'.','_');
   cpp << "// " << Version << " interface\n";
   cpp << "namespace " << underver << " {\n\n";

   cpp << "// " << nsname << " declarations\n";
   cpp << "namespace " << nsname << " {\n";
   for (auto &cl : sortedClassDependencies)
      if (cl.name.first == nsname)
         cpp << "   void wrap" << cl.name.second << "(python::module &);\n";
   cpp << "} // namespace " << nsname << "\n";
   cpp << "\n";

   cpp << "// " << nsname << " wrapper\n";
   cpp << "void wrap" << capitalize(nsname) << "(python::module &module)\n";
   cpp << "{\n";
   cpp << "   // create the " << nsname << " submodule\n";
   cpp << "   python::module submodule = module.def_submodule(\n";
   cpp << "      \"" << nsname << "\",\n";
   cpp << "      \"GNDS v1.9 " << nsname << "\"\n";
   cpp << "   );\n";

   cpp << "\n   // wrap " << nsname << " components\n";
   for (auto &cl : sortedClassDependencies)
      if (cl.name.first == nsname)
         cpp << "   " << nsname << "::wrap" << cl.name.second
             << "(submodule);\n";
   cpp << "};\n";

   cpp << "\n} // namespace " << underver << "\n";
}



// -----------------------------------------------------------------------------
// file_python_class
// -----------------------------------------------------------------------------

void file_python_class(const NameDeps &obj, const std::string &filePythonCPP)
{
   std::ofstream cpp(filePythonCPP,std::ofstream::app);

   const std::string VersionNamespace = replace(Version,'.','_');
   const std::string nsname = obj.name.first;
   const std::string clname = obj.name.second;

   cpp << "\n";

   cpp << "// system includes\n";
   cpp << "#include <pybind11/pybind11.h>\n";
   cpp << "#include <pybind11/stl.h>\n";
   cpp << "\n";

   cpp << "// local includes\n";
   cpp << "#include \"GNDStk/" << Version << "/"
       << nsname << "/" << clname << ".hpp\"\n";
   cpp << "\n";

   cpp << "// namespace aliases\n";
   cpp << "namespace python = pybind11;\n";
   cpp << "\n";

   cpp << "namespace " << VersionNamespace << " {\n";
   cpp << "namespace " << nsname << " {\n";
   cpp << "\n";

   cpp << "// " << clname << " wrapper\n";
   cpp << "void wrap" << clname << "(python::module &module)\n";
   cpp << "{\n";
   cpp << "   using namespace njoy::GNDStk;\n";
   cpp << "\n";
   cpp << "   // type aliases\n";
   cpp << "   using Component = " << VersionNamespace << "::" << nsname << "::" << clname << ";\n";
   cpp << "\n";
   cpp << "   // create the component\n";
   cpp << "   python::class_<Component> component(\n";
   cpp << "      module,\n";
   cpp << "      Component::className(),\n";
   cpp << "      Component::help()\n";
   cpp << "   );\n";
   cpp << "\n";
   cpp << "   // wrap the component\n";
   cpp << "   component\n";
   cpp << "      .def(\n";

   /*
   std::map<
      std::pair<
         std::string,
         std::string
      >,
      std::pair<
         std::vector<infoMetadata>,
         std::vector<infoChildren>
      >
   > class2info;
   */

   const auto info = class2info.find(obj.name);
   assert(info != class2info.end());
   const auto &minfo = info->second.first;  // vector<infoMetadata>
   const auto &cinfo = info->second.second; // vector<infoChildren>
   const auto total = minfo.size() + cinfo.size();
   std::size_t count;

   // python::init<...>
   cpp << "         python::init<\n";
   count = 0;
   for (auto &m : minfo) {
      cpp << "            const " << m.fullVarType;
      cpp << (++count < total ? " &,\n" : " &\n");
   }
   for (auto &c : cinfo) {
      cpp << "            const " << c.fullVarType;
      cpp << (++count < total ? " &,\n" : " &\n");
   }
   cpp << "         >(),\n";

   // python::arg...
   for (auto &m : minfo)
      cpp << "         python::arg(\"" << m.varName << "\"),\n";
   for (auto &c : cinfo)
      cpp << "         python::arg(\"" << c.varName << "\"),\n";

   cpp << "         Component::help(\"constructor\")\n";
   cpp << "      )\n";

   // .def_property_readonly...
   for (auto &m : minfo) {
      const auto name = m.varName;
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << name << "\",\n";
      cpp << "         &Component::" << name << ",\n";
      cpp << "         Component::help(\"" << name << "\")\n";
      cpp << "      )\n";
   }
   for (auto &c : cinfo) {
      const auto name = c.varName;
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << name << "\",\n";
      cpp << "         &Component::" << name << ",\n";
      cpp << "         Component::help(\"" << name << "\")\n";
      cpp << "      )\n";
   }

   // finish up
   cpp << "   ;\n";
   cpp << "}\n";
   cpp << "\n";
   cpp << "} // namespace " << nsname << "\n";
   cpp << "} // namespace " << VersionNamespace << "\n";
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main()
{
   // For diagnostics
   color = true;

   // Output file begin
   std::ofstream ofs("out.cc");
   write_file_autogen(ofs);
   write_file_prefix(ofs);
   ofs << "\n" << large << "\n";
   ofs << "// Forward declarations";
   ofs << "\n" << large << "\n";

   // Scan files to make forward declarations, because some classes forward-
   // reference others. And, it's also convenient to have a list of all classes
   // at the beginning of the file. Also, compute class/namespace associations.
   // class2nspace: For each class: what namespaces does it appear in? The JSON
   // files *do* have same-named classes in different namespaces.
   std::multimap<std::string,std::string> class2nspace;
   nlohmann::json jdoc;
   std::cout << "Preprocessing..." << std::endl;
   for (auto &file : files) {
      read(file,jdoc);
      ofs << "\n";
      const std::string file_namespace = jdoc["__namespace__"];
      for (const auto &keyvalue : jdoc.items())
         make_forward(ofs, file_namespace, keyvalue, class2nspace);
   }
   std::ofstream ver(HPPforVersion, std::ofstream::app);
   ver << "\n#endif\n";
   ver.close();

   // FYI
   if (debugging)
      for (const auto &val : class2nspace)
         std::cout << val.first << ": " << val.second << std::endl;

   // Print classes into temporary strings, because they have to be reordered
   // later (per dependencies) for final output
   std::cout << "\nBuilding classes..." << std::endl;
   for (auto &file : files) {
      read(file,jdoc);
      const std::string file_namespace = jdoc["__namespace__"];
      for (const auto &keyvalue : jdoc.items())
         make_class(keyvalue, file_namespace, class2nspace);
   }

   // Compute an ordering that respects dependencies
   while (classDependencies.size() > 0)
      insertNDep((*classDependencies.begin()).name,
                 classDependencies, sortedClassDependencies);

   // Print dependencies
   printDepVec("Class dependencies", sortedClassDependencies);

   // Print classes, using the computed ordering
   for (auto &obj : sortedClassDependencies) {
      const auto code = classCodeMap.find(obj.name);
      assert(code != classCodeMap.end());
      ofs << code->second;
   }

   // Output file end
   write_file_suffix(ofs);

   // Individual files
   {
      /*
      sortedClassDependencies:
      vector<{ name = pair<nsname,clname>,
               dependencies = vector<pair<nsname,clname>>}>

      classCodeMap:
         map< pair<nsname,clname>, string>

      class2files:
         map< pair<nsname,clname>, {fileHPP,filePythonCPP} >

      namespace2file:
         map<      nsname,         {        filePythonCPP} >

      */

      for (auto &obj : sortedClassDependencies) {
         // code
         const auto code = classCodeMap.find(obj.name);
         assert(code != classCodeMap.end());

         // hpp and Python cpp files for the class
         const auto file = class2files.find(obj.name);
         assert(file != class2files.end());
         auto fileHPP       = file->second.fileHPP;
         auto filePythonCPP = file->second.filePythonCPP;

         // class-specific hpp file
         std::ofstream hpp(fileHPP,std::ofstream::app);
         const std::string guard =
            "NJOY_GNDSTK_" + uppercase(replace(Version,'.','_')) + "_" +
            uppercase(obj.name.first) + "_" + uppercase(obj.name.second);
         hpp << "\n#ifndef " << guard;
         hpp << "\n#define " << guard << "\n";
         hpp << "\n"
             << "#include \"GNDStk.hpp\"\n"
             << "\n";
         if (obj.dependencies.size() > 0) {
            hpp << "// dependencies\n";
            for (const auto &dep : obj.dependencies)
               hpp << "#include \"GNDStk/" << Version << "/"
                   << dep.first << "/" << dep.second << ".hpp\"\n";
            hpp << "\n";
         }
         hpp << "namespace njoy {\n";
         hpp << "namespace GNDStk {\n";
         hpp << "namespace " << replace(Version,'.','_') << " {\n\n";
         hpp << "using namespace njoy::GNDStk::core;\n";
         hpp << code->second << "\n";
         hpp << "} // namespace " << replace(Version,'.','_') << "\n";
         hpp << "} // namespace GNDStk\n";
         hpp << "} // namespace njoy\n\n";
         hpp << "#endif" << std::endl;

         // class-specific cpp file for python
         file_python_class(obj,filePythonCPP);
      }
   }

   // Python: file for namespace
   for (auto &obj : namespace2file) {
      // Python cpp file for the namespace
      auto filePythonCPP = obj.second.filePythonCPP;
      file_python_namespace(obj.first,filePythonCPP);
   }
}
