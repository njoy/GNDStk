
// -----------------------------------------------------------------------------
// JSON.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call nlohmann::ordered_json's read capability
   const std::streampos pos = is.tellg();
   try {
      if (!(is >> doc)) {
         log::error("istream >> nlohmann::ordered_json returned with !istream");
         log::member("JSON.read(istream)");
         detail::failback(is,pos);
      }
   } catch (...) {
      log::error("istream >> nlohmann::ordered_json threw an exception");
      log::member("JSON.read(istream)");
      detail::failback(is,pos);
   }

   // done
   return is;
}


// ------------------------
// read(file name)
// ------------------------

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
