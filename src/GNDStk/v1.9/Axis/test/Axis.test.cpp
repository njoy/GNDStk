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
    } // WHEN

    WHEN( "the data is given explicitly without a unit" ) {

      unsigned int index = 1;
      std::string label = "energy_in";

      Axis chunk( index, label );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      node core = chunk();
      const node ccore = chunk();
      Axis chunk( core );
      Axis cchunk( ccore );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
        verifyChunk( cchunk );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        // axis has no children
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      node core = chunk();
      const node ccore = chunk();
      Axis chunk( core );
      Axis cchunk( ccore );

      // copy constructor
      Axis copy( chunk );
      Axis ccopy( cchunk );

      // copy assignment
      Axis assign;
      Axis cassign;
      assign = chunk;
      cassign = cchunk;

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( ccopy );
        verifyChunk( assign );
        verifyChunk( cassign );
      } // THEN

      THEN( "none of the nodes and its children remains in sync with the "
            "internal nodes" ) {

        CHECK( &core != &copy.node() );
        CHECK( &ccore != &ccopy.node() );
        CHECK( &core != &assign.node() );
        CHECK( &ccore != &cassign.node() );

        // axis has no children
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      node core = chunk();
      const node ccore = chunk();
      Axis chunk( core );
      Axis cchunk( ccore );

      // move constructor
      Axis move( std::move( chunk ) );
      Axis cmove( std::move( cchunk ) );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( cmove );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        // axis has no children
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

void verifyChunk( const Axis& component ) {

  CHECK( 1 == component.index() );
  CHECK( "energy_in" == component.label() );
  CHECK( std::nullopt != component.unit() );
  CHECK( "eV" == component.unit().value() );

  CHECK( chunk() == component.node() );
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
