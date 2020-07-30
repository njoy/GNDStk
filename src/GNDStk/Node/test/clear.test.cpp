
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node clear()") {

   GIVEN("A default-constructed node") {
      Node<> n;
      CHECK(n.empty());

      WHEN("a name, metadata, and children are added") {
         n.name = "I'm a node"; // name
         n.add("one","two"); // metadatum
         n.add("three","four"); // another metadatum
         n.add("five"); // child
         n.add("six"); // another child

         // well, now it's not empty
         CHECK(!n.empty());

         // clear it!
         n.clear();

         // now it's empty again
         CHECK(n.empty());
      }
   }

}
