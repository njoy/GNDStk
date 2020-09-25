
// -----------------------------------------------------------------------------
// Node::write()
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
   os << icurr << name << ":" << std::endl;

   // write metadata
   for (const auto &meta : metadata)
      if (!(os << inext << meta.first << ": " << meta.second << std::endl))
         break;

   // write children
   for (const auto &c : children)
      if (c && !c->write(os,level+1))
         break;

   // check for errors
   if (!os)
      log::error("Problem during Node::write(ostream)");

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
      log::error(
         "Could not open file in call to Node::write(filename=\"{}\")",
         filename
      );
      return false;
   }

   // write to stream
   write(ofs,level);
   if (ofs.fail()) {
      log::context("Node::write(filename=\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
