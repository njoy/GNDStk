
WORK IN PROGRESS!!
INCOMPLETE!!

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Tool for autogenerating GNDStk classes from JSON specs
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;
#include "cstring"

// Print extra chatter?
// We'd prefer the name "debug", but that would conflict with GNDStk::debug.
const bool debugging = true;

// Report instances of nodes with (1) no metadata and (2) only one child node?
// For example, <reactions> in GNDS v1.9 has no metadata, and only <reaction>
// as a child node. A case could be made that a well-designed spec shouldn't
// have such intermediaries. So, this flag allows us to find and report them.
const bool singletons = true;

// Comment-related markup.
const auto large = "// " + std::string(77,'-');
const auto small = "// " + std::string(24,'-');



// -----------------------------------------------------------------------------
// For a topological sort: classes
// These relate to the ordering of class definitions based on their dependencies
// -----------------------------------------------------------------------------

// Namespace and class
class NamespaceAndClass {
public:
   std::string nsname; // name of a namespace
   std::string clname; // name of a class in the namespace

   NamespaceAndClass(const std::string &ns="", const std::string &cl="") :
      nsname(ns),
      clname(cl)
   { }

   bool operator==(const NamespaceAndClass &other) const
   {
      return
         nsname == other.nsname &&
         clname == other.clname;
   }
};

// Class2Dependencies
// For a {namespace,class}, its {namespace,class} dependencies
class Class2Dependencies {
public:
   NamespaceAndClass object;
   std::vector<NamespaceAndClass> dependencies;
};



// -----------------------------------------------------------------------------
// Per-class information
// That is, information we'll collect for each child node in the input .json(s)
// -----------------------------------------------------------------------------

// InfoMetadata
class InfoMetadata {
public:
   // A .json spec can make a metadatum be:
   //    - a std::optional, or
   //    - a GNDStk::defaulted
   // but (in contrast with child nodes) can't make it be a vector of metadata.
   // An individual metadatum may be a vector in its own right, as in an XML
   // construct such as <element meta="1,2,3,4"> (so that meta is a vector of
   // integers). We mean here that there isn't a vector of such [meta] entries,
   // and shouldn't be (XML wouldn't allow it).
   std::string varName;
   std::string varType;     // underlying type
   std::string varTypeFull; // with any optional<> or defaulted<>
   bool        isOptional;
   bool        isDefaulted;
   std::string theDefault;
};

// InfoChildren
class InfoChildren {
public:
   // A .json spec can make a child node be:
   //    - a std::optional, and/or
   //    - a std::vector
   // but can't make it be a GNDStk::defaulted. (The use of a default value for
   // child nodes just doesn't exist in the GNDS specs, even though the concept
   // would seem to make sense.)
   std::string varName;
   std::string varType;     // underlying type
   std::string varTypeFull; // with any optional<> or vector<>
   std::string varTypeHalf; // withOUT any vector<>
   bool        isOptional;
   bool        isVector;
};

// InfoChoiceChild
class InfoChoiceChild {
public:
   std::string varName;
   std::string varType;
   bool        isVector;
};

// InfoVariants
class InfoVariants {
public:
   std::string varName;
   std::string varType;     // underlying type
   std::string varTypeFull; // with any optional<> or vector<>
   std::string varTypeHalf; // withOUT any vector<>
   bool        isVector;
   std::vector<InfoChoiceChild> children;
};

// InfoData
class InfoData {
public:
   bool has;
   std::string type;
};

// PerClass
class PerClass {
public:
   // Actual printed code for the class. We build this up and then print
   // it later, after having determined a dependency-aware class ordering.
   std::string code;
   /// in old code: classCodeMap

   // Information about the contents of the class...

   // ...its metadata
   // ...its standard children
   // ...its "choice" children
   std::vector<InfoMetadata> metadata;
   std::vector<InfoChildren> children;
   std::vector<InfoVariants> variants;
   /// in old code: class2info

   // ...its data/"body text", if applicable
   InfoData data;
   /// in old code: class2bodytext
};



// -----------------------------------------------------------------------------
// Overarching data structure reflecting all of the autogenerator's input
// as well as various processed information
// -----------------------------------------------------------------------------

class Info {
public:

   // From the .json file on the command line
   std::string JSONDir;
   std::vector<std::string> JSONFiles;
   std::string GNDSDir;
   std::string Version;

   // Directory-prefixed name of the .hpp file for this GNDS version
   std::string VersionHPP;

   // Changes to apply to a metadatum's or child node's name.
   // Example: "double" (GNDS v1.9 does have this) to "Double" for C++.
   std::map<std::string,std::string> mapName;

   // Changes to apply to metadata/attribute type and default.
   // Examples: "Boolean" to "bool", "interpolation" to "enums::Interpolation".
   std::map<std::string,std::string> mapMetaType;
   std::map<std::string,std::string> mapMetaDefault;

   /// should be computed early with file pre-scan, then used later
   std::multimap<std::string,std::string> class2nspace;

   // Class dependencies: as originally determined, and after being sorted
   // by our topological sort.
   // These objects look like this:
   //    vector<{
   //       object = {nsname,clname},
   //       dependencies = vector<{nsname,clname}>
   //    }>
   // where each element in the vector is a namespace::class along with
   // the namespace::classes on which it depends.
   std::vector<Class2Dependencies> ClassDependenciesRaw;
   std::vector<Class2Dependencies> ClassDependenciesSorted;

   // Map from {namespace::class} to information about the class
   std::map<NamespaceAndClass,PerClass> class2data;

}; // class Info



// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// Is this a class that's meaningful to autogenerate?
bool isClass(const std::string &key, const nlohmann::json &value)
{
   // not a class?
   if (key == "__namespace__" || key == "namespace" || key == "Specifications")
      return false;

   // not a node class?
   if ((value.contains("__class__") && value["__class__"] != "nodes.Node") ||
       (value.contains(  "class"  ) && value[  "class"  ] != "nodes.Node"))
      return false;

   return true;
}



// -----------------------------------------------------------------------------
// Read JSON file
// -----------------------------------------------------------------------------

nlohmann::json readJSON(const std::string &file, const bool print = false)
{
   // Depending on call context, we might want to print the file name
   if (print)
      std::cout << "File: \"" << file << '"' << std::endl;

   std::ifstream ifs(file);
   if (!ifs) {
      log::error("Could not open file \"{}\"", file);
      throw std::exception{};
   }

   nlohmann::json j;
   ifs >> j;
   return j;
}



// -----------------------------------------------------------------------------
// Functions: get*JSON
// -----------------------------------------------------------------------------

// getMetadataJSON
template<bool required>
auto getMetadataJSON(const nlohmann::json &j)
{
   static const std::string metastr = "metadata";
   static const std::string attrstr = "attributes";

   const bool meta = j.contains(metastr);
   const bool attr = j.contains(attrstr);

   if constexpr (required) {
      assert(meta != attr); // not both, but one
      return meta ? j[metastr] : j[attrstr];
   } else {
      assert(!(meta && attr)); // not both
      return std::optional<nlohmann::json>(
         meta ? j[metastr] : attr ? j[attrstr] : nlohmann::json{}
      );
   }
}

// getChildrenJSON
template<bool required>
auto getChildrenJSON(const nlohmann::json &j)
{
   static const std::string chldstr = "children";
   static const std::string nodestr = "childNodes";

   const bool chld = j.contains(chldstr);
   const bool node = j.contains(nodestr);

   if constexpr (required) {
      assert(chld != node); // not both, but one
      return chld ? j[chldstr] : j[nodestr];
   } else {
      assert(!(chld && node)); // not both
      return std::optional<nlohmann::json>(
         chld ? j[chldstr] : node ? j[nodestr] : nlohmann::json{}
      );
   }
}

// getDataJSON
void getDataJSON(const nlohmann::json &j, bool &hasData, std::string &dataType)
{
   static const std::string datastr = "data";
   static const std::string bodystr = "bodyText";

   const bool data = j.contains(datastr) && !j[datastr].is_null();
   const bool body = j.contains(bodystr) && !j[bodystr].is_null();

   assert(!(data && body)); // not both
   hasData  = data || body;
   dataType = data ? j[datastr] : "";
}



// -----------------------------------------------------------------------------
// See the comment for bool singletons near the beginning of this file
// -----------------------------------------------------------------------------

void printSingletons(const std::string &file)
{
   if (!singletons)
      return;
   const nlohmann::json &jfile = readJSON(file,true);

   for (const auto &item : jfile.items()) {
      const std::string parent = item.key();
      const nlohmann::json rhs = item.value();
      if (!isClass(parent,rhs))
         continue;

      const auto metadata = getMetadataJSON<true>(rhs);
      const auto children = getChildrenJSON<true>(rhs);

      if (metadata.size() == 0 && children.size() == 0) {
         log::info("Class \"{}\" has no metadata and no children", parent);
         continue;
      }

      if (metadata.size() == 0 && children.size() == 1) {
         log::info("Class \"{}\" has no metadata and just one child", parent);
         continue;
      }
   }
}




// -----------------------------------------------------------------------------
// Gather information from the .json file given on the command line
// -----------------------------------------------------------------------------

// Helper: isComment
bool isComment(const std::string &key)
{
   return strncmp(key.data(), "//", 2) == 0;
}

// ------------------------
// changesFile
// ------------------------

bool changesFile(const std::string &jfile, Info &info)
{
   const nlohmann::json jchanges = readJSON(jfile);
   using pair = std::pair<std::string,std::string>;

   // Changes to name?
   if (jchanges.contains("name"))
      for (const auto &item : jchanges["name"].items())
         if (!isComment(item.key()))
            info.mapName.insert(pair(item.key(),item.value()));

   // Changes to metadata/attributes?
   const auto metadata = getMetadataJSON<false>(jchanges);
   if (metadata.has_value()) {
      // from/to pairs for "type"
      if (metadata->contains("type"))
         for (const auto &item : (*metadata)["type"].items())
            if (!isComment(item.key()))
               info.mapMetaType.insert(pair(item.key(),item.value()));
      // from/to pairs for "default"
      if (metadata->contains("default"))
         for (const auto &item : (*metadata)["default"].items())
            if (!isComment(item.key()))
               info.mapMetaDefault.insert(pair(item.key(),item.value()));
   }

   // Debugging information
   if (debugging) {
      for (const auto &pair : info.mapName)
         std::cout << "name: "
                   << pair.first << " ==> " << pair.second << std::endl;
      std::cout << std::endl;
      for (const auto &pair : info.mapMetaType)
         std::cout << "metadata type: "
                   << pair.first << " ==> " << pair.second << std::endl;
      std::cout << std::endl;
      for (const auto &pair : info.mapMetaDefault)
         std::cout << "metadata default: "
                   << pair.first << " ==> " << pair.second << std::endl;
   }

   return true;
}

// ------------------------
// commandLine
// ------------------------

bool commandLine(const int argc, const char *const *const argv, Info &info)
{
   // Keys we'll look for
   static const std::string input   = "JSONDir";
   static const std::string files   = "JSONFiles";
   static const std::string output  = "GNDSDir";
   static const std::string version = "Version";
   static const std::string changes = "Changes";

   // Usage
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " file.json" << std::endl;
      return false;
   }

   // Input file
   const nlohmann::json jmain = readJSON(argv[1]);

   // Validate content
   if (!(jmain.contains(input  ) &&
         jmain.contains(files  ) &&
         jmain.contains(output ) &&
         jmain.contains(version)
   )) {
      log::error("The input json file needs {}, {}, {}, and {}",
                 input, files, output, version);
      return false;
   }

   // Extract information from the command-line .json
   info.JSONDir   = jmain[input];
   info.JSONFiles = std::vector<std::string>(jmain[files]);
   info.GNDSDir   = jmain[output];
   info.Version   = jmain[version];

   // Prepend the JSON file names with their directory
   for (std::string &file : info.JSONFiles)
      file = info.JSONDir + '/' + file;

   // Name of the .hpp file for this version
   info.VersionHPP = info.GNDSDir + "/src/GNDStk/" + info.Version + ".hpp";

   // Report on "singletons"
   for (const std::string &file : info.JSONFiles)
      printSingletons(file);

   // Changes?
   if (jmain.contains(changes))
      return changesFile(jmain[changes],info);
   return true;
}



// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// Replace character
std::string replace(std::string str, const char from, const char to)
{
   for (std::size_t i = str.size(); i--; )
      if (str[i] == from)
         str[i] = to;
   return str;
}

// Capitalize all letters
std::string allcaps(std::string str)
{
   for (std::size_t i = str.size(); i--; )
      str[i] = toupper(str[i]);
   return str;
}

// Capitalize the first letter, leaving others as-is
std::string capitalize(std::string str)
{
   if (str.size() > 0)
      str[0] = toupper(str[0]);
   return str;
}

/// The name "jpair" may not always be ideal below...

// A "type" key's value, with any info.mapMetaType entry applied
std::string getMetaType(const nlohmann::json &jpair, const Info &info)
{
   assert(jpair.contains("type"));
   const std::string type = jpair["type"];
   const auto it = info.mapMetaType.find(type);
   return it == info.mapMetaType.end() ? type : it->second;
}

// Get namespace
std::string getNamespace(const nlohmann::json &jpair)
{
   return jpair.contains("__namespace__")
      ? jpair["__namespace__"]
      : jpair[  "namespace"  ];
}

// toString
// See: https://github.com/nlohmann/json/issues/642
/// remark about the purpose of this; also, is the -2 safe?
std::string toString(const nlohmann::json &j)
{
   const auto tmp = j.dump();
   return j.type() == nlohmann::json::value_t::string
      ? tmp.substr(1, tmp.size()-2)
      : tmp;
}



// -----------------------------------------------------------------------------
// Functions: name-related
// Name in GNDS (e.g., name of an XML element)
// Name of an autogenerated class
// Name of a field (metadatum or child node) in an autogenerated class
// -----------------------------------------------------------------------------

// GNDSName
std::string GNDSName(
   const std::string &key,
   const nlohmann::json &value
) {
   // As-is, directly as stipulated in a key in the JSON spec, except
   // that we allow a "name" entry to override the key.
   return value.contains("name") ? std::string(value["name"]) : key;
}

// fieldName
std::string fieldName(
   const std::string &key,
   const nlohmann::json &value,
   const Info &info
) {
   // Like GNDSName, except that we apply any name-modification map that
   // may have been provided. That can fix, for example, the name "double",
   // which appears in GNDS v1.9 but is unsuitable for a name in C++.
   const std::string name = GNDSName(key,value);
   const auto it = info.mapName.find(name);
   return it == info.mapName.end() ? name : it->second;
}

// className
std::string className(
   const std::string &key,
   const nlohmann::json &value,
   const Info &info
) {
   // Like fieldName, but capitalized (per our class naming convention).
   return capitalize(fieldName(key,value,info));
}



// -----------------------------------------------------------------------------
// Functions: validate*
// -----------------------------------------------------------------------------

// validateMetadata
void validateMetadata(const nlohmann::json &attrs)
{
   for (const auto &field : attrs.items()) {
      if (debugging)
         std::cout << "   Metadatum: " << field.key() << std::endl;
      assert(field.value().contains("type"));
      assert(field.value().contains("required"));
   }
}

// validateChildren
void validateChildren(const nlohmann::json &elems)
{
   for (const auto &field : elems.items()) {
      if (debugging)
         std::cout << "   Child Node: " << field.key() << std::endl;
      assert(field.value().contains("occurrence"));
      assert(field.value().contains("required"));

      // Consistency check: certain "occurrence" values imply *not* required.
      // Remark: the GNDS manual speaks of "choice2" and "choice2+" options
      // for occurrence. We're not sure if those will remain, going forward,
      // in GNDS specs, so we won't worry now about how they might fit in.
      const std::string occ = field.value()["occurrence"];
      if (occ == "0+" || occ == "choice" || occ == "choice+")
         assert(!field.value()["required"]); // not required
   }
}

// validateClass
void validateClass(
   const nlohmann::json &entry,
   bool &hasData, std::string &dataType
) {
   // these must be there
   getMetadataJSON<true>(entry);
   getChildrenJSON<true>(entry);

   // data/bodyText is optional
   getDataJSON(entry,hasData,dataType);
}



// -----------------------------------------------------------------------------
// For a topological sort: functions
// Adapted from: http://coliru.stacked-crooked.com/a/7c0bf8d3443b804d
// -----------------------------------------------------------------------------

// insertDependency
void insertDependency(
   const NamespaceAndClass &wanted,
   std::vector<Class2Dependencies> &vecSource,
   std::vector<Class2Dependencies> &vecTarget
) {
   const auto iter = std::find_if(
      vecSource.begin(),
      vecSource.end(),
      [wanted](const Class2Dependencies &c2d) { return c2d.object == wanted; }
   );

   if (iter != vecSource.end()) {
      const Class2Dependencies c2d = *iter;
      vecSource.erase(iter);
      for (const NamespaceAndClass &dep : c2d.dependencies)
         insertDependency(dep, vecSource, vecTarget);
      vecTarget.push_back(c2d);
   }
}

// printDependencies
void printDependencies(
   const std::string &label,
   const std::vector<Class2Dependencies> &vec
) {
   // Debugging information
   if (debugging) {
      std::cout << label << std::endl;
      for (const Class2Dependencies &c2d : vec) {
         std::cout << "   " << c2d.object.nsname << "::" << c2d.object.clname;
         if (c2d.dependencies.size() > 0)
            std::cout << ":";
         for (const NamespaceAndClass &dep : c2d.dependencies)
            std::cout << " " << dep.nsname << "::" << dep.clname;
         std::cout << std::endl;
      }
   }
}



// -----------------------------------------------------------------------------
// Functions: some basic write*
// -----------------------------------------------------------------------------

// Admonishion
void writeAutogenerated(std::ostream &os)
{
   os << "\n"
      << "// THIS FILE WAS AUTOGENERATED!\n"
      << "// DO NOT MODIFY!\n";
}

// Class prefix
void writeClassPrefix(
   std::ostream &os,
   const std::string &nsname, const std::string &clname,
   const bool hasData, const std::string &dataType
) {
   // comment introducing class
   os << "\n\n\n"
      << large << "\n"
      << "// " << nsname << "::\n"
      << "// class " << clname << "\n"
      << large << "\n";

   // namespace+class begin
   os << "\n"
      << "namespace " << nsname << " {\n"
      << "\n"
      << "class " << clname << " : public Component<" << clname
      << (hasData ? (",true" + (dataType == "" ? "" : "," + dataType)) : "")
      << "> {\n";
}

// Class suffix
void writeClassSuffix(
   std::ostream &os,
   const std::string &nsname, const std::string &clname,
   const Info &info
) {
   // assignment
   os << "\n"
      << "   " << small << "\n"
      << "   // Assignment" << "\n"
      << "   " << small << "\n"
      << "\n"
      << "   // copy" << "\n"
      << "   " << clname << " &operator=(const " << clname << " &) = default;\n"
      << "\n"
      << "   // move" << "\n"
      << "   " << clname << " &operator=(" << clname << " &&) = default;\n";

   // customization #include
   os << "\n"
      << "   " << small << "\n"
      << "   // Custom functionality\n"
      << "   " << small << "\n"
      << "\n"
      << "   #include \"GNDStk/" << info.Version << "/"
      << nsname << "/" << clname << "/src/custom.hpp\"\n";

   // class+namespace end
   os << "\n"
      << "}; // class " << clname << "\n"
      << "\n"
      << "} // namespace " << nsname << "\n";
}



// -----------------------------------------------------------------------------
// Functions: writeCtor*
// -----------------------------------------------------------------------------

// writeCtorComponentCall
void writeCtorComponentCall(
   std::ostream &os, const bool hasOther,
   const PerClass &info
) {
   os << "      Component{\n"
      << "         "
      << (hasOther ? "other" : "BodyText{}");

   for (const auto &m : info.metadata) // metadata
      os << ",\n         content." + m.varName;
   for (const auto &c : info.children) // children
      os << ",\n         content." + c.varName;
   for (const auto &v : info.variants) // variant children
      os << ",\n         content." + v.varName;

   os << "\n      }";
}

// writeCtorBody
void writeCtorBody(
   std::ostream &os, const std::string &argName
) {
   os << "   {\n";
   os << "      Component::finish(" << argName << ");\n";
   os << "   }\n";
}



// -----------------------------------------------------------------------------
// writeGetters
// -----------------------------------------------------------------------------

// Helper: getter1Param
void getter1Param(
   std::ostream &os,
   const std::string &varType, const std::string &varName,
   const std::string &argType, const std::string &argName
) {
   // comment
   os << "\n   // " << varName << "(" << argName << ")\n";

   // getter: const
   os << "   const " << varType << " &" << varName
      << "(const " << argType << argName << ") const\n"
      << "    { return getter(" << varName
      << "(), " << argName << ", " << "\"" << varName << "\"); }\n";

   // getter: non-const
   os << "   " << varType << " &" << varName
      << "(const " << argType << argName << ")\n"
      << "    { return getter(" << varName
      << "(), " << argName << ", " << "\"" << varName << "\"); }\n";
}

// Helper: getter2Param
void getter2Param(
   std::ostream &os,
   const std::string &varType, const std::string &varName,
   const std::string &argType, const std::string &argName,
   const std::string &choiceName
) {
   // choice is a vector<variant>
   os << "\n   // " << varName << "(" << argName << ")\n";

   // const
   os << "   const " << varType << " *" << varName << "(const "
      << argType << argName
      << ") const\n" << "    { return getter<" << varType << ">"
      << "(" << choiceName << "(), " << argName
      << ", \"" << varName << "\"); }\n";

   // non-const
   os << "   " << varType << " *" << varName << "(const "
      << argType << argName
      << ")\n" << "    { return getter<" << varType << ">"
      << "(" << choiceName << "(), " << argName
      << ", \"" << varName << "\"); }\n";
}



// -----------------------------------------------------------------------------
// getClassMetadata
// -----------------------------------------------------------------------------

void getClassMetadata(
   const nlohmann::json &meta,
   const Info &info,
   PerClass &per
) {
   for (const auto &field : meta.items()) {
      const auto &metaKey = field.key();
      const auto &metaRHS = field.value();

      // Name
      InfoMetadata infom;
      infom.varName = fieldName(metaKey,metaRHS,info);

      // Has default?
      infom.theDefault = "";
      if (metaRHS.contains("default") && !metaRHS["default"].is_null()) {
         infom.theDefault = toString(metaRHS["default"]);
         const auto it = info.mapMetaDefault.find(infom.theDefault);
         if (it != info.mapMetaDefault.end())
            infom.theDefault = it->second;
      };
      if (infom.theDefault != "") {
         if (debugging)
            std::cout << "theDefault: \"" << infom.theDefault << "\"\n";
         // If this metadatum has a default, then surely it isn't required...
         assert(!metaRHS["required"]);
      }

      // Optional? (not required, and has no default)
      infom.isOptional = !metaRHS["required"] && infom.theDefault == "";
      const std::string optPrefix = infom.isOptional ? "std::optional<" : "";
      const std::string optSuffix = infom.isOptional ? ">" : "";

      // Defaulted? (not required, but does have a default)
      infom.isDefaulted = !metaRHS["required"] && infom.theDefault != "";
      const std::string defPrefix = infom.isDefaulted ? "Defaulted<" : "";
      const std::string defSuffix = infom.isDefaulted ? ">" : "";

      // Type
      infom.varType = getMetaType(metaRHS,info);

      // Full type, including any optional or defaulted
      infom.varTypeFull =
         optPrefix + defPrefix +
         infom.varType +
         defSuffix + optSuffix;

      // Add to per.metadata
      per.metadata.push_back(infom);
   }
} // getClassMetadata



// -----------------------------------------------------------------------------
// findNamespace
// -----------------------------------------------------------------------------

// Determine to what namespace "child" belongs. Context: we're (1) in a JSON
// spec with namespace parent.nsname, (2) in a parent node named parent.clname,
// and (3) wish to determine the proper namespace for the parent's child node
// named "child". childJSON is the JSON value for this child node.
std::string findNamespace(
   const nlohmann::json childJSON, const Info &info,
   const NamespaceAndClass &parent, const std::string &child
) {
   // ------------------------
   // child's namespace...
   // ------------------------

   // ...is explicitly given by "__namespace__"
   if (childJSON.contains("__namespace__"))
      return childJSON["__namespace__"];

   // ...is explicitly given by "namespace"
   if (childJSON.contains("namespace"))
      return childJSON["namespace"];

   // ...isn't given, and this child isn't in any of the JSONs :-(
   if (info.class2nspace.count(child) == 0) {
      log::warning(
         "{}::{} has child of unknown class {}",
         parent.nsname, parent.clname, child
      );
      return "unknownNamespace";
   }

   // ...isn't given, but we've seen the child in exactly *one* namespace
   if (info.class2nspace.count(child) == 1)
      return info.class2nspace.find(child)->second;

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...one of which is the parent's, which we'll presume is intended
   const auto range = info.class2nspace.equal_range(child);
   for (auto it = range.first; it != range.second; ++it)
      if (it->second == parent.nsname)
         return parent.nsname;

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...none of which is the parent's; this is an ambiguous situation :-(
   std::stringstream warn;
   int count = 0;
   for (auto it = range.first; it != range.second; ++it)
      warn << (count++ ? ", " : "") << it->second;
   log::warning(
      "{}::{} has child of ambiguous class {}.\n"
      "Child class {} appears in all of the following namespaces:\n{}",
      parent.nsname, parent.clname, child, child, warn.str()
   );

   return "ambiguousNamespace";
} // findNamespace



// -----------------------------------------------------------------------------
// getClassChildren
// -----------------------------------------------------------------------------

void getClassChildren(
   const nlohmann::json &elem,
   const Info &info,
   PerClass &per,
   const NamespaceAndClass &nandc,
   Class2Dependencies &dep
) {
   for (const auto &field : elem.items()) {
      const auto &elemKey = field.key();
      const auto &elemRHS = field.value();

      // Choice children are handled elsewhere
      const std::string occ = elemRHS["occurrence"];
      if (occ == "choice" || occ == "choice+" || occ == "choice2+")
         continue;

      // Name
      InfoChildren infoc;
      infoc.varName = fieldName(elemKey,elemRHS,info);

      // Optional?
      infoc.isOptional = !elemRHS["required"];
      const std::string optPrefix = infoc.isOptional ? "std::optional<" : "";
      const std::string optSuffix = infoc.isOptional ? ">" : "";

      // Vector?
      infoc.isVector = occ == "0+" || occ == "1+" || occ == "2+";
      const std::string vecPrefix = infoc.isVector ? "std::vector<" : "";
      const std::string vecSuffix = infoc.isVector ? ">" : "";

      // Type, including namespace
      infoc.varType = className(elemKey,elemRHS,info);
      const std::string ns = findNamespace(elemRHS,info,nandc,infoc.varType);
      infoc.varType = ns + "::" + infoc.varType;

      // Full type, including any optional or vector
      // If both, use optional<vector>; the reverse makes less sense
      infoc.varTypeFull =
         optPrefix + vecPrefix +
         infoc.varType +
         vecSuffix + optSuffix;

      // Partial type, not including any vector. This is used in the context
      // of this child node's entry in the multi-query key, where vector will
      // be implicit if it's a "many" (not a "one") child.
      infoc.varTypeHalf =
         optPrefix +
         infoc.varType +
         optSuffix;

      // Save as a dependency - if it's not its own dependency (in which case,
      // presumably, a pointer is involved, or we're out of luck in any event)
      if (infoc.varType != nandc.clname)///just one of these has namespace?????
         dep.dependencies.push_back(
            NamespaceAndClass(ns,className(elemKey,elemRHS,info)));

      // Add to per.children
      per.children.push_back(infoc);
   }
} // getClassChildren



// -----------------------------------------------------------------------------
// getClassChoice
// -----------------------------------------------------------------------------

// We want to fill in per.variants, which is a vector<InfoVariants> that has
// the "choice" children from the current parent class. First computing a
// map<string,InfoVariants> turns out to be convenient, given the manner in
// which the "choice" cases appear in the JSON specs - namely, listed
// in a "flat" manner as child nodes, rather than grouped one level deeper
// inside of, say, a "choice" JSON key. Remark: this code supports the option
// of having multiple variants under the current parent node; for example,
// the parent can have {X or Y}, *and* (independently) have {A or B or C}.
// Our "variant" JSON key facilitates this: it would be the same for X and Y,
// and the same for A, B, and C. The current (GNDS v1.9) specs only allow
// for one choice-between-things (just X,Y; or just A,B,C) in a given, but
// we believe our extension will prove to be useful.

void getClassChoices(
   const nlohmann::json &elem,
   const Info &info,
   PerClass &per,
   const NamespaceAndClass &nandc,
   Class2Dependencies &dep
) {
   std::map<std::string,InfoVariants> map;

   // Pass 1
   // Collect "variant" names, and if ever it's absent, a to-be-determined
   // name for all choice children for which it's absent
   for (const auto &field : elem.items()) {
      // Is it a choice child?
      const auto &elemRHS = field.value();
      const std::string occ = elemRHS["occurrence"];
      if (occ != "choice" && occ != "choice+" && occ != "choice2+")
         continue;

      // Variant name
      const std::string variant = elemRHS.contains("variant")
         ? elemRHS["variant"]
         : ""; // to be determined
      map.insert(std::make_pair(variant,InfoVariants{}));
   }

   // Pass 2
   for (const auto &field : elem.items()) {
      // Is it a choice child?
      const auto &elemRHS = field.value();
      const std::string occ = elemRHS["occurrence"];
      if (occ != "choice" && occ != "choice+" && occ != "choice2+")
         continue;
      const auto &elemKey = field.key();

      // Variant name
      const std::string variant = elemRHS.contains("variant")
         ? elemRHS["variant"]
         : "";
      auto it = map.find(variant);
      assert(it != map.end()); // should be there from the earlier loop

      // For the individual child that's part of a choice...
      InfoChoiceChild child;
      // ...its name
      child.varName = fieldName(elemKey,elemRHS,info);
      // ...its type, including namespace
      child.varType = className(elemKey,elemRHS,info);
      const std::string ns = findNamespace(elemRHS,info,nandc,child.varType);
      child.varType = ns + "::" + child.varType;
      // ...its vector-ness
      child.isVector = occ == "choice+" || occ == "choice2+";

      // The GNDS JSON specs appear to all have "required":false for individual
      // choices in a set of choices, so that the concept of "the entire choice
      // can be required or optional" doesn't currently exist. We could relax
      // this, but for now, we'll just ensure that it's followed.
      assert(!elemRHS["required"]);

      InfoVariants &infov = it->second;
      infov.isVector = child.isVector;
      infov.children.push_back(child);

      // save as a dependency
      if (child.varType != nandc.clname)///just one of these has namespace?????
         dep.dependencies.push_back(
            NamespaceAndClass(ns,className(elemKey,elemRHS,info)));
   }

   // Pass 3
   for (auto &pair : map) {
      InfoVariants &choice = pair.second;
      assert(choice.children.size() > 0);

      const std::string vecPrefix = choice.isVector ? "std::vector<" : "";
      const std::string vecSuffix = choice.isVector ? ">" : "";

      choice.varName = pair.first;

      for (const auto &child : choice.children) {
         assert(child.isVector == choice.isVector);
         choice.varType += (choice.varType == "" ? "std::variant<" : ",");
         choice.varType +=  child.varType;
         if (pair.first == "")
            choice.varName += (choice.varName == "" ? "_" : "") + child.varName;
      }
      choice.varType += ">";
      choice.varTypeHalf = choice.varType;
      choice.varTypeFull = vecPrefix + choice.varType + vecSuffix;

      per.variants.push_back(choice);
   }
} // getClassChoice



// -----------------------------------------------------------------------------
// writeClass*
// -----------------------------------------------------------------------------

// writeClassMetadata
void writeClassMetadata(std::ostream &os, PerClass &per)
{
   if (per.metadata.size())
      os << "      // metadata\n";

   for (const auto &m : per.metadata) {
      per.data.has && (
         m.varName == "length" ||
         m.varName == "start"  ||
         m.varName == "valueType")
       ? os << "      mutable " << m.varTypeFull << " " << m.varName
       : os << "      "         << m.varTypeFull << " " << m.varName;

      if (m.theDefault != "")
         os << "{" << m.theDefault << "}";
      os << ";\n";
   }
}

// writeClassChildren
void writeClassChildren(std::ostream &os, PerClass &per)
{
   if (per.children.size())
      os << "      // children\n";

   for (const auto &c : per.children) {
      os << "      " << c.varTypeFull << " " << c.varName;
      os << ";\n";
   }
}

// writeClassChoices
void writeClassChoices(std::ostream &os, PerClass &per)
{
   for (const auto &v : per.variants) {
      os << "      " << v.varTypeFull << " " << v.varName;
      os << ";\n";
   }
}



// -----------------------------------------------------------------------------
// getClass
// -----------------------------------------------------------------------------

template<class JSON>
void getClass(
   const JSON &keyvalue,
   const std::string &nsname, // in this file
   Info &info
) {
   const auto classKey = keyvalue.key();
   const auto classRHS = keyvalue.value();
   if (!isClass(classKey,classRHS))
      return;

   // class name
   const std::string clname = className(classKey,classRHS,info);
   if (debugging)
      std::cout << "Class: " << clname << std::endl;

   const NamespaceAndClass nandc(nsname,clname);
   PerClass per;
   per.data.has  = false;
   per.data.type = "";
   validateClass(classRHS, per.data.has, per.data.type);

   // For this class, we'll collect dependencies as this function proceeds
   Class2Dependencies dep;
   dep.object = nandc;

   // output: class begin /// as elsewhere, consider moving write
   std::ostringstream oss;
   writeClassPrefix(oss, nsname, clname, per.data.has, per.data.type);

   /// possibly split out into next two blocks...
   const nlohmann::json attrs = getMetadataJSON<true>(classRHS);
   validateMetadata(attrs);
   const nlohmann::json elems = getChildrenJSON<true>(classRHS);
   validateChildren(elems);

   /*
   qqq working here
   PerClass:
      ( ) std::string code;
      (x) std::vector<InfoMetadata> metadata;
      (x) std::vector<InfoChildren> children;
      (x) std::vector<InfoVariants> variants;
      (x) InfoData data;
   */

   // metadata
   std::ostringstream ossm;
   getClassMetadata(attrs, info, per);
   writeClassMetadata(ossm, per);

   // children - regular
   std::ostringstream ossc;
   getClassChildren(elems, info, per, nandc, dep);
   writeClassChildren(ossc, per);

   // children - choice
   std::ostringstream ossv;
   getClassChoices(elems, info, per, nandc, dep);
   writeClassChoices(ossv, per);

   // zzz working here

#if 0
   // for later use
   class2info.insert(
      std::make_pair(
         std::make_pair(nsname,clname),
         std::make_pair(per.metadata,per.children)
      )
   );
   class2bodytext.insert(
      std::make_pair(
         std::make_pair(nsname,clname),
         std::make_pair(per.data.has, per.data.type)
      )
   );

   // output: names, keys
   // As needed by the Component base
   write_keys(
      oss, classKey, classRHS, per.metadata, per.children,
      nsname
   );

   // output: base
   oss << "\n   using Component::construct;\n";
   if (per.data.has)
      oss << "   using BodyText::operator=;\n";

   // output: defaults (applicable only to metadata)
   oss << "\n   " << small;
   oss << "\n   // Relevant defaults";
   oss << "\n   // FYI for users";
   oss << "\n   " << small;
   oss << "\n";
   oss << "\n   static inline const struct Defaults {\n";
   for (auto &m : per.metadata) {
      if (m.isDefaulted) {
         oss << "      static inline const " << m.varType << " " << m.varName;
         oss << " = " << m.theDefault << ";\n";
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
   if (per.metadata.size() || per.children.size()) {
      writeGetters(oss, per.metadata, per.children);
      writeSetters(oss, per.metadata, per.children,
                   hasBodyText, per.data.has, clname);
   }

   // output: constructors
   oss << "\n   " << small
       << "\n   // Construction"
       << "\n   " << small
       << "\n";
   writeClassCtor(
      oss, clname, per.metadata, per.children,
      hasBodyText, per.data.has
   );

   // output: class end
   writeClassSuffix(oss, nsname, clname);

   // save what we've written to oss
   if (debugging)
      std::cout
         << "dep.name == "
         << dep.name.first  << "::" << dep.name.second << std::endl;
   const bool inserted =
      classCodeMap.insert(std::make_pair(dep.name,oss.str())).second;
   assert(inserted);
#endif



   info.ClassDependenciesRaw.push_back(dep);
   info.class2data.insert(std::make_pair(nandc,per));

} // getClass



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   // For GNDStk's diagnostics
   color = true;

   ///zzz write a better comment...
   // Gather information
   Info info;
   if (!commandLine(argc, argv, info))
      exit(EXIT_FAILURE);

   ///zzz then new material goes here...
}
