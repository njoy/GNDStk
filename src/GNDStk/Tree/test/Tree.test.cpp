
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Tree") {
   GIVEN("A Tree") {
      Tree tree;
      CHECK(tree.empty());
   }
}
