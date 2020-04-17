
#include "GNDStk/Node/src/detail.hpp"



// -----------------------------------------------------------------------------
// Node (templated)
// node = Node<>
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

   /*
   // removed for now; let's see if we end up needing this
   // is this a leaf node?
   bool leaf() const
   {
      return children.size() == 0;
   }
   */

   // copy
   Node copy() const
   {
      Node n;
      detail::node2Node(*this,n);
      return n;
   }

   // ------------------------
   // General functions
   // ------------------------

   // fixme Should probably have some additional constructors,
   // allowing for name, metadata, etc. at construction time.

   // ctor: default
   Node() { }

   // ctor: move, DELETED copy
   Node(Node &&) = default;
   Node(const Node &) = delete;

   // assignment: move, DELETED copy
   Node &operator=(Node &&) = default;
   Node &operator=(const Node &) = delete;

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
   debug("node operator<<");
   return obj.write(os);
}
