
namespace detail {

// -----------------------------------------------------------------------------
// Helpers for convert(*,JSON)
// -----------------------------------------------------------------------------

// node2json
template<class NODE>
bool node2json(
   const NODE &node, nlohmann::json &j,
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
   // is null (so that nothing is entered later), e.g. in XML's <something/>.
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
   // name appears multiple times, we must deal with that. For each represented
   // child name, the map gets 0 if the name appears once, 1 if it appears more
   // than once. Later, this 0/1 is used initially to make a boolean choice;
   // then it serves as a counter to generate a 0-indexed numeric suffix that
   // makes the child names unique: name0, name1, etc.
   std::map<std::string,size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0}); // once (so far)
      else
         iter->second = 1; // more than once
   }

   // now revisit and process the child nodes
   for (auto &c : node.children) {
      const size_t counter = childNames.find(c->name)->second++;
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

// internal_xml_node2Node
inline bool internal_xml_node2Node(const std::string &str)
{
   log::error(
      "Internal error in detail::xml_node2Node(pugi::xml_node,Node):\n"
      "type pugi::{} found, but not handled, as sub-element",
      str
   );
   throw std::exception{};
   return false; // in case we allow exceptions to be turned off
}

// pugi::xml_node ==> Node
template<class NODE>
bool xml_node2Node(const pugi::xml_node &xnode, NODE &node)
{
   // check destination node
   if (!node.empty()) {
      log::error(
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

      // I don't think that the following should ever appear in this context
      if (xsub.type() == pugi::node_document)
         return internal_xml_node2Node("node_document");
      if (xsub.type() == pugi::node_declaration)
         return internal_xml_node2Node("node_declaration");

      // For now I won't handle these; let's ensure that we don't see them
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
         } catch (...) {
            // recursive; no point printing error context, so just throw
            throw;
         }
         continue;
      }

      // ------------------------
      // cdata, pcdata, comment
      // ------------------------

      // We'll store these in a special manner as children of the current node,
      // reflecting how they arrived through pugi xml. Our manner of storing
      // them will allow us to maintain their original ordering if, say, someone
      // reads an XML, makes modest modifications or additions to data here and
      // there, and then writes an XML back out. GNDS has no ordering, so doing
      // this isn't necessary. It is, however, easy to handle, and users may
      // appreciate that GNDStk doesn't toss comments, or mess with the ordering
      // of cdata, pcdata, or comment nodes, either individually or together.
      // Of note, all bets are off if someone converts to JSON and back, because
      // the nlohmann JSON library reorders everything lexicographically.

      if (xsub.type() == pugi::node_cdata) {
         node.add("cdata").add("text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_pcdata) {
         node.add("pcdata").add("text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_comment) {
         node.add("comment").add("text", xsub.value());
         continue;
      }

      // ------------------------
      // well we missed something
      // ------------------------

      log::error(
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
   log::error(
      "Internal error in detail::json2node(nlohmann::json,Node):\n"
      "message is \"{}\"; please let us know about this",
      str
   );
   throw std::exception{};
   return false; // in case we allow exceptions turned off
}


template<class NODE>
bool json2node(const nlohmann::json::const_iterator &iter, NODE &node)
{
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
         } catch (...) {
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
template<class NODEFROM, class NODETO>
inline void node2Node(const NODEFROM &from, NODETO &to)
{
   // clear
   to.clear();

   // name
   to.name = from.name;

   // metadata
   for (auto &m : from.metadata)
      to.add(m.first,m.second);

   // children
   for (auto &c : from.children)
      node2Node(*c, to.add());
}



// -----------------------------------------------------------------------------
// Helpers for convert(*,XML)
// -----------------------------------------------------------------------------

// check_special
template<class NODE>
bool check_special(const NODE &node, const std::string &label)
{
   if (node.children.size() != 0) {
      log::error(
         "Internal error in detail::node2XML(Node,pugi::xml_node):\n"
         "ill-formed <" + label + "> node; "
         "should have 0 children, but has {}",
         node.children.size()
      );
      throw std::exception{};
      return false;
   }

   if (node.metadata.size() != 1) {
      log::error(
         "Internal error in detail::node2XML(Node,pugi::xml_node):\n"
         "ill-formed <" + label + "> node; "
         "should have 1 metadatum, but has {}",
         node.metadata.size()
      );
      throw std::exception{};
      return false;
   }

   if (node.metadata.begin()->first != "text") {
      log::error(
         "Internal error in detail::node2XML(Node,pugi::xml_node):\n"
         "ill-formed <" + label + "> node; "
         "should have metadatum key \"text\", but has key \"{}\"",
         node.metadata.begin()->first
      );
      throw std::exception{};
      return false;
   }

   return true;
}



// write_cdata
template<class NODE>
bool write_cdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"cdata")) return false;
   xnode.append_child(pugi::node_cdata).set_value(node.meta("text").c_str());
   return true;
}

// write_pcdata
template<class NODE>
bool write_pcdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"pcdata")) return false;
   xnode.append_child(pugi::node_pcdata).set_value(node.meta("text").c_str());
   return true;
}

// write_comment
template<class NODE>
bool write_comment(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"comment")) return false;
   xnode.append_child(pugi::node_comment).set_value(node.meta("text").c_str());
   return true;
}



// node2XML
template<class NODE>
bool node2XML(const NODE &node, pugi::xml_node &x)
{
   // name
   pugi::xml_node xnode = x.append_child(node.name.c_str());

   // metadata
   for (auto &meta : node.metadata)
      xnode.append_attribute(meta.first.c_str()) = meta.second.c_str();

   // children
   for (auto &child : node.children) {
      try {
         // special element
         if (child->name == "cdata")
            { if (write_cdata  (*child,xnode)) continue; else return false; }
         if (child->name == "pcdata")
            { if (write_pcdata (*child,xnode)) continue; else return false; }
         if (child->name == "comment")
            { if (write_comment(*child,xnode)) continue; else return false; }

         // typical element
         if (!node2XML(*child,xnode))
            return false;
      } catch (...) {
         // recursive; no point in printing error context; just throw
         throw;
      }
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// check_top
// -----------------------------------------------------------------------------

inline void check_top(
   const std::string &top,
   const std::string &type,
   const std::string &context
) {
   if (AllowedTop.find(top) == AllowedTop.end()) {
      std::string message =
         "Name \"{}\" in {} object's top-level node is not recognized\n"
         "in our list of allowable names for top-level GNDS nodes:\n";
      for (const std::string &n : detail::AllowedTop)
         message += "   \"" + n + "\"\n";
      message += "Creating node \"{}\" anyway...";
      log::warning(message, top, type, top);
      log::function(context);
   }
}

} // namespace detail
