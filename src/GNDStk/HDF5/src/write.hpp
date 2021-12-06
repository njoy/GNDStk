
// -----------------------------------------------------------------------------
// HDF5.write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os, const bool decl = true) const
{
   (void)decl; // unused
   char ch;

   try {
      if (empty()) {
         static char tempname[L_tmpnam];
         tmpnam(tempname);

         HighFive::File blank(
            tempname,
            HighFive::File::ReadWrite |
            HighFive::File::Create |
            HighFive::File::Truncate
         );
         blank.flush();

         std::ifstream ifs(tempname, std::ios::binary);
         if (!ifs) {
            log::error("Could not open temporary file \"{}\"", tempname);
            throw std::exception{};
         }
         while (ifs.get(ch) && os)
            os.put(ch);

         ifs.close(); // prior to remove...
         if (remove(tempname) != 0) {
            log::error("Could not remove temporary file \"{}\"", tempname);
            throw std::exception{};
         }
      } else {
         std::ifstream ifs(filename, std::ios::binary);
         if (!ifs) {
            log::error("Could not open file \"{}\"", filename);
            throw std::exception{};
         }
         while (ifs.get(ch) && os)
            os.put(ch);
      }
   } catch (...) {
      log::member("HDF5.write(ostream)");
      os.setstate(std::ios::failbit);
   }
   // fixme Maybe examine/check stream states after above copies

   // done
   return os;
}


// ------------------------
// write(file name)
// ------------------------

bool write(const std::string &filename, const bool decl = true) const
{
   // well, I suppose it's possible...
   if (filename == this->filename) {
      temporary = false;
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
