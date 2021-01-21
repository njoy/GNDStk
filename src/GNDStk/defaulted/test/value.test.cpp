
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s value retrieval functions") {
   using njoy::GNDStk::defaulted;

   // ------------------------
   // With
   // defaulted(default)
   // ------------------------

   WHEN("We construct a defaulted(default value)") {
      const defaulted<int> d(123);
      const defaulted<std::vector<double>> v({ 1.2, 3.4, 5.6, 7.8 });

      // value()
      THEN("value() works as expected") {
         CHECK(d.value() == 123);
      }

      // *
      THEN("operator* works as expected") {
         CHECK(*d == 123);
      }

      // ->
      THEN("operator-> works as expected") {
         CHECK(v->size() == 4);
      }

      // value()
      THEN("conversion to T works as expected") {
         CHECK(int(d) == 123);
         CHECK(std::vector<double>(v) ==
               std::vector<double>({1.2,3.4,5.6,7.8}));
      }
   }

   // ------------------------
   // With
   // defaulted(default,value)
   // ------------------------

   WHEN("We construct a defaulted(default value,value)") {
      const defaulted<int> d(123,456);
      const defaulted<std::vector<double>> v({1.2,3.4 }, {5.6,7.8});

      // value()
      THEN("value() works as expected") {
         CHECK(d.value() == 456);
         // value() returns a reference, so the following compiles...
         (void)&d.value();
      }

      // *
      THEN("operator* works as expected") {
         CHECK(*d == 456);
         // operator* returns a reference, so the following compiles...
         (void)&(*d);
      }

      // ->
      THEN("operator-> works as expected") {
         CHECK(v->size() == 2);
      }

      // value()
      THEN("conversion to T works as expected") {
         CHECK(int(d) == 456);
         CHECK(std::vector<double>(v) ==
               std::vector<double>({5.6,7.8}));
      }
   }
}
