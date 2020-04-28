
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
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "1.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "reactionSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(reactionSuite, format::json)") {
         Tree<> t;
         t.reset(reactionSuite, format::json);
         CHECK(t.decl().name == "json");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "reactionSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(covarianceSuite, format::null, \"2.0\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::null, "2.0");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "2.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "covarianceSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(covarianceSuite, format::xml, \"3.0\", \"UTF-9\")") {
         Tree<> t;
         t.reset(covarianceSuite, format::xml, "3.0", "UTF-9");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "3.0");
         CHECK(t.decl().meta("encoding") == "UTF-9");
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "covarianceSuite");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(PoPs, \"hdf5\")") {
         Tree<> t;
         t.reset(PoPs, "hdf5");
         CHECK(t.decl().name == "hdf5");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "PoPs");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);

      }

      WHEN("We call: "
           "Tree.reset(PoPs, \"tree\", \"4.0\")") {
         Tree<> t;
         t.reset(PoPs, "tree", "4.0");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "4.0");
         CHECK(t.decl().meta("encoding") == "UTF-8");
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "PoPs");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }

      WHEN("We call: "
           "Tree.reset(thermalScattering, \"xml\", \"5.0\", \"UTF-10\")") {
         Tree<> t;
         t.reset(thermalScattering, "xml", "5.0", "UTF-10");
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 2);
         CHECK(t.decl().meta("version") == "5.0");
         CHECK(t.decl().meta("encoding") == "UTF-10");
         CHECK(t.decl().children.size() == 1);
         CHECK(t.top().name == "thermalScattering");
         CHECK(t.top().metadata.size() == 0);
         CHECK(t.top().children.size() == 0);
      }
   }

}
