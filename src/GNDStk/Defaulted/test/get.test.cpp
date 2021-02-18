
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing Defaulted<T>'s get_*() functions") {
   using njoy::GNDStk::Defaulted;

   // ------------------------
   // With
   // Defaulted(default)
   // ------------------------

   WHEN("We construct a Defaulted(default value)") {
      const Defaulted<int> d(123);

      THEN("get_default() and get_optional() work as expected") {
         CHECK(d.get_default() == 123);
         CHECK(d.get_optional() == std::optional<int>{});
         CHECK(d.get_optional() == std::nullopt);

         // get_default() and get_optional() return references,
         // so these compile...
         (void)&d.get_default();
         (void)&d.get_optional();
      }
   }

   // ------------------------
   // With
   // Defaulted(default,value)
   // ------------------------

   WHEN("We construct a Defaulted(default value, value)") {
      const Defaulted<int> d(123,456);

      THEN("get_default() and get_optional() work as expected") {
         CHECK(d.get_default() == 123);
         CHECK(d.get_optional() == std::optional<int>{456});
      }
   }
}
