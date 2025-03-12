
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/HashAlgorithm.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "HashAlgorithm" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "md5" == enum2string( HashAlgorithm::md5 ) );
        CHECK( "sha1" == enum2string( HashAlgorithm::sha1 ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( HashAlgorithm::md5 == string2enum< HashAlgorithm >( "md5" ) );
        CHECK( HashAlgorithm::sha1 == string2enum< HashAlgorithm >( "sha1" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< HashAlgorithm >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << HashAlgorithm::md5 << ' ' << HashAlgorithm::sha1;

        CHECK( "md5 sha1" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        HashAlgorithm value;
        std::istringstream in( "md5 sha1" );

        in >> value;
        CHECK( HashAlgorithm::md5 == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( HashAlgorithm::sha1 == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        HashAlgorithm value = HashAlgorithm::sha1;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( HashAlgorithm::sha1 == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isHashAlgorithm is used" ) {

      THEN( "registered frame values return true, "
            "unregistered frame values return false" ) {

        CHECK( true == isHashAlgorithm( "md5" ) );
        CHECK( true == isHashAlgorithm( "sha1" ) );
        CHECK( false == isHashAlgorithm( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
