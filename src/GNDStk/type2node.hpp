
/*
Description of type2node()

Brief: type ==> node ==> node.child(child_t<type>)

These are essentially the reverse of the node2type() functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and writing them into a node that's destined to be added as a child node.
*/

#include "GNDStk/type2node/src/detail.hpp"



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
   try {
      node.clear();
      detail::node2Node(type,node);
   } catch (const std::exception &) {
      detail::context("type2node(Node,Node)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// type2node(some containers, Node)
// -----------------------------------------------------------------------------

#define GNDSTK_CONTAINER2NODE(CONTAINER) \
   template< \
      class T, class Alloc, \
      template<class...> class METADATA_CONTAINER, \
      template<class...> class CHILDREN_CONTAINER \
   > \
   void type2node( \
      const std::CONTAINER<T,Alloc> &container, \
      GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node \
   ) { \
      try { \
         node.clear(); \
         type2string(container, detail::put_pcdata_string(node)); \
      } catch (const std::exception &) { \
         detail::context("type2node(" #CONTAINER ",Node)"); \
         throw; \
      } \
   }

   GNDSTK_CONTAINER2NODE(deque)
   GNDSTK_CONTAINER2NODE(list)
   GNDSTK_CONTAINER2NODE(vector)

#undef GNDSTK_CONTAINER2NODE
