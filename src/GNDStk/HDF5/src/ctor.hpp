
// -----------------------------------------------------------------------------
// HDF5 Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Basics
// ------------------------

// default
HDF5() { }

// move
HDF5(HDF5 &&other) :
   filePtr (std::move(other.filePtr )),
   fileDesc(std::move(other.fileDesc))
{
   other.filePtr  = nullptr;
   other.fileDesc = 0;
}

// copy
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


// ------------------------
// From other classes
// ------------------------

// From XML
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

// From JSON
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
