
/*
Summary of the functions in this file:

fixme write this
*/



// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

namespace detail {

// Node2xml
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool Node2xml(
   const gnds::Node<MCON,CCON> &node,
   pugi::xml_node &x
) {
   /**/
   /**/
   /*
   std::cout << "   " << node.name << std::endl;
   for (auto &m : node.metadata)
      std::cout
         << "   \""
         << m.first << "\", \"" << m.second << '"' << std::endl;
   for (auto &c : node.children)
      std::cout << "   " << c->name << std::endl;
   */
   /**/
   /**/

   // name
   pugi::xml_node xnode = x.append_child(node.name.c_str());

   // metadata
   for (auto &meta : node.metadata) {
      if (meta.first == "comment") {
///nope         assert(node.children.size() == 0); /// correct?
         // comment
         xnode.append_child(pugi::node_comment).set_value(meta.second.c_str());
      } else if (meta.first == "text") {
         assert(node.children.size() == 0); /// correct?
         // CDATA
         xnode.append_child(pugi::node_cdata).set_value(meta.second.c_str());
      } else if (meta.first == "body") {
         assert(node.children.size() == 0); /// correct?
         // PCDATA
         xnode.append_child(pugi::node_pcdata).set_value(meta.second.c_str());
      } else {
         // regular element
         xnode.append_attribute(meta.first.c_str()) = meta.second.c_str();
      }
   }

   // children
   bool ret = true;
   for (auto &child : node.children)
      ret = ret && Node2xml(*child, xnode);

   // done
   return ret;

   /*
   // fixme Remove this eventually; was from tree-to-json code, for comparison
   // name
   // The effect of j[nodename] is to enter a key of this name into the json
   // object. Generally, this is triggered automatically in the body of one
   // and/or the other of the upcoming metadata and children loops. However,
   // consider a node that has no metadata or children; then, we need this.
   // An example is <RutherfordScattering/> in some of our GNDS XML files,
   // as it contains neither metadata nor children.
   const std::string nodename = prefix(kwdcount++) + node.name;
   j[nodename];

   // metadata
   if (node.metadata.size() > 0) {
      // ...because we only want the kwdcount ++ side effect if size() > 0
      const std::string attrname = prefix(kwdcount++) + "attributes";
      // visit
      for (auto &meta : node.metadata)
         j[nodename][attrname][prefix(kwdcount++) + meta.first] =
            meta.second;
   }

   // children
   for (auto &child : node.children)
      if (child && !Node2json(*child, j[nodename], kwdcount))
         return false;
   */
}

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
   if (tree.root) {
      const gnds::Node<MCON,CCON> &node = *tree.root;

      // ------------------------
      // root node
      // ------------------------

      // The way we're storing things in our tree structure, this might contain
      // the following if the tree was built from an xml:
      //
      //    name: "xml"
      //    metadata:
      //       "version", "1.0"
      //       "encoding", "UTF-8"
      //    children:
      //       just one, e.g. "reactionSuite"
      //
      // or the following if the tree was built from a json:
      //
      //    name: "json"
      //    metadata:
      //       (nothing; empty container)
      //    children:
      //       just one, e.g. "reactionSuite"
      //
      // or something else if the tree was built in another manner. (The ability
      // to do that isn't something we've written yet.)

      // declaration node
      pugi::xml_node decl = xdoc.doc.append_child(pugi::node_declaration);
      for (auto &meta : node.metadata)
         decl.append_attribute(meta.first.c_str()) = meta.second.c_str();

      // ------------------------
      // children
      // ------------------------

      assert(node.children.size() == 1);  // e.g. reactionSuite
      assert(*node.children.begin() != nullptr);
      return detail::Node2xml(**node.children.begin(), xdoc.doc);
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
   // this issue if and when it becomes necessary to be more efficient.

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
