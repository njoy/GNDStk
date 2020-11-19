
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

class converter {
public:
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const
   {
      convert(from,to);
   }
};

SCENARIO("Testing GNDStk meta_t<TYPE,CONVERTER>") {

   // meta_t<TYPE,CONVERTER>
   GIVEN("The meta_t<TYPE,CONVERTER> class") {
      WHEN("Constructed with (name)") {
         meta_t<double> foo("foo");
         CHECK(foo.name == "foo");
      }

      WHEN("Constructed with (name,converter)") {
         meta_t<double,converter> bar("bar",converter{});
         CHECK(bar.name == "bar");
      }
   }

   // meta_t<void>
   GIVEN("The meta_t<void> class") {
      WHEN("Constructed with (name)") {
         meta_t<void> foo("foo");
         CHECK(foo.name == "foo");
      }
   }
}
