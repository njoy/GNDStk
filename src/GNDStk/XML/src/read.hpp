
// -----------------------------------------------------------------------------
// XML.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call pugi::xml_document's read capability
   try {
      // load
      const pugi::xml_parse_result load = doc.load(
         is,
         pugi::parse_default |
         pugi::parse_declaration | // preserve <?xml ...?> material
         pugi::parse_comments      // preserve <!-- comment --> material
      );

      // check for errors
      if (load.description() != std::string("No error")) {
         log::error(
            "pugi::xml_document.load() reported an error:\n"
            "Parse error: {}\n"
            "Char offset: {}",
            load.description(),
            load.offset
         );
         log::member("XML.read(istream)");
         // apparently, pugi doesn't do this if load() fails; so we will:
         is.setstate(std::ios::failbit);
      }
   } catch (...) {
      log::error("pugi::xml_document.load() threw an exception");
      log::member("XML.read(istream)");
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
      log::member("XML.read(\"{}\")", filename);
      return false;
   }

   // read from istream
   if (!read(ifs)) {
      log::member("XML.read(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
