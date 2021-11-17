
// -----------------------------------------------------------------------------
// Tree
// -----------------------------------------------------------------------------

class Tree : public Node {
public:

   // ------------------------
   // Simple functions
   // ------------------------

   // clear
   Tree &clear()
   {
      return this->Node::clear(), *this;
   }

   // sort
   Tree &sort()
   {
      return this->Node::sort(), *this;
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

   // No-argument operator() returns the top-level Node. This overrides
   // the base Node class' no-argument operator(), which returns itself.
   const Node &operator()() const { return top(); }
   Node &operator()() { return top(); }
   using Node::operator(); // or the above would disappear Node's goodies

   // ------------------------
   // Comparison
   // ------------------------

   // We pull out top() first, rather than deferring immediately to Node's
   // operator==, because Tree can contain a "declaration node" that might
   // indicate properties such as whether the data came from an XML, JSON,
   // or HDF5 file. Those properties can be put to good use for other things,
   // but won't play a role in a Tree comparison.

   // operator==
   bool operator==(const Tree &other) const
   {
      try {
         return top() == other.top();
      } catch (...) {
         log::function("Tree == Tree");
         throw;
      }
   }

   // operator!=
   bool operator!=(const Tree &other) const
   {
      try {
         return !(*this == other);
      } catch (...) {
         log::function("Tree != Tree");
         throw;
      }
   }

}; // class Tree



// -----------------------------------------------------------------------------
// Stream I/O
// -----------------------------------------------------------------------------

// operator>>
inline std::istream &operator>>(std::istream &is, Tree &tree)
{
   try {
      return tree.read(is);
   } catch (...) {
      log::function("istream >> Tree");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const Tree &tree)
{
   try {
      return tree.write(os);
   } catch (...) {
      log::function("ostream << Tree");
      throw;
   }
}


// -----------------------------------------------------------------------------
// I/O with respect to a string
// As for Node.
// -----------------------------------------------------------------------------

// fixme Not currently tested
// Tree << string
// Note that this is an INPUT operator to Tree!
// Other comments as for Node << string
inline void operator<<(Tree &tree, const std::string &str)
{
   try {
      std::istringstream iss(str);
      tree.read(iss);
   } catch (...) {
      log::function("Tree << string");
      throw;
   }
}

// string >> Tree
// fixme Write and test this
