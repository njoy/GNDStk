
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Parity.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Parity" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "-1" == enum2string( Parity::minus ) );
        CHECK( "+1" == enum2string( Parity::plus ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Parity::minus == string2enum< Parity >( "-1" ) );
        CHECK( Parity::plus == string2enum< Parity >( "+1" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Parity >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Parity::minus << ' ' << Parity::plus;

        CHECK( "-1 +1" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Parity value;
        std::istringstream in( "-1 +1" );

        in >> value;
        CHECK( Parity::minus == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Parity::plus == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Parity value = Parity::plus;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Parity::plus == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isParity is used" ) {

      THEN( "registered parity values return true, "
            "unregistered parity values return false" ) {

        CHECK( true == isParity( "-1" ) );
        CHECK( true == isParity( "+1" ) );
        CHECK( false == isParity( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
