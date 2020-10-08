
#include "catch.hpp"
#include "GNDStk.hpp"
#include <cstring>

using namespace njoy::GNDStk;
using namespace mixed::child;
using namespace mixed::meta;

SCENARIO("Testing GNDStk Node all()") {

   GIVEN("A tree read from a particular example GNDS file") {
      // tree
      const Tree<> tree("n-008_O_016.xml");

      // chemicalElements / chemicalElement
      WHEN("We extract all <chemicalElement> nodes within <chemicalElements>") {
         const auto &CEs = tree(reactionSuite,PoPs,chemicalElements);
         {
            // without "found"
            auto ce = CEs.all("chemicalElement");
            THEN("We find eight of them") {
               CHECK(ce.size() == 8);
            }
         } {
            // with "found"
            bool found = false;
            auto ce = CEs.all("chemicalElement",found);
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
            CHECK(Rs.all("reaction",nplus).size() == 15);
         }

         THEN("There is one <reaction> node with ENDF_MT=\"600\"") {
            CHECK(Rs.all("reaction",endf_mt_600).size() == 1);
         }

         THEN("There are no <reaction> nodes with both "
              "label=\"n + *\" and ENDF_MT=\"600\"") {
            bool found = true;
            CHECK(Rs.all("reaction",filter_both,found).size() == 0);
            CHECK(!found);
         }
      }

      // reactions / reaction
      WHEN("We invoke node::all() with an empty (\"\") key") {
         auto Rs = tree(reactionSuite,reactions);

         THEN("We get back a container with one node, identical to *this") {
            bool found = false;
            auto vec = Rs.all("",found); // ensure this version works
            CHECK(found == true);
            vec = Rs.all(""); // and this one
            CHECK(vec.size() == 1);
            std::ostringstream oss1; oss1 << Rs.sort();
            std::ostringstream oss2; oss2 << vec[0].sort();
            CHECK(oss1.str() == oss2.str());
         }

         THEN("As above, with filter") {
            // filter should be ignored when used with key==""
            auto filter = [](const node &n) { return false; };
            bool found = false;
            auto vec = Rs.all("",filter,found); // ensure this version works
            CHECK(found == true);
            vec = Rs.all("",filter); // and this one
            CHECK(vec.size() == 1);
            std::ostringstream oss1; oss1 << Rs.sort();
            std::ostringstream oss2; oss2 << vec[0].sort();
            CHECK(oss1.str() == oss2.str());
         }
      }
   }
}
