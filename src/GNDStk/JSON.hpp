
// -----------------------------------------------------------------------------
// JSON
// Wraps orderedJSON
// -----------------------------------------------------------------------------

class JSON {
public:

   // flags
   // These affect precisely how Nodes are written into JSON files. Note that
   // when *reading*, we recognize and accept whichever variation we may have
   // used when we wrote the JSON file to begin with.
   static inline bool reduced = true;
   static inline bool typed = true;

#ifdef GNDSTK_DISABLE_JSON

   // clear
   JSON &clear()
   {
      return *this;
   }

   // empty
   bool empty() const
   {
      return true;
   }

#else

   // data
   json::object doc;

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

#endif

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
inline std::istream &operator>>(std::istream &is, JSON &json)
{
   try {
      return json.read(is);
   } catch (...) {
      log::function("istream >> JSON");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const JSON &json)
{
   try {
      return json.write(os);
   } catch (...) {
      log::function("ostream << JSON");
      throw;
   }
}
