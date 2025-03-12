
// -----------------------------------------------------------------------------
// HDF5 Assignment
// -----------------------------------------------------------------------------

// move
#ifdef NJOY_GNDSTK_DISABLE_HDF5
HDF5 &operator=(HDF5 &&) = default;
#else
HDF5 &operator=(HDF5 &&other)
{
   clear();

   filePtr  = std::move(other.filePtr);
   fileDesc = std::move(other.fileDesc);

   other.filePtr  = nullptr;
   other.fileDesc = 0;

   return *this;
}
#endif

// copy
#ifdef NJOY_GNDSTK_DISABLE_HDF5
HDF5 &operator=(const HDF5 &) = default;
#else
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
#endif
