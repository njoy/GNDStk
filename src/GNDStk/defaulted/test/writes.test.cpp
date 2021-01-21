
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing defaulted<T>'s writes() and quiet()") {
   using njoy::GNDStk::defaulted;

   // These tests might be overdoing it...

   // ------------------------
   // With
   // defaulted(default)
   // ------------------------

   WHEN("We construct a defaulted(default value)") {
      const defaulted<int,true > T(123);
      const defaulted<int,false> F(456);

      // writes
      THEN("writes() works as expected") {
         CHECK(T.writes().value() == 123);
         // WRITES remains true...
         CHECK((std::is_same<const decltype(T.writes()),decltype(T)>::value
                == true));

         CHECK(F.writes().value() == 456);
         // WRITES becomes true...
         CHECK((std::is_same<const decltype(F.writes()),decltype(T)>::value
                == true));
      }

      // quiet
      THEN("quiet() works as expected") {
         CHECK(T.quiet().value() == 123);
         // WRITES becomes false...
         CHECK((std::is_same<const decltype(T.quiet()),decltype(F)>::value
                == true));

         CHECK(F.quiet().value() == 456);
         // WRITES remains false...
         CHECK((std::is_same<const decltype(F.quiet()),decltype(F)>::value
                == true));
      }
   }

   // ------------------------
   // With
   // defaulted(default,value)
   // ------------------------

   WHEN("We construct a defaulted(default value, value)") {
      const defaulted<int,true > T(12,34);
      const defaulted<int,false> F(56,78);

      // writes
      THEN("writes() works as expected") {
         CHECK(T.writes().value() == 34);
         // WRITES remains true...
         CHECK((std::is_same<const decltype(T.writes()),decltype(T)>::value
                == true));

         CHECK(F.writes().value() == 78);
         // WRITES becomes true...
         CHECK((std::is_same<const decltype(F.writes()),decltype(T)>::value
                == true));
      }

      // quiet
      THEN("quiet() works as expected") {
         CHECK(T.quiet().value() == 34);
         // WRITES becomes false...
         CHECK((std::is_same<const decltype(T.quiet()),decltype(F)>::value
                == true));

         CHECK(F.quiet().value() == 78);
         // WRITES remains false...
         CHECK((std::is_same<const decltype(F.quiet()),decltype(F)>::value
                == true));
      }
   }
}
