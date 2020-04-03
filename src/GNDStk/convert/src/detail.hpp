
namespace detail {

// -----------------------------------------------------------------------------
// Helpers for convert(*,JSON)
// -----------------------------------------------------------------------------

// prefix
inline std::string prefix(const unsigned long n)
{
   std::ostringstream oss;
   oss << std::setfill('0') << std::setw(12) << n;
   return oss.str();
}



// node2json
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool node2json(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node,
   nlohmann::json &j,
   unsigned long &kwdcount
) {
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
      if (child and not node2json(*child, j[nodename], kwdcount))
         return false;

   // done
   return true;
}



// -----------------------------------------------------------------------------
// Helpers for convert(*,tree)
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

// pugi::xml_node ==> Node
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool xmlnode2Node(
   const pugi::xml_node &xnode,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   assert(node.empty());

   // name
   node.name = xnode.name();

   // metadata
   for (const pugi::xml_attribute &xattr : xnode.attributes())
      node.add(xattr.name(), xattr.value());

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
         node.add(keyword_pcdata, xsub.value());
         continue;
      }

      // CDATA
      if (xsub.type() == pugi::node_cdata) {
         assert(xsub.value() == xsub.text().get());
         node.add(keyword_cdata, xsub.value());
         continue;
      }

      // comment
      if (xsub.type() == pugi::node_comment) {
         node.add(keyword_comment, xsub.value());
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(xsub.type() == pugi::node_element);
      if (not xmlnode2Node(xsub,node.add()))
         return false;
   }

   // done
   return true;
}



// XML ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool XML2Tree(
   const GNDStk::XML &xdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // visit the XML's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root =
            std::make_unique<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>();
         tree.root->name = "xml"; // indicates that we came from an XML

         // base XML "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &xattr : xnode.attributes())
            tree.root->add(xattr.name(), xattr.value());
      }

      if (count == 1) {
         // visit the XML's outer node, and its descendants
         if (not xmlnode2Node(xnode,tree.root->add()))
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



// nlohmann::json::const_iterator ==> Node
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool jiter2Node(
   const nlohmann::json::const_iterator &jiter,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   assert(node.empty());
   assert(jiter->is_object());

   // name
   node.name = jiter.key();

   // elements
   const nlohmann::json &value = jiter.value();
   for (auto sub = value.begin();  sub != value.end();  ++sub) {
      if (sub->is_null()) {
         // The current node has a child node with neither metadata
         // nor its own children. This would come about, for example,
         // if the JSON file was created, earlier, based on an XML
         // file with a construct like <RutherfordScattering/>, i.e.
         // with /> to end the element immediately.
         node.add().name = sub.key();
      } else if (sub->is_object()) {
         // The current node has a child node *other* than as above.
         if (not jiter2Node(sub,node.add()))
            return false;
      } else {
         // The current node has this as a key/value metadata pair...
         node.add(sub.key(), sub->get<std::string>());
      }
   }

   // done
   return true;
}



// JSON ==> Tree
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool JSON2Tree(
   const GNDStk::JSON &jdoc,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // initialize root
   tree.root = std::make_unique<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>();
   tree.root->name = "json"; // indicates that we came from a JSON

   // visit the JSON's outer node, and its descendants
   for (auto elem = jdoc.doc.begin();  elem != jdoc.doc.end();  ++elem)
      if (not jiter2Node(elem,tree.root->add()))
         return false;

   // done
   tree.normalize();
   return true;
}



// Node ==> Node
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
inline void node2Node(
   const GNDStk::Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
   GNDStk::Node<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &to
) {
   assert(to.empty());

   // name
   to.name = from.name;

   // metadata
   for (auto &m : from.metadata)
      to.add(m);

   // children
   for (auto &c : from.children)
      if (c)
         node2Node(*c, to.add());
}



// -----------------------------------------------------------------------------
// Helpers for convert(*,XML)
// -----------------------------------------------------------------------------

// node2XML
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool node2XML(
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
      if (child and not node2XML(*child, xnode))
         return false;

   // done
   return true;
}

} // namespace detail
