
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node constructors") {
   // default
   Node<> n1;
   CHECK(n1.empty());

   // move
   Node<> n2(Node<>{});
   CHECK(n2.empty());

   // copy
   Tree<> tree("n-008_O_016.xml");
   Node<> node(tree.top()); // node(node)
   std::ostringstream osst; osst << tree.top();
   std::ostringstream ossn; ossn << node;
   CHECK(osst.str() == ossn.str());
}
