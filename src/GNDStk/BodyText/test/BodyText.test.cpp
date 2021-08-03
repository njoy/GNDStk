
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

SCENARIO("Testing GNDStk BodyText") {
   // Most BodyText functionality is tested in the individual test files.
   // There are just a few things we'll do here.

   // Ensure that we can make const and non-const <true> and <false> BodyText
   // objects. Note that BodyText has only a default constructor.

   {
      const BodyText<true> cbt;
      CHECK(cbt.length   () == 0);
      CHECK(cbt.size     () == 0);
      CHECK(cbt.valueType() == "");
      CHECK(cbt.string   () == "");
   } {
      const BodyText<false> cbf;
      // no data for <false>
   } {
      BodyText<true> nbt;
      CHECK(nbt.length   () == 0);
      CHECK(nbt.size     () == 0);
      CHECK(nbt.valueType() == "");
      CHECK(nbt.string   () == "");
   } {
      BodyText<false> nbf;
      // no data for <false>
   }

   // clear() and size() are defined (at the time of this writing) in the
   // BodyText.hpp file itself, so we'll test them here. size() actually
   // was used in various tests, and thus was indirectly tested elsewhere.

   GIVEN("A BodyText object") {
      // clear
      WHEN("We test clear()") {
         BodyText<true> b;

         // try int
         b = std::vector<int>{1,2,3,4,5};
         CHECK(b.size() == 5);
         b.clear();
         CHECK(b.size() == 0);

         // try double
         b = std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
         CHECK(b.size() == 5);
         b.clear();
         CHECK(b.size() == 0);

         // try string
         b = std::vector<std::string>{"one", "two", "three", "four", "five"};
         CHECK(b.size() == 5);
         b.clear();
         CHECK(b.size() == 0);
      }

      // size
      WHEN("We test size()") {
         BodyText<true> b;

         // try int
         b = std::vector<int>{1,2,3,4,5};
         CHECK(b.size() == 5);
         b = std::vector<int>{1};
         CHECK(b.size() == 1);
         b = std::vector<int>{};
         CHECK(b.size() == 0);

         // try double
         b = std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
         CHECK(b.size() == 5);
         b = std::vector<double>{1.1};
         CHECK(b.size() == 1);
         b = std::vector<double>{};
         CHECK(b.size() == 0);

         // try string
         b = std::vector<std::string>{"one", "two", "three", "four", "five"};
         CHECK(b.size() == 5);
         b = std::vector<std::string>{"one"};
         CHECK(b.size() == 1);
         b = std::vector<std::string>{};
         CHECK(b.size() == 0);
      }
   }
}
