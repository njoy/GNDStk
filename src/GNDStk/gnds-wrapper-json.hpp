
// -----------------------------------------------------------------------------
// gnds::json
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
   explicit json(const xml  &xdoc) { convert(xdoc,*this); }
   template<
      template<class...> class METADATA_CONTAINER,
      template<class...> class CHILDREN_CONTAINER
   >
   explicit json(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree)
   {
      convert(tree,*this);
   }

   // ctor: file, stream
   explicit json(const std::string &file) { read(file); }
   explicit json(std::istream &is) { read(is); }

   // read
   bool read(const std::string &file);
   std::istream &read(std::istream &);

   // write
   bool write(const std::string &file) const;
   std::ostream &write(std::ostream &) const;

}; // class json



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(string)
inline bool json::read(const std::string &file)
{
   // calls read(istream) below
   std::ifstream ifs(file.c_str());
   return not read(ifs).fail();
}


// read(istream)
inline std::istream &json::read(std::istream &is)
{
   is >> doc;
   /*
   if (is.eof ()) std::cout << "eof"  << std::endl;
   if (is.bad ()) std::cout << "bad"  << std::endl;
   if (is.fail()) std::cout << "fail" << std::endl;
   */
   return is;
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

// write(string)
inline bool json::write(const std::string &file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file.c_str());
   return not write(ofs).fail();
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
