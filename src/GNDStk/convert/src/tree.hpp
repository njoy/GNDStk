
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
//
// Also:
// convert(*,Node) for * = XML/JSON
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
      if (from.has_decl()) to.add() = from.decl();
      if (from.has_top ()) to.add() = from.top ();
   } catch (...) {
      log::function("convert(Tree,Tree)");
      throw;
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// XML ==> Node
// XML ==> Tree
// -----------------------------------------------------------------------------

// XML ==> Node
inline bool convert(const XML &x, Node &node, const bool decl)
{
   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving object
   node.clear();

   // optionally, give it a boilerplate declaration node
   if (decl)
      node.add("xml"); // <== indicates that we built the object from an XML

   // empty xml document?
   if (x.empty())
      return true;

   try {

      // ------------------------
      // validate
      // ------------------------

      // Validation, itself, is independent of whether decl is true or false

      std::size_t size = 0;
      std::string one, two;
      for (const pugi::xml_node &xnode : x.doc) {
         size++;
         if (size == 1)
            one = xnode.name();
         else if (size == 2)
            two = xnode.name();
         else {
            log::error(
               "More than two main nodes in the XML\n",
               "You can have up to "
               "one declaration node and "
               "one document node"
            );
            throw std::exception{};
         }
      }

      // possibly redundant with the earlier empty() test, but harmless
      if (size == 0)
         return true;

      // if two main nodes, they can't be of the same type
      if (size == 2) {
         if (one == "xml" && two == "xml") {
            log::error("Two declaration nodes in the XML");
            throw std::exception{};
         }
         if (one != "xml" && two != "xml") {
            log::error("Two document nodes in the XML");
            throw std::exception{};
         }
      }

      // ------------------------
      // convert the nodes
      // ------------------------

      for (const pugi::xml_node &xnode : x.doc) {
         const std::string name = xnode.name();

         if (name == "xml") {
            // Declaration node
            // Retrieve any XML attributes, e.g. version and encoding
            if (decl)
               for (const pugi::xml_attribute &xattr : xnode.attributes())
                  node.one("xml").add(xattr.name(), xattr.value());
         } else {
            // Document node
            // We'll assume that a check for this being a valid top-level
            // GNDS node aligns with whether or not we're interested in any
            // declaration node that might exist, as both of those concerns
            // are associated with being at the top level of a GNDS tree
            if (decl)
               detail::check_top(name, "XML", "convert(XML,Node)");

            // Visit the node, and its children recursively
            if (!detail::xml2node(xnode, decl ? node.add() : node))
               return false;
         }
      }
   } catch (...) {
      log::function("convert(XML,Node)");
      throw;
   }

   // done
   return true;
}


// XML ==> Tree
inline bool convert(const XML &x, Tree &tree)
{
   try {
      return convert(x, *(Node*)&tree, true);
   } catch (...) {
      log::function("convert(XML,Tree)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// JSON ==> Node
// JSON ==> Tree
// -----------------------------------------------------------------------------

// JSON ==> Node
inline bool convert(const JSON &j, Node &node, const bool decl)
{
   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving object
   node.clear();

   // optionally, give it a boilerplate declaration node
   if (decl)
      node.add("json"); // <== indicates that we built the object from a JSON

   // empty json document?
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

      // a json document should have one main node
      if (size != 1) {
         // fixme Consider relaxing this, if doing so might ever make sense
         log::error("More than one main node in the JSON");
         throw std::exception{};
      }

      // ------------------------
      // convert the nodes
      // ------------------------

      const std::string name = j.doc.begin().key();

      // See comment above check_top() call in convert(XML,Node) above.
      // JSON documents don't have "declaration nodes," as XML documents
      // do, but here we interpret the bool decl parameter as essentially
      // indicating whether we're reading a Node (decl == false) or full
      // Tree (decl == true); and, the latter case suggests we're at the
      // top level, and should thus validate it as a top-level GNDS node.
      if (decl)
         detail::check_top(name, "JSON", "convert(JSON,Node)");

      // visit the node, and its children recursively
      if (!detail::json2node(j.doc.begin(), decl ? node.add() : node))
         return false;

   } catch (...) {
      log::function("convert(JSON,Node)");
      throw;
   }

   // done
   return true;
}


// JSON ==> Tree
inline bool convert(const JSON &j, Tree &tree)
{
   try {
      return convert(j, *(Node*)&tree, true);
   } catch (...) {
      log::function("convert(JSON,Tree)");
      throw;
   }
}
