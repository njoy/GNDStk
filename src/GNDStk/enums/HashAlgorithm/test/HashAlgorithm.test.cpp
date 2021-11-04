#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using HashAlgorithm = enums::HashAlgorithm;

SCENARIO( "HashAlgorithm" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "md5" == enums::toString( HashAlgorithm::md5 ) );
        CHECK( "sha1" == enums::toString( HashAlgorithm::sha1 ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( HashAlgorithm::md5 == enums::fromString< HashAlgorithm >( "md5" ) );
        CHECK( HashAlgorithm::sha1 == enums::fromString< HashAlgorithm >( "sha1" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< HashAlgorithm >( "unregistered" ) );
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

        CHECK( true == enums::isHashAlgorithm( "md5" ) );
        CHECK( true == enums::isHashAlgorithm( "sha1" ) );
        CHECK( false == enums::isHashAlgorithm( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
