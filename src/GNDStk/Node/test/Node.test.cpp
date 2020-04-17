
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node (templated), node (not templated)") {

   // Node (upper-case N): takes 0, 1, or 2 template parameters
   GIVEN("A Node<default,default>") {
      GNDStk::Node<> n;
      REQUIRE(n.empty());
      REQUIRE(n.name == "");
      REQUIRE(n.metadata.size() == 0);
      REQUIRE(n.children.size() == 0);
   }

   // node (lower-case n) equals Node<>
   GIVEN("A node") {
      GNDStk::node n;
      REQUIRE(n.empty());
      REQUIRE(n.name == "");
      REQUIRE(n.metadata.size() == 0);
      REQUIRE(n.children.size() == 0);
   }

   // just for fun...
   GIVEN("A Node<various,various>") {
      using namespace std;
      { GNDStk::Node<deque        > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<deque ,deque > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<deque ,list  > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<deque ,vector> n;  REQUIRE(n.empty()); }
      { GNDStk::Node<list         > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<list  ,deque > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<list  ,list  > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<list  ,vector> n;  REQUIRE(n.empty()); }
      { GNDStk::Node<vector       > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<vector,deque > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<vector,list  > n;  REQUIRE(n.empty()); }
      { GNDStk::Node<vector,vector> n;  REQUIRE(n.empty()); }
   }
}
