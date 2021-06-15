#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Link.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Link = v1_9::containers::Link;

std::string chunk();
void verifyChunk( const Link& );
std::string invalidName();

SCENARIO( "Link" ) {

  GIVEN( "valid data for the component with a Values component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      std::string href = "../../grid[@index='2']/values";

      Link chunk( href );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        std::ostringstream out;
        XML( Node( chunk ) ).write( out, false );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node node;
      node << chunk();
      Link chunk( node );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        std::ostringstream out;
        XML( Node( chunk ) ).write( out, false );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a valid component instance" ) {

    WHEN( "the component is copied" ) {

      Node node;
      node << chunk();
      Link chunk( node );

      // copy constructor
      Link copy( chunk );

      // copy assignment
      Link assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      Link chunk( node );
      Link chunk2( node );

      // move constructor
      Link move( std::move( chunk ) );

      // move assignment
      Link assign;
      assign = std::move( chunk2 );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data" ) {

    WHEN( "when the wrong node is used" ) {

      Node node;
      node << invalidName();

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Link( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<link href="../../grid[@index='2']/values" />
)***";
}

void verifyChunk( const Link& component ) {

  CHECK( "../../grid[@index='2']/values" == component.href() );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName href="../../grid[@index='2']/values" />
)***";
}
