
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

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

   9. Tree(top-level node, file format | string [, version [, encoding]])
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
   template<class...> class M = std::vector,
   template<class...> class C = std::vector
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
   Tree<M,C> to(from);

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
   template<class...> class M = std::vector,
   template<class...> class C = std::vector
>
bool ctor()
{
   // read a meaningful GNDS hierarchy into a "source" tree
   const Tree<M,C> from("n-069_Tm_170-covar.xml");

   // print the Tree to a string, which we'll use for comparison
   std::ostringstream ossf;
   ossf << from;

   // construct from the source tree into other tree varieties,
   // and check that the contents of each such result are the same
   return
        ctor<decltype(from)                          >(from,ossf)
     && ctor<decltype(from), std::deque              >(from,ossf)
     && ctor<decltype(from), std::deque , std::deque >(from,ossf)
     && ctor<decltype(from), std::deque , std::list  >(from,ossf)
     && ctor<decltype(from), std::deque , std::vector>(from,ossf)
     && ctor<decltype(from), std::list               >(from,ossf)
     && ctor<decltype(from), std::list  , std::deque >(from,ossf)
     && ctor<decltype(from), std::list  , std::list  >(from,ossf)
     && ctor<decltype(from), std::list  , std::vector>(from,ossf)
     && ctor<decltype(from), std::vector             >(from,ossf)
     && ctor<decltype(from), std::vector, std::deque >(from,ossf)
     && ctor<decltype(from), std::vector, std::list  >(from,ossf)
     && ctor<decltype(from), std::vector, std::vector>(from,ossf)
   ;
}



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree constructors") {

   // 1. Tree()
   GIVEN("A default-constructed tree") {
      Tree<> t;
      WHEN("We check that it's empty") {
         CHECK(t.empty());
      }
   }

   // 2. Tree(Tree &&)
   GIVEN("One tree, read directly from a GNDS file") {
      const Tree<> one("n-026_Fe_056.xml");

      WHEN("We make a second tree, moved from a tree made from the same file") {
         const Tree<> two(Tree<>("n-026_Fe_056.xml"));

         // The two trees should be the same
         std::ostringstream oss1; oss1 << one;
         std::ostringstream oss2; oss2 << two;

         CHECK(oss1.str() == oss2.str());
      }
   }

   // 3. Tree(XML)
   GIVEN("An XML object, read from an XML file") {
      const XML x("n-026_Fe_056.xml");

      WHEN("We construct a tree from the XML object") {
         // We should get the same result for the tree constructed via the
         // XML as we do for a Tree that's read directly from the same file
         std::ostringstream oss1; oss1 << Tree<>(x);
         std::ostringstream oss2; oss2 << Tree<>("n-026_Fe_056.xml");
         CHECK(oss1.str() == oss2.str());
      }
   }

   // 4. Tree(JSON)
   GIVEN("A JSON object, read from a JSON file") {
      const JSON j("n-069_Tm_170-covar.json");

      WHEN("We construct a tree from the JSON object") {
         // We should get the same result for the tree constructed via the
         // JSON as we do for a Tree that's read directly from the same file
         std::ostringstream oss1; oss1 << Tree<>(j);
         std::ostringstream oss2; oss2 << Tree<>("n-069_Tm_170-covar.json");
         CHECK(oss1.str() == oss2.str());
      }
   }

   // 5. Tree(string)
   // 6. Tree(istream)
   GIVEN("A tree(string) and a tree(istream)") {
      const Tree<> t1("n-026_Fe_056.xml");
      CHECK(!t1.empty());
      std::ifstream ifs("n-026_Fe_056.xml");
      const Tree<> t2(ifs);
      CHECK(!t2.empty());

      // Results should be the same
      std::ostringstream oss1; oss1 << t1;
      std::ostringstream oss2; oss2 << t2;
      CHECK(oss1.str() == oss2.str());
   }

   // 7. Tree(Tree   &) // copy
   // 8. Tree(Tree<> &) // different <>
   // Do basically the same thing we did in our tree assignment
   // test code, but construct where we'd otherwise assign.
   GIVEN("Various flavors of tree, each read from a GNDS .xml file") {
      CHECK((ctor<                        >()));
      CHECK((ctor<std::deque              >()));
      CHECK((ctor<std::deque , std::deque >()));
      CHECK((ctor<std::deque , std::list  >()));
      CHECK((ctor<std::deque , std::vector>()));
      CHECK((ctor<std::list               >()));
      CHECK((ctor<std::list  , std::deque >()));
      CHECK((ctor<std::list  , std::list  >()));
      CHECK((ctor<std::list  , std::vector>()));
      CHECK((ctor<std::vector             >()));
      CHECK((ctor<std::vector, std::deque >()));
      CHECK((ctor<std::vector, std::list  >()));
      CHECK((ctor<std::vector, std::vector>()));
   }

   // 9. Tree(top-level node, file format | string [, version [, encoding]])
   GIVEN("Some trees created from scratch") {
      using namespace misc;

      /*
      Cases:
         Tree(top-level node)
         Tree(top-level node, file format)
         Tree(top-level node, file format, version)
         Tree(top-level node, file format, version, encoding)
         Tree(top-level node, string)
         Tree(top-level node, string, version)
         Tree(top-level node, string, version, encoding)
      */

      WHEN("We call: Tree(top-level node)") {
         Tree<> t(reactionSuite);
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "xml");
            CHECK(t.decl().metadata.size() == 2);
            CHECK(t.decl().meta("version") == "1.0");
            CHECK(t.decl().meta("encoding") == "UTF-8");
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "reactionSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, file format)") {
         Tree<> t(reactionSuite, FileType::json);
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "json");
            CHECK(t.decl().metadata.size() == 0);
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "reactionSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, file format, version)") {
         Tree<> t(covarianceSuite, FileType::null, "2.0");
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "xml");
            CHECK(t.decl().metadata.size() == 2);
            CHECK(t.decl().meta("version") == "2.0");
            CHECK(t.decl().meta("encoding") == "UTF-8");
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "covarianceSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, file format, version, encoding)") {
         Tree<> t(covarianceSuite, FileType::xml, "3.0", "UTF-9");
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "xml");
            CHECK(t.decl().metadata.size() == 2);
            CHECK(t.decl().meta("version") == "3.0");
            CHECK(t.decl().meta("encoding") == "UTF-9");
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "covarianceSuite");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, string)") {
         Tree<> t(PoPs, "hdf5");
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "hdf5");
            CHECK(t.decl().metadata.size() == 0);
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "PoPs");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, string, version)") {
         Tree<> t(PoPs, "tree", "4.0");
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "xml");
            CHECK(t.decl().metadata.size() == 2);
            CHECK(t.decl().meta("version") == "4.0");
            CHECK(t.decl().meta("encoding") == "UTF-8");
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "PoPs");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }

      WHEN("We call: Tree(top-level node, string, version, encoding)") {
         Tree<> t(thermalScattering, "xml", "5.0", "UTF-10");
         THEN("We can make various decl() and top() queries") {
            CHECK(t.decl().name == "xml");
            CHECK(t.decl().metadata.size() == 2);
            CHECK(t.decl().meta("version") == "5.0");
            CHECK(t.decl().meta("encoding") == "UTF-10");
            CHECK(t.decl().children.size() == 0);
            CHECK(t.top().name == "thermalScattering");
            CHECK(t.top().metadata.size() == 0);
            CHECK(t.top().children.size() == 0);
         }
      }
   }
}
