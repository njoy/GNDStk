#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Axes.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::Axis;
using Axes = v1_9::Axes;

node chunk();
void verifyChunk( const Axes& );

SCENARIO( "Axes" ) {

  GIVEN( "valid data for a Axes" ) {

    WHEN( "the data is given explicitly" ) {

      std::vector< Axis > axes = { Axis( 1, "energy_in", "eV" ),
                                   Axis( 0, "radius", "fm" ) };

      Axes chunk( std::move( axes ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

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

      Axes chunk( core );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
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

void verifyChunk( const Axes& chunk ) {

  CHECK( 2 == chunk.axes().size() );
  CHECK( 2 == chunk.size() );

  CHECK( 0 == chunk.axes()[0].index() );
  CHECK( "radius" == chunk.axes()[0].label() );
  CHECK( std::nullopt != chunk.axes()[0].unit() );
  CHECK( "fm" == chunk.axes()[0].unit().value() );

  CHECK( 1 == chunk.axes()[1].index() );
  CHECK( "energy_in" == chunk.axes()[1].label() );
  CHECK( std::nullopt != chunk.axes()[1].unit() );
  CHECK( "eV" == chunk.axes()[1].unit().value() );

  CHECK( 0 == chunk.axis(0).index() );
  CHECK( "radius" == chunk.axis(0).label() );
  CHECK( std::nullopt != chunk.axis(0).unit() );
  CHECK( "fm" == chunk.axis(0).unit().value() );

  CHECK( 1 == chunk.axis(1).index() );
  CHECK( "energy_in" == chunk.axis(1).label() );
  CHECK( std::nullopt != chunk.axis(1).unit() );
  CHECK( "eV" == chunk.axis(1).unit().value() );
}
