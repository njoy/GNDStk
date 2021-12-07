
// -----------------------------------------------------------------------------
// HDF5.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os, const bool decl = true) const
{
   (void)decl; // unused, at least for now
   char ch;
   os.clear();

   try {
      if (empty()) {
         // This HDF5 object is empty, so we'll create valid "stub" HDF5 output.
         // First, create a temporary stub HDF5 file. We go through this file,
         // not directly into the ostream, because, as we've written elsewhere,
         // the HDF5 library deals directly with files, not with streams. This
         // go-through-a-temporary process thus appears to be necessary.
         const std::string tmpName = temporaryName();
         HighFive::File stub(tmpName.data(), modeWrite);
         stub.flush(); // file should be there now

         // Open the temporary stub file
         std::ifstream ifs(tmpName, std::ios::binary);
         if (!ifs) {
            log::error("Could not open temporary HDF5 file \"{}\" "
                       "for writing to ostream", tmpName);
            throw std::exception{};
         }

         // Transfer the temporary stub file's contents to the ostream
         while (ifs.get(ch) && os)
            os.put(ch);
         const bool good = ifs.fail() && ifs.eof() && !ifs.bad() && os.good();

         // Close and remove the temporary stub file
         ifs.close(); // prior to removal...
         if (remove(tmpName.data()) != 0) {
            log::warning(
              "Could not remove temporary HDF5 file \"{}\"", tmpName);
            log::member("HDF5.write(ostream)");
         }

         if (!good) {
            log::error(
              "Error writing temporary HDF5 file \"{}\"'s contents to ostream",
               tmpName);
            throw std::exception{};
         }

      } else {
         // This HDF5 object is not empty. Writing it to an ostream - this
         // function's purpose - amounts to copying bytes *from* the file to
         // which the HDF5 object refers, *to* the ostream.
         std::ifstream ifs(filename, std::ios::binary);
         if (!ifs) {
            log::error("Could not open HDF5 file \"{}\" "
                       "for writing to ostream", filename);
            throw std::exception{};
         }

         // Transfer the file's contents to the ostream
         while (ifs.get(ch) && os)
            os.put(ch);
         if (!(ifs.fail() && ifs.eof() && !ifs.bad() && os.good())) {
            ifs.close();
            log::error(
              "Error writing HDF5 file \"{}\"'s contents to ostream", filename);
            throw std::exception{};
         }
      }

   } catch (...) {
      log::member("HDF5.write(ostream)");
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
   // well, I suppose it's possible that the file we're wanting to write the
   // HDF5 object to, is the same file the HDF5 object already references...
   if (filename == this->filename) {
      file->flush(); // <== for good measure
      temporary = false; // <== and since filename was specifically asked for
      return true;
   }

   // open file
   std::ofstream ofs(filename, std::ios::binary);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("HDF5.write(\"{}\")", filename);
      return false;
   }

   // write to ostream
   if (!write(ofs,decl)) {
      log::member("HDF5.write(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
