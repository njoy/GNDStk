
// -----------------------------------------------------------------------------
// Node Assignment
// -----------------------------------------------------------------------------

// move
Node &operator=(Node &&other)
{
   if (&other != this) {
      name = std::move(other.name);
      metadata = std::move(other.metadata);
      children = std::move(other.children);
      for (auto &c : children)
         c->parentNode = this;
   }
   return *this;
}

// copy
Node &operator=(const Node &other)
{
   if (&other != this) {
      // The following uses add()s to add child nodes. The add()s,
      // in turn, ensure that the parentNode pointers are correct.
      detail::node2Node(other,*this);

      // validate
      for (auto &c : children)
         assert(c->parentNode = this);
   }
   return *this;
}
