
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

SCENARIO("Testing GNDStk child_t<TYPE,ALLOW,CONVERTER>") {
   const auto filter = detail::noFilter{};

   // child_t<TYPE,...>
   GIVEN("The child_t<TYPE,...> class") {
      WHEN("Constructed with (name)") {
         const child_t<double>
            foo("foo");
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter)") {
         const child_t<double,Allow::one,converter>
            foo("foo", 0.0, converter{});
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter,filter)") {
         const child_t<double,Allow::one,converter>
            foo("foo", 0.0, converter{}, filter);
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,converter,filter,top)") {
         const child_t<double,Allow::one,converter>
            foo("foo", 0.0, converter{}, filter, true);
         CHECK(foo.name == "foo");
         CHECK(foo.top());
      }
   }

   // child_t<void,...>
   GIVEN("The child_t<void,...> class") {
      WHEN("Constructed with (name)") {
         const child_t<void>
            foo("foo");
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,filter)") {
         const child_t<void>
            foo("foo", filter);
         CHECK(foo.name == "foo");
         CHECK(!foo.top());
      }

      WHEN("Constructed with (name,filter,top)") {
         const child_t<void>
            foo("foo", filter, true);
         CHECK(foo.name == "foo");
         CHECK(foo.top());
      }
   }
}
