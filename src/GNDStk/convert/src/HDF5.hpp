
// -----------------------------------------------------------------------------
// convert(*,HDF5)
// That is, convert to HDF5 objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Node ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, HDF5 &h)
{
   // clear
   h.clear();

   // for the HDF5
   static char buffer[L_tmpnam];
   h.filename = tmpnam(buffer);

   static const std::string context = "convert(Node,HDF5)";
   try {

      // Open temporary file. This *should* work, but we check anyway.
      std::ofstream ofs(h.filename, std::ios::binary);
      if (!ofs) {
         log::error("Could not open temporary file \"{}\"", h.filename);
         throw std::exception{};
      }
      ofs.close();

      h.file = new HighFive::File(
         h.filename,
         HighFive::File::ReadWrite |
         HighFive::File::Create |
         HighFive::File::Truncate
      );
      h.temporary = true;

      // Probably a regular Node
      if (node.name != "") {
         bool ret = detail::node2hdf5(node,*h.file);
         h.file->flush();
         return ret;
      }

      // Probably a Tree...
      if (node.metadata.size() != 0) {
         log::warning(
            "Encountered Node with empty name \"\",\n"
            "but the Node also contains metadata.\n"
            "Not expected in this context. We'll ignore the metadata."
         );
         log::function(context);
      }

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
                  "For HDF5, we're ignoring declaration nodes anyway."
               );
               log::function(context);
            }
            found_decl = true;
         } else {
            // looks like a regular node
            /**/
            /// We really need to relax this business about requiring that there
            /// be only ONE top-level node. The XML format allows only one
            /// document node (and GNDS, probably because of XML, has just one),
            /// but JSON and HDF5 allow more (or less!) than one. And we're
            /// going to be writing the NDI3 format with this code; it shouldn't
            /// have this limitation.
            /**/
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
            if (!detail::node2hdf5(*c,*h.file))
               return false;
            h.file->flush();
            found_top = true;
         } // else
      } // for

   } catch (...) {
      log::function(context);
      throw;
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// Tree ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const Tree &tree, HDF5 &h)
{
   try {
      if (tree.has_top())
         detail::check_top(tree.top().name, "Tree", "convert(Tree,HDF5)");
      return convert(*(const Node *)&tree, h);
   } catch (...) {
      log::function("convert(Tree,HDF5)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// XML ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, HDF5 &h)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(x,t) && convert(t,h);
   } catch (...) {
      log::function("convert(XML,HDF5)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// JSON ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const JSON &j, HDF5 &h)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(j,t) && convert(t,h);
   } catch (...) {
      log::function("convert(JSON,HDF5)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// HDF5 ==> HDF5
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const HDF5 &from, HDF5 &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // convert
   try {
      if (!from.empty()) {
         std::ifstream ifs(from.filename, std::ios::binary);
         if (!ifs) {
            log::error("Could not open file \"{}\"", from.filename);
            throw std::exception{};
         }
         if (!to.read(ifs))
            throw std::exception{};
      }
   } catch (...) {
      log::function("convert(HDF5,HDF5)");
      throw;
   }

   // done
   return true;
}
