
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Encoding.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Encoding" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "ascii" == enum2string( Encoding::ascii ) );
        CHECK( "utf8" == enum2string( Encoding::utf8 ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Encoding::ascii == string2enum< Encoding >( "ascii" ) );
        CHECK( Encoding::utf8 == string2enum< Encoding >( "utf8" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Encoding >( "unregistered" ) );
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

        CHECK( true == isEncoding( "ascii" ) );
        CHECK( true == isEncoding( "utf8" ) );
        CHECK( false == isEncoding( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
