
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
using namespace mixed::child;

SCENARIO("Testing GNDStk Node all()") {

   GIVEN("A tree object") {
      // tree
      const Tree<> tree("n-008_O_016.xml");

      // node: chemicalElements
      const auto &elems = tree(reactionSuite,PoPs,chemicalElements);

      WHEN("We extract all chemicalElement nodes of chemicalElements") {
         // nodes: chemicalElement
         bool found = false;
         auto elem = elems.all("chemicalElement",found);
         CHECK(found);
         CHECK(elem.size() == 8);
      }
   }
}
