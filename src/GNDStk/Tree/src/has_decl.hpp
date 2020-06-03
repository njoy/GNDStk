
bool has_decl() const
{
   // Does the tree have something that looks like a declaration node?
   int count = 0;
   for (auto &c : children) {
      if (c->name == "xml" ||
          c->name == "json" ||
          c->name == "hdf5")
         count++;
   }

   // Ill-formed if there's more than one such node
   if (count > 1) {
      log::error(
         "Tree does not appear to be well-formed. It has {} (more than one)\n"
         "node that looks like a declaration node",
         count
      );
      throw std::exception{};
   }

   // Ill-formed if there's more than one of something else
   if (children.size()-count > 1) {
      log::error(
         "Tree does not appear to be well-formed. It has {} (more than one)\n"
         "node that looks like a GNDS top-level node",
         children.size()-count
      );
      throw std::exception{};
   }

   return count != 0;
}
