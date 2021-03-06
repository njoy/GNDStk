
#include "catch.hpp"
#include "GNDStk.hpp"
#include <cstring>

using namespace njoy::GNDStk;
using namespace misc;

SCENARIO("Testing GNDStk Node many()") {

   GIVEN("A tree read from a particular example GNDS file") {
      // tree
      const Tree<> tree("n-008_O_016.xml");

      // chemicalElements / chemicalElement
      WHEN("We extract all <chemicalElement> nodes within <chemicalElements>") {
         const auto &CEs = tree(reactionSuite,PoPs,chemicalElements);
         {
            // without "found"
            CHECK(CEs.has_many("chemicalElement"));
            auto ce = CEs.many("chemicalElement");
            THEN("We find eight of them") {
               CHECK(ce.size() == 8);
            }
         } {
            // with "found"
            bool found = false;
            auto ce = CEs.many("chemicalElement",found);
            THEN("We find eight of them") {
               CHECK(found);
               CHECK(ce.size() == 8);
            }
         }
      }

      // reactions / reaction
      WHEN("We extract selected <reactions> nodes within <reaction>") {
         const auto &Rs = tree(reactionSuite,reactions);

         // filter that requires: node has metadata label="n + *"
         auto nplus = [](const node &n)
            { return 0 == strncmp(n(label).c_str(), "n + ", 4); };

         // filter that requires: node has metadata ENDF_MT="600"
         auto endf_mt_600 = [](const node &n)
            { return n(ENDF_MT) == 600; };

         // filter that requires: both of the above
         auto filter_both = [nplus,endf_mt_600](const node &n)
            { return nplus(n) && endf_mt_600(n); };

         THEN("There are 15 <reaction> nodes with label=\"n + *\"") {
            CHECK(Rs.has_many("reaction",nplus));
            CHECK(Rs.many("reaction",nplus).size() == 15);
         }

         THEN("There is one <reaction> node with ENDF_MT=\"600\"") {
            CHECK(Rs.has_many("reaction",endf_mt_600));
            CHECK(Rs.many("reaction",endf_mt_600).size() == 1);
         }

         THEN("There are no <reaction> nodes with both "
              "label=\"n + *\" and ENDF_MT=\"600\"") {
            bool found = true;
            CHECK(!Rs.has_many("reaction",filter_both));
            CHECK(Rs.many("reaction",filter_both,found).size() == 0);
            CHECK(!found);
         }
      }

      // reactions / reaction
      WHEN("We invoke node::many() with an empty (\"\") key") {
         auto Rs = tree(reactionSuite,reactions);

         THEN("We get back a container with one node, identical to *this") {
            bool found = false;
            CHECK(Rs.has_many(""));
            auto vec = Rs.many("",found); // ensure this version works
            CHECK(found == true);
            vec = Rs.many(""); // and this one
            CHECK(vec.size() == 1);
            std::ostringstream oss1; oss1 << Rs.sort();
            std::ostringstream oss2; oss2 << vec[0].sort();
            CHECK(oss1.str() == oss2.str());
         }

         THEN("As above, with filter") {
            // filter should be ignored when used with key==""
            auto filter = [](const node &n) { return false; };
            bool found = false;
            CHECK(Rs.has_many("",filter));
            auto vec = Rs.many("",filter,found); // ensure this version works
            CHECK(found == true);
            vec = Rs.many("",filter); // and this one
            CHECK(vec.size() == 1);
            std::ostringstream oss1; oss1 << Rs.sort();
            std::ostringstream oss2; oss2 << vec[0].sort();
            CHECK(oss1.str() == oss2.str());
         }
      }
   }
}
