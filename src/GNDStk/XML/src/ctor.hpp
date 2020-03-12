
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default, move
xml() = default;
xml(xml &&) = default;

// copy
// Note: pugi::xml_document's is inaccessible
xml(const xml &x)
{
   convert(x,*this);
}


// json, tree
explicit xml(const json &j)
{
   convert(j,*this);
}

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit xml(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
{
   convert(t,*this);
}


// file, stream
explicit xml(const std::string &file) { read(file); }
explicit xml(std::istream &is) { read(is); }
