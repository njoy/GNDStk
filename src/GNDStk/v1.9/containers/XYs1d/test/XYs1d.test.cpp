#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/XYs1d.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using XYs1d = v1_9::containers::XYs1d;
using Axes = v1_9::containers::Axes;
using Axis = v1_9::containers::Axis;
using Grid = v1_9::containers::Grid;
using Values = v1_9::containers::Values;
using Link = v1_9::containers::Link;

std::string chunk();
void verifyChunk( const XYs1d& );
std::string invalidName();

SCENARIO( "XYs1d" ) {

  GIVEN( "valid data for the component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      XYs1d chunk( std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                   Axes( std::nullopt,
                         std::vector< std::variant< Axis, Grid > >{
                             Axis( 1, "energy_in", "eV" ),
                             Axis( 0, "crossSection", "b" ) } ),
                   Values( std::vector< double >
                           { 1e-05, 1., 2.53e-2, 2., 2.5e+3, 3. } ) );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        std::ostringstream out;
        XML( Node( chunk ) ).write( out, false );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node node;
      node << chunk();
      XYs1d chunk( node );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        std::ostringstream out;
        XML( Node( chunk ) ).write( out, false );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a valid component instance" ) {

    WHEN( "the component is copied" ) {

      Node node;
      node << chunk();
      XYs1d chunk( node );

      // copy constructor
      XYs1d copy( chunk );

      // copy assignment
      XYs1d assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      XYs1d chunk( node );
      XYs1d chunk2( node );

      // move constructor
      XYs1d move( std::move( chunk ) );

      // move assignment
      XYs1d assign;
      assign = std::move( chunk2 );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data" ) {

    WHEN( "when the wrong node is used" ) {

      Node node;
      node << invalidName();

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( XYs1d( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<XYs1d>
   <axes>
      <axis index="0" label="crossSection" unit="b" />
      <axis index="1" label="energy_in" unit="eV" />
   </axes>
   <values valueType="Float64" start="0" length="6">1e-05 1 0.0253 2 2500 3</values>
</XYs1d>
)***";
}

void verifyChunk( const XYs1d& component ) {

  CHECK( std::nullopt == component.index() );
  CHECK( std::nullopt == component.label() );
  CHECK( std::nullopt == component.outerDomainValue() );
  CHECK( std::nullopt != component.axes() );

  CHECK( enums::Interpolation::linlin == component.interpolation() );

  // axes data
  decltype(auto) axis0 =
     std::get< Axis >( component.axes().value().axis_grid()[0] );

  CHECK( std::nullopt != axis0.index() );
  CHECK( std::nullopt != axis0.label() );
  CHECK( std::nullopt != axis0.unit() );

  CHECK( 0 == axis0.index().value() );
  CHECK( "crossSection" == axis0.label().value() );
  CHECK( "b" == axis0.unit().value() );

  decltype(auto) axis1 =
     std::get< Axis >( component.axes().value().axis_grid()[1] );

  CHECK( std::nullopt != axis1.index() );
  CHECK( std::nullopt != axis1.label() );
  CHECK( std::nullopt != axis1.unit() );

  CHECK( 1 == axis1.index().value() );
  CHECK( "energy_in" == axis1.label().value() );
  CHECK( "eV" == axis1.unit().value() );

  // values data
  CHECK( 6 == component.values().length() );
  CHECK( 0 == component.values().start() );
  CHECK( "Float64" == component.values().valueType().value() );

  CHECK( 6 == component.values().size() );
  CHECK( 6 == component.values().doubles().size() );

  CHECK( 1e-5 == Approx( component.values().doubles()[0] ) );
  CHECK( 1. == Approx( component.values().doubles()[1] ) );
  CHECK( 2.53e-2 == Approx( component.values().doubles()[2] ) );
  CHECK( 2. == Approx( component.values().doubles()[3] ) );
  CHECK( 2.5e+3 == Approx( component.values().doubles()[4] ) );
  CHECK( 3. == Approx( component.values().doubles()[5] ) );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName>
   <axes>
      <axis index="1" label="energy_in" unit="eV"/>
      <axis index="0" label="crossSection" unit="b"/>
   </axes>
   <values length="6" start="0" valueType="Float64">1e-05 1. 2.53e-2 2. 2.5e+3 3.</values>
</wrongName>
)***";
}
