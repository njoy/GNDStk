
// -----------------------------------------------------------------------------
// GNDStk::xml
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

class xml {
public:

   // overall xml document
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

}; // class xml



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, xml &obj)
{
   return obj.read(is);
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const xml &obj)
{
   return obj.write(os);
}
