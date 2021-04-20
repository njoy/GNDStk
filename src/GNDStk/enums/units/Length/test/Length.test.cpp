#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Length = enums::units::Length;

SCENARIO( "Length" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "m" == enums::units::toString( Length::m ) );
        CHECK( "cm" == enums::units::toString( Length::cm ) );
        CHECK( "fm" == enums::units::toString( Length::fm ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Length::m == enums::units::fromString< Length >( "m" ) );
        CHECK( Length::cm == enums::units::fromString< Length >( "cm" ) );
        CHECK( Length::fm == enums::units::fromString< Length >( "fm" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::units::fromString< Length >( "unregistered" ) );
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

        CHECK( true == enums::units::isLengthUnit( "m" ) );
        CHECK( true == enums::units::isLengthUnit( "cm" ) );
        CHECK( true == enums::units::isLengthUnit( "fm" ) );
        CHECK( false == enums::units::isLengthUnit( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
