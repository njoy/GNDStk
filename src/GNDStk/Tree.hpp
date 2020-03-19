
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

   // normalize
   Tree &normalize()
   {
      if (not empty())
         root->normalize();
      return *this;
   }

   #include "GNDStk/Tree/src/ctor.hpp"
   #include "GNDStk/Tree/src/assign.hpp"

   #include "GNDStk/Tree/src/init.hpp"
   #include "GNDStk/Tree/src/read.hpp"
   #include "GNDStk/Tree/src/write.hpp"

   #include "GNDStk/Tree/src/zero.hpp"
   #include "GNDStk/Tree/src/top.hpp"

   // fixme Probably have that bool &found stuff in these as well...
   #include "GNDStk/Tree/src/meta.hpp"
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
