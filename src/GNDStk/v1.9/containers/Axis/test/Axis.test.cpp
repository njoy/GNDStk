#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Axis.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Axis = v1_9::containers::Axis;

Node defaultChunk();
void verifyDefaultChunk( const Axis& );
Node chunk();
void verifyChunk( const Axis& );
Node invalidName();

SCENARIO( "Axis" ) {

  GIVEN( "valid data for a Axis" ) {

    WHEN( "the default constructor is used" ) {

      Axis chunk;

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyDefaultChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is given explicitly" ) {

      unsigned int index = 1;
      std::string label = "energy_in";
      std::string unit = "eV";

      Axis chunk( index, label, unit );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node core = chunk();
      Axis chunk( core );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      Node core = chunk();
      Axis chunk( core );

      // copy constructor
      Axis copy( chunk );

      // copy assignment
      Axis assign;
      assign = chunk;

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node core = chunk();
      Axis chunk( core );
      Axis chunk2( core );

      // move constructor
      Axis move( std::move( chunk ) );

      // copy assignment
      Axis assign;
      assign = std::move( chunk2 );

      THEN( "an Axis can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( assign );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Axis" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Axis( invalidName() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

Node defaultChunk() {

  Node chunk;
  chunk << "<axis/>";

  return chunk;
}

void verifyDefaultChunk( const Axis& component ) {

  CHECK( std::nullopt == component.index() );
  CHECK( std::nullopt == component.label() );
  CHECK( std::nullopt == component.unit() );

  CHECK( defaultChunk() == Node( component ) );
}

Node chunk() {

  Node chunk;
  chunk << "<axis index=\"1\" label=\"energy_in\" unit=\"eV\"/>";

  return chunk;
}

void verifyChunk( const Axis& component ) {

  CHECK( std::nullopt != component.index() );
  CHECK( std::nullopt != component.label() );
  CHECK( std::nullopt != component.unit() );

  CHECK( 1 == component.index().value() );
  CHECK( "energy_in" == component.label().value() );
  CHECK( "eV" == component.unit().value() );

  CHECK( 1 == component.index() );
  CHECK( "energy_in" == component.label() );
  CHECK( "eV" == component.unit() );

  CHECK( chunk() == Node( component ) );
}

Node invalidName() {

  // wrong name for the node
  return Node( "wrongName" );
}
