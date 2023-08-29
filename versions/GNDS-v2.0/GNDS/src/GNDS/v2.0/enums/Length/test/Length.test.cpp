
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Length.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Length" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "m" == enum2string( Length::m ) );
        CHECK( "cm" == enum2string( Length::cm ) );
        CHECK( "fm" == enum2string( Length::fm ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Length::m == string2enum< Length >( "m" ) );
        CHECK( Length::cm == string2enum< Length >( "cm" ) );
        CHECK( Length::fm == string2enum< Length >( "fm" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Length >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Length::m << ' ' << Length::cm << ' ' << Length::fm;

        CHECK( "m cm fm" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Length value;
        std::istringstream in( "m cm fm" );

        in >> value;
        CHECK( Length::m == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Length::cm == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Length::fm == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Length value = Length::m;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Length::m == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isLengthUnit is used" ) {

      THEN( "registered units return true, unregistered units return false" ) {

        CHECK( true == isLengthUnit( "m" ) );
        CHECK( true == isLengthUnit( "cm" ) );
        CHECK( true == isLengthUnit( "fm" ) );
        CHECK( false == isLengthUnit( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
