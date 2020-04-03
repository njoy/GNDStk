
// -----------------------------------------------------------------------------
// convert(*,JSON)
// That is, convert to JSON objects
// -----------------------------------------------------------------------------

// Tree ==> JSON
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   GNDStk::JSON &jdoc
) {
   // clear
   jdoc.clear();

   // convert
   if (not tree.empty()) {
      unsigned long kwdcount = 0;
      return detail::node2json(tree.top(), jdoc.doc, kwdcount);
      /*
      const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
         &node = *tree.root;
      assert(node.children.size() == 1);  // e.g. reactionSuite
      assert(*node.children.begin() != nullptr);
      return detail::node2json(**node.children.begin(), jdoc.doc, kwdcount);
      */
   }

   // done
   return true;
}


// XML ==> JSON
// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const GNDStk::XML &xdoc, GNDStk::JSON &jdoc)
{
   GNDStk::tree tree;
   return
      convert(xdoc,tree) and
      convert(tree,jdoc);
}


// JSON ==> JSON
// For completeness
inline bool convert(const GNDStk::JSON &from, GNDStk::JSON &to)
{
   if (&to == &from)
      return true;

   to.clear();
   to.doc = from.doc; // nlohmann::json's assignment
   return true;
}
