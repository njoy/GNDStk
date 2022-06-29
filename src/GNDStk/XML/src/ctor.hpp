
// -----------------------------------------------------------------------------
// XML Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Basics
// ------------------------

// default
XML() = default;

// move
XML(XML &&) = default;

// copy
// Note: pugi::xml_document's copy constructor is inaccessible; otherwise we'd
// use it here, as we do in JSON's copy constructor, instead of using convert().
XML(const XML &other)
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(XML)");
      throw;
   }
}


// ------------------------
// From other classes
// ------------------------

// From JSON
explicit XML(const JSON &j)
{
   try {
      if (!convert(j,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(JSON)");
      throw;
   }
}

// From HDF5
explicit XML(const HDF5 &h)
{
   try {
      if (!convert(h,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(HDF5)");
      throw;
   }
}

// From Node
explicit XML(const Node &n)
{
   try {
      if (!convert(n,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(Node)");
      throw;
   }
}

// From Tree
explicit XML(const Tree &t)
{
   try {
      if (!convert(t,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(Tree)");
      throw;
   }
}


// ------------------------
// From file and istream
// ------------------------

// From file
explicit XML(const std::string &filename)
{
   try {
      if (!read(filename))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(\"{}\")", filename);
      throw;
   }
}

// From istream
explicit XML(std::istream &is)
{
   try {
      if (!read(is))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(istream)");
      throw;
   }
}
