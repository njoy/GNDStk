
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree clear()") {

   GIVEN("A tree") {
      Tree<> tree;

      WHEN("The tree is default-constructed") {
         CHECK(tree.empty()); // it has nothing in it
      }

      WHEN("A GNDS file is read into the tree, but then clear() is called") {
         tree.read("n-008_O_016.xml");
         CHECK(!tree.empty()); // it initially has something in it
         tree.clear();
         CHECK(tree.empty()); // but then nothing, after clear() is called
      }
   }

}
