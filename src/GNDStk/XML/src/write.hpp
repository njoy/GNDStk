
// -----------------------------------------------------------------------------
// XML.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os, const bool decl = true) const
{
   // ...fixme Can we prevent pugixml from emitting a newline at the end?
   // ...Concept: output functions shouldn't *assume* that someone who prints
   // ...something wants a newline at the end. A user should explicitly provide
   // ...the \n, std::endl, whatever, if they want that. One might think we'd
   // ...always want the newline for a "large" or "compound" object (the
   // ...printing of which might, in fact, even have internal newlines).
   // ...However, automatically printing a newline makes the behavior
   // ...different from what we expect with "simple" types - int, double, etc.
   // ...Different makes it less predictable, and inconsistent. Print a vector
   // ...of ints, for example, with an explicit newline after each, and we'll
   // ...get one int per line. Print a vector of these XML objects in the same
   // ...way, and we'll get blank lines, in between, if the XML printing takes
   // ...it upon itself to print its own newline. The best behavior, in my
   // ...opinion, is consistent behavior - it's easy to remember. So, then,
   // ...no fluff, either before or after any object being written.

   // call pugi::xml_document's write capability
   try {
      // save
      doc.save(
         os,
         std::string(indent,' ').c_str(),
         decl
          ? pugi::format_default
          : pugi::format_default | pugi::format_no_declaration
      );

      // check for errors
      if (!os) {
         log::error("pugi::xml_document.save(ostream) returned with !ostream");
         log::member("XML.write(ostream)");
      }
   } catch (...) {
      log::error("pugi::xml_document.save(ostream) threw an exception");
      log::member("XML.write(ostream)");
      os.setstate(std::ios::failbit);
   }

   // done
   return os;
}


// ------------------------
// write(file name)
// ------------------------

bool write(const std::string &filename, const bool decl = true) const
{
   // open file
   std::ofstream ofs(filename);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("XML.write(\"{}\")", filename);
      return false;
   }

   // write to ostream
   if (!write(ofs,decl)) {
      log::member("XML.write(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
