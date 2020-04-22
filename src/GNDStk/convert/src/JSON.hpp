
// -----------------------------------------------------------------------------
// convert(*,JSON)
// That is, convert to JSON objects
// -----------------------------------------------------------------------------

// ------------------------
// Tree ==> JSON
// ------------------------

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
   try {
      return tree.has_top()
         ? detail::node2json(tree.top(), j.doc)
         : true; // <== fine, JSON-wise, if nothing's there
   } catch (const std::exception &) {
      detail::context("convert(Tree,JSON)");
      throw;
   }
}



// ------------------------
// XML ==> JSON
// ------------------------

// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const GNDStk::XML &x, GNDStk::JSON &j)
{
   // temporary
   GNDStk::tree tree;

   // convert
   try {
      return
         convert(x,tree) and
         convert(tree,j);
   } catch (const std::exception &) {
      detail::context("convert(XML,JSON)");
      throw;
   }
}



// ------------------------
// JSON ==> JSON
// For completeness
// ------------------------

inline bool convert(const GNDStk::JSON &from, GNDStk::JSON &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // convert
   try {
      to.doc = from.doc; // nlohmann::json's assignment
   } catch (const std::exception &) {
      detail::context("convert(JSON,JSON)");
      throw;
   }

   // done
   return true;
}
