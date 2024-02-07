
// -----------------------------------------------------------------------------
// HDF5.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os = std::cout, const bool decl = true) const
{
   static const std::string context = "HDF5.write(ostream)";

#ifdef NJOY_GNDSTK_DISABLE_HDF5

   (void)os; (void)decl;
   log::error(
      "We can't perform the action " + context + ", because the code\n"
      "has been compiled with HDF5 disabled (macro NJOY_GNDSTK_DISABLE_HDF5).");
   log::function(context);
   throw std::exception{};

#else

   os.clear();
   (void)decl; // unused, at least for now

   try {
      if (empty()) {
         // This HDF5 object is empty. We'll place "stub" HDF5 output into
         // a temporary file, then copy the file's contents to the ostream.
         // A temporary is used here, as it is elsewhere in our HDF5 handling,
         // because HighFive deals directly with files, not with streams.
         int stubDesc;
         const std::string stubName = temporaryName(stubDesc);
         { // scoped, so the HighFive::File is "closed" at the end
            HighFive::File stub(stubName.data(), modeWrite);
            stub.flush(); // a file should be there now
         }

         // Open the temporary file
         std::ifstream ifs(stubName, std::ios::binary);
         if (!ifs) {
            log::error("Could not open temporary file \"{}\" "
                       "for writing to ostream", stubName);
            throw std::exception{};
         }

         // Transfer the temporary file's contents to the ostream
         char ch;
         while (ifs.get(ch) && os)
            os.put(ch);
         const bool good = ifs.fail() && ifs.eof() && !ifs.bad() && os.good();
         ifs.close();

         // Cleanup
         close(stubDesc);
         unlink(stubName.data());

         // Check status
         if (!good) {
            log::error(
              "Error writing temporary file \"{}\"'s contents to ostream",
               stubName);
            throw std::exception{};
         }

      } else {
         // This HDF5 object is not empty. Writing it to an ostream amounts
         // to copying bytes from *filePtr's file to the ostream.
         filePtr->flush();

         std::ifstream ifs(filePtr->getName(), std::ios::binary);
         if (!ifs) {
            log::error(
               "Could not open file \"{}\" (referenced by the HDF5 object)\n"
               "for writing to ostream", filePtr->getName());
            throw std::exception{};
         }

         // Transfer the file's contents to the ostream
         char ch;
         while (ifs.get(ch) && os)
            os.put(ch);
         const bool good = ifs.fail() && ifs.eof() && !ifs.bad() && os.good();
         ifs.close();

         // Check status
         if (!good) {
            log::error(
              "Error writing file \"{}\"'s contents to ostream",
               filePtr->getName());
            throw std::exception{};
         }
      }

   } catch (...) {
      log::member(context);
      os.setstate(std::ios::failbit);
   }

#endif

   // done
   return os;
}


// ------------------------
// write(file)
// ------------------------

#ifndef NJOY_GNDSTK_DISABLE_HDF5
bool write(const std::string &filename, const bool decl = true) const
{
   // In case the given file happens to be the same
   // file that's already referenced by filePtr...
   if (!empty() && filename == filePtr->getName()) {
      filePtr->flush();
      return true;
   }

   // Open file
   std::ofstream ofs(filename, std::ios::binary);
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("HDF5.write(\"{}\")", filename);
      return false;
   }

   // Write to ostream
   if (!write(ofs,decl)) {
      log::member("HDF5.write(\"{}\")", filename);
      return false;
   }

   // Done
   return true;
}
#endif
