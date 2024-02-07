
// -----------------------------------------------------------------------------
// JSON.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   static const std::string context = "JSON.read(istream)";

#ifdef NJOY_GNDSTK_DISABLE_JSON

   (void)is;
   log::error(
      "We can't perform the action " + context + ", because the code\n"
      "has been compiled with JSON disabled (macro NJOY_GNDSTK_DISABLE_JSON).");
   log::function(context);
   throw std::exception{};

#else

   // call orderedJSON's read capability
   const std::streampos pos = is.tellg();
   try {
      if (!(is >> doc)) {
         log::error("istream >> orderedJSON returned with !istream");
         log::member(context);
         detail::failback(is,pos);
      }
   } catch (...) {
      log::error("istream >> orderedJSON threw an exception");
      log::member(context);
      detail::failback(is,pos);
   }

   // done
   return is;

#endif
}


// ------------------------
// read(file)
// ------------------------

#ifndef NJOY_GNDSTK_DISABLE_JSON
bool read(const std::string &filename)
{
   // open file
   std::ifstream ifs(filename);
   if (!ifs) {
      log::error("Could not open file \"{}\" for input", filename);
      log::member("JSON.read(\"{}\")", filename);
      return false;
   }

   // read from istream
   if (!read(ifs)) {
      log::member("JSON.read(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
#endif
