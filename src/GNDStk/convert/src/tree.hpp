
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tree ==> Tree
// -----------------------------------------------------------------------------

inline bool convert(const Tree &from, Tree &to)
{
   // same Tree?
   if (&to == &from)
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



// -----------------------------------------------------------------------------
// XML ==> Tree
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, Tree &tree)
{
   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving tree
   tree.clear();

   // give it a boilerplate declaration node
   tree.add("xml"); // <== indicate that we built the tree from an XML

   // empty pugixml xml document?
   if (x.empty())
      return true;

   try {

      // ------------------------
      // validate
      // ------------------------

      std::size_t size = 0;
      std::string one, two;
      for (const pugi::xml_node &xnode : x.doc) {
         size++;
         if (size == 1)
            one = xnode.name();
         else if (size == 2)
            two = xnode.name();
         else {
            log::error("More than two outer nodes in the XML");
            log::info(
               "You can have up to "
               "one declaration node and "
               "one top-level node"
            );
            throw std::exception{};
         }
      }

      // possibly redundant with the earlier empty() test, but harmless
      if (size == 0)
         return true;

      // if two nodes, they can't be of the same type
      if (size == 2) {
         if (one == "xml" && two == "xml") {
            log::error("Two declaration nodes in the XML");
            throw std::exception{};
         }
         if (one != "xml" && two != "xml") {
            log::error("Two top-level nodes in the XML");
            throw std::exception{};
         }
      }

      // ------------------------
      // convert the nodes
      // ------------------------

      for (const pugi::xml_node &xnode : x.doc) {
         const std::string name = xnode.name();

         if (name == "xml") {
            // declaration node
            // retrieve any XML attributes, e.g. version and encoding
            for (const pugi::xml_attribute &xattr : xnode.attributes())
               tree.decl().add(xattr.name(), xattr.value());
         } else {
            // regular node
            // visit this node, and its children recursively
            detail::check_top(name, "XML", "convert(XML,Tree)");
            if (!detail::xml2node(xnode,tree.add()))
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



// -----------------------------------------------------------------------------
// JSON ==> Tree
// -----------------------------------------------------------------------------

inline bool convert(const JSON &j, Tree &tree)
{
   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving tree
   tree.clear();

   // give it a boilerplate declaration node
   tree.add("json"); // <== indicate that we built the tree from a JSON

   // empty nlohmann json document?
   if (j.empty())
      return true;

   try {

      // ------------------------
      // validate
      // ------------------------

      const std::size_t size = j.doc.size();

      // possibly redundant with the earlier empty() test, but harmless
      if (size == 0)
         return true;

      // a json document should have one outer element
      if (size != 1) {
         // fixme Consider relaxing this, if doing so might ever make sense
         log::error("More than one outer node in the JSON");
         throw std::exception{};
      }

      // ------------------------
      // convert the nodes
      // ------------------------

      {
         detail::check_top(j.doc.begin().key(), "JSON", "convert(JSON,Tree)");
         if (!detail::json2node(j.doc.begin(),tree.add()))
            return false;
      }
   } catch (...) {
      log::function("convert(JSON,Tree)");
      throw;
   }

   // done
   return true;
}
