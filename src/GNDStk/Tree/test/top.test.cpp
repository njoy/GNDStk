
#include "catch.hpp"
#include "GNDStk.hpp"
#include "GNDStk/test/keys.hpp"

SCENARIO("Testing GNDStk Tree top()") {
   using namespace njoy::GNDStk;
   using namespace misc;

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      Tree t("n-069_Tm_170-covar.xml");

      CHECK(t.top().name == "covarianceSuite");
      CHECK(t.top().metadata.size() == 4);
      CHECK(t.top().meta("projectile") == "n");
      CHECK(t.top().meta("target") == "Tm170");
      CHECK(t.top().meta("evaluation") == "ENDF/B-8.0");
      CHECK(t.top().meta("format") == "1.9");
      CHECK(t.top().children.size() == 3);
   }

   GIVEN("An empty tree") {

      WHEN("We call reset(reactionSuite)") {
         Tree t;
         t.reset(reactionSuite);
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "reactionSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(reactionSuite, FileType::json)") {
         Tree t;
         t.reset(reactionSuite, FileType::json);
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "reactionSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(covarianceSuite, FileType::guess, \"2.0\")") {
         Tree t;
         t.reset(covarianceSuite, FileType::guess, "2.0");
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "covarianceSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(covarianceSuite, FileType::xml, "
           "\"3.0\", \"UTF-9\")") {
         Tree t;
         t.reset(covarianceSuite, FileType::xml, "3.0", "UTF-9");
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "covarianceSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(PoPs, \"hdf5\")") {
         Tree t;
         t.reset(PoPs, "hdf5");
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "PoPs");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(PoPs, \"debug\", \"4.0\")") {
         Tree t;
         t.reset(PoPs, "debug", "4.0");
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "PoPs");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         THEN("We can make various top() (top-level node) queries") {
            CHECK(t.top().name == "thermalScattering");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }
   }
}
