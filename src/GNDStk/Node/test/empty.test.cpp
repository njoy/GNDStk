
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node empty()") {

   GIVEN("A default-constructed node") {
      Node<> n;
      CHECK(n.empty()); // it's empty
   }

   GIVEN("An initially empty node is assigned a name") {
      Node<> n;
      CHECK(n.empty());
      n.name = "foo";
      CHECK(!n.empty()); // it's not empty
   }

   GIVEN("An initially empty node is given a metadatum") {
      Node<> n;
      CHECK(n.empty());
      n.add("foo","bar");
      CHECK(n.metadata.size() == 1);
      CHECK(!n.empty()); // it's not empty
   }

   GIVEN("An initially empty node is given an empty child node") {
      Node<> n;
      CHECK(n.empty());
      n.add();
      CHECK(n.children.size() == 1);
      CHECK(!n.empty()); // it's not empty
      CHECK((*n.children.begin())->empty()); // but the child is empty
   }

   GIVEN("An initially empty node is given a named child node") {
      Node<> n;
      CHECK(n.empty());
      n.add("child");
      CHECK(n.children.size() == 1);
      CHECK(!n.empty()); // it's not empty
   }

}
