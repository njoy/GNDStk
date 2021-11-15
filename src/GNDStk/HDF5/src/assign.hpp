
// -----------------------------------------------------------------------------
// HDF5 Assignment
// -----------------------------------------------------------------------------

// move
HDF5 &operator=(HDF5 &&other)
{
   clear();
   file = std::move(other.file);
   filename = std::move(other.filename);
   temporary = std::move(other.temporary);

   other.file = nullptr;
   other.filename = "";
   other.temporary = false;

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
