
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree top()") {
   using namespace GNDStk;
   using namespace GNDStk::child;

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      Tree<> t("n-069_Tm_170-covar.xml");

      /*
      <?xml
         version="1.0"
         encoding="UTF-8"
      ?>

      <covarianceSuite
         projectile="n"
         target="Tm170"
         evaluation="ENDF/B-8.0"
         format="1.9"
      >
        <styles> ... </styles>
        <externalFiles> ... </externalFiles>
        <parameterCovariances> ... </parameterCovariances>
      </covarianceSuite>
      */

      REQUIRE(t.top().name == "covarianceSuite");
      REQUIRE(t.top().metadata.size() == 4);
      REQUIRE(t.top().meta("projectile") == "n");
      REQUIRE(t.top().meta("target") == "Tm170");
      REQUIRE(t.top().meta("evaluation") == "ENDF/B-8.0");
      REQUIRE(t.top().meta("format") == "1.9");
      REQUIRE(t.top().children.size() == 3);
   }

   GIVEN("An empty tree") {

      WHEN("reset(reactionSuite)") {
         Tree<> t;
         t.reset(reactionSuite);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(reactionSuite, format::json)") {
         Tree<> t;
         t.reset(reactionSuite, format::json);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::null, "2.0");
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::xml, "3.0", "UTF-9");
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(PoPs, \"hdf5\")") {
         Tree<> t;
         t.reset(PoPs, "hdf5");
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.reset(PoPs, "tree", "4.0");
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         REQUIRE(t.top().name == "thermalScattering");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }
   }

}
