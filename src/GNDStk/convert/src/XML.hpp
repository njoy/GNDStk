
// -----------------------------------------------------------------------------
// convert(*,XML)
// That is, convert to XML objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tree ==> XML
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   XML &x
) {
   // clear
   x.clear();

   // The way we're storing things in our tree structure, the declaration node
   // might contain, e.g., the following, if the tree was built from an XML:
   //
   //    name: "xml"
   //    metadata:
   //       "version",  "1.0"
   //       "encoding", "UTF-8"
   //    children:
   //       N/A
   //
   // or the following if the tree was built from a JSON:
   //
   //    name: "json"
   //    metadata:
   //       (nothing; empty container)
   //    children:
   //       N/A
   //
   // or something else if the tree was built in another manner. In an XML file,
   // the declaration node is the thing like: <?xml version="1.0"...?>

   try {
      // declaration node
      if (tree.has_decl()) {
         pugi::xml_node xdecl = x.doc.append_child(pugi::node_declaration);
         for (auto &meta : tree.decl().metadata)
            xdecl.append_attribute(meta.first.c_str()) = meta.second.c_str();
      }
      // top-level GNDS node
      if (!tree.has_top())
         return true;
      detail::check_top(tree.top().name, "Tree", "convert(Tree,XML)");
      return detail::node2XML(tree.top(), x.doc);
   } catch (...) {
      log::function("convert(Tree,XML)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// XML ==> XML
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const XML &from, XML &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // Unfortunately, we can't use pugi::xml_document's assignment, or for
   // that matter its copy constructor, because, for whatever reason, the
   // pugi library makes those private. (And, perhaps, those have shallow-
   // copy semantics, too. I haven't checked into that, because we can't
   // use those anyway.)

   // For now, I'll write something simple that works, although not very
   // efficiently: write "from" to a stringstream, then read "to" out of
   // the stringstream. The GNDS files that I've seen so far aren't large
   // enough to make this untenable. We can revisit this issue if and when
   // it becomes necessary to be more efficient.

   // back up indentation
   const int indent = GNDStk::indent;
   GNDStk::indent = 0; // saves memory in the stringstream

   // from ==> stringstream ==> to
   try {
      std::stringstream ss;
      from.write(ss);
      to.read(ss);
   } catch (...) {
      log::function("convert(XML,XML)");
      throw;
   }

   // restore indentation
   GNDStk::indent = indent;

   // done
   return true;
}



// -----------------------------------------------------------------------------
// JSON ==> XML
// -----------------------------------------------------------------------------

// Goes through a tree. Could be made more efficient if written more directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const JSON &j, XML &x)
{
   // temporary
   Tree<> t;

   // convert
   try {
      return convert(j,t) && convert(t,x);
   } catch (...) {
      log::function("convert(JSON,XML)");
      throw;
   }
}
