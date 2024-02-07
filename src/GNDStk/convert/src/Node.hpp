
// -----------------------------------------------------------------------------
// XML ==> Node
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, Node &node, const bool &DECL)
{
   const bool decl = detail::getDecl(node,DECL);

   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving node
   node.clear();

   // optionally, make a boilerplate declaration node
   if (decl) {
      node.name = "/";
      node.add(special::xml); // "we built the object from an XML"
   }

   // empty xml document?
   if (x.empty())
      return true;

   try {

      // ------------------------
      // validate
      // ------------------------

      // Validation, itself, is independent of whether decl is true or false

      size_t size = 0;
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
                  node.one(special::xml).add(xattr.name(), xattr.value());
         } else {
            // Document node
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



// -----------------------------------------------------------------------------
// JSON ==> Node
// -----------------------------------------------------------------------------

inline bool convert(const JSON &j, Node &node, const bool &DECL)
{
   static const std::string context = "convert(JSON,Node)";

#ifdef NJOY_GNDSTK_DISABLE_JSON

   (void)j; (void)node; (void)DECL;
   log::error(
      "We can't make the conversion " + context + ", because the code\n"
      "has been compiled with JSON disabled (macro NJOY_GNDSTK_DISABLE_JSON).");
   log::function(context);
   throw std::exception{};

#else

   const bool decl = detail::getDecl(node,DECL);

   // clear the receiving node
   node.clear();

   // optionally, make a boilerplate declaration node
   if (decl) {
      node.name = "/";
      node.add(special::json); // "we built the object from a JSON"
   }

   // empty json document?
   if (j.empty())
      return true;

   try {
      // j.doc gives a JSON "object": {...}, i.e. a JSON brace construct,
      // as opposed to a JSON key/value pair or specific JSON entity such
      // as integer or boolean. Elsewhere, in recursive calls to the below
      // function, we'd have already determined a node's name from a key.
      // In this context, however, we don't have a key. The trailing "true"
      // tells json2node to infer node.name from the contents of the {...}.
      detail::json2node(j.doc, decl ? node.add() : node, true);
      return true;
   } catch (...) {
      log::function(context);
      throw;
   }

#endif
}



// -----------------------------------------------------------------------------
// HDF5 ==> Node
// -----------------------------------------------------------------------------

/*
Remark

HighFive::File references an entire HDF5 file. By extension, this applies to
GNDStk::HDF5 - our simple wrapper around HighFive::File that helps us to provide
uniform behavior between XML, JSON, and HDF5. Unlike XML and JSON, it apparently
can't reference just part of such a file, i.e. part of an HDF5 hierarchy. So,
convert(HDF5,Tree) may be more meaningful than convert(HDF5,Node), as Tree is
specifically for a full GNDS hierarchy, Node for possibly a partial hierarchy.
Consistent with how we handle conversions from XML and JSON, however, we define
the conversion in terms of Node (from which Tree is, of course, derived), and
then guess, based on the Node's name, whether it's a Tree, or a Node proper. We
may consider, at some point, having a convert(HighFive::Group,Node), i.e. with a
HighFive::Group rather than a HighFive::File, but such a function might or might
not prove to be useful. A HighFive::Group would come from a HighFive::File; it
wouldn't be a string on its own, like a "snippet" of XML or JSON.
*/

inline bool convert(const HDF5 &h, Node &node, const bool &DECL)
{
   static const std::string context = "convert(HDF5,Node)";

#ifdef NJOY_GNDSTK_DISABLE_HDF5

   (void)h; (void)node; (void)DECL;
   log::error(
      "We can't make the conversion " + context + ", because the code\n"
      "has been compiled with HDF5 disabled (macro NJOY_GNDSTK_DISABLE_HDF5).");
   log::function(context);
   throw std::exception{};

#else

   const bool decl = detail::getDecl(node,DECL);

   // clear the receiving node
   node.clear();

   // optionally, make a boilerplate declaration node
   Node *declnode = nullptr;
   if (decl) {
      node.name = "/";
      declnode = &node.add(special::hdf5); // "we built the object from an HDF5"
   }

   // empty HDF5 document?
   if (h.empty())
      return true;

   // not empty in the earlier (h.filePtr == nullptr) sense,
   // but with no real content in the HDF5 document?
   const HighFive::Group &rootGroup = h.filePtr->getGroup("/");
   if (rootGroup.getNumberAttributes() == 0 &&
       rootGroup.getNumberObjects() == 0)
      return true;

   try {
      // if decl, then place any top-level attributes that exist, in the HDF5,
      // into the Node's special::hdf5 child that would have been created above

      if (decl)
         for (const auto &attrName : rootGroup.listAttributeNames())
            if (!detail::attr2node(rootGroup.getAttribute(attrName),*declnode))
               return false;

      // visit the rest of the root HDF5 group
      return detail::hdf52node(rootGroup, "/", node, decl);
   } catch (...) {
      log::function(context);
      throw;
   }

#endif
}
