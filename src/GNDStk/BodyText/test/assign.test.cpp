
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


// -----------------------------------------------------------------------------
// Scenario for DATA == void
// -----------------------------------------------------------------------------

SCENARIO("BodyText<DATA == void> assignment operators") {
   GIVEN("A default-constructed BodyText<true,void> object") {

      // Default value of raw string is as expected
      WHEN("We examine the raw string") {
         THEN("It is as expected") {
            BodyText<true,void> b;
            CHECK(b.string() == "");
         }
      }

      // Assignment from string works
      WHEN("We assign from a string") {
         THEN("The raw string has the correct value, and vector size() == 0") {
            BodyText<true,void> b;

            // to ensure it clears the vector below...
            b = std::vector<int>(10);
            CHECK(b.size() == 10);

            b = "10 20 30";
            CHECK(b.string() == "10 20 30");
            // Setting the string makes the vector inactive,
            // and clears the vector for good measure...
            CHECK(b.size() == 0);
         }
      }

      // Assignment from vector works
      WHEN("We assign from a vector") {
         THEN("The variant has the correct value, and raw string == \"\"") {
            BodyText<true,void> b;

            // to ensure it clears the raw string etc. below...
            b = "foo bar";
            b.start(12).length(345).valueType("foo");

            CHECK(b.size() == 0);
            CHECK(b.start() == 12);
            CHECK(b.length() == 345);
            CHECK(b.valueType() == "foo");

            b = std::vector<int>{{5,4,3,2,1}};

            CHECK(b.string() == "");
            CHECK(b.size() == 5);
            CHECK(b.start() == 0);
            CHECK(b.length() == 5);
            CHECK(b.valueType() != "foo");

            CHECK(b.get<std::vector<int>>()[0] == 5);
            CHECK(b.get<std::vector<int>>()[1] == 4);
            CHECK(b.get<std::vector<int>>()[2] == 3);
            CHECK(b.get<std::vector<int>>()[3] == 2);
            CHECK(b.get<std::vector<int>>()[4] == 1);
         }
      }

      // Assign from vector<int>; should set valueType
      WHEN("We assign from a vector<int>") {
         THEN("valueType is set correctly") {
            BodyText<true,void> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<int>{{10,20,30}};
            CHECK(b.valueType() == "Integer32");
         }
      }

      // Assign from vector<double>; should set valueType
      WHEN("We assign from a vector<double>") {
         THEN("valueType is set correctly") {
            BodyText<true,void> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<double>{{1.23,4.56,7.89}};
            CHECK(b.valueType() == "Float64");
         }
      }

      // For now, non-{int,double} sets valueType == ""
      WHEN("We assign from a vector<non-{int,double}>") {
         THEN("valueType is set correctly") {
            BodyText<true,void> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<char>{'a','b','c'};
            CHECK(b.valueType() == "char");
         }
      }

   } // GIVEN
} // SCENARIO


// -----------------------------------------------------------------------------
// Scenario for DATA != void
// -----------------------------------------------------------------------------

SCENARIO("BodyText<DATA != void> assignment operators") {
   GIVEN("A default-constructed BodyText<true,int> object") {

      // Default value of raw string is as expected
      WHEN("We examine the raw string") {
         THEN("It is as expected") {
            BodyText<true,int> b;
            CHECK(b.string() == "");
         }
      }

      // Assignment from string works
      WHEN("We assign from a string") {
         THEN("The raw string has the correct value, and vector size() == 0") {
            BodyText<true,double> b;

            // to ensure it clears the vector below...
            b = std::vector<double>(10);
            CHECK(b.size() == 10);

            b = "10.1 20.2 30.3";
            CHECK(b.string() == "10.1 20.2 30.3");
            // Setting the string makes the vector inactive,
            // and clears the vector for good measure...
            CHECK(b.size() == 0);
         }
      }

      // Assignment from vector works
      WHEN("We assign from a vector") {
         THEN("The vector has the correct value, and raw string == \"\"") {
            BodyText<true,int> b;

            // to ensure it clears the raw string etc. below...
            b = "foo bar";
            b.start(12).length(345).valueType("foo");

            CHECK(b.size() == 0);
            CHECK(b.start() == 12);
            CHECK(b.length() == 345);
            CHECK(b.valueType() == "foo");

            b = std::vector<int>{{5,4,3,2,1}};

            CHECK(b.string() == "");
            CHECK(b.size() == 5);
            CHECK(b.start() == 0);
            CHECK(b.length() == 5);
            CHECK(b.valueType() != "foo");

            CHECK(b.get<std::vector<int>>()[0] == 5);
            CHECK(b.get<std::vector<int>>()[1] == 4);
            CHECK(b.get<std::vector<int>>()[2] == 3);
            CHECK(b.get<std::vector<int>>()[3] == 2);
            CHECK(b.get<std::vector<int>>()[4] == 1);
         }
      }

      // Assign from vector<int>; should set valueType
      WHEN("We assign from a vector<int>") {
         THEN("valueType is set correctly") {
            BodyText<true,int> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<int>{{10,20,30}};
            CHECK(b.valueType() == "Integer32");
         }
      }

      // Assign from vector<double>; should set valueType
      WHEN("We assign from a vector<double>") {
         THEN("valueType is set correctly") {
            BodyText<true,double> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<double>{{1.23,4.56,7.89}};
            CHECK(b.valueType() == "Float64");
         }
      }

      // For now, non-{int,double} sets valueType == ""
      WHEN("We assign from a vector<non-{int,double}>") {
         THEN("valueType is set correctly") {
            BodyText<true,char> b;

            b.string("foo").valueType("unknown");
            CHECK(b.valueType() == "unknown");

            b = std::vector<char>{'a','b','c'};
            CHECK(b.valueType() == "char");
         }
      }

   } // GIVEN
} // SCENARIO
