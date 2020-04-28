
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Node constructors") {
   // default
   GNDStk::Node<> n1;
   CHECK(n1.empty());

   // move
   GNDStk::Node<> n2(GNDStk::Node<>{});
   CHECK(n2.empty());
}
