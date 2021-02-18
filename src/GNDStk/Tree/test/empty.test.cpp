
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree empty()") {

   GIVEN("A tree") {
      Tree tree;

      WHEN("The tree is default-constructed") {
         CHECK(tree.empty()); // empty
      }

      WHEN("A GNDS file is read into the tree") {
         tree.read("n-008_O_016.xml");
         CHECK(!tree.empty()); // not empty
      }
   }

}
