
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

   // optionally, make a boilerplate declaration node
   if (decl)
      node.add("json"); // <== indicates that we built the object from a JSON

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

      // See comment above check_top() call in convert(XML,Node) above.
      // JSON documents don't have "declaration nodes," as XML documents
      // do, but here we interpret the bool decl parameter as essentially
      // indicating whether we're reading a Node (decl == false) or full
      // Tree (decl == true); and, the latter case suggests we're at the
      // top level, and should thus validate it as a top-level GNDS node.
      if (decl) {
         const std::string name = j.doc.begin().key();
         detail::check_top(name, "JSON", "convert(JSON,Node)");
      }

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
and HDF5), refers to an entire HDF5 file. Unlike XML and JSON, it apparently
can't refer to just part of such a file, i.e. part of an HDF5 hierarchy. The
upshot: convert(HDF5,Tree) may be far more meaningful than convert(HDF5,Node),
as the former (Tree) is for a full GNDS hierarchy, the latter for possibly
a partial hierarchy. I'll leave the Node case, though. It will have slightly
different behavior than the Tree case does, due to the decl flag; and also,
the Tree version will call the Node version to do most of the work. We might
consider, at some point, having something like convert(HighFive::Group,Node),
i.e. with a HighFive::Group rather than a HighFive::File, but such a thing
might or might not prove to be useful. A HighFive::Group would end up coming
from a HighFive::File, rather than being on its own like a "snippet" of XML
or JSON could be. We'll see how things hash out.
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
   Node *declnode = nullptr;
   if (decl) {
      // indicates that we built the object from an HDF5...
      declnode = &node.add("hdf5");
   }

   // empty hdf5 document?
   if (h.empty())
      return true;

   try {
      // for brevity
      const HighFive::File &file = *h.file;

      // size == 0: not empty in the earlier (h.file == nullptr) sense,
      // but, here, meaning that there's nothing in the HDF5 document
      const std::size_t size = file.getNumberObjects();
      if (size == 0)
         return true;

      // ------------------------
      // convert the nodes
      // ------------------------

      const HighFive::Group &group = file.getGroup("/");

      // if decl, then put any top-level attributes into the "hdf5"
      // child node that would have been created above
      if (decl)
         for (auto &attrName : group.listAttributeNames())
            if (!detail::hdf5attr2node(group.getAttribute(attrName), *declnode))
               return false;

      /// may need unconditional "top"=true last argument here...
      /// or something like that...
      // visit the rest of the "/" group
      if (!detail::hdf52node(group, "/", decl ? node.add() : node, decl))
         return false;

#if 0
      // zzz see what can slip into the detail function...
      // visit the remaining objects, and their sub-groups recursively
      for (const std::string &name : names) {
         const HighFive::ObjectType type = file.getObjectType(name);
         if (type == HighFive::ObjectType::Group) {
            detail::check_top(name, "HDF5", "convert(HDF5,Node)");
            const HighFive::Group &g = file.getGroup(name);
            if (!detail::hdf52node(g, name, decl ? node.add() : node))
               return false;
         } else if (type != HighFive::ObjectType::Attribute) {
            assert(false); /// want group or attribute at top level
         }
      }
#endif

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
