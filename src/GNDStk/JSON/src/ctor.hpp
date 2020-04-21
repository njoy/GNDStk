
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default, move, copy
JSON() = default;
JSON(JSON &&) = default;
JSON(const JSON &) = default;


// XML
explicit JSON(const XML &x)
{
   try {
      convert(x,*this);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: JSON(XML)");
   }
}


// Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit JSON(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
{
   try {
      convert(t,*this);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: JSON(Tree)");
   }
}


// filename
explicit JSON(const std::string &filename)
{
   try {
      read(filename);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: JSON(filename)");
   }
}


// istream
explicit JSON(std::istream &is) {
   try {
      read(is);
   }  catch (const std::exception &) {
      njoy::Log::info("Context: JSON(istream)");
   }
}
