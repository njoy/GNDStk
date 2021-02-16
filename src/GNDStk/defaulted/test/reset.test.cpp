
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s reset() and clear()") {
   using njoy::GNDStk::defaulted;

   // These tests might be overdoing it...

   // ------------------------
   // With
   // defaulted(default)
   // ------------------------

   WHEN("We construct a defaulted(default value)") {
      // reset
      THEN("reset() works as expected") {
         defaulted<int> d(123);
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
         defaulted<int> d(123);
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
   // defaulted(default,value)
   // ------------------------

   WHEN("We construct a defaulted(default value, value)") {
      // reset
      THEN("reset() works as expected") {
         defaulted<int> d(123,789);
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
         defaulted<int> d(123,789);
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
