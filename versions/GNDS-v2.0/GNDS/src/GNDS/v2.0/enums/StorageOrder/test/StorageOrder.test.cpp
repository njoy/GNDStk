
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/StorageOrder.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "StorageOrder" ) {

  GIVEN( "valid storage order values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "row-major" == enum2string( StorageOrder::rowMajor ) );
        CHECK( "column-major" == enum2string( StorageOrder::columnMajor ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( StorageOrder::rowMajor ==
               string2enum< StorageOrder >( "row-major" ) );
        CHECK( StorageOrder::columnMajor ==
               string2enum< StorageOrder >( "column-major" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< StorageOrder >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << StorageOrder::rowMajor << ' ' << StorageOrder::columnMajor;

        CHECK( "row-major column-major" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        StorageOrder value;
        std::istringstream in( "row-major column-major" );

        in >> value;
        CHECK( StorageOrder::rowMajor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( StorageOrder::columnMajor == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        StorageOrder value = StorageOrder::columnMajor;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( StorageOrder::columnMajor == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isStorageOrder is used" ) {

      THEN( "registered storage order values return true, "
            "unregistered storage order values return false" ) {

        CHECK( true == isStorageOrder( "row-major" ) );
        CHECK( true == isStorageOrder( "column-major" ) );
        CHECK( false == isStorageOrder( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
