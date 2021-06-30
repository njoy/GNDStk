
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Component detail") {
   GIVEN("foo") {
      WHEN("bar") {
         THEN("baz") {
            CHECK(true);
         } // THEN
      } // WHEN
   } // GIVEN
} // SCENARIO
