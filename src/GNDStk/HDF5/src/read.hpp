
// -----------------------------------------------------------------------------
// HDF5.read()
// -----------------------------------------------------------------------------

/*
DISCUSSION

While this may appear at first glance to be inefficient, our read(istream)
function actually transfers the istream's contents to a temporary file, then
calls read(filename) on the temporary file. That function, in turn, uses the
underlying HighFive HDF5 library's read-from-file capability in order to do the
actual work of providing an interface into HDF5 data.

Normally, one might do the reverse: use read-from-istream as a helper to read-
from-file, with the latter opening the file as an ifstream, then calling the
former to do the heavy lifting. Indeed, our read-from-file functions for XML
and JSON do precisely that.

Here, however, we did things in the seemingly backwards way for the simple
reason that, at the time of this writing, we see no capability in HighFive to
read from an istream! Just to read directly from a file. While we haven't looked
into the details, we think HighFive isn't actually reading the file (or much of
the file) into an internal data structure, as the XML and JSON librarys do, but
instead reads little or nothing, maintains a handle to the file itself (making
the file, in effect, act as a data structure on disk, instead of one in memory),
and then deals with the file when, and only when, someone reads or writes data.

One might ask why we chose to implement this arguably convoluted read-from-
istream at all - as opposed to supporting only read-from-file, given that a file
has to be involved either way. Our reason is simply that we're designing all of
our file-format classes (at present: XML, JSON, and HDF5) to behave as similarly
as possible with one another. This uniformity helps make the code - for all the
formats and throughout GNDStk - look and feel as consistent as possible. This
helps with debugging and testing, and gives users a more-uniform interface.
*/


// -----------------------------------------------------------------------------
// read(istream)
// -----------------------------------------------------------------------------

std::istream &read(std::istream &is)
{
   // Clear present contents.
   clear();

   // Current stream position. We'll rewind to this point if an error occurs.
   // Of course it's probably at 0 - I doubt we'd be dealing with HDF5 content
   // that's mixed with something else - but we do the following elsewhere,
   // and will be consistent with that behavior here.
   const std::streampos pos = is.tellg();

   // Name for temporary file.
   filename = temporaryName();

   try {
      // Open temporary file. This *should* work, but we check anyway.
      std::ofstream ofs(filename, std::ios::binary);
      if (!ofs) {
         log::error("Could not open temporary file \"{}\"", filename);
         throw std::exception{};
      }

      // Copy bytes from the istream to the temporary file. We copy all bytes;
      // so, we suppose that something might go awry if someone somehow attached
      // non-HDF5 bytes beyond the end (which we can't detect) of the HDF5
      // material. But, that would be a very strange thing for someone to do.
      char ch;
      while (is.get(ch) && ofs)
         ofs.put(ch);
      if (!(is.fail() && is.eof() && !is.bad() && ofs.good())) {
         log::error(
           "Error writing istream HDF5 contents to temporary file \"{}\"",
            filename);
         ofs.close();
         throw std::exception{};
      }
      ofs.close();

      // Call read(filename) to read HDF5 content from the temporary file.
      // See our detailed discussion earlier.
      if (!read(filename))
         throw std::exception{};
   } catch (...) {
      log::member("HDF5.read(istream) (uses a temporary file)");
      temporary = true; // possibly after read(filename), which makes it false
      clear(); // which also does removeTemporary()
      detail::failback(is,pos);
      return is;
   }

   // done
   temporary = true; // after read(filename), which makes it false
   is.clear(std::ios_base::eofbit); // as expected
   return is;
}


// -----------------------------------------------------------------------------
// read(file name)
// -----------------------------------------------------------------------------

// The parameter is intentionally by-value, not by-reference, so that it won't
// surreptitiously be set to "" by the clear() call if the actual parameter
// happens to be this->filename - which it is, in fact, if this read() is called
// from the above read(istream). (And, although it's unlikely, someone could
// conceivably make such a call directly instead of through the above read(),
// in for example a scenario where the file might have changed on disk and
// someone wants it to be re-read.) We don't run into a similar problem with
// the XML or JSON read()s, not just because their read(istream)s don't call
// their read(file name)s, but also because they simply do not, at present,
// have std::string member data that might be aliased by a parameter like the
// one below, so that a clear() accidentally clears the parameter.
bool read(const std::string name)
{
   clear();
   filename = name;
   // Note: if this function's name parameter had been by-reference, right here
   // is where we might inadvertently have filename == ""; see the above remark
   bool ret = false;

   // Test that the file can be opened. The upcoming HighFive::File(filename)
   // call does, in fact, open the file. However, this "test open" allows us
   // to provide diagnostics that resemble those that we provide in our read()
   // functions for other file formats.
   std::ifstream ifs(filename, std::ios::binary);
   if (ifs) {
      ifs.close();
      try {
         file = new HighFive::File(filename, modeRead);
         ret = true; // all's well - our "test open," and HighFive's reading
      } catch (...) {
         log::error("file = HighFive::File(filename, ReadOnly)\n"
                    "threw an exception");
      }
   } else
      log::error("Could not open file \"{}\" for input", filename);

   if (!ret) {
      log::member("HDF5.read(\"{}\")", filename);
      clear();
   }

   // done
   temporary = false;
   return ret;
}
