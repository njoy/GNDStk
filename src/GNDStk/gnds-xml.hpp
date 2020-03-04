
// -----------------------------------------------------------------------------
// GNDStk::xml
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

class xml {
public:

   // ------------------------
   // Data
   // ------------------------

   // overall xml document
   pugi::xml_document doc;


   // ------------------------
   // Miscellaneous functions
   // ------------------------

   // clear
   void clear()
   {
      doc.reset();
   }


   // ------------------------
   // Constructors
   // ------------------------

   // default
   // move
   xml() = default;
   xml(xml &&) = default;

   // json, tree
   explicit xml(const json &j) { convert(j,*this); }
   template<
      template<class...> class METADATA_CONTAINER,
      template<class...> class CHILDREN_CONTAINER
   >
   explicit xml(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
   {
      convert(t,*this);
   }

   // file, stream
   explicit xml(const std::string &file) { read(file); }
   explicit xml(std::istream &is) { read(is); }

   // copy (pugi::xml_document's is inaccessible)
   xml(const xml &x)
   {
      convert(x,*this);
   }


   // ------------------------
   // Assignment
   // ------------------------

   // move
   xml &operator=(xml &&) = default;

   // copy (pugi::xml_document's is inaccessible)
   xml &operator=(const xml &x)
   {
      convert(x,*this);
      return *this;
   }


   // ------------------------
   // read, write
   // ------------------------

   // read
   bool read(const std::string &file);
   std::istream &read(std::istream &);

   // write
   bool write(const std::string &file) const;
   std::ostream &write(std::ostream &) const;

}; // class xml



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(string)
inline bool xml::read(const std::string &file)
{
   // load the document
   const pugi::xml_parse_result load = doc.load_file(
      file.c_str(),
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

// write(string)
inline bool xml::write(const std::string &file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file.c_str());
   return not write(ofs).fail();
}


// write(ostream)
inline std::ostream &xml::write(std::ostream &os) const
{
   // fixme Can we prevent pugixml from emitting a newline at the end?
   // ...Concept: output functions shouldn't *assume* that someone who prints
   // ...something wants a newline at the end. A user should explicitly write
   // ...the \n, std::endl, whatever, if they want that. One might think we'd
   // ...always want the newline for a "large" or "compound" object (the
   // ...printing of which might, in fact, even have internal newlines).
   // ...However, automatically printing a newline makes the behavior
   // ...different from what we expect with "simple" types - int, double, etc.
   // ...Different makes it less predictable, and inconsistent. Print a vector
   // ...of ints, for example, with an explicit newline after each, and we'll
   // ...get one int per line. Print a vector of these xml objects in the same
   // ...way, and we'll get blank lines, in between, if the xml printing takes
   // ...it upon itself to print its own newline. The best behavior, in my
   // ...opinion, is consistent behavior - it's easy to remember.
   doc.save(os, std::string(indent,' ').c_str());
   return os;
}


// operator<<
inline std::ostream &operator<<(std::ostream &os, const xml &obj)
{
   // calls write(ostream) above
   return obj.write(os);
}
