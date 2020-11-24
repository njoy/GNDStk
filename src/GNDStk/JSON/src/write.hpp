
// -----------------------------------------------------------------------------
// JSON.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os) const
{
   // call nlohmann::json's write capability
   try {
      // intentional: no << std::endl
      os << std::setw(indent) << doc;

      // check for errors
      if (!os) {
         log::error("ostream << nlohmann::json returned with !ostream");
         log::member("JSON.write(ostream)");
      }
   } catch (...) {
      log::error("ostream << nlohmann::json threw an exception");
      log::member("JSON.write(ostream)");
      os.setstate(std::ios::failbit);
   }

   // done
   return os;
}


// ------------------------
// write(filename)
// ------------------------

bool write(const std::string &filename) const
{
   // open file
   std::ofstream ofs(filename.c_str());
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("JSON.write(\"{}\")", filename);
      return false;
   }

   // write to ostream
   if (!write(ofs)) {
      log::member("JSON.write(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
