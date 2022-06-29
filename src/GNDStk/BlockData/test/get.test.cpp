
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// 1. Scenario: get<vector>()
// -----------------------------------------------------------------------------

// Helper
template<class INTEGER, class FLOAT, class STRING, class UNSIGNED>
void scenario_get_vector()
{
   // We'll deal with these vector types for the test. They should cover
   // sufficient cases (int, double, string, and none of the above)
   // that we get good coverage, without this test being excessively long.
   using ivec = std::vector<int>;
   using fvec = std::vector<double>;
   using svec = std::vector<std::string>;
   using uvec = std::vector<unsigned>;

   // We'll leave valueType at its default of "", which is compatible with
   // every possible get<T> type T. This simply means we won't get spammed
   // with warnings about the asked-for T possibly being incompatible with
   // valueType. Either way - with or without a "" for valueType - get<T>
   // gives us back a vector<T>.

   // ------------------------
   // vector<int>
   // ------------------------

   // 0 elements in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string("");
      CHECK((b.template get<ivec>() == ivec{})); }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("");
      CHECK((b.template get<ivec>() == ivec{{0,0,0,0}})); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("");
      CHECK((b.template get<ivec>() == ivec{{0,0,0,0,0}})); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("");
      CHECK((b.template get<ivec>() == ivec{{0,0,0,0,0,0}})); }

   // 1 element in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string("-12");
      CHECK((b.template get<ivec>() == ivec(1,-12))); }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("-12");
      CHECK((b.template get<ivec>() == ivec{{-12,0,0,0}})); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("-12");
      CHECK((b.template get<ivec>() == ivec{{0,-12,0,0,0}})); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("-12");
      CHECK((b.template get<ivec>() == ivec{{0,0,-12,0,0,0}})); }

   // 3 elements in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string("-12 34 -56");
      CHECK((b.template get<ivec>() == ivec{{-12,34,-56}})); }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("-12 34 -56");
      CHECK((b.template get<ivec>() == ivec{{-12,34,-56,0}})); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("-12 34 -56");
      CHECK((b.template get<ivec>() == ivec{{0,-12,34,-56,0}})); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("-12 34 -56");
      CHECK((b.template get<ivec>() == ivec{{0,0,-12,34,-56,0}})); }

   // ------------------------
   // vector<double>
   // ------------------------

   // 0 elements in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string("");
      CHECK((b.template get<fvec>() == fvec{})); }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("");
      CHECK((b.template get<fvec>() == fvec{{0,0,0,0}})); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("");
      CHECK((b.template get<fvec>() == fvec{{0,0,0,0,0}})); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("");
      CHECK((b.template get<fvec>() == fvec{{0,0,0,0,0,0}})); }

   // 1 element in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string("1.2");
      CHECK((b.template get<fvec>() == fvec(1,1.2))); }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("1.2");
      CHECK((b.template get<fvec>() == fvec{{1.2,0,0,0}})); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("1.2");
      CHECK((b.template get<fvec>() == fvec{{0,1.2,0,0,0}})); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("1.2");
      CHECK((b.template get<fvec>() == fvec{{0,0,1.2,0,0,0}})); }

   // 3 elements in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string("1.2 3.4 5.6");
      CHECK((b.template get<fvec>() == fvec{{1.2,3.4,5.6}})); }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("1.2 3.4 5.6");
      CHECK((b.template get<fvec>() == fvec{{1.2,3.4,5.6,0}})); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("1.2 3.4 5.6");
      CHECK((b.template get<fvec>() == fvec{{0,1.2,3.4,5.6,0}})); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("1.2 3.4 5.6");
      CHECK((b.template get<fvec>() == fvec{{0,0,1.2,3.4,5.6,0}})); }

   // ------------------------
   // vector<std::string>
   // ------------------------

   // 0 elements in string
   { BlockData<true,STRING> b; b.start(0).length(0).string("");
      CHECK((b.template get<svec>() == svec{})); }
   { BlockData<true,STRING> b; b.start(0).length(4).string("");
      CHECK((b.template get<svec>() == svec{{"","","",""}})); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("");
      CHECK((b.template get<svec>() == svec{{"","","","",""}})); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("");
      CHECK((b.template get<svec>() == svec{{"","","","","",""}})); }

   // 1 element in string
   { BlockData<true,STRING> b; b.start(0).length(0).string("ab");
      CHECK((b.template get<svec>() == svec(1,"ab"))); }
   { BlockData<true,STRING> b; b.start(0).length(4).string("ab");
      CHECK((b.template get<svec>() == svec{{"ab","","",""}})); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("ab");
      CHECK((b.template get<svec>() == svec{{"","ab","","",""}})); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("ab");
      CHECK((b.template get<svec>() == svec{{"","","ab","","",""}})); }

   // 3 elements in string
   { BlockData<true,STRING> b; b.start(0).length(0).string("ab cd ef");
      CHECK((b.template get<svec>() == svec{{"ab","cd","ef"}})); }
   { BlockData<true,STRING> b; b.start(0).length(4).string("ab cd ef");
      CHECK((b.template get<svec>() == svec{{"ab","cd","ef",""}})); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("ab cd ef");
      CHECK((b.template get<svec>() == svec{{"","ab","cd","ef",""}})); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("ab cd ef");
      CHECK((b.template get<svec>() == svec{{"","","ab","cd","ef",""}})); }

   // ------------------------
   // vector<unsigned>
   // ------------------------

   // 0 elements in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string("");
      CHECK((b.template get<uvec>() == uvec{})); }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("");
      CHECK((b.template get<uvec>() == uvec{{0,0,0,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("");
      CHECK((b.template get<uvec>() == uvec{{0,0,0,0,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("");
      CHECK((b.template get<uvec>() == uvec{{0,0,0,0,0,0}})); }

   // 1 element in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string("12");
      CHECK((b.template get<uvec>() == uvec(1,12))); }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("12");
      CHECK((b.template get<uvec>() == uvec{{12,0,0,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("12");
      CHECK((b.template get<uvec>() == uvec{{0,12,0,0,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("12");
      CHECK((b.template get<uvec>() == uvec{{0,0,12,0,0,0}})); }

   // 3 elements in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string("12 34 56");
      CHECK((b.template get<uvec>() == uvec{{12,34,56}})); }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("12 34 56");
      CHECK((b.template get<uvec>() == uvec{{12,34,56,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("12 34 56");
      CHECK((b.template get<uvec>() == uvec{{0,12,34,56,0}})); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("12 34 56");
      CHECK((b.template get<uvec>() == uvec{{0,0,12,34,56,0}})); }
}

// For BlockData<DATATYPE == void>
SCENARIO("BlockData<DATATYPE == void> get<vector>()") {
   GIVEN("A BlockData object") {
      scenario_get_vector<void,void,void,void>();
   }
}

// For BlockData<DATATYPE != void>
SCENARIO("BlockData<DATATYPE != void> get<vector>()") {
   GIVEN("A BlockData object") {
      scenario_get_vector<int,double,std::string,unsigned>();
   }
}



// -----------------------------------------------------------------------------
// 2. Scenario: get<T>(n)
// -----------------------------------------------------------------------------

// Helper
template<class INTEGER, class FLOAT, class STRING, class UNSIGNED>
void scenario_get_template_n()
{
   // ------------------------
   // vector<int>
   // ------------------------

   // 0 elements in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string(""); /* no elements */ }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("");
      CHECK(b.template get<int>(1) == 0); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("");
      CHECK(b.template get<int>(2) == 0); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("");
      CHECK(b.template get<int>(3) == 0); }

   // 1 element in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string("-12");
      CHECK(b.template get<int>(0) == -12); }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("-12");
      CHECK(b.template get<int>(1) == 0); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("-12");
      CHECK(b.template get<int>(2) == 0); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("-12");
      CHECK(b.template get<int>(3) == 0); }

   // 3 elements in string
   { BlockData<true,INTEGER> b; b.start(0).length(0).string("-12 34 -56");
      CHECK(b.template get<int>(0) == -12); }
   { BlockData<true,INTEGER> b; b.start(0).length(4).string("-12 34 -56");
      CHECK(b.template get<int>(1) == 34); }
   { BlockData<true,INTEGER> b; b.start(1).length(5).string("-12 34 -56");
      CHECK(b.template get<int>(2) == 34); }
   { BlockData<true,INTEGER> b; b.start(2).length(6).string("-12 34 -56");
      CHECK(b.template get<int>(3) == 34); }

   // ------------------------
   // vector<double>
   // ------------------------

   // 0 elements in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string(""); /* no elements */ }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("");
      CHECK(b.template get<double>(1) == 0); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("");
      CHECK(b.template get<double>(2) == 0); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("");
      CHECK(b.template get<double>(3) == 0); }

   // 1 element in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string("1.2");
      CHECK(b.template get<double>(0) == 1.2); }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("1.2");
      CHECK(b.template get<double>(1) == 0); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("1.2");
      CHECK(b.template get<double>(2) == 0); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("1.2");
      CHECK(b.template get<double>(3) == 0); }

   // 3 elements in string
   { BlockData<true,FLOAT> b; b.start(0).length(0).string("1.2 3.4 5.6");
      CHECK(b.template get<double>(0) == 1.2); }
   { BlockData<true,FLOAT> b; b.start(0).length(4).string("1.2 3.4 5.6");
      CHECK(b.template get<double>(1) == 3.4); }
   { BlockData<true,FLOAT> b; b.start(1).length(5).string("1.2 3.4 5.6");
      CHECK(b.template get<double>(2) == 3.4); }
   { BlockData<true,FLOAT> b; b.start(2).length(6).string("1.2 3.4 5.6");
      CHECK(b.template get<double>(3) == 3.4); }

   // ------------------------
   // vector<std::string>
   // ------------------------

   // 0 elements in string
   { BlockData<true,STRING> b; b.start(0).length(0).string(""); /* no elements */ }
   { BlockData<true,STRING> b; b.start(0).length(4).string("");
      CHECK(b.template get<std::string>(1) == ""); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("");
      CHECK(b.template get<std::string>(2) == ""); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("");
      CHECK(b.template get<std::string>(3) == ""); }

   // 1 element in string
   { BlockData<true,STRING> b; b.start(0).length(0).string("ab");
      CHECK(b.template get<std::string>(0) == "ab"); }
   { BlockData<true,STRING> b; b.start(0).length(4).string("ab");
      CHECK(b.template get<std::string>(1) == ""); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("ab");
      CHECK(b.template get<std::string>(2) == ""); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("ab");
      CHECK(b.template get<std::string>(3) == ""); }

   // 3 elements in string
   { BlockData<true,STRING> b; b.start(0).length(0).string("ab cd ef");
      CHECK(b.template get<std::string>(0) == "ab"); }
   { BlockData<true,STRING> b; b.start(0).length(4).string("ab cd ef");
      CHECK(b.template get<std::string>(1) == "cd"); }
   { BlockData<true,STRING> b; b.start(1).length(5).string("ab cd ef");
      CHECK(b.template get<std::string>(2) == "cd"); }
   { BlockData<true,STRING> b; b.start(2).length(6).string("ab cd ef");
      CHECK(b.template get<std::string>(3) == "cd"); }

   // ------------------------
   // vector<unsigned>
   // ------------------------

   // 0 elements in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string(""); /* no elements */ }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("");
      CHECK(b.template get<unsigned>(1) == 0); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("");
      CHECK(b.template get<unsigned>(2) == 0); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("");
      CHECK(b.template get<unsigned>(3) == 0); }

   // 1 element in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string("12");
      CHECK(b.template get<unsigned>(0) == 12); }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("12");
      CHECK(b.template get<unsigned>(1) == 0); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("12");
      CHECK(b.template get<unsigned>(2) == 0); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("12");
      CHECK(b.template get<unsigned>(3) == 0); }

   // 3 elements in string
   { BlockData<true,UNSIGNED> b; b.start(0).length(0).string("12 34 56");
      CHECK(b.template get<unsigned>(0) == 12); }
   { BlockData<true,UNSIGNED> b; b.start(0).length(4).string("12 34 56");
      CHECK(b.template get<unsigned>(1) == 34); }
   { BlockData<true,UNSIGNED> b; b.start(1).length(5).string("12 34 56");
      CHECK(b.template get<unsigned>(2) == 34); }
   { BlockData<true,UNSIGNED> b; b.start(2).length(6).string("12 34 56");
      CHECK(b.template get<unsigned>(3) == 34); }
}

// For BlockData<DATATYPE == void>
SCENARIO("BlockData<DATATYPE == void> get<T>(n)") {
   GIVEN("A BlockData object") {
      scenario_get_template_n<void,void,void,void>();
   }
}

// For BlockData<DATATYPE != void>
SCENARIO("BlockData<DATATYPE != void> get<T>(n)") {
   GIVEN("A BlockData object") {
      scenario_get_template_n<int,double,std::string,unsigned>();
   }
}



// -----------------------------------------------------------------------------
// 3. Scenario: get()
// -----------------------------------------------------------------------------

// For BlockData<DATATYPE == void>
SCENARIO("BlockData<DATATYPE == void> get()") {
   GIVEN("A BlockData object") {

      using ivec = std::vector<int>;
      using fvec = std::vector<double>;
      using svec = std::vector<std::string>;

      BlockData<true,void> b;

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


// For BlockData<DATATYPE != void>
SCENARIO("BlockData<DATATYPE != void> get()") {
   GIVEN("A BlockData object") {

      using ivec = std::vector<int>;
      using fvec = std::vector<double>;
      using svec = std::vector<std::string>;

      {
         BlockData<true,int> b;
         b.start(2).length(6).string("-12 34 -56");
         CHECK((b.get() == ivec{{0,0,-12,34,-56,0}}));
      }

      {
         BlockData<true,double> b;
         b.start(2).length(6).string("1.2 3.4 5.6");
         CHECK((b.get() == fvec{{0,0,1.2,3.4,5.6,0}}));
      }

      {
         BlockData<true,std::string> b;
         b.start(2).length(6).string("ab cd ef");
         CHECK((b.get() == svec{{"","","ab","cd","ef",""}}));
      }

   } // GIVEN
} // SCENARIO



// -----------------------------------------------------------------------------
// 4. Scenario: get(n)
// -----------------------------------------------------------------------------

// For BlockData<DATATYPE == void>
SCENARIO("BlockData<DATATYPE == void> get(n)") {
   GIVEN("A BlockData object") {

      BlockData<true,void> b;

      // ------------------------
      // get(n) form
      // ------------------------

      b.start(2).length(6).string("-12 34 -56");
      b.valueType("Integer32");
      CHECK(( std::holds_alternative<int>(b.get(0))));
      CHECK((!std::holds_alternative<double>(b.get(0))));
      CHECK((!std::holds_alternative<std::string>(b.get(0))));
      CHECK(( std::get<int>( b.get(0) ) ==   0 ));
      CHECK(( std::get<int>( b.get(1) ) ==   0 ));
      CHECK(( std::get<int>( b.get(2) ) == -12 ));
      CHECK(( std::get<int>( b.get(3) ) ==  34 ));
      CHECK(( std::get<int>( b.get(4) ) == -56 ));
      CHECK(( std::get<int>( b.get(5) ) ==   0 ));
      // test type changes (inefficient, but they work)...
      CHECK(b.get<long>(2) == -12);
      CHECK(b.get<double>(3) == double(34));
      CHECK(b.get<std::string>(4) == "-56");

      b.start(2).length(6).string("1.2 3.4 5.6");
      b.valueType("Float64");
      CHECK((!std::holds_alternative<int>(b.get(0))));
      CHECK(( std::holds_alternative<double>(b.get(0))));
      CHECK((!std::holds_alternative<std::string>(b.get(0))));
      CHECK(( std::get<double>( b.get(0) ) == 0   ));
      CHECK(( std::get<double>( b.get(1) ) == 0   ));
      CHECK(( std::get<double>( b.get(2) ) == 1.2 ));
      CHECK(( std::get<double>( b.get(3) ) == 3.4 ));
      CHECK(( std::get<double>( b.get(4) ) == 5.6 ));
      CHECK(( std::get<double>( b.get(5) ) == 0   ));
      // test type changes...
      CHECK(b.get<long>(2) == 1); // truncated from 1.2
      // having converted to vector<long>, the .#s aren't there any longer...
      CHECK(b.get<std::string>(2) == "1");
      CHECK(b.get<double>(3) == 3);
      CHECK(b.get<std::string>(4) == "5");

      b.start(2).length(8).string("ab cd ef 123 4.5");
      b.valueType("");
      CHECK((!std::holds_alternative<int>(b.get(0))));
      CHECK((!std::holds_alternative<double>(b.get(0))));
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
      CHECK(( std::holds_alternative<int>(b[0])));
      CHECK((!std::holds_alternative<double>(b[0])));
      CHECK((!std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<int>( b[0] ) ==   0 ));
      CHECK(( std::get<int>( b[1] ) ==   0 ));
      CHECK(( std::get<int>( b[2] ) == -12 ));
      CHECK(( std::get<int>( b[3] ) ==  34 ));
      CHECK(( std::get<int>( b[4] ) == -56 ));
      CHECK(( std::get<int>( b[5] ) ==   0 ));

      b.start(2).length(6).string("1.2 3.4 5.6");
      b.valueType("Float64");
      CHECK((!std::holds_alternative<int>(b[0])));
      CHECK(( std::holds_alternative<double>(b[0])));
      CHECK((!std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<double>( b[0] ) == 0   ));
      CHECK(( std::get<double>( b[1] ) == 0   ));
      CHECK(( std::get<double>( b[2] ) == 1.2 ));
      CHECK(( std::get<double>( b[3] ) == 3.4 ));
      CHECK(( std::get<double>( b[4] ) == 5.6 ));
      CHECK(( std::get<double>( b[5] ) == 0   ));

      b.start(2).length(6).string("ab cd ef");
      b.valueType("");
      CHECK((!std::holds_alternative<int>(b[0])));
      CHECK((!std::holds_alternative<double>(b[0])));
      CHECK(( std::holds_alternative<std::string>(b[0])));
      CHECK(( std::get<std::string>( b[0] ) == ""   ));
      CHECK(( std::get<std::string>( b[1] ) == ""   ));
      CHECK(( std::get<std::string>( b[2] ) == "ab" ));
      CHECK(( std::get<std::string>( b[3] ) == "cd" ));
      CHECK(( std::get<std::string>( b[4] ) == "ef" ));
      CHECK(( std::get<std::string>( b[5] ) == ""   ));

   } // GIVEN
} // SCENARIO


// For BlockData<DATATYPE != void>
SCENARIO("BlockData<DATATYPE != void> get(n)") {
   GIVEN("A BlockData object") {

      // ------------------------
      // get(n) form
      // ------------------------

      {
         BlockData<true,int> b;
         b.start(2).length(6).string("-12 34 -56");
         CHECK(( b.get(0) ==   0 ));
         CHECK(( b.get(1) ==   0 ));
         CHECK(( b.get(2) == -12 ));
         CHECK(( b.get(3) ==  34 ));
         CHECK(( b.get(4) == -56 ));
         CHECK(( b.get(5) ==   0 ));
      }

      {
         BlockData<true,double> b;
         b.start(2).length(6).string("1.2 3.4 5.6");
         CHECK(( b.get(0) == 0   ));
         CHECK(( b.get(1) == 0   ));
         CHECK(( b.get(2) == 1.2 ));
         CHECK(( b.get(3) == 3.4 ));
         CHECK(( b.get(4) == 5.6 ));
         CHECK(( b.get(5) == 0   ));
      }

      {
         BlockData<true,std::string> b;
         b.start(2).length(8).string("ab cd ef 123 4.5");
         CHECK(( b.get(0) == ""   ));
         CHECK(( b.get(1) == ""   ));
         CHECK(( b.get(2) == "ab" ));
         CHECK(( b.get(3) == "cd" ));
         CHECK(( b.get(4) == "ef" ));
         CHECK(( b.get(5) == "123"));
         CHECK(( b.get(6) == "4.5"));
         CHECK(( b.get(7) == ""   ));
      }

      // ------------------------
      // operator[] form
      // ------------------------

      {
         BlockData<true,int> b;
         b.start(2).length(6).string("-12 34 -56");
         CHECK(( b[0] ==   0 ));
         CHECK(( b[1] ==   0 ));
         CHECK(( b[2] == -12 ));
         CHECK(( b[3] ==  34 ));
         CHECK(( b[4] == -56 ));
         CHECK(( b[5] ==   0 ));
      }

      {
         BlockData<true,double> b;
         b.start(2).length(6).string("1.2 3.4 5.6");
         CHECK(( b[0] == 0   ));
         CHECK(( b[1] == 0   ));
         CHECK(( b[2] == 1.2 ));
         CHECK(( b[3] == 3.4 ));
         CHECK(( b[4] == 5.6 ));
         CHECK(( b[5] == 0   ));
      }

      {
         BlockData<true,std::string> b;
         b.start(2).length(6).string("ab cd ef");
         CHECK(( b[0] == ""   ));
         CHECK(( b[1] == ""   ));
         CHECK(( b[2] == "ab" ));
         CHECK(( b[3] == "cd" ));
         CHECK(( b[4] == "ef" ));
         CHECK(( b[5] == ""   ));
      }

   } // GIVEN
} // SCENARIO



// -----------------------------------------------------------------------------
// 5. Scenario: doubles() etc.
// -----------------------------------------------------------------------------

// Helper
template<class INT, class DOUBLE, class STRING>
void scenario_get_named()
{
   {
      BlockData<true,INT> b;

      b.start(2).length(6).string("-12 34 -56");
      auto result = b.ints();
      CHECK((std::is_same_v<decltype(result),
             std::vector<int>>));

      CHECK(result[0] ==   0 );
      CHECK(result[1] ==   0 );
      CHECK(result[2] == -12 );
      CHECK(result[3] ==  34 );
      CHECK(result[4] == -56 );
      CHECK(result[5] ==   0 );

      CHECK(result[0] == b.ints(0) );
      CHECK(result[1] == b.ints(1) );
      CHECK(result[2] == b.ints(2) );
      CHECK(result[3] == b.ints(3) );
      CHECK(result[4] == b.ints(4) );
      CHECK(result[5] == b.ints(5) );
   }

   {
      BlockData<true,DOUBLE> b;

      b.start(2).length(6).string("1.2 3.4 5.6");
      const BlockData<true,DOUBLE> &bconst = b; // ensure it works with const
      const auto result = bconst.doubles();
      CHECK((std::is_same_v<decltype(result),
             const std::vector<double>>));

      CHECK(result[0] == 0   );
      CHECK(result[1] == 0   );
      CHECK(result[2] == 1.2 );
      CHECK(result[3] == 3.4 );
      CHECK(result[4] == 5.6 );
      CHECK(result[5] == 0   );

      CHECK(result[0] == bconst.doubles(0) );
      CHECK(result[1] == bconst.doubles(1) );
      CHECK(result[2] == bconst.doubles(2) );
      CHECK(result[3] == bconst.doubles(3) );
      CHECK(result[4] == bconst.doubles(4) );
      CHECK(result[5] == bconst.doubles(5) );
   }

   {
      BlockData<true,STRING> b;

      b.start(2).length(6).string("ab cd ef");
      const auto &result = b.strings();
      CHECK((std::is_same_v<decltype(result),
             const std::vector<std::string> &>));

      CHECK(result[0] == ""   );
      CHECK(result[1] == ""   );
      CHECK(result[2] == "ab" );
      CHECK(result[3] == "cd" );
      CHECK(result[4] == "ef" );
      CHECK(result[5] == ""   );

      CHECK(result[0] == b.strings(0) );
      CHECK(result[1] == b.strings(1) );
      CHECK(result[2] == b.strings(2) );
      CHECK(result[3] == b.strings(3) );
      CHECK(result[4] == b.strings(4) );
      CHECK(result[5] == b.strings(5) );
   }
}

// For BlockData<DATATYPE == void>
SCENARIO("BlockData<DATATYPE == void> type-specific get functions: doubles() etc.") {
   GIVEN("A BlockData object") {
      scenario_get_named<void,void,void>();
   }
}

// For BlockData<DATATYPE != void>
SCENARIO("BlockData<DATATYPE != void> type-specific get functions: doubles() etc.") {
   GIVEN("A BlockData object") {
      scenario_get_named<int,double,std::string>();
   }
}
