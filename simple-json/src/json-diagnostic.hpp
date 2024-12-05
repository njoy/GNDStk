
// json::exception
struct exception : public std::runtime_error
{
   using runtime_error::runtime_error;
};

// color::
namespace color {
   // rgb()
   inline std::string rgb(const int r, const int g, const int b)
   {
      return "\033[38;2;" +
         std::to_string(r < 0 ? 0 : r > 255 ? 255 : r) + ';' +
         std::to_string(g < 0 ? 0 : g > 255 ? 255 : g) + ';' +
         std::to_string(b < 0 ? 0 : b > 255 ? 255 : b) + 'm';
   }

   // some specific colors
   inline const std::string black    = rgb(   0,   0,   0 );
   inline const std::string white    = rgb( 255, 255, 255 );
   inline const std::string purple   = rgb( 140, 110, 200 );
   inline const std::string green    = rgb(  41, 171, 135 );
   inline const std::string yellow   = rgb( 220, 220,  40 );
   inline const std::string orange   = rgb( 255, 136,  50 );
   inline const std::string red      = rgb( 198,  45,  66 );
   inline const std::string indigo   = rgb(  90, 110, 190 );
   inline const std::string blue     = rgb(   0, 157, 196 );
   inline const std::string cerulean = rgb(  30, 170, 215 );
   inline const std::string cyan     = rgb(  80, 250, 250 );

   // colors/decorations off
   inline const std::string reset = "\033[0m";

   // for JSON content, if colors == true; user changeable (not const)
   inline std::string key     = green;
   inline std::string null    = orange;
   inline std::string boolean = white;
   inline std::string number  = cerulean;
   inline std::string string  = cyan;
   inline std::string array   = yellow;
   inline std::string object  = red;
   inline std::string literal = purple;
}

// error (forward declaration; used in the below detail)
inline void error(const std::string &msg, std::istream *const is = nullptr);


// -----------------------------------------------------------------------------
// diagnostic
// -----------------------------------------------------------------------------

namespace detail {

inline std::string diagnostic(
   std::istream *const isptr,
   const std::string &col, // possibly a color
   const std::string &label,
   const std::string &msg,
   const bool print = true // actually print (else just return std::string)
) {
   const std::string prefix = diagnostics::colors ? col : "";
   const std::string suffix = diagnostics::colors ? color::reset : "";
   const std::string spaces(std::max(0,diagnostics::indent), ' ');
   std::string result; // for the return value

   // ------------------------
   // label
   // ------------------------

   // for std::cerr only; label won't appear in the return value
   if (print)
      std::cerr << prefix << label << suffix << '\n';

   // ------------------------
   // line number and column
   // ------------------------

   // The following isn't exactly efficient, but, for better or for worse,
   // C++ streams don't keep track of "line numbers" (insofar as the concept
   // is necessarily meaningful for general input streams), and a diagnostic
   // would have minimal value without a viable line number at which someone
   // can look for the problem. :-/ Note also that the efficiency of our line
   // number computation is irrelevant unless a warning or error occurs, at
   // which point a user would presumably fix the issue.
   bool quit = false;

   if (isptr != nullptr) { // else we're not dealing with any stream
      std::istream &is = *isptr;
      // save current stream state and position
      const std::istream::iostate currentState = is.rdstate();
      is.clear();
      const std::streampos currentPos = is.tellg();

      // seek to the beginning, to determine line and column
      std::ostringstream oss;
      if (is.seekg(0), is && is.tellg() == 0) { // <== seek must be successful
         // line and column numbers will be 1-indexed, not 0-indexed;
         // we think users will expect this
         size_t line = 1, col = 1;
         std::streampos pos; int ch;

         while ((ch = is.get(), pos = is.tellg()) >= 0 && pos < currentPos)
            if (ch == '\n') {
               ++line;
               col = 1;
            } else
               ++col;

         oss << spaces << "Around line " << line << ", column " << col << '.';
      } else
         oss << spaces << "Undetermined line and column.";

      if (print)
         std::cerr << prefix << oss.str() << suffix << '\n';
      result += oss.str() + '\n';

      // restore current stream state and position
      is.clear();
      quit = (is.seekg(currentPos), !(is && is.tellg() == currentPos));
      is.setstate(currentState);
   }

   // ------------------------
   // message
   // ------------------------

   std::string outline = ""; // as in, "line to send to output"
   for (size_t i = 0; i <= msg.size(); ++i) { // "<=", to get \0 terminator
      const char ch = msg.data()[i];
      if (ch == '\n' || ch == '\0') {
         if (print)
            outline == ""
             ? std::cerr << '\n'
             : std::cerr << prefix << spaces << outline << suffix << '\n';
         result += outline + (ch == '\n' ? "\n" : "");
         outline = "";
      } else
         outline += ch;
   }
   if (print)
      std::cerr << std::flush;

   // ------------------------
   // finish
   // ------------------------

   if (quit)
      error("Unable to recover. istream.seekg() failed after attempt\n"
            "to determine line number for previous diagnostic.");

   return result;
}

} // namespace detail


// -----------------------------------------------------------------------------
// note, warning, error
// -----------------------------------------------------------------------------

// note
// Returns a std::string.
inline std::string
note(const std::string &msg, std::istream *const is = nullptr)
{
   return detail::diagnostic(is, color::blue, "note", msg, notes);
}

// warning
// Returns a std::string.
inline std::string
warning(const std::string &msg, std::istream *const is = nullptr)
{
   return detail::diagnostic(is, color::yellow, "warning", msg, warnings);
}

// error
// Throws a json::exception.
inline void
error(const std::string &msg, std::istream *const is)
{
   throw exception(detail::diagnostic(is, color::red, "error", msg, errors));
}
