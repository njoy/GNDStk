
// -----------------------------------------------------------------------------
// gnds::xml
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

   // standard ctor/assignment
   // The copy constructor and assignment are commented-out because
   // pugi::xml_document's respective elements are inaccessible.
   xml() = default;
   // xml(const xml &) = default;
   xml(xml &&) = default;
   // xml &operator=(const xml &) = default;
   xml &operator=(xml &&) = default;

   // ctor: json, tree
   xml(const json &j) { convert(j,*this); }
   xml(const tree &t) { convert(t,*this); }

   // ctor: file, stream
   xml(const char * const file) { read(file); }
   xml(const std::string &file) { read(file); }
   xml(std::istream &is) { read(is); }

   // read
   bool read(const char * const file);
   bool read(const std::string &file) { return read(file.c_str()); }
   std::istream &read(std::istream &);

   // write
   bool write(const char * const file) const;
   bool write(const std::string &file) const { return write(file.c_str()); }
   std::ostream &write(std::ostream &) const;

}; // class xml



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(char *)
inline bool xml::read(const char * const file)
{
   // load the document
   const pugi::xml_parse_result load = doc.load_file(
      file,
      pugi::parse_default |
      pugi::parse_declaration | // preserve root <?xml ...?> material
      pugi::parse_comments      // preserve <!-- comment --> material
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      std::cout << "Error loading file: " << file               << std::endl;
      std::cout << "Parse error       : " << load.description() << std::endl;
      std::cout << "Character offset  : " << load.offset        << std::endl;
      // failure
      return false;
   }

   // success
   return true;
}


// read(istream)
inline std::istream &xml::read(std::istream &is)
{
   // load the document
   const pugi::xml_parse_result load = doc.load(
      is,
      pugi::parse_default |
      pugi::parse_declaration |
      pugi::parse_comments
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      std::cout << "Error loading from stream" << std::endl;
      std::cout << "Parse error       : " << load.description() << std::endl;
      std::cout << "Character offset  : " << load.offset        << std::endl;
   }

   // done
   return is;
}


// operator>>
inline std::istream &operator>>(std::istream &is, xml &obj)
{
   // calls read(istream) above
   return obj.read(is);
}



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *)
inline bool xml::write(const char * const file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file);
   return !write(ofs).fail();
}


// write(ostream)
inline std::ostream &xml::write(std::ostream &os) const
{
   doc.save(os, std::string(indent,' ').c_str());
   return os;
}


// operator<<
inline std::ostream &operator<<(std::ostream &os, const xml &obj)
{
   // calls write(ostream) above
   return obj.write(os);
}