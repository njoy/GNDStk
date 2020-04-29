
// -----------------------------------------------------------------------------
// GNDStk::JSON
// Wraps nlohmann::json
// -----------------------------------------------------------------------------

class JSON {
public:

   // Note: nlohmann::json reorders name/value pairs lexicographically, instead
   // of preserving the order in which it reads them. nlohmann's json.hpp says:
   //
   //   "@note The order name/value pairs are added to the object is *not*
   //    preserved by the library. Therefore, iterating an object may return
   //    name/value pairs in a different order than they were originally stored.
   //    In fact, keys will be traversed in alphabetical order as `std::map`
   //    with `std::less` is used by default. Please note this behavior conforms
   //    to [RFC 7159](http://rfc7159.net/rfc7159), because any order implements
   //    the specified 'unordered' nature of JSON objects."
   //
   // OK, fair enough, but I'd have liked to have a way to preserve the original
   // order, if for no other reason that being able to do certain tests more
   // easily. This could be hacked in some way, of course, and it's worth noting
   // that the GNDS document speaks of basically such a hack. -MFS

   // external JSON-library document
   nlohmann::json doc;

   // clear
   void clear()
   {
      doc.clear();
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
      obj.read(is);
   } catch (const std::exception &) {
      log::context("istream >> JSON");
      throw;
   }
   return is;
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const JSON &obj)
{
   try {
      obj.write(os);
   } catch (const std::exception &) {
      log::context("ostream << JSON");
      throw;
   }
   return os;
}
