
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
// Also:
// convert(*,Node) for * = XML/JSON/HDF5
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

      // a json document should have one main node
      if (size != 1) {
         // fixme Consider relaxing this, if doing so might ever make sense
         log::error("More than one main node in the JSON");
         throw std::exception{};
      }

      // ------------------------
      // convert the nodes
      // ------------------------

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



// -----------------------------------------------------------------------------
// HDF5 ==> Node
// HDF5 ==> Tree
// -----------------------------------------------------------------------------

/*
Remark

HighFive::File, and by extension GNDStk::HDF5 (our simple wrapper around
HighFive::File, to assist in providing uniform behavior between XML, JSON,
and HDF5), references an entire HDF5 file. Unlike XML and JSON, it apparently
can't reference just part of such a file, i.e. part of an HDF5 hierarchy. The
upshot: convert(HDF5,Tree) may be far more meaningful than convert(HDF5,Node),
as the Tree is for a full GNDS hierarchy, Node for possibly a partial hierarchy.
I'll keep the Node case, though. It will have slightly different behavior, due
to the decl flag. Also, the Tree version will call the Node version to do most
of the work. We might consider having a convert(HighFive::Group,Node), i.e. with
a HighFive::Group rather than a HighFive::File, but such a thing might or might
not prove to be useful. A HighFive::Group would come from a HighFive::File; it
wouldn't be a string on its own, like a "snippet" of XML or JSON.
*/

// HDF5 ==> Node
inline bool convert(const HDF5 &h, Node &node, const bool decl)
{
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
   const HighFive::Group &group = h.filePtr->getGroup(detail::rootHDF5);
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
      if (!detail::hdf52node(group, detail::rootHDF5, node, !decl))
         return false;
   } catch (...) {
      log::function("convert(HDF5,Node)");
      throw;
   }

   // done
   return true;
}


// HDF5 ==> Tree
inline bool convert(const HDF5 &h, Tree &tree)
{
   try {
      return convert(h, *(Node*)&tree, true);
   } catch (...) {
      log::function("convert(HDF5,Tree)");
      throw;
   }
}
