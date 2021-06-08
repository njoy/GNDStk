#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Values.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Values = v1_9::containers::Values;

Node defaultChunk();
void verifyDefaultChunk( const Values& );
Node chunk();
void verifyChunk( const Values& );
Node invalidName();

SCENARIO( "Values" ) {

  GIVEN( "valid data for a Values" ) {

    WHEN( "the default constructor is used" ) {

      Values chunk;

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyDefaultChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly" ) {

      unsigned int length = 4;
      unsigned int start = 0;
      std::string valueType = "Float64";
      std::vector< double > values = { 2500., 8.9172, 2550., 8.9155 };

      Values chunk1( length, start, valueType, values );
      Values chunk2( values );

      THEN( "an Values can be constructed and members can be tested" ) {

        verifyChunk( chunk1 );
        verifyChunk( chunk2 );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly" ) {

      unsigned int length = 4;
      unsigned int start = 0;
      std::string valueType = "Float64";
      std::vector< double > values = { 2500., 8.9172, 2550., 8.9155 };

      Values chunk( length, start, valueType, values );

      THEN( "an Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      Values chunk( core );

      THEN( "an Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      Node core = chunk();
      Values chunk( core );

      // copy constructor
      Values copy( chunk );

      // copy assignment
      Values assign;
      assign = chunk;

      THEN( "an Values can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node core = chunk();
      Values chunk( core );
      Values chunk2( core );

      // move constructor
      Values move( std::move( chunk ) );

      // copy assignment
      Values assign;
      assign = std::move( chunk2 );

      THEN( "an Values can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Values" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Values( invalidName() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node defaultChunk() {

  Node chunk;
  chunk << "<Values/>";

  return chunk;
}

void verifyDefaultChunk( const Values& component ) {

  CHECK( 0 == component.length() );
  CHECK( 0 == component.start() );
  CHECK( "Float64" == component.valueType() );

  CHECK( "" == component.string() );

  CHECK( 0 == component.size() );
  CHECK( 0 == component.doubles().size() );

  //! @todo comparison does not work yet
  // CHECK( defaultChunk() == Node( component ) );
}

Node chunk() {

  Node chunk;
  chunk << "<values>2500 8.9172 2550 8.9155</values>";

  return chunk;
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

  //! @todo comparison does not work yet
  // CHECK( chunk() == Node( component ) );
}

Node invalidName() {

  // wrong name for the node
  Node chunk;
  chunk << "<wrongName>2500 8.9172 2550 8.9155</wrongName>";

  return chunk;
}
