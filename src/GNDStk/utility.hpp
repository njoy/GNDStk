
// -----------------------------------------------------------------------------
// Miscellaneous variables, enums, etc.
// -----------------------------------------------------------------------------

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

// decl
// Should Tree.write() also print the tree's declaration node if it exists?
inline bool decl = false;

// format
enum class format {
   null, // default, automagick, etc.
   tree, // our own simple text format
   // give users easy-to-type lowercase as well as acronym-style uppercase...
   xml,  XML  = xml,
   json, JSON = json,
   hdf5, HDF5 = hdf5
};

// allow
enum class allow {
   one,
   many
};

namespace detail {

// default_*
// These are for internal use only, where we want to determine whether
// certain out-parameters were, or were not, sent to certain functions.

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

// allowable declaration nodes
inline std::set<std::string> AllowedDecl = {
   "xml",
   "json",
   "hdf5",
};

// allowable top-level GNDS nodes
inline std::set<std::string> AllowedTop = {
   // added as they're identified
   // in our child_t class
};

// noFilter
class noFilter {
public:
   template<class NODE>
   bool operator()(const NODE &) const { return true; }
};

} // namespace detail



// -----------------------------------------------------------------------------
// Helper constructs for some simple Log-enhancing pretty-printing
// -----------------------------------------------------------------------------

// align, color
// Users can set these in their own codes
inline bool align = true;  // extra spaces, to line stuff up for easy reading
inline bool color = false; // default: impose no ANSI escape-sequence clutter

namespace detail {

// diagnostic
inline std::string diagnostic(
   const std::string &label,
   const std::string &message,
   const std::string &prefix = ""
) {
   static std::map<std::string,std::string> codes = {
      { "debug",   "\033[37;21m" }, // white
      { "info",    "\033[36;21m" }, // cyan
      { "warning", "\033[33;1m"  }, // yellow
      { "error",   "\033[31;21m" }  // red
   };
   static const std::string under = "\033[4m";  // underline on
   static const std::string unoff = "\033[24m"; // underline off
   static const std::string reset = "\033[0m";  // all color/decorations off
   static const size_t warn = 7; // length of "warning", the longest label

   // full text, including the (possibly underlined) prefix if one was provided
   const std::string text = prefix == ""
    ?  message
    : (color ? under : "") + prefix + (color ? unoff : "") + ": " + message;

   // full text, possibly spaced for alignment
   std::string spaced, indent = std::string(warn+3,' '); // 3 for '[', ']', ' '
   if (align) {
      spaced = std::string(warn > label.size() ? warn-label.size() : 0, ' ');
      for (char c : text)
         spaced += c + (c == '\n' ? indent : "");
   } else
      spaced = text;

   // final message, possibly colorized
   return color ? codes[label] + spaced + reset : spaced;
}

} // namespace detail



// -----------------------------------------------------------------------------
// Shortcuts to njoy::Log functions
// -----------------------------------------------------------------------------

namespace log {

// ------------------------
// The basics
// ------------------------

// info
template<class... Args>
inline void info(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("info",str);
   Log::info(msg.c_str(), std::forward<Args>(args)...);
}

// debug
template<class... Args>
inline void debug(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("debug",str);
   Log::debug(msg.c_str(), std::forward<Args>(args)...);
}

// warning
template<class... Args>
inline void warning(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("warning",str);
   Log::warning(msg.c_str(), std::forward<Args>(args)...);
}

// error
template<class... Args>
inline void error(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("error",str);
   Log::error(msg.c_str(), std::forward<Args>(args)...);
}

// ------------------------
// These invoke info, with
// the intent of providing
// some context information
// ------------------------

// function
template<class... Args>
inline void function(const std::string &str, Args &&...args)
{
   const std::string msg =
      detail::diagnostic("info", "function "+str, "Context");
   Log::info(msg.c_str(), std::forward<Args>(args)...);
}

// member
template<class... Args>
inline void member(const std::string &str, Args &&...args)
{
   const std::string msg =
      detail::diagnostic("info", "member "+str, "Context");
   Log::info(msg.c_str(), std::forward<Args>(args)...);
}

// ctor
template<class... Args>
inline void ctor(const std::string &str, Args &&...args)
{
   const std::string msg =
      detail::diagnostic("info", "constructor "+str, "Context");
   Log::info(msg.c_str(), std::forward<Args>(args)...);
}

// assign
template<class... Args>
inline void assign(const std::string &str, Args &&...args)
{
   const std::string msg =
      detail::diagnostic("info", "assignment "+str, "Context");
   Log::info(msg.c_str(), std::forward<Args>(args)...);
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



// -----------------------------------------------------------------------------
// print_format
// -----------------------------------------------------------------------------

namespace detail {

inline std::string print_format(const format f, const bool brief = false)
{
   return std::string(brief ? "" : "format::") + (
      f == format::null ? "null"
    : f == format::tree ? "tree"
    : f == format::xml  ? "XML"
    : f == format::json ? "JSON"
    : f == format::hdf5 ? "HDF5"
    : "unknown"
   );
}

} // namespace detail
