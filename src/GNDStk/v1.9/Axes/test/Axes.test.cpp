#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Axes.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::Axis;
using Axes = v1_9::Axes;

// query objects
const auto axis1 = --basic::axis
                   + [] ( const auto& node )
                        { return node( basic::index ) == "1"; };

const auto axis0 = --basic::axis
                   + [] ( const auto& node )
                        { return node( basic::index ) == "0"; };

node chunk();
void verifyChunk( const Axes& );
node invalidChunk();

SCENARIO( "Axes" ) {

  GIVEN( "valid data for a Axes" ) {

    WHEN( "the data is given explicitly" ) {

      std::vector< Axis > axes = { Axis( 1, "energy_in", "eV" ),
                                   Axis( 0, "radius", "fm" ) };

      Axes chunk( std::move( axes ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      node core = chunk();
      const node ccore = chunk();
      Axes chunk( core );
      Axes cchunk( ccore );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
        verifyChunk( cchunk );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( axis0 ) == &chunk.node()( axis0 ) );
        CHECK( &core( axis1 ) == &chunk.node()( axis1 ) );
        CHECK( &ccore( axis0 ) != &cchunk.node()( axis0 ) );
        CHECK( &ccore( axis1 ) != &cchunk.node()( axis1 ) );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      node core = chunk();
      const node ccore = chunk();
      Axes chunk( core );
      Axes cchunk( ccore );

      // copy constructor
      Axes copy( chunk );
      Axes ccopy( cchunk );

      // copy assignment
      Axes assign;
      Axes cassign;
      assign = chunk;
      cassign = cchunk;

      THEN( "an Axes can be constructed and members can be tested" ) {

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

        CHECK( &core( axis0 ) != &copy.node()( axis0 ) );
        CHECK( &core( axis1 ) != &copy.node()( axis1 ) );
        CHECK( &ccore( axis0 ) != &ccopy.node()( axis0 ) );
        CHECK( &ccore( axis1 ) != &ccopy.node()( axis1 ) );

        CHECK( &core( axis0 ) != &assign.node()( axis0 ) );
        CHECK( &core( axis1 ) != &assign.node()( axis1 ) );
        CHECK( &ccore( axis0 ) != &cassign.node()( axis0 ) );
        CHECK( &ccore( axis1 ) != &cassign.node()( axis1 ) );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      node core = chunk();
      const node ccore = chunk();
      Axes chunk( core );
      Axes cchunk( ccore );

      // move constructor
      Axes move( std::move( chunk ) );
      Axes cmove( std::move( cchunk ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( cmove );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( axis0 ) == &chunk.node()( axis0 ) );
        CHECK( &core( axis1 ) == &chunk.node()( axis1 ) );
        CHECK( &ccore( axis0 ) != &cchunk.node()( axis0 ) );
        CHECK( &ccore( axis1 ) != &cchunk.node()( axis1 ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Axes" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axes( invalidChunk() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

node chunk() {

  node chunk( "axes" );

  node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );

  node axis2( "axis" );
  axis2.add( "index", "0" );
  axis2.add( "label", "radius" );
  axis2.add( "unit", "fm" );

  chunk.add( "axis" ) = axis1;
  chunk.add( "axis" ) = axis2;

  return chunk;
}

void verifyChunk( const Axes& component ) {

  CHECK( 2 == component.axis().size() );
  CHECK( 2 == component.size() );

  CHECK( 0 == component.axis()[0].index() );
  CHECK( "radius" == component.axis()[0].label() );
  CHECK( std::nullopt != component.axis()[0].unit() );
  CHECK( "fm" == component.axis()[0].unit().value() );

  CHECK( 1 == component.axis()[1].index() );
  CHECK( "energy_in" == component.axis()[1].label() );
  CHECK( std::nullopt != component.axis()[1].unit() );
  CHECK( "eV" == component.axis()[1].unit().value() );

  CHECK( 0 == component.axis(0).index() );
  CHECK( "radius" == component.axis(0).label() );
  CHECK( std::nullopt != component.axis(0).unit() );
  CHECK( "fm" == component.axis(0).unit().value() );

  CHECK( 1 == component.axis(1).index() );
  CHECK( "energy_in" == component.axis(1).label() );
  CHECK( std::nullopt != component.axis(1).unit() );
  CHECK( "eV" == component.axis(1).unit().value() );

  CHECK( chunk() == component.node() );
}

node invalidChunk() {

  // wrong name for the node
  return node( "wrongName" );
}
