
// -----------------------------------------------------------------------------
// Node ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, HDF5 &h, const std::string &name)
{
   static const std::string context = "convert(Node,HDF5)";

   // clear
   h.clear();

   try {
      // bookkeeping, re: HighFive employing basically a file descriptor
      const std::string tmpfile =
         name != "" ? name : h.temporaryName(h.fileDesc);
      h.filePtr = new HighFive::File(tmpfile, HDF5::modeWrite);

      // ------------------------
      // Node
      // ------------------------

      if (node.name != "/") {
         const bool ret = detail::node2hdf5(node,*h.filePtr);
         h.filePtr->flush();
         return ret;
      }

      // ------------------------
      // Tree
      // ------------------------

      detail::warn_node_top_metadata(node,context);
      bool found_dec = false;

      for (auto &cptr : node.children) {
         if (cptr->name == special::xml ) continue;
         if (cptr->name == special::json) continue;

         if (cptr->name == special::hdf5 || cptr->name == special::any) {
            // looks like a declaration node
            if (found_dec) // already seen
               detail::info_node_multiple_dec(context);
            // fixme Implement top-level metadata/attributes in HDF5
            found_dec = true;
         } else {
            // looks like a regular node
            const bool ret = detail::node2hdf5(*cptr,*h.filePtr);
            h.filePtr->flush();
            if (!ret)
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
// HDF5 ==> HDF5
// For completeness
// -----------------------------------------------------------------------------

inline bool convert(const HDF5 &from, HDF5 &to)
{
   // same object?
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // empty?
   if (from.empty())
      return true;

   // from ==> to
   try {
      std::ifstream ifs(from.filePtr->getName(), std::ios::binary);
      if (!ifs) {
         log::error("Could not open file \"{}\"", from.filePtr->getName());
         // The HDF5 class is different from the XML and JSON classes in that
         // it essentially employs a "file descriptor" of sorts, through the
         // underlying class HighFive::File. So, unlike convert(XML,XML) and
         // convert(JSON,JSON), this function - convert(HDF5,HDF5) - needs
         // to create a *file* for the destination object. It cannot simply
         // duplicate an internal data structure, as the analogous XML and
         // JSON convert() functions do. The above error message might thus
         // surprise a user, who wouldn't necessarily realize that a file is
         // being created as a result of this convert(). To help clarify the
         // situation, we'll write an informational note.
         log::info(
            "We're attempting to open this in this context because it's\n"
            "behind the source HDF5 object.");
         throw std::exception{};
      }
      if (!to.read(ifs))
         throw std::exception{};
   } catch (...) {
      log::function("convert(HDF5,HDF5)");
      throw;
   }

   // done
   return true;
}


// -----------------------------------------------------------------------------
// XML  ==> HDF5
// JSON ==> HDF5
// As with our convert()s to XML, these go through temporaries.
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, HDF5 &h)
{
   try {
      Tree tmp;
      return convert(x,tmp) && convert(tmp,h);
   } catch (...) {
      log::function("convert(XML,HDF5)");
      throw;
   }
}

inline bool convert(const JSON &j, HDF5 &h)
{
   try {
      Tree tmp;
      return convert(j,tmp) && convert(tmp,h);
   } catch (...) {
      log::function("convert(JSON,HDF5)");
      throw;
   }
}
