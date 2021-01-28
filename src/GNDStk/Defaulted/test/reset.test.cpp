
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing Defaulted<T>'s reset() and clear()") {
   using njoy::GNDStk::Defaulted;

   // These tests might be overdoing it...

   // ------------------------
   // With
   // Defaulted(default)
   // ------------------------

   WHEN("We construct a Defaulted(default value)") {
      // reset
      THEN("reset() works as expected") {
         Defaulted<int> d(123);
         CHECK(d == 123);
         d.reset();
         CHECK(d == 123);
         d = 456;
         CHECK(d == 456);
         d.reset();
         CHECK(d == 123);
      }

      // clear
      THEN("clear() works as expected") {
         Defaulted<int> d(123);
         CHECK(d == 123);
         d.clear();
         CHECK(d == 123);
         d = 456;
         CHECK(d == 456);
         d.clear();
         CHECK(d == 123);
      }
   }

   // ------------------------
   // With
   // Defaulted(default,value)
   // ------------------------

   WHEN("We construct a Defaulted(default value, value)") {
      // reset
      THEN("reset() works as expected") {
         Defaulted<int> d(123,789);
         CHECK(d == 789);
         d.reset();
         CHECK(d == 123);
         d = 456;
         CHECK(d == 456);
         d.reset();
         CHECK(d == 123);
      }

      // clear
      THEN("clear() works as expected") {
         Defaulted<int> d(123,789);
         CHECK(d == 789);
         d.clear();
         CHECK(d == 123);
         d = 456;
         CHECK(d == 456);
         d.clear();
         CHECK(d == 123);
      }
   }
}
