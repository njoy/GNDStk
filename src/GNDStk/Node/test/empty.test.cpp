
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node empty()") {

   GIVEN("A default-constructed node") {
      GNDStk::Node<> n;
      REQUIRE(n.empty()); // it's empty
   }

   GIVEN("An initially empty node is assigned a name") {
      GNDStk::Node<> n;
      REQUIRE(n.empty());
      n.name = "foo";
      REQUIRE(!n.empty()); // it's not empty
   }

   GIVEN("An initially empty node is given a metadatum") {
      GNDStk::Node<> n;
      REQUIRE(n.empty());
      n.add("foo","bar");
      REQUIRE(n.metadata.size() == 1);
      REQUIRE(!n.empty()); // it's not empty
   }

   GIVEN("An initially empty node is given an empty child node") {
      GNDStk::Node<> n;
      REQUIRE(n.empty());
      n.add();
      REQUIRE(n.children.size() == 1);
      REQUIRE(!n.empty()); // it's not empty
      REQUIRE((*n.children.begin())->empty()); // but the child is empty
   }

   GIVEN("An initially empty node is given a named child node") {
      GNDStk::Node<> n;
      REQUIRE(n.empty());
      n.add("child");
      REQUIRE(n.children.size() == 1);
      REQUIRE(!n.empty()); // it's not empty
   }

}
