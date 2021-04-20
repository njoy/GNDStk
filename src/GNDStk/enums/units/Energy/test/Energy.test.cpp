#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Energy = enums::units::Energy;

SCENARIO( "Energy" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "eV" == enums::units::toString( Energy::eV ) );
        CHECK( "MeV" == enums::units::toString( Energy::MeV ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Energy::eV == enums::units::fromString< Energy >( "eV" ) );
        CHECK( Energy::MeV == enums::units::fromString< Energy >( "MeV" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::units::fromString< Energy >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Energy::eV << ' ' << Energy::MeV;

        CHECK( "eV MeV" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Energy value;
        std::istringstream in( "eV MeV" );

        in >> value;
        CHECK( Energy::eV == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Energy::MeV == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Energy value = Energy::eV;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Energy::eV == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isEnergyUnit is used" ) {

      THEN( "registered units return true, unregistered units return false" ) {

        CHECK( true == enums::units::isEnergyUnit( "eV" ) );
        CHECK( true == enums::units::isEnergyUnit( "MeV" ) );
        CHECK( false == enums::units::isEnergyUnit( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
