
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

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

      WHEN("We look for an \"xml\" node") {
         // Declaration node...

         // const
         found = false;
         auto &cnode = c.one("xml",found);
         CHECK(found == true);
         CHECK(cnode.name == "xml");
         CHECK(cnode.meta("version") == "1.0");

         // non-const
         found = false;
         auto &tnode = t.one("xml",found);
         CHECK(found == true);
         CHECK(tnode.name == "xml");
         CHECK(tnode.meta("encoding") == "UTF-8");
      }

      WHEN("We look for a \"covarianceSuite\" node") {
         // Top-level GNDS node...

         // const
         found = false;
         auto &cnode = c.one("covarianceSuite",found);
         CHECK(found == true);
         CHECK(cnode.name == "covarianceSuite");
         CHECK(cnode.meta("target") == "Tm170");

         // non-const
         found = false;
         auto &tnode = t.one("covarianceSuite",found);
         CHECK(found == true);
         CHECK(tnode.name == "covarianceSuite");
         CHECK(tnode.meta("evaluation") == "ENDF/B-8.0");
      }

      WHEN("We look for a nonexistent tree node") {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto &cnode = c.one("foo",found);
         CHECK(found == false);

         // non-const
         found = true;
         auto &tnode = t.one("bar",found);
         CHECK(found == false);
      }

      // Illustrate that Tree's one(string) functions return references,
      // even when the child isn't found...
      (void)&c.one("xml");
      (void)&c.one("covarianceSuite");
      (void)&c.one("foo",found);
      CHECK(found == false);

      (void)&t.one("xml");
      (void)&t.one("covarianceSuite");
      (void)&t.one("bar",found);
      CHECK(found == false);
   }
}
