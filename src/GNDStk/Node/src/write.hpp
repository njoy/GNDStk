
// -----------------------------------------------------------------------------
// Node::write()
// -----------------------------------------------------------------------------

// ------------------------
// write(string,level)
// ------------------------

bool write(
   const std::string &file,
   const int level = 0
) const {
   // calls write(ostream) below
   std::ofstream ofs(file.c_str());
   return not write(ofs,level).fail();
}


// ------------------------
// write(ostream,level)
// ------------------------

std::ostream &write(
   std::ostream &os,
   const int level = 0
) const {
   // indentation
   const std::string icurr(indent* level   ,' '); // current indentation #spaces
   const std::string inext(indent*(level+1),' '); // next ...

   // write name
   os << icurr << name << ":" << std::endl;

   // write metadata
   for (const auto &meta : metadata)
      os << inext << meta.first << ": " << meta.second << std::endl;

   // write children
   for (const auto &cptr : children)
      if (cptr)
         cptr->write(os,level+1);

   // done
   return os;
}
