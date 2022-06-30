
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// check_special
template<class NODE>
bool check_special(const NODE &node, const std::string &label)
{
   if (node.children.size() != 0) {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have 0 children, but has {}.",
         node.children.size()
      );
      throw std::exception{};
   }

   if (node.metadata.size() != 1) {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have 1 metadatum, but has {}.",
         node.metadata.size()
      );
      throw std::exception{};
   }

   if (node.metadata.begin()->first != "#text") {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have metadatum key \"#text\", but has key \"{}\".",
         node.metadata.begin()->first
      );
      throw std::exception{};
   }

   return true;
}

// write_cdata
template<class NODE>
bool write_cdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#cdata")) return false;
   xnode.append_child(pugi::node_cdata).set_value(node.meta("#text").data());
   return true;
}

// write_pcdata
template<class NODE>
bool write_pcdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#pcdata")) return false;
   xnode.append_child(pugi::node_pcdata).set_value(node.meta("#text").data());
   return true;
}

// write_comment
template<class NODE>
bool write_comment(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#comment")) return false;
   xnode.append_child(pugi::node_comment).set_value(node.meta("#text").data());
   return true;
}


// -----------------------------------------------------------------------------
// node2xml
// -----------------------------------------------------------------------------

template<class NODE>
bool node2xml(const NODE &node, pugi::xml_node &x)
{
   static const std::string context =
      "node2xml(Node, pugi::xml_node)";

   // name
   pugi::xml_node xnode = x.append_child(node.name.data());

   // metadata
   for (auto &meta : node.metadata)
      xnode.append_attribute(meta.first.data()) = meta.second.data();

   // children
   for (auto &child : node.children) {
      try {
         // special element
         if (child->name == "#cdata")
            { if (write_cdata  (*child,xnode)) continue; else return false; }
         if (child->name == "#pcdata")
            { if (write_pcdata (*child,xnode)) continue; else return false; }
         if (child->name == "#comment")
            { if (write_comment(*child,xnode)) continue; else return false; }

         // typical element
         if (!node2xml(*child,xnode))
            return false;
      } catch (...) {
         log::function(context);
         throw;
      }
   }

   // done
   return true;
}
