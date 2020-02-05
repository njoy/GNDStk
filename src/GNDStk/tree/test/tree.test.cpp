
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Tree (templated), tree (not templated)") {

   // Here, we're just illustrating various ways to define a Tree or tree
   // object, with regards to template parameters. Below, testing .root
   // against nullptr is just for the sake of doing *something* with our
   // various trees. Of course, it means merely that a default-constructed
   // tree, of any species, has nothing in it.

   // Tree (upper-case T): takes 0, 1, or 2 template parameters
   GIVEN("A Tree<default,default>") {
      gnds::Tree<> tree;
      REQUIRE(tree.root == nullptr);
   }

   // tree (lower-case t): shorthand alias for Tree<>
   GIVEN("A tree") {
      gnds::tree tree;
      REQUIRE(tree.root == nullptr);
   }

   // Each of Tree's two template parameters can be any of three particular C++
   // sequence containers: {deque,list,vector}. We don't allow for the other two
   // sequence containers, {array,forward_list}, because each of those lacks one
   // or more features we need. In the future we may relax this restriction, or
   // even allow for other than *sequence* containers; for example, std::map.
   // Note also that users could plug in their own suitably-defined container;
   // we'll clarify the meaning of "suitably-defined" at some point.
   GIVEN("A Tree<various,various>") {
      using namespace std;

      { gnds::Tree<deque        > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<deque ,deque > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<deque ,list  > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<deque ,vector> tree; REQUIRE(tree.root == nullptr); }

      { gnds::Tree<list         > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<list  ,deque > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<list  ,list  > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<list  ,vector> tree; REQUIRE(tree.root == nullptr); }

      { gnds::Tree<vector       > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<vector,deque > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<vector,list  > tree; REQUIRE(tree.root == nullptr); }
      { gnds::Tree<vector,vector> tree; REQUIRE(tree.root == nullptr); }
   }

}
