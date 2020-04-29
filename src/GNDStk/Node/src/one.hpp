
// -----------------------------------------------------------------------------
// Node::one(string)
//
// Searches the node's children for a child node with the given name. If found,
// returns the child node in question. Else, returns an empty node. Call when
// you expect exactly one such value. (Many GNDS child nodes are expected just
// once, even though the source file format, e.g. XML, might allow any number.)
// With one(), as opposed to all(), you get back a direct reference to the one
// found node, not to a container of nodes.
// -----------------------------------------------------------------------------

// const
const Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // ""
   // special meaning: return current node
   if (key == "")
      return found = true, *this;

   // search
   const Node *theone = nullptr;
   unsigned count = 0;
   for (auto &c : children)
      if (c != nullptr && c->name == key && count++ == 0)
         theone = &(*c);

   // found
   if (count) {
      if (count > 1)
         log::warning(
            "Node::one(\"{}\") called, but {} such child nodes were found",
            key, count
         );
      return found = true, *theone;
   }

   // not found
   found = false;

   // error iff no "found" flag sent
   if (!detail::sent(found)) {
      log::error("Node::one(\"{}\"): key not found in children", key);
      throw std::exception{};
   }

   // done
   static Node empty;
   empty.clear();
   return empty;
}


// non-const
Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<Node &>(std::as_const(*this).one(key,found));
}
