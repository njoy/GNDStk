
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

SCENARIO("Testing GNDStk Child<TYPE,ALLOW,CONVERTER>") {
   const auto filter = detail::noFilter{};

   // Child<TYPE,...>
   GIVEN("The Child<TYPE,...> class") {
      WHEN("Constructed with (name)") {
         const Child<double>
            foo("foo");
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter)") {
         const Child<double,Allow::one,converter>
            foo("foo", 0.0, converter{});
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter,filter)") {
         const Child<double,Allow::one,converter>
            foo("foo", 0.0, converter{}, filter);
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter,filter,top)") {
         const Child<double,Allow::one,converter>
            foo("foo", 0.0, converter{}, filter, true);
         CHECK(foo.name == "foo");
         CHECK(foo.top());
      }
   }

   // Child<void,...>
   GIVEN("The Child<void,...> class") {
      WHEN("Constructed with (name)") {
         const Child<void>
            foo("foo");
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,filter)") {
         const Child<void>
            foo("foo", filter);
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,filter,top)") {
         const Child<void>
            foo("foo", filter, true);
         CHECK(foo.name == "foo");
         CHECK(foo.top());
      }
   }
}
