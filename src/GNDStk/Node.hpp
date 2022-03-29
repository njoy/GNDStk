
// Name for newly-created nodes
inline const std::string emptyNodeName = "";

// Name for root nodes of trees
inline const std::string slashTreeName = "/";

#include "GNDStk/Node/src/detail.hpp"
std::ostream &operator<<(std::ostream &os, const Node &node);


// -----------------------------------------------------------------------------
// Node
// -----------------------------------------------------------------------------

class Node {
   using metaPair = std::pair<std::string,std::string>;
   using childPtr = std::unique_ptr<Node>;
   friend class Tree;

public:

   // ------------------------
   // Data
   // ------------------------

   // Simple node for our tree structure:
   //    name
   //    metadata   (container of string pairs)
   //    children   (container of pointers to other Nodes)
   //    parentNode (pointer to parent node)
   std::string name;
   std::vector<metaPair> metadata;
   std::vector<childPtr> children;
private:
   // Private, because users really shouldn't deal with it; use parent()
   Node *parentNode = nullptr;
public:

   // ------------------------
   // Simple functions
   // ------------------------

   // clear
   Node &clear()
   {
      if (name != slashTreeName) // else Tree; leave alone
         name = emptyNodeName;
      metadata.clear();
      children.clear();
      return *this;
   }

   // empty?
   bool empty() const
   {
      return
        (name == emptyNodeName || name == slashTreeName) &&
         metadata.size() == 0 &&
         children.size() == 0;
   }

   // parent
   // Assumes that this Node's constness determines its parent's constness
   const Node &parent() const { return *parentNode; }
   Node &parent() { return *parentNode; }

   // ------------------------
   // General functions
   // ------------------------

   #include "GNDStk/Node/src/ctor.hpp"
   #include "GNDStk/Node/src/assign.hpp"

   #include "GNDStk/Node/src/add-meta.hpp"
   #include "GNDStk/Node/src/add-child.hpp"

   #include "GNDStk/Node/src/read.hpp"
   #include "GNDStk/Node/src/write.hpp"

   #include "GNDStk/Node/src/sort.hpp"
   #include "GNDStk/Node/src/compare.hpp"
   #include "GNDStk/Node/src/shuffle.hpp"
   #include "GNDStk/Node/src/count.hpp"

   // access
   // These form bases for the operator()s
   #include "GNDStk/Node/src/meta.hpp"
   #include "GNDStk/Node/src/one.hpp"
   #include "GNDStk/Node/src/many.hpp"
   #include "GNDStk/Node/src/child.hpp"

   // has*
   // Boolean query: will the analogous access function succeed?
   // Example: has(A,B,C,D) == "operator()(A,B,C,D) succeeds"
   #include "GNDStk/Node/src/has.hpp"

   // Node << string
   // Node >> string
   #include "GNDStk/Node/src/string.hpp"

   // ------------------------
   // operator()
   // ------------------------

   // These provide notationally consistent and richer access to the meta and
   // child functions, except that the std::string parameter versions of those
   // are intentionally unsupported, as it would be indeterminate as to whether
   // we'd want the meta or child (std::string) function. This also reflects
   // the fact that performing Node accesses with Meta/Child parameters - not
   // with std::string parameters - should be preferred. Meta and Child compile-
   // time encode that we want, respectively, metadata or children. Note: for
   // variant-based Meta and Child objects, you should still call meta<TYPE>()
   // or child<TYPE>() directly. Having operator() cases to support those would
   // complicate these files, and require that you invoke operator() in awkward
   // functional form, e.g. mynode.operator()<TYPE>(...).

   // meta-specific
   #include "GNDStk/Node/src/call-meta.hpp"

   // child-specific
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call-child.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call-child.hpp"

   // For the KeyTuple<...> std::tuple wrapper
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call-keytuple.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call-keytuple.hpp"

   // General multi-argument
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call.hpp"

   // No-argument operator() returns the current Node; this is the natural
   // extension of the multi-argument behavior
   const Node &operator()() const { return *this; }
   Node &operator()() { return *this; }

   // ------------------------
   // Miscellaneous functions
   // ------------------------

   // documentation, cdata, ...
   #include "GNDStk/Node/src/special.hpp"

   // operator[]
   #include "GNDStk/Node/src/subscript.hpp"

   // ------------------------
   // Destructor
   // ------------------------

   ~Node()
   {
      // Ensure that each child node has *this Node as its parent. This is just
      // a validity check, prior to destruction, but we might as well have it.
      for (auto &c : children) {
         if (c->parentNode != this) {
            log::error("Internal error: child parentNode != parent");
            log::dtor("~Node()");
         }
      }
   }

}; // class Node


// -----------------------------------------------------------------------------
// Stream I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, Node &node)
{
   try {
      return node.read(is);
   } catch (...) {
      log::function("istream >> Node");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const Node &node)
{
   try {
      return node.write(os);
   } catch (...) {
      log::function("ostream << Node");
      throw;
   }
}
