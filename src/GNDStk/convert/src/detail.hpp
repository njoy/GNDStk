
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



// Helper
inline bool internal_xml_node2Node(const std::string &str)
{
   njoy::Log::error(
      "Internal error in detail::xml_node2Node(pugi::xml_node,Node):\n"
      "type pugi::{} found, but not handled, as sub-element",
      str
   );
   throw std::exception{};
   return false; // in case we allow exceptions to be turned off
}



// pugi::xml_node ==> Node
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool xml_node2Node(
   const pugi::xml_node &xnode,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   // check destination node
   if (!node.empty()) {
      njoy::Log::error(
         "Internal error in detail::xml_node2Node(pugi::xml_node,Node):\n"
         "destination Node is supposed to arrive here empty, but didn't"
      );
      throw std::exception{};
      return false;
   }

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
         return internal_xml_node2Node("node_document");
      if (xsub.type() == pugi::node_declaration)
         return internal_xml_node2Node("node_declaration");

      // For now I won't handle these; let's ensure that we don't see them...
      if (xsub.type() == pugi::node_null)
         return internal_xml_node2Node("node_null");
      if (xsub.type() == pugi::node_pi)
         return internal_xml_node2Node("node_pi");
      if (xsub.type() == pugi::node_doctype)
         return internal_xml_node2Node("node_doctype");

      // ------------------------
      // element (typical case)
      // ------------------------

      if (xsub.type() == pugi::node_element) {
         try {
            if (!xml_node2Node(xsub,node.add()))
               return false;
         } catch (const std::exception &) {
            // recursive; no point printing error context; just throw
            throw;
         }
         continue;
      }

      // ------------------------
      // cdata, pcdata, comment
      // ------------------------

      // We'll store these as metadata for the current node;
      // they aren't really children in the usual XML sense.

      // cdata (from '<![CDATA[foo]]>')
      if (xsub.type() == pugi::node_cdata) {
         node.add(keyword_cdata, xsub.value());
         continue;
      }

      // pcdata (from 'foo'; plain character data)
      if (xsub.type() == pugi::node_pcdata) {
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

      njoy::Log::error(
         "Internal error in detail::xml_node2Node(pugi::xml_node,Node):\n"
         "we've encountered a pugi:: node type that we don't know about"
      );
      throw std::exception{};
      return false;
   }

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

// Helper
inline bool internal_json2node(const std::string &str)
{
   njoy::Log::error(
      "Internal error in detail::json2node(nlohmann::json,Node):\n"
      "message is \"{}\"; please let us know about this",
      str
   );
   throw std::exception{};
   return false; // in case we allow exceptions turned off
}


template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool json2node(
   const nlohmann::json::const_iterator &iter,
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   // the node sent here should be fresh, ready to receive entries...
   if (!node.empty())
      return internal_json2node("!node.empty()");

   // non-object cases were handled before a caller calls this function...
   if (!iter->is_object())
      return internal_json2node("!iter->is_object()");

   // any "attributes" key should have been handled at the parent level...
   if (iter.key() == "attributes")
      return internal_json2node("iter.key() == \"attributes\"");

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
         try {
            if (!json2node(elem,node.add()))
               return false;
         } catch (const std::exception &) {
            // recursive; no point printing error context; just throw
            throw;
         }
      } else if (elem->is_null()) {
         // null node? ...extract as normal (albeit empty) child node
         // In GNDS, e.g. XML's <RutherfordScattering/> or <isotropic2d/>
         node.add().name = elem.key();
      } else {
         // no other cases are handled right now
         return internal_json2node("unhandled JSON value type");
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
   // check destination node
   if (!to.empty()) {
      njoy::Log::error(
         "Internal error in detail::node2Node(Node,Node):\n"
         "destination Node is supposed to arrive here empty, but didn't"
      );
      throw std::exception{};
      return;
   }

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

      // ------------------------
      // PCDATA
      // ------------------------

      if (meta.first == keyword_pcdata) {
         if (node.children.size() != 0) {
            // From https://en.wikipedia.org/wiki/PCDATA
            //   "When declaring document elements. An element declaration
            //    employing the #PCDATA content model value does not allow
            //    for child elements." [Initial sentence fragment theirs.]
            // So, the following would appear to be reasonable.
            njoy::Log::error(
               "Internal error in detail::node2XML(Node,pugi::xml_node):\n"
               "node with PCDATA appears to have other elements as well,\n"
               "making the node ill-formed"
            );
            throw std::exception{};
            return false;
         }

         xnode.append_child(pugi::node_pcdata).set_value(meta.second.c_str());
         continue;
      }

      // ------------------------
      // CDATA
      // ------------------------

      if (meta.first == keyword_cdata) {
         if (node.children.size() != 0) {
            // Reading https://en.wikipedia.org/wiki/CDATA, I see nothing
            // to suggest that other child elements are disallowed in this
            // context. And, in fact, under "Uses of CDATA sections," they
            // speak of splitting CDATA into e.g. <![CDATA[]]]]><![CDATA[>]]>.
            // At the time of this writing, however, in official GNDS files,
            // I only see CDATA elements as singletons, and without siblings.
            // So, for now, I'll treat these as I do PCDATA elements (above).
            njoy::Log::error(
               "Internal error in detail::node2XML(Node,pugi::xml_node):\n"
               "node with CDATA appears to have other elements as well,\n"
               "making the node ill-formed"
            );
            throw std::exception{};
            return false;
         }

         xnode.append_child(pugi::node_cdata).set_value(meta.second.c_str());
         continue;
      }

      // ------------------------
      // comment
      // ------------------------

      if (meta.first == keyword_comment) {
         // Whoa, it seems that GNDS files sometimes have doubled-up comments,
         // e.g. <!-- foo --><!-- bar -->. So, no node.children.size() checks
         // here, as we did above for pcdata and cdata. Side note: the double
         // comments I'm seeing in some GNDS files arguably thumb their noses
         // at GNDS' "no element ordering" rule; although, the nature of the
         // offending comments, which appear to be intended as labels, e.g.
         //    <!--  energy | capture | elastic  -->
         //    <!--         |  width  |  width   -->
         // appears to make them amenable to proper interpretation/treatment.
         xnode.append_child(pugi::node_comment).set_value(meta.second.c_str());
         continue;
      }

      // ------------------------
      // regular element
      // ------------------------

      xnode.append_attribute(meta.first.c_str()) = meta.second.c_str();
   }

   // children
   for (auto &child : node.children) {
      try {
         if (child && !node2XML(*child, xnode))
            return false;
      } catch (const std::exception &) {
         // recursive; no point printing error context; just throw
         throw;
      }
   }

   // done
   return true;
}

} // namespace detail
