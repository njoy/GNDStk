
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default, move, copy
json() = default;
json(json &&) = default;
json(const json &) = default;


// xml, tree
explicit json(const xml &x)
{
   convert(x,*this);
}

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit json(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
{
   convert(t,*this);
}


// file, stream
explicit json(const std::string &file) { read(file); }
explicit json(std::istream &is) { read(is); }
