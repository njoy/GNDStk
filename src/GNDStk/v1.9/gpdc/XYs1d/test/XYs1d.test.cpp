#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/gpdc/XYs1d.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::gpdc::Axis;
using Grid = v1_9::gpdc::Grid;
using Axes = v1_9::gpdc::Axes;
using Values = v1_9::gpdc::Values;
using XYs1d_t = v1_9::gpdc::XYs1d;

Node defaultChunk();
void verifyDefaultChunk( const XYs1d_t& );
Node chunk();
void verifyChunk( const XYs1d_t& );
Node invalidName();
Node invalidChunk();

SCENARIO( "XYs1d_t" ) {

  GIVEN( "valid data for an XYs1d" ) {

    WHEN( "the default constructor is used" ) {

      XYs1d_t chunk;

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyDefaultChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly" ) {

      std::string label = "eval";
      Interpolation interpolation = Interpolation::loglog;
      Axes axes( { Axis( 1, "energy_in", "eV" ),
                   Axis( 0, "cross section", "b" ) } );
      Values values( { 1, 2, 3, 4, 5, 6 } );

      XYs1d_t chunk( std::nullopt, interpolation, label, std::nullopt,
                   axes, values );

      THEN( "an XYs1d can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "a custom constructor is used" ) {

      std::string label = "eval";
      Interpolation interpolation = Interpolation::loglog;
      std::vector< double > x = { 1, 3, 5 };
      std::vector< double > y = { 2, 4, 6 };
      std::string xLabel = "energy_in";
      std::string xUnit = "eV";
      std::string yLabel = "cross section";
      std::string yUnit = "b";

      XYs1d_t chunk( label, x, y, xLabel, xUnit, yLabel, yUnit, interpolation );

      THEN( "an XYs1d can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      XYs1d_t chunk( core );

      THEN( "an XYs1d can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      Node core = chunk();
      XYs1d_t chunk( core );

      // copy constructor
      XYs1d_t copy( chunk );

      // copy assignment
      XYs1d_t assign;
      assign = chunk;

      THEN( "an XYs1d can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node core = chunk();
      XYs1d_t chunk( core );
      XYs1d_t chunk2( core );

      // move constructor
      XYs1d_t move( std::move( chunk ) );

      // copy assignment
      XYs1d_t assign;
      assign = std::move( chunk2 );

      THEN( "an XYs1d can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an XYs1d" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( XYs1d_t( invalidName() ) );
      } // THEN
    } // WHEN

    WHEN( "when the node is illegal" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( XYs1d_t( invalidChunk() ) );
      } // THEN
    } // WHEN

    WHEN( "when the x and y sizes are wrong" ) {

      std::string label = "eval";
      std::vector< double > x = { 1, 3, 5 };
      std::vector< double > y = { 2, 4, 6, 8 }; // one too many
      std::string xLabel = "energy_in";
      std::string xUnit = "eV";
      std::string yLabel = "cross section";
      std::string yUnit = "b";

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( XYs1d_t( label, x, y, xLabel, xUnit, yLabel, yUnit ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node defaultChunk() {

  Node chunk( "XYs1d" );

  Node values( "values" );

  Node pcdata( "pcdata" );
  pcdata.add( "text", "" );

  values.add( "pcdata" ) = pcdata;

  chunk.add( "values" ) = values;

  return chunk;
}

void verifyDefaultChunk( const XYs1d_t& component ) {

  CHECK( std::nullopt == component.index() );
  CHECK( Interpolation::linlin == component.interpolation() );
  CHECK( std::nullopt == component.label() );
  CHECK( std::nullopt == component.outerDomainValue() );
  CHECK( std::nullopt == component.axes() );

//  CHECK( defaultChunk() == Node( component ) );
}

Node chunk() {

  Node chunk( "XYs1d" );

  chunk.add( "label", "eval" );
  chunk.add( "interpolation", "log-log" );

  Node axes( "axes" );

  Node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );

  Node axis2( "axis" );
  axis2.add( "index", "0" );
  axis2.add( "label", "cross section" );
  axis2.add( "unit", "b" );

  axes.add( "axis" ) = axis1;
  axes.add( "axis" ) = axis2;

  chunk.add( "axes" ) = axes;

  Node values( "values" );

  Node pcdata( "pcdata" );
  pcdata.add( "text", "1. 2. 3. 4. 5. 6." );

  values.add( "pcdata" ) = pcdata;

  chunk.add( "values" ) = values;

  return chunk;
}

void verifyChunk( const XYs1d_t& component ) {

  CHECK( std::nullopt == component.index() );
  CHECK( std::nullopt != component.label() );
  CHECK( std::nullopt == component.outerDomainValue() );
  CHECK( std::nullopt != component.axes() );

  CHECK( Interpolation::loglog == component.interpolation() );

  CHECK( "eval" == component.label().value() );

  CHECK( std::nullopt == component.axes().value().href() );
  CHECK( std::nullopt != component.axes().value().axis() );
  CHECK( std::nullopt == component.axes().value().grid() );

  CHECK( 2 == component.axes().value().axis()->size() );
  CHECK( 2 == component.axes().value().elements().size() );
  CHECK( 2 == component.axes().value().size() );

  CHECK( 0 == component.axes().value().axis().value()[0].index().value() );
  CHECK( "cross section" == component.axes().value().axis().value()[0].label().value() );
  CHECK( "b" == component.axes().value().axis().value()[0].unit().value() );

  CHECK( 1 == component.axes().value().axis().value()[1].index().value() );
  CHECK( "energy_in" == component.axes().value().axis().value()[1].label().value() );
  CHECK( "eV" == component.axes().value().axis().value()[1].unit().value() );

  CHECK( "Float64" == component.values().valueType() );
  CHECK( 0 == component.values().start() );
  CHECK( 6 == component.values().length() );
  CHECK( 6 == component.values().values().size() );

  CHECK( 1. == component.values().values()[0] );
  CHECK( 2. == component.values().values()[1] );
  CHECK( 3. == component.values().values()[2] );
  CHECK( 4. == component.values().values()[3] );
  CHECK( 5. == component.values().values()[4] );
  CHECK( 6. == component.values().values()[5] );

//  CHECK( chunk() == Node( component ) );
}

Node invalidName() {

  // wrong name for the node
  return Node( "wrongName" );
}

Node invalidChunk() {

  Node chunk( "XYs1d" );

  chunk.add( "label", "eval" );
  chunk.add( "interpolation", "log-log" );

  Node axes( "axes" );

  Node axis1( "axis" );
  axis1.add( "index", "1" );
  axis1.add( "label", "energy_in" );
  axis1.add( "unit", "eV" );

  Node axis2( "axis" );
  axis2.add( "index", "0" );
  axis2.add( "label", "cross section" );
  axis2.add( "unit", "b" );

  axes.add( "axis" ) = axis1;
  axes.add( "axis" ) = axis2;

  chunk.add( "axes" ) = axes;

  Node values( "values" );

  Node pcdata( "pcdata" );
  pcdata.add( "text", "1. 2. 3. 4. 5. 6. 7." );

  values.add( "pcdata" ) = pcdata;

  chunk.add( "values" ) = values;

  return chunk;
}
