
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// Scenario: get<vector>()
// -----------------------------------------------------------------------------

SCENARIO("BodyText get<vector>()") {

   GIVEN("A BodyText object") {

      // We'll deal with these vector types for the test. They should cover
      // sufficient cases (Integer32, Float64, string, and none of the above)
      // that we get good coverage, without this test being excessively long.
      using ivec = std::vector<Integer32>;
      using fvec = std::vector<Float64>;
      using svec = std::vector<std::string>;
      using uvec = std::vector<unsigned>;

      // We'll leave valueType at its default of "", which is compatible with
      // every possible get<T> type T. This simply means we won't get spammed
      // with warnings about the asked-for T possibly being incompatible with
      // valueType. Either way - with or without a "" for valueType - get<T>
      // gives us back a vector<T>.

      // ------------------------
      // vector<Integer32>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string("");
         CHECK((b.get<ivec>() == ivec{})); }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK((b.get<ivec>() == ivec{{0,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK((b.get<ivec>() == ivec{{0,0,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK((b.get<ivec>() == ivec{{0,0,0,0,0,0}})); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("-12");
         CHECK((b.get<ivec>() == ivec(1,-12))); }
      { BodyText<true> b; b.start(0).length(4).string("-12");
         CHECK((b.get<ivec>() == ivec{{-12,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("-12");
         CHECK((b.get<ivec>() == ivec{{0,-12,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("-12");
         CHECK((b.get<ivec>() == ivec{{0,0,-12,0,0,0}})); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("-12 34 -56");
         CHECK((b.get<ivec>() == ivec{{-12,34,-56}})); }
      { BodyText<true> b; b.start(0).length(4).string("-12 34 -56");
         CHECK((b.get<ivec>() == ivec{{-12,34,-56,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("-12 34 -56");
         CHECK((b.get<ivec>() == ivec{{0,-12,34,-56,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("-12 34 -56");
         CHECK((b.get<ivec>() == ivec{{0,0,-12,34,-56,0}})); }

      // ------------------------
      // vector<Float64>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string("");
         CHECK((b.get<fvec>() == fvec{})); }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK((b.get<fvec>() == fvec{{0,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK((b.get<fvec>() == fvec{{0,0,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK((b.get<fvec>() == fvec{{0,0,0,0,0,0}})); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("1.2");
         CHECK((b.get<fvec>() == fvec(1,1.2))); }
      { BodyText<true> b; b.start(0).length(4).string("1.2");
         CHECK((b.get<fvec>() == fvec{{1.2,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("1.2");
         CHECK((b.get<fvec>() == fvec{{0,1.2,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("1.2");
         CHECK((b.get<fvec>() == fvec{{0,0,1.2,0,0,0}})); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("1.2 3.4 5.6");
         CHECK((b.get<fvec>() == fvec{{1.2,3.4,5.6}})); }
      { BodyText<true> b; b.start(0).length(4).string("1.2 3.4 5.6");
         CHECK((b.get<fvec>() == fvec{{1.2,3.4,5.6,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("1.2 3.4 5.6");
         CHECK((b.get<fvec>() == fvec{{0,1.2,3.4,5.6,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("1.2 3.4 5.6");
         CHECK((b.get<fvec>() == fvec{{0,0,1.2,3.4,5.6,0}})); }

      // ------------------------
      // vector<std::string>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string("");
         CHECK((b.get<svec>() == svec{})); }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK((b.get<svec>() == svec{{"","","",""}})); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK((b.get<svec>() == svec{{"","","","",""}})); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK((b.get<svec>() == svec{{"","","","","",""}})); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("ab");
         CHECK((b.get<svec>() == svec(1,"ab"))); }
      { BodyText<true> b; b.start(0).length(4).string("ab");
         CHECK((b.get<svec>() == svec{{"ab","","",""}})); }
      { BodyText<true> b; b.start(1).length(5).string("ab");
         CHECK((b.get<svec>() == svec{{"","ab","","",""}})); }
      { BodyText<true> b; b.start(2).length(6).string("ab");
         CHECK((b.get<svec>() == svec{{"","","ab","","",""}})); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("ab cd ef");
         CHECK((b.get<svec>() == svec{{"ab","cd","ef"}})); }
      { BodyText<true> b; b.start(0).length(4).string("ab cd ef");
         CHECK((b.get<svec>() == svec{{"ab","cd","ef",""}})); }
      { BodyText<true> b; b.start(1).length(5).string("ab cd ef");
         CHECK((b.get<svec>() == svec{{"","ab","cd","ef",""}})); }
      { BodyText<true> b; b.start(2).length(6).string("ab cd ef");
         CHECK((b.get<svec>() == svec{{"","","ab","cd","ef",""}})); }

      // ------------------------
      // vector<unsigned>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string("");
         CHECK((b.get<uvec>() == uvec{})); }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK((b.get<uvec>() == uvec{{0,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK((b.get<uvec>() == uvec{{0,0,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK((b.get<uvec>() == uvec{{0,0,0,0,0,0}})); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("12");
         CHECK((b.get<uvec>() == uvec(1,12))); }
      { BodyText<true> b; b.start(0).length(4).string("12");
         CHECK((b.get<uvec>() == uvec{{12,0,0,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("12");
         CHECK((b.get<uvec>() == uvec{{0,12,0,0,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("12");
         CHECK((b.get<uvec>() == uvec{{0,0,12,0,0,0}})); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("12 34 56");
         CHECK((b.get<uvec>() == uvec{{12,34,56}})); }
      { BodyText<true> b; b.start(0).length(4).string("12 34 56");
         CHECK((b.get<uvec>() == uvec{{12,34,56,0}})); }
      { BodyText<true> b; b.start(1).length(5).string("12 34 56");
         CHECK((b.get<uvec>() == uvec{{0,12,34,56,0}})); }
      { BodyText<true> b; b.start(2).length(6).string("12 34 56");
         CHECK((b.get<uvec>() == uvec{{0,0,12,34,56,0}})); }

   } // GIVEN

} // SCENARIO



// -----------------------------------------------------------------------------
// Scenario: get<T>(n)
// -----------------------------------------------------------------------------

SCENARIO("BodyText get<T>(n)") {

   GIVEN("A BodyText object") {

      using ivec = std::vector<Integer32>;
      using fvec = std::vector<Float64>;
      using svec = std::vector<std::string>;

      // ------------------------
      // vector<Integer32>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string(""); /* no elements */ }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK(b.get<Integer32>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK(b.get<Integer32>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK(b.get<Integer32>(3) == 0); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("-12");
         CHECK(b.get<Integer32>(0) == -12); }
      { BodyText<true> b; b.start(0).length(4).string("-12");
         CHECK(b.get<Integer32>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("-12");
         CHECK(b.get<Integer32>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("-12");
         CHECK(b.get<Integer32>(3) == 0); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("-12 34 -56");
         CHECK(b.get<Integer32>(0) == -12); }
      { BodyText<true> b; b.start(0).length(4).string("-12 34 -56");
         CHECK(b.get<Integer32>(1) == 34); }
      { BodyText<true> b; b.start(1).length(5).string("-12 34 -56");
         CHECK(b.get<Integer32>(2) == 34); }
      { BodyText<true> b; b.start(2).length(6).string("-12 34 -56");
         CHECK(b.get<Integer32>(3) == 34); }

      // ------------------------
      // vector<Float64>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string(""); /* no elements */ }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK(b.get<Float64>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK(b.get<Float64>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK(b.get<Float64>(3) == 0); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("1.2");
         CHECK(b.get<Float64>(0) == 1.2); }
      { BodyText<true> b; b.start(0).length(4).string("1.2");
         CHECK(b.get<Float64>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("1.2");
         CHECK(b.get<Float64>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("1.2");
         CHECK(b.get<Float64>(3) == 0); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("1.2 3.4 5.6");
         CHECK(b.get<Float64>(0) == 1.2); }
      { BodyText<true> b; b.start(0).length(4).string("1.2 3.4 5.6");
         CHECK(b.get<Float64>(1) == 3.4); }
      { BodyText<true> b; b.start(1).length(5).string("1.2 3.4 5.6");
         CHECK(b.get<Float64>(2) == 3.4); }
      { BodyText<true> b; b.start(2).length(6).string("1.2 3.4 5.6");
         CHECK(b.get<Float64>(3) == 3.4); }

      // ------------------------
      // vector<std::string>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string(""); /* no elements */ }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK(b.get<std::string>(1) == ""); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK(b.get<std::string>(2) == ""); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK(b.get<std::string>(3) == ""); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("ab");
         CHECK(b.get<std::string>(0) == "ab"); }
      { BodyText<true> b; b.start(0).length(4).string("ab");
         CHECK(b.get<std::string>(1) == ""); }
      { BodyText<true> b; b.start(1).length(5).string("ab");
         CHECK(b.get<std::string>(2) == ""); }
      { BodyText<true> b; b.start(2).length(6).string("ab");
         CHECK(b.get<std::string>(3) == ""); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("ab cd ef");
         CHECK(b.get<std::string>(0) == "ab"); }
      { BodyText<true> b; b.start(0).length(4).string("ab cd ef");
         CHECK(b.get<std::string>(1) == "cd"); }
      { BodyText<true> b; b.start(1).length(5).string("ab cd ef");
         CHECK(b.get<std::string>(2) == "cd"); }
      { BodyText<true> b; b.start(2).length(6).string("ab cd ef");
         CHECK(b.get<std::string>(3) == "cd"); }

      // ------------------------
      // vector<unsigned>
      // ------------------------

      // 0 elements in string
      { BodyText<true> b; b.start(0).length(0).string(""); /* no elements */ }
      { BodyText<true> b; b.start(0).length(4).string("");
         CHECK(b.get<unsigned>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("");
         CHECK(b.get<unsigned>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("");
         CHECK(b.get<unsigned>(3) == 0); }

      // 1 element in string
      { BodyText<true> b; b.start(0).length(0).string("12");
         CHECK(b.get<unsigned>(0) == 12); }
      { BodyText<true> b; b.start(0).length(4).string("12");
         CHECK(b.get<unsigned>(1) == 0); }
      { BodyText<true> b; b.start(1).length(5).string("12");
         CHECK(b.get<unsigned>(2) == 0); }
      { BodyText<true> b; b.start(2).length(6).string("12");
         CHECK(b.get<unsigned>(3) == 0); }

      // 3 elements in string
      { BodyText<true> b; b.start(0).length(0).string("12 34 56");
         CHECK(b.get<unsigned>(0) == 12); }
      { BodyText<true> b; b.start(0).length(4).string("12 34 56");
         CHECK(b.get<unsigned>(1) == 34); }
      { BodyText<true> b; b.start(1).length(5).string("12 34 56");
         CHECK(b.get<unsigned>(2) == 34); }
      { BodyText<true> b; b.start(2).length(6).string("12 34 56");
         CHECK(b.get<unsigned>(3) == 34); }

   } // GIVEN

} // SCENARIO



// -----------------------------------------------------------------------------
// Scenario: get()
// -----------------------------------------------------------------------------

SCENARIO("BodyText get()") {

   GIVEN("A BodyText object") {

      using ivec = std::vector<Integer32>;
      using fvec = std::vector<Float64>;
      using svec = std::vector<std::string>;

      BodyText<true> b;

      b.start(2).length(6).string("-12 34 -56");
      b.valueType("Integer32");
      CHECK(( std::holds_alternative<ivec>(b.get())));
      CHECK((!std::holds_alternative<fvec>(b.get())));
      CHECK((!std::holds_alternative<svec>(b.get())));
      CHECK((std::get<ivec>(b.get()) == ivec{{0,0,-12,34,-56,0}}));

      b.start(2).length(6).string("1.2 3.4 5.6");
      b.valueType("Float64");
      CHECK((!std::holds_alternative<ivec>(b.get())));
      CHECK(( std::holds_alternative<fvec>(b.get())));
      CHECK((!std::holds_alternative<svec>(b.get())));
      CHECK((std::get<fvec>(b.get()) == fvec{{0,0,1.2,3.4,5.6,0}}));

      b.start(2).length(6).string("ab cd ef");
      b.valueType("");
      CHECK((!std::holds_alternative<ivec>(b.get())));
      CHECK((!std::holds_alternative<fvec>(b.get())));
      CHECK(( std::holds_alternative<svec>(b.get())));
      CHECK((std::get<svec>(b.get()) == svec{{"","","ab","cd","ef",""}}));

   } // GIVEN

} // SCENARIO



// -----------------------------------------------------------------------------
// Scenario: get(n)
// -----------------------------------------------------------------------------

SCENARIO("BodyText get(n)") {

   GIVEN("A BodyText object") {

      BodyText<true> b;

      // ------------------------
      // get(n) form
      // ------------------------

      b.start(2).length(6).string("-12 34 -56");
      b.valueType("Integer32");
      CHECK(( std::holds_alternative<Integer32>(b.get(0))));
      CHECK((!std::holds_alternative<Float64>(b.get(0))));
      CHECK((!std::holds_alternative<std::string>(b.get(0))));
      CHECK(( std::get<Integer32>( b.get(0) ) ==   0 ));
      CHECK(( std::get<Integer32>( b.get(1) ) ==   0 ));
      CHECK(( std::get<Integer32>( b.get(2) ) == -12 ));
      CHECK(( std::get<Integer32>( b.get(3) ) ==  34 ));
      CHECK(( std::get<Integer32>( b.get(4) ) == -56 ));
      CHECK(( std::get<Integer32>( b.get(5) ) ==   0 ));
      // test type changes (inefficient, but they work)...
      CHECK(b.get<long>(2) == -12);
      CHECK(b.get<double>(3) == double(34));
      CHECK(b.get<std::string>(4) == "-56");

      b.start(2).length(6).string("1.2 3.4 5.6");
      b.valueType("Float64");
      CHECK((!std::holds_alternative<Integer32>(b.get(0))));
      CHECK(( std::holds_alternative<Float64>(b.get(0))));
      CHECK((!std::holds_alternative<std::string>(b.get(0))));
      CHECK(( std::get<Float64>( b.get(0) ) == 0   ));
      CHECK(( std::get<Float64>( b.get(1) ) == 0   ));
      CHECK(( std::get<Float64>( b.get(2) ) == 1.2 ));
      CHECK(( std::get<Float64>( b.get(3) ) == 3.4 ));
      CHECK(( std::get<Float64>( b.get(4) ) == 5.6 ));
      CHECK(( std::get<Float64>( b.get(5) ) == 0   ));
      // test type changes...
      CHECK(b.get<long>(2) == 1); // truncated from 1.2
      // having converted to vector<long>, the .#s aren't there any longer...
      CHECK(b.get<std::string>(2) == "1");
      CHECK(b.get<double>(3) == 3);
      CHECK(b.get<std::string>(4) == "5");

      b.start(2).length(8).string("ab cd ef 123 4.5");
      b.valueType("");
      CHECK((!std::holds_alternative<Integer32>(b.get(0))));
      CHECK((!std::holds_alternative<Float64>(b.get(0))));
      CHECK(( std::holds_alternative<std::string>(b.get(0))));
      CHECK(( std::get<std::string>( b.get(0) ) == ""   ));
      CHECK(( std::get<std::string>( b.get(1) ) == ""   ));
      CHECK(( std::get<std::string>( b.get(2) ) == "ab" ));
      CHECK(( std::get<std::string>( b.get(3) ) == "cd" ));
      CHECK(( std::get<std::string>( b.get(4) ) == "ef" ));
      CHECK(( std::get<std::string>( b.get(5) ) == "123"));
      CHECK(( std::get<std::string>( b.get(6) ) == "4.5"));
      CHECK(( std::get<std::string>( b.get(7) ) == ""   ));

      // ------------------------
      // operator[] form
      // ------------------------

      b.start(2).length(6).string("-12 34 -56");
      b.valueType("Integer32");
      CHECK(( std::holds_alternative<Integer32>(b[0])));
      CHECK((!std::holds_alternative<Float64>(b[0])));
      CHECK((!std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<Integer32>( b[0] ) ==   0 ));
      CHECK(( std::get<Integer32>( b[1] ) ==   0 ));
      CHECK(( std::get<Integer32>( b[2] ) == -12 ));
      CHECK(( std::get<Integer32>( b[3] ) ==  34 ));
      CHECK(( std::get<Integer32>( b[4] ) == -56 ));
      CHECK(( std::get<Integer32>( b[5] ) ==   0 ));

      b.start(2).length(6).string("1.2 3.4 5.6");
      b.valueType("Float64");
      CHECK((!std::holds_alternative<Integer32>(b[0])));
      CHECK(( std::holds_alternative<Float64>(b[0])));
      CHECK((!std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<Float64>( b[0] ) == 0   ));
      CHECK(( std::get<Float64>( b[1] ) == 0   ));
      CHECK(( std::get<Float64>( b[2] ) == 1.2 ));
      CHECK(( std::get<Float64>( b[3] ) == 3.4 ));
      CHECK(( std::get<Float64>( b[4] ) == 5.6 ));
      CHECK(( std::get<Float64>( b[5] ) == 0   ));

      b.start(2).length(6).string("ab cd ef");
      b.valueType("");
      CHECK((!std::holds_alternative<Integer32>(b[0])));
      CHECK((!std::holds_alternative<Float64>(b[0])));
      CHECK(( std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<std::string>( b[0] ) == ""   ));
      CHECK(( std::get<std::string>( b[1] ) == ""   ));
      CHECK(( std::get<std::string>( b[2] ) == "ab" ));
      CHECK(( std::get<std::string>( b[3] ) == "cd" ));
      CHECK(( std::get<std::string>( b[4] ) == "ef" ));
      CHECK(( std::get<std::string>( b[5] ) == ""   ));

   } // GIVEN

} // SCENARIO



// -----------------------------------------------------------------------------
// Scenario: doubles() etc.
// -----------------------------------------------------------------------------

SCENARIO("BodyText type-specific get functions: doubles() etc.") {

   GIVEN("A BodyText object") {

      BodyText<true> b;

      // ------------------------
      // get(n) form
      // ------------------------

      b.start(2).length(6).string("-12 34 -56");
      auto ints = b.ints();
      CHECK((std::is_same_v<decltype(ints),
             std::vector<int>>));

      CHECK(ints[0] ==   0 );
      CHECK(ints[1] ==   0 );
      CHECK(ints[2] == -12 );
      CHECK(ints[3] ==  34 );
      CHECK(ints[4] == -56 );
      CHECK(ints[5] ==   0 );

      CHECK(ints[0] == b.ints(0) );
      CHECK(ints[1] == b.ints(1) );
      CHECK(ints[2] == b.ints(2) );
      CHECK(ints[3] == b.ints(3) );
      CHECK(ints[4] == b.ints(4) );
      CHECK(ints[5] == b.ints(5) );

      b.start(2).length(6).string("1.2 3.4 5.6");
      const auto doubles = b.doubles();
      CHECK((std::is_same_v<decltype(doubles),
             const std::vector<double>>));

      CHECK(doubles[0] == 0   );
      CHECK(doubles[1] == 0   );
      CHECK(doubles[2] == 1.2 );
      CHECK(doubles[3] == 3.4 );
      CHECK(doubles[4] == 5.6 );
      CHECK(doubles[5] == 0   );

      CHECK(doubles[0] == b.doubles(0) );
      CHECK(doubles[1] == b.doubles(1) );
      CHECK(doubles[2] == b.doubles(2) );
      CHECK(doubles[3] == b.doubles(3) );
      CHECK(doubles[4] == b.doubles(4) );
      CHECK(doubles[5] == b.doubles(5) );

      b.start(2).length(6).string("ab cd ef");
      const auto &strings = b.strings();
      CHECK((std::is_same_v<decltype(strings),
             const std::vector<std::string> &>));

      CHECK(strings[0] == ""   );
      CHECK(strings[1] == ""   );
      CHECK(strings[2] == "ab" );
      CHECK(strings[3] == "cd" );
      CHECK(strings[4] == "ef" );
      CHECK(strings[5] == ""   );

      CHECK(strings[0] == b.strings(0) );
      CHECK(strings[1] == b.strings(1) );
      CHECK(strings[2] == b.strings(2) );
      CHECK(strings[3] == b.strings(3) );
      CHECK(strings[4] == b.strings(4) );
      CHECK(strings[5] == b.strings(5) );

   } // GIVEN

} // SCENARIO
