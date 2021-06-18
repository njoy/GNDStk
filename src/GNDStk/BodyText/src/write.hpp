
// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level) const
{
   if (remake || (size() == 0 && rawstring != ""))
      get();

   if (size() == 0)
      return os;

   std::visit(
      [&os,level](auto &&alt)
      {
         const auto indent = std::string(GNDStk::indent*level,' ');
         std::size_t count = 0;

         for (auto &element : alt) {
            count == 0
               ? os << indent
               : GNDStk::across == 0 || count % GNDStk::across
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
