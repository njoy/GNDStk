
/*
Description of convert(type,node)

Brief: type ==> node ==> node.child(child_t<type>)

These are essentially the reverse of the convert(node,type) functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and converting them into a node that's destined to be added as a child node.
*/

#include "GNDStk/type2node/src/detail.hpp"



// -----------------------------------------------------------------------------
// convert(some containers, Node)
// -----------------------------------------------------------------------------

#define GNDSTK_CONVERT(CONTAINER) \
   template< \
      class T, class Alloc, \
      template<class...> class METADATA_CONTAINER, \
      template<class...> class CHILDREN_CONTAINER \
   > \
   void convert( \
      const std::CONTAINER<T,Alloc> &container, \
      Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node \
   ) { \
      try { \
         node.clear(); \
         convert(container, detail::put_pcdata_string(node)); \
      } catch (const std::exception &) { \
         log::context("convert(" #CONTAINER ",Node)"); \
         throw; \
      } \
   }

   GNDSTK_CONVERT(deque)
   GNDSTK_CONVERT(list)
   GNDSTK_CONVERT(vector)

#undef GNDSTK_CONVERT
