
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
   file(std::move(other.file)),
   filename(std::move(other.filename)),
   temporary(std::move(other.temporary))
{
   other.file = nullptr;
   other.filename = "";
   other.temporary = false;
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

// From Tree
explicit HDF5(const Tree &t)
{
   try {
      if (!convert(t,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("HDF5(Tree)");
      throw;
   }
}


// ------------------------
// From file and istream
// ------------------------

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