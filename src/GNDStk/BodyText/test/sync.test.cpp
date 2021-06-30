
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// Scenario: pull
// content == any of {length,start,valueType}
// -----------------------------------------------------------------------------

SCENARIO("BodyText pull from content") {
   GIVEN("A BodyText object") {
      WHEN("pullFromDerived() is called") {

         // none of length, start, valueType
         THEN("Push to content{} works") {
            const struct {
            } content;
            BodyText<true> b;
            b.length(100).start(200).valueType("300");
            b.pullFromDerived(content); // should do nothing here
            CHECK(b.length() == 100);
            CHECK(b.start() == 200);
            CHECK(b.valueType() == "300");
         }

         // length only
         THEN("Push to content{length} works") {
            const struct {
               int length = 10;
            } content;
            BodyText<true> b;
            b.length(11).start(12).valueType("13");
            b.pullFromDerived(content);
            CHECK(b.length() == 10);
            CHECK(b.start() == 12);
            CHECK(b.valueType() == "13");
         }

         // start only
         THEN("Push to content{start} works") {
            const struct {
               int start = 14;
            } content;
            BodyText<true> b;
            b.length(15).start(16).valueType("17");
            b.pullFromDerived(content);
            CHECK(b.length() == 15);
            CHECK(b.start() == 14);
            CHECK(b.valueType() == "17");
         }

         // valueType only
         THEN("Push to content{valueType} works") {
            const struct {
               std::string valueType = "18";
            } content;
            BodyText<true> b;
            b.length(19).start(20).valueType("21");
            b.pullFromDerived(content);
            CHECK(b.length() == 19);
            CHECK(b.start() == 20);
            CHECK(b.valueType() == "18");
         }

         // all but length
         THEN("Push to content{start,valueType} works") {
            const struct {
               int start = 22;
               std::string valueType = "23";
            } content;
            BodyText<true> b;
            b.length(24).start(25).valueType("26");
            b.pullFromDerived(content);
            CHECK(b.length() == 24);
            CHECK(b.start() == 22);
            CHECK(b.valueType() == "23");
         }

         // all but start
         THEN("Push to content{length,valueType} works") {
            const struct {
               int length = 27;
               std::string valueType = "28";
            } content;
            BodyText<true> b;
            b.length(29).start(30).valueType("31");
            b.pullFromDerived(content);
            CHECK(b.length() == 27);
            CHECK(b.start() == 30);
            CHECK(b.valueType() == "28");
         }

         // all but valueType
         THEN("Push to content{length,start} works") {
            const struct {
               int length = 32;
               int start  = 33;
            } content;
            BodyText<true> b;
            b.length(34).start(35).valueType("36");
            b.pullFromDerived(content);
            CHECK(b.length() == 32);
            CHECK(b.start() == 33);
            CHECK(b.valueType() == "36");
         }

         // all three
         THEN("Push to content{length,start,valueType} works") {
            const struct {
               int length = 37;
               int start  = 38;
               std::string valueType = "39";
            } content;
            BodyText<true> b;
            b.length(40).start(41).valueType("42");
            b.pullFromDerived(content);
            CHECK(b.length() == 37);
            CHECK(b.start() == 38);
            CHECK(b.valueType() == "39");
         }

      }
   }
}


// -----------------------------------------------------------------------------
// Scenario: push
// content == any of {length,start,valueType}
// -----------------------------------------------------------------------------

SCENARIO("BodyText push to content") {
   GIVEN("A BodyText object") {
      WHEN("pushToDerived() is called") {

         // none of length, start, valueType
         THEN("Push to content{} works") {
            struct {
               int ignored = 123456; // not length, start, or valueType
            } content;
            BodyText<true> b;
            b.length(0).start(0).valueType("0");
            b.pushToDerived(content); // should do nothing here
            CHECK(content.ignored == 123456);
         }

         // length only
         THEN("Push to content{length} works") {
            struct {
               int length = 10;
            } content;
            BodyText<true> b;
            b.length(11).start(12).valueType("13");
            b.pushToDerived(content);
            CHECK(content.length == 11);
         }

         // start only
         THEN("Push to content{start} works") {
            struct {
               int start = 14;
            } content;
            BodyText<true> b;
            b.length(15).start(16).valueType("17");
            b.pushToDerived(content);
            CHECK(content.start == 16);
         }

         // valueType only
         THEN("Push to content{valueType} works") {
            struct {
               std::string valueType = "18";
            } content;
            BodyText<true> b;
            b.length(19).start(20).valueType("21");
            b.pushToDerived(content);
            CHECK(content.valueType == "21");
         }

         // all but length
         THEN("Push to content{start,valueType} works") {
            struct {
               int start = 22;
               std::string valueType = "23";
            } content;
            BodyText<true> b;
            b.length(24).start(25).valueType("26");
            b.pushToDerived(content);
            CHECK(content.start == 25);
            CHECK(content.valueType == "26");
         }

         // all but start
         THEN("Push to content{length,valueType} works") {
            struct {
               int length = 27;
               std::string valueType = "28";
            } content;
            BodyText<true> b;
            b.length(29).start(30).valueType("31");
            b.pushToDerived(content);
            CHECK(content.length == 29);
            CHECK(content.valueType == "31");
         }

         // all but valueType
         THEN("Push to content{length,start} works") {
            struct {
               int length = 32;
               int start  = 33;
            } content;
            BodyText<true> b;
            b.length(34).start(35).valueType("36");
            b.pushToDerived(content);
            CHECK(content.length == 34);
            CHECK(content.start  == 35);
         }

         // all three
         THEN("Push to content{length,start,valueType} works") {
            struct {
               int length = 37;
               int start  = 38;
               std::string valueType = "39";
            } content;
            BodyText<true> b;
            b.length(40).start(41).valueType("42");
            b.pushToDerived(content);
            CHECK(content.length == 40);
            CHECK(content.start  == 41);
            CHECK(content.valueType == "42");
         }

      }
   }
}
