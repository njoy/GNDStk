
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace GNDStk;

SCENARIO("Testing GNDStk Node one()") {

   GIVEN("A tree object") {
      // tree
      Tree<> tree("n-008_O_016.xml");

      // node: reactionSuite
      Node<> &rs = tree(child::reactionSuite);
      const Node<> &const_rs = rs;

      WHEN("We extract one PoPs node") {
         // From the reactionSuite node, let's get one PoPs node; one,
         // in fact is all there is. If there were many, we'd probably
         // want to use all() instead of one().
         Node<> &pops = rs.one("PoPs");
         CHECK(pops.meta("name") == "protare_internal");

         // const version
         const Node<> &cpops = const_rs.one("PoPs");
         CHECK(cpops.meta("name") == "protare_internal");
      }
   }
}
