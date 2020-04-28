
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node (templated), node (not templated)") {

   // Node (upper-case N): takes 0, 1, or 2 template parameters
   GIVEN("A Node<default,default>") {
      GNDStk::Node<> n;
      CHECK(n.empty());
      CHECK(n.name == "");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // node (lower-case n) equals Node<>
   GIVEN("A node") {
      GNDStk::node n;
      CHECK(n.empty());
      CHECK(n.name == "");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // just for fun...
   GIVEN("A Node<various,various>") {
      using namespace std;
      { GNDStk::Node<deque        > n;  CHECK(n.empty()); }
      { GNDStk::Node<deque ,deque > n;  CHECK(n.empty()); }
      { GNDStk::Node<deque ,list  > n;  CHECK(n.empty()); }
      { GNDStk::Node<deque ,vector> n;  CHECK(n.empty()); }
      { GNDStk::Node<list         > n;  CHECK(n.empty()); }
      { GNDStk::Node<list  ,deque > n;  CHECK(n.empty()); }
      { GNDStk::Node<list  ,list  > n;  CHECK(n.empty()); }
      { GNDStk::Node<list  ,vector> n;  CHECK(n.empty()); }
      { GNDStk::Node<vector       > n;  CHECK(n.empty()); }
      { GNDStk::Node<vector,deque > n;  CHECK(n.empty()); }
      { GNDStk::Node<vector,list  > n;  CHECK(n.empty()); }
      { GNDStk::Node<vector,vector> n;  CHECK(n.empty()); }
   }
}
