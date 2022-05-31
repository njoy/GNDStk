
// -----------------------------------------------------------------------------
// XML ==> Node
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, Node &node, const bool &DECL)
{
   const bool decl = detail::getDecl(node,DECL);

   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving object
   node.clear();

   // optionally, make a boilerplate declaration node
   if (decl)
      node.add("#xml"); // <== indicates that we built the object from an XML

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
                  node.one("#xml").add(xattr.name(), xattr.value());
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
   const bool decl = detail::getDecl(node,DECL);

   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving object
   node.clear();

   // optionally, make a boilerplate declaration node
   if (decl)
      node.add("#json"); // <== indicates that we built the object from a JSON

   // empty json document?
   if (j.empty())
      return true;

   try {

      // ------------------------
      // validate
      // ------------------------

      // possibly redundant with the earlier empty() test, but harmless
      const std::size_t size = j.doc.size();
      if (size == 0)
         return true;

      // a json document should have one main node, although we may at some
      // point want to find a way to relax this
      if (size != 1) {
         log::error("More than one main node in the JSON");
         throw std::exception{};
      }

      // ------------------------
      // convert the nodes
      // ------------------------

      // visit the node, and its children recursively
      if (!detail::json2node(
         j.doc.begin().key(), *j.doc.begin(),
         decl ? node.add() : node
      ))
         return false;

   } catch (...) {
      log::function("convert(JSON,Node)");
      throw;
   }

   // done
   return true;
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
   const bool decl = detail::getDecl(node,DECL);

   // ------------------------
   // bookkeeping
   // ------------------------

   // clear the receiving object
   node.clear();

   // optionally, make a boilerplate declaration node
   Node *const declnode = decl
      ? &node.add("#hdf5") // indicates that we built the object from an HDF5
      : nullptr;

   // empty HDF5 document?
   if (h.empty())
      return true;

   // not empty in the earlier (h.filePtr == nullptr) sense,
   // but with no real content in the HDF5 document?
   const HighFive::Group &group = h.filePtr->getGroup(detail::rootHDF5Name);
   if (group.getNumberAttributes() == 0 && group.getNumberObjects() == 0)
      return true;

   try {
      // if decl, then place any top-level attributes that exist, in the HDF5,
      // into the Node's "#hdf5" child that would have been created above
      if (decl)
         for (auto &attrName : group.listAttributeNames())
            if (!detail::attr2node(group.getAttribute(attrName),*declnode))
               return false;

      // visit the rest of the root HDF5 group
      if (!detail::hdf52node(group, detail::rootHDF5Name, node, !decl))
         return false;
   } catch (...) {
      log::function("convert(HDF5,Node)");
      throw;
   }

   // done
   return true;
}
