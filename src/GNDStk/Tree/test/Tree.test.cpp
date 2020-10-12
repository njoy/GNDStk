
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Tree (templated), tree (not templated)") {

   // Here, we're just illustrating various ways to define a Tree or tree
   // object, with regards to template parameters.

   // Tree (upper-case T): takes 0, 1, or 2 template parameters
   GIVEN("A Tree<default,default>") {
      Tree<> tree;
      CHECK(tree.empty());
   }

   // tree (lower-case t): shorthand alias for Tree<>
   GIVEN("A tree") {
      tree tree;
      CHECK(tree.empty());
   }

   // Each of Tree's two template parameters can be any of three particular
   // sequence containers: {deque,list,vector}. We don't allow for the other
   // sequence containers, {array,forward_list}, because each of those lacks
   // one or more features we need. In the future we may relax this restriction,
   // or even allow for other than sequence containers; for example, std::map.
   // Note also that users could plug in their own suitably-defined container.
   // We'll clarify the meaning of "suitably-defined" at some point.
   GIVEN("A Tree<various,various>") {
      using namespace std;

      { Tree<deque        > tree; CHECK(tree.empty()); }
      { Tree<deque ,deque > tree; CHECK(tree.empty()); }
      { Tree<deque ,list  > tree; CHECK(tree.empty()); }
      { Tree<deque ,vector> tree; CHECK(tree.empty()); }

      { Tree<list         > tree; CHECK(tree.empty()); }
      { Tree<list  ,deque > tree; CHECK(tree.empty()); }
      { Tree<list  ,list  > tree; CHECK(tree.empty()); }
      { Tree<list  ,vector> tree; CHECK(tree.empty()); }

      { Tree<vector       > tree; CHECK(tree.empty()); }
      { Tree<vector,deque > tree; CHECK(tree.empty()); }
      { Tree<vector,list  > tree; CHECK(tree.empty()); }
      { Tree<vector,vector> tree; CHECK(tree.empty()); }
   }

}
