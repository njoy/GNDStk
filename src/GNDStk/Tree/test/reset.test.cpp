
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree reset()") {
   using namespace GNDStk;
   using namespace GNDStk::child;

   GIVEN("An empty tree") {

      /*
      Cases:
         reset(top-level node)
         reset(top-level node, format)
         reset(top-level node, format, version)
         reset(top-level node, format, version, encoding)
         reset(top-level node, string)
         reset(top-level node, string, version)
         reset(top-level node, string, version, encoding)
      */

      WHEN("We call: "
           "Tree.reset(reactionSuite)") {
         Tree<> t;
         t.reset(reactionSuite);
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "1.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(reactionSuite, format::json)") {
         Tree<> t;
         t.reset(reactionSuite, format::json);
         REQUIRE(t.decl().name == "json");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::null, "2.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "2.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::xml, "3.0", "UTF-9");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "3.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-9");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(PoPs, \"hdf5\")") {
         Tree<> t;
         t.reset(PoPs, "hdf5");
         REQUIRE(t.decl().name == "hdf5");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);

      }

      WHEN("We call: "
           "Tree.reset(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.reset(PoPs, "tree", "4.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "4.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "5.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-10");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "thermalScattering");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }
   }

}
