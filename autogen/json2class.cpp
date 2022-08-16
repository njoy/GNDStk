
// -----------------------------------------------------------------------------
// Tool for autogenerating GNDStk classes from JSON specifications
// -----------------------------------------------------------------------------

#include "GNDStk.hpp"
#include <cstring>
using namespace njoy::GNDStk;

// Report cases of nodes that have no metadata, and zero or one child node(s).
// Where these exist, a simplification of the spec may be worth considering.
const bool singletons = true;



// -----------------------------------------------------------------------------
// Data structures
// -----------------------------------------------------------------------------

// KeyValue
// Too bad the JSON library doesn't provide this more straightforwardly
using KeyValue = nlohmann::detail::iteration_proxy_value<
   nlohmann::detail::iter_impl<const orderedJSON>
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
};

// Class2Dependencies
// For a {namespace,class}, its {namespace,class} dependencies
struct Class2Dependencies {
   NamespaceAndClass theClass;
   std::vector<NamespaceAndClass> dependencies;
};

// InfoMetadata
struct InfoMetadata {
   // A JSON spec can make a metadatum be:
   //    - a std::optional, or
   //    - a GNDStk::defaulted
   // but (in contrast with child nodes) can't make it be a vector of metadata.
   // An individual metadatum may be a vector in its own right, as in an XML
   // construct such as <element meta="1 2 3 4"> (so that meta is a vector of
   // integers). We mean here that there isn't a vector of such [meta] entries,
   // and shouldn't be (XML wouldn't allow it).
   std::string name;
   std::string type;     // underlying type
   std::string typeFull; // WITH any optional<> or defaulted<>
   bool        isOptional;
   bool        isDefaulted;
   std::string defaultValue;
};

// InfoChildren
struct InfoChildren {
   // A JSON spec can make a child node be:
   //    - a std::optional, and/or
   //    - a std::vector
   // but can't make it be a GNDStk::defaulted. (The use of a default value for
   // child nodes just doesn't exist in the GNDS specifications, even though the
   // concept would seem to make sense.)
   std::string name;
   std::string ns;       // enclosing namespace
   std::string plain;    // underlying type, excluding namespace
   std::string type;     // underlying type
   std::string typeFull; // WITH any optional<> or vector<>
   std::string typeHalf; // withOUT any vector<>
   bool        isOptional;
   bool        isVector;
};

// InfoVariantsChildren
struct InfoVariantsChildren {
   std::string name;
   std::string ns;       // enclosing namespace
   std::string plain;    // underlying type, excluding namespace
   std::string type;     // underlying type
   bool        isVector;
};

// InfoVariants
struct InfoVariants {
   std::string name;
   std::string type;     // underlying type
   std::string typeFull; // WITH any optional<> or vector<>
   std::string typeHalf; // withOUT any vector<>
   bool        isVector;
   std::vector<InfoVariantsChildren> children;
};

// PerNamespace
struct PerNamespace {
   std::string cppPython; // cpp file for this namespace's Python interface
   std::string nsname;    // name of this namespace
};

// PerClass
struct PerClass {
   std::string cppPython; // cpp file for this class' Python interface
   std::string hppGNDStk; // hpp file for this class in GNDStk
   std::string headerC;   // header that works with both C and C++
   std::string sourceC;   // C++ backend source for the C interface

   std::string nsname;    // name of this class' namespace
   std::string clname;    // name of this class
   std::string nameGNDS;  // name of this class as a GNDS node

   std::string name() const { return nsname + "::" + clname; }

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
   int nfields() const
      { return metadata.size() + children.size() + variants.size(); }

   // Data node?
   // If (and only if) isData, dataType is considered. If dataType == "", this
   // is the situation in GNDS in which the type of data residing in a node is
   // to be determined dynamically, via a string metadatum called valueType. If
   // dataType != "" (for example, dataType == "int" or dataType == "double"),
   // then dataType is considered to stipulate the given type.
   bool isData;
   std::string dataType;
};



// -----------------------------------------------------------------------------
// InfoSpecs
// -----------------------------------------------------------------------------

// Overarching data structure reflecting all of the autogenerator's input
// as well as various processed information
struct InfoSpecs {
   // From the JSON file on the command line
   std::string Path;
   std::string Project;
   std::string Version;
   std::string JSONDir;
   std::vector<std::string> JSONFiles;

   // Version, but with '_' in place of '.'
   std::string VersionUnderscore;

   // Directory-prefixed names
   std::string hppVersion; // hpp file for this version
   std::string hppKey;     // hpp file for this version's Meta and Child keys
   std::string hVersion;   // header file for both C and C++
   std::string cVersion;   // C++ backend source for the C interface

   // Changes to apply to a metadatum's name or a child node's name.
   // Example: "double" (GNDS v1.9 actually has "double") to "Double" for C++.
   std::map<std::string,std::string> mapName;

   // Changes to apply to metadata/attribute type and default.
   // Examples: "Boolean" to "bool", "interpolation" to "enums::Interpolation".
   // We'll give a string ==> std::string type change as a freebie. :-)
   std::map<std::string,std::string> mapMetaType = {{"string","std::string"}};
   std::map<std::string,std::string> mapMetaDefault;

   // For each class in the input JSON specifications, the namespace(s)
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
   nlohmann::ordered_map<NamespaceAndClass,PerClass> class2data;
}; // InfoSpecs



// -----------------------------------------------------------------------------
// Miscellaneous short functions
// -----------------------------------------------------------------------------

// Print text describing an action the code is about to take
void action(const std::string &str)
{
   std::cout << colors::plain::blue << str << colors::reset << std::endl;
}

// Is the string all whitespace?
bool allws(const std::string &str)
{
   for (const auto c : str)
      if (!isspace(c))
         return false;
   return true;
}

// Escape any double quotes in the string
std::string escape(const std::string &str)
{
   std::string ret;
   for (const auto c : str) {
      if (c == '"')
         ret += '\\';
      ret += c;
   }
   return ret;
}

// initializer
// Based on m.type and m.defaultValue, make something appropriate to use
// for initialization, as with: m.type var{return value of this function}
std::string initializer(const InfoMetadata &m)
{
   // Leave an empty or all-whitespace m.defaultValue as-is.
   // This is the "no initializer" case.
   if (allws(m.defaultValue))
      return "";

   // If of string type, add double quotes.
   // We assume that the input does NOT have the quotes already!
   // Note: we may not need all of these, but the GNDS manual does describe
   // several string-like types, so we might as well include them.
   if (m.type == "XMLName" || m.type == "UTF8Text" ||
       m.type == "printableText" || m.type == "quotedText" ||
       m.type == "tdText" || m.type == "string" || m.type == "std::string")
      return '"' + escape(m.defaultValue) + '"';

   // Leave as-is;
   // applicable for non-string (int, double, etc.) cases
   return m.defaultValue;
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

// UpperCamel
std::string UpperCamel(const std::string &str)
{
   std::string ret;
   for (size_t i = 0; i < str.size(); ++i)
      if (str[i] != '_')
         ret += i ? str[i] : toupper(str[i]);
      else if (++i < str.size())
         ret += toupper(str[i]);
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
std::string stringify(const orderedJSON &j)
{
   const auto tmp = j.dump();
   return j.type() == orderedJSON::value_t::string
      ? tmp.substr(1, tmp.size()-2)
      : tmp;
}

// Does this JSON key look like a C++ style comment?
bool isComment(const std::string &key)
{
   return strncmp(key.data(), "//", 2) == 0;
}

// Does this JSON key/value pair appear to describe a class?
bool isClass(const KeyValue &keyval)
{
   const auto &key = keyval.key();
   const auto &val = keyval.value();

   // a comment?
   if (isComment(key))
      return false;

   // not a class?
   if (key == "__namespace__" || key == "namespace" || key == "Specifications")
      return false;

   // not a node class?
   if ((val.contains("__class__") && val["__class__"] != "nodes.Node") ||
       (val.contains(  "class"  ) && val[  "class"  ] != "nodes.Node"))
      return false;

   return true;
}

std::string getTimes(const orderedJSON &value)
{
   const std::string times = "times"; // shorter, less easily misspelled
   const std::string occurrence = "occurrence"; // accept; used in GNDS specs

   // need exactly one - not neither, not both
   assert(value.contains(times) != value.contains(occurrence));

   return value.contains(times)
      ? value[times]
      : value[occurrence];
}

std::string sep(int &count, const int total)
{
   return ++count < total ? "," : "";
}


// -----------------------------------------------------------------------------
// name* functions
// -----------------------------------------------------------------------------

// nameGNDS
// Name in GNDS (e.g., name of an XML element)
std::string nameGNDS(const KeyValue &keyval)
{
   // As-is, directly as stipulated in a key in the JSON spec, except
   // that we allow a "name" entry to override the key.
   return keyval.value().contains("name")
      ? std::string(keyval.value()["name"])
      : keyval.key();
}

// nameField
// Name of a field (metadatum or child node) in an autogenerated class
std::string nameField(const KeyValue &keyval, const InfoSpecs &specs)
{
   // Like nameGNDS, except that we apply any name-modification map that
   // may have been provided. That can fix, for example, the name "double",
   // which appears in GNDS v1.9 but is unsuitable for a name in C++.
   const std::string name = nameGNDS(keyval);
   const auto it = specs.mapName.find(name);
   return it == specs.mapName.end() ? name : it->second;
}

// nameClass
// Name of an autogenerated class
std::string nameClass(const KeyValue &keyval, const InfoSpecs &specs)
{
   // Like nameField, but capitalized (per our class naming convention).
   return capital(nameField(keyval,specs));
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
std::string getFileNamespace(const orderedJSON &j)
{
   return j.contains("__namespace__")
      ? j["__namespace__"]
      : j[  "namespace"  ];
}

// Get the JSON's "type", with any relevant specs.mapMetaType entry applied
std::string getMetadatumType(const orderedJSON &j, const InfoSpecs &specs)
{
   const std::string type = j["type"];
   const auto it = specs.mapMetaType.find(type);
   return it == specs.mapMetaType.end() ? type : it->second;
}

// Determine to what namespace childClass belongs. Context: we're (1) in a JSON
// spec with namespace parent.nsname, (2) in a parent node named parent.clname,
// and (3) wish to determine the proper namespace for the parent's child node
// named childClass. Parameter j is the JSON value ({...}) for this child node.
std::string getChildNamespace(
   const orderedJSON &j, const InfoSpecs &specs,
   const PerClass &per, const std::string &childClass
) {
   // childClass' namespace...

   // ...is explicitly given by "__namespace__"or "namespace"
   if (j.contains("__namespace__")) return j["__namespace__"];
   if (j.contains(  "namespace"  )) return j[  "namespace"  ];

   // ...isn't given, and this child isn't in any of the JSONs :-(
   if (specs.class2nspace.count(childClass) == 0) {
      log::warning(
         "{}::{} has a child of unknown class {}",
         per.nsname, per.clname, childClass
      );
      return "unknownNamespace";
   }

   // ...isn't given, but we've seen the child in exactly *one* namespace
   if (specs.class2nspace.count(childClass) == 1)
      return specs.class2nspace.find(childClass)->second;

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...one of which is the parent's, which we'll assume is intended
   const auto range = specs.class2nspace.equal_range(childClass);
   for (auto it = range.first; it != range.second; ++it)
      if (it->second == per.nsname) {
         log::warning(
            "{}::{} has a child {} that appears in the present\n"
            "namespace but also in one or more other namespaces. We'll\n"
            "assume that the one in the present namespace is intended.\n"
            "If this is wrong, please provide a \"namespace\" entry.",
            per.nsname, per.clname, childClass
         );
         return per.nsname;
      }

   // ...isn't given, and we've seen the child in *multiple* namespaces,
   // ...none of which is the parent's; this is an ambiguous situation :-(
   std::stringstream warn;
   int count = 0;
   for (auto it = range.first; it != range.second; ++it)
      warn << (count++ == 0 ? "" : ", ") << it->second;
   log::warning(
      "{}::{} has a child of ambiguous class {}.\n"
      "Child class {} appears in all of the following namespaces:\n{}",
      per.nsname, per.clname, childClass, childClass, warn.str()
   );

   return "ambiguousNamespace";
}



// -----------------------------------------------------------------------------
// getClass* functions re: metadata, children, variant children
// -----------------------------------------------------------------------------

// getClassMetadata
void getClassMetadata(
   const orderedJSON &j, const InfoSpecs &specs, PerClass &per
) {
   for (const auto &field : j.items()) {
      const auto &metaRHS = field.value();

      // Name
      InfoMetadata m;
      m.name = nameField(field,specs);

      // Type
      m.type = getMetadatumType(metaRHS,specs);

      // Has default?
      m.defaultValue = "";
      if (metaRHS.contains("default") && !metaRHS["default"].is_null()) {
         m.defaultValue = stringify(metaRHS["default"]);
         const auto it = specs.mapMetaDefault.find(m.defaultValue);
         if (it != specs.mapMetaDefault.end())
            m.defaultValue = it->second;
      };
      if (m.defaultValue != "") {
         // If it has a default, then presumably it isn't required...
         // fixme Should print a real, useful error message here. The mistake
         // in question is something a user could easily make!! Look at other
         // assert()s in this file as well; assert should be more for internal
         // sanity checks than for diagnostic messages, as they aren't very
         // helpful to typical users.
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
   const orderedJSON &j, const InfoSpecs &specs,
   PerClass &per, Class2Dependencies &dep
) {
   for (const auto &field : j.items()) {
      const auto &elemRHS = field.value();

      // Choice children are handled elsewhere
      const std::string times = getTimes(elemRHS);
      if (times == "choice" || times == "choice+" || times == "choice2+")
         continue;

      // Name
      InfoChildren c;
      c.name = nameField(field,specs);

      // Type, excluding namespace
      c.plain = nameClass(field,specs);

      // Type, including namespace
      c.ns = getChildNamespace(elemRHS, specs, per, c.plain);
      c.type = c.ns + "::" + c.plain;

      // Optional?
      c.isOptional = !elemRHS["required"];
      const std::string optPrefix = c.isOptional ? "std::optional<" : "";
      const std::string optSuffix = c.isOptional ? ">" : "";

      // Vector?
      c.isVector = times == "0+" || times == "1+" || times == "2+";
      const std::string vecPrefix = c.isVector ? "std::vector<" : "";
      const std::string vecSuffix = c.isVector ? ">" : "";

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
      if (c.type != per.name())
         dep.dependencies.push_back(
            NamespaceAndClass(c.ns,nameClass(field,specs)));

      // Add to per.children
      per.children.push_back(c);
   }
} // getClassChildren


// getClassVariants
void getClassVariants(
   const orderedJSON &j, const InfoSpecs &specs,
   PerClass &per, Class2Dependencies &dep
) {
   // Initialize per.variants, a vector<InfoVariants> that has the "choice"
   // children from the current class. Computing a map<string,InfoVariants>,
   // first, turns out to be convenient, given the manner in which the choice
   // children appear in the JSON specifications: listed in a "flat" manner
   // as child nodes, rather than grouped one level deeper inside of, say,
   // a "choice" JSON key. Remark: this code supports the option of having
   // multiple sets of choices under the current parent; for example, the
   // parent can have {X or Y}, and (independently) have {A or B or C}. Our
   // JSON "variant" key facilitates this: give the same value for X and Y,
   // and the same value for A, B, and C. The GNDS v1.9 specifications only
   // appear to allow for one choice-between-things (just X,Y or just A,B,C)
   // in a given parent, but we believe our extension will prove to be useful.

   std::map<std::string,InfoVariants> map;

   // Pass 1
   // Collect "variant" names, and if ever it's absent, a to-be-determined
   // name for all choice children for which it's absent
   for (const auto &field : j.items()) {
      // Is it a choice child?
      const auto &elemRHS = field.value();
      const std::string times = getTimes(elemRHS);
      if (times != "choice" && times != "choice+" && times != "choice2+")
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
      const std::string times = getTimes(elemRHS);
      if (times != "choice" && times != "choice+" && times != "choice2+")
         continue;

      // Variant name
      const std::string variantName = elemRHS.contains("variant")
         ? elemRHS["variant"]
         : "";
      auto it = map.find(variantName);
      assert(it != map.end()); // should be there from the earlier loop

      // For the individual child that's part of a choice...
      InfoVariantsChildren c;
      // ...its name
      c.name = nameField(field,specs);
      // ...its type, excluding namespace
      c.plain = nameClass(field,specs);
      // ...its type, including namespace
      c.ns = getChildNamespace(elemRHS, specs, per, c.plain);
      c.type = c.ns + "::" + c.plain;
      // ...its vector-ness
      c.isVector = times == "choice+" || times == "choice2+";

      // The GNDS JSON specifications all have "required":false for individual
      // choices in a set of choices; the concept of "the entire choice can be
      // either required or optional" doesn't seem to exist. We could support
      // it, but for now, we'll just ensure that "required":false is followed.
      assert(!elemRHS["required"]);

      InfoVariants &v = it->second;
      v.isVector = c.isVector;
      v.children.push_back(c);

      // Save as a dependency (if it's not its own dependency)
      if (c.type != per.name())
         dep.dependencies.push_back(
            NamespaceAndClass(c.ns,nameClass(field,specs)));
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

   // recurse is used to prevent multiple reports of equivalent errors
   // as we step through the format string and arguments while printing.
   static int recurse;

   template<class T, class... Ts>
   void checkArgs(const std::string &str, const T &value, Ts &&...args)
   {
      if (recurse == 0) {
         using last = decltype(
            std::get<sizeof...(args)>(std::make_tuple(value,args...)));
         const std::size_t nsub = std::count(str.begin(),str.end(),substitute);
         // a bool last argument is not interpreted as an argument to print...
         const std::size_t narg =
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

   // char* cases are needed in addition to std::string, for disambiguation.
   // level is the indentation level.

   // operator()(string, newline)
   template<class T = bool, class = std::enable_if_t<std::is_same_v<T,bool>>>
   void operator()(const std::string &str = "", const T newline = true)
   {
      s << str;
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
   void operator()(
      const int level, const std::string &str = "", const bool newline = true
   ) {
      operator()(std::string(level*indent,' ') + str, newline);
   }

   void operator()(
      const int level, const char *const str, const bool newline = true
   ) {
      operator()(level, std::string(str), newline);
   }

   // operator()(string, value, args)
   template<
      class T, class... Ts,
      class = std::enable_if_t<!std::is_same_v<T,bool>>
   >
   void operator()(const std::string &str, const T &value, Ts &&...args)
   {
      checkArgs(str, value, std::forward<Ts>(args)...);
      recurse++;
      for (const auto &ch : str)
         if (ch != substitute)
            s << ch;
         else {
            s << value;
            operator()(std::string(&ch+1), std::forward<Ts>(args)...);
            break;
         }
      recurse--;
   }

   // operator()(level, string, value, args)
   template<
      class T, class... Ts,
      class = std::enable_if_t<!std::is_same_v<T,bool>>
   >
   void operator()(
      const int level, const std::string &str, const T &value, Ts &&...args
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
void writeClassPrefix(writer &out, const PerClass &per)
{
   // namespace
   out("namespace @ {", per.nsname);

   // comment introducing class
   out();
   out(largeComment);
   out("// @::", per.nsname);
   out("// class @", per.clname);
   out(largeComment);

   // class begin
   out();
   out("class @ : public Component<@::@@> {",
       // A namespace prefix in Component<> prevents possible ambiguities with
       // the Child<> object for the class that was brought in through key.hpp.
       // Normally the class name is capitalized while the Child<> object isn't,
       // but if the node name was already capitalized in the specs (an example
       // we encountered was "XYs1d"), then the Child<> key would reflect that.
       // Then, without the nsname:: here, we'd have an ambiguity.
       per.clname, per.nsname, per.clname,
       per.isData
          ? (",true" + (per.dataType == "" ? "" : "," + per.dataType))
          : ""
   );
   out(1,"friend class Component;");
} // writeClassPrefix


// writeClassForComponent
void writeClassForComponent(writer &out, const PerClass &per)
{
   // using [name for variant] = ...
   if (per.variants.size())
      out();
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0;
      const int total = v.children.size();
      for (const auto &c : v.children)
         out(2,"@@", c.type, sep(count,total));
      out(1,">;");
   }

   out();
   out(1,smallComment);
   out(1,"// For Component");
   out(1,smallComment);
   out();
   out(1,"// Names: this namespace, this class, a field/node of this type");
   out(1,"static auto NAMESPACE() { return \"@\"; }", per.nsname);
   out(1,"static auto CLASS() { return \"@\"; }", per.clname);
   out(1,"static auto FIELD() { return \"@\"; }", per.nameGNDS);

   // KEYS() begin
   out();
   out(1,"// Core Interface multi-query to extract metadata and child nodes");
   out(1,"static auto KEYS()");
   out(1,"{");

   // KEYS() contents
   int count = 0;
   const int total = per.nfields();
   if (total == 0)
      out(2,"return std::tuple<>{};");
   else {
      out(2,"return");

      // metadata
      if (per.metadata.size())
         out(3,"// metadata");
      for (const auto &m : per.metadata) {
         out(3,"@{@}", m.typeFull, initializer(m));
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
         int n = 0; // for alternatives; not to be confused w/count
         for (const auto &c : v.children)
            out("@Child<>(\"@\")", n++ == 0 ? "" : " || ", c.name, false);
         out(")@", ++count < total ? " |" : "");
      }

      out(2,";");
   }

   // KEYS() end
   out(1,"}");
   out();
   out("public:");
} // writeClassForComponent


// Class suffix
void writeClassSuffix(
   writer &out, const PerClass &per, const InfoSpecs &specs
) {
   // assignment
   out();
   out(1,smallComment);
   out(1,"// Assignment operators");
   out(1,smallComment);
   out();
   out(1,"@ &operator=(const @ &) = default;", per.clname, per.clname);
   out(1,"@ &operator=(@ &&) = default;", per.clname, per.clname);

   // customization #include
   out();
   out(1,smallComment);
   out(1,"// Custom functionality");
   out(1,smallComment);
   out();
   out(1,"#include \"@/@/@/@/src/custom.hpp\"",
       specs.Project, specs.Version, per.nsname, per.clname);

   // this *follows* the customization #include (because it might be used there)
   out(1,"#undef GNDSTK_COMPONENT");

   // class+namespace end
   out("}; // class @", per.clname);
   out();
   out("} // namespace @", per.nsname);
} // writeClassSuffix



// -----------------------------------------------------------------------------
// writeClass*
// For metadata, children, and variant children
// -----------------------------------------------------------------------------

// writeClassContentMetadata
void writeClassContentMetadata(writer &out, const PerClass &per)
{
   if (per.metadata.size()) {
      out();
      out(1,"// metadata");
   }

   for (const auto &m : per.metadata) {
      per.isData && (
      m.name == "length" || m.name == "start" || m.name == "valueType")
         ? out(1,"mutable Field<@> @{this", m.typeFull, m.name, false)
         : out(1,        "Field<@> @{this", m.typeFull, m.name, false);
      if (m.defaultValue != "")
         out(",defaults.@", m.name, false);
      out("};");
   }

}

// writeClassContentChildren
void writeClassContentChildren(writer &out, const PerClass &per)
{
   if (per.children.size()) {
      out();
      out(1,"// children");
   }
   for (const auto &c : per.children)
      out(1,"Field<@> @{this};", c.typeFull, c.name);
}

// writeClassContentVariants
void writeClassContentVariants(writer &out, const PerClass &per)
{
   if (per.variants.size()) {
      out();
      out(1,"// children - variant");
   }
   for (const auto &v : per.variants) {
      out(1,"Field<@> @{this};", v.typeFull, v.name);
      for (const auto &c : v.children) {
         out(1,"FieldPart<decltype(@),@> @{@};",
             v.name, c.type, c.name, v.name);
      }
   }
}



// -----------------------------------------------------------------------------
// writeClassCtor*
// -----------------------------------------------------------------------------

// writeClassCtorComponent
void writeClassCtorComponent(
   writer &out, const PerClass &per, const bool copyOrMove,
   const bool newline = true
) {
   out(2,"GNDSTK_COMPONENT(@)",
       std::string(copyOrMove ? "other.baseBlockData()" : "BlockData{}"),
       newline);
}


// writeClassCtorBody
void writeClassCtorBody(
   writer &out, const std::string &line, const std::string &argName
) {
   out(1,"{");
   if (line != "")
      out(2,line);
   out(2,"Component::finish(@);", argName);
   out(1,"}");
}


// writeClassCtors
void writeClassCtors(writer &out, const PerClass &per)
{
   // ------------------------
   // ctor: default,
   // and from fields
   // ------------------------

   const int total = per.nfields();
   out();

   if (total == 0) {
      out(1,"#define GNDSTK_COMPONENT(blockdata) Component(blockdata)");
      out();
      out(1,"// default");
      out(1,"@() :", per.clname);
      writeClassCtorComponent(out, per, false);
   } else {
      int count = 0;

      // macro
      out(1,"#define GNDSTK_COMPONENT(blockdata) Component(blockdata, \\");
      for (const auto &m : per.metadata)
         out(2,"this->@@", m.name, ++count < total ? ", \\" : ")");
      for (const auto &c : per.children)
         out(2,"this->@@", c.name, ++count < total ? ", \\" : ")");
      for (const auto &v : per.variants)
         out(2,"this->@@", v.name, ++count < total ? ", \\" : ")");

      // comment for this constructor
      out();
      out(1,"// default, and from fields");

      // informational message, if applicable
      for (const auto &m : per.metadata)
         if (m.isDefaulted) {
            out(1,"// std::optional replaces Defaulted; "
                "this class knows the default(s)");
            break;
         }

      // signature, and base constructor call
      count = 0;
      out(1,"explicit @(", per.clname);

      for (const auto &m : per.metadata)
         out(2,"const wrapper<@> &@ = {}@",
             m.isDefaulted ? "std::optional<" + m.type + ">" : m.typeFull,
             m.name, sep(count,total));
      for (const auto &c : per.children)
         out(2,"const wrapper<@> &@ = {}@",
             c.typeFull, c.name, sep(count,total));
      for (const auto &v : per.variants)
         out(2,"const wrapper<@> &@ = {}@",
             v.typeFull, v.name, sep(count,total));

      out(1,") :");
      writeClassCtorComponent(out, per, false, false);

      // initialize fields
      out(",");
      count = 0;
      for (const auto &m : per.metadata)
         if (m.isDefaulted)
            out(2,"@(this,defaults.@,@)@",
                m.name, m.name, m.name, sep(count,total));
         else
            out(2,"@(this,@)@", m.name, m.name, sep(count,total));
      for (const auto &c : per.children)
         out(2,"@(this,@)@", c.name, c.name, sep(count,total));
      for (const auto &v : per.variants)
         out(2,"@(this,@)@", v.name, v.name, sep(count,total));
   }

   // body
   writeClassCtorBody(out, "", "");

   // ------------------------
   // ctor: node
   // ------------------------

   out();
   out(1,"// from node");
   out(1,"explicit @(const Node &node) :", per.clname);
   writeClassCtorComponent(out, per, false);
   writeClassCtorBody(out, "", "node");

   // ------------------------
   // ctor: vector
   // ------------------------

   if (per.isData) {
      out();
      out(1,"// from vector");
      out(1,"template<class T, class = "
          "std::enable_if_t<BLOCKDATA::template supported<T>>>");
      out(1,"@(const std::vector<T> &vector) :", per.clname);
      writeClassCtorComponent(out, per, false);
      writeClassCtorBody(out, "", "vector");
   }

   // ------------------------
   // ctor: copy
   // ------------------------

   out();
   out(1,"// copy");
   out(1,"@(const @ &other) :", per.clname, per.clname);
   writeClassCtorComponent(out, per, true);
   writeClassCtorBody(out, "*this = other;", "other");

   // ------------------------
   // ctor: move
   // ------------------------

   out();
   out(1,"// move");
   out(1,"@(@ &&other) :", per.clname, per.clname);
   writeClassCtorComponent(out, per, true);
   writeClassCtorBody(out, "*this = std::move(other);", "other");
} // writeClassCtors



// -----------------------------------------------------------------------------
// writeClass
// -----------------------------------------------------------------------------

void writeClass(PerClass &per, const InfoSpecs &specs)
{
   // false: no "file was autogenerated" message, because in writeClass we're
   // writing certain class contents to a string, not writing an entire file.
   writer out(false);

   // output: class begin
   writeClassPrefix(out, per);

   // output: for the Component base
   writeClassForComponent(out, per);

   // output: using directives
   out(1,"using Component::construct;");
   if (per.isData)
      out(1,"using BlockData::operator=;");

   // output: defaults (applicable only to metadata)
   std::size_t ndefaults = 0;
   for (auto &m : per.metadata)
      if (m.isDefaulted)
         ++ndefaults;
   if (ndefaults > 0) {
      out();
      out(1,"// defaults");
      out(1,"static inline const struct Defaults {");
      for (auto &m : per.metadata)
         if (m.isDefaulted)
            out(2, "static inline const @ @ = @;",
                m.type, m.name, initializer(m));
      out(1,"} defaults;");
   }

   // output: fields
   writeClassContentMetadata(out, per);
   writeClassContentChildren(out, per);
   writeClassContentVariants(out, per);

   // output: constructors
   out();
   out(1,smallComment);
   out(1,"// Constructors");
   out(1,smallComment);
   writeClassCtors(out, per);

   // output: class end
   writeClassSuffix(out, per, specs);

   // done
   per.code = out.str();
} // writeClass



// -----------------------------------------------------------------------------
// Miscellaneous functions for getting JSON content
// -----------------------------------------------------------------------------

// readJSONFile
orderedJSON readJSONFile(const std::string &file, const bool print = false)
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

   orderedJSON j;
   ifs >> j;
   return j;
} // readJSONFile


// getMetadataJSON
template<bool required>
auto getMetadataJSON(const orderedJSON &j)
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
      return std::optional<orderedJSON>(
         meta ? j[metastr] : attr ? j[attrstr] : orderedJSON{});
   }
} // getMetadataJSON


// getChildrenJSON
template<bool required>
auto getChildrenJSON(const orderedJSON &j)
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
      return std::optional<orderedJSON>(
         chld ? j[chldstr] : node ? j[nodestr] : orderedJSON{});
   }
} // getChildrenJSON



// -----------------------------------------------------------------------------
// commandLine and its helper functions
// -----------------------------------------------------------------------------

// readChangesFile
void readChangesFile(const std::string &file, InfoSpecs &specs)
{
   const orderedJSON jchanges = readJSONFile(file);
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
   const orderedJSON &jfile = readJSONFile(file,true);

   for (const auto &item : jfile.items()) {
      const std::string parent = item.key();
      const orderedJSON rhs = item.value();
      if (!isClass(item))
         continue;

      const auto metadata = getMetadataJSON<true>(rhs);
      const auto children = getChildrenJSON<true>(rhs);
      const bool data = rhs.contains("data") && !rhs["data"].is_null();
      const bool body = rhs.contains("bodyText") && !rhs["bodyText"].is_null();

      if (metadata.size() == 0 && children.size() == 0 && !data && !body)
         log::info("Class \"{}\" has no metadata, children, or data", parent);
      if (metadata.size() == 0 && children.size() == 1)
         log::info("Class \"{}\" has no metadata and just one child", parent);
   }
} // printSingletons


// commandLine
// Gather information from the JSON file given on the command line
void commandLine(
   const int argc, const char *const *const argv,
   InfoSpecs &specs
) {
   // JSON keys we'll look for
   static const std::string path    = "Path";
   static const std::string project = "Project";
   static const std::string version = "Version";
   static const std::string input   = "JSONDir";
   static const std::string files   = "JSONFiles";
   static const std::string changes = "Changes";

   // Usage
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " file.json" << std::endl;
      exit(EXIT_FAILURE);
   }

   // Input file
   const orderedJSON jmain = readJSONFile(argv[1]);

   // Validate content
   if (!(jmain.contains(version) &&
         jmain.contains(input) &&
         jmain.contains(files))) {
      log::error("The input JSON file needs {}, {}, and {}",
                 version, input, files);
      throw std::exception{};
   }

   // Extract information from the command line JSON file
   specs.Path = jmain.contains(path) ? jmain[path] : ".";
   specs.Project = jmain.contains(project) ? jmain[project] : "GNDStk";
   specs.Version = jmain[version];
   specs.JSONDir = jmain[input];
   for (const auto &str : jmain[files])
      specs.JSONFiles.push_back(str);

   // Version, with underscores in place of periods
   specs.VersionUnderscore = replace(specs.Version, '.', '_');

   // Prepend the JSON file names with their directory
   for (std::string &file : specs.JSONFiles)
      file = specs.JSONDir + '/' + file;

   // File names
   {
      // For C++
      const std::string base =
         specs.Path + "/" + specs.Project + "/src/" + specs.Project + "/";
      specs.hppVersion = base + specs.Version + ".hpp";
      specs.hppKey     = base + specs.Version + "/key.hpp";
   }
   {
      // For the C interface
      const std::string base =
         specs.Path + "/" + specs.Project + "/c/src/";
      specs.hVersion = base + specs.Version + ".h";
      // We don't currently know of anything that we'd have in the following
      // file, so we won't create it. But I'll leave this in as a placeholder.
      specs.cVersion = base + specs.Version + ".cpp";
   }

   // Report on "singletons"
   if (singletons) {
      action("\nFinding possible simplifications...");
      for (const std::string &file : specs.JSONFiles)
         printSingletons(file);
      action("Done.");
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
   InfoSpecs &specs, const std::string &nsname, const KeyValue &keyval
) {
   // Ensure that this JSON entry represents a class - as opposed
   // to being, say, "namespace" or some other non-class entry.
   if (!isClass(keyval))
      return;

   // Get the class name, then link this class with the current namespace.
   // This information is used, later, for various purposes.
   const std::string clname = nameClass(keyval,specs);
   specs.class2nspace.insert(std::make_pair(clname,nsname));

   // ------------------------
   // Create directories and
   // custom files as needed
   // ------------------------

   // For the present namespace: C++, Python, and C directories. The present
   // namespace probably contains multiple classes, so these directories may
   // have been created already, but that's fine.
   const std::string nsdir   = specs.Path + "/" + specs.Project +
      "/src/" + specs.Project + "/" + specs.Version + "/" + nsname;
   const std::string nsdirpy = specs.Path + "/" + specs.Project +
      "/python/src/" + specs.Version + "/" + nsname;
   const std::string nsdirc  = specs.Path + "/" + specs.Project +
      "/c/src/" + specs.Version + "/" + nsname;

   // For the present class: C++ source and test directories.
   const std::string clsrc  = nsdir + "/" + clname + "/src";
   const std::string cltest = nsdir + "/" + clname + "/test";

   // Create the above directories, if (and only if) they don't already exist.
   system(("mkdir -p " + nsdir  ).data());
   system(("mkdir -p " + nsdirpy).data());
   system(("mkdir -p " + nsdirc ).data());
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

      writer out(custom,false); // false: no "file was autogenerated" message
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
   auto ns = specs.namespace2data.insert(std::make_pair(nsname,PerNamespace{}));
   ns.first->second.cppPython = nsdirpy + ".python.cpp";
   ns.first->second.nsname = nsname;

   // For this namespace::class:
   //    The cpp file for Python
   //    The hpp file for GNDStk
   //    The C/C++ header, and the C++ backend for the C interface
   auto cl = specs.class2data.insert(
      std::make_pair(NamespaceAndClass{nsname,clname}, PerClass{}));
   assert(cl.second); // should have been inserted - not there already
   cl.first->second.cppPython = nsdirpy + "/" + clname + ".python.cpp";
   cl.first->second.hppGNDStk = nsdir   + "/" + clname + ".hpp";
   cl.first->second.headerC   = nsdirc  + "/" + clname + "qqq.h";
   cl.first->second.sourceC   = nsdirc  + "/" + clname + "qqq.cpp";
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
   action("\nPreprocessing input files...");
   // files
   for (const std::string &file : specs.JSONFiles) {
      const orderedJSON jmain = readJSONFile(file,true);
      const std::string nsname = getFileNamespace(jmain);
      // classes in the file
      for (const auto &cl : jmain.items())
         preprocessClass(specs, nsname, cl);
   }
   action("Done.");
} // preprocessFiles



// -----------------------------------------------------------------------------
// validate*
// getClass
// getFiles
// -----------------------------------------------------------------------------

// Helper: validateMetadata
void validateMetadata(const orderedJSON &metadata)
{
   for (const auto &field : metadata.items()) {
      assert(field.value().contains("type"));
      assert(field.value().contains("required"));
   }
}


// Helper: validateChildren
void validateChildren(const orderedJSON &children)
{
   for (const auto &field : children.items()) {
      assert(field.value().contains("required"));

      // Consistency check: certain occurrence values imply *not* required.
      // Remark: the GNDS manual speaks of "choice2" and "choice2+" options
      // for occurrence. We're not sure if those will remain in future GNDS
      // specifications, so we won't worry now about how they might fit in.
      const std::string times = getTimes(field.value());
      if (times == "0+" || times == "choice" || times == "choice+")
         assert(!field.value()["required"]); // not required
   }
}


// getClass
void getClass(
   InfoSpecs &specs, const std::string &nsname, const KeyValue &keyval
) {
   const auto &classRHS = keyval.value();
   if (!isClass(keyval))
      return;
   const std::string clname = nameClass(keyval,specs);

   // find in class map
   const auto it = specs.class2data.find(NamespaceAndClass(nsname,clname));
   assert(it != specs.class2data.end());
   PerClass &per = it->second;

   // collect dependencies, for the present class, as this function proceeds
   Class2Dependencies dep;
   dep.theClass = NamespaceAndClass(nsname,clname);

   // names
   per.nsname = nsname;
   per.clname = clname;
   per.nameGNDS = nameGNDS(keyval);

   // metadata/children information
   const orderedJSON attrs = getMetadataJSON<true>(classRHS);
   const orderedJSON elems = getChildrenJSON<true>(classRHS);
   validateMetadata(attrs);
   validateChildren(elems);
   getClassMetadata(attrs, specs, per);
   getClassChildren(elems, specs, per, dep);
   getClassVariants(elems, specs, per, dep);

   // data-node information
   static const std::string datastr = "data";
   static const std::string bodystr = "bodyText";
   const bool data = classRHS.contains(datastr) && !classRHS[datastr].is_null();
   const bool body = classRHS.contains(bodystr) && !classRHS[bodystr].is_null();
   assert(!(data && body)); // not both
   per.isData = data || body;
   if (data) {
      // A type change, as with metadata, could be wanted in this context as
      // well. Perhaps the name "mapMetaType" (and the location and name for
      // it in the changes.json file) should be modified to reflect this
      const std::string type = classRHS[datastr];
      const auto it = specs.mapMetaType.find(type);
      per.dataType = it == specs.mapMetaType.end() ? type : it->second;
   } else
      per.dataType = "";

   // per.code will contain printed C++ code for the class itself
   writeClass(per,specs);

   // save dependencies
   specs.ClassDependenciesRaw.push_back(dep);
} // getClass


// getFiles
void getFiles(InfoSpecs &specs)
{
   action("\nCreating classes...");
   // files
   for (const std::string &file : specs.JSONFiles) {
      const orderedJSON jmain = readJSONFile(file,true);
      const std::string nsname = getFileNamespace(jmain);
      // classes in the file
      for (const auto &cl : jmain.items())
         getClass(specs, nsname, cl);
   }
   action("Done.");
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
      vecSource.begin(), vecSource.end(),
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
// Re: C++ header files
// fileGNDStkVersion
// fileGNDStkKey
// fileGNDStkClass
// -----------------------------------------------------------------------------

// ------------------------
// fileGNDStkVersion
// ------------------------

void fileGNDStkVersion(const InfoSpecs &specs)
{
   // ------------------------
   // Create a C++ header
   // for this version
   // ------------------------

   {
      writer out(specs.hppVersion);
      out();
      out("#ifndef @_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));
      out("#define @_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));

      std::string nsname_last = "";
      for (auto &c : specs.class2data) {
         const std::string nsname = c.first.nsname;
         const std::string clname = c.first.clname;
         if (nsname != nsname_last)
            out();
         nsname_last = nsname;
         out("#include \"@/@/@/@.hpp\"",
             specs.Project, specs.Version, nsname, clname);
      }

      out();
      out("#endif");
   }

   // ------------------------
   // Create a C/C++ header
   // for the C interface
   // ------------------------

   {
      writer out(specs.hVersion);
      out();
      out(largeComment);
      out("// This header file is designed to work with both C and C++");
      out(largeComment);
      out();
      out("#ifndef C_INTERFACE_@_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));
      out("#define C_INTERFACE_@_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));

      out();
      out("#include \"GNDStk.h\"");
      out();
      out("#ifdef __cplusplus");
      out(1,"// For C++");
      out(1,"#include \"@/@.hpp\"", specs.Project, specs.VersionUnderscore);
      out("#endif");

      std::string nsname_last = "";
      for (auto &c : specs.class2data) {
         const std::string nsname = c.first.nsname;
         const std::string clname = c.first.clname;
         if (nsname != nsname_last)
            out();
         nsname_last = nsname;
         out("#include \"@/@/@.h\"", specs.Version, nsname, clname);
      }

      out();
      out("#endif");
   }
} // fileGNDStkVersion


// ------------------------
// fileGNDStkKey
// ------------------------

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
      const orderedJSON jmain = readJSONFile(file);
      auto it = namespace2children.insert(
         std::make_pair(getFileNamespace(jmain),std::set<pair>{}));

      for (const auto &node : jmain.items()) {
         if (isClass(node)) {
            // nodes ==> children
            it->second.insert(std::make_pair(
               nameField(node,specs),
               nameGNDS (node)));

            // attributes ==> metadata
            const auto attrs = getMetadataJSON<true>(node.value());
            for (const auto &attr : attrs.items())
               metadata.insert(std::make_pair(
                  nameField(attr,specs),
                  nameGNDS (attr)));
         }
      }
   }

   // ------------------------
   // comment, macro guard,
   // outer namespaces
   // ------------------------

   writer out(specs.hppKey);
   out();
   out("#ifndef @_@_KEY",
       allcaps(specs.Project), allcaps(specs.VersionUnderscore));
   out("#define @_@_KEY",
       allcaps(specs.Project), allcaps(specs.VersionUnderscore));
   out();
   out("// GNDStk Core Interface");
   out("#include \"GNDStk.hpp\"");
   out();
   if (specs.Project == "GNDStk") // <== use namespace njoy only for this
      out("namespace njoy {");
   out("namespace @ {", specs.Project);
   out("namespace @ {", specs.VersionUnderscore);
   out();
   out("using namespace njoy::GNDStk;");

   // ------------------------
   // Meta<> objects
   // ------------------------

   out();
   out();
   out(largeComment);
   out("// meta::");
   out(largeComment);
   out();
   out("namespace meta {");

   if (metadata.size() > 0) {
      out();
      out(0,"#define GNDSTK_MAKE_LOOKUP(nameField,nameGNDS) \\");
      out(1,   "inline const auto nameField = makeLookup( \\");
      out(2,      "[](const auto &obj) -> decltype(obj.nameField()) \\");
      out(2,      "{ return obj.nameField(); }, \\");
      out(2,      "#nameGNDS \\");
      out(1,   ")");
      out(0, "// nameField vs. nameGNDS: for, e.g., Double vs. double in GNDS");
      out();
      for (const auto &meta : metadata)
         out("GNDSTK_MAKE_LOOKUP(@,@);", meta.first, meta.second);
      out();
      out(0,"#undef GNDSTK_MAKE_LOOKUP");
      out();
   }

   out("} // namespace meta");

   // ------------------------
   // Child<> objects
   // ------------------------

   for (const auto &nspace : namespace2children) {
      out();
      out();
      out(largeComment);
      out("// @::child::", nspace.first);
      out(largeComment);
      out();
      out("namespace @ {", nspace.first);
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
      out("} // namespace @", nspace.first);
   }

   // ------------------------
   // Using directives
   // ------------------------

   out();
   out();
   out(largeComment);
   out("// For convenience: using directives");
   out(largeComment);
   out();
   out("namespace key {");
   out(1,"using namespace meta;");
   for (const auto &nspace : namespace2children)
      out(1,"using namespace @::child;", nspace.first);
   out("} // namespace key");
   out();
   out("using namespace key;");
   for (const auto &nspace : namespace2children)
      out("using namespace @;", nspace.first);

   // ------------------------
   // finish
   // ------------------------

   out();
   out();
   out(largeComment);
   out(largeComment);
   out();
   out("} // namespace @", specs.VersionUnderscore);
   out("} // namespace @", specs.Project);
   if (specs.Project == "GNDStk") // <== end namespace njoy only for this
      out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkKey


// ------------------------
// fileGNDStkClass
// ------------------------

void fileGNDStkClass(
   const InfoSpecs &specs, const PerClass &per, const Class2Dependencies &c2d
) {
   // class-specific hpp file
   writer out(per.hppGNDStk);
   const std::string guard =
      allcaps(specs.Project) + "_" +
      allcaps(specs.VersionUnderscore) + "_" +
      allcaps(per.nsname) + "_" +
      allcaps(per.clname);

   out();
   out("#ifndef @", guard);
   out("#define @", guard);

   out();
   if (c2d.dependencies.size() == 0) // <== otherwise, comes in through deps
      out("#include \"@/@/key.hpp\"", specs.Project, specs.Version);
   for (const auto &dep : c2d.dependencies)
      out("#include \"@/@/@/@.hpp\"",
          specs.Project, specs.Version, dep.nsname, dep.clname);

   out();
   if (specs.Project == "GNDStk")
      out("namespace njoy {");
   out("namespace @ {", specs.Project);
   out("namespace @ {", specs.VersionUnderscore);
   out(per.code,false);
   out("} // namespace @", specs.VersionUnderscore);
   out("} // namespace @", specs.Project);
   if (specs.Project == "GNDStk")
      out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkClass



// -----------------------------------------------------------------------------
// Re: C interface
// Helpers
// fileCInterface*
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

// two
// Forward args to two places: header and source
template<class... Ts>
void two(writer &hdr, writer &src, Ts &&...args)
{
   hdr(std::forward<Ts>(args)...);
   src(std::forward<Ts>(args)...);
}

// par
// For writing parameters; no \n added
template<class... Ts>
void par(writer &hdr, writer &src, Ts &&...args)
{
   two(hdr, src, std::forward<Ts>(args)..., false);
}

// ext
// For writing (or not writing) 'extern "C"'
template<class... Ts>
void ext(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("extern_c "+str, std::forward<Ts>(args)...);
   src(            str, std::forward<Ts>(args)...);
}

// ppp
// Comment, prefixed in header file with "+++"
template<class... Ts>
void ppp(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("// +++ "+str, std::forward<Ts>(args)...);
   src("// "    +str, std::forward<Ts>(args)...);
}

// mmm
// Comment, prefixed in header file with "---"
template<class... Ts>
void mmm(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("// --- "+str, std::forward<Ts>(args)...);
   src("// "    +str, std::forward<Ts>(args)...);
}

// fun
// C interface function name, and left (, with no \n added
template<class... Ts>
void fun(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   two(hdr, src, str+"(", std::forward<Ts>(args)..., false);
}

// sig
// End C interface function signature; style dependent on hadFields bool
void sig(writer &hdr, writer &src, const bool hadFields = false)
{
   // header: end of parameters, semicolon for declaration
   hdr(");");
   // source: end of parameters, beginning of body for definition
   src(hadFields ? ") {" : ")\n{");
}

// def
// End C interface function definition.
// Accept writer &hdr for consistency with above/below functions.
void def(writer &hdr, writer &src)
{
   // header: nothing
   (void)hdr;
   // source: ending of body for definition
   src("}");
}

// mtype_param
// Get metadata type, for C interface
std::string mtype_param(const InfoMetadata &m)
{
   if (m.type == "std::string")
      return "char *const";
   else
      return m.type;
}

// mtype_return
// Get metadata type, for C interface
std::string mtype_return(const InfoMetadata &m)
{
   if (m.type == "std::string")
      return "const char *";
   else
      return m.type;
}

// ctype
// Get child-node type, for C interface
std::string ctype(const InfoChildren &c)
{
   if (c.isVector)
      return "ConstHandle2Const" + c.plain + " *const";
   else
      return "ConstHandle2Const" + c.plain;
}

// fileCInterfaceCreateParams
void fileCInterfaceCreateParams(writer &hdr, writer &src, const PerClass &per)
{
   int count = 0;
   const int total = per.nfields();

   // metadata
   for (const auto &m : per.metadata) {
      two(hdr,src);
      two(hdr,src,1,"const @ @@",
          mtype_param(m), m.name, ++count < total ? "," : "", false);
   }

   // children
   for (const auto &c : per.children) {
      two(hdr,src);
      two(hdr,src,1,"@ @@@",
          ctype(c),
          c.name,
          c.isVector ? ", const size_t "+c.name+"Size" : "",
          ++count < total ? "," : "",
          false
      );
   }

   // variants
   // todo

   if (total)
      two(hdr,src);
}

// ------------------------
// fileCInterfaceBasics
// ------------------------

void fileCInterfaceBasics(writer &hdr, writer &src, const PerClass &per)
{
   // ------------------------
   // section comment
   // ------------------------

   two(hdr,src);
   two(hdr,src);
   two(hdr,src,largeComment);
   two(hdr,src,"// Basics");
   two(hdr,src,"// Create, Assign, Delete");
   two(hdr,src,largeComment);

   // ------------------------
   // create: default, const
   // ------------------------

   two(hdr,src);
   mmm(hdr,src,"Create: default, const");
   ext(hdr,src,"Handle2Const@", per.clname);
   fun(hdr,src,"@DefaultConst", per.clname);
   sig(hdr,src);
   src(1,"return detail::createHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"DefaultConst\");");
   def(hdr,src);

   // ------------------------
   // create: default, non-const
   // ------------------------

   two(hdr,src);
   ppp(hdr,src,"Create: default");
   ext(hdr,src,"Handle2@", per.clname);
   fun(hdr,src,"@Default", per.clname);
   sig(hdr,src);
   src(1,"return detail::createHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Default\");");
   def(hdr,src);

   /// factor commonality in the next two blocks

   // ------------------------
   // create: general, const
   // ------------------------

   two(hdr,src);
   mmm(hdr,src,"Create: general, const");
   ext(hdr,src,"Handle2Const@", per.clname);
   fun(hdr,src,"@CreateConst", per.clname);
   fileCInterfaceCreateParams(hdr,src,per);
   sig(hdr,src, per.nfields() != 0);
   src(1,"ConstHandle2@ handle = detail::createHandle<CPP,C>(", per.clname);
   src(2,"CLASSNAME, CLASSNAME+\"CreateConst\"", false);
   {
      // metadata
      for (const auto &m : per.metadata) {
         src(",");
         src(2,"@", m.name, false);
      }

      // children
      for (const auto &c : per.children) {
         src(",");
         const std::string Child = c.plain;
         const std::string child = c.name;
         c.isVector
          ? src(2,"std::vector<CPP@>{}", Child, false)
          : src(2,"detail::tocpp<CPP@>{@}", Child, child, false);
      }

      // variants
      // todo
   }
   src();
   src(1,");");
   for (const auto &c : per.children)
      if (c.isVector) {
         const std::string Child = c.plain;
         const std::string child = c.name;
         src(1,"for (size_t @N = 0; @N < @Size; ++@N)",
             Child, Child, child, Child);
         src(2,"Element@Add(handle, @[@N]);",
             Child, child, Child);
      }
   src(1,"return handle;");
   def(hdr,src);

   // ------------------------
   // create: general, non-const
   // ------------------------

   two(hdr,src);
   ppp(hdr,src,"Create: general");
   ext(hdr,src,"Handle2@", per.clname);
   fun(hdr,src,"@Create", per.clname);
   fileCInterfaceCreateParams(hdr,src,per);
   sig(hdr,src, per.nfields() != 0);
   src(1,"ConstHandle2@ handle = detail::createHandle<CPP,C>(", per.clname);
   src(2,"CLASSNAME, CLASSNAME+\"Create\"", false);
   {
      // metadata
      for (const auto &m : per.metadata) {
         src(",");
         src(2,"@", m.name, false);
      }

      // children
      for (const auto &c : per.children) {
         src(",");
         const std::string Child = c.plain;
         const std::string child = c.name;
         c.isVector
          ? src(2,"std::vector<CPP@>{}", Child, false)
          : src(2,"detail::tocpp<CPP@>{@}", Child, child, false);
      }

      // variants
      // todo
   }
   src();
   src(1,");");
   for (const auto &c : per.children)
      if (c.isVector) {
         const std::string Child = c.plain;
         const std::string child = c.name;
         src(1,"for (size_t @N = 0; @N < @Size; ++@N)",
             Child, Child, child, Child);
         src(2,"Element@Add(handle, @[@N]);",
             Child, child, Child);
      }
   src(1,"return handle;");
   def(hdr,src);

   // ------------------------
   // assign
   // ------------------------

   two(hdr,src);
   ppp(hdr,src,"Assign");
   ppp(hdr,src,"Use this to assign one handled object to another. Don't assign handles,");
   ppp(hdr,src,"as with to = from. That has a meaning that you probably don't intend.");
   ext(hdr,src,"void");
   fun(hdr,src,"@Assign", per.clname);
   par(hdr,src,"ConstHandle2@ This, ConstHandle2Const@ from", per.clname, per.clname);
   sig(hdr,src);
   src(1,"detail::assignHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Assign\", This, from);");
   def(hdr,src);

   // ------------------------
   // delete
   // ------------------------

   two(hdr,src);
   ppp(hdr,src,"Delete");
   ppp(hdr,src,"We'll attempt to remove no-longer-used objects automatically, but you");
   ppp(hdr,src,"may improve performance if you delete them when you're done with them.");
   ext(hdr,src,"void");
   fun(hdr,src,"@Delete", per.clname);
   par(hdr,src,"ConstHandle2Const@ This", per.clname);
   sig(hdr,src);
   src(1,"detail::deleteHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Delete\", This);");
   def(hdr,src);

} // fileCInterfaceBasics


// ------------------------
// fileCInterfaceIO
// ------------------------

void fileCInterfaceIO(writer &hdr, writer &src, const PerClass &per)
{
   // section comment
   two(hdr,src);
   two(hdr,src);
   two(hdr,src,largeComment);
   two(hdr,src,"// I/O");
   two(hdr,src,"// Read, Write, Print");
   two(hdr,src,"// Each returns 0 if failure, 1 if success.");
   two(hdr,src,largeComment);

   // read from file
   two(hdr,src);
   ppp(hdr,src,"Read from file");
   ppp(hdr,src,"File can be XML, JSON, or HDF5.");
   ppp(hdr,src,"We'll examine the file's contents to determine its type automatically.");
   ext(hdr,src,"int");
   fun(hdr,src,"@Read", per.clname);
   par(hdr,src,"ConstHandle2@ This, const char *const filename", per.clname);
   sig(hdr,src);
   src(1,"return detail::readHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Read\", This, filename);");
   def(hdr,src);

   // write to file
   two(hdr,src);
   ppp(hdr,src,"Write to file");
   ppp(hdr,src,"File can be XML, JSON, or HDF5.");
   ppp(hdr,src,"We'll use filename's extension to determine the type you want written.");
   ext(hdr,src,"int");
   fun(hdr,src,"@Write", per.clname);
   par(hdr,src,"ConstHandle2Const@ This, const char *const filename", per.clname);
   sig(hdr,src);
   src(1,"return detail::writeHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Write\", This, filename);");
   def(hdr,src);

   // print
   two(hdr,src);
   ppp(hdr,src,"Print to standard output, in our prettyprinting format");
   ext(hdr,src,"int");
   fun(hdr,src,"@Print", per.clname);
   par(hdr,src,"ConstHandle2Const@ This", per.clname);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Print\", This);");
   def(hdr,src);

   // print, XML
   two(hdr,src);
   ppp(hdr,src,"Print to standard output, as XML");
   ext(hdr,src,"int");
   fun(hdr,src,"@PrintXML", per.clname);
   par(hdr,src,"ConstHandle2Const@ This", per.clname);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"PrintXML\", This, \"XML\");");
   def(hdr,src);

   // print, JSON
   two(hdr,src);
   ppp(hdr,src,"Print to standard output, as JSON");
   ext(hdr,src,"int");
   fun(hdr,src,"@PrintJSON", per.clname);
   par(hdr,src,"ConstHandle2Const@ This", per.clname);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"PrintJSON\", This, \"JSON\");");
   def(hdr,src);

} // fileCInterfaceIO


// ------------------------
// fileCInterfaceVector
// ------------------------

void fileCInterfaceVector(
   writer &hdr, writer &src,
   const PerClass &per, const std::string &type,
   const bool section = true
) {
   // section comment
   if (section) {
      two(hdr,src);
      two(hdr,src);
      two(hdr,src,largeComment);
      two(hdr,src,"// Re: vector");
      two(hdr,src,largeComment);
   } else {
      assert(type != "");
      two(hdr,src);
      two(hdr,src,smallComment);
      two(hdr,src,"// @", type);
      two(hdr,src,smallComment);
   }

   // dynamic type?
   if (type == "") {
      // todo Any others here, for purposes of the C interface?
      fileCInterfaceVector(hdr,src,per,"int",     false);
      fileCInterfaceVector(hdr,src,per,"unsigned",false);
      fileCInterfaceVector(hdr,src,per,"float",   false);
      fileCInterfaceVector(hdr,src,per,"double",  false);
      return;
   }

   // Example:
   //    ctype: "Foobar" (class type; for brevity)
   //    type:  "double" (parameter to this function)
   //    types: "doubles"
   //    Types: "Doubles"
   const std::string cname = per.clname;
   const std::string types = type + 's';
   const std::string Types = capital(type) + 's';

   two(hdr,src);
   ppp(hdr,src,"Clear");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Clear", cname, Types);
   par(hdr,src,"ConstHandle2@ This", cname);
   sig(hdr,src);
   src(1,"detail::vectorClear<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Clear\", This);", Types);
   def(hdr,src);

   two(hdr,src);
   ppp(hdr,src,"Get size");
   ext(hdr,src,"size_t");
   fun(hdr,src,"@@Size", cname, Types);
   par(hdr,src,"ConstHandle2Const@ This", cname);
   sig(hdr,src);
   src(1,"return detail::vectorSize<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Size\", This);", Types);
   def(hdr,src);

   two(hdr,src);
   ppp(hdr,src,"Get value");
   ppp(hdr,src,"By index \\in [0,size)");
   ext(hdr,src,"@", type);
   fun(hdr,src,"@@Get", cname, Types);
   par(hdr,src,"ConstHandle2Const@ This, const size_t index", cname);
   sig(hdr,src);
   src(1,"return detail::vectorGet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", This, index);", Types);
   def(hdr,src);

   two(hdr,src);
   ppp(hdr,src,"Set value");
   ppp(hdr,src,"By index \\in [0,size)");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Set", cname, Types);
   par(hdr,src,"ConstHandle2@ This, const size_t index, const @ value", cname, type);
   sig(hdr,src);
   src(1,"detail::vectorSet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", This, index, value);", Types);
   def(hdr,src);

   two(hdr,src);
   mmm(hdr,src,"Get pointer to existing values, const");
   ext(hdr,src,"const @ *", type);
   fun(hdr,src,"@@GetArrayConst", cname, Types);
   par(hdr,src,"ConstHandle2Const@ This", cname);
   sig(hdr,src);
   src(1,"return detail::vectorGet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@GetArrayConst\", This);", Types);
   def(hdr,src);

   two(hdr,src);
   ppp(hdr,src,"Get pointer to existing values, non-const");
   ext(hdr,src,"@ *", type);
   fun(hdr,src,"@@GetArray", cname, Types);
   par(hdr,src,"ConstHandle2@ This", cname);
   sig(hdr,src);
   src(1,"return detail::vectorGet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@GetArray\", This);", Types);
   def(hdr,src);

   two(hdr,src);
   ppp(hdr,src,"Set completely new values and size");
   ext(hdr,src,"void");
   fun(hdr,src,"@@SetArray", cname, Types);
   par(hdr,src,"ConstHandle2@ This, const @ *const values, const size_t size", cname, type);
   sig(hdr,src);
   src(1,"return detail::vectorSet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@SetArray\", This, size, values);", Types);
   def(hdr,src);

} // fileCInterfaceVector


// ------------------------
// fileCInterfaceMeta
// ------------------------

void fileCInterfaceMeta(
   writer &hdr, writer &src,
   const PerClass &per, const InfoMetadata &m
) {
   const std::string Class = per.clname;
   const std::string Meta  = UpperCamel(m.name);
   const std::string meta  = m.name;

   // section comment
   two(hdr,src);
   two(hdr,src);
   two(hdr,src,largeComment);
   two(hdr,src,"// Re: @", meta);
   two(hdr,src,largeComment);

   // has
   if (m.isOptional) {
      two(hdr,src);
      ppp(hdr,src,"Has");
      ext(hdr,src,"int");
      fun(hdr,src,"@@Has", Class, Meta);
      par(hdr,src,"ConstHandle2Const@ This", Class);
      sig(hdr,src);
      src(1,"return detail::hasMetadatum<CPP>");
      src(2,"(CLASSNAME, CLASSNAME+\"@Has\", This, extract::@);", Meta, meta);
      def(hdr,src);
   }

   // get
   two(hdr,src);
   ppp(hdr,src,"Get");
   ppp(hdr,src,"Returns by value");
   ext(hdr,src,"@", mtype_return(m));
   fun(hdr,src,"@@Get", Class, Meta);
   par(hdr,src,"ConstHandle2Const@ This", Class);
   sig(hdr,src);
   src(1,"return detail::getMetadatum<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", This, extract::@);", Meta, meta);
   def(hdr,src);

   // set
   two(hdr,src);
   ppp(hdr,src,"Set");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Set", Class, Meta);
   par(hdr,src,"ConstHandle2@ This, ", Class);
   par(hdr,src,"const @ @", mtype_param(m), meta);
   sig(hdr,src);
   src(1,"detail::setMetadatum<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", This, extract::@, @);", Meta, meta, meta);
   def(hdr,src);
}


// ------------------------
// fileCInterfaceChild
// ------------------------

void fileCInterfaceChild(
   writer &hdr, writer &src,
   const InfoSpecs &specs,
   const PerClass &per, const InfoChildren &c
) {
   const std::string Class = per.clname;
   const std::string Child = c.plain;
   const std::string child = c.name;

   // section comment
   two(hdr,src);
   two(hdr,src);
   two(hdr,src,largeComment);
   two(hdr,src,"// Re: @", child);
   two(hdr,src,largeComment);

   // has
   ///if (c.isOptional) {///eventually
   two(hdr,src);
   ppp(hdr,src,"Has");
   ext(hdr,src,"int");
   fun(hdr,src,"@@Has", Class, Child);
   par(hdr,src,"ConstHandle2Const@ This", Class);
   sig(hdr,src);
   src(1,"return detail::hasMetadatum<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Has\", This, extract::@);", Child, child);
   def(hdr,src);
   ///}///eventually

   // ------------------------
   // scalar case
   // ------------------------

   if (!c.isVector) {
      // get, const
      two(hdr,src);
      mmm(hdr,src,"Get, const");
      ext(hdr,src,"Handle2Const@", Child);
      fun(hdr,src,"@@GetConst", Class, Child);
      par(hdr,src,"ConstHandle2Const@ This", Class);
      sig(hdr,src);
      src(1,"return detail::getMetadatum<CPP,Handle2Const@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetConst\", This, extract::@);", Child, child);
      def(hdr,src);

      // get, non-const
      two(hdr,src);
      ppp(hdr,src,"Get, non-const");
      ext(hdr,src,"Handle2@", Child);
      fun(hdr,src,"@@Get", Class, Child);
      par(hdr,src,"ConstHandle2@ This", Class);
      sig(hdr,src);
      src(1,"return detail::getMetadatum<CPP,Handle2@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@Get\", This, extract::@);", Child, child);
      def(hdr,src);

      // set
      two(hdr,src);
      ppp(hdr,src,"Set");
      ext(hdr,src,"void");
      fun(hdr,src,"@@Set", Class, Child);
      par(hdr,src,"ConstHandle2@ This, ConstHandle2Const@ @", Class, Child, child);
      sig(hdr,src);
      src(1,"detail::setMetadatum<CPP,CPP@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@Set\", This, extract::@, @);", Child, child, child);
      def(hdr,src);

      return;
   }

   // ------------------------
   // vector case
   // ------------------------

   // clear
   two(hdr,src);
   ppp(hdr,src,"Clear");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Clear", Class, Child);
   par(hdr,src,"ConstHandle2@ This", Class);
   sig(hdr,src);
   src(1,"detail::clearContainer<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Clear\", This, extract::@);", Child, child);
   def(hdr,src);

   // size
   two(hdr,src);
   ppp(hdr,src,"Size");
   ext(hdr,src,"size_t");
   fun(hdr,src,"@@Size", Class, Child);
   par(hdr,src,"ConstHandle2Const@ This", Class);
   sig(hdr,src);
   src(1,"return detail::sizeOfContainer<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Size\", This, extract::@);", Child, child);
   def(hdr,src);

   // add
   two(hdr,src);
   ppp(hdr,src,"Add");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Add", Class, Child);
   par(hdr,src,"ConstHandle2@ This, ", Class);
   par(hdr,src,"ConstHandle2Const@ @", Child, child);
   sig(hdr,src);
   src(1,"detail::addToContainer<CPP,CPP@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Add\", This, extract::@, @);", Child, child, child);
   def(hdr,src);

   // get, by index, const
   two(hdr,src);
   mmm(hdr,src,"Get, by index \\in [0,size), const");
   ext(hdr,src,"Handle2Const@", Child);
   fun(hdr,src,"@@GetConst", Class, Child);
   par(hdr,src,"ConstHandle2Const@ This, ", Class);
   par(hdr,src,"const size_t index_");
   sig(hdr,src);
   src(1,"return detail::getByIndex<CPP,Handle2Const@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@GetConst\", This, extract::@, index_);", Child, child);
   def(hdr,src);

   // get, by index, non-const
   two(hdr,src);
   ppp(hdr,src,"Get, by index \\in [0,size), non-const");
   ext(hdr,src,"Handle2@", Child);
   fun(hdr,src,"@@Get", Class, Child);
   par(hdr,src,"ConstHandle2@ This, ", Class);
   par(hdr,src,"const size_t index_");
   sig(hdr,src);
   src(1,"return detail::getByIndex<CPP,Handle2@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", This, extract::@, index_);", Child, child);
   def(hdr,src);

   // set, by index
   two(hdr,src);
   ppp(hdr,src,"Set, by index \\in [0,size)");
   ext(hdr,src,"void");
   fun(hdr,src,"@@Set", Class, Child);
   par(hdr,src);
   par(hdr,src,1,"ConstHandle2@ This,", Class);
   par(hdr,src);
   par(hdr,src,1,"const size_t index_,");
   par(hdr,src);
   par(hdr,src,1,"ConstHandle2Const@ @", Child, child);
   par(hdr,src);
   sig(hdr,src,true);
   src(1,"detail::setByIndex<CPP,CPP@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", This, extract::@, index_, @);", Child, child, child);
   def(hdr,src);

   for (const auto &c : per.children) {
      const auto it = specs.class2data.find(NamespaceAndClass(c.ns,c.plain));
      assert(it != specs.class2data.end());

      for (const auto &m : it->second.metadata) {
         const std::string Meta = UpperCamel(m.name);
         const std::string meta = m.name;

         // has, by metadatum
         two(hdr,src);
         ppp(hdr,src,"Has, by @", meta);
         ext(hdr,src,"@", m.type);
         fun(hdr,src,"@@HasBy@", Class, Child, Meta);
         par(hdr,src);
         par(hdr,src,1,"ConstHandle2Const@ This,", Class);
         par(hdr,src);
         par(hdr,src,1,"const @ @", m.type, meta);
         par(hdr,src);
         sig(hdr,src,true);
         src(1,"return detail::hasByMetadatum<CPP>");
         src(2,"(CLASSNAME, CLASSNAME+\"@HasBy@\",", Child, Meta);
         src(2," This, extract::@, meta::@, @);", child, meta, meta);
         def(hdr,src);

         // get, by metadatum, const
         two(hdr,src);
         mmm(hdr,src,"Get, by @, const", meta);
         ext(hdr,src,"Handle2Const@", Child);
         fun(hdr,src,"@@GetBy@Const", Class, Child, Meta);
         par(hdr,src);
         par(hdr,src,1,"ConstHandle2Const@ This,", Class);
         par(hdr,src);
         par(hdr,src,1,"const @ @", m.type, meta);
         par(hdr,src);
         sig(hdr,src,true);
         src(1,"return detail::getByMetadatum<CPP,Handle2Const@>", Child);
         src(2,"(CLASSNAME, CLASSNAME+\"@GetBy@Const\",", Child, Meta);
         src(2," This, extract::@, meta::@, @);", child, meta, meta);
         def(hdr,src);

         // get, by metadatum, non-const
         two(hdr,src);
         ppp(hdr,src,"Get, by @, non-const", meta);
         ext(hdr,src,"Handle2@", Child);
         fun(hdr,src,"@@GetBy@", Class, Child, Meta);
         par(hdr,src);
         par(hdr,src,1,"ConstHandle2@ This,", Class);
         par(hdr,src);
         par(hdr,src,1,"const @ @", m.type, meta);
         par(hdr,src);
         sig(hdr,src,true);
         src(1,"return detail::getByMetadatum<CPP,Handle2@>", Child);
         src(2,"(CLASSNAME, CLASSNAME+\"@GetBy@\",", Child, Meta);
         src(2," This, extract::@, meta::@, @);", child, meta, meta);
         def(hdr,src);

         // set, by metadatum
         two(hdr,src);
         ppp(hdr,src,"Set, by @", meta);
         ext(hdr,src,"void");
         fun(hdr,src,"@@SetBy@", Class, Child, Meta);
         par(hdr,src);
         par(hdr,src,1,"ConstHandle2@ This,", Class);
         par(hdr,src);
         par(hdr,src,1,"const @ @,", m.type, meta);
         par(hdr,src);
         par(hdr,src,1,"ConstHandle2Const@ @", Child, child);
         par(hdr,src);
         sig(hdr,src,true);
         src(1,"detail::setByMetadatum<CPP,CPP@>", Child);
         src(2,"(CLASSNAME, CLASSNAME+\"@SetBy@\",", Child, Meta);
         src(2," This, extract::@, meta::@, @, @);", child, meta, meta, child);
         def(hdr,src);

      } // metadata
   } // children
} // fileCInterfaceChild


// ------------------------
// fileCInterfaceCommon
// ------------------------

void fileCInterfaceCommon(
   writer &hdr,
   writer &src,
   const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // Basics section: create, assign, delete
   fileCInterfaceBasics(hdr, src, per);

   // IO section: read, write, print
   fileCInterfaceIO(hdr, src, per);

   // Array support, if BlockData
   if (per.isData)
      fileCInterfaceVector(hdr, src, per, per.dataType);

   // Functions regarding metadata
   for (const auto &m : per.metadata)
      fileCInterfaceMeta(hdr, src, per, m);

   // Functions regarding children
   for (const auto &c : per.children)
      fileCInterfaceChild(hdr, src, specs, per, c);

   // variants
   // todo

} // fileCInterfaceCommon



// -----------------------------------------------------------------------------
// Re: C interface
// fileCInterfaceHeader
// fileCInterfaceSource
// fileCInterface
// -----------------------------------------------------------------------------

// ------------------------
// fileCInterfaceHeader
// ------------------------

void fileCInterfaceHeader(
   writer &hdr, const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // ------------------------
   // Initial remarks
   // ------------------------

   hdr();
   hdr("// Interface for C");
   hdr("// This header file is designed to work with both C and C++");
   hdr("// Function definitions are in this file's .cpp source");
   hdr();

   // ------------------------
   // Instructions
   // ------------------------

   hdr(largeComment);
   hdr(largeComment);
   hdr("// Instructions for Users");
   hdr("//");
   hdr("// Constructs you're MORE likely to care about are preceded with:");
   hdr("//    // +++ comment");
   hdr("// Constructs you're LESS likely to care about are preceded with:");
   hdr("//    // --- comment");
   hdr("// Anything not marked as above can be ignored by most users.");
   hdr("//");
   hdr("// @ is the basic handle type in this file. Example:", per.clname);
   hdr("//    // Create a default @ object:", per.clname);
   hdr("//    @ handle = @Default();", per.clname, per.clname);
   hdr("// Functions involving @ are declared throughout this file.",
       per.clname);
   hdr(largeComment);
   hdr(largeComment);
   hdr();
   hdr();

   // ------------------------
   // Preliminaries
   // ------------------------

   hdr(largeComment);
   hdr("// Preliminaries");
   hdr(largeComment);
   hdr();

   const std::string guard =
      allcaps(specs.Project) + "_" +
      allcaps(specs.VersionUnderscore) + "_" +
      allcaps(per.nsname) + "_" +
      allcaps(per.clname);

   hdr("#ifndef C_INTERFACE_@", guard);
   hdr("#define C_INTERFACE_@", guard);
   hdr();
   hdr("#include \"GNDStk.h\"");
   for (const auto &dep : c2d.dependencies)
      hdr("#include \"@/@/@.h\"", specs.Version, dep.nsname, dep.clname);
   hdr();
   hdr("#ifdef __cplusplus");
   hdr(1,"#define extern_c extern \"C\"");
   hdr("#else");
   hdr(1,"#define extern_c");
   hdr("#endif");
   hdr();
   hdr("// Proxy C struct for the handled C++ class");
   hdr("struct @Class { };", per.clname);
   hdr();
   hdr();

   // ------------------------
   // Handle types
   // ------------------------

   hdr(largeComment);
   hdr("// Handle types");
   hdr(largeComment);
   hdr();
   hdr("// +++ @", per.clname);
   hdr("// +++ General handle, suitable for many users. "
       "If you're not concerned about");
   hdr("// +++ strict \"const correctness\" in your C code, "
       "you can probably use this in");
   hdr("// +++ place of any function parameter of a const-aware handle type.");
   hdr("typedef struct @Class *@;", per.clname, per.clname);
   hdr();
   hdr("// --- Const-aware handles, re: constness of handle vs. handled object.");
   hdr("typedef const struct @Class *const ConstHandle2Const@;",
       per.clname, per.clname);
   hdr("typedef       struct @Class *const ConstHandle2@;",
       per.clname, per.clname);
   hdr("typedef const struct @Class *      Handle2Const@;",
       per.clname, per.clname);
   hdr("typedef       struct @Class *      Handle2@;",
       per.clname, per.clname);
} // fileCInterfaceHeader


// ------------------------
// fileCInterfaceSource
// ------------------------

void fileCInterfaceSource(
   writer &src, const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // includes
   src();
   src("#include \"@/@/@/@.hpp\"",
       specs.Project, specs.VersionUnderscore, per.nsname, per.clname);
   src("#include \"@.h\"", per.clname);
   src();

   // using namespace
   src("using namespace njoy::GNDStk;");
   src("using namespace @::@;", specs.Project, specs.VersionUnderscore);
   src();

   // using
   src("using C = @Class;", per.clname);
   src("using CPP = multigroup::@;", per.clname);
   src();

   // class name
   src("static const std::string CLASSNAME = \"@\";", per.clname);

   // extract: namespace begin
   if (per.nfields()) {
      src();
      src("namespace extract {");
   }

   // extract: metadata
   for (const auto &m : per.metadata)
      src(1,"static auto @ = [](auto &obj) { return &obj.@; };",
          m.name, m.name);

   // extract: children
   for (const auto &c : per.children)
      src(1,"static auto @ = [](auto &obj) { return &obj.@; };",
          c.name, c.name);

   // extract: variants
   // todo Determine how the C interface should deal with C++ variants

   // extract: namespace end
   if (per.nfields()) src("}");

   if (c2d.dependencies.size())
      src();
   for (const auto &dep : c2d.dependencies)
      src("using CPP@ = @::@;", dep.clname, dep.nsname, dep.clname);
} // fileCInterfaceSource


// ------------------------
// fileCInterface
// ------------------------

void fileCInterface(
   const InfoSpecs &specs, const PerClass &per, const Class2Dependencies &c2d
) {
   // header beginning
   writer hdr(per.headerC);
   fileCInterfaceHeader(hdr, specs, per, c2d);

   // source beginning
   writer src(per.sourceC);
   fileCInterfaceSource(src, specs, per, c2d);

   // common or partially common to both header and source
   fileCInterfaceCommon(hdr, src, specs, per, c2d);

   // header: ending
   hdr();
   hdr();
   hdr(largeComment);
   hdr("// Done");
   hdr(largeComment);
   hdr();
   hdr("#undef extern_c");
   hdr("#endif");
} // fileCInterface



// -----------------------------------------------------------------------------
// Python:
// filePythonNamespace
// filePythonClass
// -----------------------------------------------------------------------------

// ------------------------
// filePythonNamespace
// ------------------------

void filePythonNamespace(const InfoSpecs &specs, const PerNamespace &per)
{
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
   out("// @ declarations", per.nsname);
   out("namespace python_@ {", per.nsname);
   for (auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == per.nsname)
         out(1,"void wrap@(python::module &);", cl.theClass.clname);
   out("} // namespace python_@", per.nsname);

   out();
   out("// @ wrapper", per.nsname);
   out("void wrap@(python::module &module)", capital(per.nsname));
   out("{");
   out(1,"// create the @ submodule", per.nsname);
   out(1,"python::module submodule = module.def_submodule(");
   out(2,"\"@\",", per.nsname);
   if (specs.Project == "GNDStk")
      out(2,"\"GNDS @ @\"", specs.Version, per.nsname); // "GNDS", not "GNDStk"
   else
      out(2,"\"@ @ @\"", specs.Project, specs.Version, per.nsname);
   out(1,");");

   out();
   out(1,"// wrap @ components", per.nsname);
   for (auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == per.nsname)
         out(1,"python_@::wrap@(submodule);", per.nsname, cl.theClass.clname);
   out("};");
   out();
   out("} // namespace python_@", specs.VersionUnderscore);
} // filePythonNamespace


// ------------------------
// filePythonClass
// ------------------------

void filePythonClass(const InfoSpecs &specs, const PerClass &per)
{
   const std::string &nsname = per.nsname;
   const std::string &clname = per.clname;
   writer out(per.cppPython);

   static const std::map<std::string,std::pair<std::string,std::string>> map = {
      // ----------------------   -----------            -----------------
      // In per.dataType or       The                    A name to use
      // in per.metadata's        appropriate            for the function
      // valueType defaultValue   C++ type               that returns them
      // ----------------------   -----------            -----------------

      // Described in the GNDS manual.
      // I'm not sure which of the several types that map to std::string can,
      // or would, appear in any GNDS specifications in such a way that we'd
      // need it here, but listing all "string-like" types shouldn't hurt.
      { "Integer32"          , { "int"                , "ints"        } },
      { "UInteger32"         , { "unsigned"           , "uints"       } },
      { "Float64"            , { "double"             , "doubles"     } },
      { "XMLName"            , { "std::string"        , "strings"     } },
      { "UTF8Text"           , { "std::string"        , "strings"     } },
      { "printableText"      , { "std::string"        , "strings"     } },
      { "quotedText"         , { "std::string"        , "strings"     } },
      { "tdText"             , { "std::string"        , "strings"     } },

      // Our versions of the above.
      { "int"                , { "int"                , "ints"        } },
      { "unsigned"           , { "unsigned"           , "uints"       } },
      { "double"             , { "double"             , "doubles"     } },
      { "string"             , { "std::string"        , "strings"     } },
      { "std::string"        , { "std::string"        , "strings"     } },

      // Allow other sensible things.
      { "char"               , { "char"               , "chars"       } },
      { "signed char"        , { "signed char"        , "schars"      } },
      { "short"              , { "short"              , "shorts"      } },
      { "long"               , { "long"               , "longs"       } },
      { "long long"          , { "long long"          , "longlongs"   } },
      { "unsigned char"      , { "unsigned char"      , "uchars"      } },
      { "unsigned short"     , { "unsigned short"     , "ushorts"     } },
      { "unsigned int"       , { "unsigned"           , "uints"       } },
      { "unsigned long"      , { "unsigned long"      , "ulongs"      } },
      { "unsigned long long" , { "unsigned long long" , "ulonglongs"  } },
      { "float"              , { "float"              , "floats"      } },
      { "long double"        , { "long double"        , "longdoubles" } },
      { "quad"               , { "long double"        , "quads"       } }
   };

   std::vector< std::pair< std::string, std::string > > dataTypesNames;
   if (per.isData) {
      // try to find per.dataType in the map
      auto it = map.find(per.dataType);
      if (it != map.end()) {
         // this is a node with a fixed data type
         dataTypesNames.emplace_back( it->second.first, it->second.second );
      }
      else {
         // this is a node with a runtime data type: select types to expose
         std::array< std::string, 3 > types = { "int", "double", "string" };
         for ( const auto& type : types ) {
            it = map.find( type );
            dataTypesNames.emplace_back( it->second.first, it->second.second );
         }
      }
   }

   out();
   out("// system includes");
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");

   out();
   out("// local includes");
   out("#include \"@/@/@/@.hpp\"",
       specs.Project, specs.Version, nsname, clname);
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
   const std::string prefix = specs.Project == "GNDStk" ? "njoy::" : "";
   out(1,"using namespace @@;", prefix, specs.Project);
   out(1,"using namespace @@::@;",
       prefix, specs.Project, specs.VersionUnderscore);
   out();
   out(1,"// type aliases");
   out(1,"using Component = @::@;", nsname, clname);

   // using [variant name] = std::variant..., if necessary
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0;
      const int total = v.children.size();
      for (const auto &c : v.children)
         out(2, "@@", c.type, sep(count,total));
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

   // python::init<...> for attributes and children
   out(2,".def(");
   out(3,"python::init<");
   int count = 0;
   const int total = per.nfields();
   for (auto &m : per.metadata)
      out(4,"const @ &@",
          m.isDefaulted ? "std::optional<" + m.type + ">" : m.typeFull,
          sep(count,total));
   for (auto &c : per.children)
      out(4,"const @ &@", c.typeFull, sep(count,total));
   for (auto &v : per.variants)
      out(4,"const @ &@", v.typeFull, sep(count,total));
   out(3,">(),");
   for (auto &m : per.metadata)
      out(3,"python::arg(\"@\")@,",
          namePython(m.name),
          m.isOptional || m.isDefaulted ? " = std::nullopt" : "");
   for (auto &c : per.children)
      out(3,"python::arg(\"@\")@,", namePython(c.name),
          c.isOptional ? " = std::nullopt" : "");
   for (auto &v : per.variants)
      out(3,"python::arg(\"@\"),", namePython(v.name));
   out(3,"Component::documentation(\"constructor\").data()");
   out(2,")");

   // python::init<...> for each data type and name pair
   for ( const auto& dataTypeName : dataTypesNames ) {
      out(2,".def(");
      out(3,"python::init<");
      out(4,"const std::vector<@> &", dataTypeName.first);
      out(3,">(),");
      out(3,"python::arg(\"@\"),", dataTypeName.second);
      out(3,"Component::documentation(\"constructor\").data()");
      out(2,")");
   }

   // .def_property_readonly...
   for (auto &m : per.metadata) {
      const auto pyname = namePython(m.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      m.isDefaulted
         ? out(3,"[](const Component &self) { return self.@().value(); },",
               m.name)
         : out(3,"[](const Component &self) { return self.@(); },",
               m.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   for (auto &c : per.children) {
      const auto pyname = namePython(c.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      out(3,"[](const Component &self) { return self.@(); },", c.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   for (auto &v : per.variants) {
      if (!v.isVector)
         for (auto &c : v.children) {
            const auto pyname = namePython(c.name);
            out(2,".def_property_readonly(");
            out(3,"\"@\",", pyname);
            out(3,"[](const Component &self) { return self.@(); },", c.name);
            out(3,"Component::documentation(\"@\").data()", pyname);
            out(2,")");
         }
      const auto pyname = namePython(v.name);
      out(2,".def_property_readonly(");
      out(3,"\"@\",", pyname);
      out(3,"[](const Component &self) { return self.@(); },", v.name);
      out(3,"Component::documentation(\"@\").data()", pyname);
      out(2,")");
   }

   for ( const auto& dataTypeName : dataTypesNames ) {
      out(2,".def_property_readonly(");
      out(3,"\"@\",", dataTypeName.second);
      out(3,"[] (const Component &self) { return self.@(); },",
          dataTypeName.second);
      out(3,"Component::documentation(\"@\").data()", dataTypeName.second);
      out(2,")");
   }

   // finish
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

   // GNDStk hpp file, as well as header and source files for the C interface,
   // for each namespace::class
   for (const auto &obj : specs.ClassDependenciesSorted) {
      auto find = specs.class2data.find(obj.theClass);
      assert(find != specs.class2data.end());
      // C++ header
      fileGNDStkClass(specs, find->second, obj);
      // C interface: header and source
      fileCInterface(specs, find->second, obj);
   }

   // Python cpp file for each namespace
   for (auto &obj : specs.namespace2data)
      filePythonNamespace(specs, obj.second);

   // Python cpp file for each namespace::class
   for (auto &obj : specs.class2data)
      filePythonClass(specs, obj.second);
   std::cout << std::endl;
}
