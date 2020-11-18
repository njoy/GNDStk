#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Axis.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::Axis;

node chunk();
void verifyChunk( const Axis& );
node chunkWithOptionalUnit();
void verifyChunkWithOptionalUnit( const Axis& );
node invalidChunk();

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

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is taken from a node" ) {

      node core = chunk();

      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "valid data for a Axis without a unit" ) {

    WHEN( "the data is given explicitly" ) {

      unsigned int index = 1;
      std::string label = "energy_in";

      Axis chunk( index, label );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunkWithOptionalUnit() == chunk.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is taken from a node" ) {

      node core = chunkWithOptionalUnit();

      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunkWithOptionalUnit() == chunk.node() );
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

node chunk() {

  node chunk( "axis" );
  chunk.add( "index", "1" );
  chunk.add( "label", "energy_in" );
  chunk.add( "unit", "eV" );

  return chunk;
}

void verifyChunk( const Axis& chunk ) {

  CHECK( 1 == chunk.index() );
  CHECK( "energy_in" == chunk.label() );
  CHECK( std::nullopt != chunk.unit() );
  CHECK( "eV" == chunk.unit().value() );
}

node chunkWithOptionalUnit() {

  node chunk( "axis" );
  chunk.add( "index", "1" );
  chunk.add( "label", "energy_in" );

  return chunk;
}

void verifyChunkWithOptionalUnit( const Axis& chunk ) {

  CHECK( 1 == chunk.index() );
  CHECK( "energy_in" == chunk.label() );
  CHECK( std::nullopt == chunk.unit() );
}

node invalidChunk() {

  // wrong name for the node
  return node( "wrongName" );
}
