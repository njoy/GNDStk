
// -----------------------------------------------------------------------------
// Miscellaneous variables, enums, etc.
// -----------------------------------------------------------------------------

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

inline std::string indentTo(const int level)
{
   return std::string(GNDStk::indent*level,' ');
}

// parents
// Should Node's debugging output print addresses and parent-node addresses?
inline bool parents = false;

// file type / format
enum class FileType {
   // default: guess from file magic number (input) or extension (output)
   guess,
   // our plain-text "debug format"; for writing only (not reading)
   debug,
   // give users easy-to-type lowercase as well as acronym-style uppercase...
   xml,  XML  = xml,
   json, JSON = json,
   hdf5, HDF5 = hdf5
};

// Allow
enum class Allow {
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
   "#xml",
   "#json",
   "#hdf5",
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
// Helper constructs for some simple Log-enhancing prettyprinting
// -----------------------------------------------------------------------------

// align, color
// Users can set these in their own codes.
// Remember that they're scoped in njoy::GNDStk, like other things.
inline bool align = true;  // extra spaces, to line stuff up for easy reading
inline bool color = false; // default: impose no ANSI escape-sequence clutter

namespace detail {

// diagnostic
inline std::string diagnostic(
   const std::string &label,
   const std::string &message,
   const std::string &prefix = ""
) {
   // Remark. Below, if align == true, we place spaces after any newlines that
   // appear in the message, so that output that would otherwise:
   //    [error] look something
   //    like this
   // will instead:
   //    [error] look something
   //            like this
   // Later, in functions like our error() and warning(), strings returned from
   // this present (diagnostic()) function are sent to one of the Log:: library
   // functions. Those replace instances of "{}" with the values of parameters,
   // similarly to how the old C-language printf() replaces "%". The code below
   // just does the alignment business for the message string, not for any of
   // those additional parameters. In the event that one of those is a string,
   // and has newlines, alignment may not be as one might initially expect. So,
   // this is just something to be aware of.

   static std::map<std::string,std::string> codes = {
      { "info",    "\033[36;21m" }, // cyan
      { "warning", "\033[33;1m"  }, // yellow
      { "error",   "\033[31;21m" }, // red
      { "debug",   "\033[37;1m"  }  // white
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

// context
inline std::string context(const std::string &type, const std::string &name)
{
   return diagnostic("info", type + " " + name, "Context");
}

} // namespace detail



// -----------------------------------------------------------------------------
// Miscellaneous output/printing related flags
// -----------------------------------------------------------------------------

// ------------------------
// re: Component class
// ------------------------

// Should Component's generic write() function print comments?
inline bool comments = true;

// For printing.
//
// Applicable when writing a Component with its "prettyprinting" generic write()
// function - or with its stream output, which uses its generic write().
//
// If the Component is based on a BlockData with hasBlockData == true, then data
// are printed using GNDStk::columns columns. If columns <= 0, it means to print
// all data on one line.
//
// If the data array's size is large, a user may wish to limit the total number
// of printed values. This can be done with the truncate variable. A value < 0
// means unlimited. All other values, including 0, mean: print no more than that
// number of values.
inline long columns = 4;
inline long truncate = -1;



// -----------------------------------------------------------------------------
// Flags for fine-tuning diagnostic output
// -----------------------------------------------------------------------------

// Names of these flags reflect names in our log:: functions (see below), for
// consistency and predictability. These flags are in namespace GNDStk, while
// those are in namespace GNDStk::log; so, the names don't conflict.

// Print info messages? (with log::info())
inline bool info = true;

// Print warnings? (with log::warning())
inline bool  warning  = true;
inline bool &warnings = warning; // alias; plural may "read" better

// Print debug messages? (with log::debug())
inline bool debug = false;

// Print context information? This affects all of these:
// log::function()
// log::member()
// log::ctor()
// log::dtor()
// log::assign()
inline bool context = true;

// We don't provide a way to suppress errors; too much could go wrong



// -----------------------------------------------------------------------------
// Shortcuts to njoy::Log functions
// -----------------------------------------------------------------------------

namespace log {

// ------------------------
// The basics
// ------------------------

// info
template<class... Args>
void info(const std::string &str, Args &&...args)
{
   if (GNDStk::info) {
      const std::string msg = detail::diagnostic("info",str);
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// warning
template<class... Args>
void warning(const std::string &str, Args &&...args)
{
   if (GNDStk::warning) {
      const std::string msg = detail::diagnostic("warning",str);
      Log::warning(msg.data(), std::forward<Args>(args)...);
   }
}

// error
template<class... Args>
void error(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("error",str);
   Log::error(msg.data(), std::forward<Args>(args)...);
}

// debug
template<class... Args>
void debug(const std::string &str, Args &&...args)
{
   if (GNDStk::debug) {
      const std::string msg = detail::diagnostic("debug",str);
      Log::debug(msg.data(), std::forward<Args>(args)...);
   }
}

// ------------------------
// These invoke info, with
// the intent of providing
// some context information
// ------------------------

// context is a regular function
template<class... Args>
void function(const std::string &str, Args &&...args)
{
   if (GNDStk::context)
      Log::info(detail::context("function", str).data(),
                std::forward<Args>(args)...);
}

// context is a member function
template<class... Args>
void member(const std::string &str, Args &&...args)
{
   if (GNDStk::context)
      Log::info(detail::context("member function", str).data(),
                std::forward<Args>(args)...);
}

// context is a constructor
template<class... Args>
void ctor(const std::string &str, Args &&...args)
{
   if (GNDStk::context)
      Log::info(detail::context("constructor", str).data(),
                std::forward<Args>(args)...);
}

// context is a destructor
template<class... Args>
void dtor(const std::string &str, Args &&...args)
{
   if (GNDStk::context)
      Log::info(detail::context("destructor", str).data(),
                std::forward<Args>(args)...);
}

// context is an assignment operator
template<class... Args>
void assign(const std::string &str, Args &&...args)
{
   if (GNDStk::context)
      Log::info(detail::context("assignment", str).data(),
                std::forward<Args>(args)...);
}

} // namespace log



// -----------------------------------------------------------------------------
// Forward declarations: some classes; convert
// We're not fans of having lots of forward declarations, but these are here
// because (1) relevant classes use these functions in, for example, their
// constructors, which are defined in-class; and (2) our convert() functions
// in turn work with the classes and thus need the class definitions to be
// available. The alternative would be to mostly define the classes, but only
// declare their constructors; then define the convert()s; then finally define
// the constructors. We think the forward declarations are clearer.
// -----------------------------------------------------------------------------

class Node;
class XML;
class JSON;
class HDF5;

// Node ==> {Node,XML,JSON,HDF5}
bool convert(const Node &, Node &);
bool convert(const Node &, XML  &);
bool convert(const Node &, JSON &);
bool convert(const Node &, HDF5 &, const std::string & = "");

// XML  ==> {Node,XML,JSON,HDF5}
bool convert(const XML  &, Node &, const bool & = detail::default_bool);
bool convert(const XML  &, XML  &);
bool convert(const XML  &, JSON &);
bool convert(const XML  &, HDF5 &);

// JSON ==> {Node,XML,JSON,HDF5}
bool convert(const JSON &, Node &, const bool & = detail::default_bool);
bool convert(const JSON &, XML  &);
bool convert(const JSON &, JSON &);
bool convert(const JSON &, HDF5 &);

// HDF5 ==> {Node,XML,JSON,HDF5}
bool convert(const HDF5 &, Node &, const bool & = detail::default_bool);
bool convert(const HDF5 &, XML  &);
bool convert(const HDF5 &, JSON &);
bool convert(const HDF5 &, HDF5 &);



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace.
// -----------------------------------------------------------------------------

// endsin
// C++20 will have an ends_with(); for now we'll have this
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}

// beginsin
inline bool beginsin(const std::string &str, const std::string &begin)
{
   return strncmp(&str[0], &begin[0], begin.size()) == 0;
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
        endsin(str,".xml" )
     || endsin(str,".XML" );
}

// json
inline bool endsin_json(const std::string &str)
{
   return
        endsin(str,".json")
     || endsin(str,".JSON");
}

// hdf5
inline bool endsin_hdf5(const std::string &str)
{
   return
        endsin(str,".h5"  )
     || endsin(str,".H5"  )
     || endsin(str,".hdf5")
     || endsin(str,".HDF5")
     || endsin(str,".he5" )
     || endsin(str,".HE5" );
}



// -----------------------------------------------------------------------------
// Re: file format indicators
// These are used in places where we're allowing a user to give a string,
// e.g. "xml", in place of a file format specifier ala enum class file.
// -----------------------------------------------------------------------------

// guess
inline bool eq_guess(const std::string &str)
{
   return
      nocasecmp(str,"guess") || str == "";
}

// tree
inline bool eq_debug(const std::string &str)
{
   return
      nocasecmp(str,"debug");
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
        nocasecmp(str,"h5"  )
     || nocasecmp(str,"hdf5")
     || nocasecmp(str,"he5" );
}

inline FileType string2filetype(const std::string &str, bool &matched)
{
   matched = true;
   if (eq_guess(str)) return FileType::guess;
   if (eq_debug(str)) return FileType::debug;
   if (eq_xml  (str)) return FileType::xml;
   if (eq_json (str)) return FileType::json;
   if (eq_hdf5 (str)) return FileType::hdf5;

   matched = false;
   return FileType::guess;
}



// -----------------------------------------------------------------------------
// For SFINAE
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// isVariant
// ------------------------

template<class T>
class isVariant {
public:
   static constexpr bool value = false;
};

template<class... Ts>
class isVariant<std::variant<Ts...>> {
public:
   static constexpr bool value = true;
};

// ------------------------
// isAlternative
// ------------------------

// Is T one of the alternatives in variant<Ts...>?

// no (general case)
template<class T, class VARIANT>
class is_alternative {
public:
   static constexpr bool value = false;
};

// yes
template<class T, class... Ts>
class is_alternative<T,std::variant<Ts...>> {
public:
   static constexpr bool value = (std::is_same_v<T,Ts> || ...);
};

template<class T, class VARIANT>
inline constexpr bool isAlternative =
   is_alternative<T,VARIANT>::value;

// ------------------------
// isAlternativeOrTheVariant
// ------------------------

// Is T one of the alternatives in variant<Ts...>, OR is T == variant<Ts...>
// itself? (Not any variant, but precisely that one.)
//
// Consider the functionality (Node::meta() and Node::child(), at the time of
// this writing) that use this. Invoked with a particular type from the variant,
// a call - say, to meta() - might look like node.template meta<type>(M), where
// M is a Meta<> object with the variant type. In contrast, one could merely
// write node.meta(M) for the full variant, i.e. with no specific alternative
// type stipulated. By making this SFINAE work for the full variant, not just
// for each of its constituent types (as with isAlternative), we allow the
// node.template meta<type>(M) form also to work for the full variant. While
// the short (and no doubt preferred) form would be available even without the
// following, we choose to support consistency by allowing the .template form
// to be used too. This might prove to be useful if, for instance, a user embeds
// the call in question into a single function template that invokes the long
// form, while intending to support calls of either the full variant or any of
// its types.

template<class T, class VARIANT>
class is_alternativeOrTheVariant {
public:
   static constexpr bool value =
      isAlternative<T,VARIANT> || std::is_same_v<T,VARIANT>;
};

template<class T, class VARIANT>
inline constexpr bool isAlternativeOrTheVariant =
   is_alternativeOrTheVariant<T,VARIANT>::value;

// ------------------------
// is_void
// ------------------------

// general
template<class T>
class is_void {
public:
   static constexpr bool value = false;
};

// void
template<>
class is_void<void> {
public:
   static constexpr bool value = true;
   using type = void;
};

// isVoid
template<class T>
inline constexpr bool isVoid = is_void<T>::value;

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


// ------------------------
// isIterable
// ------------------------

// The intention of this traits class is to decide if an object of the given
// type is suitable for use as the range-expression in a range-based for-loop.
// For now, we're just checking that it has a begin() and an end(). This is
// probably sufficient for our needs, and could be relaxed later if necessary.

template<class T, class = void>
class isIterable {
public:
   static constexpr bool value = false;
};

template<class T>
class isIterable<
   T,
   std::void_t<
      decltype(std::declval<T>().begin()),
      decltype(std::declval<T>().end())
   >
> {
public:
   static constexpr bool value = true;
};

} // namespace detail



// -----------------------------------------------------------------------------
// printFormat
// -----------------------------------------------------------------------------

namespace detail {

inline std::string printFormat(const FileType f)
{
   return std::string("FileType::") + (
      f == FileType::guess ? "guess"
    : f == FileType::debug ? "debug"
    : f == FileType::xml   ? "XML"
    : f == FileType::json  ? "JSON"
    : f == FileType::hdf5  ? "HDF5"
    : "unknown"
   );
}

} // namespace detail
