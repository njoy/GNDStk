
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
   //    - an optional, or
   //    - a Defaulted
   // but (in contrast with child nodes) can't make it be a vector of metadata.
   // An individual metadatum may be a vector in its own right, as in an XML
   // construct such as <element meta="1 2 3 4"> (so that meta is a vector of
   // integers). We mean here that there isn't a vector of such [meta] entries,
   // and there shouldn't be (XML wouldn't allow it).
   std::string original; // without e.g. the "double" to "Double" change
   std::string name;
   std::string converter;// converter: callable w/operator() string to/from type
   std::string type;     // underlying type
   std::string typeFull; // WITH any optional<> or Defaulted<>
   bool        isOptional;
   // todo Process and use the following - isVector - in order to properly
   // create C interface functions in the event that metadata are vectors. For
   // instance, a metadatum like size="10 20 30" might be something we'd want
   // to implement as a std::vector<int>. In this case, we'd probably want the
   // C interface to have an int* and a size. At the moment, in its current
   // form, the "C interface" generated by the code generator would end up using
   // "std::vector<int>" in the C functions, and that won't actually work if
   // somebody tried to compile them. (C doesn't know about C++ classes.)
   // Elsewhere in the code generator, the ctype_param() and ctype_return()
   // functions essentially recognize std::string and transform it to char* for
   // the C interface. Basically, the point here is that we need to make the
   // transformation more general. It would be impossible to absolutely know,
   // for any old arbitrary C++ type that somebody *could* use for a metadatum,
   // how to do something sensible in C (unless we just used a generic pointer,
   // essentially punting to the C programmer to point to some suitably
   // initialized chunk of memory), but at least we could have the code
   // generator do something reasonable for std::vector<plain old data types>.
   bool        isVector;
   bool        isDefaulted;
   std::string defaultValue;
};

// InfoChildren
struct InfoChildren {
   // A JSON spec can make a child node be:
   //    - an optional, and/or
   //    - a vector
   // but can't make it be a GNDStk::Defaulted. (The use of a default value for
   // child nodes just doesn't exist in the GNDS specifications, even though the
   // concept would seem to make sense.)
   std::string original; // without e.g. the "double" to "Double" change
   std::string name;
   std::string converter;// converter: callable w/operator() Node to/from type
   std::string filter;   // filter: bool callable(const Node &)
   std::string label;    // filter: allow for node lookup by "label" metadatum
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
   std::string sourceF03; // source for the Fortran 2003 interface

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
   // If (and only if) isDataVector, elementType is considered. If it's "", then
   // this is the situation in GNDS in which the type of data residing in a node
   // is to be determined dynamically, via a string metadatum called valueType.
   // If elementType != "" (for example, elementType == "int" or "double"), then
   // elementType stipulates the wanted type.
   bool isDataString; // Example: <foo> This is a free-form text string </foo>
   bool isDataVector; // Example: <foo> 1.2 3.45 6.789 </foo>
   std::string elementType;
   // isDataNode: for convenience: either isDataString; or, isDataVector AND
   // per.elementType is NOT "" (so that we use DataNode instead of BlockData)
   bool isDataNode;
   bool cdata; // prefer "cdata" over plain data?

   // For shortcuts from objects of this class
   std::multimap<std::string,std::vector<std::string>> name2path;
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
   std::string JSONDir;
   std::string Version;
   std::vector<std::string> JSONFiles;
   std::vector<std::pair<std::string,std::vector<std::string>>> Enumerators;

   // Version, but with '_'s in place of '.'s
   std::string VersionUnderscore;

   // Directory-prefixed names
   std::string allPython;  // cpp file for this version's all.python.cpp file
   std::string cppPython;  // cpp file for this version's Python interface
   std::string hppVersion; // hpp file for this version
   std::string hppKey;     // hpp file for this version's Meta and Child keys
   std::string hVersion;   // header file for both C and C++
   std::string cVersion;   // C++ backend source for the C interface

   // Changes to apply to a metadatum's name or a child node's name.
   // Example: "double" (GNDS v2.0, for example, actually has a "double" node)
   // to "Double" for C++.
   std::map<std::string,std::string> mapName;

   // Changes to apply to metadata/attribute type.
   // Examples: "Boolean" to "bool", "interpolation" to "enums::Interpolation".
   // We'll give a string ==> std::string type change as a freebie. :-)
   std::map<std::string,std::string> mapMetaType = {{"string","std::string"}};

   // Changes to apply to metadata/attribute default.
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
   static inline const std::function<
      bool(const NamespaceAndClass &a, const NamespaceAndClass &b)
   > compare =
      [](const NamespaceAndClass &a, const NamespaceAndClass &b)
      {
         // In the event that we display entries in the map, we prefer putting
         // everything in alphabetical order based primarily on the class name,
         // with namespace only a secondary consideration. Someone looking for
         // a class need only consider its name, and not initially worry about
         // what namespace it's in.
         return
            a.clname <  b.clname || (
            a.clname == b.clname &&
            a.nsname <  b.nsname);
      };
   std::map<NamespaceAndClass,PerClass,decltype(compare)> class2data{compare};
}; // InfoSpecs