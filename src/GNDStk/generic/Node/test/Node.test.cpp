#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO( "Testing generic Node" ){
  WHEN( "creating a node manually" ){
    GIVEN( "a generic Node" ){
      std::string nodeName = "reactionSuite";

      njoy::GNDStk::generic::Node gNode( nodeName );
      njoy::GNDStk::generic::Node cNode( "child" );
      cNode.metadata( "some", "metadata" );
      gNode.metadata( "type", "XML" );
      gNode.insertChild( njoy::utility::copy( cNode ) );
      gNode.insertChild( "child1" );
      gNode.insertChild( "child1" );

      THEN( "we can verify the contents" ){
        CHECK( nodeName == gNode.name() );
        CHECK( "XML" == gNode.metadata( "type" ) );

        CHECK( 3 == ranges::distance( gNode.children() ) );
        CHECK( 2 == ranges::distance( gNode.children( "child1" ) ) );

        auto tChild = gNode.children( "child" ).front();
        CHECK( "metadata" == tChild.metadata( "some" ) );

      } // THEN
    } // GIVEN
  } // WHEN
  WHEN( "creating a generic node from an XML file" ){
    
  } // WHEN
}
