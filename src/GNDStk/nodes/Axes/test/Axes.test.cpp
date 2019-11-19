#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the the Axes node" ){
  GIVEN( "an Axes node" ){
    GNDStk::nodes::Axes axes{};

    std::map<std::string, std::string> axes0Meta{{"label", "energy_in" }};
    std::map<std::string, std::string> axes1Meta{{"label", "crossSection" }};

    axes.push_back( GNDStk::nodes::Axis{ axes0Meta } )
        .push_back( GNDStk::nodes::Axis{ axes1Meta } );

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
