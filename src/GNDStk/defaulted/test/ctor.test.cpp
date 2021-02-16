
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s constructors") {
   using njoy::GNDStk::defaulted;

   // ------------------------
   // general constructors
   // ------------------------

   // defaulted(default)
   WHEN("We construct a defaulted(default value)") {
      const defaulted<int> d(123);
      THEN("Its value is the provided default") {
         CHECK(d == 123);
      }
   }

   // defaulted(default, value)
   WHEN("We construct a defaulted(default value,value)") {
      const defaulted<int> d(123,456);
      THEN("Its value is the provided value, not the provided default") {
         CHECK(d == 456);
         CHECK(d != 123);
      }
   }

   // defaulted(default, optional)
   WHEN("We construct a defaulted(default value,optional)") {
      THEN("It works as expected when the optional "
           "is default constructed") {
         const defaulted<int> d(123,std::optional<int>());
         CHECK(d == 123);
      }

      THEN("It works as expected when the optional "
           "has a value") {
         const defaulted<int> d(123,std::optional<int>(456));
         CHECK(d == 456);
      }

      THEN("It works as expected when the optional "
           "is constructed with nullopt") {
         const defaulted<int> d(123,std::optional<int>(std::nullopt));
         CHECK(d == 123);
      }
   }

   // defaulted(default, nullopt)
   WHEN("We construct a defaulted(default value,nullopt)") {
      const defaulted<int> d(123,std::nullopt);
      THEN("Its value is the provided default") {
         CHECK(d == 123);
      }
   }

   // ------------------------
   // standard constructors
   // ------------------------

   // copy
   WHEN("We copy construct a defaulted") {
      THEN("It works as expected when the copied-from == its default") {
         const defaulted<int> d1(123);
         const defaulted<int> d2 = d1;
         CHECK(d2 == 123);
      }

      THEN("It works as expected when the copied-from != its default") {
         const defaulted<int> d1(123,456);
         const defaulted<int> d2 = d1;
         CHECK(d2 == 456);
      }
   }

   // template "copy"
   WHEN("We construct a defaulted<X> from a defaulted<Y>") {
      THEN("It works as expected when the copied-from == its default") {
         const defaulted<int> d1(123);
         const defaulted<long> d2 = d1;
         CHECK(d2 == 123);
      }

      THEN("It works as expected when the copied-from != its default") {
         const defaulted<int> d1(123,456);
         const defaulted<long> d2 = d1;
         CHECK(d2 == 456);
      }
   }

   // move
   WHEN("We move construct a defaulted") {
      THEN("It works as expected when the moved-from == its default") {
         const defaulted<int> d(std::move(defaulted<int>(123)));
         CHECK(d == 123);
      }

      THEN("It works as expected when the moved-from != its default") {
         const defaulted<int> d(std::move(defaulted<int>(123,456)));
         CHECK(d == 456);
      }
   }
}
