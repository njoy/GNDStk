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

    WHEN( "the data is given explicitly - full move constructor" ) {

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

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly - full copy constructor" ) {

      std::string label = "eval";
      double constant = 9.41;
      double domainMin = 1e-5;
      double domainMax = 3e+4;
      Axes axes( { Axis( 1, "energy_in", "eV" ),
                   Axis( 0, "radius", "fm" ) } );

      Constant1D chunk( label, constant, domainMin, domainMax,
                        std::nullopt, axes );

      THEN( "an Constant1D can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly - convenience constructor" ) {

      std::string label = "eval";
      double constant = 9.41;
      double domainMin = 1e-5;
      double domainMax = 3e+4;
      std::string domainLabel = "energy_in";
      std::string domainUnit = "eV";
      std::string constantLabel = "radius";
      std::string constantUnit = "fm";

      Constant1D chunk( label, constant, domainMin, domainMax,
                        constantLabel, domainLabel,
                        constantUnit, domainUnit );

      THEN( "an Constant1D can be constructed and members can be tested" ) {

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

      Constant1D chunk( core );

      THEN( "an Constant1D can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        //! @todo there is currently no operator==() available to compare nodes
        // CHECK( chunk() == chunk.node() );
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

void verifyChunk( const Constant1D& chunk ) {

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
