
// -----------------------------------------------------------------------------
// Tree::one(string)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// -----------------------------------------------------------------------------

// const
const nodeType &one(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // if tree has no declaration node, but a "found" flag wasn't sent
   if (!has_decl() and !detail::sent(found)) {
      log::error("Tree::one(\"{}\") called, but the tree is empty", key);
      throw std::exception{};
   }

   try {
      return key == "" || decl().name == key
         ? (found = true, decl())
         : decl().one(key,found);
   } catch (const std::exception &) {
      log::context("Tree::one(\"{}\")", key);
      throw;
   }
}


// non-const
nodeType &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<nodeType &>(std::as_const(*this).one(key,found));
}
