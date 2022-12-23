
namespace color {

// -----------------------------------------------------------------------------
// Colors themselves
// -----------------------------------------------------------------------------

// Specific colors:
//    color::plain::*
//    color::bold::*
// Reset/clear:
//    color::reset
// All of these are ANSI color escape sequences. They'll work on many terminals,
// perhaps most, but working isn't guaranteed. The GNDStk::colors flag is false
// by default, so that colors aren't used unless a user sets it to true.

namespace plain {
   inline const std::string
   black   = "\033[30;1m",
   red     = "\033[31;1m",
   green   = "\033[32;1m",
   blue    = "\033[34;1m",
   cyan    = "\033[36;1m",
   magenta = "\033[35;1m",
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
//    color::part
// Where part is a particular portion of the relevant printed output.
// Available parts appear below. "" means no special color treatment,
// so that users get whatever text color their terminal already uses.

// Note: the following seemed to work reasonably well on terminal applications
// we tried. One such app, in particular, was "terminator" on a Linux platform.
// We like terminator, because it allows a single terminal window to be split,
// recursively, horizontally or vertically. (Allowing someone to run several
// logically related codes on different command prompts, but within the same
// overall window on their screen.) We noticed, however, that terminator prints
// all of the above-defined bold:: colors not only colored, but underlined as
// well. So, we avoided using bold:: colors below, as we found the underlines
// to be more distracting than helpful.

// General labels, colon separator between label and value, and values
inline std::string label = plain::blue;
inline std::string colon = "";
inline std::string value = plain::magenta;

// Component labels, and their begin/end curly braces
inline std::string component = plain::blue;
inline std::string brace     = plain::blue;

// Vector labels, and their begin/end square brackets
inline std::string vector  = plain::green;
inline std::string bracket = plain::green;

// If optional/defaulted, label (but not curly braces or square brackets,
// where applicable) is modified to these.
inline std::string optional  = plain::cyan;
inline std::string defaulted = plain::cyan;

// Values in nodes with block data
inline std::string data = plain::white;

// Comments - both those that we will (optionally) emit, and also those
// that appear in a comment vector<string> in a Component-derived class.
inline std::string comment = plain::red;

} // namespace color
