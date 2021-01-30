
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node empty()") {

   GIVEN("A default-constructed Node") {
      Node<> n;
      THEN("It's empty") {
         CHECK(n.empty()); // it's empty
      }
   }

   GIVEN("Another default-constructed Node") {
      Node<> n;
      THEN("It's initially empty") {
         CHECK(n.empty());
      }
      WHEN("But when it's assigned a name") {
         n.name = "foo";
         THEN("It's no longer empty") {
            CHECK(!n.empty()); // it's not empty
         }
      }
   }

   GIVEN("An initially empty Node") {
      Node<> n;
      CHECK(n.empty());
      WHEN("It's given a metadatum") {
         n.add("foo","bar");
         CHECK(n.metadata.size() == 1);
         CHECK(!n.empty()); // it's not empty
      }
   }

   GIVEN("An initially empty Node") {
      Node<> n;
      CHECK(n.empty());
      WHEN("It's given an empty child Node") {
         n.add();
         CHECK(n.children.size() == 1);
         CHECK(!n.empty()); // it's not empty
         CHECK((*n.children.begin())->empty()); // but the child is empty
      }
   }

   GIVEN("An initially empty Node") {
      Node<> n;
      CHECK(n.empty());
      WHEN("It's given a named child Node") {
         n.add("child");
         CHECK(n.children.size() == 1);
         CHECK(!n.empty()); // it's not empty
      }
   }

}
