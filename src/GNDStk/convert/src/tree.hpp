
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
bool convert(
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
   const GNDStk::XML &x,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   return detail::XML2Tree(x,tree);
}


// JSON ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::JSON &j,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   using node_t = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

   // clear
   tree.clear();

   // fixme Real error here; and if 1 then can write later loop as non-loop
   assert(j.doc.size() == 1);

   // make a boilerplate declaration node
   tree.root = std::make_unique<node_t>();
   tree.decl().name = "json"; // indicates that we came from a JSON

   // make a top-level GNDS node, name to-be-determined
   node_t &top = tree.decl().add();

   // visit the JSON's outer node, and its descendants
   bool found = false;

   for (auto iter = j.doc.begin();  iter != j.doc.end();  ++iter) {
      // we should find exactly one outer node, if it's GNDS!
      assert(!found);
      found = true;
      if (not detail::json2node(iter,top))
         return false;
   }

   // done
   return true;
}
