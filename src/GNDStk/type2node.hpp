
/*
Description of type2node()

Brief: type ==> node ==> node.child(child_t<type>)

These are essentially the reverse of the node2type() functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and writing them into a node that's destined to be added as a child node.
*/



// -----------------------------------------------------------------------------
// type2node(Node,Node)
// See node2type for relevant remarks.
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline void type2node(
   const GNDStk::Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &type,
         GNDStk::Node<METADATA_CONTAINER_TO,  CHILDREN_CONTAINER_TO  > &node
) {
   node.clear();
   detail::node2Node(type,node);
}
