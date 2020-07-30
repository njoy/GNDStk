
// -----------------------------------------------------------------------------
// XML::write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os) const
{
   // save
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
   doc.save(os, std::string(indent,' ').c_str());

   // check for errors
   if (!os) {
      log::error("Problem during pugi::xml_document::save(ostream)");
      log::context("XML::write(ostream)");
   }

   // done
   return os;
}


// ------------------------
// write(filename)
// ------------------------

bool write(const std::string &filename) const
{
   // open file
   std::ofstream ofs(filename.c_str());
   if (!ofs) {
      log::error(
         "Could not open file in call to XML::write(filename=\"{}\")",
         filename
      );
      return false;
   }

   // write to stream
   write(ofs);
   if (ofs.fail()) {
      log::context("XML::write(filename=\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
