
// -----------------------------------------------------------------------------
// JSON.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call nlohmann::json's read capability
   const std::streampos pos = is.tellg();
   try {
      if (!(is >> doc)) {
         log::error("istream >> nlohmann::json returned with !istream");
         log::member("JSON.read(istream)");
         detail::failback(is,pos);
      }
   } catch (...) {
      log::error("istream >> nlohmann::json threw an exception");
      log::member("JSON.read(istream)");
      detail::failback(is,pos);
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
