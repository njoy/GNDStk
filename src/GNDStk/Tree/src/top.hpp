
// -----------------------------------------------------------------------------
// Tree::top()
// See also: Tree::zero()
// See the comment in zero.hpp for more information.
// -----------------------------------------------------------------------------

// const
const nodeType &top() const
{
   assert(not empty() and root->children.size() == 1 and
          *root->children.begin() != nullptr);
   // **: one to dereference the begin() iterator into the container,
   // the other to dereference the pointer that's in the container.
   return **root->children.begin();
}

// non-const
nodeType &top()
{
   return const_cast<nodeType &>(std::as_const(*this).top());
}
