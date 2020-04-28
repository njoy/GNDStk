
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node copy()") {
   GNDStk::Node<> node1;
   CHECK(node1.empty());
   const GNDStk::Node<> node2 = node1.copy();
   CHECK(node2.empty());

   node1.name = "I'm a node"; // name
   node1.add("one","two"); // metadatum
   node1.add("three","four"); // another metadatum
   node1.add("five"); // child
   node1.add("six"); // another child
   node1.add("seven"); // another child

   GIVEN("One node, copied from another") {
      const auto node2 = node1.copy();

      // name
      CHECK(node2.name == "I'm a node");

      // metadata
      CHECK(node2.metadata.size() == 2);
      auto meta = node2.metadata.begin();
      CHECK(meta->first == "one");
      CHECK(meta->second == "two");
      meta++;
      CHECK(meta->first == "three");
      CHECK(meta->second == "four");

      // children
      CHECK(node2.children.size() == 3);
      auto child = node2.children.begin();
      CHECK((*child)->name == "five");
      CHECK((*++child)->name == "six");
      CHECK((*++child)->name == "seven");
   }
}
