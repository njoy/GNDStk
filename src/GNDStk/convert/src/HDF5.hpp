
// -----------------------------------------------------------------------------
// convert(*,HDF5)
// That is, convert to HDF5 objects
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Node ==> HDF5
// -----------------------------------------------------------------------------

inline bool convert(const Node &node, HDF5 &h, const std::string &name)
{
   static const std::string context = "convert(Node,HDF5)";

   // Prepare the HDF5
   h.clear();
   const std::string fileName = name != "" ? name : h.temporaryName(h.fileDesc);

   try {
      h.filePtr = new HighFive::File(fileName, HDF5::modeWrite);

      // Probably a regular Node...
      if (node.name != slashTreeName) {
         const bool ret = detail::node2hdf5(node,*h.filePtr);
         h.filePtr->flush();
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
         if (c->name == "#xml" || c->name == "#json" || c->name == "#hdf5") {
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
            const bool ret = detail::node2hdf5(*c,*h.filePtr);
            h.filePtr->flush();
            if (!ret)
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
// XML  ==> HDF5
// JSON ==> HDF5
// As with convert()s to XML, these go through a Tree temporary.
// -----------------------------------------------------------------------------

inline bool convert(const XML &x, HDF5 &h)
{
   try {
      Tree t; // temporary
      return convert(x,t) && convert(t,h);
   } catch (...) {
      log::function("convert(XML,HDF5)");
      throw;
   }
}

inline bool convert(const JSON &j, HDF5 &h)
{
   try {
      Tree t; // temporary
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
   // self?
   if (&to == &from)
      return true;

   // clear
   to.clear();

   // empty?
   if (from.empty())
      return true;

   // convert
   try {
      std::ifstream ifs(from.filePtr->getName(), std::ios::binary);
      if (!ifs) {
         log::error("Could not open file \"{}\"", from.filePtr->getName());
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
