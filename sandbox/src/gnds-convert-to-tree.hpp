
/*
Summary of functions in this file:

namespace detail {
   1. xnode2node ( pugi::xml_node,                 gnds::Node)
      ...calls (1) (itself)

   2. xml2tree   ( gnds::xml,                      gnds::Tree)
      ...calls (1)

   3. jiter2node ( nlohmann::json::const_iterator, gnds::Node)
      ...calls (3) (itself)

   4. json2tree  ( gnds::json,                     gnds::Tree)
      ...calls (3)
}

5. convert(gnds::xml,  gnds::Tree)
   ...calls (2)

6. convert(gnds::json, gnds::Tree)
   ...calls (4)
*/



// -----------------------------------------------------------------------------
// Helpers for xml-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// pugi::xml_node ==> Node
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool xnode2node(const pugi::xml_node &xnode, gnds::Node<MCON,CCON> &node)
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
      debug("new node");
      auto &back = node.push(new Node<MCON,CCON>);
      if (!xnode2node(xsub,back))
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
bool xml2tree(const gnds::xml &xdoc, gnds::Tree<MCON,CCON> &tree)
{
   // prepare output
   tree.clear();

   // visit the xml document's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root = std::make_shared<Node<MCON,CCON>>();
         tree.root->name = "xml"; // indicates that we came from a xml

         // base document "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &xattr : xnode.attributes())
            tree.root->push(xattr.name(), xattr.value());
      }

      if (count == 1) {
         // visit the document's outer node, and its descendants
         debug("new node");
         auto &back = tree.root->push(new Node<MCON,CCON>);
         if (!detail::xnode2node(xnode,back))
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
// Helpers for json-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// nlohmann::json::const_iterator ==> Node
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool jiter2node(
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
         auto &back = node.push(new Node<MCON,CCON>);
         back.name = sub.key();
      } else if (sub->is_object()) {
         // The current node has a child node *other* than as above.
         debug("new node");
         auto &back = node.push(new Node<MCON,CCON>);
         if (!jiter2node(sub,back))
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
bool json2tree(const gnds::json &jdoc, gnds::Tree<MCON,CCON> &tree)
{
   // prepare output
   tree.clear();

   // initialize base document
   tree.root = std::make_shared<Node<MCON,CCON>>();
   tree.root->name = "json"; // indicates that we came from a json

   // visit the document's outer node, and its descendants
   for (auto elem = jdoc.doc.begin();  elem != jdoc.doc.end();  ++elem) {
      debug("new node");
      auto &back = tree.root->push(new Node<MCON,CCON>);
      if (!detail::jiter2node(elem,back))
         return false;
   }

   // done
   tree.normalize();
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: (xml|json) to Tree
// I.e., convert from one of our xml or json objects (wrappers around
// pugi::xml_document and nlohmann::json) to an object of our Tree structure.
// -----------------------------------------------------------------------------

// xml ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool convert(const gnds::xml &xdoc, gnds::Tree<MCON,CCON> &tree)
{
   return detail::xml2tree(xdoc,tree);
}



// json ==> Tree
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool convert(const gnds::json &jdoc, gnds::Tree<MCON,CCON> &tree)
{
   return detail::json2tree(jdoc,tree);
}
