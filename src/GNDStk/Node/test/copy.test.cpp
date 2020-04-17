
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node copy()") {
   GNDStk::Node<> node1;
   REQUIRE(node1.empty());
   const GNDStk::Node<> node2 = node1.copy();
   REQUIRE(node2.empty());

   node1.name = "I'm a node"; // name
   node1.add("one","two"); // metadatum
   node1.add("three","four"); // another metadatum
   node1.add("five"); // child
   node1.add("six"); // another child
   node1.add("seven"); // another child

   GIVEN("One node, copied from another") {
      const auto node2 = node1.copy();

      // name
      REQUIRE(node2.name == "I'm a node");

      // metadata
      REQUIRE(node2.metadata.size() == 2);
      auto meta = node2.metadata.begin();
      REQUIRE(meta->first == "one");
      REQUIRE(meta->second == "two");
      meta++;
      REQUIRE(meta->first == "three");
      REQUIRE(meta->second == "four");

      // children
      REQUIRE(node2.children.size() == 3);
      auto child = node2.children.begin();
      REQUIRE((*child)->name == "five");
      REQUIRE((*++child)->name == "six");
      REQUIRE((*++child)->name == "seven");
   }
}
