#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Regions1d.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Regions1d = v1_9::containers::Regions1d;
using XYs1d = v1_9::containers::XYs1d;
using Axes = v1_9::containers::Axes;
using Axis = v1_9::containers::Axis;
using Grid = v1_9::containers::Grid;
using Values = v1_9::containers::Values;
using Link = v1_9::containers::Link;

std::string chunk();
void verifyChunk( const Regions1d& );
std::string invalidName();

SCENARIO( "Regions1d" ) {

  GIVEN( "valid data for the component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      Regions1d chunk(
          std::nullopt,                                // optional label
          std::nullopt,                                // optional outer domain value
          std::vector< XYs1d >{

              XYs1d( 0, std::nullopt, std::nullopt, std::nullopt,
                     std::nullopt,
                     Values( std::nullopt, std::nullopt, std::nullopt,
                             std::vector< double >{ 0.0253, 4.34057, 30000, 1.62386 } ) ),
              XYs1d( 1, std::nullopt, std::nullopt, std::nullopt,
                     std::nullopt,
                     Values( std::nullopt, std::nullopt, std::nullopt,
                             std::vector< double >{ 30000, 1.65691, 2e+7, 2.35696 } ) )
          },                                           // vector of 1D functions
          Axes( std::nullopt,
                std::vector< std::variant< Axis, Grid > >{
                    Axis( 1, "energy_in", "eV" ),
                    Axis( 0, "crossSection", "b" ) } ) // optional axes
      );

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
      Regions1d chunk( node );

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
      Regions1d chunk( node );

      // copy constructor
      Regions1d copy( chunk );

      // copy assignment
      Regions1d assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      Regions1d chunk( node );
      Regions1d chunk2( node );

      // move constructor
      Regions1d move( std::move( chunk ) );

      // move assignment
      Regions1d assign;
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

        CHECK_THROWS( Regions1d( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<regions1d>
   <XYs1d index="0">
      <values length="4" start="0" valueType="Float64">0.0253 4.34057 30000 1.62386</values>
   </XYs1d>
   <XYs1d index="1">
      <values length="4" start="0" valueType="Float64">30000 1.65691 2e+07 2.35696</values>
   </XYs1d>
   <axes>
      <axis index="0" label="crossSection" unit="b" />
      <axis index="1" label="energy_in" unit="eV" />
   </axes>
</regions1d>
)***";
}

void verifyChunk( const Regions1d& component ) {

  CHECK( std::nullopt == component.label() );
  CHECK( std::nullopt == component.outerDomainValue() );
  CHECK( std::nullopt != component.axes() );

  // axes data
  CHECK( 2 == component.axes().value().axis_grid().size() );

  decltype(auto) axis0 = std::get< Axis >( component.axes().value().axis_grid()[0] );
  CHECK( std::nullopt != axis0.index() );
  CHECK( std::nullopt != axis0.label() );
  CHECK( std::nullopt != axis0.unit() );
  CHECK( 0 == axis0.index().value() );
  CHECK( "crossSection" == axis0.label().value() );
  CHECK( "b" == axis0.unit().value() );

  decltype(auto) axis1 = std::get< Axis >( component.axes().value().axis_grid()[1] );
  CHECK( std::nullopt != axis1.index() );
  CHECK( std::nullopt != axis1.label() );
  CHECK( std::nullopt != axis1.unit() );
  CHECK( 1 == axis1.index().value() );
  CHECK( "energy_in" == axis1.label().value() );
  CHECK( "eV" == axis1.unit().value() );

  // function data
  CHECK( 2 == component.XYs1d().size() );

  decltype(auto) xys1d0 = component.XYs1d()[0];
  CHECK( 0 == xys1d0.index() );
  CHECK( std::nullopt == xys1d0.label() );
  CHECK( std::nullopt == xys1d0.outerDomainValue() );
  CHECK( std::nullopt == xys1d0.axes() );
  CHECK( enums::Interpolation::linlin == xys1d0.interpolation() );
  CHECK( 4 == xys1d0.values().length() );
  CHECK( 0 == xys1d0.values().start() );
  CHECK( "Float64" == xys1d0.values().valueType().value() );
  CHECK( 4 == xys1d0.values().size() );
  CHECK( 4 == xys1d0.values().doubles().size() );
  CHECK( 0.0253 == Approx( xys1d0.values().doubles()[0] ) );
  CHECK( 4.34057 == Approx( xys1d0.values().doubles()[1] ) );
  CHECK( 30000 == Approx( xys1d0.values().doubles()[2] ) );
  CHECK( 1.62386 == Approx( xys1d0.values().doubles()[3] ) );

  decltype(auto) xys1d1 = component.XYs1d()[1];
  CHECK( 1 == xys1d1.index() );
  CHECK( std::nullopt == xys1d1.label() );
  CHECK( std::nullopt == xys1d1.outerDomainValue() );
  CHECK( std::nullopt == xys1d1.axes() );
  CHECK( enums::Interpolation::linlin == xys1d1.interpolation() );
  CHECK( 4 == xys1d1.values().length() );
  CHECK( 0 == xys1d1.values().start() );
  CHECK( "Float64" == xys1d1.values().valueType().value() );
  CHECK( 4 == xys1d1.values().size() );
  CHECK( 4 == xys1d1.values().doubles().size() );
  CHECK( 30000 == Approx( xys1d1.values().doubles()[0] ) );
  CHECK( 1.65691 == Approx( xys1d1.values().doubles()[1] ) );
  CHECK( 2e+7 == Approx( xys1d1.values().doubles()[2] ) );
  CHECK( 2.35696 == Approx( xys1d1.values().doubles()[3] ) );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName>
   <XYs1d index="0">
      <values>0.0253 4.34057 30000 1.62386</values>
   </XYs1d>
   <XYs1d index="1">
      <values>30000 1.65691 2e+07 2.35696</values>
   </XYs1d>
   <axes>
      <axis index="0" label="crossSection" unit="b" />
      <axis index="1" label="energy_in" unit="eV" />
   </axes>
</wrongName>
)***";
}
