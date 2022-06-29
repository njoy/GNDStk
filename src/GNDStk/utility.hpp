
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
   // default, automagick, etc.
   null,
   // our plain text format (for writing only)
   text,
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

#include "GNDStk/utility/src/detail.hpp"



// -----------------------------------------------------------------------------
// Miscellaneous output/printing related flags
// -----------------------------------------------------------------------------

// ------------------------
// re: Component class
// ------------------------

// Should Component's generic write() function print comments?
inline bool comments = true;

// For printing.
// When writing a Component with its generic write() function (or its stream
// output, which uses write()), AND the Component is based on a BlockData with
// hasBlockData == true, values will be printed with GNDStk::columns across.
// "columns" is aliased to "across" for convenience, because, at the time of
// this writing, GNDStk has a Meta<> object, named "columns", which would also
// be in scope if the core namespace is used. So, a user might prefer to use
// the name "across".
inline std::size_t columns = 4;
inline std::size_t &across = columns;



// -----------------------------------------------------------------------------
// Flags for fine-tuning diagnostic output
// -----------------------------------------------------------------------------

// Names of these flags align with those in our log:: functions (see below),
// for consistency and predictability. These are in namespace GNDStk while
// those are in namespace GNDStk::log, so the names don't conflict.

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
inline void info(const std::string &str, Args &&...args)
{
   if (GNDStk::info) {
      const std::string msg = detail::diagnostic("info",str);
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// warning
template<class... Args>
inline void warning(const std::string &str, Args &&...args)
{
   if (GNDStk::warning) {
      const std::string msg = detail::diagnostic("warning",str);
      Log::warning(msg.data(), std::forward<Args>(args)...);
   }
}

// error
template<class... Args>
inline void error(const std::string &str, Args &&...args)
{
   const std::string msg = detail::diagnostic("error",str);
   Log::error(msg.data(), std::forward<Args>(args)...);
}

// debug
template<class... Args>
inline void debug(const std::string &str, Args &&...args)
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
inline void function(const std::string &str, Args &&...args)
{
   if (GNDStk::context) {
      const std::string msg =
         detail::diagnostic("info", "function " + str, "Context");
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// context is a member function
template<class... Args>
inline void member(const std::string &str, Args &&...args)
{
   if (GNDStk::context) {
      const std::string msg =
         detail::diagnostic("info", "member function " + str, "Context");
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// context is a constructor
template<class... Args>
inline void ctor(const std::string &str, Args &&...args)
{
   if (GNDStk::context) {
      const std::string msg =
         detail::diagnostic("info", "constructor " + str, "Context");
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

// context is an assignment operator
template<class... Args>
inline void assign(const std::string &str, Args &&...args)
{
   if (GNDStk::context) {
      const std::string msg =
         detail::diagnostic("info", "assignment " + str, "Context");
      Log::info(msg.data(), std::forward<Args>(args)...);
   }
}

} // namespace log



// -----------------------------------------------------------------------------
// Forward declarations: some classes; convert
// We're not fans of having lots of forward declarations, but these are here
// because (1) relevant classes (Tree, XML, JSON, HDF5) use these functions in,
// e.g., their constructors, which are defined in-class; and (2) our convert()
// functions in turn work with the classes and thus need the class definitions
// to be available. The alternative would be to mostly define the classes, but
// only declare their constructors; then define the convert()s; then finally
// define the constructors. We think the forward declarations are clearer.
// -----------------------------------------------------------------------------

// Node, Tree
class Node;
class Tree;

// XML, JSON, HDF5
class XML;
class JSON;
class HDF5;

// Node to {XML,JSON,HDF5}
bool convert(const Node &, XML  &);
bool convert(const Node &, JSON &);
bool convert(const Node &, HDF5 &, const std::string & = "");

// Tree to {Tree,XML,JSON,HDF5}
bool convert(const Tree &, Tree &);
bool convert(const Tree &, XML  &);
bool convert(const Tree &, JSON &);
bool convert(const Tree &, HDF5 &);

// XML to {Node,Tree,XML,JSON,HDF5}
bool convert(const XML  &, Node &, const bool = false);
bool convert(const XML  &, Tree &);
bool convert(const XML  &, XML  &);
bool convert(const XML  &, JSON &);
bool convert(const XML  &, HDF5 &);

// JSON to {Node,Tree,XML,JSON,HDF5}
bool convert(const JSON &, Node &, const bool = false);
bool convert(const JSON &, Tree &);
bool convert(const JSON &, XML  &);
bool convert(const JSON &, JSON &);
bool convert(const JSON &, HDF5 &);

// HDF5 to {Node,Tree,XML,JSON,HDF5}
bool convert(const HDF5 &, Node &, const bool = false);
bool convert(const HDF5 &, Tree &);
bool convert(const HDF5 &, XML  &);
bool convert(const HDF5 &, JSON &);
bool convert(const HDF5 &, HDF5 &);



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

// null
inline bool eq_null(const std::string &str)
{
   return
      nocasecmp(str,"null") || str == "";
}

// tree
inline bool eq_text(const std::string &str)
{
   return
      nocasecmp(str,"text");
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
