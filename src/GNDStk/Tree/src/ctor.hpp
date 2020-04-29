
// -----------------------------------------------------------------------------
// Tree Constructors
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Basic
// -----------------------------------------------------------------------------

// default, move
Tree() = default;
Tree(Tree &&) = default;


// copy
Tree(const Tree &from)
{
   try {
      convert(from,*this);
   } catch (const std::exception &) {
      log::context("Tree(Tree)");
      throw;
   }
}


// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
explicit Tree(const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   try {
      convert(from,*this);
   } catch (const std::exception &) {
      log::context("Tree(Tree<different>)");
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
      convert(x,*this);
   } catch (const std::exception &) {
      log::context("Tree(XML)");
      throw;
   }
}


// JSON
explicit Tree(const JSON &j)
{
   try {
      convert(j,*this);
   } catch (const std::exception &) {
      log::context("Tree(JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// From input
// Compare with our Tree read() functions
// -----------------------------------------------------------------------------

// filename, format
// Example:
//    Tree<> t("n-008_O_016.xml", format::xml);
explicit Tree(
   const std::string &filename,
   const format form = format::null
) {
   try {
      read(filename,form);
   } catch (const std::exception &) {
      log::context("Tree(filename=\"{}\"[,format])", filename);
      throw;
   }
}


// filename, string
// Example:
//    Tree<> t("n-008_O_016.xml", "xml");
Tree(
   const std::string &filename,
   const std::string &type
) {
   try {
      read(filename,type);
   } catch (const std::exception &) {
      log::context("Tree(filename=\"{}\",type=\"{}\")", filename, type);
      throw;
   }
}


// istream, format
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, format::xml);
explicit Tree(
   std::istream &is,
   const format form = format::null
) {
   try {
      read(is,form);
   } catch (const std::exception &) {
      log::context("Tree(istream[,format])");
      throw;
   }
}


// istream, string
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, "xml");
Tree(
   std::istream &is,
   const std::string &type
) {
   try {
      read(is,type);
   } catch (const std::exception &) {
      log::context("Tree(istream,type=\"{}\")", type);
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
//    Tree<> newtree(child::reactionSuite, format::xml, "1.0", "UTF-8");
// or
//    Tree<> newtree(child::reactionSuite, "xml", "1.0", "UTF-8");
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

// keyword, format
template<class RESULT, find FIND, class METADATA, class CHILDREN>
Tree(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &top,
   const format form = format::xml,
   // the names "version" and "encoding" make sense for XML at least...
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(top, form, version, encoding);
   } catch (const std::exception &) {
      log::context(
         "Tree(child_t(\"{}\")[,format,version,encoding])",
         top.name
      );
      throw;
   }
}

// keyword, string
template<class RESULT, find FIND, class METADATA, class CHILDREN>
Tree(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &top,
   const std::string &type,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      reset(top, type, version, encoding);
   } catch (const std::exception &) {
      log::context(
         "Tree(child_t(\"{}\"),type=\"{}\"[,version,encoding])",
         top.name, type
      );
      throw;
   }
}
