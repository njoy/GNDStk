#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

std::vector< std::string > keys{ "key1", "key2" };
SCENARIO( "Testing the basic Metadata class" ){
  GIVEN( "an empty Metadata object" ){
    auto meta = GNDStk::Metadata< keys >{};

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

      WHEN( "trying to use a non-allowed key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS( meta.emplace( "key3", "value3" ) );
        } // THEN
      } // WHEN
      WHEN( "asking for non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( meta.at( "abcd" ), std::out_of_range& );
        } // THEN
      } // WHEN
    } // THEN
  } // GIVEN

  GIVEN( "a starting map" ){
    WHEN( "the default keys are valid" ){
      std::map< std::string, std::string > dMap{ { "key1", "default1" } };
      THEN( "a metadata object can be created" ){
        auto meta = GNDStk::Metadata< keys >{ dMap };
      
        meta.emplace( "key2", "value2" );
      
        AND_THEN( "the key, value pairs can be verified" ){
          CHECK( dMap[ "key1" ] == meta.at( "key1" ) );
          CHECK( "value2" == meta.at( "key2" ) );
      
        } // AND_THEN
      } // THEN
    } // WHEN
    WHEN( "the default keys are not valid" ){
      std::map< std::string, std::string > dMap{ { "key3", "default1" } };
      THEN( "an exception is thrown" ){
        CHECK_THROWS( GNDStk::Metadata< keys >{ dMap } );
      } // THEN
      
    } // WHEN
  } // GIVEN
} // SCENARIO
