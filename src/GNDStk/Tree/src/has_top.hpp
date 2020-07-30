
// Does this tree have a top-level GNDS node?
bool has_top() const
{
   // This pretty much just does the complement of what has_decl() does;
   // code from the two functions could probably be combined with a bit
   // of work.

   // Does the tree have something that looks like a top-level GNDS node,
   // defined as something that *doesn't* look like a declaration node?
   int count = 0;
   for (auto &c : children) {
      if (c->name != "xml" &&
          c->name != "json" &&
          c->name != "hdf5")
         count++;
   }

   // Ill-formed if there's more than one such node
   if (count > 1) {
      log::error(
         "Tree does not appear to be well-formed. It has {} (more than one)\n"
         "node that looks like a GNDS top-level node",
         count
      );
      throw std::exception{};
   }

   // Ill-formed if there's more than one of something else
   if (children.size()-count > 1) {
      log::error(
         "Tree does not appear to be well-formed. It has {} (more than one)\n"
         "node that looks like a declaration node",
         children.size()-count
      );
      throw std::exception{};
   }

   return count != 0;
}
