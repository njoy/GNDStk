
// -----------------------------------------------------------------------------
// GNDStk::json
// Wraps nlohmann::json
// -----------------------------------------------------------------------------

class json {
public:

   // Note: The json object reorders name/value pairs lexicographically, instead
   // of preserving the order in which it reads them. nlohmann's json.hpp says:
   //
   //   "@note The order name/value pairs are added to the object is *not*
   //    preserved by the library. Therefore, iterating an object may return
   //    name/value pairs in a different order than they were originally stored.
   //    In fact, keys will be traversed in alphabetical order as `std::map`
   //    with `std::less` is used by default. Please note this behavior conforms
   //    to [RFC 7159](http://rfc7159.net/rfc7159), because any order implements
   //    the specified "unordered" nature of JSON objects."
   //
   // OK, fair enough, but I'd have liked to have a way to preserve the original
   // order. This could be hacked in some way, I suppose. And, it's worth noting
   // that the GNDS document speaks of, well, basically such a hack. -MFS

   // overall json document
   nlohmann::json doc;

   // clear
   void clear()
   {
      doc.clear();
   }

   // constructors, assignment
   #include "GNDStk/JSON/src/ctor.hpp"
   json &operator=(json &&) = default;
   json &operator=(const json &) = default;

   // read, write
   #include "GNDStk/JSON/src/read.hpp"
   #include "GNDStk/JSON/src/write.hpp"

}; // class json



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, json &obj)
{
   return obj.read(is);
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const json &obj)
{
   return obj.write(os);
}
