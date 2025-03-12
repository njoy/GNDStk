
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

namespace special {
   inline const char prefix = '#';

   inline const std::string
      any      = prefix + std::string(""),
      decl     = prefix + std::string(""),
      nodename = prefix + std::string("nodename"),
      metadata = prefix + std::string("metadata"),
      cdata    = prefix + std::string("cdata"),
      data     = prefix + std::string("data"),
      self     = prefix + std::string("self"),
      anydata  = cdata + "|" + data, // either
      comment  = prefix + std::string("comment"),
      text     = prefix + std::string("text"),
      xml      = prefix + std::string("xml"),
      json     = prefix + std::string("json"),
      hdf5     = prefix + std::string("hdf5");
}

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

// align, colors
// Users can set these in their own codes.
// Remember that they're scoped in njoy::GNDStk, like other things.
inline bool align  = true; // extra spaces, to line stuff up for easy reading
inline bool colors = true; // default: yes, colors. Switch off if not wanted.

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
   // similarly to how the old C language printf() replaces "%". The code below
   // just does the alignment business for the message string, not for any of
   // those additional parameters. In the event that one of those is a string,
   // and has newlines, alignment may not be as one might initially expect. So,
   // this is just something to be aware of.

   static std::map<std::string,std::string> codes = {
      { "info",    "\033[32;1m" }, // green
      { "warning", "\033[33;1m" }, // yellow
      { "error",   "\033[31;1m" }, // red
      { "debug",   "\033[37;1m" }  // white
   };
   static const std::string under = "\033[4m";  // underline on
   static const std::string unoff = "\033[24m"; // underline off
   static const std::string reset = "\033[0m";  // all colors/decorations off
   static const size_t warn = 7; // length of "warning", the longest label

   // full text, including the (possibly underlined) prefix if one was provided
   const std::string text = prefix == ""
    ?  message
    : (colors ? under : "") + prefix + (colors ? unoff : "") + ": " + message;

   // full text, possibly spaced for alignment
   std::string spaced, indent = std::string(warn+3,' '); // 3 for '[', ']', ' '
   if (align) {
      spaced = std::string(warn > label.size() ? warn-label.size() : 0, ' ');
      for (char c : text)
         spaced += c + (c == '\n' ? indent : "");
   } else
      spaced = text;

   // final message, possibly colored
   return colors ? codes[label] + spaced + reset : spaced;
}

// context
inline std::string context(const std::string &type, const std::string &name)
{
   return diagnostic("info", type + " " + name, "Context");
}

} // namespace detail


// -----------------------------------------------------------------------------
// Miscellaneous flags
// -----------------------------------------------------------------------------

// ------------------------
// re: Component class
// ------------------------

// Should vectors in Component-derived classes be sorted automatically?
inline bool sort = false;

// Should Component's generic print() function print comments?
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
// of printed values. This can be done with the "elements" variable. A value of
// less than 0 means unlimited. All other values, including 0, mean to print no
// more than that number of values.
inline long columns = 4;
inline long elements = -1;


// -----------------------------------------------------------------------------
// Flags for fine-tuning diagnostic output
// -----------------------------------------------------------------------------

// Names of these flags reflect names in our log:: functions (see below), for
// consistency and predictability. These flags are in namespace GNDStk, while
// those are in namespace GNDStk::log; so, the names don't conflict.

// Print info messages? (with log::info())
inline bool notes = true;

// Print warnings? (with log::warning())
inline bool warnings = true;

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
   if (GNDStk::notes) {
      const std::string msg = detail::diagnostic("info",str);
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// warning
template<class... Args>
void warning(const std::string &str, Args &&...args)
{
   if (GNDStk::warnings) {
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

// context (general)
template<class... Args>
void context(const std::string &str, Args &&...args)
{
   if (GNDStk::context) {
      const std::string msg = detail::diagnostic("info",str);
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

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
#ifndef NJOY_GNDSTK_DISABLE_JSON
bool convert(const XML  &, JSON &);
#endif
#ifndef NJOY_GNDSTK_DISABLE_HDF5
bool convert(const XML  &, HDF5 &);
#endif

// JSON ==> {Node,XML,JSON,HDF5}
bool convert(const JSON &, Node &, const bool & = detail::default_bool);
#ifndef NJOY_GNDSTK_DISABLE_JSON
bool convert(const JSON &, XML  &);
bool convert(const JSON &, JSON &);
#ifndef NJOY_GNDSTK_DISABLE_HDF5
bool convert(const JSON &, HDF5 &);
#endif
#endif

// HDF5 ==> {Node,XML,JSON,HDF5}
bool convert(const HDF5 &, Node &, const bool & = detail::default_bool);
#ifndef NJOY_GNDSTK_DISABLE_HDF5
bool convert(const HDF5 &, XML  &);
#ifndef NJOY_GNDSTK_DISABLE_JSON
bool convert(const HDF5 &, JSON &);
#endif
bool convert(const HDF5 &, HDF5 &);
#endif


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
// The old C language strcasecmp() is nonstandard. A modern, true caseless
// string comparison is actually a tougher nut to crack than meets the eye,
// but the following should suffice for our purposes.
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
     || endsin(str,".HE5" )
     || endsin(str,".hdf" )
     || endsin(str,".HDF" );
   // The last two aren't official HDF5 extensions, but we'll allow them. This
   // was motivated by the experience of one of our users, who wrote a file with
   // the .hdf extension. At the time, we didn't recognize .hdf as an allowable
   // HDF5 extention, and so our "file type guesser" fell back on its default:
   // our internal debug-dump format. The user saw the debug dump, and wondered
   // if it was HDF5. (It wasn't.) So, now, we'll write HDF5 when someone calls
   // their file something.hdf or something.HDF. But if that happens, then we'll
   // also print a message about that extension not officially being for HDF5.
}


// -----------------------------------------------------------------------------
// Re: file format indicators
// These are used in places where we're allowing a user to provide a string,
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
     || nocasecmp(str,"he5" )
     || nocasecmp(str,"hdf" ); // not official, but we'll allow
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

// is_void_v
template<class T>
inline constexpr bool is_void_v = std::is_same_v<T,void>;

// is_in_v
// Does T appear in Ts? (gives false if the pack is empty, per fold's || rules)
template<class T, class... Ts>
inline constexpr bool is_in_v = (std::is_same_v<T,Ts> || ...);
template<class T, class... Ts>
inline constexpr bool is_in_v<T,std::variant<Ts...>> = is_in_v<T,Ts...>;

// ------------------------
// isVariant
// ------------------------

template<class T>
struct isVariant {
   static constexpr bool value = false;
};

template<class... Ts>
struct isVariant<std::variant<Ts...>> {
   static constexpr bool value = true;
};

template<class T>
inline constexpr bool isVariant_v = isVariant<T>::value;

template<class T>
using isVariant_t = std::enable_if_t<isVariant_v<T>>;

// ------------------------
// isIterable
// ------------------------

// The intention of this traits class is to decide if an object of the given
// type is suitable for use as the range-expression in a range-based for-loop.
// For now, we're just checking that it has a begin() and an end(). This is
// probably sufficient for our needs, and could be relaxed later if necessary.

template<class T, class = void>
struct isIterable {
   static constexpr bool value = false;
};

template<class T>
struct isIterable<
   T,
   std::void_t<
      decltype(std::declval<T>().begin()),
      decltype(std::declval<T>().end())
   >
> {
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


// -----------------------------------------------------------------------------
// Re: OpenMP
// Completely optional - and turned off by default - to use in GNDStk.
// A user must compile with -fopenmp (g++/clang++) to get OpenMP at all.
// At the moment, what we do with threading is very limited.
// -----------------------------------------------------------------------------

// Number of threads
// Users can set this in their own codes
inline int threads = 1;

namespace detail {

#ifdef _OPENMP
   // get_nthreads()
   inline int get_nthreads()
   {
      const int want = njoy::GNDStk::threads;
      const int have = omp_get_num_procs();

      if (want <= 0)
         return std::max(1,want+have);
      if (want >= have)
         return have;
      return want;
   }

   // set_nthreads()
   inline void set_nthreads(const int nthreads)
   {
      omp_set_num_threads(nthreads);
   }

   // this_thread()
   inline int this_thread()
   {
      return omp_get_thread_num();
   }
#else
   inline int  get_nthreads() { return 1; }
   inline void set_nthreads(const int) { /* nothing */ }
   inline int  this_thread () { return 0; }
#endif

} // namespace detail


// -----------------------------------------------------------------------------
// DataNode
// -----------------------------------------------------------------------------

template<class T, bool preferCDATA = false>
struct DataNode : public T
{
   using T::operator=;
   bool cdata = preferCDATA;

   // constructors
   explicit DataNode(const T &from = T{}) : T(from) { }
   DataNode(const DataNode &from) = default;
   DataNode(DataNode &&from) = default;

   // assignment
   DataNode &operator=(const DataNode &from) = default;
   DataNode &operator=(DataNode &&from) = default;

   // baseObject
   const T &baseObject() const { return *this; }
   T &baseObject() { return *this; }
};
