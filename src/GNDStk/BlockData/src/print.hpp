
// -----------------------------------------------------------------------------
// print
// Used by Component's prettyprinting.
// -----------------------------------------------------------------------------

std::ostream &print(std::ostream &os, const int level) const
{
   try {

      // If empty, don't even print a newline
      if ((active() == Active::string && rawstring == "") ||
          (active() == Active::vector && size() == 0))
         return os;

      // ------------------------
      // If string is active
      // ------------------------

      if (active() == Active::string) {
         // Print the string exactly as-is, without column formatting
         // or any indentation; then also print a newline
         return GNDStk::colors && color::data::string != ""
            ? os << color::data::string << rawstring << color::reset
                 << std::endl
            : os << rawstring << std::endl;
      }

      // ------------------------
      // If vector is active
      // ------------------------

      // Coloring?
      const bool coloring = GNDStk::colors && color::data::vector != "";

      // Indentation (string, with some number of spaces)
      const std::string indent(GNDStk::indent*level,' ');

      const auto printLambda =
         [&os,&indent,coloring](auto &&alt)
         {
            using T = std::decay_t<decltype(alt[0])>;
            const size_t size = alt.size();
            const size_t end = (GNDStk::elements < 0)
               ? size
               : std::min(size,size_t(GNDStk::elements));

            // Print, using column formatting
            for (size_t i = 0; i < end; ++i) {
               const T &element = alt[i];

               // value's whitespace prefix
               i == 0
                  ? os << indent // at the very beginning, or...
                  : GNDStk::columns <= 0 ||
                    i % size_t(GNDStk::columns) != 0
                  ? os << ' ' // still on the current line, or...
                  : os << '\n' << indent; // starting the next line

               // value
               using namespace detail;
               if (coloring) os << color::data::vector;
               if constexpr (std::is_floating_point_v<T>)
                  os << Precision<PrecisionContext::data,T>{}.write(element);
               else
                  os << element;
               if (coloring) os << color::reset;
            };

            // If applicable, print a message saying the data were truncated
            if (end < size) {
               if (end > 0)
                  os << '\n';
               os << indent << detail::colorize_comment(
                 "truncated; actual #elements == " + std::to_string(size),
                  color::data::vector
               );
            }
         };

      if constexpr (runtime)
         std::visit(printLambda,variant);
      else
         printLambda(vector);

      return os << std::endl;

   } catch (...) {
      log::member("BlockData.print()");
      throw;
   }
}
