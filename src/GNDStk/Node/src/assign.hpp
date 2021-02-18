
// -----------------------------------------------------------------------------
// Node Assignment
// -----------------------------------------------------------------------------

// move
Node &operator=(Node &&) = default;

// copy
Node &operator=(const Node &from)
{
   if (&from != this)
      detail::node2Node(from,*this);
   return *this;
}
