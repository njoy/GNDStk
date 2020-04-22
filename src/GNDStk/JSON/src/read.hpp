
// -----------------------------------------------------------------------------
// JSON::read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call nlohmann::json's read capability
   is >> doc;

   // check for errors
   if (!is) {
      njoy::Log::error("Problem during istream >> nlohmann::json");
      detail::context("JSON::read(istream)");
   }

   // done
   return is;

   /*
   if (is.eof ()) std::cout << "eof"  << std::endl;
   if (is.bad ()) std::cout << "bad"  << std::endl;
   if (is.fail()) std::cout << "fail" << std::endl;
   */
}


// ------------------------
// read(filename)
// ------------------------

bool read(const std::string &filename)
{
   // open file
   std::ifstream ifs(filename.c_str());
   if (!ifs) {
      njoy::Log::error(
         "Could not open file in call to JSON::read(filename=\"{}\")",
         filename
      );
      return false;
   }

   // read from stream
   read(ifs);
   if (!ifs) {
      detail::context("JSON::read(filename=\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
