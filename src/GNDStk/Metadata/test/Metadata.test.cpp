#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the basic Metadata class" ){
  GIVEN( "an empty Metadata object" ){
    GNDStk::Metadata meta{};

    THEN( "key,value pairs can be added" ){

      meta.emplace( "key1", "value1" );
      meta.emplace( std::string{ "key2" }, "value2" );

      AND_THEN( "I can retrieve the appropriate values" ){
        CHECK( 2 == meta.size() );

        CHECK( "value1" == meta.at( "key1" ) );
        CHECK( "value2" == meta.at( "key2" ) );

        CHECK( ranges::equal( { "key1", "key2" }, meta.keys() ) );
        CHECK( ranges::equal( { "value1", "value2" }, meta.values() ) );

      } // AND_THEN

      WHEN( "asking for non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( meta.at( "abcd" ), std::out_of_range& );
        } // THEN
      } // WHEN
    } // THEN
  } // GIVEN
} // SCENARIO
