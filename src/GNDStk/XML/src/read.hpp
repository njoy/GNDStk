
// -----------------------------------------------------------------------------
// XML::read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call pugi::xml_document's read capability
   const pugi::xml_parse_result load = doc.load(
      is,
      pugi::parse_default |
      pugi::parse_declaration | // preserve <?xml ...?> material
      pugi::parse_comments      // preserve <!-- comment --> material
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      log::error(
         "An error occurred in XML::read(istream) during its call\n"
         "to pugi::xml_document::load(), which reported the following:\n"
         "Parse error: {}\n"
         "Character offset: {}",
         load.description(),
         load.offset
      );
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
      log::error(
         "Could not open file in call to XML::read(filename=\"{}\")",
         filename
      );
      return false;
   }

   // read from stream
   read(ifs);
   if (!ifs) {
      log::context("XML::read(filename=\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
