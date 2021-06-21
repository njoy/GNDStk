
// -----------------------------------------------------------------------------
// write
// To an ostream (not to a Node; that a different thing)
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level) const
{
   // ------------------------
   // remake == true
   // ------------------------

   if (remake) {
      // This (remake == true) means we're primed to remake a vector from the
      // raw string, if and when a caller get()s a vector or vector element.
      // BUT: here, in write(), we will NOT trigger a vector remake! Instead,
      // we consider the raw string to be "active" at this point (essentially,
      // that's why remake == true), and we'll print it instead. Also, here,
      // we ignore the columns (a.k.a. across) variable. In short, we write
      // the raw string exactly as-is.
      return os << rawstring << std::endl;
   }

   // ------------------------
   // remake == false
   // ------------------------

   // Meaning: a vector in the variant, not the raw string, is "active" now

   // If empty, don't even write the std::endl
   if (size() == 0)
      return os;

   // Indentation (some number of spaces)
   const auto indent = std::string(GNDStk::indent*level,' ');

   std::visit(
      [&os,&indent](auto &&alt)
      {
         std::size_t count = 0;

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
