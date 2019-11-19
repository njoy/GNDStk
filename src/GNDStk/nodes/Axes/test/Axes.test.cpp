#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the the Axes node" ){
  GIVEN( "an Axes node" ){
    GNDStk::nodes::Axes axes{};

    axes.push_back( GNDStk::nodes::Axis{ {{"label", "energy_in" }} } )
        .push_back( GNDStk::nodes::Axis{ {{"label", "crossSection" }} } );

    THEN( "the contained data can be verified" ){
      // auto axises = axes.children< GNDStk::nodes::Axis >();
      auto axises = axes.axis();
      CHECK( 2 == ranges::distance( axises ) );

    } // THEN

    WHEN( "metadata is added" ){
      THEN( "an exception is thrown" ){
        CHECK_THROWS_AS( axes.metadata( "axis", "1" ), std::out_of_range& );
      } // THEN
    } // WHEN
  } // GIVEN
  
} // SCENARIO
