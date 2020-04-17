
namespace detail {

// -----------------------------------------------------------------------------
// Helpers for convert(*,JSON)
// -----------------------------------------------------------------------------

// node2json
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool node2json(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node,
   nlohmann::json &j,
   const std::string &suffix = ""
) {
   // Original node name, and suffixed name. The latter is for handling child
   // nodes of the same name under the same parent node, and includes a numeric
   // suffix (so, name0, name1, etc.) in that scenario. This is needed for JSON
   // because JSON doesn't support same-named child nodes. In cases where the
   // name was unique to begin with, nameOriginal == nameSuffixed.
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // This also triggers node creation, in the event that the node exists but
   // is null (so that nothing is entered below). E.g. in XML: <something/>.
   auto &json = j[nameSuffixed];

   // ------------------------
   // metadata ==> json
   // ------------------------

   if (suffix != "")
      json["nodeName"] = nameOriginal;

   for (auto &meta : node.metadata)
      json["attributes"][meta.first] = meta.second;

   // ------------------------
   // children ==> json
   // ------------------------

   // First, account for what children appear in the current node. If any child
   // names appear multiple times, we must deal with that. For each represented
   // child name, the map gets 0 if the name appears once, 1 if it appears more
   // than once. Later, this 0/1 is used initially to make a boolean choice;
   // then it serves as a counter to generate a 0-indexed numeric suffix that
   // makes the child names unique: name0, name1, etc.
   std::map<std::string,unsigned> childNames;
   for (auto &c : node.children)
      if (c != nullptr) {
         auto iter = childNames.find(c->name);
         if (iter == childNames.end())
            childNames.insert({c->name,0}); // once (so far)
         else
            iter->second = 1; // more than once
      }

   // now revisit and process the child nodes
   for (auto &c : node.children)
      if (c != nullptr) {
         const unsigned counter = childNames.find(c->name)->second++;
         if (!node2json(*c, json, counter ? std::to_string(counter-1) : ""))
            return false;
      }

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
      node_pcdata,      // Plain character data, i.e. 'foo'
      node_cdata,       // Character data, i.e. '<![CDATA[foo]]>'
      node_comment,     // Comment tag, i.e. '<!-- foo -->'
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
      // not handled right now
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
      // element (typical case)
      // ------------------------

      if (xsub.type() == pugi::node_element) {
         if (not xmlnode2Node(xsub,node.add()))
            return false;
         continue;
      }

      // ------------------------
      // cdata, pcdata, comment
      // ------------------------

      // We'll store these as metadata for the current node;
      // they aren't really children in the usual XML sense.

      // cdata (from '<![CDATA[foo]]>')
      if (xsub.type() == pugi::node_cdata) {
         assert(xsub.value() == xsub.text().get());
         node.add(keyword_cdata, xsub.value());
         continue;
      }

      // pcdata (from 'foo'; plain character data)
      if (xsub.type() == pugi::node_pcdata) {
         assert(xsub.value() == xsub.text().get());
         node.add(keyword_pcdata, xsub.value());
         continue;
      }

      // comment (from '<!-- foo -->')
      if (xsub.type() == pugi::node_comment) {
         node.add(keyword_comment, xsub.value());
         continue;
      }

      // ------------------------
      // well we missed something
      // ------------------------

      assert(false);
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
   const GNDStk::XML &x,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // visit the XML's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : x.doc.children()) {
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
// Why the iterator rather than the json object? I found that there were some
// seemingly funny semantics in the json library. As we can see below, we have
// for example iter->is_object() (so, the -> operator, typical for iterators),
// but also iter.value() (the . operator - on an iterator). Similarly, also
// seen below, with the sub-elements. This is why we are, for now, writing
// our for-loops, here as well as in the functions that call this, in the older
// iterator form rather than the range-based-for form. Perhaps there's a way
// to reformulate all this in a shorter way, but this is what we have for now.
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool json2node(
   const nlohmann::json::const_iterator &iter,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   // the node sent here should be fresh, ready to receive entries...
   assert(node.empty());
   // non-object cases were handled before a caller calls this function...
   assert(iter->is_object());
   // any "attributes" key should have been handled at the parent level...
   assert(iter.key() != "attributes");

   // key,value ==> node name, json value to bring in
   node.name = iter.key();
   const nlohmann::json &json = iter.value();

   // elements
   for (auto elem = json.begin();  elem != json.end();  ++elem) {
      if (elem.key() == "nodeName") {
         // nodeName? ...extract as current node's true name
         node.name = elem->get<std::string>();
      } else if (elem.key() == "attributes") {
         // attributes? ...extract as current node's metadata
         const auto &jsub = elem.value();
         for (auto attr = jsub.begin();  attr != jsub.end();  ++attr)
            node.add(attr.key(), attr->get<std::string>());
      } else if (elem->is_string()) {
         // string? ...extract as metadata key/value pair
         node.add(elem.key(), elem->get<std::string>());
      } else if (elem->is_object()) {
         // {} object? ...extract as normal child node
         if (!json2node(elem,node.add()))
            return false;
      } else if (elem->is_null()) {
         // null node? ...extract as normal (albeit empty) child node
         // In GNDS, e.g. XML's <RutherfordScattering/> or <isotropic2d/>
         node.add().name = elem.key();
      } else {
         // no other cases are recognized now
         assert(false);
      }
   }

   // done
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
