#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/ConstantRadius.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using ConstantRadius = v1_9::ConstantRadius;

node chunk();
void verifyChunk( const ConstantRadius& );
node invalidChunk();

SCENARIO( "ConstantRadius" ) {

  GIVEN( "valid data for a ConstantRadius" ) {

    WHEN( "the data is given explicitly" ) {

      std::string label = "eval";
      double radius = 9.41;
      double energyMin = 1e-5;
      double energyMax = 3e+4;
      std::string radiusUnit = "fm";
      std::string energyUnit = "eV";

      ConstantRadius chunk( label, radius, energyMin, energyMax,
                            energyUnit, radiusUnit );

      THEN( "an ConstantRadius can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      node core = chunk();
      const node ccore = chunk();
      ConstantRadius chunk( core );
      ConstantRadius cchunk( ccore );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
        verifyChunk( cchunk );
      } // THEN

      THEN( "only the non-const node remains in sync with the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      node core = chunk();
      const node ccore = chunk();
      ConstantRadius chunk( core );
      ConstantRadius cchunk( ccore );

      // copy constructor
      ConstantRadius copy( chunk );
      ConstantRadius ccopy( cchunk );

      // copy assignment
      ConstantRadius assign;
      ConstantRadius cassign;
      assign = chunk;
      cassign = cchunk;

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( ccopy );
        verifyChunk( assign );
        verifyChunk( cassign );
      } // THEN

      THEN( "none of the nodes remains in sync with the internal nodes" ) {

        CHECK( &core != &copy.node() );
        CHECK( &ccore != &ccopy.node() );
        CHECK( &core != &assign.node() );
        CHECK( &ccore != &cassign.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      node core = chunk();
      const node ccore = chunk();
      ConstantRadius chunk( core );
      ConstantRadius cchunk( ccore );

      // move constructor
      ConstantRadius move( std::move( chunk ) );
      ConstantRadius cmove( std::move( cchunk ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( cmove );
      } // THEN

      THEN( "only the non-const node remains in sync with the internal node" ) {

        CHECK( &core == &move.node() );
        CHECK( &ccore != &cmove.node() );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an ConstantRadius" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( ConstantRadius( invalidChunk() ) );
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

void verifyChunk( const ConstantRadius& chunk ) {

  CHECK( 9.41 == Approx( chunk.radius() ) );
  CHECK( 1e-5 == Approx( chunk.energyMin() ) );
  CHECK( 30000. == Approx( chunk.energyMax() ) );

  CHECK( "eval" == chunk.label() );
  CHECK( 9.41 == Approx( chunk.constant() ) );
  CHECK( 1e-5 == Approx( chunk.domainMin() ) );
  CHECK( 30000. == Approx( chunk.domainMax() ) );

  CHECK( 2 == chunk.axes().size() );

  CHECK( 0 == chunk.axes().axis(0).index() );
  CHECK( "radius" == chunk.axes().axis(0).label() );
  CHECK( std::nullopt != chunk.axes().axis(0).unit() );
  CHECK( "fm" == chunk.axes().axis(0).unit().value() );

  CHECK( 1 == chunk.axes().axis(1).index() );
  CHECK( "energy_in" == chunk.axes().axis(1).label() );
  CHECK( std::nullopt != chunk.axes().axis(1).unit() );
  CHECK( "eV" == chunk.axes().axis(1).unit().value() );
}

node invalidChunk() {

  // wrong name for the node
  return node( "wrongName" );
}
