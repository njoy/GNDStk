
needs work...

// -----------------------------------------------------------------------------
// HDF5.read()
// -----------------------------------------------------------------------------

/*
DISCUSSION

While this may seem goofy and inefficient, our read(istream) function actually
transfers the istream's content to a temporary *file*, then calls read(filename)
on the temporary file. That function, in turn, uses the underlying HighFive HDF5
library's read-from-file capability, in order to do the actual work of reading
HDF5 content into an internal data structure.

Normally, one might do the reverse: use a read-from-istream as a helper to a
read-from-file, with the latter opening the file as an ifstream, then calling
the former to do the heavy lifting. Indeed, our read-from-file functions for
XML and JSON do just that.

Here, we did things in the seemingly backwards way for a simple reason: at the
time of this writing, we see no capability in HighFive to read from an istream!
Just to read directly from a file.

One might ask why we chose to implement this arguably convoluted read-from-
istream at all. Our reason: we're intentionally designing all of our file-format
classes (at present: XML, JSON, and HDF5) to "look and feel" as consistent as
possible with one another. This uniformity helps make the code - for all formats
and throughout GNDStk - to look as consistent as reasonably possible. This helps
with debugging and testing, and gives users a more-uniform interface.
*/


// -----------------------------------------------------------------------------
// read(istream)
// -----------------------------------------------------------------------------

/// zzz integrate these fixmes into regular remarks

// fixme
// We may want to detect whether or not the istream is in std::ios::binary
// mode. If it isn't, then copying it absolutely correctly, to a temporary
// file, might be problematic. We'll use get() and put(), below, but could
// something like platform-dependent line endings still be a problem? Play
// around with this to see what's what.

// fixme
// Is there a way to detect if any additional content appears in the istream,
// AFTER the HDF5 content itself? If there is, then - ideally - we should
// truncate the copy-to-temporary-file process after the end of HDF5 content,
// leaving the istream's streampos at that point. (But this situation might
// not realistically arise in practice.)

std::istream &read(std::istream &is)
{
   // Clear present contents.
   clear();

   // Current stream position. We'll rewind to this point if an error occurs.
   const std::streampos pos = is.tellg();

   // Generate a file name that's suitable for safely creating a temporary file.
   // L_tmpnam and tmpnam() are from <cstdio>. In case anyone wonders, we don't
   // need a +1 in the [L_tmpnam] here :-).
   static char buffer[L_tmpnam];
   filename = tmpnam(buffer);
   // fixme Possibly check if tmpnam() is screwy and the file actually exists?

   /*
zzz
Have HDF5::createTemporary()
Should probably make it append .h5
   */

   try {
      // Open temporary file. This *should* work, but we check anyway.
      std::ofstream ofs(filename, std::ios::binary);
      if (!ofs) {
         log::error("Unable to open temporary file \"{}\"", filename);
         throw std::exception{};
      }

      // Copy bytes from the istream to the temporary file.
      char ch;
      while (is.get(ch) && ofs)
         ofs.put(ch);
      ofs.close();
      // fixme Maybe examine/check stream states here.

      // Call read(filename) to read HDF5 content from the temporary file.
      // See our detailed discussion above.
      if (!read(filename))
         throw std::exception{};
   } catch (...) {
      temporary = true; // after read(filename), which makes it false
      removeTemporary();
      log::member("HDF5.read(istream) (uses a temporary file)");
      detail::failback(is,pos);
   }

   // done
   temporary = true; // after read(filename), which makes it false
   assert(!is.bad());
   ///   assert(!is.fail());
   assert(is.eof());
   ///assert(false);

   // zzz above, we should clear is' flags as long as the *only* problems
   // is fail(), *AND* eof() (so that eof is why it failed); I think at
   // least that that's correct.
   is.clear();///for now
   return is;
}


// -----------------------------------------------------------------------------
// read(file name)
// -----------------------------------------------------------------------------

// The parameter is intentionally value, not reference, so that it can't
// be surreptitiously set to "" by the clear() call if the actual parameter
// happens to be this->filename - which it *is*, in fact, if this read()
// is called from the above istream read()! (And, although it's unlikely,
// someone could conceivably make such a call directly instead of through
// the above read(), in for example a scenario where the file might have
// changed on disk and someone wants it to be re-read.) We don't run into
// a similar problem with the XML or JSON read()s, not just because their
// read(istream)s don't call their read(file name)s, but also because they
// simply don't, at present, have std::string member data that might be
// aliased by a parameter like name below, so that a clear() accidentally
// clears the parameter.
bool read(const std::string name)
{
   clear();
   filename = name;
   bool ret = false;

   // Test that the file can be opened. The HighFive::File(filename) call,
   // below, in fact opens and reads the file. This "test open" allows us
   // to provide diagnostics that are similar to those that we provide in
   // our read() functions for other file formats. Note: if this function's
   // name parameter had been by-reference, right here is where we might
   // inadvertently have filename == ""; see the earlier remark!
   std::ifstream ifs(filename, std::ios::binary);
   if (ifs) {
      ifs.close();
      try {
         file = new HighFive::File(filename, HighFive::File::ReadOnly);
         ret = true; // all's well - our "test open" and HighFive's reading
      } catch (...) {
         log::error("file = HighFive::File(filename, ReadOnly)\n"
                    "threw an exception");
      }
   } else
      log::error("Could not open file \"{}\" for input", filename);

   if (!ret)
      log::member("HDF5.read(\"{}\")", filename);

   // done
   temporary = false;
   return ret;
}
