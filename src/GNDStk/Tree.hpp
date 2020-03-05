
#include "GNDStk/Tree/src/detail.hpp"

// -----------------------------------------------------------------------------
// Tree (templated)
// tree = Tree<>
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER, // metadata container type
   template<class...> class CHILDREN_CONTAINER  // children container type
>
class Tree {
   using nodeType = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

public:

   // root
   std::shared_ptr<nodeType> root;

   // clear
   // root is a smart pointer, so this deletes the whole tree
   void clear()
   {
      root = nullptr;
   }

   // empty
   bool empty() const
   {
      return root == nullptr;
   }

   // normalize
   void normalize()
   {
      if (not empty())
         root->normalize();
   }

   #include "GNDStk/Tree/src/ctor.hpp"
   #include "GNDStk/Tree/src/assign.hpp"

   #include "GNDStk/Tree/src/read.hpp"
   #include "GNDStk/Tree/src/write.hpp"

   // re: build new trees, or modify existing ones
   #include "GNDStk/Tree/src/make.hpp"

   // re: access tree contents
   #include "GNDStk/Tree/src/top.hpp"  // zero(), top()
   #include "GNDStk/Tree/src/find.hpp" // meta(), child(), operator()

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
