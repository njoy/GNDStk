
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk Tree (templated), tree (not templated)") {

   // Here, we're just illustrating various ways to define a Tree or tree
   // object, with regards to template parameters.

   // Tree (upper-case T): takes 0, 1, or 2 template parameters
   GIVEN("A Tree<default,default>") {
      GNDStk::Tree<> tree;
      REQUIRE(tree.empty());
   }

   // tree (lower-case t): shorthand alias for Tree<>
   GIVEN("A tree") {
      GNDStk::tree tree;
      REQUIRE(tree.empty());
   }

   // Each of Tree's two template parameters can be any of three particular C++
   // sequence containers: {deque,list,vector}. We don't allow for the other two
   // sequence containers, {array,forward_list}, because each of those lacks one
   // or more features we need. In the future we may relax this restriction, or
   // even allow for other than *sequence* containers; for example, std::map.
   // Note also that users could plug in their own suitably-defined container.
   // We'll of course clarify the meaning of "suitably-defined" at some point.
   GIVEN("A Tree<various,various>") {
      using namespace std;

      { GNDStk::Tree<deque        > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<deque ,deque > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<deque ,list  > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<deque ,vector> tree; REQUIRE(tree.empty()); }

      { GNDStk::Tree<list         > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<list  ,deque > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<list  ,list  > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<list  ,vector> tree; REQUIRE(tree.empty()); }

      { GNDStk::Tree<vector       > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<vector,deque > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<vector,list  > tree; REQUIRE(tree.empty()); }
      { GNDStk::Tree<vector,vector> tree; REQUIRE(tree.empty()); }
   }

}
