
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree all()") {

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      // c: a const tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const tree
      Tree<> t = c;
      // found flag
      bool found;

      // Note: Tree's all() function can give back the declaration node or
      // the top-level GNDS node (or both if they have the same name, which
      // really wouldn't be a correct state of affairs).

      {
         // Declaration node...

         // const
         found = false;
         auto cnode = c.all("xml",found);
         CHECK(found == true);
         CHECK(cnode.size() == 1);
         CHECK(cnode[0].name == "xml");
         CHECK(cnode[0].meta("version") == "1.0");

         // non-const
         found = false;
         auto tnode = t.all("xml",found);
         CHECK(found == true);
         CHECK(tnode.size() == 1);
         CHECK(tnode[0].name == "xml");
         CHECK(tnode[0].meta("encoding") == "UTF-8");

      } {
         // Top-level GNDS node...

         // const
         found = false;
         auto cnode = c.all("covarianceSuite",found);
         CHECK(found == true);
         CHECK(cnode.size() == 1);
         CHECK(cnode[0].name == "covarianceSuite");
         CHECK(cnode[0].meta("target") == "Tm170");

         // non-const
         found = false;
         auto tnode = t.all("covarianceSuite",found);
         CHECK(found == true);
         CHECK(tnode.size() == 1);
         CHECK(tnode[0].name == "covarianceSuite");
         CHECK(tnode[0].meta("evaluation") == "ENDF/B-8.0");

      } {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto cnode = c.all("foo",found);
         CHECK(found == false);
         CHECK(cnode.size() == 0);

         // non-const
         found = true;
         auto tnode = t.all("bar",found);
         CHECK(found == false);
         CHECK(tnode.size() == 0);

      }
   }
}
