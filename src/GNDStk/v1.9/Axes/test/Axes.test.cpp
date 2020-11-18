#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Axes.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::Axis;
using Axes = v1_9::Axes;

std::string chunk();
void verifyChunk( const Axes& );

SCENARIO( "Axes" ) {

  GIVEN( "valid data for a Axes" ) {

    std::string string = chunk();

    WHEN( "the data is given explicitly" ) {

      std::vector< Axis > axes = { Axis( 1, "energy_in", "eV" ),
                                   Axis( 0, "radius", "fm" ) };

      Axes chunk( std::move( axes ) );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        // std::ostringstream out;
        // core.write( out );

        // CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the data is taken from a node" ) {

      std::istringstream input( string );
      Tree<> tree( input, "xml" );
      auto core = tree.top()( basic::axes );

      Axes chunk( core );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        // std::ostringstream out;
        // core.write( out );

        // CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the core interface is used to convert" ) {

      std::istringstream input( string );
      Tree<> tree( input, "xml" );

      Axes chunk = tree.top()( Axes{} / basic::axes );

      THEN( "an Axes can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be converted to a core node" ) {

        node core = chunk.node();

        // std::ostringstream out;
        // core.write( out );

        // CHECK( out.str() == string );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return R"***(<reactionSuite>
                 <axes>
                   <axis index="1" label="energy_in" unit="eV"/>
                   <axis index="0" label="radius" unit="fm"/></axes></reactionSuite>)***";
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
