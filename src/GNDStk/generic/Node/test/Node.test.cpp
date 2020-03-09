#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO( "Testing generic Node" ){
  WHEN( "creating a node manually" ){
    GIVEN( "a generic Node" ){
      std::string nodeName = "reactionSuite";
      njoy::GNDStk::generic::Node gNode( nodeName );

      THEN( "we can verify the contents" ){
        CHECK( nodeName == gNode.name() );
        
      } // THEN
    } // GIVEN
  } // WHEN
  WHEN( "creating a generic node from an XML file" ){
    
  } // WHEN
}
