
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default, move, copy
JSON() = default;
JSON(JSON &&) = default;
JSON(const JSON &) = default;


// XML, Tree
explicit JSON(const XML &x)
{
   convert(x,*this);
}

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
explicit JSON(const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &t)
{
   convert(t,*this);
}


// file, stream
explicit JSON(const std::string &file) { read(file); }
explicit JSON(std::istream &is) { read(is); }
