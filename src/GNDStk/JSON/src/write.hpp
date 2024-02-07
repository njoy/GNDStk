
// -----------------------------------------------------------------------------
// JSON.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os = std::cout, const bool decl = true) const
{
   static const std::string context = "JSON.write(ostream)";

#ifdef NJOY_GNDSTK_DISABLE_JSON

   (void)os; (void)decl;
   log::error(
      "We can't perform the action " + context + ", because the code\n"
      "has been compiled with JSON disabled (macro NJOY_GNDSTK_DISABLE_JSON).");
   log::function(context);
   throw std::exception{};

#else

   (void)decl; // unused, at least for now

   // call orderedJSON's write capability
   try {
      // intentional: no << std::endl
      os << std::setw(indent) << doc;

      // check for errors
      if (!os) {
         log::error("ostream << orderedJSON returned with !ostream");
         log::member(context);
      }
   } catch (...) {
      log::error("ostream << orderedJSON threw an exception");
      log::member(context);
      os.setstate(std::ios::failbit);
   }

#endif

   // done
   return os;
}


// ------------------------
// write(file)
// ------------------------

#ifndef NJOY_GNDSTK_DISABLE_JSON
bool write(const std::string &filename, const bool decl = true) const
{
   // open file
   std::ofstream ofs(filename);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("JSON.write(\"{}\")", filename);
      return false;
   }

   // write to the ofstream
   if (write(ofs,decl) << std::endl)
      return true;

   log::member("JSON.write(\"{}\")", filename);
   return false;
}
#endif
