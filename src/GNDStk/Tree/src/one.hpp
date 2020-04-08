
// -----------------------------------------------------------------------------
// Tree::one(string)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// -----------------------------------------------------------------------------

// const
const nodeType &one(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // if tree is empty, but a "found" flag wasn't sent
   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }

   return key == "" || decl().name == key
      ? (found = true, decl())
      : decl().one(key,found);
}


// non-const
nodeType &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<nodeType &>(std::as_const(*this).one(key,found));
}
