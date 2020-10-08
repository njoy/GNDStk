
// -----------------------------------------------------------------------------
// Node::one(string,...)
//
// Searches the current node's sub-nodes for one that has the given name, and
// that also passes the given filter requirement. If it's found, the sub-node
// is returned. Else, an empty node is returned.
//
// Call one() you expect exactly one such value. (Some GNDS nodes are expected
// to occur at most once as a sub-node of a given parent, even if the file
// format used, e.g. XML, might allow for more than one same-named sub-node.)
//
// With one(), as opposed to all(), you get back a direct reference to the one
// found node, not to a container of nodes.
// -----------------------------------------------------------------------------

// ------------------------
// one(key,filter[,found])
// ------------------------

// const
template<class FILTER>
const Node &one(
   const std::string &key,
   const FILTER &filter,
   bool &found = detail::default_bool
) const {
   // ""
   // meaning: return the current node
   if (key == "") {
      // filter is ignored in this case
      return found = true, *this;
   }

   // search in the current node's children,
   // with these tracked for better diagnostics:
   // name: #times node name == key
   // both: #times node name == key AND the filter condition is met
   const Node *theone = nullptr;
   unsigned name = 0, both = 0;
   for (auto &c : children)
      if (c->name == key && (name++, filter(*c)) && both++ == 0)
         theone = &(*c);

   // found
   if (both) {
      if (both > 1)
         log::warning(
            "Node::one(\"{}\") called, but {} matching nodes were found",
            key, both
         );
      return found = true, *theone;
   }

   // not found
   found = false;

   // error iff no "found" flag sent
   if (!detail::sent(found)) {
      if (name == 0)
         log::error(
            "Node::one(\"{}\"): node not found", key);
      else if (name == 1)
         log::error(
            "Node::one(\"{}\"): a node with the given name was found,\n"
            "but it didn't pass the filter condition", key);
      else
         log::error(
            "Node::one(\"{}\"): {} nodes with the given name were found,\n"
            "but none of them passed the filter condition", name, key);
      throw std::exception{};
   }

   // done
   static Node empty;
   return empty.clear();
}


// non-const
template<class FILTER>
Node &one(
   const std::string &key,
   const FILTER &filter,
   bool &found = detail::default_bool
) {
   return const_cast<Node &>(std::as_const(*this).one(key,filter,found));
}



// ------------------------
// one(key[,found])
// ------------------------

// const
const Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   return one(key, [](const Node &) { return true; }, found);
}

// non-const
Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return one(key, [](const Node &) { return true; }, found);
}
