#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/gpdc/Values.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Values = v1_9::gpdc::Values;

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

      std::vector< double > values = { 1., 2., 3., 4., 5., 6. };

      Values chunk( std::nullopt, 0, "Float64", values );

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "a custom constructor is used" ) {

      std::vector< double > values = { 1., 2., 3., 4., 5., 6. };

      Values chunk( values );

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      Values chunk( core );

      THEN( "a Values can be constructed and members can be tested" ) {

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

      THEN( "a Values can be constructed and members can be tested" ) {

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

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for a Values" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Values( invalidName() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node defaultChunk() {

  Node chunk( "values" );

  Node pcdata( "pcdata" );
  pcdata.add( "text", "" );

  chunk.add( "pcdata" ) = pcdata;

  return chunk;
}

void verifyDefaultChunk( const Values& component ) {

  CHECK( "Float64" == component.valueType() );
  CHECK( 0 == component.start() );
  CHECK( 0 == component.length() );
  CHECK( 0 == component.values().size() );

  CHECK( defaultChunk() == Node( component ) );
}

Node chunk() {

  Node chunk( "values" );

  Node pcdata( "pcdata" );
  pcdata.add( "text", "1 2 3 4 5 6" );

  chunk.add( "pcdata" ) = pcdata;

  return chunk;
}

void verifyChunk( const Values& component ) {

  CHECK( "Float64" == component.valueType() );
  CHECK( 0 == component.start() );
  CHECK( 6 == component.length() );
  CHECK( 6 == component.values().size() );

  CHECK( 1. == component.values()[0] );
  CHECK( 2. == component.values()[1] );
  CHECK( 3. == component.values()[2] );
  CHECK( 4. == component.values()[3] );
  CHECK( 5. == component.values()[4] );
  CHECK( 6. == component.values()[5] );

  CHECK( chunk() == Node( component ) );
}

Node invalidName() {

  // wrong name for the node
  return Node( "wrongName" );
}
