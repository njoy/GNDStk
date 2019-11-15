
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

std::string testNode();
pugi::xml_document doc;

auto fromXML( const pugi::xml_node& xmlNode ) -> GNDStk::Node< std::string >;

SCENARIO( "Creating a generic Node from XML" ){
  GIVEN( "a pugixml::node" ){
    doc.load_string( testNode().c_str() );

    WHEN( "a string node is created" ){
      auto genericNode = fromXML( doc.child( "regions1d" ) );

      // using Node_t = decltype( genericNode );
      
      THEN( "we can check the hierarchy" ){
        { // axes
          auto axes = genericNode.children( "axes" );
          CHECK( 1 == ranges::distance( axes ) );
          // CHECK( 0 == axes[0].metadata().size() );
        }

        {
          auto XYs1d = genericNode.children( "XYs1d" );
          CHECK( 2 == ranges::distance( XYs1d ) );
        }
        
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

auto fromXML( const pugi::xml_node& xmlNode ) -> GNDStk::Node< std::string >{

  // Log::info( "Creating node from XML named: {}", xmlNode.name() );
  GNDStk::Node< std::string > returnNode{ xmlNode.name() };

  // Log::info( "\tAttributes:" );
  for( const auto& attr : xmlNode.attributes()){
    // Log::info( "\t\tname: {}, value: {}", attr.name(), attr.value() );
    returnNode.metadata( attr.name(), attr.value() );
  }

  for( const auto& child : xmlNode.children() ){
    returnNode.push_back( fromXML( child ) );
  }

  return returnNode;
}

std::string testNode(){
  return R"xml(
<regions1d>
  <axes>
    <axis index="1" label="energy_in" unit="eV"/>
    <axis index="0" label="crossSection" unit="b"/>
  </axes>
  <XYs1d index="0">
    <values length="4">
      1.00000000e-05 0.500000e+00 2.53000000e-02 2.000000e+00 4.00000000e+05
    </values>
  </XYs1d>
  <XYs1d index="1">
    <values length="4">
      8.80000000e+07 1.182806e+00 8.90000000e+07 1.171179e+00
    </values>
  </XYs1d>
</regions1d>
                )xml";
}
