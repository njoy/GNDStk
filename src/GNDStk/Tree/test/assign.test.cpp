
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree assignments")
{
   using namespace std;
   Tree left;

   GIVEN("Tree = Tree")
   {
      // Test left = right assignment
      WHEN("We try Tree = Tree assignment") {
         Tree right;
         right.read("n-008_O_016.xml");

         // assign
         left = right;

         // Print the original tree
         std::ostringstream ossr;
         ossr << right;

         // Print the tree we assigned into
         std::ostringstream ossl;
         ossl << left;

         // If the assignment left = right worked correctly, then the original
         // tree, and the new one we assigned into, should be identical
         CHECK(ossl.str() == ossr.str());
      }

      // Test move assignment
      WHEN("We try Tree's move assignment") {
         left = Tree("n-069_Tm_170-covar.xml");
         std::ostringstream ossl; ossl << left;
         const Tree right("n-069_Tm_170-covar.xml");
         std::ostringstream ossr; ossr << right;
         CHECK(ossl.str() == ossr.str());
      }
   }
}
