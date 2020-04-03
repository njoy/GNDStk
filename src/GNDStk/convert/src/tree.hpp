
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
// -----------------------------------------------------------------------------

// Tree ==> Tree
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline bool convert(
   const GNDStk::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
   GNDStk::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &to
) {
   // casts needed here because template arguments may be different...
   if ((void*)&to == (void*)&from)
      return true;

   // clear
   to.clear();

   // convert
   if (not from.empty()) {
      to.root =
         std::make_unique<Node<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO>>();
      detail::node2Node(*from.root, *to.root);
   }

   // done
   return true;
}


// XML ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline bool convert(
   const GNDStk::XML &xdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   return detail::XML2Tree(xdoc,tree);
}


// JSON ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline bool convert(
   const GNDStk::JSON &jdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   return detail::JSON2Tree(jdoc,tree);
}
