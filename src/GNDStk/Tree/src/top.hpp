
// -----------------------------------------------------------------------------
// Tree::top()
// See also: Tree::decl()
// See the comment in decl.hpp for more information.
// -----------------------------------------------------------------------------

// const
const nodeType &top() const
{
   assert(has_top());
   // **: one to dereference the begin() iterator into the container,
   // the other to dereference the pointer that's in the container.
   return **root->children.begin();
}

// non-const
nodeType &top()
{
   return const_cast<nodeType &>(std::as_const(*this).top());
}
