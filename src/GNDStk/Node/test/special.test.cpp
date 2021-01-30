
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

SCENARIO("Testing certain special functions in GNDStk Node") {
   Tree<> t("n-008_O_016.xml");
   const Tree<> &c = t; // const version

   GIVEN("A GNDS tree") {
      // Get the documentation CDATA text string directly, for
      // use in checking if our direct function gets it properly
      const std::string thedocs = t(
         reactionSuite,
         documentations,
         documentation,
         cdata,
         text
      );
      CHECK(thedocs.size() == 46742);

      // ------------------------
      // documentation()
      // doc()
      // ------------------------

      WHEN("Testing documentation() and doc()") {
         // works from the tree...
         CHECK(t.documentation() == thedocs);
         CHECK(c.documentation() == thedocs);
         CHECK(t.doc() == thedocs);
         CHECK(c.doc() == thedocs);

         // works from the top-level GNDS node...
         CHECK(t(reactionSuite).documentation() == thedocs);
         CHECK(c(reactionSuite).documentation() == thedocs);
         CHECK(t(reactionSuite).doc() == thedocs);
         CHECK(c(reactionSuite).doc() == thedocs);

         // works from the <documentations> node...
         CHECK(t(reactionSuite,documentations).documentation() == thedocs);
         CHECK(c(reactionSuite,documentations).documentation() == thedocs);
         CHECK(t(reactionSuite,documentations).doc() == thedocs);
         CHECK(c(reactionSuite,documentations).doc() == thedocs);

         // works from the <documentation> node...
         CHECK(t(reactionSuite,documentations,documentation).
               documentation() == thedocs);
         CHECK(c(reactionSuite,documentations,documentation).
               documentation() == thedocs);
         CHECK(t(reactionSuite,documentations,documentation).doc() == thedocs);
         CHECK(c(reactionSuite,documentations,documentation).doc() == thedocs);

         // works from the <cdata> node...
         CHECK(t(reactionSuite,documentations,documentation,cdata).
               documentation() == thedocs);
         CHECK(c(reactionSuite,documentations,documentation,cdata).
               documentation() == thedocs);
         CHECK(t(reactionSuite,documentations,documentation,cdata).
               doc() == thedocs);
         CHECK(c(reactionSuite,documentations,documentation,cdata).
               doc() == thedocs);

         // doesn't work from some other place...
         bool found;
         CHECK(!(t(reactionSuite,PoPs).documentation(found=true),found));
         CHECK(!(c(reactionSuite,PoPs).documentation(found=true),found));
         CHECK(!(t(reactionSuite,PoPs).doc(found=true),found));
         CHECK(!(c(reactionSuite,PoPs).doc(found=true),found));
      }

      // ------------------------
      // cdata()
      // ------------------------

      WHEN("Testing cdata()") {
         {
            Node<> &n = t(reactionSuite,documentations,documentation);
            CHECK(n.cdata() == thedocs);
         } {
            const Node<> &n = c(reactionSuite,documentations,documentation);
            CHECK(n.cdata() == thedocs);
         }
      }

      // ------------------------
      // pcdata()
      // ------------------------

      WHEN("Testing pcdata()") {
         auto &valnode = t(
            reactionSuite,
            reactions,
            reaction, "n + O16",
            crossSection,
            XYs1d, "eval"
         ).one("values");
         const auto &constvalnode = valnode;

         const std::string vals = valnode(pcdata,text);
         CHECK(vals.size() == 70254);

         CHECK(valnode.pcdata() == vals);
         CHECK(constvalnode.pcdata() == vals);
      }

      // ------------------------
      // comment()
      // comments()
      // ------------------------

      // I'll test these in a Tree test file, as we have a resources/ XML
      // file there (but not here) that has cases of more than one comment
      // appearing together.
   }
}
