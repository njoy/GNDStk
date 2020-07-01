
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree decl()") {
   using namespace njoy::GNDStk;
   using namespace mixed::child;

   GIVEN("A tree read from an XML file") {
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

      CHECK(t.decl().name == "xml");
      CHECK(t.decl().metadata.size() == 2);
      CHECK(t.decl().meta("version") == "1.0");
      CHECK(t.decl().meta("encoding") == "UTF-8");
      CHECK(t.decl().children.size() == 0);
   }

   GIVEN("An empty tree") {

      WHEN("reset(reactionSuite)") {
         Tree<> t;
         t.reset(reactionSuite);
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "1.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 0);
      }

      WHEN("reset(reactionSuite, format::json)") {
         Tree<> t;
         t.reset(reactionSuite, format::json);
         CHECK(t.decl().name == "json");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::null, "2.0");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "2.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 0);
      }

      WHEN("reset(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::xml, "3.0", "UTF-9");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "3.0");
         CHECK(t.decl().meta("encoding") == "UTF-9");
         CHECK(t.decl().children.size() == 0);
      }

      WHEN("reset(PoPs, \"hdf5\")") {
         Tree<> t;
         t.reset(PoPs, "hdf5");
         CHECK(t.decl().name == "hdf5");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 0);

      }

      WHEN("reset(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.reset(PoPs, "tree", "4.0");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "4.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 0);
      }

      WHEN("reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "5.0");
         CHECK(t.decl().meta("encoding") == "UTF-10");
         CHECK(t.decl().children.size() == 0);
      }
   }

}
