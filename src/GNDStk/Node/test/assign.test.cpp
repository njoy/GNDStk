
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node assignment") {
   // copy
   GNDStk::Tree<> tree("n-008_O_016.xml");
   GNDStk::Node<> node;
   node = tree.top(); // node = node
   std::ostringstream osst; osst << tree.top();
   std::ostringstream ossn; ossn << node;
   CHECK(osst.str() == ossn.str());
}
