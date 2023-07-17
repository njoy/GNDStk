
// -----------------------------------------------------------------------------
// HDF5.read()
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// read(istream)
// -----------------------------------------------------------------------------

std::istream &read(std::istream &is)
{
   static const std::string context = "HDF5.read(istream)";

#ifdef GNDSTK_DISABLE_HDF5

   (void)is;
   log::error(
      "We can't perform the action " + context + ", because the code\n"
      "has been compiled with HDF5 disabled (macro GNDSTK_DISABLE_HDF5).");
   log::function(context);
   throw std::exception{};

#else

   static const std::string context_tmp = context + " (uses a temporary file)";

   // Clear present contents.
   clear();

   // Re: temporary file.
   int desc;
   const std::string name = temporaryName(desc);

   // Open temporary file. This *should* work, but we check anyway.
   std::ofstream ofs(name, std::ios::binary);
   if (!ofs) {
      log::error("Could not open temporary file \"{}\"", name);
      log::member(context_tmp);
      return is;
   }

   // Current stream position. We'll rewind to this point if an error occurs.
   // Of course it's probably at 0 - I doubt we'd be dealing with HDF5 content
   // that's mixed with something else - but we do the following elsewhere and
   // will be consistent with that behavior here.
   const std::streampos pos = is.tellg();

   // Copy the istream's bytes to the temporary file. We copy all bytes,
   // so we suppose something might go awry if someone somehow attached
   // non-HDF5 bytes beyond the end (which we can't detect) of the HDF5
   // material. However, that would be a strange thing for someone to do.
   char ch;
   while (is.get(ch) && ofs)
      ofs.put(ch);
   if (!(is.fail() && is.eof() && !is.bad() && ofs.good())) {
      log::error(
         "Error writing istream's contents to temporary file \"{}\"", name);
      log::member(context_tmp);
      detail::failback(is,pos);
      return is;
   }

   ofs.close();
   try {
      filePtr = new HighFive::File(name,modeRead);
      fileDesc = desc;
      is.clear(std::ios_base::eofbit); // as expected
      return is;
   } catch (...) {
      log::error("Call 'new HighFive::File(\"{}\",ReadOnly)' "
                 "threw an exception", name);
   }

   log::member(context_tmp);
   delete filePtr;
   detail::failback(is,pos);
   return is;

#endif
}


// -----------------------------------------------------------------------------
// read(file)
// -----------------------------------------------------------------------------

#ifndef GNDSTK_DISABLE_HDF5
bool read(const std::string &filename)
{
   clear();

   // Test that the file can be opened. The upcoming HighFive::File(...) call
   // does, in fact, open the file. However, a "test open" allows us to provide
   // diagnostics that resemble those that we provide in our read() functions
   // for other file formats.
   std::ifstream ifs(filename, std::ios::binary);
   if (ifs) {
      ifs.close();
      try {
         filePtr = new HighFive::File(filename,modeRead);
         return true;
      } catch (...) {
         log::error("Call 'new HighFive::File(\"{}\",ReadOnly)' "
                    "threw an exception", filename);
      }
   } else
      log::error("Could not open file \"{}\"", filename);

   log::member("HDF5.read(\"{}\")", filename);
   delete filePtr;
   return false;
}
#endif
