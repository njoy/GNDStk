
#include "catch.hpp"
#include "GNDStk.hpp"



// -----------------------------------------------------------------------------
// assign(rhs,ossr)
// -----------------------------------------------------------------------------

// TREE = a existing "right-hand-side" tree that arrives here as something
//        we'll use on the right-hand-side of an assignment to a new tree
// M = metadata container class for the new tree
// C = children container class for the new tree
template<
   class TREE,
   template<class ...> class M = std::vector,
   template<class ...> class C = std::vector
>
bool assign(
   const TREE &rhs, // arriving tree
   const std::ostringstream &ossr // the arriving tree printed to a string
) {
   // assignment: lhs = rhs
   GNDStk::Tree<M,C> lhs;
   lhs = rhs;

   // print lhs to a string
   std::ostringstream ossl;
   ossl << lhs;

   // compare the two strings
   return ossl.str() == ossr.str();
}



// -----------------------------------------------------------------------------
// assign()
// -----------------------------------------------------------------------------

// Tests various tree assignments, with a "right-hand-side" of Tree<M,C>
// M = metadata container class
// C = children container class
template<
   template<class ...> class M = std::vector,
   template<class ...> class C = std::vector
>
bool assign()
{
   // read a meaningful GNDS hierarchy into the tree that
   // we'll use as the right-hand-side of our assignments
   const GNDStk::Tree<M,C> rhs("n-008_O_016.xml");

   // print the tree to a string, which we'll use soon as
   // something to which we'll compare other trees
   std::ostringstream ossr;
   ossr << rhs;

   // assign the tree into other tree variants, and check
   // that the contents of each such result are the same
   return
      assign<decltype(rhs)                          >(rhs,ossr) &&
      assign<decltype(rhs), std::deque              >(rhs,ossr) &&
      assign<decltype(rhs), std::deque , std::deque >(rhs,ossr) &&
      assign<decltype(rhs), std::deque , std::list  >(rhs,ossr) &&
      assign<decltype(rhs), std::deque , std::vector>(rhs,ossr) &&
      assign<decltype(rhs), std::list               >(rhs,ossr) &&
      assign<decltype(rhs), std::list  , std::deque >(rhs,ossr) &&
      assign<decltype(rhs), std::list  , std::list  >(rhs,ossr) &&
      assign<decltype(rhs), std::list  , std::vector>(rhs,ossr) &&
      assign<decltype(rhs), std::vector             >(rhs,ossr) &&
      assign<decltype(rhs), std::vector, std::deque >(rhs,ossr) &&
      assign<decltype(rhs), std::vector, std::list  >(rhs,ossr) &&
      assign<decltype(rhs), std::vector, std::vector>(rhs,ossr)
      ;
}



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree assignments") {
   GIVEN("Various flavors of tree, each read from a GNDS .xml file") {

      // Extra parentheses are needed because there's
      // a comma, and REQUIRE is a macro :-/
      REQUIRE((assign<                        >()));
      REQUIRE((assign<std::deque              >()));
      REQUIRE((assign<std::deque , std::deque >()));
      REQUIRE((assign<std::deque , std::list  >()));
      REQUIRE((assign<std::deque , std::vector>()));
      REQUIRE((assign<std::list               >()));
      REQUIRE((assign<std::list  , std::deque >()));
      REQUIRE((assign<std::list  , std::list  >()));
      REQUIRE((assign<std::list  , std::vector>()));
      REQUIRE((assign<std::vector             >()));
      REQUIRE((assign<std::vector, std::deque >()));
      REQUIRE((assign<std::vector, std::list  >()));
      REQUIRE((assign<std::vector, std::vector>()));

   }
}
