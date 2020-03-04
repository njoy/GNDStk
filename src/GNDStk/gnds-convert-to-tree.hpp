
/*
Summary of the functions in this file:

namespace detail {
   1. xnode2Node ( pugi::xml_node, GNDStk::Node)
      ...uses (1) (itself)

   2. xml2Tree   ( GNDStk::xml,    GNDStk::Tree)
      ...uses (1)

   3. jiter2Node ( nlohmann::json::const_iterator, GNDStk::Node)
      ...uses (3) (itself)

   4. json2Tree  ( GNDStk::json,   GNDStk::Tree)
      ...uses (3)

   5. Node2Node  ( GNDStk::Node,   GNDStk::Node)
      ...uses (5) (itself)
}

6. convert(GNDStk::Tree, GNDStk::Tree)
   ...uses (5)

7. convert(GNDStk::xml,  GNDStk::Tree)
   ...uses (2)

8. convert(GNDStk::json, GNDStk::Tree)
   ...uses (4)
*/



// -----------------------------------------------------------------------------
// Helpers for xml-related converts
// -----------------------------------------------------------------------------

/*
FYI, here's the pugixml code for pugi::xml_node_type:

namespace pugi
{
   // Tree node types
   enum xml_node_type
   {
      node_null,        // Empty (null) node handle
      node_document,    // A document tree's absolute root
      node_element,     // Element tag, i.e. '<node/>'
      node_pcdata,      // Plain character data, i.e. 'text'
      node_cdata,       // Character data, i.e. '<![CDATA[text]]>'
      node_comment,     // Comment tag, i.e. '<!-- text -->'
      node_pi,          // Processing instruction, i.e. '<?name?>'
      node_declaration, // Document declaration, i.e. '<?xml version="1.0"?>'
      node_doctype      // Document type declaration, i.e. '<!DOCTYPE doc>'
   };
}
*/

namespace detail {

// pugi::xml_node ==> Node
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool xnode2Node(
   const pugi::xml_node &xnode,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
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
      // PCDATA, CDATA, comment
      // ------------------------

      // We'll store these as metadata for the current node;
      // they aren't really children in the usual XML sense.

      // PCDATA
      if (xsub.type() == pugi::node_pcdata) {
         assert(xsub.value() == xsub.text().get());
         node.push(keyword_pcdata, xsub.value());
         continue;
      }

      // CDATA
      if (xsub.type() == pugi::node_cdata) {
         assert(xsub.value() == xsub.text().get());
         node.push(keyword_cdata, xsub.value());
         continue;
      }

      // comment
      if (xsub.type() == pugi::node_comment) {
         node.push(keyword_comment, xsub.value());
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(xsub.type() == pugi::node_element);
      if (not xnode2Node(xsub,node.push()))
         return false;
   }

   // done
   return true;
}



// xml ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool xml2Tree(
   const GNDStk::xml &xdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // visit the xml's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root =
            std::make_shared<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>();
         tree.root->name = "xml"; // indicates that we came from a xml

         // base xml "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &xattr : xnode.attributes())
            tree.root->push(xattr.name(), xattr.value());
      }

      if (count == 1) {
         // visit the xml's outer node, and its descendants
         if (not xnode2Node(xnode,tree.root->push()))
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
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool jiter2Node(
   const nlohmann::json::const_iterator &jiter,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
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
         if (not jiter2Node(sub,node.push()))
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
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool json2Tree(
   const GNDStk::json &jdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // initialize root
   tree.root = std::make_shared<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>();
   tree.root->name = "json"; // indicates that we came from a json

   // visit the json's outer node, and its descendants
   for (auto elem = jdoc.doc.begin();  elem != jdoc.doc.end();  ++elem)
      if (not jiter2Node(elem,tree.root->push()))
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
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline void Node2Node(
   const GNDStk::Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
   GNDStk::Node<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &to
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
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline bool convert(
   const GNDStk::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
   GNDStk::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &to
) {
   // casts needed here because template arguments may be different...
   if ((void*)&to == (void*)&from)
      return true;

   // clear
   to.clear();

   // convert
   if (not from.empty()) {
      to.root =
         std::make_shared<Node<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO>>();
      detail::Node2Node(*from.root, *to.root);
   }

   // done
   return true;
}


// xml ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline bool convert(
   const GNDStk::xml &xdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   return detail::xml2Tree(xdoc,tree);
}


// json ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline bool convert(
   const GNDStk::json &jdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   return detail::json2Tree(jdoc,tree);
}
