
// -----------------------------------------------------------------------------
// XML
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

class XML {
public:

   // external XML-library document
   pugi::xml_document doc;

   // clear
   XML &clear()
   {
      doc.reset();
      return *this;
   }

   // empty
   bool empty() const
   {
      return doc.end() == doc.begin();
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
      return obj.read(is);
   } catch (...) {
      log::function("istream >> XML");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const XML &obj)
{
   try {
      return obj.write(os);
   } catch (...) {
      log::function("ostream << XML");
      throw;
   }
}
