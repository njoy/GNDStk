
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

SCENARIO("Testing comment() and comments() in GNDStk Tree") {
   // tree
   Tree<> t("n-026_Fe_056.xml");

   // non-const and const nodes
   Node<> &n = t(
      --reactionSuite,
      --resonances,
      --resolved,
      --RMatrix,
      --spinGroups,
      --spinGroup,
      --resonanceParameters,
      --table,
      --data
   );
   const Node<> &c = n;

   // correct comments
   const std::string
      title = " energy | capture | elastic  ",
      width = "        |  width  |  width   ";

   GIVEN("A GNDS node") {

      // ------------------------
      // comment()
      // ------------------------

      WHEN("Testing comment()") {
         // non-const
         CHECK(n.comment( ) == title);
         CHECK(n.comment(0) == title);
         CHECK(n.comment(1) == width);
         // const
         CHECK(c.comment( ) == title);
         CHECK(c.comment(0) == title);
         CHECK(c.comment(1) == width);
      }

      // ------------------------
      // comments()
      // ------------------------

      WHEN("Testing comments()") {
         // non-const
         CHECK(n.comments().size() == 2);
         CHECK(n.comments()[0] == title);
         CHECK(n.comments()[1] == width);
         // const
         CHECK(c.comments().size() == 2);
         CHECK(c.comments()[0] == title);
         CHECK(c.comments()[1] == width);
      }
   }
}
