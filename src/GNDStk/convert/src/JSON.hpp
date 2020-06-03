
// -----------------------------------------------------------------------------
// convert(*,JSON)
// That is, convert to JSON objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tree ==> JSON
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   JSON &j
) {
   // clear
   j.clear();

   // convert
   try {
      return !tree.has_top() || detail::node2json(tree.top(), j.doc);
   } catch (const std::exception &) {
      log::context("convert(Tree,JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// XML ==> JSON
// -----------------------------------------------------------------------------

// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const XML &x, JSON &j)
{
   // temporary
   tree t;

   // convert
   try {
      return
         convert(x,t) and
         convert(t,j);
   } catch (const std::exception &) {
      log::context("convert(XML,JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// JSON ==> JSON
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const JSON &from, JSON &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // convert
   try {
      to.doc = from.doc; // nlohmann::json's assignment
   } catch (const std::exception &) {
      log::context("convert(JSON,JSON)");
      throw;
   }

   // done
   return true;
}
