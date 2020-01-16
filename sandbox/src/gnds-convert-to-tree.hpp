
/*
Summary of the functions in this file:

namespace detail {
   1. xnode2Node ( pugi::xml_node,                 gnds::Node)
      ...uses (1) (itself)

   2. xml2Tree   ( gnds::xml,                      gnds::Tree)
      ...uses (1)

   3. jiter2Node ( nlohmann::json::const_iterator, gnds::Node)
      ...uses (3) (itself)

   4. json2Tree  ( gnds::json,                     gnds::Tree)
      ...uses (3)

   5. Node2Node  ( gnds::Node,                     gnds::Node)
      ...uses (5) (itself)
}

6. convert(gnds::Tree, gnds::Tree)
   ...uses (5)

7. convert(gnds::xml,  gnds::Tree)
   ...uses (2)

8. convert(gnds::json, gnds::Tree)
   ...uses (4)
*/



// -----------------------------------------------------------------------------
// Helpers for xml-related converts
// -----------------------------------------------------------------------------

namespace detail {

// pugi::xml_node ==> Node
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool xnode2Node(const pugi::xml_node &xnode, gnds::Node<MCON,CCON> &node)
{
   // name
   node.name = xnode.name();

   // metadata
   for (const pugi::xml_attribute &xattr : xnode.attributes())
      node.push(xattr.name(), xattr.value());

   // children (sub-nodes)
   for (const pugi::xml_node &xsub : xnode.children()) {

      // ------------------------
      // Not handled right now
      // ------------------------

      // I don't think that the following should ever appear in this context...
      if (xsub.type() == pugi::node_document)
         assert(false);
      if (xsub.type() == pugi::node_declaration)
         assert(false);

      // For now I won't handle these; let's ensure that we don't see them...
      if (xsub.type() == pugi::node_null)
         assert(false);
      if (xsub.type() == pugi::node_pi)
         assert(false);
      if (xsub.type() == pugi::node_doctype)
         assert(false);

      // ------------------------
      // Comment, CDATA, PCDATA
      // ------------------------

      // We'll store these as metadata for the current node;
      // they aren't really children in the usual XML sense.

      // comment
      // Use "comment"
      if (xsub.type() == pugi::node_comment) {
         node.push("comment", xsub.value());
         continue;
      }

      // CDATA
      // Use "text"
      if (xsub.type() == pugi::node_cdata) {
         assert(xsub.value() == xsub.text().get());
         node.push("text", xsub.value());
         continue;
      }

      // PCDATA
      // use "body"
      if (xsub.type() == pugi::node_pcdata) {
         assert(xsub.value() == xsub.text().get());
         node.push("body", xsub.value());
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(xsub.type() == pugi::node_element);
      if (!xnode2Node(xsub,node.push()))
         return false;
   }

   // done
   return true;
}



// xml ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool xml2Tree(const gnds::xml &xdoc, gnds::Tree<MCON,CCON> &tree)
{
   // clear
   tree.clear();

   // visit the xml's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root = std::make_shared<Node<MCON,CCON>>();
         tree.root->name = "xml"; // indicates that we came from a xml

         // base xml "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &xattr : xnode.attributes())
            tree.root->push(xattr.name(), xattr.value());
      }

      if (count == 1) {
         // visit the xml's outer node, and its descendants
         if (!xnode2Node(xnode,tree.root->push()))
            return false;
      }

      // a proper XML document should contain just one outer node; we expect
      // two (but no more) only because we loaded the file with a flag that
      // said to include the <?xml ... ?> material as part of the deal
      if (count >= 2)
         assert(false);
      count++;
   }
   assert(count == 2);

   // done
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// Helpers for json-related converts
// -----------------------------------------------------------------------------

namespace detail {

// nlohmann::json::const_iterator ==> Node
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool jiter2Node(
   const nlohmann::json::const_iterator &jiter,
   gnds::Node<MCON,CCON> &node
) {
   assert(jiter->is_object());

   // name
   node.name = jiter.key();

   // elements
   const nlohmann::json &value = jiter.value();
   for (auto sub = value.begin();  sub != value.end();  ++sub) {
      if (sub->is_null()) {
         // The current node has a child node with neither metadata
         // nor its own children. This would come about, for example,
         // if the .json file was created, earlier, based on an .xml
         // file with a construct like <RutherfordScattering/>, i.e.
         // with /> to end the element immediately.
         node.push().name = sub.key();
      } else if (sub->is_object()) {
         // The current node has a child node *other* than as above.
         if (!jiter2Node(sub,node.push()))
            return false;
      } else {
         // The current node has this as a key/value metadata pair...
         node.push(sub.key(), sub->get<std::string>());
      }
   }

   // done
   return true;
}



// json ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool json2Tree(const gnds::json &jdoc, gnds::Tree<MCON,CCON> &tree)
{
   // clear
   tree.clear();

   // initialize root
   tree.root = std::make_shared<Node<MCON,CCON>>();
   tree.root->name = "json"; // indicates that we came from a json

   // visit the json's outer node, and its descendants
   for (auto elem = jdoc.doc.begin();  elem != jdoc.doc.end();  ++elem)
      if (!jiter2Node(elem,tree.root->push()))
         return false;

   // done
   tree.normalize();
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// Helper for tree-to-tree convert
// -----------------------------------------------------------------------------

namespace detail {

// Node ==> Node
template<
   template<class...> class MCONFROM,
   template<class...> class CCONFROM,
   template<class...> class MCONTO,
   template<class...> class CCONTO
>
inline void Node2Node(
   const gnds::Node<MCONFROM,CCONFROM> &from,
   gnds::Node<MCONTO,CCONTO> &to
) {
   // name
   to.name = from.name;

   // metadata
   for (auto &m : from.metadata)
      to.push(m);

   // children
   for (auto &c : from.children)
      if (c)
         Node2Node(*c, to.push());
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: (xml|json) to Tree
// I.e., convert from one of our xml or json objects (wrappers around
// pugi::xml_document and nlohmann::json) to an object of our Tree structure.
// -----------------------------------------------------------------------------

// Tree ==> Tree
template<
   template<class...> class MCONFROM,
   template<class...> class CCONFROM,
   template<class...> class MCONTO,
   template<class...> class CCONTO
>
inline bool convert(
   const gnds::Tree<MCONFROM,CCONFROM> &from,
   gnds::Tree<MCONTO,CCONTO> &to
) {
   // casts needed here because template arguments may be different...
   if ((void*)&to == (void*)&from)
      return true;

   // clear
   to.clear();

   // convert
   if (from.root) {
      to.root = std::make_shared<Node<MCONTO,CCONTO>>();
      detail::Node2Node(*from.root, *to.root);
   }

   // done
   return true;
}


// xml ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool convert(const gnds::xml &xdoc, gnds::Tree<MCON,CCON> &tree)
{
   return detail::xml2Tree(xdoc,tree);
}


// json ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool convert(const gnds::json &jdoc, gnds::Tree<MCON,CCON> &tree)
{
   return detail::json2Tree(jdoc,tree);
}
