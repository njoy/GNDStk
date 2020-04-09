
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
   if (!has_decl() and detail::not_sent(found)) {
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
