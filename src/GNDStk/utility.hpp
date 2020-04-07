
// -----------------------------------------------------------------------------
// Macros, variables, enums
// -----------------------------------------------------------------------------

// printval
// printvar
// Are the same, so we don't need to remember the exact terminology.
// Note: intended for internal use during development, not for users,
// so I'm not going to UPPER CASE, or prefix with GNDSTK_.
#define printval(var) std::cout << #var ": [" << var << "]" << std::endl
#define printvar(var) printval(var)

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

// format
enum class format {
   null, // default, automagick, etc.
   tree, // our own simple text format
   xml,
   json,
   hdf5
};

// find
enum class find {
   one,
   all
};

// dummy
// Empty class. We use this here and there, in places where a class is needed
// but isn't relevant in and of itself. E.g., we have a function, and in order
// for it to work properly in a header-only library, it must be either inline
// or templated. If, for whatever reason, we don't want to make it inline,
// then we can make it a function template, and use <dummy>. We could use,
// say, <char> instead, but <dummy> may help us identify these use cases.
class dummy { };

// default_*
// fixme Describe what these are about
namespace detail {
   inline bool default_bool = false;
   inline std::string default_string = "";
}



// -----------------------------------------------------------------------------
// Forward declarations: some classes
// These are needed for the upcoming forward declarations of convert().
// -----------------------------------------------------------------------------

// Node, node
template<
   template<class...> class = std::vector,
   template<class...> class = std::vector
>
class Node;
using node = Node<>;

// Tree, tree
template<
   template<class...> class = std::vector,
   template<class...> class = std::vector
>
class Tree;
using tree = Tree<>;

// XML, JSON
class XML;
class JSON;



// -----------------------------------------------------------------------------
// Forward declarations: convert
// We're not fans of having lots of forward declarations, but these are here
// because (1) the relevant classes (Tree, XML, JSON) use these functions in,
// e.g., their constructors, which are defined in-class; and (2) the convert()
// functions in turn work with the classes and thus need the class definitions
// to be available. The alternative would be to mostly define the classes, but
// only declare their constructors; then define the convert()s; then finally
// define the constructors. We think the forward declarations are clearer.
// -----------------------------------------------------------------------------

// convert
// ...Tree to Tree
// ...Tree to XML
// ...Tree to JSON
// ...XML  to Tree
// ...XML  to XML
// ...XML  to JSON
// ...JSON to Tree
// ...JSON to XML
// ...JSON to JSON


// Tree to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &,
   GNDStk::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   GNDStk::XML &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   GNDStk::JSON &
);


// XML to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::XML &,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const GNDStk::XML &, GNDStk::XML &);
bool convert(const GNDStk::XML &, GNDStk::JSON &);


// JSON to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::JSON &,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const GNDStk::JSON &, GNDStk::XML &);
bool convert(const GNDStk::JSON &, GNDStk::JSON &);



// -----------------------------------------------------------------------------
// Some string constants
// -----------------------------------------------------------------------------

namespace detail {

// For pugi::xml_node_types { node_pcdata, node_cdata, node_comment }
inline const std::string keyword_pcdata  = "body";
inline const std::string keyword_cdata   = "text";
inline const std::string keyword_comment = "comment";

// Aliases
inline const std::string &keyword_body = keyword_pcdata;
inline const std::string &keyword_text = keyword_cdata;

} // namespace detail



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace (which enclosed the #include of this file).
// -----------------------------------------------------------------------------

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &file)
{
   std::ifstream ifs(file.c_str(), std::ifstream::ate | std::ifstream::binary);
   return ifs.tellg();
}

// endsin
// C++20 will have an ends_with(); for now we'll have this
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() and &str[str.size()-end.size()] == end;
}

// nocasecmp
// Case-insensitive string comparison.
// The old C-language strcasecmp() is nonstandard. A modern, true caseless
// string comparison is actually a tougher nut to crack than meets the eye,
// but the following will suffice for our purposes.
inline bool nocasecmp(const std::string &one, const std::string &two)
{
   return std::equal(
      one.begin(), one.end(),
      two.begin(), two.end(),
      [](const char a, const char b) { return tolower(a) == tolower(b); }
   );
}



// -----------------------------------------------------------------------------
// Re: file extensions
// -----------------------------------------------------------------------------

// has filename extension?
inline bool has_extension(const std::string &str)
{
   return str.find('.') != std::string::npos;
}

// xml
inline bool endsin_xml(const std::string &str)
{
   return
      endsin(str,".xml" ) or
      endsin(str,".XML" );
}

// json
inline bool endsin_json(const std::string &str)
{
   return
      endsin(str,".json") or
      endsin(str,".JSON");
}

// hdf5
inline bool endsin_hdf5(const std::string &str)
{
   return
      endsin(str,".hdf" ) or
      endsin(str,".HDF" ) or
      endsin(str,".h5"  ) or
      endsin(str,".H5"  ) or
      endsin(str,".hdf5") or
      endsin(str,".HDF5") or
      endsin(str,".he5" ) or
      endsin(str,".HE5" );
}



// -----------------------------------------------------------------------------
// Re: file type indicators
// These are used in places where we're allowing a user to give a string,
// e.g. "xml", in place of a format specifier ala enum class format.
// -----------------------------------------------------------------------------

// null
// Goofy, perhaps, but we'd like to be consistent with enum class format
inline bool eq_null(const std::string &str)
{
   return
      nocasecmp(str,"null") or
      str == "";
}

// tree
inline bool eq_tree(const std::string &str)
{
   return
      nocasecmp(str,"tree");
}

// xml
inline bool eq_xml(const std::string &str)
{
   return
      nocasecmp(str,"xml");
}

// json
inline bool eq_json(const std::string &str)
{
   return
      nocasecmp(str,"json");
}

// hdf5
inline bool eq_hdf5(const std::string &str)
{
   return
      nocasecmp(str,"hdf" ) or
      nocasecmp(str,"h5"  ) or
      nocasecmp(str,"hdf5") or
      nocasecmp(str,"he5" );
}



// -----------------------------------------------------------------------------
// For debugging
// fixme Remove this goofy looking stuff at some point
// -----------------------------------------------------------------------------

namespace detail {

// re: node::meta()
inline const std::string nm01 =
 "01. nm: (        string                                 &) const";
inline const std::string nm02 =
 "02. nm: (        string                                 &)";
inline const std::string nm03 =
 "03. nm: (meta_t< RESULT                               > &) const";
inline const std::string nm04 =
 "04. nm: (meta_t< string                               > &) const";
inline const std::string nm05 =
 "05. nm: (meta_t< void                                 > &) const";
inline const std::string nm06 =
 "06. nm: (meta_t< variant<Ts...>                       > &) const";

// re: node::child()
inline const std::string nc07 =
 "07. nc: (        string                                 &) const";
inline const std::string nc08 =
 "08. nc: (        string                                 &)";
inline const std::string nc09 =
 "09. nc: (child_t<RESULT,        one, METADATA,CHILDREN> &) const";
inline const std::string nc10 =
 "10. nc: (child_t<void,          one, METADATA,CHILDREN> &) const";
inline const std::string nc11 =
 "11. nc: (child_t<variant<Ts...>,one, METADATA,CHILDREN> &) const";
inline const std::string nc12 =
 "12. nc: (child_t<RESULT,        all, METADATA,CHILDREN> &) const";
inline const std::string nc13 =
 "13. nc: (child_t<void,          all, METADATA,CHILDREN> &) const";
inline const std::string nc14 =
 "14. nc: (child_t<variant<Ts...>,all, METADATA,CHILDREN> &) const";

// re: node::operator()()
inline const std::string np15 =
 "15. np: (meta_t <RESULT                               > &) const";
inline const std::string np16 =
 "16. np: (child_t<RESULT,        FIND,METADATA,CHILDREN> &) const";
inline const std::string np17 =
 "17. np: (child_t<RESULT,        FIND,METADATA,CHILDREN> &, ...) const";
inline const std::string np18 =
 "18. np: (meta_t <RESULT                               > &)";
inline const std::string np19 =
 "19. np: (child_t<RESULT,        FIND,METADATA,CHILDREN> &)";
inline const std::string np20 =
 "20. np: (child_t<RESULT,        FIND,METADATA,CHILDREN> &, ...)";

// re: tree::meta()
inline const std::string tm21 =
 "21. tm: (        string                                 &) const";
inline const std::string tm22 =
 "22. tm: (        string                                 &)";
inline const std::string tm23 =
 "23. tm: (meta_t< RESULT                               > &) const";
inline const std::string tm24 =
 "24. tm: (meta_t< variant<Ts...>                       > &) const";

// re: tree::child()
inline const std::string tc25 =
 "25. tc: (        string                                 &) const";
inline const std::string tc26 =
 "26. tc: (        string                                 &)";
inline const std::string tc27 =
 "27. tc: (child_t<RESULT,        one, METADATA,CHILDREN> &) const";
inline const std::string tc28 =
 "28. tc: (child_t<void,          one, METADATA,CHILDREN> &) const";
inline const std::string tc29 =
 "29. tc: (child_t<variant<Ts...>,one, METADATA,CHILDREN> &) const";

// re: tree::operator()()
inline const std::string tp30 =
 "30. tp: (meta_t <RESULT                               > &) const";
inline const std::string tp31 =
 "31. tp: (child_t<RESULT,        FIND,METADATA,CHILDREN> &) const";
inline const std::string tp32 =
 "32. tp: (child_t<RESULT,        FIND,METADATA,CHILDREN> &kwd, ...) const";
inline const std::string tp33 =
 "33. tp: (meta_t <RESULT                               > &)";
inline const std::string tp34 =
 "34. tp: (child_t<RESULT,        FIND,METADATA,CHILDREN> &)";
inline const std::string tp35 =
 "35. tp: (child_t<RESULT,        FIND,METADATA,CHILDREN> &kwd, ...)";

} // namespace detail
