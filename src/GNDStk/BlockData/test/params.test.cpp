
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


// -----------------------------------------------------------------------------
// Helper
// -----------------------------------------------------------------------------

template<class DATATYPE>
void scenario_params()
{
   // Default values of parameters are as expected
   WHEN("We examine the default length, start, and valueType") {
      THEN("They are as expected") {
         BlockData<true,DATATYPE> b;
         CHECK(b.length() == 0);
         CHECK(b.start() == 0);
         CHECK(b.valueType() == "");
      }
   }

   // length setter/getter works
   WHEN("We set length, then get and verify") {
      THEN("It works for a plain value") {
         BlockData<true,DATATYPE> b;
         b.length(12);
         CHECK(b.length() == 12);
      }
      THEN("It works for optional-with-value") {
         BlockData<true,DATATYPE> b;
         b.length(std::optional<std::size_t>(34));
         CHECK(b.length() == 34);
      }
      THEN("It works for optional-without-value (remains unchanged)") {
         BlockData<true,DATATYPE> b;
         b.length(56);
         b.length(std::optional<std::size_t>(std::nullopt));
         CHECK(b.length() == 56);
      }
   }

   // start setter/getter works
   WHEN("We set start, then get and verify") {
      THEN("It works for a plain value") {
         BlockData<true,DATATYPE> b;
         b.start(11);
         CHECK(b.start() == 11);
      }
      THEN("It works for optional-with-value") {
         BlockData<true,DATATYPE> b;
         b.start(std::optional<std::size_t>(13));
         CHECK(b.start() == 13);
      }
      THEN("It works for optional-without-value (remains unchanged)") {
         BlockData<true,DATATYPE> b;
         b.start(17);
         b.start(std::optional<std::size_t>(std::nullopt));
         CHECK(b.start() == 17);
      }
   }

   // valueType setter/getter works
   WHEN("We set valueType, then get and verify") {
      THEN("It works for a plain value") {
         BlockData<true,DATATYPE> b;
         b.valueType("unknown");
         CHECK(b.valueType() == "unknown");
      }
      THEN("It works for optional-with-value") {
         BlockData<true,DATATYPE> b;
         b.valueType(std::optional<std::string>("Integer32"));
         CHECK(b.valueType() == "Integer32");
      }
      THEN("It works for optional-without-value (remains unchanged)") {
         BlockData<true,DATATYPE> b;
         b.valueType("Float64");
         b.valueType(std::optional<std::string>(std::nullopt));
         CHECK(b.valueType() == "Float64");
      }
   }

   // Combo of the above, using builder-pattern nature of the setters
   WHEN("We set length/start/valueType together, then get and verify") {
      THEN("It works for a plain value") {
         BlockData<true,DATATYPE> b;
         b.length(1)
          .start(2)
          .valueType("a");
         CHECK(b.length() == 1);
         CHECK(b.start() == 2);
         CHECK(b.valueType() == "a");
      }
      THEN("It works for optional-with-value") {
         BlockData<true,DATATYPE> b;
         b.length(std::optional<std::size_t>(3))
          .start(std::optional<std::size_t>(4))
          .valueType(std::optional<std::string>("b"));
         CHECK(b.length() == 3);
         CHECK(b.start() == 4);
         CHECK(b.valueType() == "b");
      }
      THEN("It works for optional-without-value (remains unchanged)") {
         BlockData<true,DATATYPE> b;
         b.length(100).start(200).valueType("c");
         b.length(std::optional<std::size_t>(std::nullopt))
          .start(std::optional<std::size_t>(std::nullopt))
          .valueType(std::optional<std::string>(std::nullopt));
         CHECK(b.length() == 100);
         CHECK(b.start() == 200);
         CHECK(b.valueType() == "c");
      }
   }
}


// -----------------------------------------------------------------------------
// Scenarios
// -----------------------------------------------------------------------------

SCENARIO("BlockData<DATATYPE == void> length/start/valueType") {
   GIVEN("A default-constructed BlockData<true,void> object") {
      scenario_params<void>();
   }
}

SCENARIO("BlockData<DATATYPE != void> length/start/valueType") {
   GIVEN("A default-constructed BlockData<true,int> object") {
      scenario_params<int>();
   }
}
