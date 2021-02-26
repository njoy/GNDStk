
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing Defaulted<T>'s assignment operators") {
   using njoy::GNDStk::Defaulted;

   // ------------------------
   // general assignments
   // ------------------------

   GIVEN("A Defaulted object") {
      // = T
      THEN("Assignment object = T works as expected") {
         Defaulted<double> d(12.34);
         d = 56.78;
         CHECK(d == 56.78);
      }

      // = optional()
      THEN("Assignment object = optional() works as expected") {
         Defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::optional<double>(); // this sets the Defaulted...
         CHECK(d == 12.34); // ...back to its default
      }

      // = optional(value)
      THEN("Assignment object = optional(value) works as expected") {
         Defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::optional<double>(3.14);
         CHECK(d == 3.14);
      }

      // = nullopt
      THEN("Assignment object = nullopt works as expected") {
         Defaulted<double> d(12.34,56.78);
         CHECK(d == 56.78);
         d = std::nullopt; // this sets the Defaulted...
         CHECK(d == 12.34); // ...back to its default
      }
   }

   // ------------------------
   // copy assignment
   // ------------------------

   GIVEN("A Defaulted object") {
      // copy
      THEN("Copy assignment works as expected") {
         // case: "w/default = w/default"
         {
            Defaulted<double> a(1.2);
            const Defaulted<double> b(5.6);
            a = b;
            CHECK(a == 5.6);
            CHECK(a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            Defaulted<double> a(1.2);
            const Defaulted<double> b(5.6, 7.8);
            a = b;
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            Defaulted<double> a(1.2, 3.4);
            const Defaulted<double> b(5.6);
            a = b;
            CHECK(a == 5.6);
            CHECK(a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            Defaulted<double> a(1.2, 3.4);
            const Defaulted<double> b(5.6, 7.8);
            a = b;
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }
      }
   }

   // ------------------------
   // template "copy" assignment
   // ------------------------

   GIVEN("A Defaulted object") {
      THEN("Assignment Defaulted<X> = Defaulted<Y> works as expected") {
         // case: "w/default = w/default"
         {
            Defaulted<double> a(1.2);
            const Defaulted<int> b(56);
            a = b;
            CHECK(a == 56);
            CHECK(a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            Defaulted<double> a(1.2);
            const Defaulted<int> b(56, 78);
            a = b;
            CHECK(a == 78);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            Defaulted<double> a(1.2, 3.4);
            const Defaulted<int> b(56);
            a = b;
            CHECK(a == 56);
            CHECK(a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            Defaulted<double> a(1.2, 3.4);
            const Defaulted<int> b(56, 78);
            a = b;
            CHECK(a == 78);
            CHECK(!a.is_default());
         }
      }
   }

   // ------------------------
   // move assignment
   // ------------------------

   GIVEN("A Defaulted object") {
      THEN("Move assignment works as expected") {
         // case: "w/default = w/default"
         {
            Defaulted<double> a(1.2);
            a = Defaulted<double>(5.6);
            CHECK(a == 5.6);
            CHECK(a.is_default());
         }

         // case: "w/default = w/hard value"
         {
            Defaulted<double> a(1.2);
            a = Defaulted<double>(5.6, 7.8);
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }

         // case: "w/hard value = w/default"
         {
            Defaulted<double> a(1.2, 3.4);
            a = Defaulted<double>(5.6);
            CHECK(a == 5.6);
            CHECK(a.is_default());
         }

         // case: "w/hard value = w/hard value"
         {
            Defaulted<double> a(1.2, 3.4);
            a = Defaulted<double>(5.6, 7.8);
            CHECK(a == 7.8);
            CHECK(!a.is_default());
         }
      }
   }
}
