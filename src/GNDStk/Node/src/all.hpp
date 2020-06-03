
// -----------------------------------------------------------------------------
// Node::all(string)
//
// Searches the node's children for all child nodes of the given name. Returns
// a container of copies of all such child nodes. (Might be size 0, of course.)
// -----------------------------------------------------------------------------

// const
template<template<class...> class CONTAINER = std::vector>
CONTAINER<Node> all(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<Node> container;

   try {
      // search
      for (auto &c : children)
         if (c->name == key)
            container.push_back(*c); // can throw
   } catch (const std::exception &) {
      found = container.size() > 0;
      log::context("Node::all(key=\"{}\")", key);
      throw;
   }

   // done
   found = container.size() > 0;
   return container;
}

// non-const
// Not needed, because the const version returns by value
