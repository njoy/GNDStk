#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Values.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Values = v1_9::containers::Values;

std::string chunk();
void verifyChunk( const Values& );
std::string invalidName();

SCENARIO( "Values" ) {

  GIVEN( "valid data for the component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      unsigned int length = 4;
      unsigned int start = 0;
      std::string valueType = "Float64";
      std::vector< double > values = { 2500., 8.9172, 2550., 8.9155 };

      Values chunk( length, start, valueType, values );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        Node data( chunk );
        XML xml( data );

        std::ostringstream out;
        xml.doc.first_child().print( out, "  " );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "custom constructor: only values are given" ) {

      std::vector< double > values = { 2500., 8.9172, 2550., 8.9155 };

      Values chunk( values );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        Node data( chunk );
        XML xml( data );

        std::ostringstream out;
        xml.doc.first_child().print( out, "  " );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node node;
      node << chunk();
      Values chunk( node );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        Node data( chunk );
        XML xml( data );

        std::ostringstream out;
        xml.doc.first_child().print( out, "  " );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

  } // GIVEN

  GIVEN( "a valid component instance" ) {

    WHEN( "the component is copied" ) {

      Node node;
      node << chunk();
      Values chunk( node );

      // copy constructor
      Values copy( chunk );

      // copy assignment
      Values assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      Values chunk( node );
      Values chunk2( node );

      // move constructor
      Values move( std::move( chunk ) );

      // move assignment
      Values assign;
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

        CHECK_THROWS( Values( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<values length="4" start="0" valueType="Float64">2500 8.9172 2550 8.9155</values>
)***";
}

void verifyChunk( const Values& component ) {

  CHECK( 4 == component.length() );
  CHECK( 0 == component.start() );
  CHECK( "Float64" == component.valueType() );

  CHECK( "2500 8.9172 2550 8.9155" == component.string() );

  CHECK( 4 == component.size() );
  CHECK( 4 == component.doubles().size() );

  CHECK( 2500. == Approx( component.doubles()[0] ) );
  CHECK( 8.9172 == Approx( component.doubles()[1] ) );
  CHECK( 2550. == Approx( component.doubles()[2] ) );
  CHECK( 8.9155 == Approx( component.doubles()[3] ) );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName length="4" start="0" valueType="Float64">2500 8.9172 2550 8.9155</wrongName>
)***";
}
