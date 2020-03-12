
// -----------------------------------------------------------------------------
// convert(*,json)
// That is, convert TO json objects
// -----------------------------------------------------------------------------

// Tree ==> json
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   GNDStk::json &jdoc
) {
   // clear
   jdoc.clear();

   // convert
   if (not tree.empty()) {
      unsigned long kwdcount = 0;
      return detail::Node2json(tree.top(), jdoc.doc, kwdcount);
      /*
      const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
         &node = *tree.root;
      assert(node.children.size() == 1);  // e.g. reactionSuite
      assert(*node.children.begin() != nullptr);
      return detail::Node2json(**node.children.begin(), jdoc.doc, kwdcount);
      */
   }

   // done
   return true;
}


// xml ==> json
// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const GNDStk::xml &xdoc, GNDStk::json &jdoc)
{
   GNDStk::tree tree;
   return
      convert(xdoc,tree) and
      convert(tree,jdoc);
}


// json ==> json
// For completeness
inline bool convert(const GNDStk::json &from, GNDStk::json &to)
{
   if (&to == &from)
      return true;

   to.clear();
   to.doc = from.doc; // nlohmann::json's assignment
   return true;
}
