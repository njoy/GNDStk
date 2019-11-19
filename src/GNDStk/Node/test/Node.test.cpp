#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

/*
template< typename T >
auto children( const T& v, const unsigned int index ){
  return v
    | ranges::view::filter(
      [&]( auto& child ){ return index == child.value.index(); } )
    | ranges::view::transform(
      [&]( auto& child ){ return std::get< child.value.index() >( child.value ); } );
}

SCENARIO( "Trying things out" ){

  using var_t = std::variant< int, std::string >;
  struct Node_t{ var_t value; };
  using vec_t = std::vector< Node_t >;

  vec_t collection{};

  collection.push_back( Node_t{ "three" } );
  collection.push_back( Node_t{2} );
  collection.push_back( Node_t{1} );

  Log::info( "Collection size: {}", collection.size() );

  auto ints = children( collection, 1 );

  // Log::info( "ints size: {}", ints.size() );
  // Log::info( "ints[0]: {}", get( ints[0] ) );
  for( auto N : ints ){
    // Log::info( "i: {}", std::get< int >( N.value ) );
    Log::info( "i: {}", N );
  }

} // SCENARIO
 */

std::vector< std::string > allowedKeys{ "key1", "key2" };
SCENARIO( "Testing the basic Node class" ){
  GIVEN( "a Node containing a single type (std::string)" ){
    using Node_string = GNDStk::Node<allowedKeys, std::string >;
    Node_string gndsNode{ { { "key1", "default1" } }};

    WHEN( "adding data" ){
      gndsNode.metadata( "key2", "value2" );

      gndsNode.push_back( "child1" );
      gndsNode.push_back( "child2", "child3" );
      gndsNode.push_back( "stepchild" );

      THEN( "the data can be verified" ){
        { // children
          CHECK( 4 == ranges::distance( gndsNode.children() ) );
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

template< typename V >
const int& get( const V& v ){ return std::get< int >( v ); }

auto visitor = []( auto&& v ){ return v; };

SCENARIO( "Testing a Node with multiple types" ){
  GIVEN( "a Node containing multiple types" ){
    using Node_t = GNDStk::AllKeysValidNode< int, double >;
    Node_t gndsNode{};

    WHEN( "adding data" ){
      gndsNode.push_back( 1.15, 3.3 );
      gndsNode.push_back( 2.2, 4 );

      THEN( "the data can be verified" ){
        // auto intChildren = gndsNode.children( 0 );
        auto intChildren = gndsNode.children< int >();

        std::vector< int > iChildren{ 4 };
        CHECK( 1 == ranges::distance( intChildren ) );
        for( auto&& [reference, test] : 
             ranges::view::zip( iChildren, intChildren ) ){
          CHECK( reference == test );
        }

        auto doubleChildren = gndsNode.children< double >();
        CHECK( 3 == ranges::distance( doubleChildren ) );
        std::vector< double > dChildren{ 1.15, 3.3, 2.2 };
        for( auto&& [reference, test] : 
             ranges::view::zip( dChildren, doubleChildren ) ){
          CHECK( reference == test );
        }

        auto children = gndsNode.children();
        CHECK( 1.15 == std::get< double >( children[ 0 ] ) );
        CHECK( 3.3 == std::get< double >( children[ 1 ] ) );
        CHECK( 2.2 == std::get< double >( children[ 2 ] ) );
        CHECK( 4 == std::get< int >( children[ 3 ] ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
