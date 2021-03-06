
// -----------------------------------------------------------------------------
// Basic Tree Constructors
// -----------------------------------------------------------------------------

// default
Tree() = default;

// move
Tree(Tree &&) = default;

// copy
Tree(const Tree &from) : nodeType{}
{
   try {
      if (!convert(from,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(Tree)");
      throw;
   }
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Tree(const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   try {
      if (!convert(from,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(Tree<different>)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// From XML and JSON objects
// -----------------------------------------------------------------------------

// XML
explicit Tree(const XML &x)
{
   try {
      if (!convert(x,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(XML)");
      throw;
   }
}

// JSON
explicit Tree(const JSON &j)
{
   try {
      if (!convert(j,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// From input file/stream
// Compare with our Tree read() functions
// -----------------------------------------------------------------------------

// file name, file format
// Example:
//    Tree<> t("n-008_O_016.xml", file::xml);
explicit Tree(const std::string &filename, const file form = file::null)
{
   try {
      if (!read(filename,form))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(\"{}\")", filename);
      throw;
   }
}

// file name, string
// Example:
//    Tree<> t("n-008_O_016.xml", "xml");
Tree(const std::string &filename, const std::string &filetype)
{
   try {
      if (!read(filename,filetype))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(\"{}\",type=\"{}\")", filename, filetype);
      throw;
   }
}

// istream, file format
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, file::xml);
explicit Tree(std::istream &is, const file form = file::null)
{
   try {
      if (!read(is,form))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(istream,string)");
      throw;
   }
}

// istream, string
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, "xml");
Tree(std::istream &is, const std::string &filetype)
{
   try {
      if (!read(is,filetype))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(istream,format)", filetype);
      throw;
   }
}



// -----------------------------------------------------------------------------
// Starter tree
// Compare with our Tree reset() functions
// -----------------------------------------------------------------------------

// Idea: User wants to begin building a brand-new GNDS tree from scratch.
//
// Examples:
//    Tree<> newtree(reactionSuite, file::xml, "1.0", "UTF-8");
// or
//    Tree<> newtree(reactionSuite, "xml", "1.0", "UTF-8");
//
// Note that the first argument is NOT quoted (""). It isn't the name of the
// top-level node that we want; rather, it's one of our "smart keywords."
// These keywords encode lots of information in them, including the quoted
// name that we'd otherwise have expected above, and, importantly, a boolean
// value that indicates whether or not the name encoded within the keyword
// is allowed (per the GNDS specification) as a top-level node. (If it isn't
// so allowed, then we shouldn't be starting a new tree from it!) Note, also,
// that by requiring the use of one of our keywords as the first argument to
// each of the below constructors, we avoid the situation of the constructors
// being ambiguous with other Tree constructors that take their (string) first
// arguments to be *file* names (not top-level node names).

// keyword, file format
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
Tree(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const file form = file::xml,
   // the names "version" and "encoding" make sense for XML at least...
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(kwd, form, version, encoding);
   } catch (...) {
      log::ctor("Tree(" + detail::keyname(kwd) + ")");
      throw;
   }
}

// keyword, string
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
Tree(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &filetype,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(kwd, filetype, version, encoding);
   } catch (...) {
      log::ctor("Tree(" + detail::keyname(kwd) + ",type=\"{}\")", filetype);
      throw;
   }
}
