
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree root") {

   GIVEN("A tree") {
      GNDStk::Tree<> tree;

      WHEN("The tree is default-constructed") {
         REQUIRE(tree.root == nullptr); // it has nothing in it
      }

      WHEN("A GNDS file is read into the tree") {
         tree.read("n-008_O_016.xml");
         REQUIRE(tree.root != nullptr); // it has something in it
      }
   }

}
