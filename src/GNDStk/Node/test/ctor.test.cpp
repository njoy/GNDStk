
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node constructors") {
   // default
   GNDStk::Node<> n1;
   CHECK(n1.empty());

   // move
   GNDStk::Node<> n2(GNDStk::Node<>{});
   CHECK(n2.empty());

   // copy
   GNDStk::Tree<> tree("n-008_O_016.xml");
   GNDStk::Node<> node(tree.top()); // node(node)
   std::ostringstream osst; osst << tree.top();
   std::ostringstream ossn; ossn << node;
   CHECK(osst.str() == ossn.str());
}
