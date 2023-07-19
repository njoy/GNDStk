#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Parity = enums::Parity;

SCENARIO( "Parity" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "-1" == enums::toString( Parity::minus ) );
        CHECK( "+1" == enums::toString( Parity::plus ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Parity::minus == enums::fromString< Parity >( "-1" ) );
        CHECK( Parity::plus == enums::fromString< Parity >( "+1" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Parity >( "unregistered" ) );
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

        CHECK( true == enums::isParity( "-1" ) );
        CHECK( true == enums::isParity( "+1" ) );
        CHECK( false == enums::isParity( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
