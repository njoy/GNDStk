
// -----------------------------------------------------------------------------
// Node.write()
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// write(ostream,level)
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level = 0) const
{
   // indentation
   const std::string icurr(indent* level   ,' '); // current indentation #spaces
   const std::string inext(indent*(level+1),' '); // next ...

   // write name
   if (!(os << icurr << name << ":" << std::endl))
      log::error("ostream << node.name returned with !ostream");

   // write metadata
   if (os)
      for (const auto &meta : metadata)
         if (!(os << inext << meta.first << ": " << meta.second << std::endl)) {
            log::error("ostream << node.metadata returned with !ostream");
            break;
         }

   // write children
   if (os)
      for (const auto &c : children)
         if (c && !c->write(os,level+1)) {
            log::error("ostream << node.children returned with !ostream");
            break;
         }

   // context, if applicable
   if (!os)
      log::member("Node.write(ostream)");

   // done
   return os;
}



// -----------------------------------------------------------------------------
// write(filename,level)
// -----------------------------------------------------------------------------

bool write(const std::string &filename, const int level = 0) const
{
   // open file
   std::ofstream ofs(filename.c_str());
   if (!ofs) {
      log::error("Could not open file \"{}\" for output", filename);
      log::member("Node.write(\"{}\")", filename);
      return false;
   }

   // write to ostream
   if (!write(ofs,level)) {
      log::member("Node.write(\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
