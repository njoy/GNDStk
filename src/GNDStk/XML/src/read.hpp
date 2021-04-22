
// -----------------------------------------------------------------------------
// XML.read()
// -----------------------------------------------------------------------------

// ------------------------
// read(istream)
// ------------------------

std::istream &read(std::istream &is)
{
   // call pugi::xml_document's read capability
   const std::streampos pos = is.tellg();
   try {
      // load
      const pugi::xml_parse_result load = doc.load(
           is,
           pugi::parse_default
         | pugi::parse_declaration // preserve <?xml ...?> material
         | pugi::parse_comments    // preserve <!-- comment --> material
      );

      // check for errors
      // note: we've noticed that pugi doesn't (or, at least, doesn't
      // always) arrange for !is when pugi::xml_document.load() fails
      const bool pugierr = load.description() != std::string("No error");
      if (pugierr || !is) {
         // print error
         if (pugierr) {
            // pugierr
            log::error(
               "pugi::xml_document.load(istream,...) reported an error:\n"
               "Parse error: {}\n"
               "Char offset: {}",
               load.description(),
               load.offset
            );
         } else {
            // !is
            // given the earlier comment about pugi and !is, it may
            // not be possible to get here, but we'll cover it...
            log::error(
               "pugi::xml_document.load(istream,...) returned with !istream"
            );
         }

         // print context
         log::member("XML.read(istream)");

         // cleanup
         detail::failback(is,pos);
      }
   } catch (...) {
      // print error
      log::error("pugi::xml_document.load() threw an exception");

      // print context
      log::member("XML.read(istream)");

      // cleanup
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
