#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the basic Values node." ){
  GIVEN( "initial value data" ){
    std::vector< int > intValues{ 1, 2, 3, 4 };
    std::vector< double > doubleValues{ 10.0, 11.0, 12.0 };

    GNDStk::nodes::Values< int > iValues{ utility::copy( intValues ) };
    GNDStk::nodes::Values< double > dValues{ utility::copy(doubleValues ) };
    GNDStk::nodes::Values< double > iILValues{ { 13.0, 14.0 } };
    GNDStk::nodes::Values< double > dSparse{ { 13.0, 14.0 }, 3, 7 };

    THEN( "the values can be verified" ){
      CHECK( intValues == iValues.values() );
      CHECK( doubleValues == dValues.values() );
      CHECK( ( std::vector< double >{ 13.0, 14.0 } == iILValues.values() ) );

      AND_THEN( "the metadata can be checked" ){
        CHECK( "4" == iValues.metadata( "length" ) );
        CHECK( "3" == dValues.metadata( "length" ) );
        CHECK( "2" == iILValues.metadata( "length" ) );

        CHECK( "7" == dSparse.metadata( "length" ) );
        CHECK( "3" == dSparse.metadata( "start" ) );
      } // AND_THEN
    } // THEN
  } // GIVEN
  
} // SCENARIO
