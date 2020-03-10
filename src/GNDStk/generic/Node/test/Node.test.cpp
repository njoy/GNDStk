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
        CHECK( "XML" == gNode( "type" ) );

        CHECK( 3 == ranges::distance( gNode.children() ) );
        CHECK( 2 == ranges::distance( gNode.children( "child1" ) ) );
        CHECK( 2 == ranges::distance( gNode[ "child1" ] ) );

        auto tChild = gNode.children( "child" ).front();
        CHECK( "metadata" == tChild.metadata( "some" ) );
        CHECK( "metadata" == tChild( "some" ) );

      } // THEN
    } // GIVEN
  } // WHEN
  WHEN( "creating a generic node from an XML file" ){

    std::string sXML = R"_(
<?xml version="1.0" encoding="UTF-8"?>
<reactionSuite projectile="n" target="O16" evaluation="ENDF/B-8.0" format="1.9" projectileFrame="lab">
  <reactions>
    <reaction label="n + O16" ENDF_MT="2">
    </reaction>
    <reaction label="n + (O16_e1 -> O16)" ENDF_MT="51">1 2 3 4 5</reaction>
  </reactions>
</reactionSuite>
    )_";
    pugi::xml_document xml;
    auto result = xml.load_buffer( sXML.c_str(), sXML.size() );

    GIVEN( "an XML node" ){
      auto node = xml.child( "reactionSuite" );
      njoy::GNDStk::generic::Node xNode( node );

      THEN( "we can traverse the node" ){

        CHECK( "n" == xNode( "projectile" ) );
        CHECK( "O16" == xNode( "target" ) );
        CHECK( "ENDF/B-8.0" == xNode( "evaluation" ) );
        CHECK( "1.9" == xNode( "format" ) );

        auto reactions = xNode.children( "reactions" ).front()
                              .children( "reaction" );
        CHECK( 2 == ranges::distance( reactions ) );

        auto mt2 = reactions.front();
        CHECK( "n + O16" == mt2( "label" ) );
        CHECK( "2" == mt2( "ENDF_MT" ) );
        CHECK( "" == mt2.body() );

        auto mt51 = reactions.back();
        CHECK( "n + (O16_e1 -> O16)" == mt51( "label" ) );
        CHECK( "51" == mt51( "ENDF_MT" ) );
        CHECK( "1 2 3 4 5" == mt51.body() );
        
      } // THEN

    } // GIVEN
    
    
  } // WHEN
}
