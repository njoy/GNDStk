
/*
Summary of the functions in this file:

namespace detail {
   1. Node2xml(GNDStk::Node, pugi::xml_node)
      ...uses (1) (itself)
}

2. convert(GNDStk::Tree, GNDStk::xml)
   ...uses (1)

3. convert(GNDStk::xml, GNDStk::xml)

4. convert(GNDStk::json, GNDStk::xml)
   ...uses (2)
*/



// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

namespace detail {

// Node2xml
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool Node2xml(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node,
   pugi::xml_node &x
) {
   // name
   pugi::xml_node xnode = x.append_child(node.name.c_str());

   // metadata
   for (auto &meta : node.metadata) {
      // PCDATA
      if (meta.first == keyword_pcdata) {
         assert(node.children.size() == 0);
         xnode.append_child(pugi::node_pcdata).set_value(meta.second.c_str());
         continue;
      }

      // CDATA
      if (meta.first == keyword_cdata) {
         assert(node.children.size() == 0);
         xnode.append_child(pugi::node_cdata).set_value(meta.second.c_str());
         continue;
      }

      // comment
      if (meta.first == keyword_comment) {
         xnode.append_child(pugi::node_comment).set_value(meta.second.c_str());
         continue;
      }

      // regular element
      xnode.append_attribute(meta.first.c_str()) = meta.second.c_str();
   }

   // children
   for (auto &child : node.children)
      if (child and not Node2xml(*child, xnode))
         return false;

   // done
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert
// -----------------------------------------------------------------------------

// Tree ==> xml
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree,
   GNDStk::xml &xdoc
) {
   // clear
   xdoc.clear();

   // convert
   if (not tree.empty()) {
      const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &zero =
         tree.zero();

      // ------------------------
      // "zero" node
      // ------------------------

      // The way we're storing things in our tree structure, this might
      // contain e.g. the following if the tree was built from an xml:
      //
      //    name: "xml"
      //    metadata:
      //       "version",  "1.0"
      //       "encoding", "UTF-8"
      //    children:
      //       just one, e.g. "reactionSuite" or "PoPs"
      //
      // or the following if the tree was built from a json:
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
      pugi::xml_node decl = xdoc.doc.append_child(pugi::node_declaration);
      for (auto &meta : zero.metadata)
         decl.append_attribute(meta.first.c_str()) = meta.second.c_str();

      // ------------------------
      // children
      // ------------------------

      return detail::Node2xml(tree.top(), xdoc.doc);

      /*
      // fixme Everywhere, checks like the following should
      // eventually be handled by something better than asserts
      assert(zero.children.size() == 1);  // e.g. reactionSuite or PoPs
      assert(*zero.children.begin() != nullptr);
      return detail::Node2xml(**zero.children.begin(), xdoc.doc);
      */
   }

   // done
   return true;
}



// xml ==> xml
// For completeness
inline bool convert(const GNDStk::xml &from, GNDStk::xml &to)
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



// json ==> xml
// Goes through a tree. Could be made more efficient if written more directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const GNDStk::json &jdoc, GNDStk::xml &xdoc)
{
   GNDStk::tree tree;
   return
      convert(jdoc,tree) and
      convert(tree,xdoc);
}
