
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Scenario for DATATYPE == void
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk BlockData with DATATYPE == void") {
   // Most BlockData functionality is tested in the individual test files.
   // There are just a few things we'll do here.

   // Ensure that we can make const and non-const <true> and <false> BlockData
   // objects. Note that BlockData has only a default constructor.

   GIVEN("A const BlockData<true,void> cbtextt") {
      const BlockData<true,void> cbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(cbtextt.length   () == 0);
         CHECK(cbtextt.size     () == 0);
         CHECK(cbtextt.valueType() == "");
         CHECK(cbtextt.string   () == "");
      }
   }

   GIVEN("A const BlockData<false,void> cbtextf") {
      const BlockData<false,void> cbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A non-const BlockData<true,void> nbtextt") {
      BlockData<true,void> nbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(nbtextt.length   () == 0);
         CHECK(nbtextt.size     () == 0);
         CHECK(nbtextt.valueType() == "");
         CHECK(nbtextt.string   () == "");
      }
   }

   GIVEN("A non-const BlockData<false,void> nbtextf") {
      BlockData<false,void> nbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   // clear() and size() are defined (at the time of this writing) in the
   // BlockData.hpp file itself, so we'll test them here. size() actually
   // was used in various tests, and thus was indirectly tested elsewhere.

   GIVEN("A BlockData") {
      // clear
      WHEN("We test clear()") {
         BlockData<true,void> b;

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
         BlockData<true,void> b;

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
// Scenario for DATATYPE != void
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk BlockData with DATATYPE != void") {

   GIVEN("A const BlockData<true,double> cbtextt") {
      const BlockData<true,double> cbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(cbtextt.length   () == 0);
         CHECK(cbtextt.size     () == 0);
         CHECK(cbtextt.valueType() == "");
         CHECK(cbtextt.string   () == "");
      }
   }

   GIVEN("A const BlockData<false,double> cbtextf") {
      const BlockData<false,double> cbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A non-const BlockData<true,int> nbtextt") {
      BlockData<true,int> nbtextt;
      THEN("It constructed correctly, and its data are as expected") {
         CHECK(nbtextt.length   () == 0);
         CHECK(nbtextt.size     () == 0);
         CHECK(nbtextt.valueType() == "");
         CHECK(nbtextt.string   () == "");
      }
   }

   GIVEN("A non-const BlockData<false,int> nbtextf") {
      BlockData<false,int> nbtextf;
      THEN("It constructed correctly") {
         // no data for <false>
      }
   }

   GIVEN("A BlockData") {
      // clear
      WHEN("We test clear()") {
         BlockData<true,int> b;
         THEN("size() works correctly") {
            b = std::vector<int>{1,2,3,4,5};
            CHECK(b.size() == 5);
            b.clear();
            CHECK(b.size() == 0);
         }
      }

      // size
      WHEN("We test size()") {
         BlockData<true,std::string> b;
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
