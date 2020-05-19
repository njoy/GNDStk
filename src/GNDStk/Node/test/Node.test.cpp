
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node (templated), node (not templated)") {

   // Node (upper-case N): takes 0, 1, or 2 template parameters
   GIVEN("A Node<default,default>") {
      Node<> n;
      CHECK(n.empty());
      CHECK(n.name == "");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // node (lower-case n) equals Node<>
   GIVEN("A node") {
      node n;
      CHECK(n.empty());
      CHECK(n.name == "");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // just for fun...
   GIVEN("A Node<various,various>") {
      using namespace std;
      { Node<deque        > n;  CHECK(n.empty()); }
      { Node<deque ,deque > n;  CHECK(n.empty()); }
      { Node<deque ,list  > n;  CHECK(n.empty()); }
      { Node<deque ,vector> n;  CHECK(n.empty()); }
      { Node<list         > n;  CHECK(n.empty()); }
      { Node<list  ,deque > n;  CHECK(n.empty()); }
      { Node<list  ,list  > n;  CHECK(n.empty()); }
      { Node<list  ,vector> n;  CHECK(n.empty()); }
      { Node<vector       > n;  CHECK(n.empty()); }
      { Node<vector,deque > n;  CHECK(n.empty()); }
      { Node<vector,list  > n;  CHECK(n.empty()); }
      { Node<vector,vector> n;  CHECK(n.empty()); }
   }
}
