
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
JSON(const JSON &other)
try: doc(other.doc)
{
}
catch (...) {
   log::ctor("JSON(JSON)");
   throw;
}


// ------------------------
// From other classes
// ------------------------

// From XML
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

// From HDF5
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
// From file and istream
// ------------------------

// From file
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
