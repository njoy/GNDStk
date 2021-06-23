#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Axes.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axes = v1_9::containers::Axes;
using Axis = v1_9::containers::Axis;
using Grid = v1_9::containers::Grid;
using Values = v1_9::containers::Values;
using Link = v1_9::containers::Link;

std::string chunk();
void verifyChunk( const Axes& );
std::string invalidName();

SCENARIO( "Axes" ) {

  GIVEN( "valid data for the component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      std::vector< std::variant< Axis, Grid > > axis = {

        Axis( 1, "energy_in", "eV" ),
        Axis( 0, "radius", "fm" )
      };

      Axes chunk( std::nullopt, axis );

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
      Axes chunk( node );

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
      Axes chunk( node );

      // copy constructor
      Axes copy( chunk );

      // copy assignment
      Axes assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      Axes chunk( node );
      Axes chunk2( node );

      // move constructor
      Axes move( std::move( chunk ) );

      // move assignment
      Axes assign;
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

        CHECK_THROWS( Axes( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<axes>
   <axis index="0" label="radius" unit="fm" />
   <axis index="1" label="energy_in" unit="eV" />
</axes>
)***";
}

void verifyChunk( const Axes& component ) {

  CHECK( std::nullopt == component.href() );

  CHECK( 2 == component.choice().size() );
  CHECK( 2 == component.size() );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // indexing into the vector and accessing the variant directly
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  decltype(auto) axis_i0 = std::get< Axis >( component.choice()[0] );

  CHECK( std::nullopt != axis_i0.index() );
  CHECK( std::nullopt != axis_i0.label() );
  CHECK( std::nullopt != axis_i0.unit() );

  CHECK( 0 == axis_i0.index().value() );
  CHECK( "radius" == axis_i0.label().value() );
  CHECK( "fm" == axis_i0.unit().value() );

  decltype(auto) axis_i1 = std::get< Axis >( component.choice()[1] );

  CHECK( std::nullopt != axis_i1.index() );
  CHECK( std::nullopt != axis_i1.label() );
  CHECK( std::nullopt != axis_i1.unit() );

  CHECK( 1 == axis_i1.index().value() );
  CHECK( "energy_in" == axis_i1.label().value() );
  CHECK( "eV" == axis_i1.unit().value() );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // using the index based choice getter and accessing the variant directly
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//! @todo the underlying getters do not seem to be able to find the index 0
//! @todo a compilation issue exists, where a pointer is returned instead of a reference?

//  decltype(auto) axis_ii0 = std::get< Axis >( component.choice( 0 ) );
//
//  CHECK( std::nullopt != axis_ii0.index() );
//  CHECK( std::nullopt != axis_ii0.label() );
//  CHECK( std::nullopt != axis_ii0.unit() );
//
//  CHECK( 0 == axis_ii0.index().value() );
//  CHECK( "radius" == axis_ii0.label().value() );
//  CHECK( "fm" == axis_ii0.unit().value() );
//
//  decltype(auto) axis_ii1 = std::get< Axis >( component.choice( 1 ) );
//
//  CHECK( std::nullopt != axis_ii1.index() );
//  CHECK( std::nullopt != axis_ii1.label() );
//  CHECK( std::nullopt != axis_ii1.unit() );
//
//  CHECK( 1 == axis_ii1.index().value() );
//  CHECK( "energy_in" == axis_ii1.label().value() );
//  CHECK( "eV" == axis_ii1.unit().value() );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // using the label based choice getter and accessing the variant directly
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//  decltype(auto) axis_iii0 = std::get< Axis >( component.choice( "radius" ) );
//
//  CHECK( std::nullopt != axis_iii0.index() );
//  CHECK( std::nullopt != axis_iii0.label() );
//  CHECK( std::nullopt != axis_iii0.unit() );
//
//  CHECK( 0 == axis_iii0.index().value() );
//  CHECK( "radius" == axis_iii0.label().value() );
//  CHECK( "fm" == axis_iii0.unit().value() );
//
//  decltype(auto) axis_iii1 = std::get< Axis >( component.choice( "energy_in" ) );
//
//  CHECK( std::nullopt != axis_iii1.index() );
//  CHECK( std::nullopt != axis_iii1.label() );
//  CHECK( std::nullopt != axis_iii1.unit() );
//
//  CHECK( 1 == axis_iii1.index().value() );
//  CHECK( "energy_in" == axis_iii1.label().value() );
//  CHECK( "eV" == axis_iii1.unit().value() );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // using the index based axis getter
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//  decltype(auto) axis_iv0 = component.axis( 0 );
//
//  CHECK( std::nullopt != axis_iv0.index() );
//  CHECK( std::nullopt != axis_iv0.label() );
//  CHECK( std::nullopt != axis_iv0.unit() );
//
//  CHECK( 0 == axis_iv0.index().value() );
//  CHECK( "radius" == axis_iv0.label().value() );
//  CHECK( "fm" == axis_iv0.unit().value() );
//
//  decltype(auto) axis_iv1 = component.axis( 1 );
//
//  CHECK( std::nullopt != axis_iv1.index() );
//  CHECK( std::nullopt != axis_iv1.label() );
//  CHECK( std::nullopt != axis_iv1.unit() );
//
//  CHECK( 1 == axis_iv1.index().value() );
//  CHECK( "energy_in" == axis_iv1.label().value() );
//  CHECK( "eV" == axis_iv1.unit().value() );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // using the label based axis getter
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//  decltype(auto) axis_v0 = component.axis( "radius" );
//
//  CHECK( std::nullopt != axis_v0.index() );
//  CHECK( std::nullopt != axis_v0.label() );
//  CHECK( std::nullopt != axis_v0.unit() );
//
//  CHECK( 0 == axis_v0.index().value() );
//  CHECK( "radius" == axis_v0.label().value() );
//  CHECK( "fm" == axis_v0.unit().value() );
//
//  decltype(auto) axis_v1 = component.axis( "energy_in" );
//
//  CHECK( std::nullopt != axis_v1.index() );
//  CHECK( std::nullopt != axis_v1.label() );
//  CHECK( std::nullopt != axis_v1.unit() );
//
//  CHECK( 1 == axis_v1.index().value() );
//  CHECK( "energy_in" == axis_v1.label().value() );
//  CHECK( "eV" == axis_v1.unit().value() );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName>
  <axis index="1" label="energy_in" unit="eV" />
  <axis index="0" label="radius" unit="fm" /></wrongName>
)***";
}
