
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node clear()") {
   GIVEN("A default-constructed Node") {
      Node n;
      THEN("It checks as being empty()") {
         CHECK(n.empty());
      }

      WHEN("A name, metadata, and children are added") {
         n.name = "I'm a Node"; // name
         n.add("one","two"); // metadatum
         n.add("three","four"); // another metadatum
         n.add("five"); // child
         n.add("six"); // another child

         THEN("The Node is no longer empty") {
            CHECK(!n.empty());
         }
      }

      WHEN("But if we clear the non-empty Node") {
         n.clear();
         THEN("It's empty again") {
            CHECK(n.empty());
         }
      }
   }
}
