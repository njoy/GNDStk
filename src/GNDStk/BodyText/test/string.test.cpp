
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("BodyText string()") {
   GIVEN("A default-constructed BodyText<true,void> object") {

      // Default value of raw string is as expected
      WHEN("We examine the raw string") {
         THEN("It is as expected") {
            BodyText<true,void> b;
            CHECK(b.string() == "");
         }
      }

      // Raw string setter/getter works
      WHEN("We set the raw string") {
         THEN("It has the correct value, and vector size() == 0 too") {
            BodyText<true,void> b;

            // to ensure it clears below...
            b = std::vector<int>(10);
            CHECK(b.size() == 10);

            b.string("0 1 22 333 4444");
            CHECK(b.string() == "0 1 22 333 4444");
            // Setting the string makes the vector inactive,
            // and clears the vector for good measure...
            CHECK(b.size() == 0);
         }
      }

      // Test in conjunction with length, start, and valueType
      WHEN("We set string, length, start, and valueType together") {
         THEN("All values check out") {
            BodyText<true,void> b;
            b.string("3 4 5 6").length(10).start(2).valueType("Integer32");

            CHECK(b.length() == 10);
            CHECK(b.start() == 2);
            CHECK(b.valueType() == "Integer32");
            CHECK(b.string() == "3 4 5 6");
         }
      }

   }
}
