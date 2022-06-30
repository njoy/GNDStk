
// -----------------------------------------------------------------------------
// HDF5 Assignment
// -----------------------------------------------------------------------------

// move
HDF5 &operator=(HDF5 &&other)
{
   clear();

   filePtr  = std::move(other.filePtr);
   fileDesc = std::move(other.fileDesc);

   other.filePtr  = nullptr;
   other.fileDesc = 0;

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
