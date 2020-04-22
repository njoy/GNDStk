
// -----------------------------------------------------------------------------
// JSON Constructors
// -----------------------------------------------------------------------------

// default, move
JSON() = default;
JSON(JSON &&) = default;


// JSON
JSON(const JSON &j)
try: doc(j.doc)
{
}
catch (const std::exception &) {
   detail::context("JSON(JSON)");
   throw;
}


// XML
explicit JSON(const XML &x)
{
   try {
      convert(x,*this);
   } catch (const std::exception &) {
      detail::context("JSON(XML)");
      throw;
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
   } catch (const std::exception &) {
      detail::context("JSON(Tree)");
      throw;
   }
}


// filename
explicit JSON(const std::string &filename)
{
   try {
      read(filename);
   } catch (const std::exception &) {
      detail::context("JSON(filename=\"{}\")", filename);
      throw;
   }
}


// istream
explicit JSON(std::istream &is) {
   try {
      read(is);
   } catch (const std::exception &) {
      detail::context("JSON(istream)");
      throw;
   }
}
