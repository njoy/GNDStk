
// -----------------------------------------------------------------------------
// HDF5 Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Basics
// ------------------------

// default
HDF5() { }

// move
#ifdef GNDSTK_DISABLE_HDF5
HDF5(HDF5 &&) = default;
#else
HDF5(HDF5 &&other) :
   filePtr (std::move(other.filePtr )),
   fileDesc(std::move(other.fileDesc))
{
   other.filePtr = nullptr;
   other.fileDesc = 0;
}
#endif

// copy
#ifdef GNDSTK_DISABLE_HDF5
HDF5(const HDF5 &) = default;
#else
HDF5(const HDF5 &other)
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(HDF5)");
      throw;
   }
}
#endif


// ------------------------
// From other classes
// ------------------------

// From XML
#ifndef GNDSTK_DISABLE_HDF5
explicit HDF5(const XML &x)
{
   try {
      if (!convert(x,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(XML)");
      throw;
   }
}
#endif

// From JSON
#ifndef GNDSTK_DISABLE_HDF5
#ifndef GNDSTK_DISABLE_JSON
explicit HDF5(const JSON &j)
{
   try {
      if (!convert(j,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(JSON)");
      throw;
   }
}
#endif
#endif

// From Node
explicit HDF5(const Node &n)
{
   try {
      if (!convert(n,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(Node)");
      throw;
   }
}


// ------------------------
// From istream and file
// ------------------------

// From istream
explicit HDF5(std::istream &is)
{
   try {
      if (!read(is))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(istream)");
      throw;
   }
}

// From file
#ifndef GNDSTK_DISABLE_HDF5
explicit HDF5(const std::string &filename)
{
   try {
      if (!read(filename))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(\"{}\")", filename);
      throw;
   }
}
#endif
