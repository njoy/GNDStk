
#include "GNDStk/Tree/src/detail.hpp"

// -----------------------------------------------------------------------------
// Tree (templated)
// tree = Tree<>
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER, // container type for metadata
   template<class...> class CHILDREN_CONTAINER  // container type for children
>
class Tree {
   using nodeType = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

public:

   // ------------------------
   // Data
   // ------------------------

   // Initial node of the tree
   std::unique_ptr<nodeType> root;

   // ------------------------
   // Functions
   // ------------------------

   // clear
   // root is a unique_ptr, so this deletes the whole tree
   void clear()
   {
      root = nullptr;
   }

   // is this tree empty?
   bool empty() const
   {
      return root == nullptr;
   }

   // does this tree have a declaration node?
   bool has_decl() const
   {
      // This is basically equivalent to !empty(),
      // but with an additional well-formedness check

      // no
      if (root == nullptr) return false;
      // well-formedness check
      assert(root->children.size() == 0 || (
             root->children.size() == 1 && *root->children.begin() != nullptr));
      // yes
      return true;
   }

   // does this tree have a top-level GNDS node?
   bool has_top() const
   {
      // no
      if (!has_decl()) return false;
      // maybe yes, maybe no
      return root->children.size() == 1;
   }

   // sort
   Tree &sort()
   {
      if (has_decl()) decl().sort();
      return *this;
   }

   #include "GNDStk/Tree/src/reset.hpp"
   #include "GNDStk/Tree/src/ctor.hpp"
   #include "GNDStk/Tree/src/assign.hpp"

   #include "GNDStk/Tree/src/read.hpp"
   #include "GNDStk/Tree/src/write.hpp"

   #include "GNDStk/Tree/src/decl.hpp"
   #include "GNDStk/Tree/src/top.hpp"

   #include "GNDStk/Tree/src/meta.hpp"
   #include "GNDStk/Tree/src/one.hpp"
   #include "GNDStk/Tree/src/all.hpp"
   #include "GNDStk/Tree/src/child.hpp"
   #include "GNDStk/Tree/src/call.hpp"

}; // class Tree



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// operator>>
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline std::istream &operator>>(
   std::istream &is,
   Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &obj
) {
   return obj.read(is);
}

// operator<<
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline std::ostream &operator<<(
   std::ostream &os,
   const Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &obj
) {
   return obj.write(os);
}
