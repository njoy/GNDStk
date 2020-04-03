
// -----------------------------------------------------------------------------
// GNDStk::XML
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

class XML {
public:

   // overall XML document
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
   return obj.read(is);
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const XML &obj)
{
   return obj.write(os);
}
