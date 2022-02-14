#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk/v1.9/containers/Grid.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Values = v1_9::containers::Values;
using Link = v1_9::containers::Link;
using Grid = v1_9::containers::Grid;

std::string chunk();
void verifyChunk( const Grid& );
std::string chunkWithLink();
void verifyChunkWithLink( const Grid& );
std::string invalidName();

SCENARIO( "Grid" ) {

  GIVEN( "valid data for the component with a Values component" ) {

    std::string string = chunk();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      unsigned index = 2;
      std::string label = "row_energy_bounds";
      std::string unit = "eV";
      enums::GridStyle style = enums::GridStyle::boundaries;
      std::vector< double > values = { 1e-5, 2e7 };

      Grid chunk( index, std::nullopt, label, style, unit, Values( values ) );

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
      Grid chunk( node );

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

  GIVEN( "valid data for the component with a Link component" ) {

    std::string string = chunkWithLink();

    WHEN( "autogenerated constructor: the data is given explicitly" ) {

      unsigned index = 1;
      std::string label = "column_energy_bounds";
      std::string unit = "eV";
      enums::GridStyle style = enums::GridStyle::link;
      std::string href = "../../grid[@index='2']/values";

      Grid chunk( index, std::nullopt, label, style, unit,
                  Link( href ) );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunkWithLink( chunk );
      } // THEN

      THEN( "it can be written in XML" ) {

        std::ostringstream out;
        XML( Node( chunk ) ).write( out, false );

        CHECK( out.str() == string );
      } // THEN
    } // WHEN

    WHEN( "the data is constructed from a node" ) {

      Node node;
      node << chunkWithLink();
      Grid chunk( node );

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunkWithLink( chunk );
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
      Grid chunk( node );

      // copy constructor
      Grid copy( chunk );

      // copy assignment
      Grid assign;
      assign = chunk;

      THEN( "the component can be constructed and members can be tested" ) {

        verifyChunk( copy );
        verifyChunk( assign );
      } // THEN
    } // WHEN

    WHEN( "the data is moved" ) {

      Node node;
      node << chunk();
      Grid chunk( node );
      Grid chunk2( node );

      // move constructor
      Grid move( std::move( chunk ) );

      // move assignment
      Grid assign;
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

        CHECK_THROWS( Grid( node ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {

  return
R"***(<grid index="2" label="row_energy_bounds" style="boundaries" unit="eV">
   <values valueType="Float64" start="0" length="2">1e-05 2e+07</values>
</grid>
)***";
}

void verifyChunk( const Grid& component ) {

  CHECK( std::nullopt != component.index() );
  CHECK( std::nullopt != component.label() );
  CHECK( std::nullopt != component.style() );
  CHECK( std::nullopt != component.unit() );

  CHECK( 2 == component.index().value() );
  CHECK( "row_energy_bounds" == component.label().value() );
  CHECK( "eV" == component.unit().value() );
  CHECK( enums::GridStyle::boundaries == component.style().value() );

  CHECK( 2 == component.index() );
  CHECK( "row_energy_bounds" == component.label() );
  CHECK( "eV" == component.unit() );
  CHECK( enums::GridStyle::boundaries == component.style() );

  decltype(auto) values = std::get< Values >( component.link_values() );
  CHECK( 2 == values.length() );
  CHECK( 0 == values.start() );
  CHECK( "Float64" == values.valueType().value() );

  CHECK( 2 == values.size() );
  CHECK( 2 == values.doubles().size() );

  CHECK( 1e-5 == Approx( values.doubles()[0] ) );
  CHECK( 2e+7 == Approx( values.doubles()[1] ) );
}

std::string chunkWithLink() {

  return
R"***(<grid index="1" label="column_energy_bounds" style="link" unit="eV">
   <link href="../../grid[@index='2']/values" />
</grid>
)***";
}

void verifyChunkWithLink( const Grid& component ) {

  CHECK( std::nullopt != component.index() );
  CHECK( std::nullopt != component.label() );
  CHECK( std::nullopt != component.style() );
  CHECK( std::nullopt != component.unit() );

  CHECK( 1 == component.index().value() );
  CHECK( "column_energy_bounds" == component.label().value() );
  CHECK( "eV" == component.unit().value() );
  CHECK( enums::GridStyle::link == component.style().value() );

  CHECK( 1 == component.index() );
  CHECK( "column_energy_bounds" == component.label() );
  CHECK( "eV" == component.unit() );
  CHECK( enums::GridStyle::link == component.style() );

  decltype(auto) link = std::get< Link >( component.link_values() );
  CHECK( "../../grid[@index='2']/values" == link.href() );
}

std::string invalidName() {

  // wrong name for the node
  return
R"***(<wrongName index="1" label="column_energy_bounds" style="link" unit="eV">
   <link href="../../grid[@index='2']/values" />
</wrongName>
)***";
}
