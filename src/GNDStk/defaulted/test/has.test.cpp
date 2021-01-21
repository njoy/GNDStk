
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s default-ness functions") {
   using njoy::GNDStk::defaulted;

   // ------------------------
   // With
   // defaulted(default)
   // ------------------------

   WHEN("We construct a defaulted(default value)") {
      const defaulted<int> d(123);
      THEN("has_value() and is_default() work as expected") {
         CHECK(d.has_value() == false);
         CHECK(d.is_default() == true);
      }
   }

   // ------------------------
   // With
   // defaulted(default,value)
   // ------------------------

   WHEN("We construct a defaulted(default value, value)") {
      const defaulted<int> d(123,456);
      THEN("has_value() and is_default() work as expected") {
         CHECK(d.has_value() == true);
         CHECK(d.is_default() == false);
      }
   }

   WHEN("We construct a defaulted(default value, value same as default)") {
      // Just to be sure no future code maintainer does something goofy
      // like changing the functions so they compare against the default...
      const defaulted<int> d(123,123);

      THEN("has_value() and is_default() work as expected") {
         // even though the value happens to equal the default:
         CHECK(d.has_value() == true);
         CHECK(d.is_default() == false);
      }
   }
}
