
#include "GNDStk/Tree/src/detail.hpp"

// -----------------------------------------------------------------------------
// Tree
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER, // container type for metadata
   template<class...> class CHILDREN_CONTAINER  // container type for children
>
class Tree : public Node<METADATA_CONTAINER,CHILDREN_CONTAINER> {
public:
   using nodeType = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

   // ------------------------
   // From Node
   // ------------------------

   using nodeType::name;
   using nodeType::metadata;
   using nodeType::children;

   using nodeType::empty;

   using nodeType::meta;
   using nodeType::one;
   using nodeType::all;
   using nodeType::child;
   using nodeType::operator();

   // ------------------------
   // Simple functions
   // ------------------------

   // clear
   Tree &clear()
   {
      return this->nodeType::clear(), *this;
   }

   // sort
   Tree &sort()
   {
      return this->nodeType::sort(), *this;
   }

   // ------------------------
   // General functions
   // ------------------------

   #include "GNDStk/Tree/src/has_decl.hpp"
   #include "GNDStk/Tree/src/has_top.hpp"

   #include "GNDStk/Tree/src/decl.hpp"
   #include "GNDStk/Tree/src/top.hpp"

   #include "GNDStk/Tree/src/reset.hpp"
   #include "GNDStk/Tree/src/ctor.hpp"
   #include "GNDStk/Tree/src/assign.hpp"

   #include "GNDStk/Tree/src/read.hpp"
   #include "GNDStk/Tree/src/write.hpp"

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
      return obj.read(is);
   } catch (...) {
      log::function("istream >> Tree");
      throw;
   }
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
      return obj.write(os);
   } catch (...) {
      log::function("ostream << Tree");
      throw;
   }
}
