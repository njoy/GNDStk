#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the basic Node class" ){
  GIVEN( "a Node containing a single type (std::string)" ){
    using Node_string = GNDStk::Node< std::string >;
    Node_string gndsNode{};

    WHEN( "adding metadata" ){
      gndsNode.metadata( "key1", "value1" );
      gndsNode.metadata( "key2", "value2" );

      THEN( "the metadata can be verified" ){
        CHECK( "value1" == gndsNode.metadata( "key1" ) );
        CHECK( "value2" == gndsNode.metadata( "key2" ) );

        const auto& metadata = gndsNode.metadata();
        CHECK( "value1" == metadata.at( "key1" ) );
        CHECK( "value2" == metadata.at( "key2" ) );
      } // THEN
      WHEN( "asking for a non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( gndsNode.metadata( "key3" ), 
                           std::out_of_range& );
          
        } // THEN
      } // WHEN
    } // WHEN
    
  } // GIVEN
  
} // SCENARIO
