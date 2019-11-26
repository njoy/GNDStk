
// -----------------------------------------------------------------------------
// json
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

   // standard ctor/assignment
   json() = default;
   json(const json &) = default;
   json(json &&) = default;
   json &operator=(const json &) = default;
   json &operator=(json &&) = default;

   // ctor: xml, tree
   json(const xml  &x);
   json(const tree &t) { convert(t,*this); }

   // ctor: file, stream
   json(const char * const file) { read(file); }
   json(const std::string &file) { read(file); }
   json(std::istream &is) { read(is); }

   // read
   bool read(const char * const file);
   bool read(const std::string &file) { return read(file.c_str()); }
   std::istream &read(std::istream &);

   // write
   bool write(const char * const file) const;
   bool write(const std::string &file) const { return write(file.c_str()); }
   std::ostream &write(std::ostream &) const;

}; // class json



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(char *)
inline bool json::read(const char * const file)
{
   // calls read(istream) below
   std::ifstream ifs(file);
   return !read(ifs).fail();
}


// read(istream)
inline std::istream &json::read(std::istream &is)
{
   return is >> doc;
}


// operator>>
inline std::istream &operator>>(std::istream &is, json &obj)
{
   // calls read(istream) above
   return obj.read(is);
}



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *)
inline bool json::write(const char * const file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file);
   return !write(ofs).fail();
}


// write(ostream)
inline std::ostream &json::write(std::ostream &os) const
{
   os << std::setw(indent) << doc; // intentional: no << std::endl
   return os;
}


// operator<<
inline std::ostream &operator<<(std::ostream &os, const json &obj)
{
   // calls write(ostream) above
   return obj.write(os);
}
