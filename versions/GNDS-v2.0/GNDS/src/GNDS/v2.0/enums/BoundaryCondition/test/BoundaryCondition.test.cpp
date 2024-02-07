
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/BoundaryCondition.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "BoundaryCondition" ) {

  GIVEN( "valid BoundaryCondition values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "EliminateShiftFunction"
               == enum2string( BoundaryCondition::EliminateShiftFunction ) );
        CHECK( "NegativeOrbitalMomentum"
               == enum2string( BoundaryCondition::NegativeOrbitalMomentum ) );
        CHECK( "Brune" == enum2string( BoundaryCondition::Brune ) );
        CHECK( "Given" == enum2string( BoundaryCondition::Given ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( BoundaryCondition::EliminateShiftFunction
               == string2enum< BoundaryCondition >( "EliminateShiftFunction" ) );
        CHECK( BoundaryCondition::NegativeOrbitalMomentum
               == string2enum< BoundaryCondition >( "NegativeOrbitalMomentum" ) );
        CHECK( BoundaryCondition::Brune == string2enum< BoundaryCondition >( "Brune" ) );
        CHECK( BoundaryCondition::Given == string2enum< BoundaryCondition >( "Given" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< BoundaryCondition >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << BoundaryCondition::EliminateShiftFunction << ' '
            << BoundaryCondition::NegativeOrbitalMomentum << ' '
            << BoundaryCondition::Brune << ' '
            << BoundaryCondition::Given;

        CHECK( "EliminateShiftFunction NegativeOrbitalMomentum Brune Given" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        BoundaryCondition value;
        std::istringstream in( "EliminateShiftFunction NegativeOrbitalMomentum Brune Given" );

        in >> value;
        CHECK( BoundaryCondition::EliminateShiftFunction == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( BoundaryCondition::NegativeOrbitalMomentum == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( BoundaryCondition::Brune == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( BoundaryCondition::Given == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        BoundaryCondition value = BoundaryCondition::EliminateShiftFunction;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( BoundaryCondition::EliminateShiftFunction == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isBoundaryCondition is used" ) {

      THEN( "registered BoundaryCondition values return true, "
            "unregistered BoundaryCondition values return false" ) {

        CHECK( true == isBoundaryCondition( "EliminateShiftFunction" ) );
        CHECK( true == isBoundaryCondition( "NegativeOrbitalMomentum" ) );
        CHECK( true == isBoundaryCondition( "Brune" ) );
        CHECK( true == isBoundaryCondition( "Given" ) );
        CHECK( false == isBoundaryCondition( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
