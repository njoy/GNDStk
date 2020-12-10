
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node shuffle()") {
   Tree<> tree("n-069_Tm_170-covar.xml");

   GIVEN("A GNDS tree") {
      Tree<> copy = tree;
      copy.shuffle();

      WHEN("We randomly shuffle the tree") {
         THEN("Printed, it looks different from the original") {
            std::ostringstream oss1; oss1 << tree; // original
            std::ostringstream oss2; oss2 << copy; // shuffled
            CHECK(oss1.str() != oss2.str());
         }
      }

      WHEN("We do an order-independent comparison of shuffled and original") {
         THEN("They're still the same GNDS tree") {
            CHECK(tree == copy);
         }
      }
   }
}
