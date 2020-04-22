
// -----------------------------------------------------------------------------
// GNDStk::XML
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

class XML {
public:

   // external XML-library document
   pugi::xml_document doc;

   // clear
   void clear()
   {
      doc.reset();
   }

   // constructors, assignment
   #include "GNDStk/XML/src/ctor.hpp"
   #include "GNDStk/XML/src/assign.hpp"

   // read, write
   #include "GNDStk/XML/src/read.hpp"
   #include "GNDStk/XML/src/write.hpp"

}; // class XML



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, XML &obj)
{
   try {
      obj.read(is);
   } catch (const std::exception &) {
      detail::context("istream >> XML");
      throw;
   }
   return is;
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const XML &obj)
{
   try {
      obj.write(os);
   } catch (const std::exception &) {
      detail::context("ostream << XML");
      throw;
   }
   return os;
}
