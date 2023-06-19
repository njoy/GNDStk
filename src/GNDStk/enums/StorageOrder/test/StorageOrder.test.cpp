#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using StorageOrder = enums::StorageOrder;

SCENARIO( "StorageOrder" ) {

  GIVEN( "valid storage order values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "rowMajor" == enums::toString( StorageOrder::rowMajor ) );
        CHECK( "columnMajor" == enums::toString( StorageOrder::columnMajor ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( StorageOrder::rowMajor ==
               enums::fromString< StorageOrder >( "rowMajor" ) );
        CHECK( StorageOrder::columnMajor ==
               enums::fromString< StorageOrder >( "columnMajor" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< StorageOrder >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << StorageOrder::rowMajor << ' ' << StorageOrder::columnMajor;

        CHECK( "rowMajor columnMajor" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        StorageOrder value;
        std::istringstream in( "rowMajor columnMajor" );

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

        CHECK( true == enums::isStorageOrder( "rowMajor" ) );
        CHECK( true == enums::isStorageOrder( "columnMajor" ) );
        CHECK( false == enums::isStorageOrder( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
