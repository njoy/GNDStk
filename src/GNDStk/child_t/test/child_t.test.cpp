
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

   // child_t<TYPE,...>
   GIVEN("The child_t<TYPE,...> class") {
      WHEN("Constructed with (name)") {
         child_t<double> foo("foo");
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == false);
      }

      WHEN("Constructed with (name,top=true)") {
         child_t<double> foo("foo",true);
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == true);
      }

      WHEN("Constructed with (name,top=true,converter)") {
         child_t<double,allow::one,converter> foo("foo",true,converter{});
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == true);
      }

      WHEN("Constructed with (name,converter)") {
         child_t<double,allow::one,converter> foo("foo",converter{});
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == false);
      }

      WHEN("Constructed with (name,converter,top=true)") {
         child_t<double,allow::one,converter> foo("foo",converter{},true);
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == true);
      }
   }

   // child_t<void,...>
   GIVEN("The child_t<void,...> class") {
      WHEN("Constructed with (name)") {
         child_t<void> foo("foo");
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == false);
      }

      WHEN("Constructed with (name,top=true)") {
         child_t<void> foo("foo",true);
         CHECK(foo.name == "foo");
         CHECK(foo.canBeTopLevel == true);
      }
   }
}
