#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Axis.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::Axis;

std::string chunk();
void verifyChunk( const Axis& );
std::string chunkWithOptionalUnit();
void verifyChunkWithOptionalUnit( const Axis& );

SCENARIO( "Axis" ) {

  GIVEN( "valid data for a Axis" ) {

    std::string string = chunk();

    WHEN( "the data is given explicitly" ) {

      unsigned int index = 1;
      std::string label = "energy_in";
      std::string unit = "eV";

      Axis chunk( index, label, unit );

      THEN( "an Axis can be constructed and members can be tested" ) {

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
      auto core = tree.top()( --basic::axis );

      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

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

      Axis chunk = tree.top()( Axis{} / --basic::axis );

      THEN( "an Axis can be constructed and members can be tested" ) {

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

  GIVEN( "valid data for a Axis without a unit" ) {

    std::string string = chunkWithOptionalUnit();

    WHEN( "the data is given explicitly" ) {

      unsigned int index = 1;
      std::string label = "energy_in";

      Axis chunk( index, label );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
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
      auto core = tree.top()( --basic::axis );

      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
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

      Axis chunk = tree.top()( Axis{} / --basic::axis );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunkWithOptionalUnit( chunk );
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
                 <axis index="1" label="energy_in" unit="eV"/></reactionSuite>)***";
}

void verifyChunk( const Axis& chunk ) {

  CHECK( 1 == chunk.index() );
  CHECK( "energy_in" == chunk.label() );
  CHECK( std::nullopt != chunk.unit() );
  CHECK( "eV" == chunk.unit().value() );
}

std::string chunkWithOptionalUnit() {

  return R"***(<reactionSuite>
                 <axis index="1" label="energy_in"/></reactionSuite>)***";
}

void verifyChunkWithOptionalUnit( const Axis& chunk ) {

  CHECK( 1 == chunk.index() );
  CHECK( "energy_in" == chunk.label() );
  CHECK( std::nullopt == chunk.unit() );
}
