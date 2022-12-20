
namespace colors {

// -----------------------------------------------------------------------------
// Colors themselves
// -----------------------------------------------------------------------------

// Specific colors:
//    colors::plain::*
//    colors::bold::*
// Reset/clear:
//    colors::reset
// Note that all of these are ANSI color escape sequences. They'll work on many
// terminals, perhaps most, but working isn't guaranteed. GNDStk::color is false
// by default, so colors aren't actually used unless someone sets it to true.

namespace plain {
   inline const std::string
   black   = "\033[30;1m",
   red     = "\033[31;1m",
   green   = "\033[32;1m",
   blue    = "\033[34;1m",
   cyan    = "\033[36;1m",
   magenta = "\033[35;1m",
   purple  = magenta,
   violet  = magenta,
   yellow  = "\033[33;1m",
   white   = "\033[37;1m";
}

namespace bold {
   inline const std::string
   black   = "\033[30;21m",
   red     = "\033[31;21m",
   green   = "\033[32;21m",
   blue    = "\033[34;21m",
   cyan    = "\033[36;21m",
   magenta = "\033[35;21m",
   purple  = magenta,
   violet  = magenta,
   yellow  = "\033[33;21m",
   white   = "\033[37;21m";
}

inline const std::string reset = "\033[0m";



// -----------------------------------------------------------------------------
// For Component printing
// Non-const, so that you can change them if they don't work well with your
// window's color scheme, or if you just prefer something else.
// -----------------------------------------------------------------------------

// Use:
//    colors::part
// Where part is a particular portion of the relevant printed output.
// Available parts appear below. "" means no special color treatment,
// so that users get whatever text color their terminal already uses.

// General labels, and colon separator between label and value
inline std::string label = "";
inline std::string colon = "";

// Component labels, and begin/end curly braces
inline std::string component = plain::magenta;
inline std::string brace     = plain::magenta;

// Vector labels, and begin/end square brackets
inline std::string vector  = plain::yellow;
inline std::string bracket = plain::yellow;

// If optional/defaulted, label (but not curly braces or square brackets,
// where applicable) are modified to these. Both are blue-ish, reflecting
// the general similarities between std::optional and GNDStk::Defaulted.
inline std::string optional  = plain::cyan;
inline std::string defaulted = plain::blue;

// Values in nodes with block data
inline std::string value = plain::white;

// Comments
inline std::string comment = plain::red;

} // namespace colors
