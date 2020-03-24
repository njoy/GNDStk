
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree decl()") {
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

      REQUIRE(t.decl().name == "xml");
      REQUIRE(t.decl().metadata.size() == 2);
      REQUIRE(t.decl().meta("version") == "1.0");
      REQUIRE(t.decl().meta("encoding") == "UTF-8");
      REQUIRE(t.decl().children.size() == 1);
   }

   GIVEN("An empty tree") {

      WHEN("init(reactionSuite)") {
         Tree<> t;
         t.init(reactionSuite);
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "1.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
      }

      WHEN("init(reactionSuite, format::json)") {
         Tree<> t;
         t.init(reactionSuite, format::json);
         REQUIRE(t.decl().name == "json");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);
      }

      WHEN("init(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.init(covarianceSuite, format::null, "2.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "2.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
      }

      WHEN("init(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.init(covarianceSuite, format::xml, "3.0", "UTF-9");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "3.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-9");
         REQUIRE(t.decl().children.size() == 1);
      }

      WHEN("init(PoPs, \"hdf5\")") {
         Tree<> t;
         t.init(PoPs, "hdf5");
         REQUIRE(t.decl().name == "hdf5");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);

      }

      WHEN("init(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.init(PoPs, "tree", "4.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "4.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
      }

      WHEN("init(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.init(thermalScattering, "xml", "5.0", "UTF-10");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "5.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-10");
         REQUIRE(t.decl().children.size() == 1);
      }
   }

}
