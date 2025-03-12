
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node") {
   GIVEN("A Node") {
      Node n;
      CHECK(n.empty());
      CHECK(n.name == emptyNodeName);
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }
}
