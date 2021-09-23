
// -----------------------------------------------------------------------------
// write
// To an ostream (not to a Node; that a different thing)
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level) const
{
   // If empty, don't even write a newline
   if ((active == Active::string && rawstring == "") ||
       (active == Active::vector && size() == 0))
      return os;

   // ------------------------
   // If string is active
   // ------------------------

   if (active == Active::string) {
      // write the string exactly as-is, without our column formatting
      // or any indentation; then also write a newline
      GNDStk::color && GNDStk::colors::value != ""
         ? os << colors::value << rawstring << colors::reset
         : os << rawstring;
      return os << std::endl;
   }

   // ------------------------
   // If vector is active
   // ------------------------

   // Indentation (string, with some number of spaces)
   const auto indent = std::string(GNDStk::indent*level,' ');

   const auto writeLambda =
      [&os,&indent](auto &&alt)
      {
         std::size_t count = 0;
         using T = std::decay_t<decltype(alt[0])>;

         // use our column formatting
         for (auto &element : alt) {
            count == 0
               ? os << indent
               : GNDStk::across == 0 || count % GNDStk::across != 0
               ? os << ' '
               : os << '\n' << indent;

            if (GNDStk::color && GNDStk::colors::value != "")
               os << colors::value;

            if constexpr (std::is_floating_point_v<T>)
               os << detail::Precision<detail::PrecisionContext::data,T>{}.
                     write(element);
            else
               os << element;

            if (GNDStk::color && GNDStk::colors::value != "")
               os << colors::reset;

            count++;
         };
      };

   if constexpr (runtime)
      std::visit(writeLambda,variant);
   else
      writeLambda(vector);

   return os << std::endl;
}
