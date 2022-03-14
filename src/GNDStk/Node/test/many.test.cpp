
#include "catch.hpp"
#include "GNDStk.hpp"
#include <cstring>

using namespace njoy::GNDStk;

#include "GNDStk/test/keys.hpp"
using namespace misc;

SCENARIO("Testing GNDStk Node many()") {

   GIVEN("A tree read from a particular example GNDS file") {
      // tree
      const Tree tree("n-008_O_016.xml");

      // chemicalElements / chemicalElement
      WHEN("We extract all <chemicalElement> nodes within <chemicalElements>") {
         const auto &CEs = tree(reactionSuite,PoPs,chemicalElements);

         THEN("We find eight of them (case: has_many() withOUT \"found\")") {
            // without "found"
            CHECK(CEs.has_many("chemicalElement"));
            auto ce = CEs.many("chemicalElement");
            CHECK(ce.size() == 8);
         }

         THEN("We find eight of them (case: has_many() with \"found\")") {
            // with "found"
            bool found = false;
            auto ce = CEs.many("chemicalElement",found);
            CHECK(found);
            CHECK(ce.size() == 8);
         }
      }

      // reactions / reaction
      WHEN("We extract selected <reactions> nodes within <reaction>") {
         const auto &Rs = tree(reactionSuite,reactions);

         // filter that requires: Node has metadata label="n + *"
         auto nplus = [](const Node &n)
            { return 0 == strncmp(n(label).data(), "n + ", 4); };

         // filter that requires: Node has metadata ENDF_MT="600"
         auto endf_mt_600 = [](const Node &n)
            { return n(ENDF_MT) == 600; };

         // filter that requires: both of the above
         auto filter_both = [nplus,endf_mt_600](const Node &n)
            { return nplus(n) && endf_mt_600(n); };

         THEN("There are 15 <reaction> Nodes with label=\"n + *\"") {
            CHECK(Rs.has_many("reaction",nplus));
            CHECK(Rs.many("reaction",nplus).size() == 15);
         }

         THEN("There is one <reaction> Node with ENDF_MT=\"600\"") {
            CHECK(Rs.has_many("reaction",endf_mt_600));
            CHECK(Rs.many("reaction",endf_mt_600).size() == 1);
         }

         THEN("There are no <reaction> Nodes with both "
              "label=\"n + *\" and ENDF_MT=\"600\"") {
            bool found = true;
            CHECK(!Rs.has_many("reaction",filter_both));
            CHECK(Rs.many("reaction",filter_both,found).size() == 0);
            CHECK(!found);
         }
      }

      // reactions / reaction
      WHEN("We invoke Node::many() with an empty (\"\") key") {
         auto Rs = tree(reactionSuite,reactions);

         THEN("We get back a container with one Node, identical to *this") {
            bool found = false;
            CHECK(Rs.has_many(""));
            auto vec = Rs.many("",found); // ensure this version works
            CHECK(found);
            vec = Rs.many(""); // and this one
            CHECK(vec.size() == 1);
            CHECK(Rs == vec[0]);
         }

         THEN("As above, with filter") {
            // filter should be ignored when used with key == ""
            auto filter = [](const Node &n) { return false; };
            bool found = false;
            CHECK(Rs.has_many("",filter));
            auto vec = Rs.many("",filter,found); // ensure this version works
            CHECK(found);
            vec = Rs.many("",filter); // and this one
            CHECK(vec.size() == 1);
            CHECK(Rs == vec[0]);
         }
      }
   }
}
