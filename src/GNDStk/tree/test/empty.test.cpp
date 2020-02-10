
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree empty()") {

   GIVEN("A tree") {
      gnds::Tree<> tree;

      WHEN("The tree is default-constructed") {
         REQUIRE(tree.empty()); // it has nothing in it
      }

      WHEN("A GNDS file is read into the tree") {
         tree.read("n-008_O_016.xml");
         REQUIRE(!tree.empty()); // it has something in it
      }
   }

}
