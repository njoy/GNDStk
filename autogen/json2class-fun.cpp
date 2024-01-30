
// -----------------------------------------------------------------------------
// Miscellaneous short functions
// -----------------------------------------------------------------------------

// action_helper
void action_helper(std::string str)
{
   str.resize(80,' ');
   // boldface + background color + foreground color + text
   // std::cout << "\033[1m\033[48;2;80;80;80m\033[38;2;255;255;255m" << str;
   // background color + foreground color + text
   std::cout << "\033[48;2;80;80;80m\033[38;2;255;255;255m" << str;
   std::cout << color::reset << std::endl;

   /*
   // loud colors; may or may not want
   static const int ncol = 80;
   static const int last = ncol-1;

   for (int col = 0; col < ncol; ++col) {
      int r = 255*(last-col)/last;
      int g = 255 - std::abs(255*(last-col-col)/last);
      int b = 255*col/last;
      std::cout << "\033[48;2;" << r << ";" << g << ";" << b << "m"
                << "\033[38;2;255;255;255m"
                << (col < str.size() ? str[col] : ' ');
   }
   std::cout << color::reset << std::endl;
   */
}

// action
// Print text describing an action the code is about to take
template<class... ARGS>
void action(const ARGS &...args)
{
   static const std::string inverse = "\033[7m";
   static const std::string background(80,' ');
   std::cout << '\n';
   action_helper("");
   (action_helper(args), ...);
   action_helper("");
   std::cout << color::reset << std::endl;
}

// allws
// Is the string all whitespace?
bool allws(const std::string &str)
{
   for (const auto c : str)
      if (!isspace(c))
         return false;
   return true;
}

// escape
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

// capital
// Capitalize the first letter
std::string capital(const std::string &str)
{
   std::string ret = str;
   if (ret.size() > 0)
      ret[0] = toupper(ret[0]);
   return ret;
}

// allcaps
// Capitalize all letters
std::string allcaps(const std::string &str)
{
   std::string ret = str;
   for (size_t i = ret.size(); i--; )
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

// replace
// Replace character
std::string replace(const std::string &str, const char from, const char to)
{
   std::string ret = str;
   for (size_t i = ret.size(); i--; )
      if (ret[i] == from)
         ret[i] = to;
   return ret;
}

// stringify
// Stringify JSON
std::string stringify(const json::value &j)
{
   const std::string tmp = j.dump();
   return j.has<json::string>()
      ? tmp.substr(1, tmp.size()-2)
      : tmp;
}

// isComment
// Does this JSON key look like a C++ style comment?
bool isComment(const std::string &key)
{
   return strncmp(key.data(), "//", 2) == 0;
}

// isClass
// Does this JSON key/value pair appear to describe a class?
bool isClass(const json::pair &keyval)
{
   const auto &key = keyval.first;
   const auto &val = keyval.second;

   // a comment?
   if (isComment(key))
      return false;

   // not a class?
   if (key == "__namespace__" || key == "namespace" || key == "Specifications")
      return false;

   // not a node class?
   if ((val.has("__class__") &&
        val["__class__"].get<json::string>() != "nodes.Node") ||
       (val.has(  "class"  ) &&
        val[  "class"  ].get<json::string>() != "nodes.Node")
   )
      return false;

   return true;
}

// getTimes
const std::string &getTimes(
   const PerClass &per, const std::string &key, const json::object &value
) {
   const std::string times = "times"; // shorter, less easily misspelled
   const std::string occurrence = "occurrence"; // accept; used in GNDS specs

   // need exactly one - not neither, not both
   if (value.has(times) == value.has(occurrence)) {
      log::error(
        "In namespace \"{}\", class \"{}\":\n"
        "Child node \"{}\" needs exactly one of \"times\" or \"occurrence\".\n"
        "Or, did you possibly intend \"{}\" to be an attribute/metadatum?",
         per.nsname, per.clname, key, key);
      throw std::exception{};
   }

   return value.has(times)
      ? value[times].get<json::string>()
      : value[occurrence].get<json::string>();
}

// sep
std::string sep(int &count, const int total)
{
   return ++count < total ? "," : "";
}


// -----------------------------------------------------------------------------
// name* functions
// -----------------------------------------------------------------------------

// nameGNDS
// Name in a GNDS file (e.g., name of an XML element)
const std::string &nameGNDS(
   const json::pair &keyval,
   const std::string &nsname = "",
   const bool print = false
) {
   // For debugging
   if (debugging && print) {
      const std::string key = keyval.first;
      const std::string name = keyval.second.has("name")
         ? keyval.second["name"].get<json::string>()
         : key;

      std::cout
         << "class:  "
         << std::setw(20) << std::left << nsname << " "
         << std::setw(48) << std::left << key << " "
         << (key == name ? " " : "*")  << " "
         << std::left << name << std::endl;
   }

   // As-is, directly as stipulated in the key in the JSON spec, except
   // that we allow a "name" entry in the key's value to override the key.
   return keyval.second.has("name")
      ? keyval.second["name"].get<json::string>()
      : keyval.first;
}

// nameField
// Name of a field (metadatum or child node) in an autogenerated class
const std::string &nameField(const json::pair &keyval, const InfoSpecs &specs)
{
   const std::string &name = keyval.first;
   // Here, we apply any name-modification map that may have been provided
   // in a "changes" file. Such changes can fix, for example, the name "double"
   // that appears in some GNDS specs as a JSON key, given that "double" is
   // unsuitable for use as a variable name in C++.
   const auto it = specs.mapName.find(name);
   return it == specs.mapName.end() ? name : it->second;
}

// nameClass
// Name of an autogenerated class
std::string nameClass(const json::pair &keyval, const InfoSpecs &specs)
{
   // Capitalized version of either the JSON key, or, if applicable,
   // its change under the name-modification map in a "changes" file.
   const std::string &name = keyval.first;
   const auto it = specs.mapName.find(name);
   return capital(it == specs.mapName.end() ? name : it->second);
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
const std::string &getFileNamespace(const json::object &j)
{
   return j.has("__namespace__")
      ? j["__namespace__"].get<json::string>()
      : j[  "namespace"  ].get<json::string>();
}

// Get the JSON's "type", with any relevant specs.mapMetaType entry applied
const std::string &getMetadatumType(
   const json::object &j, const InfoSpecs &specs
) {
   const std::string &type = j["type"].get<json::string>();
   const auto it = specs.mapMetaType.find(type);
   return it == specs.mapMetaType.end() ? type : it->second;
}

// Determine to what namespace childClass belongs. Context: we're (1) in a JSON
// spec with namespace parent.nsname, (2) in a parent node named parent.clname,
// and (3) wish to determine the proper namespace for the parent's child node
// named childClass. Parameter j is the JSON value ({...}) for this child node.
std::string getChildNamespace(
   const json::object &j, const InfoSpecs &specs,
   const PerClass &per, const std::string &childClass
) {
   // childClass' namespace...

   // ...is explicitly given by "__namespace__"or "namespace"
   if (j.has("__namespace__"))
      return j["__namespace__"].get<json::string>();
   if (j.has(  "namespace"  ))
      return j[  "namespace"  ].get<json::string>();

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

// ------------------------
// getClassMetadata
// ------------------------

void getClassMetadata(
   const json::object &j, const InfoSpecs &specs,
   PerClass &per
) {
   for (const auto &field : j.items()) {
      if (beginsin(field.first, "//"))
         continue;
      if (!field.second.has<json::object>())
         continue;
      const json::object &metaRHS = field.second.get<json::object>();

      // Name
      InfoMetadata m;
      m.original = nameGNDS(field);
      m.name = nameField(field,specs);

      // Converter, if given
      m.converter = metaRHS.has("converter")
         ? metaRHS["converter"].get<json::string>()
         : "";

      // Type
      m.type = getMetadatumType(metaRHS,specs);

      // Has default?
      m.defaultValue = "";
      if (metaRHS.has("default") && !metaRHS["default"].is_null()) {
         m.defaultValue = stringify(metaRHS["default"]);
         // Apply the "changes.json" change, if any, to the given value
         const auto it = specs.mapMetaDefault.find(m.defaultValue);
         if (it != specs.mapMetaDefault.end())
            m.defaultValue = it->second;
      };
      if (m.defaultValue != "") {
         // If it has a default, then presumably it isn't required...
         if (metaRHS["required"].get<json::boolean>()) {
            log::error(
              "In namespace \"{}\", class \"{}\",\n"
              "metadatum \"{}\" has a default ({}), but is required.\n"
              "If it really is required, then it shouldn't have a default.\n"
              "If it really has a default, then presumably it isn't required.",
               per.nsname, per.clname, m.name, m.defaultValue);
            throw std::exception{};
         }
      }

      // Optional? (not required, and has no default)
      m.isOptional =
         !metaRHS["required"].get<json::boolean>() &&
         m.defaultValue == "";
      const std::string optPrefix = m.isOptional ? "std::optional<" : "";
      const std::string optSuffix = m.isOptional ? ">" : "";

      // Defaulted? (not required, but does have a default)
      m.isDefaulted =
         !metaRHS["required"].get<json::boolean>() &&
         m.defaultValue != "";
      const std::string defPrefix = m.isDefaulted ? "Defaulted<" : "";
      const std::string defSuffix = m.isDefaulted ? ">" : "";

      // Full type, including any optional<> or Defaulted<>
      m.typeFull =
         optPrefix + defPrefix +
         m.type +
         defSuffix + optSuffix;

      // Add to per.metadata
      per.metadata.push_back(m);
   }
} // getClassMetadata


// ------------------------
// getClassChildren
// ------------------------

void getClassChildren(
   const json::object &j, const InfoSpecs &specs,
   PerClass &per, Class2Dependencies &dep
) {
   for (const auto &field : j.items()) {
      if (beginsin(field.first, "//"))
         continue;
      if (!field.second.has<json::object>())
         continue;
      const json::object &elemRHS = field.second.get<json::object>();

      // Choice children are handled elsewhere
      const std::string &times = getTimes(per, field.first, elemRHS);
      if (times == "choice" || times == "choice+" || times == "choice2+")
         continue;

      // Name
      InfoChildren c;
      c.original = nameGNDS(field);
      c.name = nameField(field,specs);

      // Converter, Filter, and Label, if given
      c.converter = elemRHS.has("converter")
         ? elemRHS["converter"].get<json::string>() : "";
      c.filter    = elemRHS.has("filter")
         ? elemRHS["filter"   ].get<json::string>() : "";
      c.label     = elemRHS.has("label")
         ? elemRHS["label"    ].get<json::string>() : "";

      // Type, excluding namespace
      c.plain = nameClass(field,specs);

      // Type, including namespace
      c.ns = getChildNamespace(elemRHS, specs, per, c.plain);
      c.type = c.ns + "::" + c.plain;

      // Optional?
      c.isOptional = !elemRHS["required"].get<json::boolean>();
      const std::string optPrefix = c.isOptional ? "std::optional<" : "";
      const std::string optSuffix = c.isOptional ? ">" : "";

      // Vector?
      c.isVector = times == "0+" || times == "1+" || times == "2+";
      const std::string vecPrefix = c.isVector ? "std::vector<" : "";
      const std::string vecSuffix = c.isVector ? ">" : "";

      // Full type, including any optional<> or vector<>
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


// ------------------------
// getClassVariants
// ------------------------

void getClassVariants(
   const json::object &j, const InfoSpecs &specs,
   PerClass &per, Class2Dependencies &dep
) {
   // Initialize per.variants, a vector<InfoVariants> that has the "choice"
   // children from the current class. Computing a map<string,InfoVariants>,
   // first, turns out to be convenient, given the manner in which the choice
   // children appear in the JSON specifications: listed in a "flat" manner,
   // as child nodes, rather than grouped one level deeper inside of, say,
   // a "choice" JSON key. Remark: this code supports the option of having
   // multiple sets of choices under the current parent; for example, the
   // parent can have {X or Y}, and (independently) have {A or B or C}. Our
   // JSON "variant" key facilitates this: give the same value for X and Y,
   // and the same value for A, B, and C. At the time of this writing, GNDS
   // specifications appear to allow for only one choice-between-things (just
   // X,Y, for example, or just A,B,C) in a given parent, but we believe that
   // our extension may prove to be useful at some point.

   std::map<std::string,InfoVariants> map;

   // Pass 1
   // Collect "variant" names, and if ever it's absent, a to-be-determined
   // name for all choice children for which it's absent
   for (const auto &field : j.items()) {
      if (beginsin(field.first, "//"))
         continue;

      // Is it a choice child?
      if (!field.second.has<json::object>())
         continue;
      const json::object &elemRHS = field.second.get<json::object>();
      const std::string &times = getTimes(per,field.first,elemRHS);
      if (times != "choice" && times != "choice+" && times != "choice2+")
         continue;

      // Variant name
      const std::string variantName = elemRHS.has("variant")
         ? elemRHS["variant"].get<json::string>()
         : ""; // to be determined
      map.insert(std::make_pair(variantName,InfoVariants{}));
   }

   // Pass 2
   for (const auto &field : j.items()) {
      if (beginsin(field.first, "//"))
         continue;

      // Is it a choice child?
      if (!field.second.has<json::object>())
         continue;
      const json::object &elemRHS = field.second.get<json::object>();
      const std::string &times = getTimes(per,field.first,elemRHS);
      if (times != "choice" && times != "choice+" && times != "choice2+")
         continue;

      // Variant name
      const std::string variantName = elemRHS.has("variant")
         ? elemRHS["variant"].get<json::string>()
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

      assert(!elemRHS["required"].get<json::boolean>());

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
// Miscellaneous functions for getting JSON content
// -----------------------------------------------------------------------------

// readJSONFile
json::object readJSONFile(const std::string &file, const bool print = false)
{
   // Depending on the call context, we might or might not print the file name
   if (print) {
      const std::string f = beginsin(file,"./") ? std::string(&file[2]) : file;
      std::cout << color::custom::purple << f << color::reset << std::endl;
   }

   std::ifstream ifs(file);
   if (!ifs) {
      log::error("Could not open file \"{}\"", file);
      throw std::exception{};
   }

   json::object j;
   ifs >> j;
   return j;
} // readJSONFile


// getMetadataJSON
json::object getMetadataJSON(const json::object &j)
{
   static const std::string metastr = "metadata";
   static const std::string attrstr = "attributes";
   const bool meta = j.has(metastr);
   const bool attr = j.has(attrstr);

   // not both
   assert(!(meta && attr));

   return
      meta ? j[metastr].get<json::object>()
    : attr ? j[attrstr].get<json::object>()
    : json::object{};
} // getMetadataJSON


// getChildrenJSON
json::object getChildrenJSON(const json::object &j)
{
   static const std::string chldstr = "children";
   static const std::string nodestr = "childNodes";
   const bool chld = j.has(chldstr);
   const bool node = j.has(nodestr);

   // not both
   assert(!(chld && node));

   return
      chld ? j[chldstr].get<json::object>()
    : node ? j[nodestr].get<json::object>()
    : json::object{};
} // getChildrenJSON


// -----------------------------------------------------------------------------
// commandLine and its helper functions
// -----------------------------------------------------------------------------

// ------------------------
// readChangesFile
// ------------------------

void readChangesFile(const std::string &file, InfoSpecs &specs)
{
   const json::object jchanges = readJSONFile(file);
   using pair = std::pair<std::string,std::string>;

   // Changes to name?
   if (jchanges.has("name"))
      for (const auto &item : jchanges["name"].items())
         if (!isComment(item.first))
            specs.mapName.insert(
               pair(item.first, item.second.get<json::string>())
            );

   // Changes to metadata/attributes?
   const json::object metadata = getMetadataJSON(jchanges);

   // from/to pairs for "type"
   if (metadata.has("type"))
      for (const auto &item : metadata["type"].items())
         if (!isComment(item.first))
            specs.mapMetaType.insert(
               pair(item.first,item.second.get<json::string>())
            );
   // from/to pairs for "default"
   if (metadata.has("default"))
      for (const auto &item : metadata["default"].items())
         if (!isComment(item.first))
            specs.mapMetaDefault.insert(
               pair(item.first,item.second.get<json::string>())
            );
} // readChangesFile


// ------------------------
// printSingletons
// ------------------------

void printSingletons(const std::string &file)
{
   const json::object &jfile = readJSONFile(file,true);

   for (const auto &item : jfile.items()) {
      if (beginsin(item.first, "//"))
         continue;
      if (!item.second.has<json::object>())
         continue;
      const json::object &rhs = item.second.get<json::object>();

      if (!isClass(item))
         continue;

      const bool hasdata =
         (rhs.has("string"  ) && !rhs["string"  ].is_null()) ||
         (rhs.has("vector"  ) && !rhs["vector"  ].is_null()) ||
         (rhs.has("bodyText") && !rhs["bodyText"].is_null());

      const json::object metadata = getMetadataJSON(rhs);
      const json::object children = getChildrenJSON(rhs);

      const std::string parent = item.first;
      if (metadata.size() == 0 && children.size() == 1 && !hasdata)
         std::cout
            << color::custom::green
            << "   Entry has no metadata or data, and just one child: "
            << color::custom::blue << parent << color::reset << std::endl;
      if (metadata.size() == 0 && children.size() == 0 && !hasdata)
         std::cout
            << color::custom::yellow
            << "   Entry has no metadata, data, or children: "
            << color::custom::blue << parent << color::reset << std::endl;
   }
} // printSingletons


// ------------------------
// commandLine
// ------------------------

// Gather information from the JSON file given on the command line
void commandLine(
   const int argc, const char *const *const argv,
   InfoSpecs &specs
) {
   // Usage
   if (argc < 2) {
      std::cout << "Usage: " << argv[0] << " file.json" << std::endl;
      exit(EXIT_FAILURE);
   }

   // Input file
   const json::object jmain = readJSONFile(argv[1]);

   // JSON keys we'll look for
   static const std::string path    = "Path";
   static const std::string project = "Project";
   static const std::string version = "Version";
   static const std::string input   = "JSONDir";
   static const std::string files   = "JSONFiles";
   static const std::string enums   = "Enumerators";
   static const std::string changes = "Changes";

   // Need "Version"
   if (!jmain.has(version)) {
      log::error("The input JSON file needs {}", version);
      throw std::exception{};
   }

   // Need "JSONFiles"
   if (!jmain.has(files)) {
      log::error("The input JSON file needs {}", files);
      throw std::exception{};
   }

   // Extract information from the command line JSON file...

   // ...these are optional:
   specs.Path    = jmain.has(path   )
      ? jmain[path   ].get<json::string>() : ".";
   specs.Project = jmain.has(project)
      ? jmain[project].get<json::string>() : "GNDStk";
   specs.JSONDir = jmain.has(input  )
      ? jmain[input  ].get<json::string>() : ".";

   if (jmain.has(enums))
      for (const auto &e : jmain[enums].get<json::object>().items()) {
         specs.Enumerators.push_back(
            std::make_pair(e.first,std::vector<std::string>()));
         for (const auto &sym : e.second.get<json::array>())
            specs.Enumerators.back().second.push_back(sym.get<json::string>());
      }

   // ...these are required:
   specs.Version = jmain[version].get<json::string>();
   for (const auto &str : jmain[files].get<json::array>())
      specs.JSONFiles.push_back(str.get<json::string>());

   // Version, with '_'s in place of '.'s
   specs.VersionUnderscore = replace(specs.Version, '.', '_');

   // Prepend the JSON file names with their directory
   for (std::string &file : specs.JSONFiles)
      file = specs.JSONDir + '/' + file;

   // File names...

   // For C++
   const std::string cbase =
      specs.Path + "/" + specs.Project + "/src/" + specs.Project + "/";
   specs.hppVersion = cbase + specs.Version + ".hpp";
   specs.hppKey     = cbase + specs.Version + "/key.hpp";

   // For the C interface
   const std::string cppbase = specs.Path + "/" + specs.Project + "/c/src/";
   specs.hVersion = cppbase + specs.Version + ".h";
   // We don't currently know of anything that we'd have in the following
   // file, so we won't create it. But I'll leave this in as a placeholder.
   specs.cVersion = cppbase + specs.Version + ".cpp";

   // For the python interface
   const std::string pybase = specs.Path + "/" + specs.Project + "/python/src/";
   specs.allPython = pybase + "all.python.cpp";
   specs.cppPython = pybase + specs.Version + ".python.cpp";

   // Changes?
   if (jmain.has(changes))
      readChangesFile(jmain[changes].get<json::string>(),specs);
} // commandLine


// -----------------------------------------------------------------------------
// preprocess* functions
// -----------------------------------------------------------------------------

// preprocessClass
void preprocessClass(
   InfoSpecs &specs, const std::string &nsname, const json::pair &keyval
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
   // Create directories
   // ------------------------

   // For the present namespace: C++, Python, and C directories. The present
   // namespace probably contains multiple classes, so these directories may
   // have been created already, but that's fine.
   const std::string nsdircpp = specs.Path + "/" + specs.Project +
      "/src/" + specs.Project + "/" + specs.Version + "/" + nsname;
   const std::string nsdirpy  = specs.Path + "/" + specs.Project +
      "/python/src/" + specs.Version + "/" + nsname;
   const std::string nsdirc   = specs.Path + "/" + specs.Project +
      "/c/src/" + specs.Version + "/" + nsname;
   const std::string nsdirf03 = specs.Path + "/" + specs.Project +
      "/fortran/src/" + specs.Version + "/" + nsname;

   // For the present class: C++ and C source and test directories.
   const std::string clsrccpp  = nsdircpp + "/" + clname + "/src";
   const std::string cltestcpp = nsdircpp + "/" + clname + "/test";
   const std::string clsrcc    = nsdirc   + "/" + clname + "/src";
   const std::string cltestc   = nsdirc   + "/" + clname + "/test";
   // const std::string clsrcf03  = nsdirf03 + "/" + clname + "/src";
   // const std::string cltestf03 = nsdirf03 + "/" + clname + "/test";

   // Create the above directories, if (and only if) they don't already exist.
   system(("mkdir -p " + nsdircpp ).data());
   system(("mkdir -p " + nsdirpy  ).data());
   system(("mkdir -p " + nsdirc   ).data());
   system(("mkdir -p " + nsdirf03 ).data());
   system(("mkdir -p " + clsrccpp ).data());
   system(("mkdir -p " + cltestcpp).data());
   system(("mkdir -p " + clsrcc   ).data());
   system(("mkdir -p " + cltestc  ).data());
   // system(("mkdir -p " + clsrcf03 ).data());
   // system(("mkdir -p " + cltestf03).data());

   // ------------------------
   // Create custom files
   // ------------------------

   // To allow for customization of the present class in the present namespace,
   // create certain custom.* files. Do so, however, only where any such file
   // isn't already there, or else we might be trashing someone's customization!

   // Below, the "false" parameters in the writer constructions prevent the
   // file from getting our "autogenerated, do not modify" admonishment at the
   // top. This makes sense, as the customization file are there precisely for
   // users to, well, customize.

   // C++ custom.hpp
   const std::string customhpp = clsrccpp + "/custom.hpp";
   if (!std::ifstream(customhpp)) {
      std::cout
         << color::custom::green << "   Creating " << clsrccpp + "/"
         << color::custom::blue << "custom.hpp" << color::reset << std::endl;
      writer out(customhpp,false); // false: no "file was autogenerated" message
      out();
      out(0,"private:");
      out();
      out(1,"static inline helpMap help = {};");
   }

   // As above, but for the C interface: create custom.h and custom.cpp if and
   // where they don't already exist.

   // C custom.h
   const std::string customh = clsrcc + "/custom.h";
   if (!std::ifstream(customh)) {
      std::cout
         << color::custom::green << "   Creating " << clsrcc + "/"
         << color::custom::blue << "custom.h" << color::reset << std::endl;
      writer out(customh,false);
   }

   // C custom.cpp
   // Meaning, C++ source for the C interface to call. (That is, this isn't for
   // C++ itself; remember that our C++ library is header-only.)
   const std::string customcpp = clsrcc + "/custom.cpp";
   if (!std::ifstream(customcpp)) {
      std::cout
         << color::custom::green << "   Creating " << clsrcc + "/"
         << color::custom::blue << "custom.cpp" << color::reset << std::endl;
      writer out(customcpp,false);
   }

   // ------------------------
   // Create file-name maps
   // ------------------------

   // For this namespace:
   //    The cpp file for Python
   // ns.first -> a PerNamespace
   auto ns = specs.namespace2data.insert(std::make_pair(nsname,PerNamespace{}));
   ns.first->second.cppPython = nsdirpy + ".python.cpp";
   ns.first->second.nsname = nsname;

   // For this namespace::class:
   //    The cpp file for Python
   //    The hpp file for GNDStk
   //    The C/C++ header, and the C++ backend source for the C interface
   //    The Fortran 2003 source
   // cl.first -> a PerClass
   auto cl = specs.class2data.insert(
      std::make_pair(NamespaceAndClass{nsname,clname}, PerClass{}));
   assert(cl.second); // should have been inserted - not there already
   cl.first->second.cppPython = nsdirpy  + "/" + clname + ".python.cpp";
   cl.first->second.hppGNDStk = nsdircpp + "/" + clname + ".hpp";
   cl.first->second.headerC   = nsdirc   + "/" + clname + ".h";
   cl.first->second.sourceC   = nsdirc   + "/" + clname + ".cpp";
   cl.first->second.sourceF03 = nsdirf03 + "/" + clname + ".f03";
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
   // files
   for (const std::string &file : specs.JSONFiles) {
      const json::object jmain = readJSONFile(file,true);
      const std::string nsname = getFileNamespace(jmain);
      // classes in the file
      for (const auto &cl : jmain.items())
         preprocessClass(specs, nsname, cl);
   }
} // preprocessFiles


// -----------------------------------------------------------------------------
// validate*
// getClass
// getFilesAndClasses
// -----------------------------------------------------------------------------

// validateMetadata
void validateMetadata(const json::object &metadata)
{
   for (const auto &field : metadata.items()) {
      if (beginsin(field.first, "//"))
         continue;
      assert(field.second.has("type"));
      assert(field.second.has("required"));
   }
}

// validateChildren
void validateChildren(const json::object &children, const PerClass &per)
{
   for (const auto &field : children.items()) {
      if (beginsin(field.first, "//"))
         continue;
      assert(field.second.has("required"));

      // Consistency check: certain occurrence values imply *not* required.
      // Remark: the GNDS manual speaks of "choice2" and "choice2+" options
      // for occurrence. We're not sure if those will remain in future GNDS
      // specifications, so we won't worry now about how they might fit in.
      const std::string &times = getTimes(
         per,
         field.first,
         field.second.get<json::object>()
      );
      if (times == "0+" || times == "choice" || times == "choice+")
         assert(!field.second["required"].get<json::boolean>()); // not required

      if (debugging) {
         const std::string key  = field.first;
         const std::string name = field.second.has("name")
            ? field.second["name"].get<json::string>()
            : key;
         std::cout
            << "child:  "
            << std::setw(20) << std::left << per.nsname << " "
            << std::setw(48) << std::left << per.clname << " "
            << std::setw(48) << std::left << key << " "
            << (key == name ? " " : "*")  << " "
            << std::left << name << std::endl;
      }
   }
}

// getClass
void getClass(
   InfoSpecs &specs, const std::string &nsname, const json::pair &keyval
) {
   if (!isClass(keyval))
      return;
   const std::string clname = nameClass(keyval,specs);

   // find in class map
   const auto it = specs.class2data.find(NamespaceAndClass(nsname,clname));
   PerClass &per = it->second;

   // collect dependencies, for the present class, as this function proceeds
   Class2Dependencies dep;
   dep.theClass = NamespaceAndClass(nsname,clname);

   // names
   per.nsname = nsname;
   per.clname = clname;
   per.nameGNDS = nameGNDS(keyval,nsname,true);

   // metadata/children information
   const json::object &classRHS = keyval.second.get<json::object>();
   const json::object attrs = getMetadataJSON(classRHS);
   const json::object elems = getChildrenJSON(classRHS);
   validateMetadata(attrs);
   validateChildren(elems, per);
   getClassMetadata(attrs, specs, per);
   getClassChildren(elems, specs, per, dep);
   getClassVariants(elems, specs, per, dep);

   // data-node information
   const bool
      str  = classRHS.has("string"  ) && !classRHS["string"  ].is_null(),
      vec  = classRHS.has("vector"  ) && !classRHS["vector"  ].is_null(),
      body = classRHS.has("bodyText") && !classRHS["bodyText"].is_null();
   assert(int(str) + int(vec) + int(body) <= 1); // no more than one

   per.isDataString = str;
   per.isDataVector = vec || body;
   if (vec) {
      // A type change, as with metadata, may be warranted here as well
      const std::string type = classRHS["vector"].get<json::string>();
      const auto it = specs.mapMetaType.find(type);
      per.elementType = it == specs.mapMetaType.end() ? type : it->second;
   } else
      per.elementType = "";
   per.isDataNode =
      per.isDataString ||
     (per.isDataVector && per.elementType != "");
   per.cdata =
      classRHS.has("cdata") &&
      classRHS["cdata"].get<json::boolean>();

   // save dependencies
   specs.ClassDependenciesRaw.push_back(dep);
} // getClass


// getFilesAndClasses
void getFilesAndClasses(InfoSpecs &specs)
{
   // each file
   for (const std::string &file : specs.JSONFiles) {
      const json::object jmain = readJSONFile(file);
      const std::string nsname = getFileNamespace(jmain);
      // each class
      for (const auto &cl : jmain.items())
         getClass(specs, nsname, cl);
   }
} // getFilesAndClasses


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
// ShortcutDown
// Helper for the shortcuts() function
// -----------------------------------------------------------------------------

void ShortcutDown(
   const InfoSpecs &specs,
   const InfoChildren &child,
   std::map<std::string,bool> &usednames,
   std::vector<std::string> &path,
   std::multimap<std::string,std::vector<std::string>> &name2path,
   std::set<std::string> &optvec,
   std::string &title, // might be modified
   int down,
   const bool warn,
   bool consider // <== we've *not* already gone through an optional or vector?
) {
   if (child.isOptional || child.isVector)
      consider = false; // at least henceforth, if not already

   const std::string &nsname = child.ns;
   const std::string &clname = child.plain;
   const auto it = specs.class2data.find(NamespaceAndClass(nsname,clname));
   if (it == specs.class2data.end()) {
      // We can't seem to find the namespace::class of the child object we're
      // looking at. This is probably more-or-less an error situation, at least
      // if somebody created all the children in their generated classes at the
      // same time that they created the parent - basically, meaning everything
      // was created in a single run of the code generator, which is how we
      // intend for it to be used. In any event: right here, in the present
      // context, we can't reason about shortcuts through the child if we can't
      // find any information *about* the child. So, we'll just return.
      return;
   }

   for (const auto &grand : it->second.children) {
      // grand: an InfoChildren
      const auto used = usednames.find(grand.name);
      if (used == usednames.end()) {
         if (consider) {
            // Create a preliminary shortcut, to be used later if, and only if,
            // nothing elsewhere introduces a name conflict. If something else
            // does, then we'll say, at that point, that the potential shortcut
            // is ambiguous. (It would probably create confusion if we somehow
            // chose one shortcut path over others, or tried to disambiguate by
            // inventing different names based on the same original name.)
            name2path.insert(std::make_pair(grand.name,path));
         } else {
            // We've gone through an optional or vector, and thus won't ever
            // be creating a shortcut to here. However, we'll record the fact
            // that something of this name exists, even if only through an
            // optional or vector, because such a scenario might be regarded
            // as a good reason to *not* shortcut to other same-named objects
            // that are otherwise valid for shurtcuts.
            optvec.insert(grand.name);
         }
      } else if (warn && !used->second) {
         std::cout
            << title << color::custom::faded::yellow
            << "   Shortcut would conflict with existing field: "
            << color::custom::yellow << grand.name
            << color::reset << std::endl;
         title = "";
         used->second = true; // so, don't report future conflicts w/same name
      }

      // Note that we always dig further, regardless of what happened with the
      // above conditionals. The current object might or might not, for whatever
      // reason or reasons, be something to which we could shortcut. However,
      // objects further down could potentially still be shortcut candidates,
      // or could prove to be deal breakers for other candidates.
      if (--down) {
         path.push_back(grand.name);
         ShortcutDown(
            specs, grand, usednames, path, name2path,
            optvec, title, down, warn, consider
         );
         path.pop_back();
      }
      down++;
   }
}


// -----------------------------------------------------------------------------
// shortcuts
// -----------------------------------------------------------------------------

void shortcuts(InfoSpecs &specs, int down, const bool warn)
{
   if (down == 1)
      return;

   // ------------------------
   // For each class
   // ------------------------

   for (auto &s : specs.class2data) {
      // s.first : a NamespaceAndClass
      // s.second: a PerClass, which we'll call "current" (the current class)

      // The following, title, simply tells us the namespace::class we're
      // currently examining. We'll arrange things so that it isn't printed
      // at all (thus reducing/decluttering the code generator's output) if
      // there's nothing to say - no shortcuts, no remarks about why some
      // shortcut potential didn't pan out. If anything *is* said, title is
      // printed and then set to "", so that it isn't needlessly re-printed.
      std::string title =
         color::custom::faded::purple + s.first.nsname + "::" +
         color::custom::purple + s.first.clname +
         color::reset + '\n';

      // ------------------------
      // Existing field names
      // in the current class
      // ------------------------

      // The bool is for diagnostic reporting, if we want to report only
      // once, per name, about potential shortcut(s) conflicting with it.
      std::map<std::string,bool> usednames;

      // comment; all of our generated classes have this
      usednames.insert(std::make_pair("comment",false));

      // metadata, children, variants
      PerClass &current = s.second;
      for (const auto &m : current.metadata)
         usednames.insert(std::make_pair(m.name,false));
      for (const auto &c : current.children)
         usednames.insert(std::make_pair(c.name,false));
      for (const auto &v : current.variants)
         usednames.insert(std::make_pair(v.name,false));

      // data (string or vector)
      if (current.isDataNode) {
         if (current.isDataString)
            usednames.insert(std::make_pair("string",false));
         else {
            // As in some other new(er) code-generator capabilities, I haven't
            // handled the GNDS valueType (basically, dynamic data type) stuff
            // here because it's inherently a messy concept and we may be able
            // to avoid the need for it. (But possibly todo.)
            auto it = nameMap.find(current.elementType);
            if (it != nameMap.end())
               usednames.insert(std::make_pair(it->second.second,false));
         }
      }

      // ------------------------
      // Visit children
      // ------------------------

      // For each object to which a shortcut may be possible (to be determined,
      // based on criteria such as uniqueness), we'll have a map key:value pair.
      // The key is the name of the object to which we may shortcut. The value
      // is a vector of names, giving the path to the object. Example: say that
      // the current class has x, which has y, which has foo. The potential foo
      // shortcut would be represented by map key "foo", value {"x","y"}. Note
      // that we use a multimap, because something might appear via multiple
      // viable paths - without going through any optional, vector, or variant.
      // An object of the same name being in multiple paths may mean that we
      // won't shortcut to any of them (unless we decide on a reasonable way
      // to disambiguate), but we can still use the multimap we'll be computing
      // to print informational messages telling users about multuple paths.
      std::multimap<std::string, std::vector<std::string>> name2path;

      // The above will contain key:value pairs for objects that appear to be
      // valid for shortcutting - they don't go through optionals or vectors -
      // except potentially for ambiguities. We'll also maintain (separately,
      // as doing so is cleaner) a set of names that appear through optionals
      // and/or vectors. We won't need paths here, as we'd never be using them,
      // and also don't need to record names more than once for our purposes
      // here (hence a plain set). This set can be used to exclude otherwise
      // valid and unambiguous shortcuts, if we regard the existence of another
      // object of the same name - even under an optional or a vector - to have
      // introduced an ambiguity. todo: Consider variants here too!
      std::set<std::string> optvec;

      // Each "child" in the following is of class InfoChildren
      for (const auto &child : current.children) {
         // Path down which we're shortcutting
         std::vector<std::string> path;
         path.push_back(child.name);

         // The "true" in the following call means we haven't already gone
         // through an optional or vector. Which of course we haven't - at
         // this point, because this is the initial call into the recursion.
         down--;
         ShortcutDown(
            specs, child, usednames, path, name2path,
            optvec, title, down, warn, true
         );
         down++;
      }

      // ------------------------
      // Identify unique
      // shortcuts
      // ------------------------

      using namespace color;
      std::set<std::string> reportedAlready;

      // For each potential shortcut as determined above...
      for (const auto &cut : name2path) {
         const std::string &name = cut.first;
         const std::vector<std::string> &path = cut.second;

         // If a shortcut of this name would be ambiguous directly - because
         // another otherwise viable shortcut of the same name exists - then
         // report on this. We arrange to do the reporting just once.
         if (name2path.count(name) > 1) {
            if (warn && reportedAlready.find(name) == reportedAlready.end()) {
               std::cout
                  << title << "   " << custom::faded::yellow
                  << "Shortcut would be ambiguous: "
                  << custom::yellow << name << reset << std::endl;
               title = "";

               auto one = name2path.lower_bound(name);
               auto end = name2path.upper_bound(name);
               while (one != end) {
                  std::cout << "      " << custom::faded::yellow;
                  for (const std::string &field : one->second)
                     std::cout << field << '.';
                  std::cout << custom::yellow << name << reset << std::endl;
                  one++;
               }

               // So we don't print the above message again, for the duplicates
               reportedAlready.insert(name);
            }
            continue;
         }

         // If a shortcut of this name *could* be considered ambiguous because
         // the same name also exists beyond an optional or a vector, then the
         // following code excludes it from being made into a shortcut. We may
         // or may not want to have this condition. Todo: decide on this.
         if (optvec.find(name) != optvec.end()) {
            if (warn && reportedAlready.find(name) == reportedAlready.end()) {
               std::cout
                  << title << "   " << custom::faded::yellow
                  << "Shortcut would be ambiguous vis-à-vis optional/vector: "
                  << custom::yellow << name << reset << std::endl;
               title = "";
               reportedAlready.insert(name);
            }
            continue;
         }

         // Shortcut!
         std::cout << title << custom::blue << "   Shortcut: " << custom::green;
         title = "";
         for (const std::string &field : path)
            std::cout << field << '.';
         std::cout << custom::red << name << reset << std::endl;

         // Remember this shortcut. We'll use it soon,
         // when writing code for the current class.
         current.name2path.insert(cut);
      }
   } // each class in which we're looking for shortcuts
}
