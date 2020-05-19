
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


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
   Tree<M,C> left; // for a left = right assignment

   // Perform a left = right assignment for various "right" cases
   CHECK(sets_equal_to(left, Tree<              >()));
   CHECK(sets_equal_to(left, Tree<deque         >()));
   CHECK(sets_equal_to(left, Tree<deque , deque >()));
   CHECK(sets_equal_to(left, Tree<deque , list  >()));
   CHECK(sets_equal_to(left, Tree<deque , vector>()));
   CHECK(sets_equal_to(left, Tree<list          >()));
   CHECK(sets_equal_to(left, Tree<list  , deque >()));
   CHECK(sets_equal_to(left, Tree<list  , list  >()));
   CHECK(sets_equal_to(left, Tree<list  , vector>()));
   CHECK(sets_equal_to(left, Tree<vector        >()));
   CHECK(sets_equal_to(left, Tree<vector, deque >()));
   CHECK(sets_equal_to(left, Tree<vector, list  >()));
   CHECK(sets_equal_to(left, Tree<vector, vector>()));

   // Test move assignment
   left = Tree<M,C>("n-069_Tm_170-covar.xml");
   std::ostringstream ossl; ossl << left;
   Tree<M,C> right("n-069_Tm_170-covar.xml");
   std::ostringstream ossr; ossr << right;
   CHECK(ossl.str() == ossr.str());
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
