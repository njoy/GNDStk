
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("BodyText toNode()") {

   // Default-constructed BodyText
   GIVEN("A default-constructed BodyText") {
      WHEN("toNode() is called") {
         THEN("The computed text string is empty") {
            const BodyText<true> b;

            std::string text = "abc";
            struct { } content;

            // w/trim == true (shouldn't matter here; applies to vector)
            b.trim = true;
            b.toNode(text,content);
            CHECK(text == "");

            // w/trim == false (shouldn't matter here; applies to vector)
            b.trim = false;
            b.toNode(text,content);
            CHECK(text == "");
         }
      }
   }

   // BodyText, after being given a particular raw string and parameters
   GIVEN("A BodyText, with given raw string and parameters") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters remain as given"
         ) {
            BodyText<true> b;
            b.string("0 12 34 56 0 0")
             .start(100).length(200).valueType("hello");

            std::string text = "abc";
            struct { } content;

            // Someone who sets the raw string directly (as opposed to using
            // a vector) is stating that they want *exactly* that raw string,
            // including any 0s or anything else. To have BodyText's trim flag
            // be relevant, use a vector.

            // w/trim == true (shouldn't matter here; applies to vector)
            b.trim = true;
            b.toNode(text,content);
            CHECK(text == "0 12 34 56 0 0");
            CHECK(b.start() == 100);
            CHECK(b.length() == 200);
            CHECK(b.valueType() == "hello");

            // w/trim == false (shouldn't matter here; applies to vector)
            b.trim = false;
            b.toNode(text,content);
            CHECK(text == "0 12 34 56 0 0");
            CHECK(b.start() == 100);
            CHECK(b.length() == 200);
            CHECK(b.valueType() == "hello");
         }
      }
   }

   // BodyText, after being given a particular vector<Integer32>
   GIVEN("A BodyText, assigned from a particular vector<Integer32>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            BodyText<true> b;
            // what's set here should be replaced upon assignment from vector
            b.string("a b c").start(10).length(20).valueType("foobar");

            // assign from vector
            b = std::vector<Integer32>{{0, 0, 12, 34, 56, 78, 0, 0, 0, 0, 0}};

            std::string text = "this should be replaced";
            struct { } content;

            // w/trim == true
            b.trim = true;
            b.toNode(text,content);
            CHECK(text == "12 34 56 78");
            CHECK(b.start() == 2);
            CHECK(b.length() == 11);
            CHECK(b.valueType() == "Integer32");

            // w/trim == false
            b.trim = false;
            b.toNode(text,content);
            CHECK(text == "0 0 12 34 56 78 0 0 0 0 0");
            CHECK(b.start() == 0);
            CHECK(b.length() == 11);
            CHECK(b.valueType() == "Integer32");
         }
      }
   }

   // BodyText, after being given a particular vector<Float64>
   GIVEN("A BodyText, assigned from a particular vector<Float64>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            BodyText<true> b;
            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<Float64>{{0, 0, 0, 1.234, 5.678, 0, 0 }};

            std::string text = "this should be replaced";
            struct { } content;

            // w/trim == true
            b.trim = true;
            b.toNode(text,content);
            CHECK(text == "1.234 5.678");
            CHECK(b.start() == 3);
            CHECK(b.length() == 7);
            CHECK(b.valueType() == "Float64");

            // w/trim == false
            b.trim = false;
            b.toNode(text,content);
            CHECK(text == "0 0 0 1.234 5.678 0 0");
            CHECK(b.start() == 0);
            CHECK(b.length() == 7);
            CHECK(b.valueType() == "Float64");
         }
      }
   }

   // BodyText, after being given a particular vector<string>
   // A key point here is to ensure that ""s (string "zeros") are properly
   // trimmed at the beginning and end.
   GIVEN("A BodyText, assigned from a particular vector<std::string>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            BodyText<true> b;
            // what's set here should be replaced upon assignment from vector
            b.string("d e f").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<std::string>{{"","","","foo","bar","baz","",""}};

            std::string text = "this should be replaced";
            struct { } content;

            // w/trim == true
            b.trim = true;
            b.toNode(text,content);
            CHECK(text == "foo bar baz");
            CHECK(b.start() == 3);
            CHECK(b.length() == 8);
            CHECK(b.valueType() == "");

            // w/trim == false
            // toNode() should treat this (the std::string) case as if trim
            // were true. If it didn't, we'd end up with, well, leading and
            // trailing *empty* strings, which, well, amount to leading and
            // trailing nothing.
            b.trim = false;
            b.toNode(text,content);
            CHECK(text == "foo bar baz");
            CHECK(b.start() == 3);
            CHECK(b.length() == 8);
            CHECK(b.valueType() == "");
         }
      }
   }

   // BodyText, after being given a particular vector<T>
   // For T something other than Integer32, Float64, and std::string
   GIVEN("A BodyText, assigned from a particular vector<char>") {
      WHEN("toNode() is called") {
         THEN("The computed text string is as expected, "
              "and the parameters were computed properly"
         ) {
            BodyText<true> b;
            // what's set here should be replaced upon assignment from vector
            b.string("x y z").start(100).length(200).valueType("foobar");

            // assign from vector
            b = std::vector<char>{{0,0,0,0,0,'a','b','c','d',0}};

            std::string text = "this should be replaced";
            struct { } content;

            b.toNode(text,content);
            CHECK(text == "a b c d");
            CHECK(b.start() == 5);
            CHECK(b.length() == 10);
            CHECK(b.valueType() == "");
         }
      }
   }

   // Test various different configurations of "content" when calling toNode().
   // Basically, these test whether toNode properly updates whichever of length,
   // start, and valueType are in "content" (toNode()'s second argument).
   GIVEN("A BodyText, with vector<Integer32>") {
      WHEN("toNode() is called") {

         // none of length, start, valueType
         THEN("Push to content{} works") {
            struct { int ignored = 12345; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            // toNode doesn't care about what's *not* length/start/valueType...
            CHECK(content.ignored == 12345); // same as before toNode()
         }

         // length only
         THEN("Push to content{length} works") {
            struct { int length=0; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.length == 8);
         }

         // start only
         THEN("Push to content{start} works") {
            struct { int start=0; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.start == 2);
         }

         // valueType only
         THEN("Push to content{valueType} works") {
            struct { std::string valueType=""; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.valueType == "Integer32");
         }

         // all but length
         THEN("Push to content{start,valueType} works") {
            struct { int start=0; std::string valueType=""; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.start == 2);
            CHECK(content.valueType == "Integer32");
         }

         // all but start
         THEN("Push to content{length,valueType} works") {
            struct { int length=0; std::string valueType=""; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.length == 8);
            CHECK(content.valueType == "Integer32");
         }

         // all but valueType
         THEN("Push to content{length,start} works") {
            struct { int length=0, start=0; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.length == 8);
            CHECK(content.start == 2);
         }

         // all three
         THEN("Push to content{length,start,valueType} works") {
            struct { int length=0, start=0; std::string valueType=""; } content;
            BodyText<true> b; std::string text;
            b = std::vector<Integer32>{{0,0,10,20,30,0,0,0}};
            b.toNode(text,content);
            CHECK(content.length == 8);
            CHECK(content.start == 2);
            CHECK(content.valueType == "Integer32");
         }

      }
   }

} // SCENARIO
