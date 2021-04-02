#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/gpdc/Axes.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::gpdc::Axis;
using Grid = v1_9::gpdc::Grid;
using Axes = v1_9::gpdc::Axes;

Node defaultChunk();
void verifyDefaultChunk( const Axes& );
Node chunk();
void verifyChunk( const Axes& );
Node invalidName();
Node invalidChunk();

SCENARIO( "Axes" ) {

  GIVEN( "valid data for a Axes" ) {

    WHEN( "the default constructor is used" ) {

      Axes chunk;

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyDefaultChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly" ) {

      std::vector< Axis > axis = { Axis( 1, "energy_in", "eV" ),
                                   Axis( 0, "radius", "fm" ) };

      Axes chunk( std::nullopt, axis, std::nullopt );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "a custom constructor is used" ) {

      std::vector< std::variant< Axis, Grid > > elements = {

        Axis( 1, "energy_in", "eV" ),
        Axis( 0, "radius", "fm" )
      };

      Axes chunk( elements );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      Axes chunk( core );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      Node core = chunk();
      Axes chunk( core );

      // copy constructor
      Axes copy( chunk );

      // copy assignment
      Axes assign;
      assign = chunk;

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node core = chunk();
      Axes chunk( core );
      Axes chunk2( core );

      // move constructor
      Axes move( std::move( chunk ) );

      // copy assignment
      Axes assign;
      assign = std::move( chunk2 );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Axes" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axes( invalidName() ) );
      } // THEN
    } // WHEN

    WHEN( "when the node is illegal" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axes( invalidChunk() ) );
      } // THEN
    } // WHEN

    WHEN( "when the axis indices are wrong" ) {

      std::vector< std::variant< Axis, Grid > > elements = {

        Axis( 2, "energy_in", "eV" ), // the index should have been 1
        Axis( 0, "radius", "fm" )
      };

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axes( elements ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node defaultChunk() {

  Node chunk( "axes" );

  return chunk;
}

void verifyDefaultChunk( const Axes& component ) {

  CHECK( std::nullopt == component.href() );
  CHECK( std::nullopt == component.axis() );
  CHECK( std::nullopt == component.grid() );

  CHECK( 0 == component.elements().size() );
  CHECK( 0 == component.size() );

//  CHECK( defaultChunk() == Node( component ) );
}

Node chunk() {

  Node chunk( "axes" );

  Node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );

  Node axis2( "axis" );
  axis2.add( "index", "0" );
  axis2.add( "label", "radius" );
  axis2.add( "unit", "fm" );

  chunk.add( "axis" ) = axis1;
  chunk.add( "axis" ) = axis2;

  return chunk;
}

void verifyChunk( const Axes& component ) {

  CHECK( std::nullopt == component.href() );
  CHECK( std::nullopt != component.axis() );
  CHECK( std::nullopt == component.grid() );

  CHECK( 2 == component.axis()->size() );
  CHECK( 2 == component.elements().size() );
  CHECK( 2 == component.size() );

  CHECK( 0 == component.axis().value()[0].index().value() );
  CHECK( "radius" == component.axis().value()[0].label().value() );
  CHECK( "fm" == component.axis().value()[0].unit().value() );

  CHECK( 1 == component.axis().value()[1].index().value() );
  CHECK( "energy_in" == component.axis().value()[1].label().value() );
  CHECK( "eV" == component.axis().value()[1].unit().value() );

  const Axis& index0 = std::get< 0 >( component.element(0) );
  CHECK( 0 == index0.index().value() );
  CHECK( "radius" == index0.label().value() );
  CHECK( "fm" == index0.unit().value() );

  const Axis& index1 = std::get< 0 >( component.element(1) );
  CHECK( 1 == index1.index().value() );
  CHECK( "energy_in" == index1.label().value() );
  CHECK( "eV" == index1.unit().value() );

//  CHECK( chunk() == Node( component ) );
}

Node invalidName() {

  // wrong name for the node
  return Node( "wrongName" );
}

Node invalidChunk() {

  Node chunk( "axes" );
  chunk.add( "href", "1" );

  // href and axis nodes are not allowed
  Node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );
  chunk.add( "axis" ) = axis1;

  return chunk;
}
