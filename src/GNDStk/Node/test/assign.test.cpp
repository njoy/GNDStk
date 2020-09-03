
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node assignment") {
   GIVEN("A tree read from a GNDS file") {
      Tree<> tree("n-008_O_016.xml");
      WHEN("We assign: node = the tree") {
         Node<> node;
         node = tree.top(); // node = node
         THEN("the new node, and the tree's top-level node, are identical") {
            std::ostringstream osst; osst << tree.top();
            std::ostringstream ossn; ossn << node;
            CHECK(osst.str() == ossn.str());
         }
      }
   }
}
