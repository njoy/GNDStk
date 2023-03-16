#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Encoding = enums::Encoding;

SCENARIO( "Encoding" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "ascii" == enums::toString( Encoding::ascii ) );
        CHECK( "utf8" == enums::toString( Encoding::utf8 ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Encoding::ascii == enums::fromString< Encoding >( "ascii" ) );
        CHECK( Encoding::utf8 == enums::fromString< Encoding >( "utf8" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Encoding >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Encoding::ascii << ' ' << Encoding::utf8;

        CHECK( "ascii utf8" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Encoding value;
        std::istringstream in( "ascii utf8" );

        in >> value;
        CHECK( Encoding::ascii == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Encoding::utf8 == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Encoding value = Encoding::utf8;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Encoding::utf8 == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isEncoding is used" ) {

      THEN( "registered encoding values return true, "
            "unregistered encoding values return false" ) {

        CHECK( true == enums::isEncoding( "ascii" ) );
        CHECK( true == enums::isEncoding( "utf8" ) );
        CHECK( false == enums::isEncoding( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
