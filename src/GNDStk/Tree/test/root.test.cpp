
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree root") {

   GIVEN("A tree") {
      Tree<> tree;

      WHEN("The tree is default-constructed") {
         CHECK(tree.root == nullptr); // it has nothing in it
      }

      WHEN("A GNDS file is read into the tree") {
         tree.read("n-008_O_016.xml");
         CHECK(tree.root != nullptr); // it has something in it
      }
   }

}
