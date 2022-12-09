
// -----------------------------------------------------------------------------
// XML.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os = std::cout, const bool decl = true) const
{
   // Here, pugi::xml_document's save() capability does most of the work.

   try {
      // Unfortunately, pugixml emits a newline at the end of its save().
      // In fact, a general output function shouldn't *assume* that someone
      // who uses it actually wants the newline; it should let a user provide
      // one if they want it. One might think we'd always want a newline for
      // a "large" or "compound" object (the printing of which might, in fact,
      // even have internal newlines). However, automatically printing a
      // terminating newline makes the behavior different from what we expect
      // with "simple" types - int, double, etc. "Different" makes behavior
      // less predictable. Print a vector of ints, with a << std::endl after
      // each int (the usual pattern), and we'll get one int per line. Print
      // a vector of XML objects in the same manner, and we'll get blank lines
      // between values if the XML printing already prints its own newline.
      // Imagine a generic print(vector<T>), where T could be int or XML or
      // whatever else, and you can see the issue. So, we're actually going
      // to circumvent pugixml's presumptuous \n by save()ing to a buffer,
      // then shipping the buffer to the std::ostream, without the \n. This
      // may seem goofy, and it may make the code less efficient (although
      // I'm not seeing that in tests). The upside is, it makes XML objects
      // behave predictably. Write one, and, as with int, double, or other
      // well-mannered objects, you'll get a \n if AND ONLY IF you give it.

      // save to buffer
      std::ostringstream buffer;
      doc.save(
         buffer,
         std::string(indent,' ').data(),
         decl
          ? pugi::format_default
          : pugi::format_default | pugi::format_no_declaration
      );

      // transfer buffer, chucking last character iff it's a newline
      if (buffer) {
         const std::size_t size = buffer.str().size();
         if (size)
            os.write(buffer.str().data(), size-(buffer.str()[size-1] == '\n'));
      }

      // check for errors
      if (!buffer || !os) {
         log::error(!buffer
          ? "pugi::xml_document.save(buffer) returned with !buffer"
          : "ostream.write() returned with !ostream");
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
// write(file)
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
