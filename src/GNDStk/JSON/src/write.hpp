
// -----------------------------------------------------------------------------
// JSON.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os = std::cout, const bool decl = true) const
{
   (void)decl; // unused, at least for now

   // call orderedJSON's write capability
   try {
      // intentional: no << std::endl
      os << std::setw(indent) << doc;

      // check for errors
      if (!os) {
         log::error("ostream << orderedJSON returned with !ostream");
         log::member("JSON.write(ostream)");
      }
   } catch (...) {
      log::error("ostream << orderedJSON threw an exception");
      log::member("JSON.write(ostream)");
      os.setstate(std::ios::failbit);
   }

   // done
   return os;
}


// ------------------------
// write(file)
// ------------------------

bool write(const std::string &filename, const bool decl = true) const
{
   // open file
   std::ofstream ofs(filename);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("JSON.write(\"{}\")", filename);
      return false;
   }

   // write to ostream
   if (!write(ofs,decl)) {
      log::member("JSON.write(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
