
// -----------------------------------------------------------------------------
// XML::read()
// -----------------------------------------------------------------------------

// read(string)
bool read(const std::string &file)
{
   // load the document
   const pugi::xml_parse_result load = doc.load_file(
      file.c_str(),
      pugi::parse_default |
      pugi::parse_declaration | // preserve root <?xml ...?> material
      pugi::parse_comments      // preserve <!-- comment --> material
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      std::cout << "Error loading file: " << file               << std::endl;
      std::cout << "Parse error       : " << load.description() << std::endl;
      std::cout << "Character offset  : " << load.offset        << std::endl;
      // failure
      return false;
   }

   // success
   return true;
}


// read(istream)
std::istream &read(std::istream &is)
{
   // load the document
   const pugi::xml_parse_result load = doc.load(
      is,
      pugi::parse_default |
      pugi::parse_declaration |
      pugi::parse_comments
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      std::cout << "Error loading from stream" << std::endl;
      std::cout << "Parse error       : " << load.description() << std::endl;
      std::cout << "Character offset  : " << load.offset        << std::endl;
   }

   // done
   return is;
}
