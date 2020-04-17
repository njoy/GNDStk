
// -----------------------------------------------------------------------------
// Node::all(string)
//
// Searches the node's children for all child nodes of the given name. Returns
// a container of copies of all such child nodes. (Might be size 0, of course.)
// -----------------------------------------------------------------------------

// const
// returns by value, so non-const isn't needed
template<template<class...> class CONTAINER = std::vector>
CONTAINER<Node,std::allocator<Node>> all(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<Node,std::allocator<Node>> container;

   // search
   for (auto &c : children)
      if (c != nullptr and c->name == key)
         container.push_back(c->copy());

   // done
   found = container.size() > 0;
   return container;
}
