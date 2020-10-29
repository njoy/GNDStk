
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
   METADATA_CONTAINER<metaPair> metadata;
   CHILDREN_CONTAINER<childPtr> children;

   // ------------------------
   // Simple functions
   // ------------------------

   // clear
   Node &clear()
   {
      name = "";
      metadata.clear();
      children.clear();
      return *this;
   }

   // empty?
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

   #include "GNDStk/Node/src/sort.hpp"

   // miscellaneous specialty functions:
   // documentation, cdata, ...
   #include "GNDStk/Node/src/special.hpp"

   // ------------------------
   // operator()
   // ------------------------

   // These provide notationally consistent and richer access to the meta and
   // child functions, except that the std::string parameter versions of those
   // are intentionally unsupported, as it would be indeterminate as to whether
   // we'd want the meta or child (std::string) function. This also reflects
   // the fact that performing node accesses with meta_t/child_t parameters -
   // not with std::string parameters - should be preferred. meta_t and child_t
   // compile-time encode that we want, respectively, metadata or children.
   // Note: for variant-based meta_t and child_t keywords, you should still
   // call meta<TYPE>() or child<TYPE>() directly. Having operator() cases to
   // support those would complicate these files, and require that you invoke
   // operator() in awkward functional form, e.g. mynode.operator()<TYPE>(...).

   #include "GNDStk/Node/src/call-meta.hpp"
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call-child.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call-child.hpp"

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
      return obj.write(os);
   } catch (...) {
      log::function("ostream << Node");
      throw;
   }
}
