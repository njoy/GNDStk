
// -----------------------------------------------------------------------------
// Miscellaneous macros, variables, enums, etc.
// -----------------------------------------------------------------------------

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

// default_*
// These are for internal use only, where we want to determine whether
// certain out-parameters were, or were not, sent to certain functions.
namespace detail {
   // bool
   inline bool default_bool = false;
   inline bool sent(const bool &found)
   {
      return &found != &default_bool;
   }

   // string
   inline std::string default_string = "";
   inline bool sent(const std::string &string)
   {
      return &string != &default_string;
   }
} // namespace detail



// -----------------------------------------------------------------------------
// Shortcuts to njoy::Log functions
// -----------------------------------------------------------------------------

namespace log {

// info
template<class... Args>
inline void info(const std::string &str, Args &&...args)
{
   Log::info(str.c_str(), std::forward<Args>(args)...);
}

// debug
template<class... Args>
inline void debug(const std::string &str, Args &&...args)
{
   Log::debug(str.c_str(), std::forward<Args>(args)...);
}

// warning
template<class... Args>
inline void warning(const std::string &str, Args &&...args)
{
   Log::warning(str.c_str(), std::forward<Args>(args)...);
}

// error
template<class... Args>
inline void error(const std::string &str, Args &&...args)
{
   Log::error(str.c_str(), std::forward<Args>(args)...);
}

// context
// For certain particular calls to Log::info()
template<class... Args>
inline void context(const std::string &str, Args &&...args)
{
   log::info(("Context: " + str).c_str(), std::forward<Args>(args)...);
}

} // namespace log



// -----------------------------------------------------------------------------
// Forward declarations: some classes
// These are needed for the upcoming forward declarations of convert().
// -----------------------------------------------------------------------------

#define GNDSTK_DEFAULT_CONTAINER std::vector

// Node, node
template<
   template<class...> class = GNDSTK_DEFAULT_CONTAINER,
   template<class...> class = GNDSTK_DEFAULT_CONTAINER
>
class Node;
using node = Node<>;

// Tree, tree
template<
   template<class...> class = GNDSTK_DEFAULT_CONTAINER,
   template<class...> class = GNDSTK_DEFAULT_CONTAINER
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

// Note: the template arguments below are all CONTAINER types. These template
// arguments are: MONE, CONE, MTWO, CTWO, M, and C. Normally we'd give longer,
// more-descriptive names, as we do elsewhere. These mere forward declarations
// for convert() are, however, shorter and clearer with the abbreviated names.

// Tree to {Tree,XML,JSON}
template<template<class...> class MONE, template<class...> class CONE,
         template<class...> class MTWO, template<class...> class CTWO>
bool convert(const Tree<MONE,CONE> &, Tree<MTWO,CTWO> &);

template<template<class...> class M, template<class...> class C>
bool convert(const Tree<M,C> &, XML &);

template<template<class...> class M, template<class...> class C>
bool convert(const Tree<M,C> &, JSON &);

// XML to {Tree,XML,JSON}
template<template<class...> class M, template<class...> class C>
bool convert(const XML &, Tree<M,C> &);
bool convert(const XML &, XML  &);
bool convert(const XML &, JSON &);

// JSON to {Tree,XML,JSON}
template<template<class...> class M, template<class...> class C>
bool convert(const JSON &, Tree<M,C> &);
bool convert(const JSON &, XML  &);
bool convert(const JSON &, JSON &);



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace (which enclosed the #include of this file).
// -----------------------------------------------------------------------------

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &filename)
{
   std::ifstream ifs(
      filename.c_str(),
      std::ifstream::ate | std::ifstream::binary
   );
   return ifs.tellg();
}

// endsin
// C++20 will have an ends_with(); for now we'll have this
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}

// nocasecmp
// Case-insensitive string comparison.
// The old C-language strcasecmp() is nonstandard. A modern, true caseless
// string comparison is actually a tougher nut to crack than meets the eye,
// but the following will suffice for our English-language purposes.
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
      endsin(str,".xml" ) ||
      endsin(str,".XML" );
}

// json
inline bool endsin_json(const std::string &str)
{
   return
      endsin(str,".json") ||
      endsin(str,".JSON");
}

// hdf5
inline bool endsin_hdf5(const std::string &str)
{
   return
      endsin(str,".hdf" ) ||
      endsin(str,".HDF" ) ||
      endsin(str,".h5"  ) ||
      endsin(str,".H5"  ) ||
      endsin(str,".hdf5") ||
      endsin(str,".HDF5") ||
      endsin(str,".he5" ) ||
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
      nocasecmp(str,"null") ||
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
      nocasecmp(str,"hdf" ) ||
      nocasecmp(str,"h5"  ) ||
      nocasecmp(str,"hdf5") ||
      nocasecmp(str,"he5" );
}



// -----------------------------------------------------------------------------
// For some SFINAE
// -----------------------------------------------------------------------------

namespace detail {

// is_oneof
// Is T one of the types in T?
template<class T, class... Ts>
class is_oneof {
public:
   static constexpr bool value = (std::is_same_v<T,Ts> || ...);
};

// oneof
template<class T, class... Ts>
class oneof {
public:
   using type = typename std::enable_if<is_oneof<T,Ts...>::value,T>::type;
};

// isVoid<T>
template<class T>
class isVoid {
};

// isVoid<void>
template<>
class isVoid<void> {
public:
   using type = void;
};

// isNotVoid<T>
template<class T>
class isNotVoid {
public:
   using type = T;
};

// isNotVoid<void>
template<>
class isNotVoid<void> {
};

} // namespace detail
