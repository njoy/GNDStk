
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing Defaulted<T>'s default-ness functions") {
   using njoy::GNDStk::Defaulted;

   // ------------------------
   // With
   // Defaulted(default)
   // ------------------------

   WHEN("We construct a Defaulted(default value)") {
      const Defaulted<int> d(123);
      THEN("has_value() and is_default() work as expected") {
         CHECK(!d.has_value());
         CHECK(d.is_default());
      }
   }

   // ------------------------
   // With
   // Defaulted(default,value)
   // ------------------------

   WHEN("We construct a Defaulted(default value, value)") {
      const Defaulted<int> d(123,456);
      THEN("has_value() and is_default() work as expected") {
         CHECK(d.has_value());
         CHECK(!d.is_default());
      }
   }

   WHEN("We construct a Defaulted(default value, value same as default)") {
      // Just to be sure no future code maintainer does something goofy
      // like changing the functions so they compare against the default...
      const Defaulted<int> d(123,123);

      THEN("has_value() and is_default() work as expected") {
         // even though the value happens to equal the default:
         CHECK(d.has_value());
         CHECK(!d.is_default());
      }
   }
}
