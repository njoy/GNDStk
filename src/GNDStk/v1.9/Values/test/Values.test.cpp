#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/Values.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
template < typename ValueType > using Values = v1_9::Values< ValueType >;

node chunk();
void verifyChunk( const Values< double >& );
node invalidChunk();

SCENARIO( "Values" ) {

  GIVEN( "valid data for a Values" ) {

    WHEN( "the data is given explicitly" ) {

      std::vector< double > values = { 1., 2., 3., 4., 5., 6. };

      Values< double > chunk( std::move( values ) );

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      node core = chunk();
      const node ccore = chunk();
      Values< double > chunk( core );
      Values< double > cchunk( ccore );

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( chunk );
        verifyChunk( cchunk );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( basic::pcdata ) == &chunk.node()( basic::pcdata ) );
        CHECK( &ccore( basic::pcdata ) != &cchunk.node()( basic::pcdata ) );
      } // THEN
    } // WHEN

    WHEN( "the data is copied" ) {

      node core = chunk();
      const node ccore = chunk();
      Values< double > chunk( core );
      Values< double > cchunk( ccore );

      // copy constructor
      Values< double > copy( chunk );
      Values< double > ccopy( cchunk );

      // copy assignment
      Values< double > assign;
      Values< double > cassign;
      assign = chunk;
      cassign = cchunk;

      THEN( "a Values can be constructed and members can be tested" ) {

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

        CHECK( &core( basic::pcdata ) != &copy.node()( basic::pcdata ) );
        CHECK( &ccore( basic::pcdata ) != &ccopy.node()( basic::pcdata ) );

        CHECK( &core( basic::pcdata ) != &assign.node()( basic::pcdata ) );
        CHECK( &ccore( basic::pcdata ) != &cassign.node()( basic::pcdata ) );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      node core = chunk();
      const node ccore = chunk();
      Values< double > chunk( core );
      Values< double > cchunk( ccore );

      // move constructor
      Values< double > move( std::move( chunk ) );
      Values< double > cmove( std::move( cchunk ) );

      THEN( "a Values can be constructed and members can be tested" ) {

        verifyChunk( move );
        verifyChunk( cmove );
      } // THEN

      THEN( "only the non-const node and its children remains in sync with "
            "the internal node" ) {

        CHECK( &core == &chunk.node() );
        CHECK( &ccore != &cchunk.node() );

        CHECK( &core( basic::pcdata ) == &chunk.node()( basic::pcdata ) );
        CHECK( &ccore( basic::pcdata ) != &cchunk.node()( basic::pcdata ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for an Values" ) {

    WHEN( "when the wrong node is used" ) {

      THEN( "an exception is thrown" ) {

        CHECK_THROWS( Values< double >( invalidChunk() ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

node chunk() {

  node chunk( "values" );

  chunk.add( "valueType", "Float64" );
  chunk.add( "start", "0" );
  chunk.add( "length", "6" );

  node pcdata( "pcdata" );
  pcdata.add( "text", "1 2 3 4 5 6" );

  chunk.add( "pcdata" ) = pcdata;

  return chunk;
}

void verifyChunk( const Values< double >& component ) {

  CHECK( "Float64" == component.valueType() );
  CHECK( 0 == component.start() );
  CHECK( 6 == component.length() );
  CHECK( 6 == component.values().size() );

  CHECK( 1. == component.values()[0] );
  CHECK( 2. == component.values()[1] );
  CHECK( 3. == component.values()[2] );
  CHECK( 4. == component.values()[3] );
  CHECK( 5. == component.values()[4] );
  CHECK( 6. == component.values()[5] );

  CHECK( chunk() == component.node() );
}

node invalidChunk() {

  // wrong name for the node
  return node( "wrongName" );
}
