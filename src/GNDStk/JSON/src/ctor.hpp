
// -----------------------------------------------------------------------------
// JSON Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Basics
// ------------------------

// default
JSON() = default;

// move
JSON(JSON &&) = default;

// copy
#ifdef NJOY_GNDSTK_DISABLE_JSON
JSON(const JSON &) = default;
#else
JSON(const JSON &other)
try: doc(other.doc)
{
}
catch (...) {
   log::ctor("JSON(JSON)");
   throw;
}
#endif


// ------------------------
// From other classes
// ------------------------

// From XML
#ifndef NJOY_GNDSTK_DISABLE_JSON
explicit JSON(const XML &x)
{
   try {
      if (!convert(x,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(XML)");
      throw;
   }
}
#endif

// From HDF5
#ifndef NJOY_GNDSTK_DISABLE_JSON
#ifndef NJOY_GNDSTK_DISABLE_HDF5
explicit JSON(const HDF5 &h)
{
   try {
      if (!convert(h,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(HDF5)");
      throw;
   }
}
#endif
#endif

// From Node
explicit JSON(const Node &n)
{
   try {
      if (!convert(n,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(Node)");
      throw;
   }
}


// ------------------------
// From istream and file
// ------------------------

// From istream
explicit JSON(std::istream &is)
{
   try {
      if (!read(is))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(istream)");
      throw;
   }
}

// From file
#ifndef NJOY_GNDSTK_DISABLE_JSON
explicit JSON(const std::string &filename)
{
   try {
      if (!read(filename))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(\"{}\")", filename);
      throw;
   }
}
#endif
