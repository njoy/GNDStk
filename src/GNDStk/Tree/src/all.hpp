
// -----------------------------------------------------------------------------
// Tree::all(string)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// Note: These are here to help tree be as consistent with node as reasonable.
// Given, however, that there's at most one declaration node and one top-level
// GNDS node in a tree, we should expect that the containers returned by these
// will have either size 0 (if the key wasn't found at all) or size 1. Size 2
// is technically possible here if the declaration node and the top-level node
// have the same key, but this would indicate an improper state of affairs.
// -----------------------------------------------------------------------------

// const
// returns by value, so only const is needed
template<template<class...> class CONTAINER = std::vector>
CONTAINER<nodeType,std::allocator<nodeType>> all(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<nodeType,std::allocator<nodeType>> container;

   try {
      // search
      if (has_decl()) {
         if (decl().name == key)
            container.push_back(decl());
         if (has_top() && top().name == key)
            container.push_back(top());
      }
   } catch (const std::exception &) {
      found = container.size() > 0;
      log::context("Tree::all(key=\"{}\")", key);
      throw;
   }

   // done
   found = container.size() > 0;
   return container;
}
