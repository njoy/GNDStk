
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree clear()") {

   GIVEN("A tree") {
      GNDStk::Tree<> tree;

      WHEN("The tree is default-constructed") {
         REQUIRE(tree.empty()); // it has nothing in it
      }

      WHEN("A GNDS file is read into the tree, but then clear() is called") {
         tree.read("n-008_O_016.xml");
         tree.clear();
         REQUIRE(tree.empty()); // it still has nothing in it
      }
   }

}
