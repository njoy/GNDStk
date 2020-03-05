
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
   static std::string static_str1;
   static std::string static_str2;
   using nodeType = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

public:

   // root
   std::shared_ptr<nodeType> root;

   // clear
   void clear()
   {
      root = nullptr; // smart pointer; this deletes the whole tree
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

#include "GNDStk/Tree/src/make.hpp"
#include "GNDStk/Tree/src/top.hpp"

#include "GNDStk/Tree/src/ctor.hpp"
#include "GNDStk/Tree/src/assign.hpp"

#include "GNDStk/Tree/src/read.hpp"
#include "GNDStk/Tree/src/write.hpp"

// meta, child, operator()
#include "GNDStk/Tree/src/find.hpp"

}; // class Tree



// Tree::static_*
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
std::string Tree<METADATA_CONTAINER,CHILDREN_CONTAINER>::static_str1 = "";

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
std::string Tree<METADATA_CONTAINER,CHILDREN_CONTAINER>::static_str2 = "";



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
