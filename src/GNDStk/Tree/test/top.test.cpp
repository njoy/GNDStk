
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree top()") {
   using namespace njoy::GNDStk;
   using namespace child;

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

      CHECK(t.top().name == "covarianceSuite");
      CHECK(t.top().metadata.size() == 4);
      CHECK(t.top().meta("projectile") == "n");
      CHECK(t.top().meta("target") == "Tm170");
      CHECK(t.top().meta("evaluation") == "ENDF/B-8.0");
      CHECK(t.top().meta("format") == "1.9");
      CHECK(t.top().children.size() == 3);
   }

   GIVEN("An empty tree") {

      WHEN("reset(reactionSuite)") {
         Tree<> t;
         t.reset(reactionSuite);
         CHECK(t.top().name == "reactionSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(reactionSuite, format::json)") {
         Tree<> t;
         t.reset(reactionSuite, format::json);
         CHECK(t.top().name == "reactionSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::null, "2.0");
         CHECK(t.top().name == "covarianceSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::xml, "3.0", "UTF-9");
         CHECK(t.top().name == "covarianceSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(PoPs, \"hdf5\")") {
         Tree<> t;
         t.reset(PoPs, "hdf5");
         CHECK(t.top().name == "PoPs");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.reset(PoPs, "tree", "4.0");
         CHECK(t.top().name == "PoPs");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         CHECK(t.top().name == "thermalScattering");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }
   }

}
