
// -----------------------------------------------------------------------------
// convert(*,JSON)
// That is, convert to JSON objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Node ==> JSON
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, JSON &j)
{
   // clear
   j.clear();

   static const std::string context = "convert(Node,JSON)";
   try {

      // Probably a regular Node...
      if (node.name != "")
         return detail::node2json(node,j.doc);

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
         if (c->name == "#xml" || c->name == "#json" || c->name == "#hdf5") {
            // looks like a declaration node
            if (found_decl) {
               // already seen
               log::warning(
                  "Encountered Node with empty name \"\",\n"
                  "and > 1 child nodes that look like "
                  "declaration nodes.\n"
                  "Not expected in this context. "
                  "For JSON, we're ignoring declaration nodes anyway."
               );
               log::function(context);
            }
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
            if (!detail::node2json(*c,j.doc))
               return false;
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
// Tree ==> JSON
// -----------------------------------------------------------------------------

inline bool convert(const Tree &tree, JSON &j)
{
   try {
      return convert(*(const Node *)&tree, j);
   } catch (...) {
      log::function("convert(Tree,JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// XML ==> JSON
// -----------------------------------------------------------------------------

// Goes through a tree. Could be made more efficient if written directly.
// We'll revisit this if it becomes more of an issue.
inline bool convert(const XML &x, JSON &j)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(x,t) && convert(t,j);
   } catch (...) {
      log::function("convert(XML,JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// HDF5 ==> JSON
// -----------------------------------------------------------------------------

// As above, goes through a tree.
inline bool convert(const HDF5 &h, JSON &j)
{
   // temporary
   Tree t;

   // convert
   try {
      return convert(h,t) && convert(t,j);
   } catch (...) {
      log::function("convert(HDF5,JSON)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// JSON ==> JSON
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const JSON &from, JSON &to)
{
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // convert
   try {
      to.doc = from.doc; // nlohmann::json's assignment
   } catch (...) {
      log::function("convert(JSON,JSON)");
      throw;
   }

   // done
   return true;
}
