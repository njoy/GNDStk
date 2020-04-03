
#include "catch.hpp"
#include "GNDStk.hpp"

/*
What we'll need to test...

   1. Tree()
   2. Tree(Tree &&)

   3. Tree(XML)
   4. Tree(JSON)

   5. Tree(string)
   6. Tree(istream)

   7. Tree(Tree   &) // copy
   8. Tree(Tree<> &) // different <>

   9. Tree(top-level node, format | string [, version [, encoding]])
*/



// -----------------------------------------------------------------------------
// ctor(from,ossf)
// -----------------------------------------------------------------------------

// TREE = a existing source tree that arrives here as something
//        we'll use to construct a new tree
// M = metadata container class for the new tree
// C = children container class for the new tree
template<
   class TREE,
   template<class ...> class M = std::vector,
   template<class ...> class C = std::vector
>
bool ctor(
   const TREE &from, // arriving tree
   const std::ostringstream &ossf // the arriving tree printed to a string
) {
   // construct
   // The context here is such that we're testing several constructions
   // of a Tree<A,B> from a Tree<C,D>, where in some cases <A,B> == <C,D>,
   // in which case we're testing the copy constructor, and in other cases,
   // <A,B> != <C,D>, in which case we're testing that our various tree
   // species construct properly from other tree species.
   GNDStk::Tree<M,C> to(from);

   // print "to" to a string
   std::ostringstream osst;
   osst << to;

   // compare the two strings
   return osst.str() == ossf.str();
}



// -----------------------------------------------------------------------------
// ctor()
// -----------------------------------------------------------------------------

// Tests various tree constructors, with an argument of Tree<M,C>
// M = metadata container class
// C = children container class
template<
   template<class ...> class M = std::vector,
   template<class ...> class C = std::vector
>
bool ctor()
{
   // read a meaningful GNDS hierarchy into a "source" tree
   const GNDStk::Tree<M,C> from("n-069_Tm_170-covar.xml");

   // print the tree to a string, which we'll use for comparison
   std::ostringstream ossf;
   ossf << from;

   // construct from the source tree into other tree varieties,
   // and check that the contents of each such result are the same
   return
      ctor<decltype(from)                          >(from,ossf) &&
      ctor<decltype(from), std::deque              >(from,ossf) &&
      ctor<decltype(from), std::deque , std::deque >(from,ossf) &&
      ctor<decltype(from), std::deque , std::list  >(from,ossf) &&
      ctor<decltype(from), std::deque , std::vector>(from,ossf) &&
      ctor<decltype(from), std::list               >(from,ossf) &&
      ctor<decltype(from), std::list  , std::deque >(from,ossf) &&
      ctor<decltype(from), std::list  , std::list  >(from,ossf) &&
      ctor<decltype(from), std::list  , std::vector>(from,ossf) &&
      ctor<decltype(from), std::vector             >(from,ossf) &&
      ctor<decltype(from), std::vector, std::deque >(from,ossf) &&
      ctor<decltype(from), std::vector, std::list  >(from,ossf) &&
      ctor<decltype(from), std::vector, std::vector>(from,ossf)
      ;
}



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree constructors") {

   // 1. Tree()
   GIVEN("A default-constructed tree") {
      GNDStk::Tree<> t;
      WHEN("We check that it's empty") {
         REQUIRE(t.empty());
      }
   }

   // 2. Tree(Tree &&)
   GIVEN("One tree, read directly from a GNDS file") {
      const GNDStk::Tree<> one("n-026_Fe_056.xml");

      WHEN("We make a second tree, moved from a tree made from the same file") {
         const GNDStk::Tree<> two(GNDStk::Tree<>("n-026_Fe_056.xml"));

         // The two trees should be the same
         std::ostringstream oss1; oss1 << one;
         std::ostringstream oss2; oss2 << two;

         REQUIRE(oss1.str() == oss2.str());
      }
   }

   // 3. Tree(XML)
   GIVEN("A GNDStk::XML object, read from an XML file") {
      const GNDStk::XML x("n-026_Fe_056.xml");

      WHEN("We construct a tree from the GNDStk::XML object") {
         // We should get the same result for the tree constructed via the XML,
         // as we do for a tree that's read directly from the same file...
         std::ostringstream oss1; oss1 << GNDStk::Tree<>(x);
         std::ostringstream oss2; oss2 << GNDStk::Tree<>("n-026_Fe_056.xml");
         REQUIRE(oss1.str() == oss2.str());
      }
   }

   // 4. Tree(JSON)
   // fixme JSON work isn't complete yet, so we won't write this test yet

   // 5. Tree(string)
   // 6. Tree(istream)
   GIVEN("A tree(string) and a tree(istream)") {
      const GNDStk::Tree<> t1("n-026_Fe_056.xml");
      REQUIRE(!t1.empty());
      std::ifstream ifs("n-026_Fe_056.xml");
      const GNDStk::Tree<> t2(ifs);
      REQUIRE(!t2.empty());

      // Results should be the same
      std::ostringstream oss1; oss1 << t1;
      std::ostringstream oss2; oss2 << t2;
      REQUIRE(oss1.str() == oss2.str());
   }

   // 7. Tree(Tree   &) // copy
   // 8. Tree(Tree<> &) // different <>
   // Do basically the same thing we did in our tree assignment
   // test code, but construct where we'd otherwise assign.
   GIVEN("Various flavors of tree, each read from a GNDS .xml file") {
      REQUIRE((ctor<                        >()));
      REQUIRE((ctor<std::deque              >()));
      REQUIRE((ctor<std::deque , std::deque >()));
      REQUIRE((ctor<std::deque , std::list  >()));
      REQUIRE((ctor<std::deque , std::vector>()));
      REQUIRE((ctor<std::list               >()));
      REQUIRE((ctor<std::list  , std::deque >()));
      REQUIRE((ctor<std::list  , std::list  >()));
      REQUIRE((ctor<std::list  , std::vector>()));
      REQUIRE((ctor<std::vector             >()));
      REQUIRE((ctor<std::vector, std::deque >()));
      REQUIRE((ctor<std::vector, std::list  >()));
      REQUIRE((ctor<std::vector, std::vector>()));
   }

   // 9. Tree(top-level node, format | string [, version [, encoding]])
   GIVEN("Some trees created from scratch") {
      using namespace GNDStk;
      using namespace GNDStk::child;

      /*
      Cases:
         Tree(top-level node)
         Tree(top-level node, format)
         Tree(top-level node, format, version)
         Tree(top-level node, format, version, encoding)
         Tree(top-level node, string)
         Tree(top-level node, string, version)
         Tree(top-level node, string, version, encoding)
      */

      WHEN("We call: Tree(top-level node)") {
         Tree<> t(reactionSuite);
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "1.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: Tree(top-level node, format)") {
         Tree<> t(reactionSuite, format::json);
         REQUIRE(t.decl().name == "json");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "reactionSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: Tree(top-level node, format, version)") {
         Tree<> t(covarianceSuite, format::null, "2.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "2.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: Tree(top-level node, format, version, encoding)") {
         Tree<> t(covarianceSuite, format::xml, "3.0", "UTF-9");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "3.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-9");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "covarianceSuite");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: Tree(top-level node, string)") {
         Tree<> t(PoPs, "hdf5");
         REQUIRE(t.decl().name == "hdf5");
         REQUIRE(t.decl().metadata.size() == 0);
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);

      }

      WHEN("We call: Tree(top-level node, string, version)") {
         Tree<> t(PoPs, "tree", "4.0");
         REQUIRE(t.decl().name == "xml");
         REQUIRE(t.decl().metadata.size() == 2);
         REQUIRE(t.decl().meta("version") == "4.0");
         REQUIRE(t.decl().meta("encoding") == "UTF-8");
         REQUIRE(t.decl().children.size() == 1);
         REQUIRE(t.top().name == "PoPs");
         REQUIRE(t.top().metadata.size() == 0);
         REQUIRE(t.top().children.size() == 0);
      }

      WHEN("We call: Tree(top-level node, string, version, encoding)") {
         Tree<> t(thermalScattering, "xml", "5.0", "UTF-10");
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
