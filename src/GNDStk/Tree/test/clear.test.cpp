
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Tree clear()") {

   GIVEN("A default-constructed tree") {
      Tree<> tree;
      THEN("It checks as being empty()") {
         CHECK(tree.empty());
      }

      WHEN("A GNDS file is read into the tree") {
         tree.read("n-008_O_016.xml");
         THEN("It checks as being non-empty()") {
            CHECK(!tree.empty());
         }
         THEN("After clear() is called, it's empty again") {
            tree.clear();
            CHECK(tree.empty());
         }
      }
   }
}
