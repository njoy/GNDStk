
// -----------------------------------------------------------------------------
// HDF5
// Wraps HighFive::File
// -----------------------------------------------------------------------------

class HDF5 {
public:

   // data
   HighFive::File *filePtr = nullptr;
   std::string fileName = "";
   int fileDesc = 0;

   // file modes
   static inline const auto modeRead =
      HighFive::File::ReadOnly;
   static inline const auto modeWrite =
      HighFive::File::ReadWrite |
      HighFive::File::Create |
      HighFive::File::Truncate;

   // temporaryName()
   static std::string temporaryName(int &desc)
   {
      static const int maxTry = 10;
      int count = 0;

      while (true) {
         std::string name = "GNDStk-tmp-XXXXXX.h5";
         if ((desc = mkstemps(name.data(),3)) > 0)
            return name;

         log::warning(
           "Creation of temporary file with mkstemps() failed.\n"
           "Message: \"{}\"",
            strerror(errno)
         );

         if (++count == maxTry) {
            log::error(
              "Maximum number {} of temporary file "
              "creation failures reached; bailing out",
               maxTry
            );
            throw std::exception{};
         }
      }
   }

   // clear
   HDF5 &clear()
   {
      if (filePtr)
         filePtr->flush();

      if (fileDesc > 0) {
         close(fileDesc);
         if (fileName != "") // should be, if (fileDesc > 0)
            unlink(fileName.data());
      }

      fileDesc = 0;
      fileName = "";
      delete filePtr;
      filePtr = nullptr;

      return *this;
   }

   // empty
   bool empty() const
   {
      return filePtr == nullptr;
   }

   // destructor
  ~HDF5()
   {
      clear();
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
