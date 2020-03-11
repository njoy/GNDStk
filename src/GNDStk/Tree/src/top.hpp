
// -----------------------------------------------------------------------------
// Tree::top()
// See also: Tree::zero()
// See the comment in zero.hpp for more information.
// -----------------------------------------------------------------------------

// **: one to dereference the begin() iterator into the container,
// the other to dereference the pointer that's in the container.

// non-const
nodeType &top()
{
   assert(not empty() and root->children.size() == 1 and
          *root->children.begin() != nullptr);
   return **root->children.begin();
}

// const
const nodeType &top() const
{
   assert(not empty() and root->children.size() == 1 and
          *root->children.begin() != nullptr);
   return **root->children.begin();
}
