
#include "GNDStk/Tree/src/detail.hpp"

// -----------------------------------------------------------------------------
// Tree
// -----------------------------------------------------------------------------

class Tree : public Node {
   using nodeType = Node;
public:

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
inline std::istream &operator>>(std::istream &is, Tree &obj)
{
   try {
      return obj.read(is);
   } catch (...) {
      log::function("istream >> Tree");
      throw;
   }
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const Tree &obj)
{
   try {
      return obj.write(os);
   } catch (...) {
      log::function("ostream << Tree");
      throw;
   }
}
