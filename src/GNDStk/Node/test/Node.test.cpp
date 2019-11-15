#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

std::vector< std::string > allowedKeys{ "key1", "key2" };
SCENARIO( "Testing the basic Node class" ){
  GIVEN( "a Node containing a single type (std::string)" ){
    using Node_string = GNDStk::Node<allowedKeys, std::string >;
    std::map< std::string, std::string > dMap{ { "key1", "default1" } };
    Node_string gndsNode{ dMap };

    WHEN( "adding data" ){
      gndsNode.metadata( "key2", "value2" );

      gndsNode.push_back( "child1" );
      gndsNode.push_back( "child2", "child3" );
      gndsNode.push_back( "stepchild" );

      THEN( "the data can be verified" ){
        { // children
          CHECK( 4 == ranges::distance( gndsNode.children( 0 ) ) );
          auto children = gndsNode.children();
          CHECK( 4 == children.size() );
          CHECK( "child1" == std::get< std::string >( children[ 0 ] ) );
          CHECK( "child1" == std::get< 0 >( children[ 0 ] ) );
          CHECK( "child2" == std::get< 0 >( children[ 1 ] ) );
          CHECK( "child3" == std::get< 0 >( children[ 2 ] ) );
          CHECK( "stepchild" == std::get< 0 >( children[ 3 ] ) );
        }
        { // metadata
         CHECK( "default1" == gndsNode.metadata( "key1" ) );
         CHECK( "value2" == gndsNode.metadata( "key2" ) );
         
         const auto& metadata = gndsNode.metadata();
         CHECK( "default1" == metadata.at( "key1" ) );
         CHECK( "value2" == metadata.at( "key2" ) );
        }
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

SCENARIO( "Testing a Node with multiple types" ){
  GIVEN( "a Node containing multiple types" ){
    using Node_t = GNDStk::AllKeysValidNode< int, double >;
    Node_t gndsNode{ 1.15 };

    WHEN( "adding data" ){
      gndsNode.push_back( 3.3 );
      gndsNode.push_back( 2.2, 4 );

      THEN( "the data can be verified" ){
        auto intChildren = gndsNode.children( 0 );

        CHECK( 1 == ranges::distance( intChildren ) );
        // CHECK( 4 == std::get< 0 >( intChildren[ 0 ] ) );

        // auto doubleChildren = gndsNode.children( 1 );
        // CHECK( 2 == ranges::distance( gndsNode.children( 1 ) ) );
        // CHECK( 3.3 == std::get< 1 >( doubleChildren[ 0 ] ) );
        // CHECK( 2.2 == std::get< 1 >( doubleChildren[ 1 ] ) );

        auto children = gndsNode.children();
        CHECK( 1.15 == std::get< double >( children[ 0 ] ) );
        CHECK( 3.3 == std::get< double >( children[ 1 ] ) );
        CHECK( 2.2 == std::get< double >( children[ 2 ] ) );
        CHECK( 4 == std::get< int >( children[ 3 ] ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
