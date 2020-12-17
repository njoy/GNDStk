
// -----------------------------------------------------------------------------
// Miscellaneous variables, enums, etc.
// -----------------------------------------------------------------------------

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

// decl
// Should Tree.write() also print the tree's declaration node if it exists?
inline bool decl = false;

// file format
enum class file {
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

// failback
inline void failback(std::istream &is, const std::streampos pos)
{
   is.clear();
   is.seekg(pos);
   is.setstate(std::ios::failbit);
}

} // namespace detail



// -----------------------------------------------------------------------------
// Helper constructs for some simple Log-enhancing pretty-printing
// -----------------------------------------------------------------------------

// align, color
// Users can set these in their own codes.
// Remember that they're scoped in njoy::GNDStk, like other things.
inline bool align = true;  // extra spaces, to line stuff up for easy reading
inline bool color = false; // default: impose no ANSI escape-sequence clutter

// fixme A possible concern here is that the alignment, as controlled by the
// align bool, is only applied to the message string that's sent as the first
// parameter to our log:: functions - not to the entire message that might be
// constructed and printed.
//
// Imagine that you wrote:
//
//    log::error("Some information: {}", someStringParameterWithNewlines);
//
// Our log:: functions ultimately forward their own parameters to the external
// Log library for final handling. Before doing so, they process the message
// string ("Some information: {}", in our example above). If align == true,
// they create a *modified* message string - with spacing for alignment after
// any newlines. However, content that arrives through the "{}"s, from other
// parameters, and that has newlines, doesn't get alignment spacing. Someone
// might then see the diagnostic, and believe that our alignment flag is broken.
//
// We should consider solutions to this - ones that don't require replicating
// too much content from the external Log library, and that allow us to still
// take advantage of its convenient "{}" notation for writing parameters. For
// now, a few particular "long" diagnostic messages in GNDStk are formatted
// and printed completely into the format string, so that we avoid this issue.

namespace detail {

// diagnostic
inline std::string diagnostic(
   const std::string &label,
   const std::string &message,
   const std::string &prefix = ""
) {
   static std::map<std::string,std::string> codes = {
      { "info",    "\033[36;21m" }, // cyan
      { "warning", "\033[33;1m"  }, // yellow
      { "error",   "\033[31;21m" }, // red
      { "debug",   "\033[37;21m" }  // white
   };
   static const std::string under = "\033[4m";  // underline on
   static const std::string unoff = "\033[24m"; // underline off
   static const std::string reset = "\033[0m";  // all color/decorations off
   static const std::size_t warn = 7; // length of "warning", the longest label

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

// Convenient, namespace-scope booleans for fine-tuning diagnostic output
inline bool notes     = true;  // general info messages
inline bool warnings  = true;  // warnings
inline bool context   = true;  // any of our context-printing info messages
inline bool debugging = false; // debug calls
// We don't provide a way to suppress errors; too much could go wrong

namespace log {

// ------------------------
// The basics
// ------------------------

// info
template<class... Args>
inline void info(const std::string &str, Args &&...args)
{
   if (notes) {
      const std::string msg = detail::diagnostic("info",str);
      Log::info(msg.c_str(), std::forward<Args>(args)...);
   }
}

// warning
template<class... Args>
inline void warning(const std::string &str, Args &&...args)
{
   if (warnings) {
      const std::string msg = detail::diagnostic("warning",str);
      Log::warning(msg.c_str(), std::forward<Args>(args)...);
   }
}

// error
template<class... Args>
inline void error(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("error",str);
   Log::error(msg.c_str(), std::forward<Args>(args)...);
}

// debug
template<class... Args>
inline void debug(const std::string &str, Args &&...args)
{
   if (debugging) {
      const std::string msg = detail::diagnostic("debug",str);
      Log::debug(msg.c_str(), std::forward<Args>(args)...);
   }
}

// ------------------------
// These invoke info, with
// the intent of providing
// some context information
// ------------------------

// context is a regular function
template<class... Args>
inline void function(const std::string &str, Args &&...args)
{
   if (context) {
      const std::string msg =
         detail::diagnostic("info", "function "+str, "Context");
      Log::info(msg.c_str(), std::forward<Args>(args)...);
   }
}

// context is a member function
template<class... Args>
inline void member(const std::string &str, Args &&...args)
{
   if (context) {
      const std::string msg =
         detail::diagnostic("info", "member "+str, "Context");
      Log::info(msg.c_str(), std::forward<Args>(args)...);
   }
}

// context is a constructor
template<class... Args>
inline void ctor(const std::string &str, Args &&...args)
{
   if (context) {
      const std::string msg =
         detail::diagnostic("info", "constructor "+str, "Context");
      Log::info(msg.c_str(), std::forward<Args>(args)...);
   }
}

// context is an assignment operator
template<class... Args>
inline void assign(const std::string &str, Args &&...args)
{
   if (context) {
      const std::string msg =
         detail::diagnostic("info", "assignment "+str, "Context");
      Log::info(msg.c_str(), std::forward<Args>(args)...);
   }
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

// string (presumably a file name) has an extension?
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
// Re: file format indicators
// These are used in places where we're allowing a user to give a string,
// e.g. "xml", in place of a file format specifier ala enum class file.
// -----------------------------------------------------------------------------

// null
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
// For SFINAE
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// is_oneof
// ------------------------

// Is T either variant<Ts...> itself,
// or one of the Ts...?

// neither
template<class T, class VAR>
class is_oneof {
public:
   static constexpr bool value = false;
};

// variant<Ts...> itself
// Consider the functionality (currently Node::meta() and Node::child()) that
// use is_oneof. (Or, rather, use its sidekick oneof, defined soon.) Invoked
// with a particular type from the variant, a call - say, to meta() - might
// look like n.template meta<type>(M), where n is a node, and M is a meta_t
// with the variant type. In contrast, one could merely write n.meta(M) for
// the full variant, i.e. with no specific member type stipulated. By making
// the is_oneof SFINAE work for the full variant as well, however, not just
// for each of its constituent types, we allow the n.template meta<type>(M)
// form also to work for the full variant type. While the short (and no doubt
// preferred) form would be available even without the following, we choose
// to support consistency by allowing the .template form to be used as well.
// This might prove to be useful if, for instance, someone embeds the call in
// question into a single function template that invokes the long form, while
// indending to support calls of either the full variant or any of its types.
template<class... Ts>
class is_oneof<std::variant<Ts...>, std::variant<Ts...>> {
public:
   static constexpr bool value = true;
};

// possibly one of the Ts...
template<class T, class... Ts>
class is_oneof<T, std::variant<Ts...>> {
public:
   static constexpr bool value = (std::is_same_v<T,Ts> || ...);
};


// ------------------------
// oneof
// ------------------------

template<class T, class VAR>
class oneof {
public:
   using type = typename std::enable_if<is_oneof<T,VAR>::value,T>::type;
};


// ------------------------
// isVoid
// ------------------------

// general
template<class T>
class isVoid {
public:
   static constexpr bool value = false;
};

// void
template<>
class isVoid<void> {
public:
   static constexpr bool value = true;
   using type = void;
};


// ------------------------
// isNotVoid
// ------------------------

// general
template<class T>
class isNotVoid {
public:
   static constexpr bool value = true;
   using type = T;
};

// void
template<>
class isNotVoid<void> {
public:
   static constexpr bool value = false;
};

} // namespace detail



// -----------------------------------------------------------------------------
// print_format
// -----------------------------------------------------------------------------

namespace detail {

inline std::string print_format(const file f, const bool brief = false)
{
   return std::string(brief ? "" : "file::") + (
      f == file::null ? "null"
    : f == file::tree ? "tree"
    : f == file::xml  ? "XML"
    : f == file::json ? "JSON"
    : f == file::hdf5 ? "HDF5"
    : "unknown"
   );
}

} // namespace detail
