
// -----------------------------------------------------------------------------
// Tool for autogenerating GNDStk classes from JSON specifications
// -----------------------------------------------------------------------------

#include "GNDStk.hpp"
#include "cstring"
using namespace njoy::GNDStk::core;

// Report cases of nodes that have no metadata, and zero or one child node(s).
// Where these exist, a simplification of the spec may be worth considering.
const bool singletons = true;



// -----------------------------------------------------------------------------
// Data structures
// -----------------------------------------------------------------------------

/// use...
// KeyValue
using KeyValue = nlohmann::detail::iteration_proxy_value<
   nlohmann::detail::iter_impl<
      const nlohmann::basic_json<>
   >
>;

// NamespaceAndClass
struct NamespaceAndClass {
   std::string nsname; // name of a namespace
   std::string clname; // name of a class in the namespace

   NamespaceAndClass(const std::string &ns = "", const std::string &cl = "") :
      nsname(ns), clname(cl)
   { }

   bool operator==(const NamespaceAndClass &other) const
   {
      return nsname == other.nsname && clname == other.clname;
   }

   bool operator<(const NamespaceAndClass &other) const
   {
      return
         nsname < other.nsname ? true
       : other.nsname < nsname ? false
       : clname < other.clname;
   }

   std::string name() const { return nsname + "::" + clname; }
};

// Class2Dependencies
// For a {namespace,class}, its {namespace,class} dependencies
struct Class2Dependencies {
   NamespaceAndClass theClass;
   std::vector<NamespaceAndClass> dependencies;
};

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
   std::string name;
   std::string type;     // underlying type
   std::string typeFull; // with any optional<> or defaulted<>
   bool        isOptional;
   bool        isDefaulted;
   std::string defaultValue;
};

// InfoChildren
struct InfoChildren {
   // A .json spec can make a child node be:
   //    - a std::optional, and/or
   //    - a std::vector
   // but can't make it be a GNDStk::defaulted. (The use of a default value for
   // child nodes just doesn't exist in the GNDS specifications, even though the
   // concept would seem to make sense.)
   std::string name;
   std::string type;     // underlying type
   std::string typeFull; // with any optional<> or vector<>
   std::string typeHalf; // withOUT any vector<>
   bool        isOptional;
   bool        isVector;
};

// InfoVariantsChildren
struct InfoVariantsChildren {
   std::string name;
   std::string type;
   bool        isVector;
};

// InfoVariants
struct InfoVariants {
   std::string name;
   std::string type;     // underlying type
   std::string typeFull; // with any optional<> or vector<>
   std::string typeHalf; // withOUT any vector<>
   bool        isVector;
   std::vector<InfoVariantsChildren> children;
};

// PerNamespace
struct PerNamespace {
   // File name for...
   std::string cppPython; // ...cpp code for this namespace's Python interface
};

// PerClass
struct PerClass {
   // File names for...
   std::string cppPython; // ...cpp code for this class' Python interface
   std::string hppGNDStk; // ...hpp code for this class in GNDStk

   // Names for...
   std::string nameGNDS; // ...this class as a GNDS node

   // Actual printed code for the class. We build this up and then print
   // it later, after having determined a dependency-aware class ordering.
   std::string code;

   // Information about the contents of the class...
   // ...its metadata
   // ...its regular children
   // ...its variant children
   std::vector<InfoMetadata> metadata;
   std::vector<InfoChildren> children;
   std::vector<InfoVariants> variants;

   // Data node?
   bool isData;
   std::string dataType;
};



// -----------------------------------------------------------------------------
// InfoSpecs
// -----------------------------------------------------------------------------

// Overarching data structure reflecting all of the autogenerator's input
// as well as various processed information
struct InfoSpecs {
   // From the .json file on the command line
   std::string JSONDir;
   std::vector<std::string> JSONFiles;
   std::string GNDSDir;
   std::string Version;

   // Version, but with '_' in place of '.'
   std::string VersionUnderscore;

   // Directory-prefixed names for the hpp file for this version, and for
   // its Meta/Child key file
   std::string hppVersion;
   std::string hppKey;

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

   // Class dependencies: as originally determined, and after being sorted.
   // Elements of these vectors contain:
   //    theClass = {nsname,clname}
   //    dependencies = vector<{nsname,clname}>
   // These are (1) the class in question, and (2) its dependencies.
   std::vector<Class2Dependencies> ClassDependenciesRaw;
   std::vector<Class2Dependencies> ClassDependenciesSorted;

   // Map from namespace to information about the namespace
   std::map<std::string,PerNamespace> namespace2data;

   // Map from namespace::class to information about the class
   std::map<NamespaceAndClass,PerClass> class2data;
};



// -----------------------------------------------------------------------------
// Miscellaneous short functions
// -----------------------------------------------------------------------------

// Print text describing an action the code is about to take
void action(const std::string &str)
{
   std::cout
      << "\n"
      << colors::plain::blue << str << "..." << colors::reset << std::endl;
}

// Capitalize the first letter
std::string capital(const std::string &str)
{
   std::string ret = str;
   if (ret.size() > 0)
      ret[0] = toupper(ret[0]);
   return ret;
}

// Capitalize all letters
std::string allcaps(const std::string &str)
{
   std::string ret = str;
   for (auto i = ret.size(); i--; )
      ret[i] = toupper(ret[i]);
   return ret;
}

// Replace character
std::string replace(const std::string &str, const char from, const char to)
{
   std::string ret = str;
   for (auto i = ret.size(); i--; )
      if (ret[i] == from)
         ret[i] = to;
   return ret;
}

// Stringify JSON
// See: https://github.com/nlohmann/json/issues/642
std::string stringify(const nlohmann::json &j)
{
   const auto tmp = j.dump();
   return j.type() == nlohmann::json::value_t::string
      ? tmp.substr(1, tmp.size()-2)
      : tmp;
}

// Does this JSON key look like a C++ style comment?
bool isComment(const std::string &key)
{
   return strncmp(key.data(), "//", 2) == 0;
}

// Does this JSON key/value pair appear to describe a class?
bool isClass(const std::string &key, const nlohmann::json &value)
{
   // a comment?
   if (isComment(key))
      return false;

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
// name* functions
// -----------------------------------------------------------------------------

// nameGNDS
// Name in GNDS (e.g., name of an XML element)
std::string nameGNDS(
   const std::string &key, const nlohmann::json &value
) {
   // As-is, directly as stipulated in a key in the JSON spec, except
   // that we allow a "name" entry to override the key.
   return value.contains("name") ? std::string(value["name"]) : key;
}

// nameField
// Name of a field (metadatum or child node) in an autogenerated class
std::string nameField(
   const std::string &key, const nlohmann::json &value, const InfoSpecs &specs
) {
   // Like nameGNDS, except that we apply any name-modification map that
   // may have been provided. That can fix, for example, the name "double",
   // which appears in GNDS v1.9 but is unsuitable for a name in C++.
   const std::string name = nameGNDS(key,value);
   const auto it = specs.mapName.find(name);
   return it == specs.mapName.end() ? name : it->second;
}

// nameClass
// Name of an autogenerated class
std::string nameClass(
   const std::string &key, const nlohmann::json &value, const InfoSpecs &specs
) {
   // Like nameField, but capitalized (per our class naming convention).
   return capital(nameField(key,value,specs));
}

// namePython
// Name for Python
std::string namePython(const std::string &name)
{
   if (name.size() == 0)
      return name;
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
// Functions for getting certain information from JSON input
// -----------------------------------------------------------------------------

// Get the JSON's "namespace"
std::string getFileNamespace(const nlohmann::json &j)
{
   return j.contains("__namespace__")
      ? j["__namespace__"]
      : j[  "namespace"  ];
}

// Get the JSON's "type", with any relevant specs.mapMetaType entry applied
std::string getMetadatumType(const nlohmann::json &j, const InfoSpecs &specs)
{
   const std::string type = j["type"];
   const auto it = specs.mapMetaType.find(type);
   return it == specs.mapMetaType.end() ? type : it->second;
}

// Determine to what namespace "child" belongs. Context: we're (1) in a JSON
// spec with namespace parent.nsname, (2) in a parent node named parent.clname,
// and (3) wish to determine the proper namespace for the parent's child node
// named "child". Parameter j is the JSON value ({...}) for this child node.
std::string getChildNamespace(
   const nlohmann::json &j, const InfoSpecs &specs,
   const NamespaceAndClass &parent, const std::string &child
) {
   // ------------------------
   // child's namespace...
   // ------------------------

   // ...is explicitly given by "__namespace__"
   if (j.contains("__namespace__"))
      return j["__namespace__"];

   // ...is explicitly given by "namespace"
   if (j.contains("namespace"))
      return j["namespace"];

   // ...isn't given, and this child isn't in any of the JSONs :-(
   if (specs.class2nspace.count(child) == 0) {
      log::warning(
         "{}::{} has child of unknown class {}",
         parent.nsname, parent.clname, child
      );
      return "unknownNamespace";
   }

   // ...isn't given, but we've seen the child in exactly *one* namespace
   if (specs.class2nspace.count(child) == 1)
      return specs.class2nspace.find(child)->second;

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...one of which is the parent's, which we'll presume is intended
   const auto range = specs.class2nspace.equal_range(child);
   for (auto it = range.first; it != range.second; ++it)
      if (it->second == parent.nsname) {
         // fixme: a *warning* might be good to have here,
         // because we're assuming something
         return parent.nsname;
      }

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...none of which is the parent's; this is an ambiguous situation :-(
   std::stringstream warn;
   int count = 0;
   for (auto it = range.first; it != range.second; ++it)
      warn << (count++ == 0 ? "" : ", ") << it->second;
   log::warning(
      "{}::{} has child of ambiguous class {}.\n"
      "Child class {} appears in all of the following namespaces:\n{}",
      parent.nsname, parent.clname, child, child, warn.str()
   );

   return "ambiguousNamespace";
}



// -----------------------------------------------------------------------------
// getClass* functions re: metadata, children, variant children
// -----------------------------------------------------------------------------

// getClassMetadata
void getClassMetadata(
   const nlohmann::json &j, const InfoSpecs &specs, PerClass &per
) {
   for (const auto &field : j.items()) {
      const auto &metaKey = field.key();
      const auto &metaRHS = field.value();

      // Name
      InfoMetadata m;
      m.name = nameField(metaKey,metaRHS,specs);

      // Has default?
      m.defaultValue = "";
      if (metaRHS.contains("default") && !metaRHS["default"].is_null()) {
         m.defaultValue = stringify(metaRHS["default"]);
         const auto it = specs.mapMetaDefault.find(m.defaultValue);
         if (it != specs.mapMetaDefault.end())
            m.defaultValue = it->second;
      };
      if (m.defaultValue != "") {
         // If this metadatum has a default, then surely it isn't required...
         assert(!metaRHS["required"]);
      }

      // Optional? (not required, and has no default)
      m.isOptional = !metaRHS["required"] && m.defaultValue == "";
      const std::string optPrefix = m.isOptional ? "std::optional<" : "";
      const std::string optSuffix = m.isOptional ? ">" : "";

      // Defaulted? (not required, but does have a default)
      m.isDefaulted = !metaRHS["required"] && m.defaultValue != "";
      const std::string defPrefix = m.isDefaulted ? "Defaulted<" : "";
      const std::string defSuffix = m.isDefaulted ? ">" : "";

      // Type
      m.type = getMetadatumType(metaRHS,specs);

      // Full type, including any optional or defaulted
      m.typeFull =
         optPrefix + defPrefix +
         m.type +
         defSuffix + optSuffix;

      // Add to per.metadata
      per.metadata.push_back(m);
   }
} // getClassMetadata


// getClassChildren
void getClassChildren(
   const nlohmann::json &j, const InfoSpecs &specs, PerClass &per,
   const NamespaceAndClass &parent, Class2Dependencies &dep
) {
   for (const auto &field : j.items()) {
      const auto &elemKey = field.key();
      const auto &elemRHS = field.value();

      // Choice children are handled elsewhere
      const std::string occ = elemRHS["occurrence"];
      if (occ == "choice" || occ == "choice+" || occ == "choice2+")
         continue;

      // Name
      InfoChildren c;
      c.name = nameField(elemKey,elemRHS,specs);

      // Optional?
      c.isOptional = !elemRHS["required"];
      const std::string optPrefix = c.isOptional ? "std::optional<" : "";
      const std::string optSuffix = c.isOptional ? ">" : "";

      // Vector?
      c.isVector = occ == "0+" || occ == "1+" || occ == "2+";
      const std::string vecPrefix = c.isVector ? "std::vector<" : "";
      const std::string vecSuffix = c.isVector ? ">" : "";

      // Type, including namespace
      c.type = nameClass(elemKey,elemRHS,specs);
      const std::string ns = getChildNamespace(elemRHS,specs,parent,c.type);
      c.type = ns + "::" + c.type;

      // Full type, including any optional or vector
      // If both, use optional<vector>; the reverse makes less sense
      c.typeFull =
         optPrefix + vecPrefix +
         c.type +
         vecSuffix + optSuffix;

      // Partial type, not including any vector. This is used in the context
      // of this child node's entry in the multi-query key, where vector will
      // be implicit if it's a "many" (not a "one") child.
      c.typeHalf =
         optPrefix +
         c.type +
         optSuffix;

      // Save as a dependency (if it's not its own dependency)
      if (c.type != parent.name())
         dep.dependencies.push_back(
            NamespaceAndClass(ns,nameClass(elemKey,elemRHS,specs)));

      // Add to per.children
      per.children.push_back(c);
   }
} // getClassChildren


// getClassVariants
void getClassVariants(
   const nlohmann::json &j, const InfoSpecs &specs, PerClass &per,
   const NamespaceAndClass &parent, Class2Dependencies &dep
) {
   // We want to fill in per.variants, which is a vector<InfoVariants> that
   // has the "choice" children from the current parent class. First computing
   // a map<string,InfoVariants> turns out to be convenient, given the manner
   // in which the "choice" cases appear in the JSON specifications - namely,
   // listed in a "flat" manner as child nodes, rather than grouped one level
   // deeper inside of, say, a "choice" JSON key. Remark: this code supports
   // the option of having multiple variants under the current parent node;
   // for example, the parent can have {X or Y}, *and* (independently) have
   // {A or B or C}. Our "variant" JSON key facilitates this: it would be the
   // same for X and Y, and the same for A, B, and C. The current (GNDS v1.9)
   // specifications only allow for one choice-between-things (just X,Y; or
   // just A,B,C) in a given parent node, but we believe our extension will
   // prove to be useful.

   std::map<std::string,InfoVariants> map;

   // Pass 1
   // Collect "variant" names, and if ever it's absent, a to-be-determined
   // name for all choice children for which it's absent
   for (const auto &field : j.items()) {
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
   for (const auto &field : j.items()) {
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
      c.name = nameField(elemKey,elemRHS,specs);
      // ...its type, including namespace
      c.type = nameClass(elemKey,elemRHS,specs);
      const std::string ns = getChildNamespace(elemRHS,specs,parent,c.type);
      c.type = ns + "::" + c.type;
      // ...its vector-ness
      c.isVector = occ == "choice+" || occ == "choice2+";

      // The GNDS JSON specifications all have "required":false for individual
      // choices in a set of choices; the concept of "the entire choice can be
      // either required or optional" doesn't seem to exist. We could support
      // it, but for now, we'll just ensure that "required":false is followed.
      assert(!elemRHS["required"]);

      InfoVariants &v = it->second;
      v.isVector = c.isVector;
      v.children.push_back(c);

      // Save as a dependency (if it's not its own dependency)
      if (c.type != parent.name())
         dep.dependencies.push_back(
            NamespaceAndClass(ns,nameClass(elemKey,elemRHS,specs)));
   }

   // Pass 3
   for (auto &pair : map) {
      InfoVariants &v = pair.second;
      assert(v.children.size() > 0);

      const std::string vecPrefix = v.isVector ? "std::vector<" : "";
      const std::string vecSuffix = v.isVector ? ">" : "";

      v.name = pair.first;
      v.type = pair.first + "_t";

      for (const auto &c : v.children) {
         assert(c.isVector == v.isVector);
         if (pair.first == "")
            v.name += (v.name == "" ? "_" : "") + c.name;
      }
      v.typeHalf = v.type;
      v.typeFull = vecPrefix + v.type + vecSuffix;

      per.variants.push_back(v);
   }
} // getClassVariants



// -----------------------------------------------------------------------------
// writer
// -----------------------------------------------------------------------------

// Comment-related markup
const auto largeComment = "// " + std::string(77,'-');
const auto smallComment = "// " + std::string(24,'-');

class writer {
   std::ostream &s;
   std::ofstream fstream;
   std::ostringstream sstream;

   static inline const char substitute = '@';
   static inline const int indent = 3;
   static inline const std::string message =
      "\n"
      "// THIS FILE WAS AUTOGENERATED!\n"
      "// DO NOT MODIFY!\n";

public:

   // writer()
   // Use a string stream
   explicit writer(const bool autogen = true) :
      s(sstream)
   {
      if (autogen) s << message;
   }

   // writer(file)
   // Use a file stream
   explicit writer(const std::string &file, const bool autogen = true) :
      s(fstream), fstream(file)
   {
      if (autogen) s << message;
   }

   // str()
   std::string str() const
   {
      if (&s != &sstream) {
         log::error(
            "writer.str() is available only for a writer "
            "that was default constructed"
         );
         throw std::exception{};
      }
      return sstream.str();
   }

   // ------------------------
   // operator()
   // ------------------------

   // operator()(string, newline)
   template<class T=bool, class = std::enable_if_t<std::is_same_v<T,bool>>>
   void operator()(
      const std::string &string = "", const T newline = true
   ) {
      s << string;
      if (newline)
         s << std::endl;
   }

   template<class T, class = std::enable_if_t<std::is_same_v<T,bool>>>
   void operator()(
      const char *const str, const T newline = true
   ) {
      operator()(std::string(str), newline);
   }

   // operator()(level, string, newline)
   // Where level is the indentation level
   void operator()(
      const int level, const std::string &string = "", const bool newline = true
   ) {
      operator()(std::string(level*indent,' ') + string, newline);
   }

   void operator()(
      const int level, const char *const str, const bool newline = true
   ) {
      operator()(level, std::string(str), newline);
   }

   static int recurse;

   template<class T, class... Ts>
   void checkArgs(const std::string &str, const T &value, Ts &&...args)
   {
      if (recurse == 0) {
         using last = decltype(
            std::get<sizeof...(args)>(std::make_tuple(value,args...)));
         const size_t nsub = std::count(str.begin(), str.end(), substitute);
         // a bool last argument is not interpreted as an argument to print...
         const size_t narg =
            1 + sizeof...(args) - std::is_same_v<std::decay_t<last>,bool>;
         if (narg != nsub) {
            log::error(
               "Number of '{}' substitution characters and arguments "
               "don't match:\n"
               "writer(\"{}\", ...)", substitute, str);
            throw std::exception{};
         }
      }
   }

   template<
      class T, class... Ts,
      class = std::enable_if_t<!std::is_same_v<T,bool>>
   >
   void operator()(const std::string &str, const T &value, Ts &&...args)
   {
      checkArgs(str, value, std::forward<Ts>(args)...);
      recurse++;
      for (const auto &ch : str) {
         if (ch != substitute)
            s << ch;
         else {
            s << value;
            operator()(std::string(&ch+1), std::forward<Ts>(args)...);
            break;
         }
      }
      recurse--;
   }

   template<
      class T, class... Ts,
      class = std::enable_if_t<!std::is_same_v<T,bool>>
   >
   void operator()(
      const int level,
      const std::string &str, const T &value, Ts &&...args
   ) {
      checkArgs(str, value, std::forward<Ts>(args)...);
      recurse++;
      operator()(
         std::string(level*indent,' ') + str,
         value,
         std::forward<Ts>(args)...
      );
      recurse--;
   }
};

int writer::recurse = 0;



// -----------------------------------------------------------------------------
// write*
// Autogenerated admonishment, and class prefix/suffix
// -----------------------------------------------------------------------------

// Class prefix
void writeClassPrefix(
   writer &out, const NamespaceAndClass &nandc, const PerClass &per
) {
   // comment introducing class
   out();
   out();
   out();
   out(largeComment);
   out("// @::", nandc.nsname);
   out("// class @", nandc.clname);
   out(largeComment);

   // namespace+class begin
   out();
   out("namespace @ {", nandc.nsname);
   out();
   out("class @ : public Component<@@> {",
       nandc.clname, nandc.clname,
       per.isData
          ? (",true" + (per.dataType == "" ? "" : "," + per.dataType))
          : ""
   );
} // writeClassPrefix


// writeClassForComponent
void writeClassForComponent(
   writer &out, const NamespaceAndClass &nandc, const PerClass &per
) {
   // using [name for variant] = ...
   out();
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0, total = v.children.size();
      for (const auto &c : v.children)
         out(2,"@@", c.type, ++count == total ? "" : ",");
      out(1,">;");
   }

   out();
   out(1,smallComment);
   out(1,"// For Component");
   out(1,smallComment);
   out();
   out(1,"friend class Component;");
   out();
   out(1,"// Current namespace, current class, and GNDS node name");
   out(1,"static auto namespaceName() { return \"@\"; }", nandc.nsname);
   out(1,"static auto className() { return \"@\"; }", nandc.clname);
   out(1,"static auto GNDSName() { return \"@\"; }", per.nameGNDS);
   out();

   // keys() begin
   out(1,"// Core Interface object to extract metadata and child nodes");
   out(1,"static auto keys()");
   out(1,"{");

   // keys() contents
   auto total = per.metadata.size() + per.children.size() + per.variants.size();
   if (total == 0)
      out(2,"return std::tuple<>{};");
   else {
      out(2,"return");
      std::size_t count = 0;

      // metadata
      if (per.metadata.size())
         out(3,"// metadata");
      for (const auto &m : per.metadata) {
         out(3,"@{@}", m.typeFull, m.defaultValue);
         out(4,"/ Meta<>(\"@\")@", m.name, ++count < total ? " |" : "");
      }

      // children
      if (per.children.size() || per.variants.size())
         out(3,"// children");
      for (const auto &c : per.children) {
         out(3,"@{}", c.typeHalf); // w/o any std::vector
         out(4,"/ @Child<>(\"@\")@",
             c.isVector ? "++" : "--", c.name, ++count < total ? " |" : "");
      }

      // variants
      for (const auto &v : per.variants) {
         out(3,"@{}", v.typeHalf); // w/o any std::vector
         out(4,"/ @(", v.isVector ? "++" : "--", false);
         int n = 0;
         for (const auto &c : v.children)
            out("@Child<>(\"@\")", n++ == 0 ? "" : " || ", c.name, false);
         out(")@", ++count < total ? " |" : "");
      }

      out(2,";");
   }

   // keys() end
   out(1,"}");
   out();
   out("public:");
} // writeClassForComponent


// Class suffix
void writeClassSuffix(
   writer &out, const NamespaceAndClass &nandc, const std::string &version
) {
   // assignment
   out();
   out(1,smallComment);
   out(1,"// Assignment");
   out(1,smallComment);
   out();
   out(1,"// copy");
   out(1,"@ &operator=(const @ &) = default;", nandc.clname, nandc.clname);
   out();
   out(1,"// move");
   out(1,"@ &operator=(@ &&) = default;", nandc.clname, nandc.clname);

   // customization #include
   out();
   out(1,smallComment);
   out(1,"// Custom functionality");
   out(1,smallComment);
   out();
   out(1,"#include \"GNDStk/@/@/@/src/custom.hpp\"",
       version, nandc.nsname, nandc.clname);

   // class+namespace end
   out();
   out("}; // class @", nandc.clname);
   out();
   out("} // namespace @", nandc.nsname);
} // writeClassSuffix




// -----------------------------------------------------------------------------
// writeClass*
// For metadata, children, and variant children
// -----------------------------------------------------------------------------

// writeClassContentMetadata
void writeClassContentMetadata(writer &out, const PerClass &per)
{
   if (per.metadata.size())
      out(2,"// metadata");
   for (const auto &m : per.metadata) {
      per.isData && (
      m.name == "length" || m.name == "start" || m.name == "valueType")
         ? out(2,"mutable @ @", m.typeFull, m.name, false)
         : out(2,        "@ @", m.typeFull, m.name, false);
      if (m.defaultValue != "")
         out("{@}", m.defaultValue, false);
      out(";");
   }
}

// writeClassContentChildren
void writeClassContentChildren(writer &out, const PerClass &per)
{
   if (per.children.size())
      out(2,"// children");
   for (const auto &c : per.children)
      out(2,"@ @;", c.typeFull, c.name);
}

// writeClassContentVariants
void writeClassContentVariants(writer &out, const PerClass &per)
{
   if (per.variants.size())
      out(2,"// children - variant");
   for (const auto &v : per.variants)
      out(2,"@ @;", v.typeFull, v.name);
}



// -----------------------------------------------------------------------------
// writeClassGetter*
// -----------------------------------------------------------------------------

// writeClassGetterOneParam
// Helper
template<class INFO> // <== InfoChildren or InfoVariants
void writeClassGetterOneParam(
   writer &out, const INFO &i,
   const std::string &ptype, const std::string &pname // p for parameter
) {
   out();
   out(1,"// @(@)", i.name, pname);

   // const, then non-const
   out(1,"const @ &@(const @@) const", i.type, i.name, ptype, pname);
   out(1," { return getter(@(), @, \"@\"); }", i.name, pname, i.name);
   out(1,"@ &@(const @@)", i.type, i.name, ptype, pname);
   out(1," { return getter(@(), @, \"@\"); }", i.name, pname, i.name);
}


// writeClassGetterTwoParam
// Helper
template<class INFO>
void writeClassGetterTwoParam(
   writer &out, const INFO &i,
   const std::string &ptype, const std::string &pname,
   const std::string &vname // variant name
) {
   out();
   out(1,"// @(@)", i.name, pname);

   // const, then non-const
   out(1,"const @ *@(const @@) const", i.type, i.name, ptype, pname);
   out(1," { return getter<@>(@(), @, \"@\"); }", i.type, vname, pname, i.name);
   out(1,      "@ *@(const @@)",       i.type, i.name, ptype, pname);
   out(1," { return getter<@>(@(), @, \"@\"); }", i.type, vname, pname, i.name);
}


// writeClassGetter
void writeClassGetter(writer &out, const PerClass &per)
{
   out();
   out(1,smallComment);
   out(1,"// Getters");
   out(1,"// const and non-const");
   out(1,smallComment);

   // metadata
   for (const auto &m : per.metadata) {
      out();
      out(1,"// @", m.name);

      // const and non-const
      out(1,"const @ &@() const", m.typeFull, m.name);
      out(1," { return content.@; }", m.name);
      out(1,      "@ &@()",       m.typeFull, m.name);
      out(1," { return content.@; }", m.name);
   }

   // children
   for (const auto &c : per.children) {
      out();
      out(1,"// @", c.name);

      // const and non-const
      out(1,"const @ &@() const", c.typeFull, c.name);
      out(1," { return content.@; }", c.name);
      out(1,      "@ &@()",       c.typeFull, c.name);
      out(1," { return content.@; }", c.name);

      // with index or label
      if (c.isVector) {
         writeClassGetterOneParam(out, c, "std::size_t ",  "index");
         writeClassGetterOneParam(out, c, "std::string &", "label");
      }
   }

   // variants
   for (const auto &v : per.variants) {
      out();
      out(1,"// @", v.name);

      // const and non-const
      out(1,"const @ &@() const", v.typeFull, v.name);
      out(1," { return content.@; }", v.name);
      out(1,      "@ &@()",       v.typeFull, v.name);
      out(1," { return content.@; }", v.name);

      // with index or label
      if (v.isVector) {
         writeClassGetterOneParam(out, v, "std::size_t ",  "index");
         writeClassGetterOneParam(out, v, "std::string &", "label");
      }

      // alternatives
      for (const auto &c : v.children) {
         if (v.isVector) {
            writeClassGetterTwoParam(out, c, "std::size_t ",  "index", v.name);
            writeClassGetterTwoParam(out, c, "std::string &", "label", v.name);
         } else {
            out();
            out(1,"// @", c.name);

            // const and non-const
            out(1,"const @ *@() const", c.type, c.name);
            out(1," { return getter<@>(@(), \"@\"); }", c.type, v.name, c.name);
            out(1,"@ *@()", c.type, c.name);
            out(1," { return getter<@>(@(), \"@\"); }", c.type, v.name, c.name);
         }
      }
   }
} // writeClassGetter



// -----------------------------------------------------------------------------
// writeClassSetter*
// -----------------------------------------------------------------------------

// writeClassSetterChild
template<class INFO>
void writeClassSetterChild(
   writer &out, const INFO &i, // InfoChildren or InfoVariants
   const std::string &clname
) {
   // setter
   // note that if type is optional<T>, a T can still be sent
   out();
   out(1,"// @(value)", i.name);
   out(1,"@ &@(const @ &obj)", clname, i.name, i.typeFull);
   out(1," { @() = obj; return *this; }", i.name);

   // index and label cases
   if (i.isVector) {
      out();
      out(1,"// @(index,value)", i.name);
      out(1,"@ &@(", clname, i.name);
      out(2,"const std::size_t index,");
      out(2,"const @ &obj", i.type);
      out(1,") {");
      out(2,"@(index) = obj; return *this;", i.name);
      out(1,"}");
      out();
      out(1,"// @(label,value)", i.name);
      out(1,"@ &@(", clname, i.name);
      out(2,"const std::string &label,");
      out(2,"const @ &obj", i.type);
      out(1,") {");
      out(2,"@(label) = obj; return *this;", i.name);
      out(1,"}");
   }
} // writeClassSetterChild


// writeClassSetter
void writeClassSetter(
   writer &out, const PerClass &per,
   const std::string &clname
) {
   out();
   out(1,smallComment);
   out(1,"// Setters");
   out(1,"// non-const");
   out(1,"// All return *this");
   out(1,smallComment);

   // Reminder:
   //    metadata can have: optional, defaulted (but not vector)
   //    children can have: optional, vector (but not defaulted)

   // metadata
   for (const auto &m : per.metadata) {
      out();
      out(1,"// @(value)", m.name);

      // special cases: we want to send length, start, and valueType
      // to the BodyText base as well
      const bool special =
         per.isData &&
        (m.name == "length" || m.name == "start" || m.name == "valueType");

      // setter
      // note that if type is optional<T>, a T can still be sent
      out(1,"@ &@(const @ &obj)", clname, m.name, m.typeFull);
      if (special && m.isDefaulted)
         out(1," { BodyText::@(content.@ = obj); return *this; }",m.name,m.name);
      if (special && !m.isDefaulted)
         out(1," { BodyText::@(@() = obj); return *this; }", m.name, m.name);
      if (!special && m.isDefaulted)
         out(1," { content.@ = obj; return *this; }", m.name);
      if (!special && !m.isDefaulted)
         out(1," { @() = obj; return *this; }", m.name);

      // setter, if type is Defaulted<T>
      if (m.isDefaulted) {
         out(1,"@ &@(const std::optional<@> &obj)", clname, m.name, m.type);
         special
            ? out(1," { BodyText::@(content.@ = obj); return *this; }",
                  m.name, m.name)
            : out(1," { content.@ = obj; return *this; }", m.name);
      }
   }

   // children
   for (const auto &c : per.children)
      writeClassSetterChild(out, c, clname);

   // variants
   for (const auto &v : per.variants) {
      writeClassSetterChild(out, v, clname);

      // setters, using individual names
      if (v.isVector) {
         // choice is a vector<variant>
         for (const auto &c : v.children) {
            // index
            out();
            out(1,"// @(index,value)", c.name);
            out(1,"@ &@(", clname, c.name);
            out(2,"const std::size_t index,");
            out(2,"const std::optional<@> &obj", c.type);
            out(1,") {");
            out(2,"if (obj) @(index,obj.value());", v.name);
            out(2,"return *this;");
            out(1,"}");

            // label
            out();
            out(1,"// @(label,value)", c.name);
            out(1,"@ &@(", clname, c.name);
            out(2,"const std::string &label,");
            out(2,"const std::optional<@> &obj", c.type);
            out(1,") {");
            out(2,"if (obj) @(label,obj.value());", v.name);
            out(2,"return *this;");
            out(1,"}");
         }
      } else {
         // choice is a variant
         for (const auto &c : v.children) {
            out();
            out(1,"// @(value)", c.name);
            out(1,"@ &@(const std::optional<@> &obj)", clname, c.name, c.type);
            out(1," { if (obj) @(obj.value()); return *this; }", v.name);
         }
      }
   }
} // writeClassSetter



// -----------------------------------------------------------------------------
// writeClassCtor*
// -----------------------------------------------------------------------------

// writeClassCtorComponent
void writeClassCtorComponent(
   writer &out, const PerClass &per, const bool hasOther
) {
   out(2,"Component{");
   out(3, hasOther ? "other" : "BodyText{}", false);

   for (const auto &m : per.metadata) { // metadata
      out(",");
      out(3,"content.@", m.name, false);
   }
   for (const auto &c : per.children) { // children
      out(",");
      out(3,"content.@", c.name, false);
   }
   for (const auto &v : per.variants) { // variants
      out(",");
      out(3,"content.@", v.name, false);
   }

   out();
   out(2,"}",false);
} // writeClassCtorComponent


// writeClassCtorBody
void writeClassCtorBody(writer &out, const std::string &argName)
{
   out(1,"{");
   out(2,"Component::finish(@);", argName);
   out(1,"}");
} // writeClassCtorBody


// writeClassCtor
void writeClassCtor(
   writer &out, const PerClass &per, const std::string &clname
) {
   // ctor: default
   out();
   out(1,"// default");
   out(1,"@() :", clname);
   writeClassCtorComponent(out, per, false);
   out();
   writeClassCtorBody(out, "");

   // ctor: copy
   out();
   out(1,"// copy");
   out(1,"@(const @ &other) :", clname, clname);
   writeClassCtorComponent(out, per, true);
   out(",");
   out(2,"content{other.content}");
   writeClassCtorBody(out, "other");

   // ctor: move
   out();
   out(1,"// move");
   out(1,"@(@ &&other) :", clname, clname);
   writeClassCtorComponent(out, per, true);
   out(",");
   out(2,"content{std::move(other.content)}");
   writeClassCtorBody(out, "other");

   // ctor: node
   out();
   out(1,"// from node");
   out(1,"@(const Node &node) :", clname);
   writeClassCtorComponent(out, per, false);
   out();
   writeClassCtorBody(out, "node");

   // ------------------------
   // ctor: fields
   // ------------------------

   const auto total =
      per.metadata.size() +
      per.children.size() +
      per.variants.size();

   if (total != 0) {
      out();
      out(1,"// from fields");
      for (const auto &m : per.metadata) {
         if (m.isDefaulted) {
            out(1,"// std::optional replaces Defaulted; "
                "this class knows the default(s)");
            break;
         }
      }

      // signature, and base constructor call
      // Note: we don't need "explicit" unless this constructor can be called
      // with one argument. We'll always write it, however, in case someone
      // modifies the auto-generated constructor (say, giving its arguments
      // defaults) in such a way that is *can* be called with one argument.
      // But we'd rather nobody modify the auto-generated classes.
      std::size_t count = 0;
      out(1,"explicit @(", clname);
      for (const auto &m : per.metadata) {
         out(2,"const @ &@@",
             m.isDefaulted ? "std::optional<" + m.type + ">" : m.typeFull,
             m.name, ++count < total ? "," : "");
      }
      for (const auto &c : per.children) {
         out(2,"const @ &@@",
             c.typeFull,
             c.name, ++count < total ? "," : "");
      }
      for (const auto &v : per.variants) {
         out(2,"const @ &@@",
             v.typeFull,
             v.name, ++count < total ? "," : "");
      }

      out(1,") :");
      writeClassCtorComponent(out, per, false);

      // initialize fields
      out(",");
      out(2,"content{");
      count = 0;
      for (const auto &m : per.metadata) {
         out(3,"@@",
             m.isDefaulted
                ? "Defaulted<"+m.type+">(defaults."+m.name+","+m.name+")"
                : m.name,
             ++count < total ? "," : "");
      }
      for (const auto &c : per.children)
         out(3,"@@", c.name, ++count < total ? "," : "");
      for (const auto &v : per.variants)
         out(3,"@@", v.name, ++count < total ? "," : "");
      out(2,"}");

      // body
      writeClassCtorBody(out, "");
   }

   // ------------------------
   // ctor: vector
   // ------------------------

   if (per.isData) {
      out();
      out(1,"// from vector");
      out(1,"template<class T, class = "
          "std::enable_if_t<body::template supported<T>>>");
      out(1,"@(const std::vector<T> &vector) :", clname);
      writeClassCtorComponent(out, per, false);
      out();
      writeClassCtorBody(out, "vector");
   }
} // writeClassCtor



// -----------------------------------------------------------------------------
// writeClass
// -----------------------------------------------------------------------------

void writeClass(
   PerClass &per, const NamespaceAndClass &nandc, const InfoSpecs &specs
) {
   writer out(false);

   // output: class begin
   writeClassPrefix(out, nandc, per);

   // output: for the Component base
   writeClassForComponent(out, nandc, per);

   // output: using directives
   out();
   out(1,"using Component::construct;");
   if (per.isData)
      out(1,"using BodyText::operator=;");

   // output: defaults (applicable only to metadata)
   out();
   out(1,smallComment);
   out(1,"// Relevant defaults");
   out(1,"// FYI for users");
   out(1,smallComment);
   out();
   out(1,"static inline const struct Defaults {");
   for (auto &m : per.metadata)
      if (m.isDefaulted)
         out(2,"static inline const @ @ = @;", m.type, m.name, m.defaultValue);
   out(1,"} defaults;");

   // output: content (the metadata/children computed earlier)
   out();
   out(1,smallComment);
   out(1,"// Raw GNDS content");
   out(1,smallComment);
   out();
   out(1,"struct {");
   writeClassContentMetadata(out, per);
   writeClassContentChildren(out, per);
   writeClassContentVariants(out, per);
   out(1,"} content;");

   // output: getters, setters
   if (per.metadata.size() || per.children.size() || per.variants.size()) {
      writeClassGetter(out, per);
      writeClassSetter(out, per, nandc.clname);
   }

   // output: constructors
   out();
   out(1,smallComment);
   out(1,"// Construction");
   out(1,smallComment);
   writeClassCtor(out, per, nandc.clname);

   // output: class end
   writeClassSuffix(out, nandc, specs.Version);

   // done
   per.code = out.str();
} // writeClass



// -----------------------------------------------------------------------------
// Miscellaneous functions for getting JSON content
// -----------------------------------------------------------------------------

// readJSONFile
nlohmann::json readJSONFile(const std::string &file, const bool print = false)
{
   static const std::string underlineON  = "\033[4m";
   static const std::string underlineOFF = "\033[24m";

   // Depending on call context, we might want to print the file name
   if (print) {
      std::cout << "   ";
      std::cout << underlineON << "File:" << underlineOFF << " ";
      std::cout << '"' << colors::vivid::green << file << colors::reset << '"';
      std::cout << std::endl;
   }

   std::ifstream ifs(file);
   if (!ifs) {
      log::error("Could not open file \"{}\"", file);
      throw std::exception{};
   }

   nlohmann::json j;
   ifs >> j;
   return j;
} // readJSONFile


// getMetadataJSON
template<bool required>
auto getMetadataJSON(const nlohmann::json &j)
{
   static const std::string metastr = "metadata";
   static const std::string attrstr = "attributes";

   const bool meta = j.contains(metastr);
   const bool attr = j.contains(attrstr);

   if constexpr (required) {
      assert(meta != attr); // exactly one
      return meta ? j[metastr] : j[attrstr];
   } else {
      assert(!(meta && attr)); // not both
      return std::optional<nlohmann::json>(
         meta ? j[metastr] : attr ? j[attrstr] : nlohmann::json{});
   }
} // getMetadataJSON


// getChildrenJSON
template<bool required>
auto getChildrenJSON(const nlohmann::json &j)
{
   static const std::string chldstr = "children";
   static const std::string nodestr = "childNodes";

   const bool chld = j.contains(chldstr);
   const bool node = j.contains(nodestr);

   if constexpr (required) {
      assert(chld != node); // exactly one
      return chld ? j[chldstr] : j[nodestr];
   } else {
      assert(!(chld && node)); // not both
      return std::optional<nlohmann::json>(
         chld ? j[chldstr] : node ? j[nodestr] : nlohmann::json{});
   }
} // getChildrenJSON



// -----------------------------------------------------------------------------
// commandLine and its helper functions
// -----------------------------------------------------------------------------

// readChangesFile
void readChangesFile(const std::string &file, InfoSpecs &specs)
{
   const nlohmann::json jchanges = readJSONFile(file);
   using pair = std::pair<std::string,std::string>;

   // Changes to name?
   if (jchanges.contains("name"))
      for (const auto &item : jchanges["name"].items())
         if (!isComment(item.key()))
            specs.mapName.insert(pair(item.key(),item.value()));

   // Changes to metadata/attributes?
   const auto metadata = getMetadataJSON<false>(jchanges);
   if (metadata.has_value()) {
      // from/to pairs for "type"
      if (metadata->contains("type"))
         for (const auto &item : (*metadata)["type"].items())
            if (!isComment(item.key()))
               specs.mapMetaType.insert(pair(item.key(),item.value()));
      // from/to pairs for "default"
      if (metadata->contains("default"))
         for (const auto &item : (*metadata)["default"].items())
            if (!isComment(item.key()))
               specs.mapMetaDefault.insert(pair(item.key(),item.value()));
   }
} // readChangesFile


// printSingletons
void printSingletons(const std::string &file)
{
   const nlohmann::json &jfile = readJSONFile(file,true);

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
} // printSingletons


// commandLine
// Gather information from the .json file given on the command line
void commandLine(const int argc, const char *const *const argv, InfoSpecs &specs)
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
      exit(EXIT_FAILURE);
   }

   // Input file
   const nlohmann::json jmain = readJSONFile(argv[1]);

   // Validate content
   if (!(jmain.contains(input) && jmain.contains(output) &&
         jmain.contains(files) && jmain.contains(version)
   )) {
      log::error("The input json file needs {}, {}, {}, and {}",
                 input, files, output, version);
      throw std::exception{};
   }

   // Extract information from the command line .json
   specs.JSONDir   = jmain[input];
   specs.JSONFiles = std::vector<std::string>(jmain[files]);
   specs.GNDSDir   = jmain[output];
   specs.Version   = jmain[version];
   specs.VersionUnderscore = replace(specs.Version, '.', '_');

   // Prepend the JSON file names with their directory
   for (std::string &file : specs.JSONFiles)
      file = specs.JSONDir + '/' + file;

   // File names
   specs.hppVersion = specs.GNDSDir + "/src/GNDStk/" + specs.Version + ".hpp";
   specs.hppKey = specs.GNDSDir + "/src/GNDStk/" + specs.Version + "/key.hpp";

   // Report on "singletons"
   if (singletons) {
      action("Finding possible simplifications");
      for (const std::string &file : specs.JSONFiles)
         printSingletons(file);
   }

   // Changes?
   if (jmain.contains(changes))
      readChangesFile(jmain[changes],specs);
} // commandLine



// -----------------------------------------------------------------------------
// preprocess* functions
// -----------------------------------------------------------------------------

// preprocessClass
void preprocessClass(
   InfoSpecs &specs, const std::string &nsname,
   const std::string &classKey, const nlohmann::json &classRHS,
   const KeyValue &
) {
   // Ensure that this JSON entry represents a class - as opposed
   // to being, say, "namespace" or some other non-class entry.
   if (!isClass(classKey,classRHS))
      return;

   // Get the class name, then link this class with the current namespace.
   // This information is used, later, for various purposes.
   const std::string clname = nameClass(classKey,classRHS,specs);
   specs.class2nspace.insert(std::make_pair(clname,nsname));

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
      nsdir   = specs.GNDSDir + "/src/GNDStk/" + specs.Version + "/" + nsname,
      nsdirpy = specs.GNDSDir + "/python/src/" + specs.Version + "/" + nsname,
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
      std::cout << "   No customization file " << custom << "\n";
      std::cout << "   ...so, creating a basic one" << std::endl;

      writer out(custom,false); // no "this file was autogenerated" message
      out();
      out(0,"private:");
      out();
      out(1,"static inline helpMap help = {};");
   }

   // ------------------------
   // Create file-name maps
   // ------------------------

   // For this namespace:
   //    The cpp file for Python
   auto ns = specs.namespace2data.insert(std::make_pair(nsname, PerNamespace{}));
   ns.first->second.cppPython = nsdirpy + ".python.cpp";

   // For this namespace::class:
   //    The cpp file for Python
   //    The hpp file for GNDStk
   auto cl = specs.class2data.insert(
      std::make_pair(NamespaceAndClass{nsname,clname}, PerClass{}));
   assert(cl.second); // should have been inserted - not there already
   cl.first->second.cppPython = nsdirpy + "/" + clname + ".python.cpp";
   cl.first->second.hppGNDStk = nsdir   + "/" + clname + ".hpp";
} // preprocessClass


// preprocessFiles
// This reads the JSON spec files and collects preliminary information that's
// used, later, when the spec files are processed in more detail. (Detailed
// processing requires knowledge obtained from this preliminary pass, which is
// why these things are done separately.) This preliminary processing includes
// creating a class-to-namespace map; creating directories into which output
// files will be placed; creating class-specific customization files when it's
// appropriate to do so; and creating maps from namespace to namespace-specific
// information, and from namespace::class to class-specific information. File
// names are computed as part of the "information" for the maps just mentioned.
void preprocessFiles(InfoSpecs &specs)
{
   action("Preprocessing input files");
   for (const std::string &file : specs.JSONFiles) {
      const nlohmann::json jmain = readJSONFile(file,true);
      const std::string nsname = getFileNamespace(jmain);
      for (const auto &cl : jmain.items())
         preprocessClass(specs, nsname, cl.key(), cl.value(), cl);///
   }
} // preprocessFiles



// -----------------------------------------------------------------------------
// validate*
// getClass
// getFiles
// -----------------------------------------------------------------------------

// Helper: validateMetadata
void validateMetadata(const nlohmann::json &metadata)
{
   for (const auto &field : metadata.items()) {
      assert(field.value().contains("type"));
      assert(field.value().contains("required"));
   }
}


// Helper: validateChildren
void validateChildren(const nlohmann::json &children)
{
   for (const auto &field : children.items()) {
      assert(field.value().contains("occurrence"));
      assert(field.value().contains("required"));

      // Consistency check: certain "occurrence" values imply *not* required.
      // Remark: the GNDS manual speaks of "choice2" and "choice2+" options
      // for occurrence. We're not sure if those will remain in future GNDS
      // specifications, so we won't worry now about how they might fit in.
      const std::string occ = field.value()["occurrence"];
      if (occ == "0+" || occ == "choice" || occ == "choice+")
         assert(!field.value()["required"]); // not required
   }
}


// getClass
void getClass(
   InfoSpecs &specs, const std::string &nsname,
   const std::string &classKey, const nlohmann::json &classRHS
) {
   if (!isClass(classKey,classRHS))
      return;
   const std::string clname = nameClass(classKey,classRHS,specs);

   // find in class map
   const NamespaceAndClass nandc(nsname,clname);
   const auto it = specs.class2data.find(nandc);
   assert(it != specs.class2data.end());
   PerClass &per = it->second;

   // collect dependencies, for the present class, as this function proceeds
   Class2Dependencies dep;
   dep.theClass = nandc;

   // names
   per.nameGNDS = nameGNDS(classKey,classRHS);

   // metadata/children information
   const nlohmann::json attrs = getMetadataJSON<true>(classRHS);
   const nlohmann::json elems = getChildrenJSON<true>(classRHS);
   validateMetadata(attrs);
   validateChildren(elems);
   getClassMetadata(attrs, specs, per);
   getClassChildren(elems, specs, per, nandc, dep);
   getClassVariants(elems, specs, per, nandc, dep);

   // data-node information
   static const std::string datastr = "data";
   static const std::string bodystr = "bodyText";
   const bool data = classRHS.contains(datastr) && !classRHS[datastr].is_null();
   const bool body = classRHS.contains(bodystr) && !classRHS[bodystr].is_null();
   assert(!(data && body)); // not both
   per.isData = data || body;
   per.dataType = data ? classRHS[datastr] : "";

   // per.code will get printed C++ code for the class itself
   writeClass(per, nandc, specs);

   // save dependencies
   specs.ClassDependenciesRaw.push_back(dep);
} // getClass


// getFiles
void getFiles(InfoSpecs &specs)
{
   action("Creating classes");
   for (const std::string &file : specs.JSONFiles) {
      const nlohmann::json jmain = readJSONFile(file,true);
      const std::string nsname = getFileNamespace(jmain);
      for (const auto &aClass : jmain.items())
         getClass(specs, nsname, aClass.key(), aClass.value());
   }
} // getFiles



// -----------------------------------------------------------------------------
// Functions relating to our topological sort
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
      [wanted](const Class2Dependencies &c2d) { return c2d.theClass == wanted; }
   );

   if (iter != vecSource.end()) {
      const Class2Dependencies c2d = *iter;
      vecSource.erase(iter);
      for (const NamespaceAndClass &dep : c2d.dependencies)
         insertDependency(dep, vecSource, vecTarget);
      vecTarget.push_back(c2d);
   }
}

// sortDependencies
void sortDependencies(InfoSpecs &specs)
{
   while (specs.ClassDependenciesRaw.size() > 0)
      insertDependency(
         specs.ClassDependenciesRaw.begin()->theClass,
         specs.ClassDependenciesRaw,
         specs.ClassDependenciesSorted);
}



// -----------------------------------------------------------------------------
// Functions for creating output files
// -----------------------------------------------------------------------------

// fileGNDStkVersion
void fileGNDStkVersion(const InfoSpecs &specs)
{
   // Create an overarching file for this version
   writer out(specs.hppVersion);
   out();
   out("#ifndef NJOY_GNDSTK_@", allcaps(specs.VersionUnderscore));
   out("#define NJOY_GNDSTK_@", allcaps(specs.VersionUnderscore));

   std::string nsname_last = "";
   for (auto &c : specs.class2data) {
      const std::string nsname = c.first.nsname;
      const std::string clname = c.first.clname;
      if (nsname != nsname_last)
         out();
      nsname_last = nsname;
      out("#include \"GNDStk/@/@/@.hpp\"", specs.Version, nsname, clname);
   }

   out();
   out("#include \"GNDStk/@/key.hpp\"", specs.Version);
   out();
   out("#endif");
} // fileGNDStkVersion


/// fixme Reconsider the arrangement described here...
// fileGNDStkKey
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

void fileGNDStkKey(const InfoSpecs &specs)
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
   // The multimap contains: namespace name, set<pair>
   std::multimap<std::string, std::set<pair>> namespace2children;

   for (const auto &file : specs.JSONFiles) {
      const nlohmann::json jmain = readJSONFile(file);
      const std::string nsname = getFileNamespace(jmain);
      auto it = namespace2children.insert(std::make_pair(nsname,std::set<pair>{}));

      for (const auto &node : jmain.items()) {
         if (!isClass(node.key(), node.value()))
            continue;

         // nodes ==> children
         it->second.insert(std::make_pair(
            nameField(node.key(), node.value(), specs),
            nameGNDS (node.key(), node.value())));

         // attributes ==> metadata
         const auto attrs = getMetadataJSON<true>(node.value());
         for (const auto &attr : attrs.items())
            metadata.insert(std::make_pair(
               nameField(attr.key(), attr.value(), specs),
               nameGNDS (attr.key(), attr.value())));
      }
   }

   const std::string version = specs.VersionUnderscore;
   const std::string VERSION = allcaps(version);

   // ------------------------
   // comment, macro guard,
   // outer namespaces
   // ------------------------

   writer out(specs.hppKey);
   out();
   out("/*",false);
   out(file_key_comment,false);
   out("*/");
   out();
   out("#ifndef NJOY_GNDSTK_@_KEY", VERSION);
   out("#define NJOY_GNDSTK_@_KEY", VERSION);
   out();
   out("namespace njoy {");
   out("namespace GNDStk {");
   out("namespace @ {", version);

   // ------------------------
   // Meta<> objects
   // ------------------------

   out();
   out();
   out(largeComment);
   out("// key::meta::");
   out(largeComment);
   out();
   out("namespace key {");
   out("namespace meta {");

   if (metadata.size() > 0) {
      out();
      for (const auto &meta : metadata)
         out("inline const Meta<> @(\"@\");", meta.first, meta.second);
      out();
   }

   out("} // namespace meta");
   out("using namespace meta;");
   out("} // namespace key");

   // ------------------------
   // Child<> objects
   // ------------------------

   for (const auto &nspace : namespace2children) {
      out();
      out();
      out(largeComment);
      out("// @::key::child::", nspace.first);
      out(largeComment);
      out();
      out("namespace @ {", nspace.first);
      out("namespace key {");
      out("namespace child {");

      const auto &children = nspace.second;
      if (children.size() > 0) {
         out();
         for (const auto &child : children)
            out("inline const Child<> @(\"@\");", child.first, child.second);
         out();
      }

      out("} // namespace child");
      out("using namespace child;");
      out("} // namespace key");
      out("} // namespace @", nspace.first);
   }

   // ------------------------
   // finish
   // ------------------------

   out();
   out();
   out(largeComment);
   out(largeComment);
   out();
   out("} // namespace @", version);
   out("} // namespace GNDStk");
   out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkKey


// fileGNDStkClass
void fileGNDStkClass(
   const InfoSpecs &specs, const NamespaceAndClass &nandc,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // class-specific hpp file
   writer out(per.hppGNDStk);
   const std::string guard =
     "NJOY_GNDSTK_" + allcaps(specs.VersionUnderscore) + "_" +
      allcaps(nandc.nsname) + "_" + allcaps(nandc.clname);

   out();
   out("#ifndef @", guard);
   out("#define @", guard);
   out();
   out("// core interface");
   out("#include \"GNDStk.hpp\"");
   out();

   if (c2d.dependencies.size() > 0) {
      out("// @ dependencies", specs.Version);
      for (const auto &dep : c2d.dependencies) {
         out("#include \"GNDStk/@/@/@.hpp\"",
             specs.Version, dep.nsname, dep.clname);
      }
      out();
   }

   out("namespace njoy {");
   out("namespace GNDStk {");
   out("namespace @ {", specs.VersionUnderscore);
   out();
   out("using namespace njoy::GNDStk::core;");
   out(per.code,false); // no \n
   out("} // namespace @", specs.VersionUnderscore);
   out("} // namespace GNDStk");
   out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkClass


// filePythonNamespace
void filePythonNamespace(
   const InfoSpecs &specs, const std::string &nsname, const PerNamespace &per
) {
   writer out(per.cppPython);
   out();
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");
   out();
   out("namespace python = pybind11;");
   out();
   out("// @ interface", specs.Version);
   out("namespace python_@ {", specs.VersionUnderscore);

   out();
   out("// @ declarations", nsname);
   out("namespace python_@ {", nsname);
   for (auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == nsname)
         out(1,"void wrap@(python::module &);", cl.theClass.clname);
   out("} // namespace python_@", nsname);

   out();
   out("// @ wrapper", nsname);
   out("void wrap@(python::module &module)", capital(nsname));
   out("{");
   out(1,"// create the @ submodule", nsname);
   out(1,"python::module submodule = module.def_submodule(");
   out(2,"\"@\",", nsname);
   out(2,"\"GNDS @ @\"", specs.Version, nsname);
   out(1,");");

   out();
   out(1,"// wrap @ components", nsname);
   for (auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == nsname)
         out(1,"python_@::wrap@(submodule);", nsname, cl.theClass.clname);
   out("};");
   out();
   out("} // namespace python_@", specs.VersionUnderscore);
} // filePythonNamespace


// filePythonClass
void filePythonClass(
   const InfoSpecs &specs, const NamespaceAndClass &nandc, const PerClass &per
) {
   const std::string &nsname = nandc.nsname;
   const std::string &clname = nandc.clname;
   writer out(per.cppPython);

   out();
   out("// system includes");
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");
   out();

   out("// local includes");
   out("#include \"GNDStk/@/@/@.hpp\"", specs.Version, nsname, clname);
   out("#include \"definitions.hpp\"");
   out();

   out("// namespace aliases");
   out("namespace python = pybind11;");
   out();

   out("namespace python_@ {", specs.VersionUnderscore);
   out("namespace python_@ {", nsname);
   out();

   out("// @ wrapper", clname);
   out("void wrap@(python::module &module)", clname);
   out("{");
   out(1,"using namespace njoy::GNDStk;");
   out(1,"using namespace njoy::GNDStk::@;", specs.VersionUnderscore);
   out();
   out(1,"// type aliases");
   out(1,"using Component = @::@;", nsname, clname);

   // using [variant name] = std::variant..., if necessary
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0, total = v.children.size();
      for (const auto &c : v.children)
         out(2, "@@", c.type, ++count == total ? "" : ",");
      out(1,">;");
   }

   out();
   out(1,"// create the component");
   out(1,"python::class_<Component> component(");
   out(2,"module,");
   out(2,"\"@\",", clname);
   out(2,"Component::documentation().data()");
   out(1,");");
   out();
   out(1,"// wrap the component");
   out(1,"component");
   out(2,".def(");

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
         if (m.name == "valueType") {
            if (m.defaultValue == "\"Integer32\"") {
               bodyType = "Integer32";
               bodyName = "ints";
            } else if (m.defaultValue == "\"Float64\"") {
               bodyType = "Float64";
               bodyName = "doubles";
            } else if (m.defaultValue == "\"UTF8Text\"") {
               bodyType = "UTF8Text";
               bodyName = "strings";
            }
         }
      }
   }

   // python::init<...>
   out(3,"python::init<");
   int count = 0;
   int total = per.metadata.size() + per.children.size() + per.variants.size()
             + per.isData;
   for (auto &m : per.metadata) {
      const std::string type = m.isDefaulted
         ? "std::optional<" + m.type + ">"
         : m.typeFull;
      out(4,"const @ &@", type, ++count < total ? "," : "");
   }
   for (auto &c : per.children)
      out(4,"const @ &@", c.typeFull, ++count < total ? "," : "");
   for (auto &v : per.variants)
      out(4,"const @ &@", v.typeFull, ++count < total ? "," : "");
   if (per.isData)
      out(4,"const std::vector<@> &", bodyType);
   out(3,">(),");

   // python::arg...
   for (auto &m : per.metadata) {
      out(3,"python::arg(\"@\")@,",
          namePython(m.name),
          (m.isOptional || m.isDefaulted) ? " = std::nullopt" : "");
   }
   for (auto &c : per.children) {
      out(3,"python::arg(\"@\")@,", namePython(c.name),
          c.isOptional ? " = std::nullopt" : "");
   }
   for (auto &v : per.variants)
      out(3,"python::arg(\"@\"),", namePython(v.name));
   if (per.isData)
      out(3,"python::arg(\"values\"),");
   out(3,"Component::documentation(\"constructor\").data()");
   out(2,")");

   // .def_property_readonly...
   for (auto &m : per.metadata) {
      const auto pyname = namePython(m.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      m.isDefaulted
         ? out(3,"[](const Component &self) { return self.@().value(); },",
               m.name)
         : out(3,"&Component::@,",
               m.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   for (auto &c : per.children) {
      const auto pyname = namePython(c.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      out(3,"python::overload_cast<>(&Component::@),", c.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   for (auto &v : per.variants) {
      if (!v.isVector)
         for (auto &c : v.children) {
            const auto pyname = namePython(c.name);
            out(2,".def_property_readonly(");
            out(3,"\"@\",", pyname);
            out(3,"python::overload_cast<>(&Component::@),", c.name);
            out(3,"Component::documentation(\"@\").data()", pyname);
            out(2,")");
         }
      const auto pyname = namePython(v.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      out(3,"python::overload_cast<>(&Component::@),", v.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   if (per.isData) {
      out(2,".def_property_readonly(");
      out(3,"\"@\",", bodyName);
      out(3,"[] (const Component &self) { return self.@(); },", bodyName);
      out(3,"Component::documentation(\"@\").data()", bodyName);
      out(2,")");
   }

   // finish up
   out(1,";");
   out();
   out(1,"// add standard component definitions");
   out(1,"addStandardComponentDefinitions< Component >( component );");
   out("}");
   out();
   out("} // namespace python_@", nsname);
   out("} // namespace python_@", specs.VersionUnderscore);
} // filePythonClass



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   // For GNDStk's diagnostics
   color = true;

   // READ INFORMATION from the JSON file on the command line
   InfoSpecs specs;
   commandLine(argc, argv, specs);

   // PREPROCESS, to get information needed upfront for detailed processing
   preprocessFiles(specs);

   // PRINT CLASS CODE into temporary strings, which are written to the
   // class-specific files later, after class dependencies are computed
   getFiles(specs);

   // COMPUTE AN ORDERING that respects dependencies
   sortDependencies(specs);

   // GNDStk hpp file for this GNDS version
   fileGNDStkVersion(specs);

   // GNDStk hpp file for Meta and Child keys
   fileGNDStkKey(specs);

   // GNDStk hpp file for each namespace::class
   for (const auto &obj : specs.ClassDependenciesSorted) {
      auto find = specs.class2data.find(obj.theClass);
      assert(find != specs.class2data.end());
      fileGNDStkClass(specs, find->first, find->second, obj);///first+second??
   }

   // Python cpp file for each namespace
   for (auto &obj : specs.namespace2data)
      filePythonNamespace(specs, obj.first, obj.second);///first+second??

   // Python cpp file for each namespace::class
   for (auto &obj : specs.class2data)
      filePythonClass(specs, obj.first, obj.second);///first+second??
   std::cout << std::endl;
}
