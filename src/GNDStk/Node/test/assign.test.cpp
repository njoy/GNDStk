
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node assignment") {
   // copy
   Tree<> tree("n-008_O_016.xml");
   Node<> node;
   node = tree.top(); // node = node
   std::ostringstream osst; osst << tree.top();
   std::ostringstream ossn; ossn << node;
   CHECK(osst.str() == ossn.str());
}
