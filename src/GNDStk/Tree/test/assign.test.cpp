
#include "catch.hpp"
#include "GNDStk.hpp"


// -----------------------------------------------------------------------------
// sets_equal_to()
// -----------------------------------------------------------------------------

template<
   class LTREE, // left-hand tree
   class RTREE // right-hand tree
>
bool sets_equal_to(LTREE &left, RTREE &&right)
{
   // Read something in for the right-hand tree
   right.read("n-008_O_016.xml");

   // WE WANT TO TEST IF THIS ASSIGNMENT WORKS CORRECTLY
   left = right;

   // Print the original tree
   std::ostringstream ossr;
   ossr << right;

   // Print the tree we assigned into
   std::ostringstream ossl;
   ossl << left;

   // If the assignment left = right worked correctly, then the original tree,
   // and the new one that we assigned into, should have printed identically
   return ossl.str() == ossr.str();
}


// -----------------------------------------------------------------------------
// assign()
// -----------------------------------------------------------------------------

// Tests various tree assignments of the form:
//    Tree<M,C> = Tree<various types>
// where:
//    M = metadata container class
//    C = children container class
template<
   template<class ...> class M = std::vector,
   template<class ...> class C = std::vector
>
void assign()
{
   using namespace std;
   GNDStk::Tree<M,C> left; // for a left = right assignment

   // Perform a left = right assignment for various "right" cases
   REQUIRE(sets_equal_to(left, GNDStk::Tree<              >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<deque         >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<deque , deque >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<deque , list  >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<deque , vector>()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<list          >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<list  , deque >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<list  , list  >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<list  , vector>()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<vector        >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<vector, deque >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<vector, list  >()));
   REQUIRE(sets_equal_to(left, GNDStk::Tree<vector, vector>()));
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree assignments") {
   using namespace std;

   GIVEN("Tree<              > = Tree<*>") { assign<              >(); }
   GIVEN("Tree<deque         > = Tree<*>") { assign<deque         >(); }
   GIVEN("Tree<deque , deque > = Tree<*>") { assign<deque , deque >(); }
   GIVEN("Tree<deque , list  > = Tree<*>") { assign<deque , list  >(); }
   GIVEN("Tree<deque , vector> = Tree<*>") { assign<deque , vector>(); }
   GIVEN("Tree<list          > = Tree<*>") { assign<list          >(); }
   GIVEN("Tree<list  , deque > = Tree<*>") { assign<list  , deque >(); }
   GIVEN("Tree<list  , list  > = Tree<*>") { assign<list  , list  >(); }
   GIVEN("Tree<list  , vector> = Tree<*>") { assign<list  , vector>(); }
   GIVEN("Tree<vector        > = Tree<*>") { assign<vector        >(); }
   GIVEN("Tree<vector, deque > = Tree<*>") { assign<vector, deque >(); }
   GIVEN("Tree<vector, list  > = Tree<*>") { assign<vector, list  >(); }
   GIVEN("Tree<vector, vector> = Tree<*>") { assign<vector, vector>(); }
}
