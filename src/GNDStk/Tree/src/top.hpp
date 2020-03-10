
// -----------------------------------------------------------------------------
// Access to "top-level" tree information
// Relevant files:
//    zero.hpp
//    top.hpp
// See the comment in zero.hpp for more information.
// -----------------------------------------------------------------------------

// ------------------------
// top
// ------------------------

// **: one to dereference the begin() iterator into the container,
// the other to dereference the pointer that's in the container.

nodeType &top()
{
   assert(not empty() and root->children.size() == 1 and
          *root->children.begin() != nullptr);
   return **root->children.begin();
}

const nodeType &top() const
{
   assert(not empty() and root->children.size() == 1 and
          *root->children.begin() != nullptr);
   return **root->children.begin();
}
