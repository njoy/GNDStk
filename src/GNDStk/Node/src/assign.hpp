
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
      for (const childPtr &c : children)
         c->parentNode = this;
   }
   return *this;
}

// copy
Node &operator=(const Node &other)
{
   if (&other != this) {
      clear();
      name = other.name;

      // metadata
      for (const auto &m : other.metadata)
         add(m.first,m.second);

      // children
      for (const childPtr &c : other.children)
         add() = *c;

      // validate
      for (const childPtr &c : children)
         assert(c->parentNode = this);
   }
   return *this;
}
