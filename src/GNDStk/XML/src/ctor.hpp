
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
   convert(x,*this);
}


// JSON, Tree
explicit XML(const JSON &j)
{
   convert(j,*this);
}

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit XML(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
{
   convert(t,*this);
}


// file, stream
explicit XML(const std::string &file) { read(file); }
explicit XML(std::istream &is) { read(is); }
