
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

      // Coloring?
      const bool coloring = GNDStk::colors && GNDStk::color::data != "";

      // ------------------------
      // If string is active
      // ------------------------

      if (active() == Active::string) {
         // Print the string exactly as-is, without our column formatting
         // or any indentation; then also print a newline
         return coloring
            ? os << color::data << rawstring << color::reset << std::endl
            : os << rawstring << std::endl;
      }

      // ------------------------
      // If vector is active
      // ------------------------

      // Indentation (string, with some number of spaces)
      const std::string indent(GNDStk::indent*level,' ');

      const auto printLambda =
         [&os,&indent,coloring](auto &&alt)
         {
            using T = std::decay_t<decltype(alt[0])>;
            const std::size_t size = alt.size();
            const std::size_t end = (GNDStk::truncate < 0)
               ? size
               : std::min(size,std::size_t(GNDStk::truncate));

            // Print, using our column formatting
            for (std::size_t i = 0; i < end; ++i) {
               const T &element = alt[i];

               // value's whitespace prefix
               i == 0
                  ? os << indent // at the very beginning, or...
                  : GNDStk::columns <= 0 ||
                    i % std::size_t(std::abs(GNDStk::columns)) != 0
                  ? os << ' ' // still on the current line, or...
                  : os << '\n' << indent; // starting the next line

               // value
               using namespace detail;
               if (coloring) os << color::data;
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
                  "// truncated; total #values == " + std::to_string(size));
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
