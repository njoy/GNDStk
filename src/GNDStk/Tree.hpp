
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

   // ------------------------
   // Comparison
   // ------------------------

   // We pull out top() first, rather than deferring immediately to Node's
   // operator==, because Tree can contain a "declaration node" that might
   // indicate properties such as whether the data came from an XML file or
   // a JSON file. Those properties can be put to good use for other things,
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
// I/O
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

// Tree << std::string
// Comment as for Node << std::string
inline void operator<<(Tree &tree, const std::string &str)
{
   try {
      std::istringstream iss(str);
      iss >> tree;
   } catch (...) {
      log::function("Tree << string");
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
