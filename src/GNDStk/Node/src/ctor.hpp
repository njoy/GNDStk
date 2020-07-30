
// -----------------------------------------------------------------------------
// Node Constructors
// -----------------------------------------------------------------------------

// fixme Should probably have some additional constructors,
// allowing for name, metadata, etc. at construction time.

// default, move
Node() = default;
Node(Node &&) = default;

// copy
Node(const Node &from)
{
   *this = from;
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Node(const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   *this = from;
}
