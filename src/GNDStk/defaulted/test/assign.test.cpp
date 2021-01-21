
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s assignment operators") {
   using njoy::GNDStk::defaulted;

   // ------------------------
   // general assignments
   // ------------------------

   GIVEN("A defaulted object") {
      // = T
      THEN("Assignment object = T works as expected") {
         defaulted<double> d(12.34);
         d = 56.78;
         CHECK(d == 56.78);
      }

      // = optional()
      THEN("Assignment object = optional() works as expected") {
         defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::optional<double>(); // this sets the defaulted...
         CHECK(d == 12.34); // ...back to its default
      }

      // = optional(value)
      THEN("Assignment object = optional(value) works as expected") {
         defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::optional<double>(3.14);
         CHECK(d == 3.14);
      }

      // = nullopt
      THEN("Assignment object = nullopt works as expected") {
         defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::nullopt; // this sets the defaulted...
         CHECK(d == 12.34); // ...back to its default
      }
   }

   // ------------------------
   // copy assignment
   // ------------------------

   GIVEN("A defaulted object") {
      // copy
      THEN("Copy assignment works as expected") {
         // case: "w/default = w/default"
         {
            defaulted<double> a(1.2);
            defaulted<double> b(5.6);
            a = b;
            CHECK(a == 5.6);
            CHECK(!a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            defaulted<double> a(1.2);
            defaulted<double> b(5.6, 7.8);
            a = b;
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            defaulted<double> a(1.2, 3.4);
            defaulted<double> b(5.6);
            a = b;
            CHECK(a == 5.6);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            defaulted<double> a(1.2, 3.4);
            defaulted<double> b(5.6, 7.8);
            a = b;
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }
      }
   }

   // ------------------------
   // template "copy" assignment
   // ------------------------

   GIVEN("A defaulted object") {
      THEN("Assignment defaulted<X> = defaulted<Y> works as expected") {
         // case: "w/default = w/default"
         {
            defaulted<double> a(1.2);
            defaulted<int> b(56);
            a = b;
            CHECK(a == 56);
            CHECK(!a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            defaulted<double> a(1.2);
            defaulted<int> b(56, 78);
            a = b;
            CHECK(a == 78);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            defaulted<double> a(1.2, 3.4);
            defaulted<int> b(56);
            a = b;
            CHECK(a == 56);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            defaulted<double> a(1.2, 3.4);
            defaulted<int> b(56, 78);
            a = b;
            CHECK(a == 78);
            CHECK(!a.is_default());
         }
      }
   }

   // ------------------------
   // move assignment
   // ------------------------

   GIVEN("A defaulted object") {
      THEN("Move assignment works as expected") {
         // case: "w/default = w/default"
         {
            defaulted<double> a(1.2);
            a = defaulted<double>(5.6);
            CHECK(a == 5.6);
            CHECK(!a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            defaulted<double> a(1.2);
            a = defaulted<double>(5.6, 7.8);
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            defaulted<double> a(1.2, 3.4);
            a = defaulted<double>(5.6);
            CHECK(a == 5.6);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            defaulted<double> a(1.2, 3.4);
            a = defaulted<double>(5.6, 7.8);
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }
      }
   }
}
