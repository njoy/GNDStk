
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


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
            const BlockData<true,INTEGER> b;

            std::string text = "abc";
            struct {
               struct {
               } content;
            } derived;
            // w/trim == true (shouldn't matter here; applies to vector)
            b.trim = true;
            b.toNode(text,derived);
            CHECK(text == "");

            // w/trim == false (shouldn't matter here; applies to vector)
            b.trim = false;
            b.toNode(text,derived);
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
            BlockData<true,INTEGER> b;
            b.string("0 12 34 56 0 0")
             .start(100).length(200).valueType("hello");

            std::string text = "abc";
            struct {
               struct {
               } content;
            } derived;

            // Someone who sets the raw string directly (as opposed to using
            // a vector) is stating that they want *exactly* that raw string,
            // including any 0s or anything else. To have BlockData's trim flag
            // be relevant, use a vector.

            // w/trim == true (shouldn't matter here; applies to vector)
            b.trim = true;
            b.toNode(text,derived);
            CHECK(text == "0 12 34 56 0 0");
            CHECK(b.start() == 100);
            CHECK(b.length() == 200);
            CHECK(b.valueType() == "hello");

            // w/trim == false (shouldn't matter here; applies to vector)
            b.trim = false;
            b.toNode(text,derived);
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
            BlockData<true,INTEGER> b;
            // what's set here should be replaced upon assignment from vector
            b.string("a b c").start(10).length(20).valueType("foobar");

            // assign from vector
            b = std::vector<int>{{0, 0, 12, 34, 56, 78, 0, 0, 0, 0, 0}};

            std::string text = "this should be replaced";
            struct {
               struct {
               } content;
            } derived;

            // w/trim == true
            b.trim = true;
            b.toNode(text,derived);
            CHECK(text == "12 34 56 78");
            CHECK(b.start() == 2);
            CHECK(b.length() == 11);
            CHECK(b.valueType() == "Integer32");

            // w/trim == false
            b.trim = false;
            b.toNode(text,derived);
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
            BlockData<true,FLOAT> b;
            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<double>{{0, 0, 0, 1.234, 5.678, 0, 0 }};

            std::string text = "this should be replaced";
            struct {
               struct {
               } content;
            } derived;

            // w/trim == true
            b.trim = true;
            b.toNode(text,derived);
            CHECK(text == "1.234 5.678");
            CHECK(b.start() == 3);
            CHECK(b.length() == 7);
            CHECK(b.valueType() == "Float64");

            // w/trim == false
            b.trim = false;
            b.toNode(text,derived);
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
            BlockData<true,STRING> b;
            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<std::string>{{"","","","foo","bar","baz","",""}};

            std::string text = "this should be replaced";
            struct {
               struct {
               } content;
            } derived;

            // w/trim == true
            b.trim = true;
            b.toNode(text,derived);
            CHECK(text == "foo bar baz");
            CHECK(b.start() == 3);
            CHECK(b.length() == 8);
            CHECK(b.valueType() == "UTF8Text");

            // w/trim == false
            // toNode() should treat this (the std::string) case as if trim
            // were true. If it didn't, we'd end up with, well, leading and
            // trailing *empty* strings, which, well, amount to leading and
            // trailing nothing.
            b.trim = false;
            b.toNode(text,derived);
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
            BlockData<true,CHAR> b;
            // what's set here should be replaced upon assignment from vector
            b.string("x y z").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<char>{{0,0,0,0,0,'a','b','c','d',0}};

            std::string text = "this should be replaced";
            struct {
               struct {
               } content;
            } derived;

            b.toNode(text,derived);
            CHECK(text == "a b c d");
            CHECK(b.start() == 5);
            CHECK(b.length() == 10);
            CHECK(b.valueType() == "char");
         }
      }
   }

   // Test various configurations of content{} when calling toNode(). Basically,
   // these test whether toNode properly updates whichever of length, start, and
   // valueType are in .content of toNode()'s second argument.
   GIVEN("A BlockData, with vector<int>") {
      WHEN("toNode() is called") {

         // none of length, start, valueType
         THEN("Push to content{} works") {
            struct {
               struct {
                  int ignored = 12345;
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            // toNode doesn't care about what's *not* length/start/valueType...
            CHECK(derived.content.ignored == 12345); // same as before toNode()
         }

         // length only
         THEN("Push to content{length} works") {
            struct {
               struct {
                  int length = 0;
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.length == 8);
         }

         // start only
         THEN("Push to content{start} works") {
            struct {
               struct {
                  int start = 0;
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.start == 2);
         }

         // valueType only
         THEN("Push to content{valueType} works") {
            struct {
               struct {
                  std::string valueType = "";
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.valueType == "Integer32");
         }

         // all but length
         THEN("Push to content{start,valueType} works") {
            struct {
               struct {
                  int start = 0;
                  std::string valueType = "";
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.start == 2);
            CHECK(derived.content.valueType == "Integer32");
         }

         // all but start
         THEN("Push to content{length,valueType} works") {
            struct {
               struct {
                  int length = 0;
                  std::string valueType = "";
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.length == 8);
            CHECK(derived.content.valueType == "Integer32");
         }

         // all but valueType
         THEN("Push to content{length,start} works") {
            struct {
               struct {
                  int length = 0;
                  int start = 0;
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.length == 8);
            CHECK(derived.content.start == 2);
         }

         // all three
         THEN("Push to content{length,start,valueType} works") {
            struct {
               struct {
                  int length = 0;
                  int start = 0;
                  std::string valueType = "";
               } content;
            } derived;
            BlockData<true,INTEGER> b; std::string text;
            b = std::vector<int>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,derived);
            CHECK(derived.content.length == 8);
            CHECK(derived.content.start == 2);
            CHECK(derived.content.valueType == "Integer32");
         }
      }
   }
}


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("BlockData<DATA == void> toNode()") {
   scenario_toNode<void,void,void,void>();
}

SCENARIO("BlockData<DATA != void> toNode()") {
   scenario_toNode<int,double,std::string,char>();
}
