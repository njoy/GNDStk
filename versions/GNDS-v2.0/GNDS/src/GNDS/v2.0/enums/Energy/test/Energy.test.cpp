
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Energy.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Energy" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "eV" == enum2string( Energy::eV ) );
        CHECK( "MeV" == enum2string( Energy::MeV ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Energy::eV == string2enum< Energy >( "eV" ) );
        CHECK( Energy::MeV == string2enum< Energy >( "MeV" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Energy >( "unregistered" ) );
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

        CHECK( true == isEnergyUnit( "eV" ) );
        CHECK( true == isEnergyUnit( "MeV" ) );
        CHECK( false == isEnergyUnit( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
