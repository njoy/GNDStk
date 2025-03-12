
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Scenario: pull
// Content == any of {length,start,valueType}
// -----------------------------------------------------------------------------

// Helper
template<class DATATYPE>
void scenario_pull()
{
   WHEN("pullFromDerived() is called") {
      // none of length, start, valueType
      THEN("Push to Content{} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
            } Content;
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(100).start(200).valueType("300");
         b.pullFromDerived(derived); // should do nothing here
         CHECK(b.length() == 100);
         CHECK(b.start() == 200);
         CHECK(b.valueType() == "300");
      }

      // length only
      THEN("Push to Content{length} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 10;
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(11).start(12).valueType("13");
         b.pullFromDerived(derived);
         CHECK(b.length() == 10);
         CHECK(b.start() == 12);
         CHECK(b.valueType() == "13");
      }

      // start only
      THEN("Push to Content{start} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int start = 14;
            } Content;
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(15).start(16).valueType("17");
         b.pullFromDerived(derived);
         CHECK(b.length() == 15);
         CHECK(b.start() == 14);
         CHECK(b.valueType() == "17");
      }

      // valueType only
      THEN("Push to Content{valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               std::string valueType = "18";
            } Content;
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(19).start(20).valueType("21");
         b.pullFromDerived(derived);
         CHECK(b.length() == 19);
         CHECK(b.start() == 20);
         CHECK(b.valueType() == "18");
      }

      // all but length
      THEN("Push to Content{start,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int start = 22;
               std::string valueType = "23";
            } Content;
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(24).start(25).valueType("26");
         b.pullFromDerived(derived);
         CHECK(b.length() == 24);
         CHECK(b.start() == 22);
         CHECK(b.valueType() == "23");
      }

      // all but start
      THEN("Push to Content{length,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 27;
               std::string valueType = "28";
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(29).start(30).valueType("31");
         b.pullFromDerived(derived);
         CHECK(b.length() == 27);
         CHECK(b.start() == 30);
         CHECK(b.valueType() == "28");
      }

      // all but valueType
      THEN("Push to Content{length,start} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 32;
               int start  = 33;
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(34).start(35).valueType("36");
         b.pullFromDerived(derived);
         CHECK(b.length() == 32);
         CHECK(b.start() == 33);
         CHECK(b.valueType() == "36");
      }

      // all three
      THEN("Push to Content{length,start,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 37;
               int start  = 38;
               std::string valueType = "39";
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(40).start(41).valueType("42");
         b.pullFromDerived(derived);
         CHECK(b.length() == 37);
         CHECK(b.start() == 38);
         CHECK(b.valueType() == "39");
      }
   }
}


SCENARIO("BlockData<DATATYPE == void> pull from Content") {
   GIVEN("A BlockData<true,void> object") {
      scenario_pull<void>();
   }
}

SCENARIO("BlockData<DATATYPE != void> pull from Content") {
   GIVEN("A BlockData<true,int> object") {
      scenario_pull<int>();
   }
}


// -----------------------------------------------------------------------------
// Scenario: push
// Content == any of {length,start,valueType}
// -----------------------------------------------------------------------------

// Helper
template<class DATATYPE>
void scenario_push()
{
   WHEN("pushToDerived() is called") {
      // none of length, start, valueType
      THEN("Push to Content{} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int ignored = 123456; // not length, start, or valueType
            } Content;
            const int &ignored() const { return Content.ignored; }
            int &ignored() { return Content.ignored; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(0).start(0).valueType("0");
         b.pushToDerived(derived); // should do nothing here
         CHECK(derived.ignored() == 123456);
      }

      // length only
      THEN("Push to Content{length} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 10;
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(11).start(12).valueType("13");
         b.pushToDerived(derived);
         CHECK(derived.length() == 11);
      }

      // start only
      THEN("Push to Content{start} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int start = 14;
            } Content;
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(15).start(16).valueType("17");
         b.pushToDerived(derived);
         CHECK(derived.start() == 16);
      }

      // valueType only
      THEN("Push to Content{valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               std::string valueType = "18";
            } Content;
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(19).start(20).valueType("21");
         b.pushToDerived(derived);
         CHECK(derived.valueType() == "21");
      }

      // all but length
      THEN("Push to Content{start,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int start = 22;
               std::string valueType = "23";
            } Content;
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(24).start(25).valueType("26");
         b.pushToDerived(derived);
         CHECK(derived.start() == 25);
         CHECK(derived.valueType() == "26");
      }

      // all but start
      THEN("Push to Content{length,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 27;
               std::string valueType = "28";
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(29).start(30).valueType("31");
         b.pushToDerived(derived);
         CHECK(derived.length() == 29);
         CHECK(derived.valueType() == "31");
      }

      // all but valueType
      THEN("Push to Content{length,start} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 32;
               int start  = 33;
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(34).start(35).valueType("36");
         b.pushToDerived(derived);
         CHECK(derived.length() == 34);
         CHECK(derived.start()  == 35);
      }

      // all three
      THEN("Push to Content{length,start,valueType} works") {
         struct : public BlockData<true,DATATYPE> {
            struct {
               int length = 37;
               int start  = 38;
               std::string valueType = "39";
            } Content;
            const int &length() const { return Content.length; }
            int &length() { return Content.length; }
            const int &start() const { return Content.start; }
            int &start() { return Content.start; }
            const std::string &valueType() const { return Content.valueType; }
            std::string &valueType() { return Content.valueType; }
         } derived;
         BlockData<true,DATATYPE> &b = derived;
         b.length(40).start(41).valueType("42");
         b.pushToDerived(derived);
         CHECK(derived.length() == 40);
         CHECK(derived.start()  == 41);
         CHECK(derived.valueType() == "42");
      }
   }
}


SCENARIO("BlockData<DATATYPE == void> push to Content") {
   GIVEN("A BlockData<true,void> object") {
      scenario_push<void>();
   }
}

SCENARIO("BlockData<DATATYPE != void> push to Content") {
   GIVEN("A BlockData<true,int> object") {
      scenario_push<int>();
   }
}
