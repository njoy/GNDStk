
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


// -----------------------------------------------------------------------------
// Scenario for DATA == void
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk BodyText with DATA == void") {
   // Most BodyText functionality is tested in the individual test files.
   // There are just a few things we'll do here.

   // Ensure that we can make const and non-const <true> and <false> BodyText
   // objects. Note that BodyText has only a default constructor.

   GIVEN("A const BodyText<true,void> cbtextt") {
      const BodyText<true,void> cbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(cbtextt.length   () == 0);
         CHECK(cbtextt.size     () == 0);
         CHECK(cbtextt.valueType() == "");
         CHECK(cbtextt.string   () == "");
      }
   }

   GIVEN("A const BodyText<false,void> cbtextf") {
      const BodyText<false,void> cbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A non-const BodyText<true,void> nbtextt") {
      BodyText<true,void> nbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(nbtextt.length   () == 0);
         CHECK(nbtextt.size     () == 0);
         CHECK(nbtextt.valueType() == "");
         CHECK(nbtextt.string   () == "");
      }
   }

   GIVEN("A non-const BodyText<false,void> nbtextf") {
      BodyText<false,void> nbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   // clear() and size() are defined (at the time of this writing) in the
   // BodyText.hpp file itself, so we'll test them here. size() actually
   // was used in various tests, and thus was indirectly tested elsewhere.

   GIVEN("A BodyText") {
      // clear
      WHEN("We test clear()") {
         BodyText<true,void> b;

         // try int
         THEN("size() works correctly for vector<int>") {
            b = std::vector<int>{1,2,3,4,5};
            CHECK(b.size() == 5);
            b.clear();
            CHECK(b.size() == 0);
         }

         // try double
         THEN("size() works correctly for vector<double>") {
            b = std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
            CHECK(b.size() == 5);
            b.clear();
            CHECK(b.size() == 0);
         }

         // try string
         THEN("size() works correctly for vector<string>") {
            b = std::vector<std::string>{"one","two","three","four","five"};
            CHECK(b.size() == 5);
            b.clear();
            CHECK(b.size() == 0);
         }
      }

      // size
      WHEN("We test size()") {
         BodyText<true,void> b;

         // try int
         THEN("size() works correctly for vector<int>") {
            b = std::vector<int>{1,2,3,4,5};
            CHECK(b.size() == 5);
            b = std::vector<int>{1};
            CHECK(b.size() == 1);
            b = std::vector<int>{};
            CHECK(b.size() == 0);
         }

         // try double
         THEN("size() works correctly for vector<double>") {
            b = std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
            CHECK(b.size() == 5);
            b = std::vector<double>{1.1};
            CHECK(b.size() == 1);
            b = std::vector<double>{};
            CHECK(b.size() == 0);
         }

         // try string
         THEN("size() works correctly for vector<string>") {
            b = std::vector<std::string>{"one","two","three","four","five"};
            CHECK(b.size() == 5);
            b = std::vector<std::string>{"one"};
            CHECK(b.size() == 1);
            b = std::vector<std::string>{};
            CHECK(b.size() == 0);
         }
      }
   }
} // SCENARIO


// -----------------------------------------------------------------------------
// Scenario for DATA != void
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk BodyText with DATA != void") {

   GIVEN("A const BodyText<true,double> cbtextt") {
      const BodyText<true,double> cbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(cbtextt.length   () == 0);
         CHECK(cbtextt.size     () == 0);
         CHECK(cbtextt.valueType() == "");
         CHECK(cbtextt.string   () == "");
      }
   }

   GIVEN("A const BodyText<false,double> cbtextf") {
      const BodyText<false,double> cbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A non-const BodyText<true,int> nbtextt") {
      BodyText<true,int> nbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(nbtextt.length   () == 0);
         CHECK(nbtextt.size     () == 0);
         CHECK(nbtextt.valueType() == "");
         CHECK(nbtextt.string   () == "");
      }
   }

   GIVEN("A non-const BodyText<false,int> nbtextf") {
      BodyText<false,int> nbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A BodyText") {
      // clear
      WHEN("We test clear()") {
         BodyText<true,int> b;
         THEN("size() works correctly") {
            b = std::vector<int>{1,2,3,4,5};
            CHECK(b.size() == 5);
            b.clear();
            CHECK(b.size() == 0);
         }
      }

      // size
      WHEN("We test size()") {
         BodyText<true,std::string> b;
         THEN("size() works correctly") {
            b = std::vector<std::string>{"one","two","three","four","five"};
            CHECK(b.size() == 5);
            b = std::vector<std::string>{"one"};
            CHECK(b.size() == 1);
            b = std::vector<std::string>{};
            CHECK(b.size() == 0);
         }
      }
   }
} // SCENARIO
