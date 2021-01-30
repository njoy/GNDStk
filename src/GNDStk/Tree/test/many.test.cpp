
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Tree many()") {

   GIVEN("A Tree read from n-069_Tm_170-covar.xml") {
      // c: a const Tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const Tree
      Tree<> t = c;
      // found flag
      bool found;

      // Note: Tree's many() function can give back the declaration node or
      // the top-level GNDS node (or both if they have the same name, which
      // really wouldn't be a correct state of affairs).

      WHEN("We look for all \"xml\" nodes") {
         // Declaration node...

         // const
         found = false;
         auto cnode = c.many("xml",found);
         CHECK(found);
         CHECK(cnode.size() == 1);
         CHECK(cnode[0].name == "xml");
         CHECK(cnode[0].meta("version") == "1.0");

         // non-const
         found = false;
         auto tnode = t.many("xml",found);
         CHECK(found);
         CHECK(tnode.size() == 1);
         CHECK(tnode[0].name == "xml");
         CHECK(tnode[0].meta("encoding") == "UTF-8");
      }

      WHEN("We look for all \"covarianceSuite\" nodes") {
         // Top-level GNDS node...

         // const
         found = false;
         auto cnode = c.many("covarianceSuite",found);
         CHECK(found);
         CHECK(cnode.size() == 1);
         CHECK(cnode[0].name == "covarianceSuite");
         CHECK(cnode[0].meta("target") == "Tm170");

         // non-const
         found = false;
         auto tnode = t.many("covarianceSuite",found);
         CHECK(found);
         CHECK(tnode.size() == 1);
         CHECK(tnode[0].name == "covarianceSuite");
         CHECK(tnode[0].meta("evaluation") == "ENDF/B-8.0");
      }

      WHEN("We look for some nonexistent tree nodes") {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto cnode = c.many("foo",found);
         CHECK(!found);
         CHECK(cnode.size() == 0);

         // non-const
         found = true;
         auto tnode = t.many("bar",found);
         CHECK(!found);
         CHECK(tnode.size() == 0);
      }
   }
}
