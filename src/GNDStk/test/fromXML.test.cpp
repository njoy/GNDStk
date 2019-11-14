
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

std::string testNode();
pugi::xml_document doc;

SCENARIO( "Creating a generic Node from XML" ){
  GIVEN( "a pugixml::node" ){
    doc.load_string( testNode().c_str() );

    WHEN( "a string node is created" ){
      auto genericNode = GNDStk::fromXML( doc.child( "regions1d" ) );

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
