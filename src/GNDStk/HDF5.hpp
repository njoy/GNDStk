
// -----------------------------------------------------------------------------
// HDF5
// Wraps HighFive::File
// -----------------------------------------------------------------------------

class HDF5 {
public:

   // data
   int fileDesc = 0;
   HighFive::File *filePtr = nullptr;
   std::string filename = "";

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

      desc = 0;
      std::string name;

      while (true) {
         name = "GNDStk-tmp-XXXXXX.h5";
         if ((desc = mkstemps(name.data(),3)) > 0)
            break;

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

      /*
      auto ret = unlink(name.data());
      std::cout << "unlink   == " <<        ret         << std::endl;///
      std::cout << "fileDesc == " <<        desc        << std::endl;///
      std::cout << "fileName == " << '"' << name << '"' << std::endl;///
      */

      return name;
   }

   // clear
   HDF5 &clear()
   {
      if (fileDesc > 0 && filePtr)
         filePtr->flush();
      delete filePtr;
      filePtr = nullptr;

      if (fileDesc > 0)
         close(fileDesc);
      fileDesc = 0;

      if (filename != "")
         unlink(filename.data());
      filename = "";

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
