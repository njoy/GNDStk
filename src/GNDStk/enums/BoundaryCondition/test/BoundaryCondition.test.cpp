#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using BoundaryCondition = enums::BoundaryCondition;

SCENARIO( "BoundaryCondition" ) {

  GIVEN( "valid BoundaryCondition values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "EliminateShiftFunction"
               == enums::toString( BoundaryCondition::EliminateShiftFunction ) );
        CHECK( "NegativeOrbitalMomentum"
               == enums::toString( BoundaryCondition::NegativeOrbitalMomentum ) );
        CHECK( "Brune" == enums::toString( BoundaryCondition::Brune ) );
        CHECK( "Given" == enums::toString( BoundaryCondition::Given ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( BoundaryCondition::EliminateShiftFunction
               == enums::fromString< BoundaryCondition >( "EliminateShiftFunction" ) );
        CHECK( BoundaryCondition::NegativeOrbitalMomentum
               == enums::fromString< BoundaryCondition >( "NegativeOrbitalMomentum" ) );
        CHECK( BoundaryCondition::Brune == enums::fromString< BoundaryCondition >( "Brune" ) );
        CHECK( BoundaryCondition::Given == enums::fromString< BoundaryCondition >( "Given" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< BoundaryCondition >( "unregistered" ) );
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

        CHECK( true == enums::isBoundaryCondition( "EliminateShiftFunction" ) );
        CHECK( true == enums::isBoundaryCondition( "NegativeOrbitalMomentum" ) );
        CHECK( true == enums::isBoundaryCondition( "Brune" ) );
        CHECK( true == enums::isBoundaryCondition( "Given" ) );
        CHECK( false == enums::isBoundaryCondition( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
