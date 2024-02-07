
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
// Note: pugi::xml_document's copy constructor is inaccessible;
// otherwise, we'd use it here.
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
#ifndef NJOY_GNDSTK_DISABLE_JSON
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
#endif

// From HDF5
#ifndef NJOY_GNDSTK_DISABLE_HDF5
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
#endif

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


// ------------------------
// From istream and file
// ------------------------

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
