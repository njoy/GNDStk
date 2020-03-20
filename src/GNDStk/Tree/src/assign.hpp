
// -----------------------------------------------------------------------------
// Tree Assignment
// -----------------------------------------------------------------------------

// move
Tree &operator=(Tree &&) = default;

// copy
Tree &operator=(const Tree &t)
{
   convert(t,*this);
   return *this;
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Tree &operator=(const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &t)
{
   convert(t,*this);
   return *this;
}
