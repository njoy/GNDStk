
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Scenario for DATATYPE == void
// -----------------------------------------------------------------------------

SCENARIO("BlockData<DATATYPE == void> fromNode()") {

   GIVEN("A Node with no \"block data\"") {
      WHEN("BlockData.fromNode(the node) is called") {
         THEN("The BlockData's raw string is \"\", as expected") {
            BlockData<true,void> b;
            b.string("This string should be replaced");
            CHECK(b.string() != "");

            Node node;
            node << "<foo></foo>";
            b.fromNode(node);
            CHECK(b.string() == "");
         }
      }
   }

   GIVEN("A Node with some \"block data\"") {
      WHEN("BlockData.fromNode(the node) is called") {
         THEN("The BlockData's raw string equals the text from the Node") {
            BlockData<true,void> b;
            b.string("This string should be replaced");
            CHECK(b.string() != "");

            Node node;

            node << "<foo>some plain character data</foo>";
            b.fromNode(node);
            CHECK(b.string() == "some plain character data");

            // it shouldn't matter, but leading spaces are preserved
            node << "<bar>   data with leading spaces</bar>";
            b.fromNode(node);
            CHECK(b.string() == "   data with leading spaces");

            // ditto for trailing spaces
            node << "<baz>data with trailing spaces     </baz>";
            b.fromNode(node);
            CHECK(b.string() == "data with trailing spaces     ");

            // ditto for both together
            node << "<boo>  data    </boo>";
            b.fromNode(node);
            CHECK(b.string() == "  data    ");
         }
      }
   }

} // SCENARIO


// -----------------------------------------------------------------------------
// Scenario for DATATYPE != void
// -----------------------------------------------------------------------------

SCENARIO("BlockData<DATATYPE != void> fromNode()") {

   GIVEN("A Node with no \"block data\"") {
      WHEN("BlockData.fromNode(the node) is called") {
         THEN("The BlockData's raw string is \"\", as expected") {
            BlockData<true,int> b;
            b.string("This string should be replaced");
            CHECK(b.string() != "");

            Node node;
            node << "<foo></foo>";
            b.fromNode(node);
            CHECK(b.string() == "");
         }
      }
   }

   GIVEN("A Node with some \"block data\"") {
      WHEN("BlockData.fromNode(the node) is called") {
         THEN("The BlockData's raw string equals the text from the Node") {
            BlockData<true,double> b;
            b.string("This string should be replaced");
            CHECK(b.string() != "");

            Node node;

            node << "<foo>some plain character data</foo>";
            b.fromNode(node);
            CHECK(b.string() == "some plain character data");

            // it shouldn't matter, but leading spaces are preserved
            node << "<bar>   data with leading spaces</bar>";
            b.fromNode(node);
            CHECK(b.string() == "   data with leading spaces");

            // ditto for trailing spaces
            node << "<baz>data with trailing spaces     </baz>";
            b.fromNode(node);
            CHECK(b.string() == "data with trailing spaces     ");

            // ditto for both together
            node << "<boo>  data    </boo>";
            b.fromNode(node);
            CHECK(b.string() == "  data    ");
         }
      }
   }

} // SCENARIO
