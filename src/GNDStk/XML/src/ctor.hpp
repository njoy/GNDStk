
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default, move
XML() = default;
XML(XML &&) = default;

// copy
// Note: pugi::xml_document's is inaccessible
XML(const XML &x)
{
   try {
      convert(x,*this);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: XML(XML)");
   }
}


// JSON
explicit XML(const JSON &j)
{
   try {
      convert(j,*this);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: XML(JSON)");
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
      convert(t,*this);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: XML(Tree)");
   }
}


// filename
explicit XML(const std::string &filename)
{
   try {
      read(filename);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: XML(filename)");
   }
}


// istream
explicit XML(std::istream &is)
{
   try {
      read(is);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: XML(istream)");
   }
}
