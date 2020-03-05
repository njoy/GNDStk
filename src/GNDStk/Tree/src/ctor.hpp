
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Basics
// ------------------------

// default, move
Tree() { }
Tree(Tree &&) = default;

// copy
Tree(const Tree &t)
{
   convert(t,*this);
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
explicit Tree(const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &t)
{
   convert(t,*this);
}


// ------------------------
// From xml and json
// objects
// ------------------------

// xml, json
explicit Tree(const xml  &xdoc) { convert(xdoc,*this); }
explicit Tree(const json &jdoc) { convert(jdoc,*this); }


// ------------------------
// From input
// ------------------------

// file
explicit Tree(
   const std::string &file,
   const format form = format::null
) {
   read(file,form);
}

// stream
explicit Tree(
   std::istream &is,
   const format form = format::null
) {
   read(is,form);
}


// ------------------------
// starter tree
// ------------------------

// Idea: User wants to begin building a brand-new GNDS tree from scratch.
// Example:
//    Tree<> newtree("xml", "reactionSuite", "1.0", "UTF-8");
// fixme: Probably reverse the first and second parameter.
Tree(
   const std::string &type_str,
   const std::string &gnds_str,
   const std::string &param1 = static_str1,
   const std::string &param2 = static_str2
) {
   start(type_str, gnds_str, param1, param2);
}


// ------------------------
// Not viable right now,
// but worth mentioning
// ------------------------

// fixme I change I may make to the "starter tree" constructor will make
// these workable, so I'm leaving them here for now.

/*
// The read() and write() functions allow a std::string form, for user
// convenience vs. writing format::something. However, we can't have the
// first of the following two here - it ambiguous versus the "starter
// tree" constructor. Given that we don't want the first of these, we
// probably don't want the second either, for the sake of API uniformity.

Tree(
   const std::string &file,
   const std::string &form
) {
   read(file,form);
}

Tree(
   std::istream &is,
   const std::string &form
) {
   read(is,form);
}
*/
