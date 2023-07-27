#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Length = enums::Length;

SCENARIO( "Length" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "m" == enums::toString( Length::m ) );
        CHECK( "cm" == enums::toString( Length::cm ) );
        CHECK( "fm" == enums::toString( Length::fm ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Length::m == enums::fromString< Length >( "m" ) );
        CHECK( Length::cm == enums::fromString< Length >( "cm" ) );
        CHECK( Length::fm == enums::fromString< Length >( "fm" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Length >( "unregistered" ) );
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

        CHECK( true == enums::isLengthUnit( "m" ) );
        CHECK( true == enums::isLengthUnit( "cm" ) );
        CHECK( true == enums::isLengthUnit( "fm" ) );
        CHECK( false == enums::isLengthUnit( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
