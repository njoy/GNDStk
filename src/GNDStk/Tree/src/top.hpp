
// -----------------------------------------------------------------------------
// Tree::top()
// See also: Tree::decl()
// See the comment in decl.hpp for more information.
// -----------------------------------------------------------------------------

// const
const nodeType &top() const
{
   if (!has_top()) {
      njoy::Log::error(
         "tree.top() called, "
         "but this tree has no top-level node"
      );
      throw std::exception{};
   }

   // **: one to dereference the begin() iterator into the container,
   // the other to dereference the pointer that's in the container.
   return **root->children.begin();
}

// non-const
nodeType &top()
{
   return const_cast<nodeType &>(std::as_const(*this).top());
}
