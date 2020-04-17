
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
   GNDStk::JSON &j
) {
   // clear
   j.clear();

   // convert
   return tree.has_top()
      ? detail::node2json(tree.top(), j.doc)
      : true; // <== fine, JSON-wise, if nothing's there
}


// XML ==> JSON
// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const GNDStk::XML &x, GNDStk::JSON &j)
{
   GNDStk::tree tree;
   return
      convert(x,tree) and
      convert(tree,j);
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
