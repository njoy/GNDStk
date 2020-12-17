
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

SCENARIO("Testing GNDStk Node operator==() and operator!=") {
   Tree<> oh("n-008_O_016.xml");
   Tree<> o2 = oh;
   Tree<> tm("n-069_Tm_170-covar.xml");
   Tree<> t2 = tm;

   GIVEN("Two different GNDS trees") {
      WHEN("We try all four comparisons") {
         CHECK(oh == oh);
         CHECK(oh != tm);
         CHECK(tm != oh);
         CHECK(tm == tm);
      }
   }

   GIVEN("Two randomly shuffled versions of the same tree") {
      // for the O file
      oh.shuffle(); std::string astr; convert(oh,astr);
      o2.shuffle(); std::string bstr; convert(o2,bstr);

      // for the Tm file
      tm.shuffle(); std::string cstr; convert(tm,cstr);
      t2.shuffle(); std::string dstr; convert(t2,dstr);

      WHEN("We compare directly, they look different") {
         // Note: technically, if the "random" shuffle behaved in such a way
         // that, by chance, it didn't change anything, then these could fail.
         // We don't think there's much chance that that will happen.
         CHECK(astr != bstr);
         CHECK(cstr != dstr);
      }

      WHEN("We compare using operator==, they're the same") {
         CHECK(oh == o2);
         CHECK(tm == t2);
         // Try directly a few times...
         CHECK(oh.shuffle() == o2.shuffle());
         CHECK(oh.shuffle() == o2.shuffle());
         CHECK(oh.shuffle() == o2.shuffle());
      }
   }

   GIVEN("Two equal trees") {
      /*
        <mass>
          <double label="eval" value="0.0" unit="amu"/>
        </mass>
        <spin>
          <fraction label="eval" value="1" unit="hbar"/>
        </spin>
        <parity>
          <integer label="eval" value="1"/>
        </parity>
        <charge>
          <integer label="eval" value="0" unit="e"/>
        </charge>
        <halflife>
          <string label="eval" value="stable" unit="s"/>
        </halflife>
      */

      WHEN("We change a node name somewhere") {
         o2 = oh;
         o2(reactionSuite,PoPs,
            gaugeBosons,--gaugeBoson).name = "foo";
         THEN("operator== fails") {
            CHECK(o2 != oh);
         }
      }

      WHEN("We change a metadatum key somewhere") {
         o2 = oh;
         o2(reactionSuite,PoPs,
            gaugeBosons,--gaugeBoson,mass,Double).metadata[1].first
            = "foo";
         THEN("operator== fails") {
            CHECK(o2 != oh);
         }
      }

      WHEN("We change a metadatum value somewhere") {
         o2 = oh;
         o2(reactionSuite,PoPs,
            gaugeBosons,--gaugeBoson,child::spin,fraction,unit) = "hfoo";
         THEN("operator== fails") {
            CHECK(o2 != oh);
         }
      }

      WHEN("We remove a node somewhere") {
         o2 = oh;
         o2(reactionSuite,PoPs).children.pop_back();
         THEN("operator== fails") {
            CHECK(o2 != oh);
         }
      }

      WHEN("We remove a metadatum somewhere") {
         o2 = oh;
         o2(reactionSuite,PoPs).metadata.pop_back();
         THEN("operator== fails") {
            CHECK(o2 != oh);
         }
      }
   }
}
