
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Helper
// -----------------------------------------------------------------------------

// Tests use either void for each template parameter, or int, double,
// std::string, and char, in that order. In the former case, we're testing
// toNode() for the generic BlockData<...,void>. In the latter case, we're
// testing toNode() for non-generic BlockData.
template<class INTEGER, class FLOAT, class STRING, class CHAR>
void scenario_toNode()
{
   // Default-constructed BlockData
   GIVEN("A default-constructed BlockData") {
      WHEN("toNode() is called") {
         THEN("The computed text string is empty") {
            std::string text = "abc";
            struct : public BlockData<true,INTEGER> {
               struct {
               } content;
            } derived;
            BlockData<true,INTEGER> &b = derived;

            // w/trim == true (shouldn't matter here; applies to vector)
            b.trim = true;
            b.toNode(text);
            CHECK(text == "");

            // w/trim == false (shouldn't matter here; applies to vector)
            b.trim = false;
            b.toNode(text);
            CHECK(text == "");
         }
      }
   }

   // BlockData, after being given a particular raw string and parameters
   GIVEN("A BlockData, with given raw string and parameters") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters remain as given"
         ) {
            struct : public BlockData<true,INTEGER> {
               struct {
               } content;
            } derived;
            BlockData<true,INTEGER> &b = derived;

            b.string("0 12 34 56 0 0")
             .start(100).length(200).valueType("hello");

            // Someone who sets the raw string directly (as opposed to using
            // a vector) is stating that they want *exactly* that raw string,
            // including any 0s or anything else. To have BlockData's trim flag
            // be relevant, use a vector.

            // w/trim == true (shouldn't matter here; applies to vector)
            std::string text = "abc";
            b.trim = true;
            b.toNode(text);
            CHECK(text == "0 12 34 56 0 0");
            CHECK(b.start() == 100);
            CHECK(b.length() == 200);
            CHECK(b.valueType() == "hello");

            // w/trim == false (shouldn't matter here; applies to vector)
            text = "abc";
            b.trim = false;
            b.toNode(text);
            CHECK(text == "0 12 34 56 0 0");
            CHECK(b.start() == 100);
            CHECK(b.length() == 200);
            CHECK(b.valueType() == "hello");
         }
      }
   }

   // BlockData, after being given a particular vector<int>
   GIVEN("A BlockData, assigned from a particular vector<int>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            struct : public BlockData<true,INTEGER> {
               struct {
               } content;
            } derived;
            BlockData<true,INTEGER> &b = derived;

            // what's set here should be replaced upon assignment from vector
            b.string("a b c").start(10).length(20).valueType("foobar");

            // assign from vector
            b = std::vector<int>{{0, 0, 12, 34, 56, 78, 0, 0, 0, 0, 0}};

            // w/trim == true
            std::string text = "this should be replaced";
            b.trim = true;
            b.toNode(text);
            CHECK(text == "12 34 56 78");
            CHECK(b.start() == 2);
            CHECK(b.length() == 11);
            CHECK(b.valueType() == "Integer32");

            // w/trim == false
            text = "this should be replaced";
            b.trim = false;
            b.toNode(text);
            CHECK(text == "0 0 12 34 56 78 0 0 0 0 0");
            CHECK(b.start() == 0);
            CHECK(b.length() == 11);
            CHECK(b.valueType() == "Integer32");
         }
      }
   }

   // BlockData, after being given a particular vector<double>
   GIVEN("A BlockData, assigned from a particular vector<double>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            struct : public BlockData<true,FLOAT> {
               struct {
               } content;
            } derived;
            BlockData<true,FLOAT> &b = derived;

            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<double>{{0, 0, 0, 1.234, 5.678, 0, 0 }};

            // w/trim == true
            std::string text = "this should be replaced";
            b.trim = true;
            b.toNode(text);
            CHECK(text == "1.234 5.678");
            CHECK(b.start() == 3);
            CHECK(b.length() == 7);
            CHECK(b.valueType() == "Float64");

            // w/trim == false
            text = "this should be replaced";
            b.trim = false;
            b.toNode(text);
            CHECK(text == "0 0 0 1.234 5.678 0 0");
            CHECK(b.start() == 0);
            CHECK(b.length() == 7);
            CHECK(b.valueType() == "Float64");
         }
      }
   }

   // BlockData, after being given a particular vector<string>
   // A key point here is to ensure that ""s (string "zeros") are properly
   // trimmed at the beginning and end.
   GIVEN("A BlockData, assigned from a particular vector<std::string>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            struct : public BlockData<true,STRING> {
               struct {
               } content;
            } derived;
            BlockData<true,STRING> &b = derived;

            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<std::string>{{"","","","foo","bar","baz","",""}};

            // w/trim == true
            std::string text = "this should be replaced";
            b.trim = true;
            b.toNode(text);
            CHECK(text == "foo bar baz");
            CHECK(b.start() == 3);
            CHECK(b.length() == 8);
            CHECK(b.valueType() == "UTF8Text");

            // w/trim == false
            // toNode() should treat this (the std::string) case as if trim
            // were true. If it didn't, we'd end up with, well, leading and
            // trailing *empty* strings, which, well, amount to leading and
            // trailing nothing.
            text = "this should be replaced";
            b.trim = false;
            b.toNode(text);
            CHECK(text == "foo bar baz");
            CHECK(b.start() == 3);
            CHECK(b.length() == 8);
            CHECK(b.valueType() == "UTF8Text");
         }
      }
   }

   // BlockData, after being given a particular vector<T>
   // For T something other than int, double, and std::string
   GIVEN("A BlockData, assigned from a particular vector<char>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            struct : public BlockData<true,CHAR> {
               struct {
               } content;
            } derived;
            BlockData<true,CHAR> &b = derived;

            // what's set here should be replaced upon assignment from vector
            b.string("x y z").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<char>{{0,0,0,0,0,'a','b','c','d',0}};

            std::string text = "this should be replaced";
            b.toNode(text);
            CHECK(text == "a b c d");
            CHECK(b.start() == 5);
            CHECK(b.length() == 10);
            CHECK(b.valueType() == "char");
         }
      }
   }
}


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("BlockData<DATATYPE == void> toNode()") {
   scenario_toNode<void,void,void,void>();
}

SCENARIO("BlockData<DATATYPE != void> toNode()") {
   scenario_toNode<int,double,std::string,char>();
}
