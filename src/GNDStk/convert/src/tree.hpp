
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
// -----------------------------------------------------------------------------

// ------------------------
// Tree ==> Tree
// ------------------------

inline bool convert(const Tree &from, Tree &to)
{
   // void* because template arguments could differ
   if ((void*)&to == (void*)&from)
      return true;

   // clear
   to.clear();

   // convert
   try {
      if (from.has_decl())
         to.add() = from.decl();
      if (from.has_top())
         to.add() = from.top();
   } catch (...) {
      log::function("convert(Tree,Tree)");
      throw;
   }

   // done
   return true;
}



// ------------------------
// XML ==> Tree
// ------------------------

inline bool convert(const XML &x, Tree &tree)
{
   // clear the receiving tree
   tree.clear();

   // the pugixml xml document might have nothing in it;
   // in this case, we'll leave the tree completely empty
   if (x.empty())
      return true;

   // make a boilerplate declaration node
   tree.add("xml"); // indicates that we built the tree from an XML

   // visit the pugixml document's nodes
   try {
      bool found_top = false;
      for (const pugi::xml_node &xnode : x.doc.children()) {
         const std::string top = xnode.name();

         if (top == std::string("xml")) {
            // looks like a declaration node
            // retrieve any XML attributes, e.g. version and encoding
            for (const pugi::xml_attribute &xattr : xnode.attributes())
               tree.decl().add(xattr.name(), xattr.value());
         } else {
            // looks like a regular node
            if (found_top) {
               log::error("More than one top-level node in the XML");
               throw std::exception{};
            }
            found_top = true;

            // visit this node, as well as its descendants recursively
            detail::check_top(top, "XML", "convert(XML,Tree)");
            if (!detail::xml_node2Node(xnode,tree.add()))
               return false;
         }
      }
   } catch (...) {
      log::function("convert(XML,Tree)");
      throw;
   }

   // done
   return true;
}



// ------------------------
// JSON ==> Tree
// ------------------------

inline bool convert(const JSON &j, Tree &tree)
{
   // clear the receiving tree
   tree.clear();

   // the nlohmann json document might have nothing in it;
   // in this case, we'll leave the tree completely empty
   if (j.empty())
      return true;

   // make a boilerplate declaration node
   tree.add("json"); // indicates that we built the tree from a JSON

   // the nlohmann json document should have one outer element
   if (j.doc.size() != 1) {
      // fixme Consider relaxing this, if doing so might ever make sense
      log::error("More than one top-level node in the JSON");
      throw std::exception{};
   }

   // visit the JSON's outer node, and its descendants
   try {
      detail::check_top(j.doc.begin().key(), "JSON", "convert(JSON,Tree)");
      if (!detail::json2node(j.doc.begin(),tree.add()))
         return false;
      } catch (...) {
         log::function("convert(JSON,Tree)");
         throw;
      }

   // done
   return true;
}
