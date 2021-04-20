
// -----------------------------------------------------------------------------
// Node.write()
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// write(ostream,level)
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level = 0) const
{
   // indentation: spaces for current and next levels
   const std::string icurr(indent* level   ,' ');
   const std::string inext(indent*(level+1),' ');

   // name
   if (!(os << icurr << name << ":"))
      log::error("ostream << Node.name returned with !ostream");

   // address and parent-node information (optionally)
   if (os && parents)
      if (!(os << " (address " << this << ", parent " << &parent() << ")"))
         log::error("ostream << (Node address/parent information) "
                    "returned with !ostream");

   // metadata
   if (os)
      for (const auto &meta : metadata)
         if (!(os << "\n" << inext << meta.first << ": " << meta.second)) {
            log::error("ostream << Node.metadata returned with !ostream");
            break;
         }

   // children
   if (os)
      for (const auto &childptr : children)
         if (childptr && !(os << "\n" && childptr->write(os,level+1))) {
            log::error("ostream << Node.children returned with !ostream");
            break;
         }

   // context, if applicable
   if (!os)
      log::member("Node.write(ostream)");

   // done
   return os << std::flush;
}



// -----------------------------------------------------------------------------
// write(filename,level)
// -----------------------------------------------------------------------------

bool write(const std::string &filename, const int level = 0) const
{
   // open file
   std::ofstream ofs(filename);
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
