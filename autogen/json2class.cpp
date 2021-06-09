
// Code for auto-generating classes from JSON specs.

#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;
#include <cstdlib>

// re: comments
const auto large = "// " + std::string(77,'-');
const auto small = "// " + std::string(24,'-');

// re: extra chatter
const bool debugging = false;



// -----------------------------------------------------------------------------
// Base directory, GNDS version, and JSON files
// -----------------------------------------------------------------------------

// Base directory (of the GNDStk repo); no / at end
// const std::string GNDSDir = "testdir";
const std::string GNDSDir = "GNDStk";

// GNDS Version
const std::string Version = "v1.9";

// ------------------------
// Simple test JSON files
// ------------------------

const std::vector<std::string> files = {
   "generalPurpose.json",
   "reactionSuite.json"
};

// ------------------------
// Full JSON files
// ------------------------

/*
const std::vector<std::string> files = {
   "../formats/" + Version + "/summary_abstract.json",
   "../formats/" + Version + "/summary_appData.json",
   "../formats/" + Version + "/summary_atomic.json",
// "../formats/" + Version + "/summary_basic.json",
   "../formats/" + Version + "/summary_common.json",
   "../formats/" + Version + "/summary_covariance.json",
   "../formats/" + Version + "/summary_cpTransport.json",
   "../formats/" + Version + "/summary_documentation.json",
   "../formats/" + Version + "/summary_fissionTransport.json",
   "../formats/" + Version + "/summary_fpy.json",
   "../formats/" + Version + "/summary_containers.json",
   "../formats/" + Version + "/summary_pops.json",
   "../formats/" + Version + "/summary_processed.json",
   "../formats/" + Version + "/summary_resonance.json",
   "../formats/" + Version + "/summary_styles.json",
   "../formats/" + Version + "/summary_transport.json",
   "../formats/" + Version + "/summary_tsl.json"
};
*/



// -----------------------------------------------------------------------------
// Changes to apply...
// -----------------------------------------------------------------------------

// JSON attribute "type" to GNDStk type
const std::map<std::string,std::string> mapMetaType {
   { "Boolean",       "bool" },
   { "encoding",      "enums::Encoding" },
   { "frame",         "enums::Frame" },
   { "interaction",   "enums::Interaction" },
   { "interpolation", "enums::Interpolation" },
   { "storageOrder",  "enums::StorageOrder" }
};

// JSON attribute "default" to GNDStk default
const std::map<std::string,std::string> mapMetaDefault {
   { "Float64",  "\"Float64\"" },

   // encoding
   { "ascii", "enums::Encoding::ascii" },
   { "utf8",  "enums::Encoding::utf8" },

   // frame
   { "lab",          "enums::Frame::lab" },
   { "centerOfMass", "enums::Frame::centerOfMass" },

   // interaction
   { "nuclear", "enums::Interaction::nuclear" },
   { "atomic",  "enums::Interaction::atomic" },
   { "thermalNeutronScatteringLaw",
         "enums::Interaction::thermalNeutronScatteringLaw" },

   // interpolation
   { "flat",              "enums::Interpolation::flat" },
   { "charged-particle",  "enums::Interpolation::chargedparticle" },
   { "lin-lin",           "enums::Interpolation::linlin" },
   { "lin-log",           "enums::Interpolation::linlog" },
   { "log-lin",           "enums::Interpolation::loglin" },
   { "log-log",           "enums::Interpolation::loglog" },
   { "\\\\attr{lin-lin}", "enums::Interpolation::linlin" }, // :-/

   // storage order
   { "row-major",    "enums::StorageOrder::rowMajor" },
   { "column-major", "enums::StorageOrder::columnMajor" },

   // these must relate to auto-generating the GNDS manual
   { "`' (i.e. unitless)", "" }, // what's the `' all about?
   { " \\\\kern-1ex",      "" }, // note the leading space :-/
   { "`' (no label)",      "" }, // so, map to no label
   { "`none'",         "none" }  // lose the `...' (perhaps do generically?)
};



// -----------------------------------------------------------------------------
// Miscellaneous functions
// -----------------------------------------------------------------------------

std::string replace(std::string str, const char from, const char to)
{
   for (auto i = str.size(); i--; ) {

     if (str[i] == from)
        str[i] = to;
   }
   return str;
}

std::string uppercase(std::string str)
{
   for (auto i = str.size(); i--; ) {

     str[i] = toupper(str[i]);
   }
   return str;
}

std::string capitalize(std::string str)
{
   return str.size() ? (str[0] = toupper(str[0]), str) : str;
}

// metaType
std::string metaType(const nlohmann::json &value)
{
   // value of JSON "type", with mapMetaType applied
   assert(value.contains("type"));
   const std::string type = value["type"];
   const auto iter = mapMetaType.find(type);
   return iter == mapMetaType.end() ? type : iter->second;
}

// className
// Think "classType" to compare/contrast with metaType() above; equivalently,
// gives return value for derived-class className() for Component<DERIVED>.
// Not namespace qualified; namespace is added where, and if, it's needed.
std::string className(const nlohmann::json &value)
{
   // capitalize, per our class naming convention
   assert(value.contains("name"));
   std::string name = value["name"];
   name[0] = toupper(name[0]);
   return name;
}

// GNDSName
// Gives return value for derived-class GNDSName() for Component<DERIVED>.
std::string GNDSName(const nlohmann::json &value)
{
   // as-is; appears in actual GNDS files like this
   assert(value.contains("name"));
   return value["name"];
}

// fieldName
// Name for metadata or child-node field in the auto-generated class
std::string fieldName(const nlohmann::json &value)
{
   // as-is, except that we need to rename double :-/
   assert(value.contains("name"));
   const std::string name = value["name"];
   return name == "double" ? "Double" : name;
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
      const auto ndep = *iter;
      sourceVec.erase(iter);
      for (const auto &name : ndep.dependencies) {

        insertNDep(name, sourceVec, targetVec);
      }
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
      for (const auto &dep : ndep.dependencies) {

        std::cout << " " << dep.first << "::" << dep.second;
      }
      std::cout << std::endl;
   }
}



// -----------------------------------------------------------------------------
// check_*
// -----------------------------------------------------------------------------

// check_class
void check_class(
   const std::string &key, const nlohmann::json &value,
   bool &hasBodyText
) {
   if (debugging)
      std::cout << "Key: " << key << std::endl;

   assert(value.contains("name"));
   assert(value.contains("attributes"));
   assert(value.contains("childNodes"));
   assert(value.contains("description"));
   assert(value.contains("bodyText"));

   hasBodyText = !value["bodyText"].is_null();
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

      // consistency check: certain "occurrence" values ==> !required
      // Note: I'm unsure right now if "choice2" or "choice2+" will even exist.
      const std::string occurrence = field.value()["occurrence"];
      if (occurrence == "0+" ||
          occurrence == "choice" || occurrence == "choice+")
         assert(!field.value()["required"]); // !required
   }
}



// -----------------------------------------------------------------------------
// Functions: for output
// -----------------------------------------------------------------------------

// ------------------------
// re: output file
// ------------------------

void write_file_autogen(std::ostream &os)
{
   os << "\n// THIS FILE WAS AUTO-GENERATED!";
   os << "\n// DO NOT MODIFY!\n";
}

void write_file_prefix(std::ostream &os)
{
   // GNDStk
   os << "\n";
   os << "#include \"GNDStk.hpp\"\n";
   os << "using namespace njoy::GNDStk::core;\n";
   os << "\n";

   // namespace begin
   os << "namespace " + replace(Version,'.','_') + " {\n\n\n";
}

void write_file_suffix(std::ostream &os)
{
   // namespace end
   os << "\n";
   os << "} // namespace " + replace(Version,'.','_');
   os << "\n";

   // main
   os << "\n\n\n";
   os << large << "\n";
   os << "// main\n";
   os << large << "\n";
   os << "\n";
   os << "int main()\n";
   os << "{\n";
   os << "}\n";
}


// ------------------------
// re: class
// ------------------------

void write_class_prefix(
   std::ostream &os,
   const std::string &file_namespace, const std::string &clname,
   const bool hasBodyText
) {
   // comment introducing class
   os << "\n\n\n"
      << large << "\n"
      << "// " << file_namespace << "::\n"
      << "// class " << clname << "\n"
      << large << "\n"
      << "\n";

   // namespace + class begin
   os << "namespace " << file_namespace << " {\n\n"
      << "class " << clname << " : public Component<"
      << clname << (hasBodyText ? ",true" : "" /* default false */) << "> {\n";
}

void write_class_suffix(
   std::ostream &os,
   const std::string &file_namespace, const std::string &clname
) {
   // boilerplate assignment operators
   os << "\n   " << small
      << "\n   // Assignment"
      << "\n   " << small
      << "\n"
      << "\n   // copy"
      << "\n   " << clname << " &operator=(const " << clname << " &) = default;"
      << "\n"
      << "\n   // move"
      << "\n   " << clname << " &operator=(" << clname << " &&) = default;\n";

   // #include for custom code
   os << "\n   " << small
      << "\n   // Custom functionality"
      << "\n   " << small << "\n"
      << "\n   #include \"GNDStk/" << Version << "/"
      << file_namespace << "/" << clname << "/src/custom.hpp\"\n";

   // class + namespace end
   os << "\n}; // class " << clname << "\n"
      << "\n} // namespace " << file_namespace << "\n";
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Functions for in-class constructs
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

// infoMetadata
class infoMetadata {
public:
   // metadata can have:
   //    - optional
   //    - defaulted
   // but not vector
   std::string varName;
   std::string varType;     // underlying type
   std::string fullVarType; // with any optional<>, defaulted<>
   std::string theDefault;
   bool        isOptional;
   bool        isDefaulted;
};

// infoChildren
class infoChildren {
public:
   // children can have:
   //    - optional
   //    - vector
   // but not defaulted
   std::string varName;
   std::string varType;     // underlying type
   std::string fullVarType; // with any optional<> or vector<>
   std::string halfVarType; // withOUT any vector<>
   bool        isOptional;
   bool        isVector;    // if also isChoice, then "choice+" was used
   bool        isChoice;    // is part of a set of choices
   std::string varNameSeq;
};

// to_string
// See: https://github.com/nlohmann/json/issues/642
std::string to_string(const nlohmann::json &j)
{
   const auto tmp = j.dump();
   return j.type() == nlohmann::json::value_t::string
      ? tmp.substr(1, tmp.size()-2)
      : tmp;
}



// -----------------------------------------------------------------------------
// compute_metadata
// Also creates entries in vecInfoMetadata, for later use
// -----------------------------------------------------------------------------

void compute_metadata(
   std::ostream &ossm, // in caller, this is a temporary ostringstream
   const nlohmann::json &attrs,
   std::vector<infoMetadata> &vecInfoMetadata // output
) {
   // here, we're within the public struct for raw GNDS content
   ossm << "\n      // metadata\n";

   for (const auto &field : attrs.items()) {
      // the default
      std::string theDefault = "";
      if (!field.value()["default"].is_null()) {
         theDefault = to_string(field.value()["default"]);
         const auto iter = mapMetaDefault.find(theDefault);
         if (iter != mapMetaDefault.end())
            theDefault = iter->second;
      };

      if (theDefault != "") {
         if (debugging)
            std::cout << "theDefault: \"" << theDefault << "\"\n";
         // It makes sense that the following would be true. If something is
         // required, then why give it a "default"? The original JSONs actually
         // had a couple of cases for which this wasn't the case. For those, I
         // changed "default" to null. If doing so was wrong, we can revert the
         // JSON files in question, and change or remove the following.
         assert(!field.value()["required"]); // <== had default, so not required
      }

      // optional? (not required, and has no default)
      const bool opt = !field.value()["required"] && theDefault == "";
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // defaulted? (not required, but *does* have a default)
      const bool def = !field.value()["required"] && theDefault != "";
      const std::string defPrefix = def ? "Defaulted<" : "";
      const std::string defSuffix = def ? ">" : "";

      // sanity check
      assert(
         (optPrefix == ""  &&  defPrefix == "") || // neither, or...
         (optPrefix == "") != (defPrefix == "")    // XOR
      );

      // type
      const std::string varType = metaType(field.value());

      // full type (including any optional or defaulted)
      const std::string fullVarType =
         optPrefix + defPrefix +
         varType +
         defSuffix + optSuffix;

      // name
      const std::string varName = fieldName(field.value());

      // write
      ossm << "      " << fullVarType << " " << varName;
      if (theDefault != "") ossm << "{" << theDefault << "}";
      ossm << ";\n";

      // add to vecInfoMetadata, to be used later
      vecInfoMetadata.push_back(infoMetadata{});
      vecInfoMetadata.back().varName     = varName;
      vecInfoMetadata.back().varType     = varType;
      vecInfoMetadata.back().fullVarType = fullVarType;
      vecInfoMetadata.back().theDefault  = theDefault;
      vecInfoMetadata.back().isOptional  = opt;
      vecInfoMetadata.back().isDefaulted = def;
   }
} // compute_metadata



// -----------------------------------------------------------------------------
// compute_children
// Also creates entries in vecInfoChildren, for later use
// -----------------------------------------------------------------------------

void compute_children(
   std::ostream &ossc, // in caller, this is a temporary ostringstream
   const nlohmann::json &elems,
   std::vector<infoChildren> &vecInfoChildren, // output
   // additional parameters, in comparison with compute_metadata() above
   const std::string &file_namespace, // JSONs file's overall "__namespace__"
   const std::string &clname, // name of enclosing class; plain, no namespace::
   NameDeps &ndep,
   const std::multimap<std::string,std::string> &class2nspace
) {
   // here, we're within the public struct for raw GNDS content
   ossc << "\n      // children\n";

   std::string names;
   for (const auto &field : elems.items()) {
      // optional?
      const bool opt = !field.value()["required"];
      const std::string optPrefix = opt ? "std::optional<" : "";
      const std::string optSuffix = opt ? ">" : "";

      // vector?
      const std::string occurrence = field.value()["occurrence"];
      std::string vecPrefix;
      std::string vecSuffix;
      bool vec, choice;

      if (occurrence == "0+" || occurrence == "1+" ||
          occurrence == "2+" || occurrence == "choice2+") {
         vec = true;
         choice = false;
         vecPrefix = "std::vector<";
         vecSuffix = ">";
      } else if (occurrence == "choice") {
         vec = false;
         choice = true;
      } else if (occurrence == "choice+") {
         vec = true; // <== for the choice, not for this field individually
         choice = true;
      } else {
         vec = false;
         choice = false;
      }

      // I think this is always true; if choice, wouldn't be required
      if (choice)
         assert(opt);

      // type (and compute and prepend its namespace)
      std::string ns, varType = className(field.value());
      {
         // Determine what namespace varType belongs in. The scenario: we're
         // inside of a file with "__namespace__" file_namespace, in a class
         // with name clname, looking at a child node with name varType.
         const auto value = field.value();

         // we'll recognize either of these, but disallow both together...
         assert(!(value.contains("namespace") &&
                  value.contains("__namespace__")));

         if (value.contains("namespace")) {
            ns = value["namespace"];
         } else if (value.contains("__namespace__")) {
            ns = value["__namespace__"];
         } else if (class2nspace.count(varType) == 0) {
            log::warning(
               "{}::{} has child of unknown class {}.",
               file_namespace, clname, varType
            );
            ns = "unknownNamespace";
         } else if (class2nspace.count(varType) == 1) {
            // child class is in exactly one namespace; use it
            ns = class2nspace.find(varType)->second;
         } else {
            // child class is in >= 2 namespaces; one of them must be the
            // current one, or we consider this situation to be ambiguous
            for (auto it = class2nspace.equal_range(varType).first;
                 it != class2nspace.equal_range(varType).second; ++it) {

              if (it->second == file_namespace) // current namespace...
                ns = file_namespace; // ...is presumed; good news
            }

            if (ns == "") { // none of the >= 2 are in current namespace :-(
               std::stringstream warn;
               int count = 0;
               for (auto it = class2nspace.equal_range(varType).first;
                    it != class2nspace.equal_range(varType).second; ++it) {

                 warn << (count++ ? ", " : "") << it->second;
               }
               log::warning(
                  "{}::{} has child of ambiguous type {}.\n"
                  "Child type {} appears in all of these namespaces:\n{}",
                  file_namespace, clname, varType, varType, warn.str()
               );
               ns = "ambiguousNamespace";
            }
         }

         // prepend varType with its namespace
         varType = ns + "::" + varType;
      }

      // full type (including any optional or vector)
      // If both, it's a optional<vector>; the reverse would make less sense
      const std::string fullVarType =
         optPrefix + vecPrefix +
         varType +
         vecSuffix + optSuffix;

      // partial type (not including any vector); this is used in the context
      // of this child node's element of the multi-query key, where the Child
      // object's one/many status causes vector to be added if it's appropriate
      const std::string halfVarType =
         optPrefix +
         varType +
         optSuffix;

      // name
      const std::string varName = fieldName(field.value());
      if (choice)
         names += (names == "" ? "" : " ") + varName;

      // write to struct {...} content
      if (!choice)
         ossc << "      " << fullVarType << " " << varName << ";\n";

      // save as a dependency - if it's not its own dependency (in which case,
      // presumably, a pointer is involved, or we're out of luck in any event)
      if (varType != clname)
         ndep.dependencies.
            push_back(std::make_pair(ns,className(field.value())));

      // vecInfoChildren
      vecInfoChildren.push_back(infoChildren{});

      vecInfoChildren.back().varName     = varName;
      vecInfoChildren.back().varType     = varType;
      vecInfoChildren.back().fullVarType = fullVarType;
      vecInfoChildren.back().halfVarType = halfVarType;
      vecInfoChildren.back().isOptional  = opt;
      vecInfoChildren.back().isVector    = vec;
      vecInfoChildren.back().isChoice    = choice;
   }

   for (const auto &c : vecInfoChildren) {

     if (c.isChoice) {
        vecInfoChildren.push_back(infoChildren{});

        vecInfoChildren.back().varName     = "choice";
        vecInfoChildren.back().varType     = "VARIANT";
        vecInfoChildren.back().fullVarType = c.isVector
           ? "std::vector<VARIANT>"
           : "VARIANT";
        vecInfoChildren.back().halfVarType = "VARIANT";
        vecInfoChildren.back().isOptional  = false;
        vecInfoChildren.back().isVector    = c.isVector;
        vecInfoChildren.back().isChoice    = false; // for choice itself
        vecInfoChildren.back().varNameSeq  = names;
        ossc << "      " << vecInfoChildren.back().fullVarType << " "
             << vecInfoChildren.back().varName << ";\n";
        break;
     }
   }
} // compute_children



// -----------------------------------------------------------------------------
// write_keys
// Names and keys for the Component base
// -----------------------------------------------------------------------------

void write_keys(
   std::ostream &os,
   const nlohmann::json &value,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren,
   const std::string &nsname,
   const bool hasBodyText
) {
   // using VARIANT = ..., if necessary
   for (const auto &child : vecInfoChildren) {

     if (child.isChoice) {
        os << "\n   using VARIANT = std::variant<";
        std::size_t count = 0;
        for (const auto &c : vecInfoChildren)
           if (c.isChoice)
              os << (count++ ? "," : "") << "\n      " << c.varType;
        os << "\n   >;\n";
        break;
     }
   }

   // names
   const std::string name = className(value);
   const std::string gnds = GNDSName(value);

   os << "\n";
   os << "   " << small << "\n";
   os << "   // For Component\n";
   os << "   " << small << "\n";
   os << "\n";
   os << "   friend class Component<" << name << (hasBodyText ? ",true" : "");
   os << ">;\n\n";
   os << "   // Current namespace, current class, and GNDS node name\n";
   os << "   static auto namespaceName() { return \"" << nsname << "\"; }\n";
   os << "   static auto className() { return \"" << name << "\"; }\n";
   os << "   static auto GNDSName() { return \"" << gnds << "\"; }\n\n";

   // keys begin
   os << "   // Core Interface construct to extract metadata and child nodes\n";
   os << "   static auto keys()\n";
   os << "   {\n";

   // keys
   if (vecInfoMetadata.size() + vecInfoChildren.size() == 0)
      os << "      return std::tuple<>{};\n";
   else {
      os << "      return";

      // metadata
      std::size_t count = 0;
      for (const auto &m : vecInfoMetadata) {

        os << (count++ ? " |\n" : "\n         // metadata\n")
           << "         " << m.fullVarType << "{" << m.theDefault << "}\n"
           << "            / Meta<>(\""  << m.varName << "\")";
      }

      // children
      if (vecInfoChildren.size() && count)
         os << " |";
      count = 0;
      for (const auto &c : vecInfoChildren) {

        if (!c.isChoice)
           os << (count++ ? " |\n" : "\n         // children\n")
              << "         " << c.halfVarType << "{}\n" // w/o any std::vector<>
              << "            / " << (c.isVector ? "++" : "--") << "Child<>(\""
              << (c.varNameSeq == "" ? c.varName : c.varNameSeq) << "\")";
      }
      os << "\n      ;\n";
   }

   // keys end
   os << "   }\n";
   os << "\n";
   os << "public:\n";
}



// -----------------------------------------------------------------------------
// write_getters
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

void getter_param_1(
   std::ostream &os,
   const std::string &varName,
   const std::string &paramType, const std::string &paramName
) {
   // comment
   os << "\n   // " << varName << "(" << paramName << ")\n";

   // getter: const
   os << "   const auto &" << varName;
   os << "(const " << paramType << paramName << ") const\n";
   os << "    { return getter(" << varName;
   os << "()," << paramName << "," << "\"" << varName << "\"); }\n";

   // getter: non-const
   os << "   auto &" << varName;
   os << "(const " << paramType << paramName << ")\n";
   os << "    { return getter(" << varName;
   os << "()," << paramName << "," << "\"" << varName << "\"); }\n";
}

void getter_param_2(
   std::ostream &os,
   const std::string &varType, const std::string &varName,
   const std::string &paramType, const std::string &paramName
) {
   // choice is a vector<variant>
   os << "\n   // optional " << varName << "(" << paramName << ")\n";
   os << "   auto " << varName << "(const " << paramType << paramName;
   os << ") const\n" << "   {\n";
   os << "      return getter<" << varType << ">";
   os << "(choice()," << paramName << ",\"" << varName << "\");\n";
   os << "   }\n";
}


// ------------------------
// write_getters
// ------------------------

void write_getters(
   std::ostream &os,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   os << "\n   " << small;
   os << "\n   // Getters";
   os << "\n   // const and non-const";
   os << "\n   " << small << "\n";

   // ------------------------
   // metadata
   // ------------------------

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

   // ------------------------
   // children
   // ------------------------

   bool isVec = false;
   for (const auto &c : vecInfoChildren) {
      if (c.isChoice) {
         isVec = c.isVector; // <== all should be consistent in this regard
         continue;
      }

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

      // getters for [optional] vector: accept (const std::size_t n)
      if (c.isVector) {
         getter_param_1(os, c.varName, "std::size_t ",  "n");
         getter_param_1(os, c.varName, "std::string &", "label");
      }
   }

   for (const auto &c : vecInfoChildren) {
      if (!c.isChoice)
         continue;

      if (isVec) {
         getter_param_2(os, c.varType, c.varName, "std::size_t ",  "n");
         getter_param_2(os, c.varType, c.varName, "std::string &", "label");
      } else {
         // choice is a variant
         os << "\n   // optional " << c.varName << "\n";
         os << "   auto " << c.varName << "() const\n";
         os << "   {\n";
         os << "      return getter<" << c.varType << ">";
         os << "(choice()," << "\"" << c.varName << "\");\n";
         os << "   }\n";
      }
   }
}



// -----------------------------------------------------------------------------
// write_setters
// -----------------------------------------------------------------------------

void write_setters(
   std::ostream &os,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren,
   const bool hasBodyText
) {
   os << "\n   " << small;
   os << "\n   // Setters";
   os << "\n   // non-const";
   os << "\n   " << small << "\n";

   // Reminder:
   //    metadata can have: optional, defaulted (but not vector)
   //    children can have: optional, vector (but not defaulted)

   // ------------------------
   // metadata
   // ------------------------

   for (const auto &m : vecInfoMetadata) {
      // comment
      os << "\n   // " << m.varName << "\n";

      // special cases: we want to send length, start, and valueType
      // down to the BodyText base as well
      const bool special = hasBodyText && (
         m.varName == "length" ||
         m.varName == "start" ||
         m.varName == "valueType"
      );

      // setter, for T as-is
      {
         os << "   auto &" << m.varName;
         os << "(const " << m.fullVarType << " &obj)\n";
         special
            ? os << "    { BaseBodyText::" << m.varName << "(content."
                 << m.varName << " = obj); return *this; }\n"
            : os << "    { content." << m.varName
                 << " = obj; return *this; }\n";
      }

      // setter, for T, if type is optional<T>
      // shouldn't need; T will convert to optional<T>

      // setter, for T, if type is Defaulted<T>
      if (m.isDefaulted) {
         os << "   auto &" << m.varName;
         os << "(const " << m.varType << " &obj)\n";
         special
            ? os << "    { BaseBodyText::" << m.varName << "(content."
                 << m.varName << " = obj); return *this; }\n"
            : os << "    { content." << m.varName
                 << " = obj; return *this; }\n";
      }
   }

   // ------------------------
   // children
   // ------------------------

   bool isVec = false;
   for (const auto &c : vecInfoChildren) {
      if (c.isChoice) {
         isVec = c.isVector; // <== all should be consistent in this regard
         continue;
      }

      // comment
      os << "\n   // " << c.varName << "\n";

      // setter, for T as-is
      {
         os << "   auto &" << c.varName;
         os << "(const " << c.fullVarType << " &obj)\n";
         os << "    { content." << c.varName << " = obj; return *this; }\n";
      }

      // setter, for T, if type is optional<T>
      // shouldn't need; T will convert to optional<T>

      // setter, for vector<T>, if type is optional<vector<T>>
      // equivalent to the above
   }

   for (const auto &c : vecInfoChildren) {
      if (!c.isChoice)
         continue;
      os << "\n";
      os << "   // " << c.varName << "\n";

      // getters, using individual names
      if (isVec) {
         // choice is a vector<variant>
         os << "   auto &" << c.varName << "(\n";
         os << "      const std::size_t n,\n";
         os << "      const std::optional<" << c.varType << "> &obj\n";
         os << "   ) {\n";
         os << "      detail::setter(choice(),n,obj," << "namespaceName()";
         os << ",className(),\"" << c.varName << "\");\n";
         os << "      return *this;\n";
         os << "   }\n";
      } else {
         // choice is a variant
         os << "   auto &" << c.varName << "(const std::optional<";
         os << c.varType << "> &obj)\n";
         os << "    { if (obj) choice(*obj); return *this; }\n";
      }
   }
}



// -----------------------------------------------------------------------------
// write_class_ctor
// -----------------------------------------------------------------------------

// helper
void write_component_base(
   std::ostream &os,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren,
   const bool have_other
) {
   os << "      Component{\n";
   have_other
      ? os << "         other"
      : os << "         BaseBodyText{}";

   for (const auto &m : vecInfoMetadata) { // metadata

      os << ",\n         content." + m.varName;
   }
   for (const auto &c : vecInfoChildren) { // children

     if (!c.isChoice)
        os << ",\n         content." + c.varName;
   }

   os << "\n      }";
}

// helper
void write_ctor_body(
   std::ostream &os,
   const std::string &param,
   const bool query = false
) {
   os << "   {\n";
   if (query)
      os << "      fromNode(node);\n";
   os << "      bodyTextUpdate(content);\n";
   os << "      construct(" << param << ");\n";
   os << "   }\n";
}



// write_class_ctor
void write_class_ctor(
   std::ostream &os,
   const std::string &clname,
   const std::vector<infoMetadata> &vecInfoMetadata,
   const std::vector<infoChildren> &vecInfoChildren
) {
   std::size_t count;
   os << "\n";

   // ------------------------
   // ctor: default
   // ------------------------

   // signature, and base constructor call
   os << "   // default\n";
   os << "   " << clname << "() :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, false);

   // body
   os << "\n";
   write_ctor_body(os,"");
   os << "\n";

   // ------------------------
   // ctor: copy
   // ------------------------

   // signature, and base constructor call
   os << "   // copy\n";
   os << "   " << clname << "(const " << clname << " &other) :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, true);

   // copy fields
   os << ",\n      content{other.content}";

   // body
   os << "\n";
   write_ctor_body(os,"other");
   os << "\n";

   // ------------------------
   // ctor: move
   // ------------------------

   // signature, and base constructor call
   os << "   // move\n";
   os << "   " << clname << "(" << clname << " &&other) :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, true);

   // copy fields
   os << ",\n      content{std::move(other.content)}";

   // body
   os << "\n";
   write_ctor_body(os,"other");
   os << "\n";

   // ------------------------
   // ctor: node
   // ------------------------

   // signature, and base constructor call
   os << "   // from node\n";
   os << "   " << clname << "(const Node &node) :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, false);

   // body
   os << "\n";
   write_ctor_body(os,"node",true);

   // ------------------------
   // ctor: fields
   // ------------------------

   if (vecInfoMetadata.size() + vecInfoChildren.size() == 0)
      return;
   os << "\n   // from fields\n";

   // signature, and base constructor call
   // Note: we don't really need "explicit" unless this constructor can be
   // called with one argument. We'll always put it in, however, just in
   // case someone modifies the auto-generated constructor (say, giving its
   // arguments defaults) in such a way that is *can* be called with one
   // argument. (But we'd rather nobody modify the auto-generated classes.)
   count = 0;
   os << "   explicit " << clname << "(";
   for (const auto &m : vecInfoMetadata) {

     os << (count++ ? ",\n" : "\n")
        << "      const " << m.fullVarType << " &" << m.varName;
   }
   for (const auto &c : vecInfoChildren) {

     if (!c.isChoice)
        os << (count++ ? ",\n" : "\n")
           << "      const " << c.fullVarType << " &" << c.varName;
   }
   os << "\n   ) :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, false);

   // initialize fields
   os << ",\n";
   os << "      content{";
   count = 0;
   for (const auto &m : vecInfoMetadata) {

     os << (count++ ? ",\n" : "\n") << "         " << m.varName;
   }
   for (const auto &c : vecInfoChildren) {

     if (!c.isChoice)
        os << (count++ ? ",\n" : "\n") << "         " << c.varName;
   }
   os << "\n      }\n";

   // body
   write_ctor_body(os,"",false);

   // ------------------------
   // ctor: fields but without
   // Defaulted<>, if there
   // are any Defaulted<>s
   // ------------------------

   bool def = false; // are there any Defaulted<>s?
   for (const auto &m : vecInfoMetadata) {

     if (m.isDefaulted)
        def = true;
   }
   // infoChildren doesn't have isDefaulted, so isn't a factor here
   if (!def)
      return;
   os << "\n   // from fields, with T replacing Defaulted<T>\n";

   // signature, and base constructor call
   count = 0;
   os << "   explicit " << clname << "(";
   for (const auto &m : vecInfoMetadata) {

     os << (count++ ? ",\n" : "\n") << "      const "
        << (m.isDefaulted ? m.varType : m.fullVarType) << " &" << m.varName;
   }
   for (const auto &c : vecInfoChildren) {

     if (!c.isChoice)
        os << (count++ ? ",\n" : "\n") << "      const "
           << c.fullVarType << " &" << c.varName;
   }
   os << "\n   ) :\n";
   write_component_base(os, vecInfoMetadata, vecInfoChildren, false);

   // initialize fields
   os << ",\n";
   os << "      content{";
   count = 0;
   for (const auto &m : vecInfoMetadata) {

     if (m.isDefaulted)
        os << (count++ ? ",\n" : "\n") << "         " << m.varName
           << " == " << m.theDefault << "\n"
           << "            ? " << m.fullVarType
           << "{" << m.theDefault << "}\n"
           << "            : " << m.fullVarType
           << "{" << m.theDefault << "," << m.varName << "}";
     else
        os << (count++ ? ",\n" : "\n") << "         " << m.varName;
   }
   for (const auto &c : vecInfoChildren) {

     if (!c.isChoice)
        os << (count++ ? ",\n" : "\n") << "         " << c.varName;
   }
   os << "\n      }\n";

   // body
   write_ctor_body(os,"",false);
}



// -----------------------------------------------------------------------------
// make_forward
// Receives each key/value pair in the outer {...} json level.
// Computes class2nspace.
// Creates some of the directory/file structure.
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
   std::string filePythonCPP;
   std::string fileGNDStkHPP;
};

// namespace name to file name (Python CPP for the namespace)
std::map<std::string,NSFile> namespace2file;

// namespace,class names to file names (GNDStk HPP and Python CPP for the class)
std::map<std::pair<std::string,std::string>,CLFile> class2files;


// make_forward
void make_forward(
   std::ostream &os,
   const std::string &file_namespace, // value of "__namespace__" in the file
   const std::string &key, const nlohmann::json &value,
   std::multimap<std::string,std::string> &class2nspace
) {
   // not a class?
   if (key == "__namespace__" || key == "Specifications")
      return;

   // not a node class?
   if (value["__class__"] != "nodes.Node")
      return;

   // class name
   const std::string clname = className(value);

   // forward declaration
   os << "namespace " << file_namespace << " { class " << clname << "; }\n";

   // for later use: map class to namespace(s) in which it's found
   class2nspace.insert(std::make_pair(clname,file_namespace));

   // ------------------------
   // Namespace+class files
   // ------------------------

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
   if (!std::ifstream(custom)) {
      std::cout << "   No file " << custom << std::endl;
      std::cout << "   ...So, creating a blank one" << std::endl;
      std::ofstream(custom,std::ofstream::app);
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
      CLFile{clcpppy,clhpp}
   ));

   // ------------------------
   // For Version.hpp
   // ------------------------

   // Handled after the earlier mkdir system() commands, so
   // that the necessary directories are guaranteed to exist
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

   static std::string last_file_namespace = "";
   if (last_file_namespace != file_namespace) {
      last_file_namespace = file_namespace;
      ofs << "\n"; // <== so, basically, do this when the namespace changes
   }

   ofs << "#include \"GNDStk/" << Version << "/";
   ofs << file_namespace << "/" << clname << ".hpp\"\n";
   first = false;
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
   const std::string clname = className(keyvalue.value());
   if (debugging)
      std::cout << "Class: " << clname << std::endl;
   bool hasBodyText = false;
   check_class(keyvalue.key(), keyvalue.value(), hasBodyText);

   // re: ordering
   // Save current namespace-qualified class name; we'll then add dependencies
   classDependencies.push_back(NameDeps{});
   auto &ndep = classDependencies.back();
   ndep.name = std::make_pair(file_namespace,clname);

   // output: class begin
   std::ostringstream oss;
   write_class_prefix(oss, file_namespace, clname, hasBodyText);
   const auto attrs = value["attributes"]; check_metadata(attrs);
   const auto elems = value["childNodes"]; check_children(elems);

   // metadata
   std::vector<infoMetadata> vecInfoMetadata;
   std::ostringstream ossm;
   if (attrs.size() != 0)
      compute_metadata(ossm, attrs, vecInfoMetadata);

   // children
   std::vector<infoChildren> vecInfoChildren;
   std::ostringstream ossc;
   if (elems.size() != 0)
      compute_children(ossc, elems, vecInfoChildren,
                     file_namespace, clname, ndep, class2nspace);

   // for later use
   class2info.insert(
      std::make_pair(
         std::make_pair(file_namespace,clname),
         std::make_pair(vecInfoMetadata,vecInfoChildren)
      )
   );

   // output: names, keys
   // As needed by the Component base
   write_keys(
      oss, keyvalue.value(), vecInfoMetadata, vecInfoChildren,
      file_namespace, hasBodyText
   );

   // output: base
   oss << "\n   // Base classes";
   oss << "\n   using BaseComponent = Component<"
       << clname << (hasBodyText ? ",true" : "") << ">;";
   oss << "\n   using BaseBodyText = BodyText<"
       <<           (hasBodyText ?  "true" : "false") << ">;\n";

   // output: defaults (applicable only to metadata)
   oss << "\n   " << small;
   oss << "\n   // Relevant defaults";
   oss << "\n   // FYI for users";
   oss << "\n   " << small;
   oss << "\n";
   oss << "\n   static const struct {\n";
   for (auto &m : vecInfoMetadata) {

     if (m.isDefaulted) {
        oss << "      const " << m.varType << " " << m.varName;
        oss << "{" << m.theDefault << "};\n";
     }
   }
   oss << "   } defaults;\n";

   // output: content (the metadata/children computed earlier)
   oss << "\n   " << small;
   oss << "\n   // Raw GNDS content";
   oss << "\n   " << small;
   oss << "\n";
   oss << "\n   struct {";
   oss << ossm.str();
   oss << ossc.str();
   if (ossm.str() == "" && ossc.str() == "") oss << "\n";
   oss << "   } content;\n";

   // output: getters, setters
   if (vecInfoMetadata.size() || vecInfoChildren.size()) {
      write_getters(oss, vecInfoMetadata, vecInfoChildren);
      write_setters(oss, vecInfoMetadata, vecInfoChildren, hasBodyText);
   }

   // output: constructors
   oss << "\n   " << small
       << "\n   // Construction"
       << "\n   " << small
       << "\n";
   write_class_ctor(oss, clname, vecInfoMetadata, vecInfoChildren);

   // output: class end
   write_class_suffix(oss, file_namespace, clname);

   // save what we've written to oss
   if (debugging)
      std::cout
         << "ndep.name == "
         << ndep.name.first  << "::" << ndep.name.second << std::endl;
   const bool inserted =
      classCodeMap.insert(std::make_pair(ndep.name,oss.str())).second;
   assert(inserted);
}



// -----------------------------------------------------------------------------
// read JSON file
// -----------------------------------------------------------------------------

void read(const std::string &file, nlohmann::json &jdoc)
{
   std::cout << "File: \"" << file << '"' << std::endl;
   std::ifstream ifs(file);
   if (!ifs) {
      log::error("Could not open \"{}\"", file);
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
   for (auto &cl : sortedClassDependencies) {

     if (cl.name.first == nsname)
        cpp << "   void wrap" << cl.name.second << "(python::module &);\n";
   }
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
   for (auto &cl : sortedClassDependencies) {

     if (cl.name.first == nsname)
        cpp << "   " << nsname << "::wrap" << cl.name.second
            << "(submodule);\n";
   }
   cpp << "};\n";

   cpp << "\n} // namespace " << underver << "\n";
}



// -----------------------------------------------------------------------------
// file_python_class
// -----------------------------------------------------------------------------

std::string toPythonName( const std::string& name ) {

  std::string python;
  python += std::tolower( name[0] );
  for ( auto iter = name.begin() + 1; iter != name.end(); ++iter ) {

    if ( std::isupper( *iter ) && std::islower( *( iter - 1 ) ) ) {

      python += '_';
    }
    python += std::tolower( *iter );
  }
  return python;
}

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
   cpp << "#include \"definitions.hpp\"\n";
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
   cpp << "   using Component = " << "njoy::GNDStk::" << VersionNamespace << "::" << nsname << "::" << clname << ";\n";
   cpp << "\n";
   cpp << "   // create the component\n";
   cpp << "   python::class_<Component> component(\n";
   cpp << "      module,\n";
   cpp << "      \"" << clname << "\",\n";
   cpp << "      Component::help().c_str()\n";
   cpp << "   );\n";
   cpp << "\n";
   cpp << "   // wrap the component\n";
   cpp << "   component\n";
   cpp << "      .def(\n";

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
      cpp << "            const " << (m.isDefaulted ? m.varType : m.fullVarType);
      cpp << (++count < total ? " &,\n" : " &\n");
   }
   for (auto &c : cinfo) {
      cpp << "            const " << c.fullVarType;
      cpp << (++count < total ? " &,\n" : " &\n");
   }
   cpp << "         >(),\n";

   // python::arg...
   for (auto &m : minfo) {

     cpp << "         python::arg(\"" << toPythonName( m.varName ) << "\")";
     if (m.isDefaulted) {

        cpp << " = " << m.theDefault;
     }
     else {

       if (m.isOptional) {

          cpp << " = std::nullopt";
       }
     }
     cpp << ",\n";
   }
   for (auto &c : cinfo) {

     cpp << "         python::arg(\"" << toPythonName( c.varName ) << "\")";
     if (c.isOptional) {

        cpp << " = std::nullopt";
     }
     cpp << ",\n";
   }

   cpp << "         Component::help(\"constructor\").c_str()\n";
   cpp << "      )\n";

   // .def_property_readonly...
   for (auto &m : minfo) {
      const auto name = m.varName;
      const auto pythonname = toPythonName( m.varName );
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << pythonname << "\",\n";
      cpp << "         &Component::" << name << ",\n";
      cpp << "         Component::help(\"" << pythonname << "\").c_str()\n";
      cpp << "      )\n";
   }
   for (auto &c : cinfo) {
      const auto name = c.varName;
      const auto pythonname = toPythonName( c.varName );
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << pythonname << "\",\n";
      cpp << "         &Component::" << name << ",\n";
      cpp << "         Component::help(\"" << pythonname << "\").c_str()\n";
      cpp << "      )\n";
   }

   // finish up
   cpp << "   ;\n\n";
   cpp << "   // add standard component definitions\n";
   cpp << "   addStandardComponentDefinitions< Component >( component );\n";
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
      const std::string nsname = jdoc["__namespace__"];
      for (const auto &item : jdoc.items()) {

        make_forward(ofs, nsname, item.key(), item.value(), class2nspace);
      }
   }
   std::ofstream ver(HPPforVersion, std::ofstream::app);
   ver << "\n#endif\n";
   ver.close();

   // FYI
   if (debugging)
      for (const auto &val : class2nspace) {

        std::cout << val.first << ": " << val.second << std::endl;
      }

   // Print classes into temporary strings, because they have to be reordered
   // later (per dependencies) for final output
   std::cout << "\nBuilding classes..." << std::endl;
   for (auto &file : files) {
      read(file,jdoc);
      const std::string file_namespace = jdoc["__namespace__"];
      for (const auto &keyvalue : jdoc.items()) {

        make_class(keyvalue, file_namespace, class2nspace);
      }
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
         map< pair<nsname,clname>, {filePythonCPP,fileGNDStkHPP} >

      namespace2file:
         map<      nsname,         {filePythonCPP} >

      */

      for (auto &obj : sortedClassDependencies) {
         // code
         const auto code = classCodeMap.find(obj.name);
         assert(code != classCodeMap.end());

         // hpp and Python cpp files for the class
         const auto file = class2files.find(obj.name);
         assert(file != class2files.end());
         const auto &filePythonCPP = file->second.filePythonCPP;
         const auto &fileGNDStkHPP = file->second.fileGNDStkHPP;

         // class-specific hpp file
         std::ofstream hpp(fileGNDStkHPP,std::ofstream::app);
         const std::string guard =
            "NJOY_GNDSTK_" + uppercase(replace(Version,'.','_')) + "_" +
            uppercase(obj.name.first) + "_" + uppercase(obj.name.second);
         hpp << "\n#ifndef " << guard;
         hpp << "\n#define " << guard << "\n";
         hpp << "\n"
             << "// core interface\n"
             << "#include \"GNDStk.hpp\"\n"
             << "\n";
         if (obj.dependencies.size() > 0) {
            hpp << "// " << Version << " dependencies\n";
            for (const auto &dep : obj.dependencies) {

              hpp << "#include \"GNDStk/" << Version << "/"
                  << dep.first << "/" << dep.second << ".hpp\"\n";
            }
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
