
/*
Description of convert(node,type)

Brief: node.child(Child<type>) ==> node ==> type

These are analogous to the convert(string,type) functions, and the description
of those largely applies here.

The difference is that these are called through child(), not through meta(),
and hence have nodes, not strings, as their inputs.

Also, we don't have any viable general default here. We simply don't know, for
a general node, how it would convert to any particular type. And, although the
convert(string,type) functions could default to the behavior of converting the
string to an istream and then punting to operator>>, we can't think of a default
that's both plausible and particularly helpful for similarly converting a node
to an istream prior to operator>>.
*/

// -----------------------------------------------------------------------------
// convert(Node,Node)
// We may or may not really care about allowing for different container
// types in both the input and the output, but supporting it is harmless.
// -----------------------------------------------------------------------------

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
      to = from;
   } catch (...) {
      log::function("convert(Node,Node)");
      throw;
   }
}
