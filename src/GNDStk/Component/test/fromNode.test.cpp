
#include "catch.hpp"
#include "GNDStk.hpp"
#include "prototype.hpp"

using namespace njoy::GNDStk::core;
using namespace GNDStk::proto;


// -----------------------------------------------------------------------------
// DISCUSSION
// -----------------------------------------------------------------------------

/*
Consider a class that's derived from Component. When the class has a constructor
from Node, and uses (as it should) Component's facilities to help read the Node,
Component does the following:

   - Calls Component's fromNode() function to read known fields from the
     Node into the derived class object.

   - If the Node has block data, syncs certain fields in the BlockData (base
     of Component) class, with fields in the derived class. Then, converts a
     raw block data string into a vector of values.

   - Performs a sort() of derived-class vectors that are known to Component,
     and that have an index and/or a label.

   - Calls the derived class' construct(Node) function, if it has one.

The key point here: construction from Node does a fromNode(), plus some other
things that may or may not have any effect, depending on specific circumstances.

The tests in this file make use of a particular GNDS file with a reactionSuite.
We use a prototype ReactionSuite class (with content that's pared down from
what's in the full GNDS spec) that's derived from Component.

The reaction suite itself doesn't (directly) have any block data or sort-able
fields, and doesn't have a construct().

So, our first test (1) constructs from a Node, (2) uses fromNode() to read from
the same Node, and (3) verifies that (1) and (2) give exactly the same result.
They should do so, in this case, precisely because the other actions that
construction-from-Node can do, are not applicable here. (Those things ARE
in fact applicable for certain fields that are nested down in the ReactionSuite,
but (1) and (2) both end up running construction-from-Node for those things, so
we won't see the differences here, at the ReactionSuite level.)

Our second test constructs a Reactions, which has individual Reaction objects
inside of it. In the GNDS file we're using, those Reaction elements are not in
sorted order. So, in this case, (1) construction from Node, and (2) fromNode(),
give different results: the former sorts, the latter doesn't. After the results
from (2) are sorted, however, the two Reactions objects are the same.

Finally, our third test works with Values objects. Objects of this type have
block data. Construction from Node does a get(), which takes the original, raw
block data in the Node, and makes a vector (in this case vector<double>) from
it. fromNode() doesn't do that until, and unless, we ask for it by calling get()
directly. Values objects with only raw text write differently than those with
text that was processed into a vector. So, this test first ensures that the two
Values objects print differently. Then it does an explicit get() for the object
that used fromNode(), and ensures that the results are identical thereafter.
*/


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Component fromNode()") {
   GIVEN("A GNDS tree") {
      const Tree tree("n-001_H_002.xml");

      // ------------------------
      // Test #1: ReactionSuite
      // ------------------------

      WHEN("A ReactionSuite object is constructed from a Node") {
         // Construct a ReactionSuite from a Node. That this
         // is done correctly is tested elsewhere.
         const ReactionSuite suite1(tree(child::reactionSuite));

         THEN("A ReactionSuite made with fromNode(the same Node) "
               "is the same"
         ) {
            // Default-construct a ReactionSuite, then use fromNode
            // to make it from a Node.
            ReactionSuite suite2;
            suite2.fromNode(tree(child::reactionSuite));

            // Print both ReactionSuite objects
            std::ostringstream oss1;
            oss1 << suite1;
            std::ostringstream oss2;
            oss2 << suite2;

            // Ensure that they're equal
            CHECK(oss1.str() == oss2.str());
         } // THEN
      } // WHEN


      // ------------------------
      // Test #2: Reactions
      // ------------------------

      WHEN("A Reactions object is constructed from a Node") {
         // Construct from Node
         const Reactions reacts1(tree(child::reactionSuite,child::reactions));

         THEN("A Reactions made with fromNode(the same Node) may (and in "
               "this case IS) different until we sort it, because fromNode() "
               "doesn't sort the Reaction sub-elements"
         ) {
            // Use fromNode()
            Reactions reacts2;
            reacts2.fromNode(tree(child::reactionSuite,child::reactions));


            std::ostringstream oss1;
            oss1 << reacts1;
            std::ostringstream oss2;
            oss2 << reacts2;
            CHECK(oss1.str() != oss2.str()); // not equal (yet)

            // *** Sort ***; then they should be equal
            reacts2.sort();
            oss2.str("");
            oss2 << reacts2;
            CHECK(oss1.str() == oss2.str()); // equal

         } // THEN
      } // WHEN


      // ------------------------
      // Test #3: Values
      // ------------------------

      WHEN("A Values object is constructed from a Node") {
         const Node node = tree(
            child::reactionSuite,
            child::reactions,
            child::reaction, "n + H2",
            child::crossSection,
            child::XYs1d, "eval",
            --child::values
         );

         // Construct from Node
         const Values values1(node);

         THEN("A Values made with fromNode(the same Node) may (and in "
               "this case IS) different until we process it"
         ) {
            Values values2;
            values2.fromNode(node);

            std::ostringstream oss1;
            oss1 << values1;
            std::ostringstream oss2;
            oss2 << values2;
            CHECK(oss1.str() != oss2.str()); // not equal (yet)

            // *** Apply get() *** to transform the raw string of block data
            // values into a vector
            values2.get();
            oss2.str("");
            oss2 << values2;
            CHECK(oss1.str() == oss2.str()); // equal

         } // THEN
      } // WHEN

   } // GIVEN
} // SCENARIO
