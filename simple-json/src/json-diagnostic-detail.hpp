
namespace detail {

// color
inline std::string color(const int r, const int g, const int b)
{
   return "\033[38;2;" +
      std::to_string(r < 0 ? 0 : r > 255 ? 255 : r) + ';' +
      std::to_string(g < 0 ? 0 : g > 255 ? 255 : g) + ';' +
      std::to_string(b < 0 ? 0 : b > 255 ? 255 : b) + 'm';
} // color

// diagnostic
inline void diagnostic(
   std::istream &is,
   const std::string &message,
   const std::string &label
) {
   static const std::string reset = "\033[0m"; // all colors/decorations off
   const std::string spaces(indent,' ');

   // label
   std::cout << label << '\n';

   // line, if we can compute it
   // The following isn't exactly efficient, but, for better or for worse,
   // C++ streams don't keep track of "line numbers" (insofar as the concept
   // is necessarily meaningful for input streams), and a diagnostic is likely
   // to be of minimal use if we don't provide a viable line number at which
   // someone can look for the problem. :-/ Note also that the efficiency
   // of our line number computation is irrelevant unless errors or warnings
   // occur, at which point we'd hope that the problems would be fixed.
   bool quit = false;
   if (&is != &detail::iss) {
      // back up stream state and position
      const std::istream::iostate oldState = is.rdstate();
      is.clear();
      const std::streampos currentPosition = is.tellg();

      // try to seek to the beginning, to determine and print line and column
      if (is.seekg(0), is && is.tellg() == 0) { // <== seek must be successful
         size_t line = 1, column = 1; std::streampos pos; int ch;
         while ((ch = is.get(), pos = is.tellg()) >= 0 && pos < currentPosition)
            if (ch == '\n') {
               ++line;
               column = 1;
            } else
               ++column;
         std::cout << spaces << "Around line " << line << ", column "
                   << column << ".\n";
      } else
         std::cout << spaces << "Undetermined line and column.\n";

      // restore stream state and position
      is.clear();
      quit = (is.seekg(currentPosition),
              !(is && is.tellg() == currentPosition));
      is.setstate(oldState);
   }

   // message
   std::cout << spaces;
   for (const char &ch : message)
      std::cout << ch << (ch == '\n' ? spaces : "");
   std::cout << reset << std::endl;

   if (quit)
      error("Unable to recover. istream.seekg() failed after attempt\n"
            "to determine line number for previous diagnostic.");
} // diagnostic

} // namespace detail
