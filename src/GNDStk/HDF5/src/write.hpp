
// -----------------------------------------------------------------------------
// HDF5.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os, const bool decl = true) const
{
   static const std::string context = "HDF5.write(ostream)";

   (void)decl; // unused, at least for now
   char ch;
   os.clear();

   try {
      if (empty()) {
         // This HDF5 object is empty. We'll place "stub" HDF5 output into
         // a temporary file, then read the contents into the ostream. Using
         // a temporary file is necessary here, as it is elsewhere, because
         // HighFive deals directly with files, not with streams.
         int tmpDesc;
         const std::string tmpName = temporaryName(tmpDesc);
         { // scoped, so the HighFive::File is "closed" at the end
            HighFive::File stub(tmpName.data(), modeWrite);
            stub.flush(); // a file should be there now
         }

         // Open the temporary file
         std::ifstream ifs(tmpName, std::ios::binary);
         if (!ifs) {
            log::error("Could not open temporary file \"{}\" "
                       "for writing to ostream", tmpName);
            throw std::exception{};
         }

         // Transfer the temporary file's contents to the ostream
         while (ifs.get(ch) && os)
            os.put(ch);
         const bool good = ifs.fail() && ifs.eof() && !ifs.bad() && os.good();
         ifs.close();

         // Finally, close via tmpDesc. Combined with temporaryName()'s
         // call to unlink(), this should trigger removal of the file.
         close(tmpDesc);

         if (!good) {
            log::error(
              "Error writing temporary file \"{}\"'s contents to ostream",
               tmpName);
            throw std::exception{};
         }

      } else {
         // This HDF5 object is not empty. Writing it to an ostream - this
         // function's purpose - amounts to copying bytes *from* the file to
         // which the HDF5 object refers, *to* the ostream.
         filePtr->flush();

         std::ifstream ifs(filename, std::ios::binary);
         if (!ifs) {
            log::error("Could not open file \"{}\" "
                       "for writing to ostream", filename);
            throw std::exception{};
         }

         // Transfer the file's contents to the ostream
         while (ifs.get(ch) && os)
            os.put(ch);
         const bool good = ifs.fail() && ifs.eof() && !ifs.bad() && os.good();
         ifs.close();

         if (!good) {
            log::error(
              "Error writing file \"{}\"'s contents to ostream",
               filename);
            throw std::exception{};
         }
      }

   } catch (...) {
      log::member(context);
      os.setstate(std::ios::failbit);
   }

   // done
   return os;
}


// ------------------------
// write(file name)
// ------------------------

bool write(const std::string &name, const bool decl = true) const
{
   // Well, I suppose it's possible...
   if (!empty() && name == filename) {
      filePtr->flush();
      return true;
   }

   // Open file
   std::ofstream ofs(name, std::ios::binary);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", name);
      log::member("HDF5.write(\"{}\")", name);
      return false;
   }

   // Write to ostream
   if (!write(ofs,decl)) {
      log::member("HDF5.write(\"{}\")", name);
      return false;
   }

   // Done
   return true;
}
