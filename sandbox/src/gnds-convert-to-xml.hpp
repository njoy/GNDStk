
/*
Summary of functions in this file:

fixme write this
*/



// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

namespace detail {

// node2xml
// fixme write this

} // namespace detail



// -----------------------------------------------------------------------------
// convert
// -----------------------------------------------------------------------------

// Tree ==> xml
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(const gnds::Tree<MCON,CCON> &tree, gnds::xml &xdoc)
{
   (void)tree;

   // prepare output
   xdoc.clear();

   // convert
   // fixme write this
   assert(false);

   // done
   return true;
}


// xml ==> xml
// For completeness
inline bool convert(const gnds::xml &from, gnds::xml &to)
{
   if (&from == &to)
      return true;
   to.clear();

   (void)from;
   (void)to;

   // fixme write this!
   assert(false);
   return true;
}


// json ==> xml
// Goes through a tree. Could be made more efficient if written more directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const gnds::json &jdoc, gnds::xml &xdoc)
{
   gnds::tree tree;
   return
      convert(jdoc,tree) &&
      convert(tree,xdoc);
}
