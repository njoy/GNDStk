
// -----------------------------------------------------------------------------
// convert(*,JSON)
// That is, convert to JSON objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tree ==> JSON
// -----------------------------------------------------------------------------

inline bool convert(const Tree &tree, JSON &j)
{
   // clear
   j.clear();

   // convert
   try {
      if (!tree.has_top())
         return true;
      detail::check_top(tree.top().name, "Tree", "convert(Tree,JSON)");
      return detail::node2json(tree.top(), j.doc);
   } catch (...) {
      log::function("convert(Tree,JSON)");
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
   Tree t;

   // convert
   try {
      return convert(x,t) && convert(t,j);
   } catch (...) {
      log::function("convert(XML,JSON)");
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
   } catch (...) {
      log::function("convert(JSON,JSON)");
      throw;
   }

   // done
   return true;
}
