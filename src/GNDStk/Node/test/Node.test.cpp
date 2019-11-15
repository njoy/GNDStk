#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

std::vector< std::string > allowedKeys{};
SCENARIO( "Testing the basic Node class" ){
  GIVEN( "a Node containing a single type (std::string)" ){
    using Node_string = GNDStk::AllKeysValidNode<std::string >;
    Node_string gndsNode{ "stringNode" };

    WHEN( "adding data" ){
      gndsNode.push_back( Node_string{ "child" } );
      gndsNode.push_back( Node_string{ "child" } );
      gndsNode.push_back( Node_string{ "stepchild" } );
      gndsNode.push_back( "body1" );
      gndsNode.push_back( "body2" );

      gndsNode.metadata( "key1", "value1" );
      gndsNode.metadata( "key2", "value2" );

      THEN( "the data can be verified" ){
        { // body
         auto body = gndsNode.body();
         CHECK( "body1" == std::get< std::string >( body[ 0 ] ) );
         CHECK( "body2" == std::get< std::string >( body[ 1 ] ) );
        }

        { // children
         CHECK( 3 == gndsNode.children().size() );
         CHECK( "stepchild" == gndsNode.children().back()->name() );
         
         auto childRange = gndsNode.children( "child" );
         auto stepchildRange = gndsNode.children( "stepchild" );
         
         CHECK( 2 == ranges::distance( childRange ) );
         CHECK( 1 == ranges::distance( stepchildRange ) );
        }
        { // metadata
          CHECK( "stringNode" == gndsNode.name() );
         
         CHECK( "value1" == gndsNode.metadata( "key1" ) );
         CHECK( "value2" == gndsNode.metadata( "key2" ) );
         
         const auto& metadata = gndsNode.metadata();
         CHECK( "value1" == metadata.at( "key1" ) );
         CHECK( "value2" == metadata.at( "key2" ) );
        }
      } // THEN
      WHEN( "asking for a non-existent key" ){
        THEN( "an exception is thrown" ){
          CHECK_THROWS_AS( gndsNode.metadata( "key3" ), std::out_of_range& );
        } // THEN
      } // WHEN
    } // WHEN
  } // GIVEN
} // SCENARIO

SCENARIO( "Testing a Node with multiple types" ){
  GIVEN( "a Node containing multiple types" ){
    using Node_t = GNDStk::AllKeysValidNode< int, double >;
    Node_t gndsNode{ "bi-type" };

    WHEN( "adding data" ){
      gndsNode.push_back( 3.0 );
      gndsNode.push_back( 2.0, 1 );

      THEN( "the data can be verified" ){
         auto body = gndsNode.body();
         CHECK( 3.0 == std::get< double >( body[ 0 ] ) );
         CHECK( 2.0 == std::get< double >( body[ 1 ] ) );
         CHECK( 1 == std::get< int >( body[ 2 ] ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
