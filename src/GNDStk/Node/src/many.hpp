
// -----------------------------------------------------------------------------
// Node.many(string,...)
//
// Searches the current node's sub-nodes for all nodes that have the given name
// and that pass the given filter requirement. Returns a container of copies of
// all such sub-nodes. The container might, of course, have size 0.
// -----------------------------------------------------------------------------

// ------------------------
// many(key,filter[,found])
// ------------------------

// const
template<template<class...> class CONTAINER = std::vector, class FILTER>
CONTAINER<Node> many(
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
            if (std::regex_match(c->name, std::regex(key)) && filter(*c)) {
               container.push_back(*c); // can throw
               found = true;
            }
         }
      }
   } catch (...) {
      log::member("Node.many(\"{}\")", key);
      throw;
   }

   // done
   return container;
}

// non-const
// Not needed, because the const version returns by value


// ------------------------
// many(key[,found])
// ------------------------

// const
template<template<class...> class CONTAINER = std::vector>
CONTAINER<Node> many(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   return many<CONTAINER>(key, detail::noFilter{}, found);
}
