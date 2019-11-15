#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy;

SCENARIO( "Testing the basic axis node" ){
  GIVEN( "no initial metadata" ){
    GNDStk::nodes::Axis axis{};

    THEN( "an exception is thrown if you try to access the values" ){
      CHECK_THROWS_AS( axis.metadata( "index" ), std::out_of_range& );
      CHECK_THROWS_AS( axis.metadata( "label" ), std::out_of_range& );
      CHECK_THROWS_AS( axis.metadata( "unit" ), std::out_of_range& );

      CHECK_THROWS_AS( axis.metadata( "fakeNews" ), std::out_of_range& );
    } // THEN
  } // GIVEN

  GIVEN( "initial metadata" ){
    std::map< std::string, std::string > dMap{ 
      { "index", "0" },
      { "label", "energy_in" },
      { "unit", "eV" }
    };

    GNDStk::nodes::Axis axis{ dMap };
    THEN( "we can verify the initial values" ){
      
      CHECK( "0" == axis.metadata( "index" ) );
      CHECK( "energy_in" == axis.metadata( "label" ) );
      CHECK( "eV" == axis.metadata( "unit" ) );
    } // THEN
  } // GIVEN
  
} // SCENARIO
