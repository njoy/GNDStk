
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// error_xml2node
inline void error_xml2node(const std::string &type)
{
   log::error(
     "Internal error in xml2node(pugi::xml_node, Node):\n"
     "Type pugi::{} found, but not handled, as sub-element.",
      type
   );
   throw std::exception{};
}


// -----------------------------------------------------------------------------
// xml2node
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
template<class NODE>
bool xml2node(const pugi::xml_node &xnode, NODE &node)
{
   static const std::string context =
      "xml2node(pugi::xml_node, Node)";

   // check destination node
   if (!node.empty()) {
      log::error(
         "Internal error in xml2node(pugi::xml_node, Node):\n"
         "Destination Node is supposed to arrive here empty, but didn't."
      );
      throw std::exception{};
   }

   // name
   node.name = xnode.name();

   // metadata
   for (const pugi::xml_attribute &xattr : xnode.attributes())
      node.add(xattr.name(), xattr.value());

   // children (sub-nodes)
   for (const pugi::xml_node &xsub : xnode) {

      // ------------------------
      // not handled right now
      // ------------------------

      // I don't think that the following should ever appear in this context
      if (xsub.type() == pugi::node_document)
         error_xml2node("node_document");
      if (xsub.type() == pugi::node_declaration)
         error_xml2node("node_declaration");

      // For now I won't handle these; let's ensure that we don't see them
      if (xsub.type() == pugi::node_null)
         error_xml2node("node_null");
      if (xsub.type() == pugi::node_pi)
         error_xml2node("node_pi");
      if (xsub.type() == pugi::node_doctype)
         error_xml2node("node_doctype");

      // ------------------------
      // element (typical case)
      // ------------------------

      if (xsub.type() == pugi::node_element) {
         try {
            if (!xml2node(xsub,node.add()))
               return false;
         } catch (...) {
            log::function(context);
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
         node.add("#cdata").add("#text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_pcdata) {
         node.add("#pcdata").add("#text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_comment) {
         node.add("#comment").add("#text", xsub.value());
         continue;
      }

      // ------------------------
      // well we missed something
      // ------------------------

      log::error(
         "Internal error in xml2node(pugi::xml_node, Node):\n"
         "Encountered a pugi:: node type that we don't know about."
      );
      throw std::exception{};
   }

   // done
   return true;
}