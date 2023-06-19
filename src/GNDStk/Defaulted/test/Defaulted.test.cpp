
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Defaulted<T>") {
   // There's not really anything to do here that isn't already in other tests
   // for Defaulted. So, this file is really just a place for CATCH_CONFIG_MAIN.
   // Let's go ahead and do a little something, though, just for fun...

   GIVEN("A Defaulted<int>") {
      Defaulted<int> d(0); // 0 is the default - not a value
      CHECK(d.has_value() == false);
      d = 12345;
      CHECK(d.has_value() == true);
      CHECK(d.value() == 12345);
   }
}
