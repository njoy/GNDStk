
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
   #include "GNDStk/Tree/src/has_decl.hpp"

   // does this tree have a top-level GNDS node?
   bool has_top() const
   {
      return has_decl() && root->children.size() == 1;
   }

   // sort
   Tree &sort()
   {
      if (has_decl())
         decl().sort();
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
   try {
      obj.read(is);
   } catch (const std::exception &) {
      detail::context("istream >> Tree");
      throw;
   }
   return is;
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
   try {
      obj.write(os);
   } catch (const std::exception &) {
      detail::context("ostream << Tree");
      throw;
   }
   return os;
}
