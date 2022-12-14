
// -----------------------------------------------------------------------------
// Node ==> XML
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, XML &x)
{
   static const std::string context = "convert(Node,XML)";

   // clear
   x.clear();

   // We recognize below that the Node could in fact be the base of a Tree,
   // which might have a declaration node. If it does, then we'll preserve
   // the declaration node's information in the output XML object.
   //
   // The way we're storing things in Tree, a declaration node might contain,
   // for example, the following, if the Tree was built from an XML:
   //
   //    name: #xml
   //    metadata:
   //       "version",  "1.0"
   //       "encoding", "UTF-8"
   //    children:
   //       (none)
   //
   // In an XML file, the declaration node is the construct that optionally
   // can appear at the beginning, and looks like: <?xml version="1.0"...?>.

   try {
      // ------------------------
      // Node
      // ------------------------

      if (node.name != "/") {
         // A Tree should have name "/" at the root level, so this looks
         // like it's garden-variety Node. Do a straight Node conversion.
         return detail::node2xml(node,x.doc);
      }

      // Henceforth it's presumably a Tree, unless someone gave the root Tree-
      // node name to a regular node, which they really shouldn't have done.

      // ------------------------
      // Tree
      // ------------------------

      detail::warn_node_top_metadata(node,context);
      bool found_dec = false;
      bool found_top = false;

      for (auto &cptr : node.children) {
         if (cptr->name == special::json) continue;
         if (cptr->name == special::hdf5) continue;

         if (cptr->name == special::xml || cptr->name == special::any) {
            // looks like a declaration node
            pugi::xml_node xdecl;
            if (found_dec) // already seen
               detail::info_node_multiple_dec(context);
            else
               xdecl = x.doc.append_child(pugi::node_declaration);
            for (auto &meta : cptr->metadata)
               xdecl.append_attribute(meta.first.data()) = meta.second.data();
            found_dec = true;
         } else {
            // looks like a regular node
            if (found_top) { // already seen
               log::info(
                  "Node has name \"/\" and multiple \"document nodes\".\n"
                  "This is nonstandard in XML, but we'll write them all.");
               log::function(context);
            }
            if (!detail::node2xml(*cptr,x.doc))
               return false;
            found_top = true;
         }
      }

   } catch (...) {
      log::function(context);
      throw;
   }

   // done
   return true;
}


// -----------------------------------------------------------------------------
// XML ==> XML
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const XML &from, XML &to)
{
   // same object?
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // empty?
   if (from.empty())
      return true;

   // It seems that pugi::xml_document's assignment operator, and for that
   // matter its copy constructor, are private. So, we can't use either of
   // those here. For now, then, we'll do something simple that works, but
   // not very efficiently: write "from" to a stringstream, then read "to"
   // from the stringstream. (Note that it's XML that's written and read.)
   // The GNDS files that I've seen so far aren't large enough to make this
   // problematic. We'll revisit this if and when more efficiency is needed.

   // back up indentation; is restored later
   const int indent = GNDStk::indent;
   GNDStk::indent = 0; // to save memory in the intermediary stringstream

   // from ==> temporary stringstream ==> to
   try {
      std::stringstream tmp;
      from.write(tmp,true); // true: include declaration node
      if (!to.read(tmp))
         throw std::exception{};
   } catch (...) {
      GNDStk::indent = indent;
      log::function("convert(XML,XML)");
      throw;
   }

   // done
   GNDStk::indent = indent;
   return true;
}


// -----------------------------------------------------------------------------
// JSON ==> XML
// HDF5 ==> XML
// These go through temporaries, for compactness. They could likely be made
// more efficient if written directly. We'll revisit this issue if necessary.
// -----------------------------------------------------------------------------

inline bool convert(const JSON &j, XML &x)
{
   try {
      Tree tmp;
      return convert(j,tmp) && convert(tmp,x);
   } catch (...) {
      log::function("convert(JSON,XML)");
      throw;
   }
}

inline bool convert(const HDF5 &h, XML &x)
{
   try {
      Tree tmp;
      return convert(h,tmp) && convert(tmp,x);
   } catch (...) {
      log::function("convert(HDF5,XML)");
      throw;
   }
}
