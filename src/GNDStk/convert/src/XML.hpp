
// -----------------------------------------------------------------------------
// convert(*,XML)
// That is, convert to XML objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Node ==> XML
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, XML &x)
{
   // clear
   x.clear();

   // We recognize here that the Node could in fact be the base of a Tree,
   // which might have a declaration node. If it does, then we'll preserve
   // the declaration node's information in the output XML object.
   //
   // The way we're storing things in Tree, a declaration node might contain,
   // for example, the following, if the Tree was built from an XML:
   //
   //    name: "xml"
   //    metadata:
   //       "version",  "1.0"
   //       "encoding", "UTF-8"
   //    children:
   //       N/A
   //
   // or this if the Tree was built from a JSON:
   //
   //    name: "json"
   //    metadata:
   //       (nothing; empty vector)
   //    children:
   //       N/A
   //
   // or something else if the Tree was built in another manner. In an XML
   // file, the declaration node is the thing like: <?xml version="1.0"...?>.

   static const std::string context = "convert(Node,XML)";
   try {

      if (node.name != "") {
         // A Tree should have name == "" at the root level, so we don't
         // consider this to be a Tree. Just do a straight Node conversion.
         return detail::node2xml(node,x.doc);
      }

      // Henceforth it's presumably a Tree, unless someone gave the name ""
      // to a regular node, which they really shouldn't have done...
      if (node.metadata.size() != 0) {
         log::warning(
            "Encountered Node with empty name \"\",\n"
            "but the Node also contains metadata.\n"
            "Not expected in this context. We'll ignore the metadata."
         );
         log::function(context);
      }

      pugi::xml_node xdecl;
      bool found_decl = false;
      bool found_top  = false;

      for (auto &c : node.children) {
         if (c->name == "xml" || c->name == "json" || c->name == "hdf5") {
            // looks like a declaration node
            if (found_decl) {
               // already seen
               log::warning(
                  "Encountered Node with empty name \"\",\n"
                  "and > 1 child nodes that look like "
                  "declaration nodes.\n"
                  "Not expected in this context. "
                  "We'll combine the metadata."
               );
               log::function(context);
            } else
               xdecl = x.doc.append_child(pugi::node_declaration);
            for (auto &meta : c->metadata)
               xdecl.append_attribute(meta.first.data()) = meta.second.data();
            found_decl = true;
         } else {
            // looks like a regular node
            if (found_top) {
               // already seen
               log::warning(
                  "Encountered Node with empty name \"\",\n"
                  "and > 1 child nodes that look like "
                  "regular (non-declaration) nodes.\n"
                  "Not expected in this context. "
                  "We'll convert all the child nodes."
               );
               log::function(context);
            }
            if (!detail::node2xml(*c,x.doc))
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
// Tree ==> XML
// -----------------------------------------------------------------------------

inline bool convert(const Tree &tree, XML &x)
{
   try {
      return convert(*(const Node *)&tree, x);
   } catch (...) {
      log::function("convert(Tree,XML)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// XML ==> XML
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const XML &from, XML &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // Unfortunately, we can't use pugi::xml_document's assignment, or for
   // that matter its copy constructor, because, for whatever reason, the
   // pugi library makes those private. (And, perhaps, those have shallow-
   // copy semantics, too. I haven't checked into that, because we can't
   // use those anyway.)

   // For now, I'll write something simple that works, although not very
   // efficiently: write "from" to a stringstream, then read "to" out of
   // the stringstream. The GNDS files that I've seen so far aren't large
   // enough to make this untenable. We can revisit this issue if and when
   // it becomes necessary to be more efficient.

   // back up indentation
   const int indent = GNDStk::indent;
   GNDStk::indent = 0; // saves memory in the stringstream

   // from ==> stringstream ==> to
   try {
      std::stringstream ss;
      from.write(ss);
      to.read(ss);
   } catch (...) {
      log::function("convert(XML,XML)");
      throw;
   }

   // restore indentation
   GNDStk::indent = indent;

   // done
   return true;
}



// -----------------------------------------------------------------------------
// JSON ==> XML
// -----------------------------------------------------------------------------

// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const JSON &j, XML &x)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(j,t) && convert(t,x);
   } catch (...) {
      log::function("convert(JSON,XML)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// HDF5 ==> XML
// -----------------------------------------------------------------------------

// As above, goes through a tree.
inline bool convert(const HDF5 &h, XML &x)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(h,t) && convert(t,x);
   } catch (...) {
      log::function("convert(HDF5,XML)");
      throw;
   }
}
