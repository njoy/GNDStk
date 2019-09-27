#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO( "Testing generic GNDStk Node" ){
  GIVEN( "a generic node" ){
    generic::Node genNode{};
    WHEN( "data has been added" ){
      genNode.metadata( "interpolation", "log-log" );
      genNode.metadata( "index", "0" );

      THEN( "the metadata can be checked" ){
        CHECK( "log-log" == genNode.metadata( "interpolation" ) );
        CHECK( "0" == genNode.metadata( "index" ) );

        CHECK_THROWS( genNode.metadata( "abc" ) );
        // genNode.metadata( "abc" );
        
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
