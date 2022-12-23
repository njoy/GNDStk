
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
// Color-related functions
// -----------------------------------------------------------------------------

// makeColor
// Here, not in detail::, because it's possibly of interest to users.
inline std::string makeColor(const int r, const int g, const int b)
{
   return "\033[38;2;" +
      std::to_string(r < 0 ? 0 : r > 255 ? 255 : r) + ";" +
      std::to_string(g < 0 ? 0 : g > 255 ? 255 : g) + ";" +
      std::to_string(b < 0 ? 0 : b > 255 ? 255 : b) + "m";
}

// spectrum
template<class T>
std::string spectrum(
   T min,
   T val,
   T max,
   const std::string &color = ""
) {
   if constexpr (!std::is_arithmetic_v<T>)
      return color; // fallback

   if (max < min)
      std::swap(min,max);
   val = val < min ? min : val > max ? max : val;

   using quad = long double;
   // zzz but deal with max == min
   const T frac = quad(val-min)/(max-min);

   // zzz maybe not quite right...
   const int r = lround(256*frac);
   const int g = lround(128 - 256*std::abs(frac-0.5));
   const int b = lround(256*(1-frac));

   // zzz remember to return something here!

   /*
   zzz

   const int ncol = argc == 1 ? 80 : atoi(argv[1]);
   const int last = ncol == 1 ? 1 : ncol-1;

   for (int col = 0; col < ncol; ++col) {
      const int r = 255*col/last;
      const int g = 255 - std::abs(255*(last-col-col)/last);
      const int b = 255*(last-col)/last;

      std::cout << "\033[48;2;" << r << ";" << g << ";" << b << "m"
                << " " // just print a space
                << "\033[0m";
      std::cout << " " << r << ", " << g << ", " << b << std::endl;
   }
   */

   /*
   zzz c.cc
   #include <cmath>
   #include <iostream>
   #include <sstream>

   int main(const int argc, const char *const *const argv)
   {
      const int ncol = argc == 1 ? 80 : atoi(argv[1]);
      const int last = ncol == 1 ? 1 : ncol-1;

      for (int col = 0; col < ncol; ++col) {
         const int r = 255*(last-col)/last;
         const int g = 255 - std::abs(255*(last-col-col)/last);
         const int b = 255*col/last;

         std::cout << "\033[48;2;" << r << ";" << g << ";" << b << "m"
                   << " " // just print a space
                   << "\033[0m";
         std::cout << " " << r << ", " << g << ", " << b << std::endl;
      }
   }
   */
}


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
inline std::string data = "";

// Comments - both those that we will (optionally) emit, and also those
// that appear in a comment vector<string> in a Component-derived class.
inline std::string comment = plain::red;


// -----------------------------------------------------------------------------
// truecolor
// -----------------------------------------------------------------------------

inline void truecolor()
{
   /*
   static const std::string
      blue    = makeColor( 41, 128, 185),
      green   = makeColor( 39, 174,  96),
      red     = makeColor(218,  68,  83),
      magenta = makeColor(128,  68,  83),
      cyan    = makeColor( 61, 174, 233),
      gray    = makeColor(189, 195, 199);
   */

   static const std::string
      blue    = makeColor( 45, 135, 192),
      green   = makeColor( 39, 174,  96),
      red     = makeColor(218,  68,  83),
      magenta = makeColor(128,  68,  83),
      cyan    = makeColor( 72, 192, 253),
      gray    = makeColor(189, 195, 199);

   label = blue;
   colon = "";
   value = magenta;
   component = blue;
   brace = blue;
   vector = green;
   bracket = green;
   optional = cyan;
   defaulted = cyan;
   data = "";
   comment = red;
}

} // namespace color
