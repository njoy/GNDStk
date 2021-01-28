
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing Defaulted<T>'s constructors") {
   using njoy::GNDStk::Defaulted;

   // ------------------------
   // general constructors
   // ------------------------

   // Defaulted(default)
   WHEN("We construct a Defaulted(default value)") {
      const Defaulted<int> d(123);
      THEN("Its value is the provided default") {
         CHECK(d == 123);
      }
   }

   // Defaulted(default, value)
   WHEN("We construct a Defaulted(default value,value)") {
      const Defaulted<int> d(123,456);
      THEN("Its value is the provided value, not the provided default") {
         CHECK(d == 456);
         CHECK(d != 123);
      }
   }

   // Defaulted(default, optional)
   WHEN("We construct a Defaulted(default value,optional)") {
      THEN("It works as expected when the optional "
           "is default constructed") {
         const Defaulted<int> d(123,std::optional<int>());
         CHECK(d == 123);
      }

      THEN("It works as expected when the optional "
           "has a value") {
         const Defaulted<int> d(123,std::optional<int>(456));
         CHECK(d == 456);
      }

      THEN("It works as expected when the optional "
           "is constructed with nullopt") {
         const Defaulted<int> d(123,std::optional<int>(std::nullopt));
         CHECK(d == 123);
      }
   }

   // Defaulted(default, nullopt)
   WHEN("We construct a Defaulted(default value,nullopt)") {
      const Defaulted<int> d(123,std::nullopt);
      THEN("Its value is the provided default") {
         CHECK(d == 123);
      }
   }

   // ------------------------
   // standard constructors
   // ------------------------

   // copy
   WHEN("We copy construct a Defaulted") {
      THEN("It works as expected when the copied-from == its default") {
         const Defaulted<int> d1(123);
         const Defaulted<int> d2 = d1;
         CHECK(d2 == 123);
      }

      THEN("It works as expected when the copied-from != its default") {
         const Defaulted<int> d1(123,456);
         const Defaulted<int> d2 = d1;
         CHECK(d2 == 456);
      }
   }

   // template "copy"
   WHEN("We construct a Defaulted<X> from a Defaulted<Y>") {
      THEN("It works as expected when the copied-from == its default") {
         const Defaulted<int> d1(123);
         const Defaulted<long> d2 = d1;
         CHECK(d2 == 123);
      }

      THEN("It works as expected when the copied-from != its default") {
         const Defaulted<int> d1(123,456);
         const Defaulted<long> d2 = d1;
         CHECK(d2 == 456);
      }
   }

   // move
   WHEN("We move construct a Defaulted") {
      THEN("It works as expected when the moved-from == its default") {
         const Defaulted<int> d(std::move(Defaulted<int>(123)));
         CHECK(d == 123);
      }

      THEN("It works as expected when the moved-from != its default") {
         const Defaulted<int> d(std::move(Defaulted<int>(123,456)));
         CHECK(d == 456);
      }
   }
}
