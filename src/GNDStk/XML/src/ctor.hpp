
// -----------------------------------------------------------------------------
// XML Constructors
// -----------------------------------------------------------------------------

// default
XML() = default;


// move
XML(XML &&) = default;


// copy
// Note: pugi::xml_document's is inaccessible
XML(const XML &x)
{
   try {
      if (!convert(x,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("XML(XML)");
      throw;
   }
}


// JSON
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


// Tree
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


// filename
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


// istream
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
