
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
using namespace misc;

SCENARIO("Testing GNDStk Node one()") {

   GIVEN("A tree object") {
      // tree
      Tree tree("n-008_O_016.xml");

      // Node: reactionSuite
      Node &rsuite = tree(misc::child::reactionSuite);
      const Node &const_rsuite = rsuite;

      WHEN("We extract one PoPs Node") {
         // From the reactionSuite Node, let's get one PoPs Node; one,
         // in fact is all there is. If there were many, we'd probably
         // want to use many() instead of one().
         CHECK(rsuite.has_one("PoPs"));
         Node &pops = rsuite.one("PoPs");
         CHECK(pops.meta("name") == "protare_internal");

         // const version
         CHECK(const_rsuite.has_one("PoPs"));
         const Node &cpops = const_rsuite.one("PoPs");
         CHECK(cpops.meta("name") == "protare_internal");
      }


      // ------------------------
      // Let's do the Node::one()
      // variations mechanically
      // ------------------------

      // non-const and const Nodes
      Node &rs = tree(reactionSuite,reactions);
      const Node rsconst = rs; // non-reference, makes some CHECKs better

      // filter for nodes that have label="2n + *"
      auto twon = [](const Node &n)
         { return 0 == strncmp(n(label).data(), "2n + ", 5); };

      // case 1
      WHEN("We test node.one(key,filter) const")
      {
         CHECK(rsconst.has_one("reaction",twon));
         const Node &r = rsconst.one("reaction",twon);
         CHECK(r(label) == "2n + O15 + photon");
         CHECK(r(ENDF_MT) == 16);
         // with key "": returns reference to *this; ignores filter
         CHECK(rsconst.has_one("",twon));
         CHECK(&rsconst.one("",twon) == &rsconst);
      }

      // case 2
      WHEN("We test node.one(key,filter,found) const")
      {
         bool found = false;
         CHECK(rsconst.has_one("reaction",twon));
         const Node &r = rsconst.one("reaction",twon,found);
         CHECK(found);
         CHECK(r(label) == "2n + O15 + photon");
         CHECK(r(ENDF_MT) == 16);
         CHECK(!rsconst.has_one("nonsense",twon));
         CHECK((rsconst.one("nonsense",twon,found), !found));
         // with key ""...
         found = false;
         CHECK(&rsconst.one("",twon,found) == &rsconst);
         CHECK(found);
      }

      // case 3
      WHEN("We test node.one(key,filter)")
      {
         // like case 1, but non-const version
         Node &r = rs.one("reaction",twon);
         CHECK(r(label) == "2n + O15 + photon");
         CHECK(r(ENDF_MT) == 16);
         CHECK(&rs.one("",twon) == &rs);
      }

      // case 4
      WHEN("We test node.one(key,filter,found)")
      {
         // like case 2, but non-const version
         bool found = false;
         Node &r = rs.one("reaction",twon,found);
         CHECK(found);
         CHECK(r(label) == "2n + O15 + photon");
         CHECK(r(ENDF_MT) == 16);
         CHECK((rs.one("nonsense",twon,found), !found));
         found = false;
         CHECK(&rs.one("",twon,found) == &rs);
         CHECK(found);
      }

      // case 5
      WHEN("We test node.one(key) const")
      {
         // like case 1, but without the filter
         const Node &r = rsconst.one("reaction");
         CHECK(r(label) == "n + O16");
         CHECK(r(ENDF_MT) == 2);
         CHECK(&rsconst.one("") == &rsconst);
      }

      // case 6
      WHEN("We test node.one(key,found) const")
      {
         // like case 2, but without the filter
         bool found = false;
         const Node &r = rsconst.one("reaction",found);
         CHECK(found);
         CHECK(r(label) == "n + O16");
         CHECK(r(ENDF_MT) == 2);
         CHECK((rsconst.one("nonsense",found), !found));
         found = false;
         CHECK(&rsconst.one("",found) == &rsconst);
         CHECK(found);
      }

      // case 7
      WHEN("We test node.one(key)")
      {
         // like case 3, but without the filter
         Node &r = rs.one("reaction");
         CHECK(r(label) == "n + O16");
         CHECK(r(ENDF_MT) == 2);
         CHECK(&rs.one("") == &rs);
      }

      // case 8
      WHEN("We test node.one(key,found)")
      {
         // like case 4, but without the filter
         bool found = false;
         Node &r = rs.one("reaction",found);
         CHECK(found);
         CHECK(r(label) == "n + O16");
         CHECK(r(ENDF_MT) == 2);
         CHECK((rs.one("nonsense",found), !found));
         found = false;
         CHECK(&rs.one("",found) == &rs);
         CHECK(found);
      }
   }
}
