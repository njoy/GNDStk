
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace GNDStk;

SCENARIO("Testing GNDStk tree one()") {

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      // c: a const tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const tree
      Tree<> t = c;
      // found flag
      bool found;

      // Note: Tree's one() function can give back either the declaration
      // node, or the top-level GNDS node; we consider both of those to be
      // a Tree's children.

      {
         // Declaration node...

         // const
         found = false;
         auto &cnode = c.one("xml",found);
         REQUIRE(found == true);
         REQUIRE(cnode.name == "xml");
         REQUIRE(cnode.meta("version") == "1.0");

         // non-const
         found = false;
         auto &tnode = t.one("xml",found);
         REQUIRE(found == true);
         REQUIRE(tnode.name == "xml");
         REQUIRE(tnode.meta("encoding") == "UTF-8");

      } {
         // Top-level GNDS node...

         // const
         found = false;
         auto &cnode = c.one("covarianceSuite",found);
         REQUIRE(found == true);
         REQUIRE(cnode.name == "covarianceSuite");
         REQUIRE(cnode.meta("target") == "Tm170");

         // non-const
         found = false;
         auto &tnode = t.one("covarianceSuite",found);
         REQUIRE(found == true);
         REQUIRE(tnode.name == "covarianceSuite");
         REQUIRE(tnode.meta("evaluation") == "ENDF/B-8.0");

      } {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto &cnode = c.one("foo",found);
         REQUIRE(found == false);

         // non-const
         found = true;
         auto &tnode = t.one("bar",found);
         REQUIRE(found == false);

      }

      // Illustrate that Tree's one(string) functions return references,
      // even when the child isn't found...
      (void)&c.one("xml");
      (void)&c.one("covarianceSuite");
      (void)&c.one("foo",found);

      (void)&t.one("xml");
      (void)&t.one("covarianceSuite");
      (void)&t.one("bar",found);
   }
}
