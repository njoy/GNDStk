#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/gpdc/Axis.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::gpdc::Axis;

Node chunk();
void verifyChunk( const Axis& );
Node chunkWithOptionalUnit();
void verifyChunkWithOptionalUnit( const Axis& );
Node invalidChunk();

SCENARIO( "Axis" ) {

  GIVEN( "valid data for a Axis" ) {

    WHEN( "the data is given explicitly" ) {

      unsigned int index = 1;
      std::string label = "energy_in";
      std::string unit = "eV";

      Axis chunk( index, label, unit );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

//    WHEN( "the data is given explicitly without a unit" ) {
//
//      unsigned int index = 1;
//      std::string label = "energy_in";
//
//      Axis chunk( index, label );
//
//      THEN( "an Axis can be constructed and members can be tested" ) {
//
//        verifyChunkWithOptionalUnit( chunk );
//      } // THEN
//    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Axis" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axis( invalidChunk() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node chunk() {

  Node chunk( "axis" );
  chunk.add( "index", "1" );
  chunk.add( "label", "energy_in" );
  chunk.add( "unit", "eV" );

  return chunk;
}

void verifyChunk( const Axis& component ) {

  CHECK( 1 == component.index() );
  CHECK( "energy_in" == component.label() );
  CHECK( std::nullopt != component.unit() );
  CHECK( "eV" == component.unit().value() );

  CHECK( chunk() == Node( component ) );
}

Node chunkWithOptionalUnit() {

  Node chunk( "axis" );
  chunk.add( "index", "1" );
  chunk.add( "label", "energy_in" );

  return chunk;
}

void verifyChunkWithOptionalUnit( const Axis& component ) {

  CHECK( 1 == component.index() );
  CHECK( "energy_in" == component.label() );
  CHECK( std::nullopt == component.unit() );

  CHECK( chunkWithOptionalUnit() == Node( component ) );
}

Node invalidChunk() {

  // wrong name for the node
  return Node( "wrongName" );
}
