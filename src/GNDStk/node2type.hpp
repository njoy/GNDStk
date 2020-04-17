
/*
Description of node2type()

Brief: node.child(child_t<type>) ==> node ==> type

These are analogous to the string2type() functions, and the description
of those largely applies here.

The difference is that these are called through child(), not meta, and
hence have nodes, not strings, as inputs.

Also, we don't have any viable general default here. We simply don't know,
for a general node, how it would convert to any particular type. And, while
the string2type() functions could default to the behavior of converting
the string to a stream and using operator>>, we don't know how to convert
a node to a stream either.
*/

#include "GNDStk/node2type/src/detail.hpp"



// -----------------------------------------------------------------------------
// node2type(Node,Node)
//
// We may or may not really care about allowing for different container types
// in the input and the output, but supporting it shouldn't do any harm.
// -----------------------------------------------------------------------------

// Turns out that we already have this capability, in order to do tree-to-tree
// conversions. I'll just need to forward-declare it first...
namespace detail {
   template<
      template<class...> class METADATA_CONTAINER_FROM,
      template<class...> class CHILDREN_CONTAINER_FROM,
      template<class...> class METADATA_CONTAINER_TO,
      template<class...> class CHILDREN_CONTAINER_TO
   >
   void node2Node(
      const GNDStk::Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &,
            GNDStk::Node<METADATA_CONTAINER_TO,  CHILDREN_CONTAINER_TO  > &
   );
}

// And then node2type, for type == node
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline void node2type(
   const GNDStk::Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &node,
         GNDStk::Node<METADATA_CONTAINER_TO,  CHILDREN_CONTAINER_TO  > &type
) {
   type.clear();
   detail::node2Node(node,type);
}



// -----------------------------------------------------------------------------
// node2type(Node, some containers)
// Supports GNDS nodes like this:
//    <values>0.0 1.0 2.0 3.0 4.0</values>
// where the pugixml reader interprets the content as pcdata.
// -----------------------------------------------------------------------------

#define GNDSTK_NODE2CONTAINER(CONTAINER) \
   template< \
      template<class...> class METADATA_CONTAINER, \
      template<class...> class CHILDREN_CONTAINER, \
      class T, class Alloc \
   > \
   void node2type( \
      const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node, \
      std::CONTAINER<T,Alloc> &container \
   ) { \
      container.clear(); \
      string2type(detail::get_pcdata_string(node), container); \
   }

   GNDSTK_NODE2CONTAINER(deque)
   GNDSTK_NODE2CONTAINER(list)
   GNDSTK_NODE2CONTAINER(vector)

#undef GNDSTK_NODE2CONTAINER
