
// -----------------------------------------------------------------------------
// Node::all(string,...)
//
// Searches the current node's sub-nodes for all nodes that have the given name
// and that pass the given filter requirement. Returns a container of copies of
// all such sub-nodes. The container might, of course, have size 0.
// -----------------------------------------------------------------------------

// ------------------------
// all(key,filter[,found])
// ------------------------

// const
template<template<class...> class CONTAINER = std::vector, class FILTER>
CONTAINER<Node> all(
   const std::string &key,
   const FILTER &filter,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<Node> container;
   found = false;

   try {
      // ""
      // meaning: return a container with a copy of current node
      if (key == "") {
         // filter is ignored in this case
         container.push_back(*this);
         found = true;
      } else {
         // search in the current node's children
         for (auto &c : children) {
            if (c->name == key && filter(*c)) {
               container.push_back(*c); // can throw
               found = true;
            }
         }
      }
   } catch (const std::exception &) {
      log::context("Node::all(key=\"{}\")", key);
      throw;
   }

   // done
   return container;
}

// non-const
// Not needed, because the const version returns by value


// ------------------------
// all(key[,found])
// ------------------------

// const
template<template<class...> class CONTAINER = std::vector>
CONTAINER<Node> all(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   return all<CONTAINER>(key, [](const Node &) { return true; }, found);
}
