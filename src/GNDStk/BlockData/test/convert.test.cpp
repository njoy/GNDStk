
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("BlockData<DATATYPE != void> conversion to vector<DATATYPE>") {
   GIVEN("A BlockData object") {

      {
         using T = int;
         BlockData<true,T> b;
         b.start(2).length(6).string("-12 34 -56");
         std::vector<T> myVector = b;
         CHECK(myVector.size() == 6);
         CHECK(myVector[0] ==   0);
         CHECK(myVector[1] ==   0);
         CHECK(myVector[2] == -12);
         CHECK(myVector[3] ==  34);
         CHECK(myVector[4] == -56);
         CHECK(myVector[5] ==   0);
      }

      {
         using T = double;
         BlockData<true,T> b;
         b.start(2).length(6).string("1.2 3.4 5.6");
         std::vector<T> myVector = b;
         CHECK(myVector.size() == 6);
         CHECK(myVector[0] == 0);
         CHECK(myVector[1] == 0);
         CHECK(myVector[2] == 1.2);
         CHECK(myVector[3] == 3.4);
         CHECK(myVector[4] == 5.6);
         CHECK(myVector[5] == 0);
      }

      {
         using T = std::string;
         BlockData<true,T> b;
         b.start(2).length(6).string("ab cd ef");
         std::vector<T> myVector = b;
         CHECK(myVector.size() == 6);
         CHECK(myVector[0] == "");
         CHECK(myVector[1] == "");
         CHECK(myVector[2] == "ab");
         CHECK(myVector[3] == "cd");
         CHECK(myVector[4] == "ef");
         CHECK(myVector[5] == "");
      }

   } // GIVEN
} // SCENARIO
