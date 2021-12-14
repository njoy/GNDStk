
// -----------------------------------------------------------------------------
// HDF5 Assignment
// -----------------------------------------------------------------------------

// move
HDF5 &operator=(HDF5 &&other)
{
   clear();

   fileDesc = std::move(other.fileDesc);
   filePtr  = std::move(other.filePtr);
   filename = std::move(other.filename);

   other.fileDesc = 0;
   other.filePtr  = nullptr;
   other.filename = "";

   return *this;
}

// copy
HDF5 &operator=(const HDF5 &other)
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("HDF5 = HDF5");
      throw;
   }
   return *this;
}
