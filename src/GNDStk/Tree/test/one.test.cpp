
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Tree one()") {

   GIVEN("A Tree read from n-069_Tm_170-covar.xml") {
      // c: a const Tree
      const Tree c("n-069_Tm_170-covar.xml");
      // t: a non-const Tree
      Tree t = c;
      // found flag
      bool found;

      // Note: Tree's one() function can give back either the declaration
      // node, or the top-level GNDS node; we consider both of those to be
      // a Tree's children.

      WHEN("We look for an \"#xml\" node") {
         // Declaration node...

         // const
         found = false;
         auto &cnode = c.one(special::xml,found);
         CHECK(found);
         CHECK(cnode.name == special::xml);
         CHECK(cnode.meta("version") == "1.0");

         // non-const
         found = false;
         auto &tnode = t.one(special::xml,found);
         CHECK(found);
         CHECK(tnode.name == special::xml);
         CHECK(tnode.meta("encoding") == "UTF-8");
      }

      WHEN("We look for a \"covarianceSuite\" node") {
         // Top-level GNDS node...

         // const
         found = false;
         auto &cnode = c.one("covarianceSuite",found);
         CHECK(found);
         CHECK(cnode.name == "covarianceSuite");
         CHECK(cnode.meta("target") == "Tm170");

         // non-const
         found = false;
         auto &tnode = t.one("covarianceSuite",found);
         CHECK(found);
         CHECK(tnode.name == "covarianceSuite");
         CHECK(tnode.meta("evaluation") == "ENDF/B-8.0");
      }

      WHEN("We look for a nonexistent Tree node") {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto &cnode = c.one("foo",found);
         CHECK(!found);

         // non-const
         found = true;
         auto &tnode = t.one("bar",found);
         CHECK(!found);
      }

      // Illustrate that Tree's one(string) functions return references,
      // even when the child isn't found...
      (void)&c.one(special::xml);
      (void)&c.one("covarianceSuite");
      (void)&c.one("foo",found);
      CHECK(!found);

      (void)&t.one(special::xml);
      (void)&t.one("covarianceSuite");
      (void)&t.one("bar",found);
      CHECK(!found);
   }
}
