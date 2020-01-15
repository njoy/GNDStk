
/*
Summary of functions in this file:

fixme write this
*/



// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

namespace detail {

// Node2xml
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
   // clear
   xdoc.clear();

   // convert
   // fixme write this
   if (tree.root) {
      (void)tree;
      assert(false);
   }

   // done
   return true;
}



// xml ==> xml
// For completeness
inline bool convert(const gnds::xml &from, gnds::xml &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // Unfortunately, we can't use pugi::xml_document's assignment, or for
   // that matter its copy constructor, because, for whatever reason, the
   // pugi library makes those private. (And, perhaps, those have shallow-
   // copy semantics, too. I haven't checked into that, because we can't
   // use those anyway.) For now, I'll write something simple that works,
   // albeit not very efficiently: write "from" to a stringstream, then
   // read "to" out of the stringstream. The GNDS documents that I've seen
   // so far aren't large enough to make this untenable. We can revisit
   // this issue if and when it's necessary to be more efficient.

   // backup indentation
   const int indent = gnds::indent;
   gnds::indent = 0; // to save a bit of space in the stringstream

   // from ==> stringstream ==> to
   std::stringstream ss;
   from.write(ss);
   to.read(ss);

   // restore indentation
   gnds::indent = indent;

   // done
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
