
#include "catch.hpp"
#include "GNDStk.hpp"

/*
What we'll need to test...

   1. Tree()
   2. Tree(Tree &&)

   3. Tree(xml)
   4. Tree(json)

   5. Tree(string)
   6. Tree(istream)

   7. Tree(Tree   &) // copy
   8. Tree(Tree<> &) // different <>
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
   // The context here is such that we're testing a whole bunch of constructions
   // of a Tree<A,B> from a Tree<C,D>, where in some cases <A,B> == <C,D>,
   // in which case we're testing the copy constructor, and in other cases,
   // <A,B> != <C,D>, in which case we're testing that our various tree species
   // construct properly from other tree species.
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
   // read a meaningful GNDS hierarchy into the tree we'll use as a source
   const GNDStk::Tree<M,C> from("n-008_O_016.xml");

   // print the tree to a string, which we'll soon use for comparison
   std::ostringstream ossf;
   ossf << from;

   // construct from the tree into other tree variants, and check
   // that the contents of each such result are the same
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

   // 3. Tree(xml)
   GIVEN("A GNDStk::xml object, read from an XML file") {
      const GNDStk::xml x("n-026_Fe_056.xml");

      WHEN("We construct a tree from the GNDStk::xml object") {
         // We should get the same result for the tree constructed via the XML,
         // as we do for a tree that's read directly from the same file...
         std::ostringstream oss1; oss1 << GNDStk::Tree<>(x);
         std::ostringstream oss2; oss2 << GNDStk::Tree<>("n-026_Fe_056.xml");
         REQUIRE(oss1.str() == oss2.str());
      }
   }

   // 4. Tree(json)
   // fixme Json work isn't complete yet, so we won't write this test yet

   // 5. Tree(string)
   // 6. Tree(istream)
   GIVEN("A tree(string) and a tree(istream)") {
      const GNDStk::Tree<> t1("n-026_Fe_056.xml");
      std::ifstream ifs("n-026_Fe_056.xml");
      const GNDStk::Tree<> t2(ifs);

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
}
