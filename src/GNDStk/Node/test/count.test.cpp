
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

SCENARIO("Testing GNDStk Node count()") {
   const Tree<> tree("n-008_O_016.xml");
   const node n = tree.top();

   // count() cases to check:
   //    const string &key
   //    const string &key, const FILTER &filter
   //    const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd
   //    const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, string &label
   //    const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, regex  &labelRegex

   GIVEN("A GNDS tree") {
      auto version1 = [](const node &n) { return n(version) == "1.0"; };
      auto version2 = [](const node &n) { return n(version) == "2.0"; };
      auto symbolH  = [](const node &n) { return n(symbol)[0] == 'H'; };
      auto symbolB  = [](const node &n) { return n(symbol)[0] == 'B'; };

      // count(string)
      THEN("count(string) works") {
         CHECK(n.count("PoPs") == 1);
         CHECK(n(PoPs,chemicalElements).count("chemicalElement") == 8);
      }

      // count(string,filter)
      THEN("count(string, filter) works") {
         // one such thing with version 1.0...
         CHECK(n.count("PoPs",version1) == 1);
         // none with version 2.0...
         CHECK(n.count("PoPs",version2) == 0);
         // "H" and "He" match...
         CHECK(n(PoPs,chemicalElements).count("chemicalElement",symbolH) == 2);
         // "Be" and "B" match...
         CHECK(n(PoPs,chemicalElements).count("chemicalElement",symbolB) == 2);
      }

      // count(Child)
      THEN("count(Child) works") {
         CHECK(n.count(PoPs) == 1);
         CHECK(n(PoPs,chemicalElements).count(chemicalElement) == 8);
      }

      // count(Child+filter)
      THEN("count(Child+filter) works") {
         CHECK(n.count(PoPs+version1) == 1);
         CHECK(n.count(PoPs+version2) == 0);
         CHECK(n(PoPs,chemicalElements).count(chemicalElement+symbolH) == 2);
         CHECK(n(PoPs,chemicalElements).count(chemicalElement+symbolB) == 2);
      }

      // count(Child, string label)
      THEN("count(Child, string label) works") {
         CHECK(n(reactions).count(reaction,"n + O16") == 1);
         CHECK(n(reactions).count(reaction,"foo+bar") == 0);
      }

      // count(Child+filter, string label)
      THEN("count(Child+filter, string label) works") {
         auto endfmt1 = [](const node &n) { return n(int{}/ENDF_MT) == 1; };
         auto endfmt2 = [](const node &n) { return n(int{}/ENDF_MT) == 2; };
         CHECK(n(reactions).count(reaction+endfmt1, "n + O16") == 0);
         CHECK(n(reactions).count(reaction+endfmt2, "n + O16") == 1);
      }

      // count(Child, regex label)
      THEN("count(Child, regex label) works") {
         CHECK(n(reactions).count(reaction,std::regex("H1 \\+ .*")) == 5);
         CHECK(n(reactions).count(reaction,std::regex("H2 \\+ .*")) == 20);
      }

      // count(Child+filter, regex label)
      THEN("count(Child+filter, regex label) works") {
         auto f1 = [](const node &n)
            { int mt = n(int{}/ENDF_MT); return mt > 600; };
         auto f2 = [](const node &n)
            { int mt = n(int{}/ENDF_MT); return 660 <= mt && mt <= 665; };
         CHECK(n(reactions).count(reaction+f1,std::regex("H1 \\+ .*")) == 3);
         CHECK(n(reactions).count(reaction+f2,std::regex("H2 \\+ .*")) == 6);
      }
   }
}
