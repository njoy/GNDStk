
// -----------------------------------------------------------------------------
// Tool for autogenerating GNDStk classes from JSON specs
// -----------------------------------------------------------------------------

#include "GNDStk.hpp"
#include "cstring"
using namespace njoy::GNDStk::core;

// Print extra chatter?
const bool debugging = true;

// Report cases of nodes that have no metadata, and zero or one child node(s).
// Where these exist, a simplification of your schema is worth considering.
const bool singletons = true;

// Comment-related markup
const auto large = "// " + std::string(77,'-');
const auto small = "// " + std::string(24,'-');

// Replace character
std::string replace(std::string str, const char from, const char to)
{
   for (std::size_t i = str.size(); i--; )
      if (str[i] == from)
         str[i] = to;
   return str;
}

std::string toPythonName(const std::string &name)
{
   std::string python;
   python += std::tolower(name[0]);
   for (auto it = name.begin()+1; it != name.end(); ++it) {
      if (std::isupper(*it) && std::islower(*(it-1)))
         python += '_';
      python += std::tolower(*it);
   }
   return python;
}



// -----------------------------------------------------------------------------
// For a topological sort: classes
// These relate to the ordering of class definitions based on their dependencies
// -----------------------------------------------------------------------------

// Namespace and class
struct NamespaceAndClass {
   std::string nsname; // name of a namespace
   std::string clname; // name of a class in the namespace

   NamespaceAndClass(const std::string &ns = "", const std::string &cl = "") :
      nsname(ns),
      clname(cl)
   { }

   bool operator==(const NamespaceAndClass &other) const
   {
      return
         nsname == other.nsname &&
         clname == other.clname;
   }

   bool operator<(const NamespaceAndClass &other) const
   {
      return
         nsname < other.nsname ? true
       : other.nsname < nsname ? false
       : clname < other.clname;
   }
};

// Class2Dependencies
// For a {namespace,class}, its {namespace,class} dependencies
struct Class2Dependencies {
   NamespaceAndClass object;///not a good name
   std::vector<NamespaceAndClass> dependencies;
};



// -----------------------------------------------------------------------------
// Per-class information
// That is, information we'll collect for each child node in the input .json(s)
// -----------------------------------------------------------------------------

// InfoMetadata
struct InfoMetadata {
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
struct InfoChildren {
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

// InfoVariantsChildren
struct InfoVariantsChildren {
   std::string varName;
   std::string varType;
   bool        isVector;
};

// InfoVariants
struct InfoVariants {
   std::string varName;
   std::string varType;     // underlying type
   std::string varTypeFull; // with any optional<> or vector<>
   std::string varTypeHalf; // withOUT any vector<>
   bool        isVector;
   std::vector<InfoVariantsChildren> children;
};

// PerNamespace
struct PerNamespace {
   // File name for...
   std::string filePythonCPP; // .cpp code for this namespace's Python interface
};

// PerClass
struct PerClass {
   // File names for...
   std::string filePythonCPP; // .cpp code for this class' Python interface
   std::string fileGNDStkHPP; // .hpp code for GNDStk

   // Actual printed code for the class. We build this up and then print
   // it later, after having determined a dependency-aware class ordering.
   std::string code;

   // Information about the contents of the class...
   // ...its metadata
   // ...its standard children
   // ...its "choice" children
   std::vector<InfoMetadata> metadata;
   std::vector<InfoChildren> children;
   std::vector<InfoVariants> variants;

   // Data node?
   bool hasData;
   std::string dataType;
};



// -----------------------------------------------------------------------------
// Overarching data structure reflecting all of the autogenerator's input
// as well as various processed information
// -----------------------------------------------------------------------------

struct Info {
   // From the .json file on the command line
   std::string JSONDir;
   std::vector<std::string> JSONFiles;
   std::string GNDSDir;
   std::string Version;

   // Same as Version except with '_' in place of '.'
   std::string VersionUnderscore;

   // Directory-prefixed name of the .hpp file for this GNDS version
   std::string VersionHPP;

   // Changes to apply to a metadatum's or child node's name.
   // Example: "double" (GNDS v1.9 does have this) to "Double" for C++.
   std::map<std::string,std::string> mapName;

   // Changes to apply to metadata/attribute type and default.
   // Examples: "Boolean" to "bool", "interpolation" to "enums::Interpolation".
   std::map<std::string,std::string> mapMetaType;
   std::map<std::string,std::string> mapMetaDefault;

   // For each class (node) in the input JSON specifications, the namespace(s)
   // in which it appears.
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

   // Map from namespace to information about the namespace
   std::map<std::string,PerNamespace> namespace2data;

   // Map from namespace::class to information about the class
   std::map<NamespaceAndClass,PerClass> class2data;
};



// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// isClass: is this a class that's meaningful to autogenerate?
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

// Read JSON file
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

      if (metadata.size() == 0 && children.size() == 0)
         log::info("Class \"{}\" has no metadata and no children", parent);
      if (metadata.size() == 0 && children.size() == 1)
         log::info("Class \"{}\" has no metadata and just one child", parent);
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

void changesFile(const std::string &jfile, Info &info)
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

   // Extract information from the command line .json
   info.JSONDir   = jmain[input];
   info.JSONFiles = std::vector<std::string>(jmain[files]);
   info.GNDSDir   = jmain[output];
   info.Version   = jmain[version];
   info.VersionUnderscore = replace(info.Version, '.', '_');

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
      changesFile(jmain[changes],info);
   return true;
}



// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// Capitalize the first letter, leaving others as-is
std::string capital(std::string str)
{
   if (str.size() > 0)
      str[0] = toupper(str[0]);
   return str;
}

// Capitalize all letters
std::string allcaps(std::string str)
{
   for (std::size_t i = str.size(); i--; )
      str[i] = toupper(str[i]);
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
   return capital(fieldName(key,value,info));
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
   const NamespaceAndClass &nandc, const PerClass &per
) {
   // comment introducing class
   os << "\n\n\n"
      << large << "\n"
      << "// " << nandc.nsname << "::\n"
      << "// class " << nandc.clname << "\n"
      << large << "\n";

   // namespace+class begin
   os << "\n"
      << "namespace " << nandc.nsname << " {\n"
      << "\n"
      << "class " << nandc.clname << " : public Component<" << nandc.clname
      << (per.hasData ? (",true" + (per.dataType == "" ? "" : "," + per.dataType)) : "")
      << "> {\n";
}

// Class suffix
void writeClassSuffix(
   std::ostream &os,
   const NamespaceAndClass &nandc, const Info &info
) {
   // assignment
   os << "\n"
      << "   " << small << "\n"
      << "   // Assignment" << "\n"
      << "   " << small << "\n"
      << "\n"
      << "   // copy" << "\n"
      << "   " << nandc.clname << " &operator=(const " << nandc.clname << " &) = default;\n"
      << "\n"
      << "   // move" << "\n"
      << "   " << nandc.clname << " &operator=(" << nandc.clname << " &&) = default;\n";

   // customization #include
   os << "\n"
      << "   " << small << "\n"
      << "   // Custom functionality\n"
      << "   " << small << "\n"
      << "\n"
      << "   #include \"GNDStk/" << info.Version << "/"
      << nandc.nsname << "/" << nandc.clname << "/src/custom.hpp\"\n";

   // class+namespace end
   os << "\n"
      << "}; // class " << nandc.clname << "\n"
      << "\n"
      << "} // namespace " << nandc.nsname << "\n";
}



// -----------------------------------------------------------------------------
// Functions: writeCtor*
// -----------------------------------------------------------------------------

// writeCtorComponentCall
void writeCtorComponentCall(
   std::ostream &os, const PerClass &info, const bool hasOther
) {
   os << "      Component{\n"
      << "         "
      << (hasOther ? "other" : "BodyText{}");

   for (const auto &m : info.metadata) // metadata
      os << ",\n         content." + m.varName;
   for (const auto &c : info.children) // children
      os << ",\n         content." + c.varName;
   for (const auto &v : info.variants) // variants
      os << ",\n         content." + v.varName;

   os << "\n      }";
}

// writeCtorBody
void writeCtorBody(std::ostream &os, const std::string &argName)
{
   os << "   {\n";
   os << "      Component::finish(" << argName << ");\n";
   os << "   }\n";
}



// -----------------------------------------------------------------------------
// Helper functions
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
   const std::string &variantName
) {
   // comment
   os << "\n   // " << varName << "(" << argName << ")\n";

   // const
   os << "   const " << varType << " *" << varName << "(const "
      << argType << argName
      << ") const\n" << "    { return getter<" << varType << ">"
      << "(" << variantName << "(), " << argName
      << ", \"" << varName << "\"); }\n";

   // non-const
   os << "   " << varType << " *" << varName << "(const "
      << argType << argName
      << ")\n" << "    { return getter<" << varType << ">"
      << "(" << variantName << "(), " << argName
      << ", \"" << varName << "\"); }\n";
}



// -----------------------------------------------------------------------------
// getClassMetadata
// -----------------------------------------------------------------------------

void getClassMetadata(
   const nlohmann::json &meta, const Info &info, PerClass &per
) {
   for (const auto &field : meta.items()) {
      const auto &metaKey = field.key();
      const auto &metaRHS = field.value();

      // Name
      InfoMetadata m;
      m.varName = fieldName(metaKey,metaRHS,info);

      // Has default?
      m.theDefault = "";
      if (metaRHS.contains("default") && !metaRHS["default"].is_null()) {
         m.theDefault = toString(metaRHS["default"]);
         const auto it = info.mapMetaDefault.find(m.theDefault);
         if (it != info.mapMetaDefault.end())
            m.theDefault = it->second;
      };
      if (m.theDefault != "") {
         if (debugging)
            std::cout << "theDefault: \"" << m.theDefault << "\"\n";
         // If this metadatum has a default, then surely it isn't required...
         assert(!metaRHS["required"]);
      }

      // Optional? (not required, and has no default)
      m.isOptional = !metaRHS["required"] && m.theDefault == "";
      const std::string optPrefix = m.isOptional ? "std::optional<" : "";
      const std::string optSuffix = m.isOptional ? ">" : "";

      // Defaulted? (not required, but does have a default)
      m.isDefaulted = !metaRHS["required"] && m.theDefault != "";
      const std::string defPrefix = m.isDefaulted ? "Defaulted<" : "";
      const std::string defSuffix = m.isDefaulted ? ">" : "";

      // Type
      m.varType = getMetaType(metaRHS,info);

      // Full type, including any optional or defaulted
      m.varTypeFull =
         optPrefix + defPrefix +
         m.varType +
         defSuffix + optSuffix;

      // Add to per.metadata
      per.metadata.push_back(m);
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
   const nlohmann::json &elem, const Info &info, PerClass &per,
   const NamespaceAndClass &nandc, Class2Dependencies &dep
) {
   for (const auto &field : elem.items()) {
      const auto &elemKey = field.key();
      const auto &elemRHS = field.value();

      // Choice children are handled elsewhere
      const std::string occ = elemRHS["occurrence"];
      if (occ == "choice" || occ == "choice+" || occ == "choice2+")
         continue;

      // Name
      InfoChildren c;
      c.varName = fieldName(elemKey,elemRHS,info);

      // Optional?
      c.isOptional = !elemRHS["required"];
      const std::string optPrefix = c.isOptional ? "std::optional<" : "";
      const std::string optSuffix = c.isOptional ? ">" : "";

      // Vector?
      c.isVector = occ == "0+" || occ == "1+" || occ == "2+";
      const std::string vecPrefix = c.isVector ? "std::vector<" : "";
      const std::string vecSuffix = c.isVector ? ">" : "";

      // Type, including namespace
      c.varType = className(elemKey,elemRHS,info);
      const std::string ns = findNamespace(elemRHS,info,nandc,c.varType);
      c.varType = ns + "::" + c.varType;

      // Full type, including any optional or vector
      // If both, use optional<vector>; the reverse makes less sense
      c.varTypeFull =
         optPrefix + vecPrefix +
         c.varType +
         vecSuffix + optSuffix;

      // Partial type, not including any vector. This is used in the context
      // of this child node's entry in the multi-query key, where vector will
      // be implicit if it's a "many" (not a "one") child.
      c.varTypeHalf =
         optPrefix +
         c.varType +
         optSuffix;

      // Save as a dependency - if it's not its own dependency (in which case,
      // presumably, a pointer is involved, or we're out of luck in any event)
      if (c.varType != nandc.clname)///just one of these has namespace?????
         dep.dependencies.push_back(
            NamespaceAndClass(ns,className(elemKey,elemRHS,info)));

      // Add to per.children
      per.children.push_back(c);
   }
} // getClassChildren



// -----------------------------------------------------------------------------
// getClassVariants
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

void getClassVariants(
   const nlohmann::json &elem, const Info &info, PerClass &per,
   const NamespaceAndClass &nandc, Class2Dependencies &dep
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
      const std::string variantName = elemRHS.contains("variant")
         ? elemRHS["variant"]
         : ""; // to be determined
      map.insert(std::make_pair(variantName,InfoVariants{}));
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
      InfoVariantsChildren c;
      // ...its name
      c.varName = fieldName(elemKey,elemRHS,info);
      // ...its type, including namespace
      c.varType = className(elemKey,elemRHS,info);
      const std::string ns = findNamespace(elemRHS,info,nandc,c.varType);
      c.varType = ns + "::" + c.varType;
      // ...its vector-ness
      c.isVector = occ == "choice+" || occ == "choice2+";

      // The GNDS JSON specs appear to all have "required":false for individual
      // choices in a set of choices, so that the concept of "the entire choice
      // can be required or optional" doesn't currently exist. We could support
      // it, but for now, we'll just ensure that "required":false is followed.
      assert(!elemRHS["required"]);

      InfoVariants &v = it->second;
      v.isVector = c.isVector;
      v.children.push_back(c);

      // save as a dependency
      if (c.varType != nandc.clname)///just one of these has namespace?????
         dep.dependencies.push_back(
            NamespaceAndClass(ns,className(elemKey,elemRHS,info)));
   }

   // Pass 3
   for (auto &pair : map) {
      InfoVariants &v = pair.second;
      assert(v.children.size() > 0);

      const std::string vecPrefix = v.isVector ? "std::vector<" : "";
      const std::string vecSuffix = v.isVector ? ">" : "";

      v.varName = pair.first;
      v.varType = allcaps(pair.first); /// consider _t

      for (const auto &c : v.children) {
         assert(c.isVector == v.isVector);
         if (pair.first == "")
            v.varName += (v.varName == "" ? "_" : "") + c.varName;
      }
      v.varTypeHalf = v.varType;
      v.varTypeFull = vecPrefix + v.varType + vecSuffix;

      per.variants.push_back(v);
   }
} // getClassVariants



// -----------------------------------------------------------------------------
// writeClass*
// -----------------------------------------------------------------------------

// writeClassMetadata
void writeClassMetadata(std::ostream &os, const PerClass &per)
{
   if (per.metadata.size())
      os << "      // metadata\n";

   for (const auto &m : per.metadata) {
      per.hasData && (
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
void writeClassChildren(std::ostream &os, const PerClass &per)
{
   if (per.children.size() || per.variants.size()) {
      if (per.metadata.size())
         os << "\n";
      os << "      // children\n";
   }

   for (const auto &c : per.children)
      os << "      " << c.varTypeFull << " " << c.varName << ";\n";
}

// writeClassVariants
void writeClassVariants(std::ostream &os, const PerClass &per)
{
   for (const auto &v : per.variants)
      os << "      " << v.varTypeFull << " " << v.varName << ";\n";
}



// -----------------------------------------------------------------------------
// writeForComponent
// -----------------------------------------------------------------------------

void writeForComponent(
   std::ostream &os,
   const std::string &classKey, const nlohmann::json &classRHS,
   const PerClass &per, const std::string &nsname, const Info &info
) {
   os << "\n";

   // using [name for variant] = ...
   for (const auto &v : per.variants) {
      os << "   using " << v.varType << " = std::variant<\n";
      int total = v.children.size();
      int count = 0;
      for (const auto &c : v.children)
         os << "      " << c.varType << (++count == total ? "" : ",") << "\n";
      os << "   >;\n";
   }

   // names
   ///These are the only things that need classKey, classRHS, and info. Perhaps
   ///there's a better way - say, with name and gnds stored in the perclass??
   const std::string name = className(classKey,classRHS,info);
   const std::string gnds = GNDSName(classKey,classRHS);

   os << "\n";
   os << "   " << small << "\n";
   os << "   // For Component\n";
   os << "   " << small << "\n";
   os << "\n";
   os << "   friend class Component;\n";
   os << "\n";
   os << "   // Current namespace, current class, and GNDS node name\n";
   os << "   static auto namespaceName() { return \"" << nsname << "\"; }\n";
   os << "   static auto className() { return \"" << name << "\"; }\n";
   os << "   static auto GNDSName() { return \"" << gnds << "\"; }\n";
   os << "\n";

   // keys() begin
   os << "   // Core Interface object to extract metadata and child nodes\n";
   os << "   static auto keys()\n";
   os << "   {\n";

   // keys() contents
   auto total = per.metadata.size() + per.children.size() + per.variants.size();
   if (total == 0) {
      os << "      return std::tuple<>{};\n";
   } else {
      os << "      return\n";
      std::size_t count = 0;

      // metadata
      if (per.metadata.size())
         os << "         // metadata\n";
      for (const auto &m : per.metadata) {
         os << "         " << m.varTypeFull << "{" << m.theDefault << "}\n";
         os << "            / ";
         os << "Meta<>(\"" << m.varName << "\")";
         os << (++count < total ? " |\n" : "\n");
      }

      // children
      if (per.children.size() || per.variants.size())
         os << "         // children\n";
      for (const auto &c : per.children) {
         os << "         " << c.varTypeHalf << "{}\n"; // w/o any std::vector
         os << "            / " << (c.isVector ? "++" : "--");
         os << "Child<>(\"" << c.varName << "\")";
         os << (++count < total ? " |\n" : "\n");
      }

      // variants
      for (const auto &v : per.variants) {
         os << "         " << v.varTypeHalf << "{}\n"; // w/o any std::vector
         os << "            / " << (v.isVector ? "++" : "--");
         os << "(";
         std::size_t n = 0;
         for (const auto &c : v.children)
            os << (n++ ? " || " : "") << "Child<>(\"" << c.varName << "\")";
         os << ")";
         os << (++count < total ? " |\n" : "\n");
      }

      os << "      ;\n";
   }

   // keys() end
   os << "   }\n";
   os << "\n";
   os << "public:\n";
} // writeForComponent



// -----------------------------------------------------------------------------
// writeGetters
// -----------------------------------------------------------------------------

void writeGetters(std::ostream &os, const PerClass &per)
{
   os << "\n   " << small;
   os << "\n   // Getters";
   os << "\n   // const and non-const";
   os << "\n   " << small << "\n";

   // metadata
   for (const auto &m : per.metadata) {
      // comment
      os << "\n   // " << m.varName << "\n";

      // getter: const
      os << "   const ";
      os << m.varTypeFull << " &" << m.varName << "() const\n";
      os << "    { return content." << m.varName << "; }\n";

      // getter: non-const
      os << "   ";
      os << m.varTypeFull << " &" << m.varName << "()\n";
      os << "    { return content." << m.varName << "; }\n";
   }

   // children
   for (const auto &c : per.children) {
      // comment
      os << "\n   // " << c.varName << "\n";

      // getter: const
      os << "   const ";
      os << c.varTypeFull << " &" << c.varName << "() const\n";
      os << "    { return content." << c.varName << "; }\n";

      // getter: non-const
      os << "   ";
      os << c.varTypeFull << " &" << c.varName << "()\n";
      os << "    { return content." << c.varName << "; }\n";

      // with index or label
      if (c.isVector) {
         getter1Param(os, c.varType, c.varName, "std::size_t ",  "index");
         getter1Param(os, c.varType, c.varName, "std::string &", "label");
      }
   }

   // variants
   for (const auto &v : per.variants) {
      // comment
      os << "\n   // " << v.varName << "\n";

      // getter: const
      os << "   const " << v.varTypeFull << " &" << v.varName << "() const\n";
      os << "    { return content." << v.varName << "; }\n";

      // getter: non-const
      os << "   " << v.varTypeFull << " &" << v.varName << "()\n";
      os << "    { return content." << v.varName << "; }\n";

      // with index or label
      if (v.isVector) {
         getter1Param(os, v.varType, v.varName, "std::size_t ",  "index");
         getter1Param(os, v.varType, v.varName, "std::string &", "label");
      }

      // alternatives
      for (const auto &c : v.children) {
         if (v.isVector) {
            getter2Param(os, c.varType, c.varName,
                         "std::size_t ",  "index", v.varName);
            getter2Param(os, c.varType, c.varName,
                         "std::string &", "label", v.varName);
         } else {
            // comment
            os << "\n   // " << c.varName << "\n";

            // getter: const
            os << "   const " << c.varType << " *" << c.varName << "() const\n";
            os << "    { return getter<" << c.varType << ">";
            os << "(" << v.varName << "(), " << "\"" << c.varName << "\"); }\n";

            // getter: non-const
            os << "   " << c.varType << " *" << c.varName << "()\n";
            os << "    { return getter<" << c.varType << ">";
            os << "(" << v.varName << "(), " << "\"" << c.varName << "\"); }\n";
         }
      }
   }
}



// -----------------------------------------------------------------------------
// writeSetterChild
// -----------------------------------------------------------------------------

template<class INFO>
void writeSetterChild(
   std::ostream &os,
   const INFO &c, // InfoChildren or InfoVariants
   const std::string &clname
) {
   // setter, for T as-is
   os << "\n   // " << c.varName << "(value)\n";
   os << "   " << clname << " &" << c.varName;
   os << "(const " << c.varTypeFull << " &obj)\n";
   os << "    { " << c.varName << "() = obj; return *this; }\n";

   // setter, for T, if type is optional<T>
   // shouldn't need; T will convert to optional<T>

   // setter, for vector<T>, if type is optional<vector<T>>
   // equivalent to the above

   // index and label cases
   if (c.isVector) {
      os << "\n";
      os << "   // " << c.varName << "(index,value)\n";
      os << "   " << clname << " &" << c.varName << "(\n";
      os << "      const std::size_t index,\n";
      os << "      const " << c.varType << " &obj\n";
      os << "   ) {\n";
      os << "      " << c.varName << "(index) = obj; return *this;\n";
      os << "   }\n";
      os << "\n";
      os << "   // " << c.varName << "(label,value)\n";
      os << "   " << clname << " &" << c.varName << "(\n";
      os << "      const std::string &label,\n";
      os << "      const " << c.varType << " &obj\n";
      os << "   ) {\n";
      os << "      " << c.varName << "(label) = obj; return *this;\n";
      os << "   }\n";
   }
}



// -----------------------------------------------------------------------------
// writeSetters
// -----------------------------------------------------------------------------

void writeSetters(
   std::ostream &os, const PerClass &per,
   const bool hasData, const std::string &clname
) {
   os << "\n   " << small;
   os << "\n   // Setters";
   os << "\n   // non-const";
   os << "\n   // All return *this";
   os << "\n   " << small << "\n";

   // Reminder:
   //    metadata can have: optional, defaulted (but not vector)
   //    children can have: optional, vector (but not defaulted)

   // metadata
   for (const auto &m : per.metadata) {
      // comment
      os << "\n   // " << m.varName << "(value)\n";

      // special cases: we want to send length, start, and valueType
      // to the BodyText base as well
      const bool special = hasData && (
         m.varName == "length" ||
         m.varName == "start" ||
         m.varName == "valueType"
      );

      // setter, for T as-is
      {
         os << "   " << clname << " &" << m.varName;
         os << "(const " << m.varTypeFull << " &obj)\n";
         if (special && m.isDefaulted)
            os << "    { BodyText::" << m.varName << "(content."
               << m.varName << " = obj); return *this; }\n";
         if (special && !m.isDefaulted)
            os << "    { BodyText::" << m.varName << "("
               << m.varName << "() = obj); return *this; }\n";
         if (!special && m.isDefaulted)
            os << "    { content." << m.varName
               << " = obj; return *this; }\n";
         if (!special && !m.isDefaulted)
            os << "    { " << m.varName
               << "() = obj; return *this; }\n";
      }

      // setter, for T, if type is optional<T>
      // shouldn't need; T will convert to optional<T>

      // setter, for T, if type is Defaulted<T>
      if (m.isDefaulted) {
         os << "   " << clname << " &" << m.varName;
         os << "(const std::optional<" << m.varType << "> &obj)\n";
         special
            ? os << "    { BodyText::" << m.varName << "(content."
                 << m.varName << " = obj); return *this; }\n"
            : os << "    { content." << m.varName
                 << " = obj; return *this; }\n";
      }
   }

   // children
   for (const auto &c : per.children)
      writeSetterChild(os,c,clname);

   // variants
   for (const auto &v : per.variants) {
      writeSetterChild(os,v,clname);

      // setters, using individual names
      if (v.isVector) {
         // choice is a vector<variant>
         for (const auto &c : v.children) {
            // index
            os << "\n   // " << c.varName << "(index,value)\n";
            os << "   " << clname << " &" << c.varName << "(\n";
            os << "      const std::size_t index,\n";
            os << "      const std::optional<" << c.varType << "> &obj\n";
            os << "   ) {\n";
            os << "      if (obj) " << v.varName << "(index,obj.value());\n";
            os << "      return *this;\n";
            os << "   }\n";
            // label
            os << "\n   // " << c.varName << "(label,value)\n";
            os << "   " << clname << " &" << c.varName << "(\n";
            os << "      const std::string &label,\n";
            os << "      const std::optional<" << c.varType << "> &obj\n";
            os << "   ) {\n";
            os << "      if (obj) " << v.varName << "(label,obj.value());\n";
            os << "      return *this;\n";
            os << "   }\n";
         }
      } else {
         // choice is a variant
         for (const auto &c : v.children) {
            os << "\n   // " << c.varName << "(value)\n";
            os << "   " << clname << " &" << c.varName << "(const std::optional<";
            os << c.varType << "> &obj)\n";
            os << "    { if (obj) " << v.varName;
            os << "(obj.value()); return *this; }\n";
         }
      }
   }
}



// -----------------------------------------------------------------------------
// writeClassCtor
// -----------------------------------------------------------------------------

void writeClassCtor(
   std::ostream &os, const std::string &clname,
   const PerClass &per, const bool hasData
) {
   os << "\n";

   // ------------------------
   // ctor: default
   // ------------------------

   // signature, and base constructor call
   os << "   // default\n";
   os << "   " << clname << "() :\n";
   writeCtorComponentCall(os,per,false);

   // body
   os << "\n";
   writeCtorBody(os,"");
   os << "\n";

   // ------------------------
   // ctor: copy
   // ------------------------

   // signature, and base constructor call
   os << "   // copy\n";
   os << "   " << clname << "(const " << clname << " &other) :\n";
   writeCtorComponentCall(os,per,true);

   // copy fields
   os << ",\n      content{other.content}";

   // body
   os << "\n";
   writeCtorBody(os,"other");
   os << "\n";

   // ------------------------
   // ctor: move
   // ------------------------

   // signature, and base constructor call
   os << "   // move\n";
   os << "   " << clname << "(" << clname << " &&other) :\n";
   writeCtorComponentCall(os, per, true);

   // copy fields
   os << ",\n      content{std::move(other.content)}";

   // body
   os << "\n";
   writeCtorBody(os,"other");
   os << "\n";

   // ------------------------
   // ctor: node
   // ------------------------

   // signature, and base constructor call
   os << "   // from node\n";
   os << "   " << clname << "(const Node &node) :\n";
   writeCtorComponentCall(os, per, false);

   // body
   os << "\n";
   writeCtorBody(os,"node");

   // ------------------------
   // ctor: fields
   // ------------------------

   if (per.metadata.size() + per.children.size() + per.variants.size() == 0)
      return;

   os << "\n   // from fields\n";
   for (const auto &m : per.metadata) {
      if (m.isDefaulted) {
         os << "   // std::optional replaces Defaulted; ";
         os << "this class knows the default(s)\n";
         break;
      }
   }

   // signature, and base constructor call
   // Note: we don't really need "explicit" unless this constructor can be
   // called with one argument. We'll always write it, however, in case
   // someone modifies the auto-generated constructor (say, giving its
   // arguments defaults) in such a way that is *can* be called with one
   // argument. (But we'd rather nobody modify the auto-generated classes.)
   std::size_t count;
   count = 0;
   os << "   explicit " << clname << "(";
   for (const auto &m : per.metadata) {
      os << (count++ ? ",\n" : "\n") << "      const ";
      m.isDefaulted
         ? os << "std::optional<" << m.varType << ">"
         : os << m.varTypeFull;
      os << " &" << m.varName;
   }
   for (const auto &c : per.children) {
      os << (count++ ? ",\n" : "\n")
         << "      const " << c.varTypeFull << " &" << c.varName;
   }
   for (const auto &v : per.variants) {
      os << (count++ ? ",\n" : "\n")
         << "      const " << v.varTypeFull << " &" << v.varName;
   }

   os << "\n   ) :\n";
   writeCtorComponentCall(os, per, false);

   // initialize fields
   os << ",\n";
   os << "      content{";
   count = 0;
   for (const auto &m : per.metadata) {
      os << (count++ ? ",\n" : "\n") << "         ";
      m.isDefaulted
         ? os << "Defaulted<" << m.varType << ">(defaults."
              << m.varName << "," << m.varName << ")"
         : os << m.varName;
   }
   for (const auto &c : per.children)
      os << (count++ ? ",\n" : "\n") << "         " << c.varName;
   for (const auto &v : per.variants)
      os << (count++ ? ",\n" : "\n") << "         " << v.varName;
   os << "\n      }\n";

   // body
   writeCtorBody(os,"");

   // ------------------------
   // ctor: vector
   // ------------------------

   if (hasData) {
      // signature, and base constructor call
      os << "\n";
      os << "   // from vector\n";
      os << "   template<class T, class = "
         << "std::enable_if_t<body::template supported<T>>>\n";
      os << "   " << clname << "(const std::vector<T> &vector) :\n";
      writeCtorComponentCall(os, per, false);

      // body
      os << "\n";
      writeCtorBody(os,"vector");
   }
}



// -----------------------------------------------------------------------------
// writeClass
// -----------------------------------------------------------------------------

void writeClass(
   std::ostringstream &oss,
   const std::string &classKey, const nlohmann::json &classRHS,
   const PerClass &per, const NamespaceAndClass &nandc, const Info &info
) {
   // write
   std::ostringstream ossm;
   std::ostringstream ossc;
   std::ostringstream ossv;
   writeClassMetadata(ossm, per);
   writeClassChildren(ossc, per);
   writeClassVariants(ossv, per);

   // output: class begin
   writeClassPrefix(oss, nandc, per);

   // As needed by the Component base
   writeForComponent(oss, classKey, classRHS, per, nandc.nsname, info);

   // output: base
   oss << "\n   using Component::construct;\n";
   if (per.hasData)
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
   oss << "\n   struct {\n";
   oss << ossm.str();
   oss << ossc.str();
   oss << ossv.str();
   oss << "   } content;\n";

   // output: getters, setters
   if (per.metadata.size() || per.children.size() || per.variants.size()) {
      writeGetters(oss, per);
      writeSetters(oss, per, per.hasData, nandc.clname);
   }

   // output: constructors
   oss << "\n";
   oss << "   " << small << "\n";
   oss << "   // Construction\n";
   oss << "   " << small << "\n";

   writeClassCtor(oss, nandc.clname, per, per.hasData);

   // output: class end
   writeClassSuffix(oss, nandc, info);
}



// -----------------------------------------------------------------------------
// getClass
// -----------------------------------------------------------------------------

void getClass(
   const std::string &classKey, const nlohmann::json &classRHS,
   const std::string &nsname, Info &info
) {
   if (!isClass(classKey,classRHS))
      return;

   // class name
   const std::string clname = className(classKey,classRHS,info);
   if (debugging)
      std::cout << "Class: " << clname << std::endl;

   // find in class map
   const NamespaceAndClass nandc(nsname,clname);
   const auto it = info.class2data.find(nandc);
   assert(it != info.class2data.end());
   PerClass &per = it->second;

   ///Behavior here is more than validate; also compare with metadata/children
   // validate below; this material needs to be reworked/clarified
   per.hasData  = false;
   per.dataType = "";
   validateClass(classRHS, per.hasData, per.dataType);

   // Collect dependencies, for the present class, as this function proceeds
   Class2Dependencies dep;
   dep.object = nandc;

   // metadata
   const nlohmann::json attrs = getMetadataJSON<true>(classRHS);
   validateMetadata(attrs);
   getClassMetadata(attrs, info, per);

   // children
   const nlohmann::json elems = getChildrenJSON<true>(classRHS);
   validateChildren(elems);
   getClassChildren(elems, info, per, nandc, dep);

   // variants
   getClassVariants(elems, info, per, nandc, dep);

   if (debugging) {
      std::cout
         << "dep.name == "
         <<  dep.object.nsname << "::" << dep.object.clname << std::endl;
   }

   // Compute per.code
   std::ostringstream oss;
   writeClass(oss,classKey,classRHS,per,nandc,info);
   per.code = oss.str();

   info.ClassDependenciesRaw.push_back(dep);
} // getClass



// -----------------------------------------------------------------------------
// preprocessClass
// -----------------------------------------------------------------------------

void preprocessClass(
   const std::string &nsname,
   const std::string &classKey, const nlohmann::json &classRHS,
   Info &info
) {
   // Ensure that this JSON entry represents a class - as opposed
   // to being, say, "namespace" or some other non-class entry.
   if (!isClass(classKey,classRHS))
      return;

   // Get the class name, then link this class with the current namespace.
   // This information is used, later, for various purposes.
   const std::string clname = className(classKey,classRHS,info);
   info.class2nspace.insert(std::make_pair(clname,nsname));

   // ------------------------
   // Create directories and
   // custom files as needed
   // ------------------------

   // Given the base GNDS directory and the GNDS version, as obtained earlier
   // from the JSON input file to this tool, compute relevant directory names.
   const std::string
      // For the present namespace: C++ and Python directories. The present
      // namespace probably contains multiple classes, so its directories
      // may have been created already, but that's fine.
      nsdir   = info.GNDSDir + "/src/GNDStk/" + info.Version + "/" + nsname,
      nsdirpy = info.GNDSDir + "/python/src/" + info.Version + "/" + nsname,
      // For the present class: C++ source and test directories.
      clsrc   = nsdir + "/" + clname + "/src",
      cltest  = nsdir + "/" + clname + "/test";

   // Create the above directories, if (and only if) they don't already exist.
   system(("mkdir -p " + nsdir  ).data());
   system(("mkdir -p " + nsdirpy).data());
   system(("mkdir -p " + clsrc  ).data());
   system(("mkdir -p " + cltest ).data());

   // To allow for customization of the present class in the present namespace,
   // create a custom.hpp file in the C++ source directory for the class. But
   // do so only if the customization file isn't already there, or else we might
   // be trashing someone's customization!
   const std::string custom = clsrc + "/custom.hpp";
   if (!std::ifstream(custom)) {
      std::cout << "No customization file " << custom << std::endl;
      std::cout << "...So, creating a basic one" << std::endl;
      std::ofstream ofs(custom);
      ofs << "\n";
      ofs << "private:\n";
      ofs << "\n";
      ofs << "   static inline helpMap help = {};\n";
   }

   // ------------------------
   // Create file-name maps
   // ------------------------

   // For this namespace:
   //    The .cpp file for Python
   auto ns = info.namespace2data.insert(
      std::make_pair(nsname, PerNamespace{}));
   ns.first->second.filePythonCPP = nsdirpy + ".python.cpp";

   // For this namespace::class:
   //    The .cpp file for Python
   //    The .hpp file for GNDStk
   auto cl = info.class2data.insert(
      std::make_pair(NamespaceAndClass{nsname,clname}, PerClass{}));
   assert(cl.second); // should have been inserted - not there already
   cl.first->second.filePythonCPP = nsdirpy + "/" + clname + ".python.cpp";
   cl.first->second.fileGNDStkHPP = nsdir   + "/" + clname + ".hpp";
}



// -----------------------------------------------------------------------------
// preprocess
// -----------------------------------------------------------------------------

void preprocess(Info &info)
{
   std::cout << "Preprocessing JSON files..." << std::endl;

   // For each JSON spec
   for (const std::string &file : info.JSONFiles) {
      const nlohmann::json jmain = readJSON(file,true);
      const std::string nsname = getNamespace(jmain);
      // For each entry (typically a class) in the JSON spec
      for (const auto &cl : jmain.items())
         preprocessClass(nsname, cl.key(), cl.value(), info);
   }

   // Create an overarching
   // file for this version
   std::ofstream ofs(info.VersionHPP);
   writeAutogenerated(ofs);
   ofs << "\n#ifndef NJOY_GNDSTK_" << allcaps(info.VersionUnderscore);
   ofs << "\n#define NJOY_GNDSTK_" << allcaps(info.VersionUnderscore) << "\n";

   std::string nsname_last = "";
   for (auto &c : info.class2data) {
      const std::string nsname = c.first.nsname;
      const std::string clname = c.first.clname;
      if (nsname != nsname_last)
         ofs << "\n";
      nsname_last = nsname;
      ofs << "#include \"GNDStk/" << info.Version << "/";
      ofs << nsname << "/" << clname << ".hpp\"\n";
   }

   ofs << "\n#include \"GNDStk/" << info.Version << "/key.hpp\"\n";
   ofs << "\n#endif\n";

   // Debugging information
   if (debugging) {
      std::cout << "For each class, namespace(s) it appears in:" << std::endl;
      for (const auto &it : info.class2nspace)
         std::cout << "   " << it.first << ": " << it.second << std::endl;
   }
}



// -----------------------------------------------------------------------------
// filePythonNamespace
// -----------------------------------------------------------------------------

void filePythonNamespace(
   const std::string &nsname,
   const PerNamespace &per,
   const Info &info
) {
   std::ofstream cpp(per.filePythonCPP);
   writeAutogenerated(cpp);

   cpp << "\n";
   cpp << "#include <pybind11/pybind11.h>\n";
   cpp << "#include <pybind11/stl.h>\n";
   cpp << "\n";
   cpp << "namespace python = pybind11;\n";
   cpp << "\n";

   cpp << "// " << info.Version << " interface\n";
   cpp << "namespace python_" << info.VersionUnderscore << " {\n\n";

   cpp << "// " << nsname << " declarations\n";
   cpp << "namespace python_" << nsname << " {\n";
   for (auto &cl : info.ClassDependenciesSorted)
      if (cl.object.nsname == nsname)
         cpp << "   void wrap" << cl.object.clname << "(python::module &);\n";
   cpp << "} // namespace python_" << nsname << "\n";
   cpp << "\n";

   cpp << "// " << nsname << " wrapper\n";
   cpp << "void wrap" << capital(nsname) << "(python::module &module)\n";
   cpp << "{\n";
   cpp << "   // create the " << nsname << " submodule\n";
   cpp << "   python::module submodule = module.def_submodule(\n";
   cpp << "      \"" << nsname << "\",\n";
   cpp << "      \"GNDS " << info.Version << " " << nsname << "\"\n";
   cpp << "   );\n";

   cpp << "\n   // wrap " << nsname << " components\n";
   for (auto &cl : info.ClassDependenciesSorted)
      if (cl.object.nsname == nsname)
         cpp << "   python_" << nsname << "::wrap" << cl.object.clname
             << "(submodule);\n";
   cpp << "};\n";
   cpp << "\n} // namespace python_" << info.VersionUnderscore << "\n";
}



// -----------------------------------------------------------------------------
// filePythonClass
// -----------------------------------------------------------------------------

void filePythonClass(
   const NamespaceAndClass &nandc,
   const PerClass &per,
   const Info &info
) {
   const std::string &nsname = nandc.nsname;
   const std::string &clname = nandc.clname;

   std::ofstream cpp(per.filePythonCPP);
   writeAutogenerated(cpp);

   cpp << "\n";

   cpp << "// system includes\n";
   cpp << "#include <pybind11/pybind11.h>\n";
   cpp << "#include <pybind11/stl.h>\n";
   cpp << "\n";

   cpp << "// local includes\n";
   cpp << "#include \"GNDStk/" << info.Version << "/"
       << nsname << "/" << clname << ".hpp\"\n";
   cpp << "#include \"definitions.hpp\"\n";
   cpp << "\n";

   cpp << "// namespace aliases\n";
   cpp << "namespace python = pybind11;\n";
   cpp << "\n";

   cpp << "namespace python_" << info.VersionUnderscore << " {\n";
   cpp << "namespace python_" << nsname << " {\n";
   cpp << "\n";

   cpp << "// " << clname << " wrapper\n";
   cpp << "void wrap" << clname << "(python::module &module)\n";
   cpp << "{\n";
   cpp << "   using namespace njoy::GNDStk;\n";
   cpp << "   using namespace njoy::GNDStk::" << info.VersionUnderscore << ";\n";
   cpp << "\n";
   cpp << "   // type aliases\n";
   cpp << "   using Component = " << nsname << "::" << clname << ";\n";

   // using [variant name] = std::variant..., if necessary
   for (const auto &v : per.variants) {
      cpp << "   using " << v.varType << " = std::variant<\n";
      int total = v.children.size();
      int count = 0;
      for (const auto &c : v.children)
         cpp << "      " << c.varType << (++count == total ? "" : ",") << "\n";
      cpp << "   >;\n";
   }

   cpp << "\n";
   cpp << "   // create the component\n";
   cpp << "   python::class_<Component> component(\n";
   cpp << "      module,\n";
   cpp << "      \"" << clname << "\",\n";
   cpp << "      Component::documentation().data()\n";
   cpp << "   );\n";
   cpp << "\n";
   cpp << "   // wrap the component\n";
   cpp << "   component\n";
   cpp << "      .def(\n";

   // compute some things with respect to "body text"
   std::string bodyType = "unknownType";
   std::string bodyName = "unknownName";
   if (per.dataType == "Integer32") {
      bodyType = "Integer32";
      bodyName = "ints";
   } else if (per.dataType == "Float64") {
      bodyType = "Float64";
      bodyName = "doubles";
   } else if (per.dataType == "UTF8Text") {
      bodyType = "UTF8Text";
      bodyName = "strings";
   } else {
      for (auto &m : per.metadata) {
         if (m.varName == "valueType") {
            if (m.theDefault == "\"Integer32\"") {
               bodyType = "Integer32";
               bodyName = "ints";
            } else if (m.theDefault == "\"Float64\"") {
               bodyType = "Float64";
               bodyName = "doubles";
            } else if (m.theDefault == "\"UTF8Text\"") {
               bodyType = "UTF8Text";
               bodyName = "strings";
            }
         }
      }
   }

   // python::init<...>
   cpp << "         python::init<";
   int count = 0;
   for (auto &m : per.metadata) {
      cpp << (count++ ? "," : "") << "\n            ";
      m.isDefaulted
       ? cpp << "const std::optional<" << m.varType << "> &"
       : cpp << "const " << m.varTypeFull << " &";
   }
   for (auto &c : per.children) {
      cpp << (count++ ? "," : "") << "\n            "
          << "const " << c.varTypeFull << " &";
   }
   for (auto &v : per.variants) {
      cpp << (count++ ? "," : "") << "\n            "
          << "const " << v.varTypeFull << " &";
   }
   if (per.hasData) {
      cpp << (count++ ? "," : "") << "\n            ";
      cpp << "const std::vector<" << bodyType << "> &";
   }
   cpp << "\n         >(),\n";

   // python::arg...
   for (auto &m : per.metadata) {
      cpp << "         python::arg(\"" << toPythonName(m.varName) << "\")";
      if (m.isDefaulted) {
         cpp << " = " << m.theDefault;
      } else if (m.isOptional) {
         cpp << " = std::nullopt";
      }
      cpp << ",\n";
   }
   for (auto &c : per.children) {
      cpp << "         python::arg(\"" << toPythonName(c.varName) << "\")";
      if (c.isOptional)
         cpp << " = std::nullopt";
      cpp << ",\n";
   }
   for (auto &v : per.variants) {
      cpp << "         python::arg(\"" << toPythonName(v.varName) << "\")";
      cpp << ",\n";
   }
   if (per.hasData)
      cpp << "         python::arg(\"values\"),\n";
   cpp << "         Component::documentation(\"constructor\").data()\n";
   cpp << "      )\n";

   // .def_property_readonly...
   for (auto &m : per.metadata) {
      const auto pythonname = toPythonName(m.varName);
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << pythonname << "\",\n";
      m.isDefaulted
       ? cpp << "         [](const Component &self) { return self."
             << m.varName << "().value(); },\n"
       : cpp << "         &Component::" << m.varName << ",\n";
      cpp << "         Component::documentation(\""
          << pythonname << "\").data()\n";
      cpp << "      )\n";
   }
   for (auto &c : per.children) {
      const auto pythonname = toPythonName(c.varName);
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << pythonname << "\",\n";
      cpp << "         python::overload_cast<>(&Component::"
          << c.varName << "),\n";
      cpp << "         Component::documentation(\""
          << pythonname << "\").data()\n";
      cpp << "      )\n";
   }
   for (auto &v : per.variants) {
      if (!v.isVector) {
         for (auto &c : v.children) {
            const auto pythonname = toPythonName(c.varName);
            cpp << "      .def_property_readonly(\n";
            cpp << "         \"" << pythonname << "\",\n";
            cpp << "         python::overload_cast<>(&Component::"
                << c.varName << "),\n";
            cpp << "         Component::documentation(\""
                << pythonname << "\").data()\n";
            cpp << "      )\n";
         }
      }
      const auto pythonname = toPythonName(v.varName);
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << pythonname << "\",\n";
      cpp << "         python::overload_cast<>(&Component::"
          << v.varName << "),\n";
      cpp << "         Component::documentation(\""
          << pythonname << "\").data()\n";
      cpp << "      )\n";
   }

   if (per.hasData) {
      cpp << "      .def_property_readonly(\n";
      cpp << "         \"" << bodyName << "\",\n";
      cpp << "         [] (const Component &self) "
          << "{ return self." << bodyName << "(); },\n";
      cpp << "         Component::documentation(\""
          << bodyName << "\").data()\n";
      cpp << "      )\n";
   }

   // finish up
   cpp << "   ;\n\n";
   cpp << "   // add standard component definitions\n";
   cpp << "   addStandardComponentDefinitions< Component >( component );\n";
   cpp << "}\n";
   cpp << "\n";
   cpp << "} // namespace python_" << nsname << "\n";
   cpp << "} // namespace python_" << info.VersionUnderscore << "\n";
}



// -----------------------------------------------------------------------------
// fileGNDStkClass
// -----------------------------------------------------------------------------

void fileGNDStkClass(
   const std::string &nsname,
   const std::string &clname,
   const PerClass &per,
   const Info &info,
   const Class2Dependencies &c2d
) {
   // class-specific hpp file
   std::ofstream hpp(per.fileGNDStkHPP);
   writeAutogenerated(hpp);
   const std::string guard =
     "NJOY_GNDSTK_" + allcaps(info.VersionUnderscore) + "_" +
      allcaps(nsname) + "_" + allcaps(clname);

   hpp << "\n";
   hpp << "#ifndef " << guard << "\n";
   hpp << "#define " << guard << "\n";
   hpp << "\n";
   hpp << "// core interface\n";
   hpp << "#include \"GNDStk.hpp\"\n";
   hpp << "\n";

   if (c2d.dependencies.size() > 0) {
      hpp << "// " << info.Version << " dependencies\n";
      for (const auto &dep : c2d.dependencies) {
         hpp << "#include \"GNDStk/" << info.Version << "/"
             << dep.nsname << "/" << dep.clname << ".hpp\"\n";
      }
      hpp << "\n";
   }

   hpp << "namespace njoy {\n";
   hpp << "namespace GNDStk {\n";
   hpp << "namespace " << info.VersionUnderscore << " {\n";
   hpp << "\n";
   hpp << "using namespace njoy::GNDStk::core;\n";
   hpp << per.code;
   hpp << "} // namespace " << info.VersionUnderscore << "\n";
   hpp << "} // namespace GNDStk\n";
   hpp << "} // namespace njoy\n\n";
   hpp << "#endif\n";
}



// -----------------------------------------------------------------------------
// fileKey
// -----------------------------------------------------------------------------

const std::string file_key_comment =
R"***(
This file contains Meta and Child objects for metadata and child nodes in the
current GNDS version. These may prove to be useful if you wish to use the Core
Interface in conjunction with the autogenerated classes for this GNDS version.

Within the outer njoy::GNDStk::version namespace below, the remaining namespace
arrangement was chosen to make the use of these objects smooth and logical.

Meta and Child objects are collectively called "keys." Meta keys are placed
into key::meta. Child keys correspond to autogenerated classes, each of which
is already in some namespace; we thus use theNamespace::key::child::. That way,
an autogenerated class [ns::Foo] has [ns::key::foo] as its Child object, and
a "using namespace ns" allows the class and the Child object to be [Foo] and
[key::foo], respectively. (If we reordered ns:: and key::, that wouldn't work.)

Within key::, we use meta:: and child:: around Meta and Child objects, just in
case there exist any identical GNDS metadata names and child-node names. (That
can, in fact, happen). The "using namespace meta" and "using namespace child"
directives then make the Meta<> and Child<> objects appear directly in key::,
so that "meta::" and "child::" are needed only to disambiguate identical names.
)***";

void fileKey(const Info &info)
{
   // ------------------------
   // Gather information
   // ------------------------

   // pair: key name, GNDS name
   using pair = std::pair<std::string, std::string>;

   // For metadata, collect into one place
   std::set<pair> metadata;

   // For children, process on a per-file basis; *multi*map is
   // in case the same namespace appears in more than one file.
   // multimap: namespace name, set<pair>
   std::multimap<std::string, std::set<pair>> children;

   for (const auto &file : info.JSONFiles) {
      const nlohmann::json jmain = readJSON(file);
      const std::string nsname = getNamespace(jmain);
      auto it = children.insert(std::make_pair(nsname,std::set<pair>{}));

      for (const auto &node : jmain.items()) {
         if (!isClass(node.key(), node.value()))
            continue;

         // nodes ==> children
         it->second.insert(std::make_pair(
            fieldName(node.key(), node.value(), info),
            GNDSName (node.key(), node.value())
         ));

         // attributes ==> metadata
         const auto attrs = getMetadataJSON<true>(node.value());
         for (const auto &attr : attrs.items())
            metadata.insert(std::make_pair(
               fieldName(attr.key(), attr.value(), info),
               GNDSName (attr.key(), attr.value())
            ));
      }
   }

   // ------------------------
   // comment, macro guard,
   // outer namespaces
   // ------------------------

   const std::string file = info.GNDSDir + "/src/GNDStk/" + info.Version + "/key.hpp";
   std::ofstream ofs(file);
   writeAutogenerated(ofs);
   ofs << "\n/*" << file_key_comment << "*/\n\n";

   const std::string ver = info.VersionUnderscore;
   const std::string Ver = allcaps(ver);

   ofs << "#ifndef NJOY_GNDSTK_" << Ver << "_KEY\n";
   ofs << "#define NJOY_GNDSTK_" << Ver << "_KEY\n\n";
   ofs << "namespace njoy {\n";
   ofs << "namespace GNDStk {\n";
   ofs << "namespace " << ver << " {\n\n";

   // ------------------------
   // Meta<> objects
   // ------------------------

   ofs << "\n" << large << "\n";
   ofs << "// key::meta::";
   ofs << "\n" << large << "\n\n";
   ofs << "namespace key {\n";
   ofs << "namespace meta {\n\n";

   if (metadata.size() > 0) {
      ofs << "inline const Meta<>";
      int count = 0;
      for (const auto &meta : metadata) {
         ofs << (count++ ? "," : "") << "\n   "
             << meta.first << "(\"" << meta.second << "\")";
      }
      ofs << ";\n\n";
   }

   ofs << "} // namespace meta\n";
   ofs << "using namespace meta;\n";
   ofs << "} // namespace key\n";

   // ------------------------
   // Child<> objects
   // ------------------------

   for (const auto &nspace : children) {
      ofs << "\n";
      ofs << "\n" << large << "\n";
      ofs << "// " << nspace.first << "::key::child::";
      ofs << "\n" << large << "\n\n";
      ofs << "namespace " << nspace.first << " {\n";
      ofs << "namespace key {\n";
      ofs << "namespace child {\n\n";

      const auto &set = nspace.second;
      if (set.size() > 0) {
         ofs << "inline const Child<>";
         int count = 0;
         for (const auto &child : set) {
            ofs << (count++ ? "," : "") << "\n   "
                << child.first << "(\"" << child.second << "\")";
         }
         ofs << ";\n\n";
      }

      ofs << "} // namespace child\n";
      ofs << "using namespace child;\n";
      ofs << "} // namespace key\n";
      ofs << "} // namespace " << nspace.first << "\n";
   }

   // ------------------------
   // finish
   // ------------------------

   ofs << "\n";
   ofs << "\n" << large;
   ofs << "\n" << large << "\n\n";
   ofs << "} // namespace " << ver << "\n";
   ofs << "} // namespace GNDStk\n";
   ofs << "} // namespace njoy\n\n";
   ofs << "#endif\n";
} // fileKey



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   // For GNDStk's diagnostics
   color = true;

   // ------------------------
   // Basic information
   // ------------------------

   // Gather information from the JSON file given on the command line. This
   // consists of getting relevant directories, a GNDS version number, a list
   // of JSON files in which class specifications are given, and, optionally,
   // reading a "Changes" file that provides some search/replace information.
   Info info;
   if (!commandLine(argc, argv, info))
      exit(EXIT_FAILURE);

   // ------------------------
   // Preprocess
   // ------------------------

   // The following reads through the JSON spec files - these were determined
   // in the above step - and collects preliminary information that is used,
   // later, when the spec files are processed in more detail. (The detailed
   // processing requires knowledge obtained from the preliminary processing,
   // which is why those things are done separately.) Preliminary processing
   // includes creating a class-to-namespace map, making directories in which
   // output files will be placed, creating class-specific customization files
   // when appropriate, and creating maps from namespace to namespace-specific
   // information, and from namespace::class to class-specific information.
   // Relevant file names are computed as part of the "information" for the
   // maps just mentioned; other parts of the information are computer later,
   // during detailed processing. Finally, the below call writes the entire
   // GNDS "version" file, e.g. a file called v2.0.cpp if the GNDS version
   // is 2.0, because it has enough information that's it's able to do this.
   preprocess(info);

   if (debugging) {
      for (auto &n : info.namespace2data) {
         std::cout
            << "Namespace Python .cpp: [" << n.second.filePythonCPP << "]\n";
      }
      for (auto &c : info.class2data) {
         std::cout
            << "Class Python .cpp: [" << c.second.filePythonCPP << "]\n"
            << "Class GNDStk .hpp: [" << c.second.fileGNDStkHPP << "]\n";
      }
   }

   // ------------------------
   // Process classes
   // ------------------------

   // Print class code into temporary strings. These are printed to the class-
   // specific files later, after class dependencies (which must appear above
   // the class code in its file) are computed.
   std::cout << "\nBuilding classes..." << std::endl;

   for (const std::string &file : info.JSONFiles) {
      const nlohmann::json jmain = readJSON(file,true);
      const std::string nsname = getNamespace(jmain);
      // For each entry (typically a class) in the JSON spec
      for (const auto &cl : jmain.items())
         getClass(cl.key(), cl.value(), nsname, info);
   }

   // ------------------------
   // Re: class ordering
   // ------------------------

   // Compute an ordering that respects dependencies
   while (info.ClassDependenciesRaw.size() > 0)
      insertDependency(
         info.ClassDependenciesRaw.begin()->object,
         info.ClassDependenciesRaw,
         info.ClassDependenciesSorted);

   // Print dependencies
   printDependencies("Class dependencies", info.ClassDependenciesSorted);

   // ------------------------
   // Files
   // ------------------------

   // GNDStk: cpp file for namespace::class
   for (const auto &obj : info.ClassDependenciesSorted) {
      auto find = info.class2data.find(obj.object);
      assert(find != info.class2data.end());
      fileGNDStkClass(
         find->first.nsname,
         find->first.clname,
         find->second,
         info, obj);
   }

   // Python: cpp file for namespace
   for (auto &obj : info.namespace2data)
      filePythonNamespace(obj.first, obj.second, info);

   // Python: cpp file for namespace::class
   for (auto &obj : info.class2data)
      filePythonClass(obj.first, obj.second, info);

   // GNDStk: cpp file for Meta and Child keys
   fileKey(info);
}
