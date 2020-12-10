
// -----------------------------------------------------------------------------
// JSON.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call nlohmann::json's read capability
   try {
      if (!(is >> doc)) {
         log::error("istream >> nlohmann::json returned with !istream");
         log::member("JSON.read(istream)");
      }
   } catch (...) {
      log::error("istream >> nlohmann::json threw an exception");
      log::member("JSON.read(istream)");
      is.setstate(std::ios::failbit);
   }

   // done
   return is;
}


// ------------------------
// read(filename)
// ------------------------

bool read(const std::string &filename)
{
   // open file
   std::ifstream ifs(filename.c_str());
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
