
namespace detail {

// color
inline std::string color(const int r, const int g, const int b)
{
   return "\033[38;2;" +
      std::to_string(r < 0 ? 0 : r > 255 ? 255 : r) + ';' +
      std::to_string(g < 0 ? 0 : g > 255 ? 255 : g) + ';' +
      std::to_string(b < 0 ? 0 : b > 255 ? 255 : b) + 'm';
}


// -----------------------------------------------------------------------------
// diagnostic
// -----------------------------------------------------------------------------

inline std::string diagnostic(
   std::istream &is,
   const std::string &prefix, // possibly a color
   const std::string &label,
   const std::string &message,
   const std::string &suffix, // possibly reset (colors off)
   const bool print_cerr = true // actually print to cerr
) {
   const std::string spaces(indent, ' ');
   std::string result; // for the return value

   // ------------------------
   // label
   // ------------------------

   // for std::cerr only; label won't appear in the return value
   if (print_cerr)
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

   if (&is != &issNone) { // else we're not dealing with any stream
      // save current stream state and position
      const std::istream::iostate currentState = is.rdstate();
      is.clear();
      const std::streampos currentPos = is.tellg();

      // seek to the beginning, to determine line and column
      std::ostringstream oss;
      if (is.seekg(0), is && is.tellg() == 0) { // <== seek must be successful
         // line and column numbers will be 1-indexed, not 0-indexed;
         // we think users will expect this
         usize line = 1, col = 1;
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

      if (print_cerr)
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
   for (usize i = 0; i <= message.size(); ++i) { // "<=", to get \0 terminator
      const char ch = message.data()[i];
      if (ch == '\n' || ch == '\0') {
         if (print_cerr)
            outline == ""
             ? std::cerr << '\n'
             : std::cerr << prefix << spaces << outline << suffix << '\n';
         result += outline + (ch == '\n' ? "\n" : "");
         outline = "";
      } else
         outline += ch;
   }
   if (print_cerr)
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
