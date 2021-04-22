
// -----------------------------------------------------------------------------
// JSON Constructors
// -----------------------------------------------------------------------------

// default
JSON() = default;

// move
JSON(JSON &&) = default;

// copy
JSON(const JSON &j)
try: doc(j.doc)
{
}
catch (...) {
   log::ctor("JSON(JSON)");
   throw;
}

// XML
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

// Node
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

// Tree
explicit JSON(const Tree &t)
{
   try {
      if (!convert(t,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("JSON(Tree)");
      throw;
   }
}

// file name
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

// istream
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
