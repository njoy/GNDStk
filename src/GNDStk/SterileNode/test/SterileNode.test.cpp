#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

template< const std::vector< std::string >& AllowedKeys >
struct SterileTest: public GNDStk::SterileNode< AllowedKeys > {
  using SN = GNDStk::SterileNode< AllowedKeys >;

public:
  SterileTest() = default;
  SterileTest( typename GNDStk::Metadata< AllowedKeys >::MapType& dMap ):
    SN( dMap )
  { }

  using SN::metadata;
};

std::vector< std::string > allowedKeys{ "key1", "key2" };
SCENARIO( "Testing the SterileNode" ){
  GIVEN( "a SterileNode with default map" ){
    std::map< std::string, std::string > dMap{ { "key1", "default1" } };
    SterileTest< allowedKeys > gndsNode{ dMap };

    WHEN( "adding metadata" ){
      gndsNode.metadata( "key2", "value2" );

      THEN( "the metadata can be verified" ){
      
        CHECK( "default1" == gndsNode.metadata( "key1" ) );
        CHECK( "value2" == gndsNode.metadata( "key2" ) );
        
        const auto& metadata = gndsNode.metadata();
        CHECK( "default1" == metadata.at( "key1" ) );
        CHECK( "value2" == metadata.at( "key2" ) );
      } // THEN
      WHEN( "asking for a non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( gndsNode.metadata( "key3", "value3" ), 
                           std::out_of_range& );
        } // THEN
      } // WHEN
    } // WHEN
  } // GIVEN
  GIVEN( "a SterileNode without default map" ){
    SterileTest< allowedKeys > gndsNode{};

    WHEN( "adding metadata" ){
      gndsNode.metadata( "key1", "value1" );
      gndsNode.metadata( "key2", "value2" );

      THEN( "the metadata can be verified" ){
      
        CHECK( "value1" == gndsNode.metadata( "key1" ) );
        CHECK( "value2" == gndsNode.metadata( "key2" ) );
        
        const auto& metadata = gndsNode.metadata();
        CHECK( "value1" == metadata.at( "key1" ) );
        CHECK( "value2" == metadata.at( "key2" ) );
      } // THEN
      WHEN( "asking for a non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( gndsNode.metadata( "key3", "value3" ), 
                           std::out_of_range& );
        } // THEN
      } // WHEN
    } // WHEN
  } // GIVEN
} // SCENARIO

