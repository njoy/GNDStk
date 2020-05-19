
/*
Description of convert(node,type)

Brief: node.child(child_t<type>) ==> node ==> type

These are analogous to the convert(string,type) functions, and the description
of those largely applies here.

The difference is that these are called through child(), not meta, and
hence have nodes, not strings, as inputs.

Also, we don't have any viable general default here. We simply don't know, for
a general node, how it would convert to any particular type. And, although the
convert(string,type) functions could default to the behavior of converting the
string to a stream and using operator>>, there's no way that seems plausible
or particularly helpful to convert a node to a stream.
*/

#include "GNDStk/node2type/src/detail.hpp"



// -----------------------------------------------------------------------------
// convert(Node,Node)
// We may or may not really care about allowing for different container types
// in both the input and the output, but supporting it shouldn't do any harm.
// -----------------------------------------------------------------------------

// Turns out that we already have this capability, in order to do tree-to-tree
// conversions. We just need to forward-declare it first...
namespace detail {
   template<
      template<class...> class METADATA_CONTAINER_FROM,
      template<class...> class CHILDREN_CONTAINER_FROM,
      template<class...> class METADATA_CONTAINER_TO,
      template<class...> class CHILDREN_CONTAINER_TO
   >
   void node2Node(
      const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &,
            Node<METADATA_CONTAINER_TO,  CHILDREN_CONTAINER_TO  > &
   );
}

// And then convert, for type == node
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline void convert(
   const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
         Node<METADATA_CONTAINER_TO,  CHILDREN_CONTAINER_TO  > &to
) {
   try {
      to.clear();
      detail::node2Node(from,to);
   } catch (const std::exception &) {
      log::context("convert(Node,Node)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// convert(Node, some containers)
// Supports GNDS nodes like this:
//    <values>0.0 1.0 2.0 3.0 4.0</values>
// where the pugixml reader interprets the content as pcdata.
// -----------------------------------------------------------------------------

#define GNDSTK_CONVERT(CONTAINER) \
   template< \
      template<class...> class METADATA_CONTAINER, \
      template<class...> class CHILDREN_CONTAINER, \
      class T, class Alloc \
   > \
   void convert( \
      const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node, \
      std::CONTAINER<T,Alloc> &container \
   ) { \
      try { \
         container.clear(); \
         convert(detail::get_pcdata_string(node), container); \
      } catch (const std::exception &) { \
         log::context("convert(Node," #CONTAINER ")"); \
         throw; \
      } \
   }

   GNDSTK_CONVERT(deque)
   GNDSTK_CONVERT(list)
   GNDSTK_CONVERT(vector)

#undef GNDSTK_CONVERT
