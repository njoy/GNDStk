
// -----------------------------------------------------------------------------
// Node ==> JSON
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, JSON &j)
{
   static const std::string context = "convert(Node,JSON)";

   // clear the receiving JSON
   j.clear();

   try {
      // ------------------------
      // Node
      // ------------------------

      if (node.name != "/")
         return detail::node2json(node,j.doc);

      // ------------------------
      // Tree
      // ------------------------

      detail::warn_node_top_metadata(node,context);
      bool found_dec = false;

      for (const auto &cptr : node.children) {
         if (cptr->name == special::xml ) continue;
         if (cptr->name == special::hdf5) continue;

         if (cptr->name == special::json || cptr->name == special::decl) {
            // looks like a declaration node
            if (found_dec) // already seen
               detail::info_node_multiple_dec(context);
            // fixme Implement top-level metadata/attributes in JSON
            found_dec = true;
         } else {
            // looks like a regular node
            if (!detail::node2json(*cptr,j.doc))
               return false;
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
// JSON ==> JSON
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const JSON &from, JSON &to)
{
   // same object?
   if (&to == &from)
      return true;

   // clear the receiving JSON
   to.clear();

   // empty?
   if (from.empty())
      return true;

   // from ==> to
   try {
      to.doc = from.doc; // orderedJSON's assignment
   } catch (...) {
      log::function("convert(JSON,JSON)");
      throw;
   }

   // done
   return true;
}


// -----------------------------------------------------------------------------
// XML  ==> JSON
// HDF5 ==> JSON
// As with our convert()s to XML, these go through temporaries.
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, JSON &j)
{
   try {
      Tree tmp;
      return convert(x,tmp) && convert(tmp,j);
   } catch (...) {
      log::function("convert(XML,JSON)");
      throw;
   }
}

#ifndef GNDSTK_DISABLE_HDF5
inline bool convert(const HDF5 &h, JSON &j)
{
   try {
      Tree tmp;
      return convert(h,tmp) && convert(tmp,j);
   } catch (...) {
      log::function("convert(HDF5,JSON)");
      throw;
   }
}
#endif
