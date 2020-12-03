
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing certain special functions in GNDStk Node") {
   Tree<> tree("n-008_O_016.xml");

   GIVEN("something") {
      Node<> n;
      THEN("something else") {
         CHECK(n.empty());
      }

      WHEN("foo") {
         THEN("bar") {
            CHECK(true);
         }
      }

      WHEN("one") {
         THEN("two") {
            CHECK(true);
         }
      }
   }
}
