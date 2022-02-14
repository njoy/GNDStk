
// -----------------------------------------------------------------------------
// JSON
// Wraps nlohmann::ordered_json
// -----------------------------------------------------------------------------

class JSON {
public:
   nlohmann::ordered_json doc;

   // clear
   JSON &clear()
   {
      doc.clear();
      return *this;
   }

   // empty
   bool empty() const
   {
      return doc.size() == 0;
   }

   // constructors, assignment
   #include "GNDStk/JSON/src/ctor.hpp"
   JSON &operator=(JSON &&) = default;
   JSON &operator=(const JSON &) = default;

   // read, write
   #include "GNDStk/JSON/src/read.hpp"
   #include "GNDStk/JSON/src/write.hpp"

}; // class JSON



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, JSON &obj)
{
   try {
      return obj.read(is);
   } catch (...) {
      log::function("istream >> JSON");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const JSON &obj)
{
   try {
      return obj.write(os);
   } catch (...) {
      log::function("ostream << JSON");
      throw;
   }
}
