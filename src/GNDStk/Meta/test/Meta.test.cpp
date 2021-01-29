
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

SCENARIO("Testing GNDStk Meta<TYPE,CONVERTER>") {

   // Meta<TYPE,CONVERTER>
   GIVEN("The Meta<TYPE,CONVERTER> class") {
      WHEN("Constructed with (name)") {
         Meta<double> foo("foo");
         CHECK(foo.name == "foo");
      }

      WHEN("Constructed with (name,converter)") {
         Meta<double,converter> bar("bar",double{},converter{});
         CHECK(bar.name == "bar");
      }
   }

   // Meta<void>
   GIVEN("The Meta<void> class") {
      WHEN("Constructed with (name)") {
         Meta<void> foo("foo");
         CHECK(foo.name == "foo");
      }
   }
}
