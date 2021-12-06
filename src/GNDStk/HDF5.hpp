
// -----------------------------------------------------------------------------
// HDF5
// Wraps HighFive::File
// -----------------------------------------------------------------------------

class HDF5 {
public:

   // data
   HighFive::File *file = nullptr;
   std::string filename = "";
   mutable bool temporary = false;

private:

   void removeTemporary() const
   {
      if (filename != "" && temporary) {
         std::ifstream ifs(filename);
         if (!ifs)
            return; // apparently removed already, so no need to remove
         ifs.close(); // prior to remove
         if (remove(filename.c_str()) != 0) {
            log::warning(
               "Could not remove temporary file \"{}\"", filename);
            log::member(
               "HDF5::removeTemporary(), with filename \"{}\"", filename);
         }
      }
   }

public:

   // clear
   HDF5 &clear()
   {
      delete file;
      file = nullptr;
      removeTemporary();
      filename = "";
      temporary = false;
      return *this;
   }

   // empty
   bool empty() const
   {
      return file == nullptr;
   }

   // destructor
  ~HDF5()
   {
      delete file;
      removeTemporary();
   }

   // constructors, assignment
   #include "GNDStk/HDF5/src/ctor.hpp"
   #include "GNDStk/HDF5/src/assign.hpp"

   // read, write
   #include "GNDStk/HDF5/src/read.hpp"
   #include "GNDStk/HDF5/src/write.hpp"

}; // class HDF5



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, HDF5 &obj)
{
   try {
      return obj.read(is);
   } catch (...) {
      log::function("istream >> HDF5");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const HDF5 &obj)
{
   try {
      return obj.write(os);
   } catch (...) {
      log::function("ostream << HDF5");
      throw;
   }
}
