
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node assignment") {
   GIVEN("A tree read from a GNDS file") {
      Tree tree("n-008_O_016.xml");

      WHEN("We assign: Node = tree.top()") {
         Node node;

         // put some initial content into the node...
         node.add("key","value");
         node.add("name");

         // assign...
         node = tree.top(); // Node = Node

         THEN("The Node, and the tree's top-level node, are identical") {
            std::ostringstream osst; osst << tree.top();
            std::ostringstream ossn; ossn << node;
            CHECK(osst.str() == ossn.str());
         }
      }
   }
}
