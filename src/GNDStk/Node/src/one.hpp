
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
      if (count > 1) {
         // fixme As elsewhere, rework diagnostics
         warning("Node::one(\"" + key + "\") called, "
                 "but " + std::to_string(count) + " such nodes were found");
      }
      return found = true, *theone;
   }

   // not found
   static Node empty;
   empty.clear();

   // error iff no "found" flag sent
   if (!detail::sent(found))
      error(
         "Node::one(key) called with key \"" + key + "\", "
         "but this key wasn't\nfound in the node's children."
      );

   // done
   return found = false, empty;
}


// non-const
Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<Node &>(std::as_const(*this).one(key,found));
}
