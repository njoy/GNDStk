
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

   // file modes
   static inline const auto modeRead =
      HighFive::File::ReadOnly;
   static inline const auto modeWrite =
      HighFive::File::ReadWrite |
      HighFive::File::Create |
      HighFive::File::Truncate;

   // temporaryName()
   static std::string temporaryName()
   {
      // Generate a file name that's supposed to be suitable for safely creating
      // a temporary file. L_tmpnam and tmpnam() are from <cstdio>. In case
      // anyone wonders, we don't need a +1 in the [L_tmpnam]. :-)
      static char buffer[L_tmpnam];

      while (true) {
         const std::string name = std::string(tmpnam(buffer)) + ".h5";
         std::ifstream ifs(name, std::ios::binary);
         if (!ifs) // <== as should be the case
            return name;

         // Well that's weird; the tmpnam()-generated file name (admittedly,
         // with our added ".h5") refers to a file that already exists. :-/
         log::info("Generated temporary HDF5 file name \"{}\" "
                   "is already in use.\n"
                   "That's harmless, but it really shouldn't happen.\n"
                   "Generating another name....", name);
      }
   }

private:

   void removeTemporary() const
   {
      if (temporary && filename != "") {
         std::ifstream ifs(filename);
         if (!ifs)
            return; // removed already, or was not there (e.g. creation error)

         ifs.close(); // prior to removal...
         if (remove(filename.data()) == 0)
            return; // remove() succeeded

         log::warning("Could not remove temporary HDF5 file \"{}\"", filename);
         log::member("HDF5::removeTemporary(), with filename \"{}\"", filename);
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
