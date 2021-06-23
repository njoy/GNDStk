
// -----------------------------------------------------------------------------
// write
// To an ostream (not to a Node; that a different thing)
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level) const
{
   // ------------------------
   // If string is active
   // ------------------------

   if (active == Active::string) {
      // write string exactly as-is; don't use our column formatting
      GNDStk::color && GNDStk::colors::value != ""
         ? os << colors::value << rawstring << colors::reset
         : os << rawstring;
      return os << std::endl;
   }

   // ------------------------
   // If vector is active
   // ------------------------

   // If empty, don't even write a std::endl
   if (size() == 0)
      return os;

   // Indentation (some number of spaces)
   const auto indent = std::string(GNDStk::indent*level,' ');

   std::visit(
      [&os,&indent](auto &&alt)
      {
         std::size_t count = 0;

         // use our column formatting
         for (auto &element : alt) {
            count == 0
               ? os << indent
               : GNDStk::across == 0 || count % GNDStk::across != 0
               ? os << ' '
               : os << '\n' << indent;

            GNDStk::color && GNDStk::colors::value != ""
               ? os << colors::value << element << colors::reset
               : os << element;

            count++;
         };
      },
      variant
   );

   return os << std::endl;
}
