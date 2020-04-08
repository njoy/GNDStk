
// -----------------------------------------------------------------------------
// Tree::all(string)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// Note: These are here to help tree be as consistent with node as reasonable.
// Given, however, that there's at most one declaration node and one top-level
// GNDS node in a tree, we should expect that the containers returned by these
// will have either size 0 (if the key wasn't found at all) or size 1. Size 2
// is actually possible below, if the declaration node and the top-level node
// have the same key, but this would indicate an improper state of affairs.
// -----------------------------------------------------------------------------

// const
// return by value, so non-const isn't needed
template<template<class ...> class CONTAINER = std::vector>
CONTAINER<nodeType,std::allocator<nodeType>> all(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<nodeType,std::allocator<nodeType>> container;

   // search
   if (!empty()) {
      if (decl().name == key)
         container.push_back(decl().copy());
      if (decl().children.size() > 0 && top().name == key)
         container.push_back(top().copy());
   }

   // done
   found = container.size() > 0;
   return container;
}
