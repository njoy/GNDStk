
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


// -----------------------------------------------------------------------------
// Scenario: raw string
// -----------------------------------------------------------------------------

// Helper
template<class DATATYPE>
void scenario_write_string_active()
{
   GIVEN("A BlockData with an empty raw string") {
      WHEN("BlockData.write() is called") {
         THEN("Nothing is printed") {
            BlockData<true,DATATYPE> b;
            b = std::vector<char>{{'a','b','c'}};
            b.string(""); // should make string (not vector) active
            std::ostringstream oss;
            b.write(oss,0);
            CHECK(oss.str() == "");

            // same (nothing printed) if indentation is non-0
            b.write(oss,2);
            CHECK(oss.str() == "");
         }
      }
   }

   GIVEN("A BlockData with a non-empty raw string") {
      WHEN("BlockData.write() is called") {
         THEN("The raw string and a newline are printed") {
            BlockData<true,DATATYPE> b;
            b = std::vector<char>{{'a','b','c'}};
            b.string("foo bar"); // should make string (not vector) active

            std::ostringstream oss;
            b.write(oss,0);
            CHECK(oss.str() == "foo bar\n");

            // indentation isn't applied when the raw string is active
            oss.str("");
            b.write(oss,2);
            CHECK(oss.str() == "foo bar\n");
         }
      }
   }
}

// For DATATYPE == void
SCENARIO("BlockData<DATATYPE == void> write(), when the raw string is active") {
   scenario_write_string_active<void>();
}

// For DATATYPE != void
SCENARIO("BlockData<DATATYPE != void> write(), when the raw string is active") {
   scenario_write_string_active<char>();
}


// -----------------------------------------------------------------------------
// Scenario: vector
// -----------------------------------------------------------------------------

// Helper
template<class DATATYPE>
void scenario_write_vector_active()
{
   GIVEN("A BlockData with an empty vector") {
      WHEN("BlockData.write() is called") {
         THEN("Nothing is printed") {
            BlockData<true,int> b;
            b.string("should be ignored"); // because vector is forthcoming...
            b = std::vector<int>{};
            std::ostringstream oss;
            b.write(oss,0);
            CHECK(oss.str() == "");

            // same (nothing printed) if indentation is non-0
            b.write(oss,2);
            CHECK(oss.str() == "");
         }
      }
   }

   GIVEN("A BlockData with a non-empty vector") {
      WHEN("BlockData.write() is called") {
         THEN("The vector and a newline are printed") {
            BlockData<true,int> b;
            b.string("should be ignored"); // because vector is forthcoming...
            b = std::vector<int>{{2,3,5,7,11,13,17,19,21,23}};
            std::ostringstream oss;

            // Cases:
            //    indent: 0, 3 (number of spaces per indentation level)
            //    across: 0, 1, 2, 5, 10, 11 (note that 10 == vector size)
            //    level:  0, 1, 2 (indentation level)
            // Note: across == 0 ==> unlimited.
            // Lots of cases, but we want to check that our pretty-printing
            // functionality works perfectly, and doesn't do anything that's
            // unexpected around "boundaries" like across==10 with 10 values.

            oss.str(""); indent = 0; across =  0; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across =  0; b.write(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across =  0; b.write(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across =  1; b.write(oss,0);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; across =  1; b.write(oss,1);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; across =  1; b.write(oss,2);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; across =  2; b.write(oss,0);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; across =  2; b.write(oss,1);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; across =  2; b.write(oss,2);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; across =  5; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; across =  5; b.write(oss,1);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; across =  5; b.write(oss,2);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 10; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 10; b.write(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 10; b.write(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 11; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 11; b.write(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; across = 11; b.write(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  0; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  0; b.write(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  0; b.write(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  1; b.write(oss,0);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 3; across =  1; b.write(oss,1);
            CHECK(oss.str() == "   2\n   3\n   5\n   7\n   11\n   13\n   17\n   19\n   21\n   23\n");

            oss.str(""); indent = 3; across =  1; b.write(oss,2);
            CHECK(oss.str() == "      2\n      3\n      5\n      7\n      11\n      13\n      17\n      19\n      21\n      23\n");

            oss.str(""); indent = 3; across =  2; b.write(oss,0);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 3; across =  2; b.write(oss,1);
            CHECK(oss.str() == "   2 3\n   5 7\n   11 13\n   17 19\n   21 23\n");

            oss.str(""); indent = 3; across =  2; b.write(oss,2);
            CHECK(oss.str() == "      2 3\n      5 7\n      11 13\n      17 19\n      21 23\n");

            oss.str(""); indent = 3; across =  5; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  5; b.write(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11\n   13 17 19 21 23\n");

            oss.str(""); indent = 3; across =  5; b.write(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11\n      13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 10; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 10; b.write(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 10; b.write(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 11; b.write(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 11; b.write(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; across = 11; b.write(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");
         }
      }
   }
}

// For DATATYPE == void
SCENARIO("BlockData<DATATYPE == void> write(), when a vector is active") {
   scenario_write_vector_active<void>();
}

// For DATATYPE != void
SCENARIO("BlockData<DATATYPE != void> write(), when a vector is active") {
   scenario_write_vector_active<int>();
}
