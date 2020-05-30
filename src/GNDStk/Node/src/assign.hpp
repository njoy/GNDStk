
// -----------------------------------------------------------------------------
// Node Assignment
// -----------------------------------------------------------------------------

// move
Node &operator=(Node &&) = default;

// copy
Node &operator=(const Node &from)
{
   if (&from != this)
      detail::node2Node(from,*this);
   return *this;
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Node &operator=(
   const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from
) {
   detail::node2Node(from,*this);
   return *this;
}
