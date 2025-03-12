
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Scenario: raw string is active
// -----------------------------------------------------------------------------

// Helper: scenario_print_string_active
template<class DATATYPE>
void scenario_print_string_active()
{
   // string is active, but empty
   GIVEN("A BlockData with an empty raw string") {
      WHEN("BlockData.print() is called") {
         THEN("Nothing is printed") {
            BlockData<true,DATATYPE> b;
            b.string("");

            // with no indentation
            std::ostringstream oss;
            b.print(oss,0);
            CHECK(oss.str() == "");

            // the same (nothing is printed) even if indentation is nonzero
            oss.str("");
            b.print(oss,2);
            CHECK(oss.str() == "");
         }
      }
   }

   // string is active, and contains values
   GIVEN("A BlockData with a non-empty raw string") {
      WHEN("BlockData.print() is called") {
         THEN("The raw string and a newline are printed") {
            BlockData<true,DATATYPE> b;
            b.string("foo bar baz");

            njoy::GNDStk::colors = false;
            njoy::GNDStk::shades = false;

            // with no indentation
            std::ostringstream oss;
            b.print(oss,0);
            CHECK(oss.str() == "foo bar baz\n");

            // the same, even if indentation is nonzero; indentation isn't
            // applied when the raw string (as opposed to the ) is active
            oss.str("");
            b.print(oss,2);
            CHECK(oss.str() == "foo bar baz\n");
         }
      }
   }
}

// For DATATYPE == void
SCENARIO("BlockData<void> print(), when the raw string is active")
{
   scenario_print_string_active<void>();
}

// For DATATYPE == double
SCENARIO("BlockData<double> print(), when the raw string is active")
{
   scenario_print_string_active<double>();
}


// -----------------------------------------------------------------------------
// Scenario: vector is active
// -----------------------------------------------------------------------------

SCENARIO("BlockData<int> print(), when a vector is active")
{
   // vector is active, but empty
   GIVEN("A BlockData with an empty vector") {
      WHEN("BlockData.print() is called") {
         THEN("Nothing is printed") {
            BlockData<true,int> b;
            b = std::vector<int>{};

            // with no indentation
            std::ostringstream oss;
            b.print(oss,0);
            CHECK(oss.str() == "");

            // the same (nothing is printed) even if indentation is nonzero
            oss.str("");
            b.print(oss,2);
            CHECK(oss.str() == "");
         }
      }
   }

   // vector is active, and contains values
   GIVEN("A BlockData with a non-empty vector") {
      WHEN("BlockData.print() is called") {
         THEN("The vector and a newline are printed") {
            BlockData<true,int> b;
            b = std::vector<int>{{2, 3, 5, 7, 11, 13, 17, 19, 21, 23}};
            std::ostringstream oss;

            // Cases:
            //    indent:  0, 3 (number of spaces per indentation level)
            //    columns: 0, 1, 2, 5, 10, 11 (note that 10 == vector size)
            //    level:   0, 1, 2 (indentation level)
            // Note: columns <= 0 means unlimited: so, all values on one line.
            // Lots of cases, but we want to check that our prettyprinting
            // functionality works perfectly, and doesn't do anything that's
            // unexpected around "boundaries" like columns==10 with 10 values.

            oss.str(""); indent = 0; columns =  0; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns =  0; b.print(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns =  0; b.print(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns =  1; b.print(oss,0);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; columns =  1; b.print(oss,1);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; columns =  1; b.print(oss,2);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 0; columns =  2; b.print(oss,0);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; columns =  2; b.print(oss,1);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; columns =  2; b.print(oss,2);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 0; columns =  5; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; columns =  5; b.print(oss,1);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; columns =  5; b.print(oss,2);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 10; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 10; b.print(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 10; b.print(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 11; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 11; b.print(oss,1);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 0; columns = 11; b.print(oss,2);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  0; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  0; b.print(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  0; b.print(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  1; b.print(oss,0);
            CHECK(oss.str() == "2\n3\n5\n7\n11\n13\n17\n19\n21\n23\n");

            oss.str(""); indent = 3; columns =  1; b.print(oss,1);
            CHECK(oss.str() ==
                  "   2\n   3\n   5\n   7\n   11\n"
                  "   13\n   17\n   19\n   21\n   23\n");

            oss.str(""); indent = 3; columns =  1; b.print(oss,2);
            CHECK(oss.str() ==
                  "      2\n      3\n      5\n      7\n      11\n"
                  "      13\n      17\n      19\n      21\n      23\n");

            oss.str(""); indent = 3; columns =  2; b.print(oss,0);
            CHECK(oss.str() == "2 3\n5 7\n11 13\n17 19\n21 23\n");

            oss.str(""); indent = 3; columns =  2; b.print(oss,1);
            CHECK(
               oss.str() ==
               "   2 3\n   5 7\n   11 13\n   17 19\n   21 23\n"
            );

            oss.str(""); indent = 3; columns =  2; b.print(oss,2);
            CHECK(
               oss.str() ==
               "      2 3\n      5 7\n      11 13\n      17 19\n      21 23\n"
            );

            oss.str(""); indent = 3; columns =  5; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11\n13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  5; b.print(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11\n   13 17 19 21 23\n");

            oss.str(""); indent = 3; columns =  5; b.print(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11\n      13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 10; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 10; b.print(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 10; b.print(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 11; b.print(oss,0);
            CHECK(oss.str() == "2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 11; b.print(oss,1);
            CHECK(oss.str() == "   2 3 5 7 11 13 17 19 21 23\n");

            oss.str(""); indent = 3; columns = 11; b.print(oss,2);
            CHECK(oss.str() == "      2 3 5 7 11 13 17 19 21 23\n");
         }
      }
   }
}



// -----------------------------------------------------------------------------
// Scenario: vector is active; test GNDStk::elements
// -----------------------------------------------------------------------------

// Helper: test_elements
template<class DATATYPE>
void test_elements(
   const BlockData<true,DATATYPE> &b,
   const int indent,
   const size_t columns,
   const int level,
   const long elements,
   const std::string &want
) {
   njoy::GNDStk::indent   = indent;
   njoy::GNDStk::columns  = columns;
   njoy::GNDStk::elements = elements;

   std::ostringstream oss;
   b.print(oss,level);

   std::cout << "test_elements:" << std::endl;
   std::cout << oss.str() << std::endl;

   CHECK(oss.str() == want);
}

SCENARIO("BlockData<double> print(), vector, trying GNDStk::elements")
{
   // vector is active, but empty
   GIVEN("A BlockData with an empty vector") {
      WHEN("BlockData.print() is called") {
         THEN("Nothing is printed") {
            BlockData<true,double> b;
            b = std::vector<double>{};

            using njoy::GNDStk::elements;
            for (elements = -10; elements <= 10; ++elements) {
               // with no indentation
               std::ostringstream oss;
               b.print(oss,0);
               CHECK(oss.str() == "");

               // the same (nothing is printed) even if indentation is nonzero
               oss.str("");
               b.print(oss,2);
               CHECK(oss.str() == "");
            }
         }
      }
   }

   // vector is active, and contains values
   GIVEN("A BlockData with a non-empty vector") {
      WHEN("BlockData.print() is called") {
         THEN("The vector and a newline are printed") {
            BlockData<true,double> b;
            b = std::vector<double>{{2.3, 5.7, 11.13, 17.19, 21.23}};

            // Cases:
            //    indent:    3 (number of spaces per indentation level)
            //    columns:   0, 2, 3 (0 means unlimited)
            //    level:     0, 1, 2 (indentation level)
            //    elements: -1, 0, 1, 2, 3 (-1 means none; so, print all values)
            // Lots of cases; we want prettyprinting to be perfect.

            // Integral parameters below are: indent, columns, level, elements
            test_elements(b, 3,  0,  0,  -1,
                          "2.3 5.7 11.13 17.19 21.23\n");
            test_elements(b, 3,  0,  0,  +0,
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  0,  +1,
                          "2.3\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  0,  +2,
                          "2.3 5.7\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  0,  +3,
                          "2.3 5.7 11.13\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  1,  -1,
                          "   2.3 5.7 11.13 17.19 21.23\n");
            test_elements(b, 3,  0,  1,  +0,
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  1,  +1,
                          "   2.3\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  1,  +2,
                          "   2.3 5.7\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  1,  +3,
                          "   2.3 5.7 11.13\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  2,  -1,
                          "      2.3 5.7 11.13 17.19 21.23\n");
            test_elements(b, 3,  0,  2,  +0,
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  2,  +1,
                          "      2.3\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  2,  +2,
                          "      2.3 5.7\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  0,  2,  +3,
                          "      2.3 5.7 11.13\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  0,  -1,
                          "2.3 5.7\n"
                          "11.13 17.19\n"
                          "21.23\n");
            test_elements(b, 3,  2,  0,  +0,
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  0,  +1,
                          "2.3\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  0,  +2,
                          "2.3 5.7\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  0,  +3,
                          "2.3 5.7\n"
                          "11.13\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  1,  -1,
                          "   2.3 5.7\n"
                          "   11.13 17.19\n"
                          "   21.23\n");
            test_elements(b, 3,  2,  1,  +0,
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  1,  +1,
                          "   2.3\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  1,  +2,
                          "   2.3 5.7\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  1,  +3,
                          "   2.3 5.7\n"
                          "   11.13\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  2,  -1,
                          "      2.3 5.7\n"
                          "      11.13 17.19\n"
                          "      21.23\n");
            test_elements(b, 3,  2,  2,  +0,
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  2,  +1,
                          "      2.3\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  2,  +2,
                          "      2.3 5.7\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  2,  2,  +3,
                          "      2.3 5.7\n"
                          "      11.13\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  0,  -1,
                          "2.3 5.7 11.13\n"
                          "17.19 21.23\n");
            test_elements(b, 3,  3,  0,  +0,
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  0,  +1,
                          "2.3\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  0,  +2,
                          "2.3 5.7\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  0,  +3,
                          "2.3 5.7 11.13\n"
                          "// truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  1,  -1,
                          "   2.3 5.7 11.13\n"
                          "   17.19 21.23\n");
            test_elements(b, 3,  3,  1,  +0,
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  1,  +1,
                          "   2.3\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  1,  +2,
                          "   2.3 5.7\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  1,  +3,
                          "   2.3 5.7 11.13\n"
                          "   // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  2,  -1,
                          "      2.3 5.7 11.13\n"
                          "      17.19 21.23\n");
            test_elements(b, 3,  3,  2,  +0,
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  2,  +1,
                          "      2.3\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  2,  +2,
                          "      2.3 5.7\n"
                          "      // truncated; actual #elements == 5\n");
            test_elements(b, 3,  3,  2,  +3,
                          "      2.3 5.7 11.13\n"
                          "      // truncated; actual #elements == 5\n");
         }
      }
   }
}
