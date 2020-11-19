
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
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit XML(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
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
