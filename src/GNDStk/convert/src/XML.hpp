
// -----------------------------------------------------------------------------
// convert(*,XML)
// That is, convert to XML objects
// -----------------------------------------------------------------------------

// Tree ==> XML
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   GNDStk::XML &xdoc
) {
   // clear
   xdoc.clear();

   // convert
   if (tree.has_decl()) {
      const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &tdecl =
         tree.decl();

      // ------------------------
      // declaration node
      // ------------------------

      // The way we're storing things in our tree structure, this might
      // contain e.g. the following if the tree was built from an XML:
      //
      //    name: "xml"
      //    metadata:
      //       "version",  "1.0"
      //       "encoding", "UTF-8"
      //    children:
      //       just one, e.g. "reactionSuite" or "PoPs"
      //
      // or the following if the tree was built from a JSON:
      //
      //    name: "json"
      //    metadata:
      //       (nothing; empty container)
      //    children:
      //       just one, e.g. "reactionSuite" or "PoPs"
      //
      // or something else if the tree was built in another manner.

      // declaration node
      // That's the thing like this: <?xml version="1.0" encoding="UTF-8"?>
      pugi::xml_node xdecl = xdoc.doc.append_child(pugi::node_declaration);
      for (auto &meta : tdecl.metadata)
         xdecl.append_attribute(meta.first.c_str()) = meta.second.c_str();

      // ------------------------
      // children
      // ------------------------

      return !tree.has_top() || detail::node2XML(tree.top(), xdoc.doc);

      /*
      // fixme Everywhere, checks like the following should
      // eventually be handled by something better than asserts
      assert(tdecl.children.size() == 1);  // e.g. reactionSuite or PoPs
      assert(*tdecl.children.begin() != nullptr);
      return detail::node2XML(**tdecl.children.begin(), xdoc.doc);
      */
   }

   // done
   return true;
}


// XML ==> XML
// For completeness
inline bool convert(const GNDStk::XML &from, GNDStk::XML &to)
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
   // this issue if and when it becomes necessary to be more efficient.

   // backup indentation
   const int indent = GNDStk::indent;
   GNDStk::indent = 0; // saves memory in the stringstream

   // from ==> stringstream ==> to
   std::stringstream ss;
   from.write(ss);
   to.read(ss);

   // restore indentation
   GNDStk::indent = indent;

   // done
   return true;
}


// JSON ==> XML
// Goes through a tree. Could be made more efficient if written more directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const GNDStk::JSON &jdoc, GNDStk::XML &xdoc)
{
   GNDStk::tree tree;
   return
      convert(jdoc,tree) and
      convert(tree,xdoc);
}
