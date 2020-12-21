#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Constant1D.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Constant1D = v1_9::Constant1D;
using Axes = v1_9::Axes;
using Axis = v1_9::Axis;

node chunk();
void verifyChunk( const Constant1D& );
node invalidChunk();

SCENARIO( "Constant1D" ) {

  GIVEN( "valid data for a Constant1D" ) {

    WHEN( "the data is given explicitly" ) {

      std::string label = "eval";
      double constant = 9.41;
      double domainMin = 1e-5;
      double domainMax = 3e+4;
      Axes axes( { Axis( 1, "energy_in", "eV" ),
                   Axis( 0, "radius", "fm" ) } );

      Constant1D chunk( std::move( label ), constant, domainMin, domainMax,
                        std::nullopt, std::move( axes ) );

      THEN( "an Constant1D can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      node core = chunk();
      const node ccore = chunk();
      Constant1D chunk( core );
      Constant1D cchunk( ccore );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
        verifyChunk( cchunk );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( basic::axes ) == &chunk.node()( basic::axes ) );
        CHECK( &ccore( basic::axes ) != &cchunk.node()( basic::axes ) );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      node core = chunk();
      const node ccore = chunk();
      Constant1D chunk( core );
      Constant1D cchunk( ccore );

      // copy constructor
      Constant1D copy( chunk );
      Constant1D ccopy( cchunk );

      // copy assignment
      Constant1D assign;
      Constant1D cassign;
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

        CHECK( &core( basic::axes ) != &copy.node()( basic::axes ) );
        CHECK( &ccore( basic::axes ) != &ccopy.node()( basic::axes ) );
        CHECK( &core( basic::axes ) != &assign.node()( basic::axes ) );
        CHECK( &ccore( basic::axes ) != &cassign.node()( basic::axes ) );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      node core = chunk();
      const node ccore = chunk();
      Constant1D chunk( core );
      Constant1D cchunk( ccore );

      // move constructor
      Constant1D move( std::move( chunk ) );
      Constant1D cmove( std::move( cchunk ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( cmove );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( basic::axes ) == &chunk.node()( basic::axes ) );
        CHECK( &ccore( basic::axes ) != &cchunk.node()( basic::axes ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Constant1D" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Constant1D( invalidChunk() ) );
      } // THEN
    } // WHEN

    WHEN( "when the wrong number of axis is used" ) {

      std::string label = "eval";
      double constant = 9.41;
      double domainMin = 1e-5;
      double domainMax = 3e+4;
      Axes axes( { Axis( 2, "some_dimension", "some_unit" ),
                   Axis( 1, "energy_in", "eV" ),
                   Axis( 0, "radius", "fm" ) } );

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Constant1D( std::move( label ), constant,
                                  domainMin, domainMax,
                                  std::nullopt, std::move( axes ) ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

node chunk() {

  node chunk( "constant1d" );

  chunk.add( "label", "eval" );
  chunk.add( "constant", 9.41 );
  chunk.add( "domainMin", 1e-5 );
  chunk.add( "domainMax", 30000. );

  node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );

  node axis2( "axis" );
  axis2.add( "index", "0" );
  axis2.add( "label", "radius" );
  axis2.add( "unit", "fm" );

  node axes( "axes" );
  axes.add( "axis" ) = axis1;
  axes.add( "axis" ) = axis2;

  chunk.add( "axes" ) = axes;

  return chunk;
}

void verifyChunk( const Constant1D& component ) {

  CHECK( "eval" == component.label() );
  CHECK( 9.41 == Approx( component.constant() ) );
  CHECK( 1e-5 == Approx( component.domainMin() ) );
  CHECK( 30000. == Approx( component.domainMax() ) );

  CHECK( 2 == component.axes().size() );

  CHECK( 0 == component.axes().axis(0).index() );
  CHECK( "radius" == component.axes().axis(0).label() );
  CHECK( std::nullopt != component.axes().axis(0).unit() );
  CHECK( "fm" == component.axes().axis(0).unit().value() );

  CHECK( 1 == component.axes().axis(1).index() );
  CHECK( "energy_in" == component.axes().axis(1).label() );
  CHECK( std::nullopt != component.axes().axis(1).unit() );
  CHECK( "eV" == component.axes().axis(1).unit().value() );

  CHECK( chunk() == component.node() );
}

node invalidChunk() {

  // wrong name for the node
  return node( "wrongName" );
}
