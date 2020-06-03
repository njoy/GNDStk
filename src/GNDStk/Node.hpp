
#include "GNDStk/Node/src/detail.hpp"

// -----------------------------------------------------------------------------
// Node
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER, // container type for metadata
   template<class...> class CHILDREN_CONTAINER  // container type for children
>
class Node {
   using metaPair = std::pair<std::string,std::string>;
   using childPtr = std::unique_ptr<Node>;

public:

   // ------------------------
   // Data
   // ------------------------

   // Simple node for our tree structure:
   //    name
   //    metadata (container of string pairs)
   //    children (container of pointers to other Node<>s)
   std::string name;
   METADATA_CONTAINER<metaPair,std::allocator<metaPair>> metadata;
   CHILDREN_CONTAINER<childPtr,std::allocator<childPtr>> children;

   // ------------------------
   // Simple functions
   // ------------------------

   // clear()
   Node &clear()
   {
      name = "";
      metadata.clear();
      children.clear();
      return *this;
   }

   // is this node empty?
   bool empty() const
   {
      return name == "" && metadata.size() == 0 && children.size() == 0;
   }

   // ------------------------
   // General functions
   // ------------------------

   #include "GNDStk/Node/src/ctor.hpp"
   #include "GNDStk/Node/src/assign.hpp"

   #include "GNDStk/Node/src/add.hpp"
   #include "GNDStk/Node/src/write.hpp"

   #include "GNDStk/Node/src/meta.hpp"
   #include "GNDStk/Node/src/one.hpp"
   #include "GNDStk/Node/src/all.hpp"
   #include "GNDStk/Node/src/child.hpp"
   #include "GNDStk/Node/src/call.hpp"

   #include "GNDStk/Node/src/sort.hpp"

}; // class Node



// -----------------------------------------------------------------------------
// operator<<
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline std::ostream &operator<<(
   std::ostream &os,
   const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &obj
) {
   try {
      obj.write(os);
   } catch (const std::exception &) {
      log::context("ostream << Node");
      throw;
   }
   return os;
}
