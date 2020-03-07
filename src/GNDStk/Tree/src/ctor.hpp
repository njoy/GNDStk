
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Basics
// -----------------------------------------------------------------------------

// default, move
Tree() { }
Tree(Tree &&) = default;

// copy
Tree(const Tree &from)
{
   convert(from,*this);
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
explicit Tree(const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   convert(from,*this);
}



// -----------------------------------------------------------------------------
// From xml and json objects
// -----------------------------------------------------------------------------

// xml, json
explicit Tree(const xml  &xdoc) { convert(xdoc,*this); }
explicit Tree(const json &jdoc) { convert(jdoc,*this); }



// -----------------------------------------------------------------------------
// From input
// Compare with our Tree read() functions
// -----------------------------------------------------------------------------

// file, format
// Example:
//    Tree<> t("n-008_O_016.xml", format::xml);
explicit Tree(
   const std::string &file,
   const format form = format::null
) {
   read(file,form);
}

// file, string
// Example:
//    Tree<> t("n-008_O_016.xml", "xml");
Tree(
   const std::string &file,
   const std::string &form
) {
   read(file,form);
}

// istream, format
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, format::xml);
explicit Tree(
   std::istream &is,
   const format form = format::null
) {
   read(is,form);
}

// istream, string
// Example:
//    std::ifstream ifs("n-008_O_016.xml");
//    Tree<> t(ifs, "xml");
Tree(
   std::istream &is,
   const std::string &form
) {
   read(is,form);
}



// -----------------------------------------------------------------------------
// Starter tree
// Compare with our Tree init() functions
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
template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
Tree(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &top,
   const format form,
   // the names "version" and "encoding" make sense for XML at least...
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   init(top, form, version, encoding);
}

// keyword, string
template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
Tree(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &top,
   const std::string &form,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   init(top, form, version, encoding);
}
