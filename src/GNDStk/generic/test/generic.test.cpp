#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO( "Testing generic GNDStk Node" ){
  GIVEN( "a generic node" ){
    decltype( auto ) genNode = generic::node( "XYs1d" );
    WHEN( "data has been added" ){
      genNode[ "metadata" ].insert( "interpolation", generic::Node_t{ "log-log" } );
      genNode[ "metadata" ].insert( "index", generic::Node_t{ "0" } );
      // genNode.insert( generic::Node_t{ "1.0, 2.0, 3.0" } );

      THEN( "the metadata can be checked" ){
        CHECK( "log-log" == 
               generic::getString( genNode[ "metadata" ][ "interpolation" ] ) );
        CHECK( "0" == generic::getString( genNode[ "metadata" ][ "index" ] ) );

        
      } // THEN
    } // WHEN
    WHEN( "accessing a node that doesn't exist" ){
      THEN( "an exception is thrown" ){
        CHECK_THROWS_AS( genNode[ "abc" ], std::out_of_range& );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

