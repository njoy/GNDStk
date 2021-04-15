
#include "GNDStk/Node/src/detail.hpp"
std::ostream &operator<<(std::ostream &os, const Node &obj);

// -----------------------------------------------------------------------------
// Node
// -----------------------------------------------------------------------------

class Node {
   using metaPair = std::pair<std::string,std::string>;
   using childPtr = std::unique_ptr<Node>;

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

   // parent
   // Assumes that this Node's constness determines its parent's constness
   const Node &parent() const { return *parentNode; }
         Node &parent()       { return *parentNode; }

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

   // For the KeywordTup<...> tuple wrapper
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call-keywordtup.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call-keywordtup.hpp"

   // general multi-argument
   #define GNDSTK_CONST const
   #include "GNDStk/Node/src/call.hpp"
   #define GNDSTK_CONST
   #include "GNDStk/Node/src/call.hpp"

   // no-argument operator() returns the current Node; this is the natural
   // extension of the multi-argument behavior
   const Node &operator()() const { return *this; }
   Node &operator()() { return *this; }

   // ------------------------
   // miscellaneous specialty functions:
   // documentation, cdata, ...
   // ------------------------

   #include "GNDStk/Node/src/special.hpp"

   // ------------------------
   // operator[]
   // ------------------------

   #include "GNDStk/Node/src/subscript.hpp"

   // ------------------------
   // destructor
   // ------------------------

   ~Node()
   {
      // Ensure that each child has the current Node as a parent.
      // fixme This is just a validity check; consider removing it.
      for (auto &c : children)
         assert(c->parentNode == this);
   }

}; // class Node



// -----------------------------------------------------------------------------
// operator<<
// -----------------------------------------------------------------------------

inline std::ostream &operator<<(std::ostream &os, const Node &obj)
{
   try {
      return obj.write(os);
   } catch (...) {
      log::function("ostream << Node");
      throw;
   }
}
