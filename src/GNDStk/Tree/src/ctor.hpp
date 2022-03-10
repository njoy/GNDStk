
// -----------------------------------------------------------------------------
// Basic Tree Constructors
// -----------------------------------------------------------------------------

// default
Tree() = default;

// move
Tree(Tree &&) = default;

// copy
Tree(const Tree &other) : Node{}
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(Tree)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// From XML, JSON, and HDF5 objects
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

// HDF5
explicit Tree(const HDF5 &h)
{
   try {
      if (!convert(h,*this))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(HDF5)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// From input file/stream
// Compare with our Tree read() functions
// -----------------------------------------------------------------------------

// file name, FileType
// Example:
//    Tree t("n-008_O_016.xml", FileType::xml);
explicit Tree(
   const std::string &filename,
   const FileType format = FileType::guess
) {
   try {
      if (!read(filename,format))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(\"{}\")", filename);
      throw;
   }
}

// file name, string
// Example:
//    Tree t("n-008_O_016.xml", "xml");
Tree(const std::string &filename, const std::string &format)
{
   try {
      if (!read(filename,format))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(\"{}\",type=\"{}\")", filename, format);
      throw;
   }
}

// istream, FileType
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree t(ifs, FileType::xml);
explicit Tree(std::istream &is, const FileType format = FileType::guess)
{
   try {
      if (!read(is,format))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(istream,string)");
      throw;
   }
}

// istream, string
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree t(ifs, "xml");
Tree(std::istream &is, const std::string &format)
{
   try {
      if (!read(is,format))
         throw std::exception{};
   } catch (...) {
      log::ctor("Tree(istream,format)", format);
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
//    Tree newtree(reactionSuite, FileType::xml, "1.0", "UTF-8");
// or
//    Tree newtree(reactionSuite, "xml", "1.0", "UTF-8");
//
// Note that the first argument is NOT quoted (""). It isn't the name of the
// top-level node that we want; rather, it's one of our Child "query objects."
// These encode lots of information in them, including the quoted name that
// we'd otherwise have expected above, and, importantly, a boolean value that
// indicates whether or not the name encoded within the object is allowed (per
// the GNDS specification) as a top-level node. (If it isn't so allowed, then
// we shouldn't be starting a new tree from it!) Note, also, that by requiring
// the use of a Child object as the first argument to each of the below
// constructors, we avoid the situation of the constructors being ambiguous
// with other Tree constructors that take their (string) first arguments to
// be *file* names (not top-level node names).

// keyword, FileType
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
Tree(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const FileType format = FileType::xml,
   // the names "version" and "encoding" make sense for XML at least...
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(kwd, format, version, encoding);
   } catch (...) {
      log::ctor("Tree(" + detail::keyname(kwd) + ")");
      throw;
   }
}

// keyword, string
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
Tree(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &format,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(kwd, format, version, encoding);
   } catch (...) {
      log::ctor("Tree(" + detail::keyname(kwd) + ",type=\"{}\")", format);
      throw;
   }
}
