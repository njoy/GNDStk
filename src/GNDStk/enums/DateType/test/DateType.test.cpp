#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using DateType = enums::DateType;

SCENARIO( "DateType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "accepted" == enums::toString( DateType::accepted ) );
        CHECK( "available" == enums::toString( DateType::available ) );
        CHECK( "copyrighted" == enums::toString( DateType::copyrighted ) );
        CHECK( "collected" == enums::toString( DateType::collected ) );
        CHECK( "created" == enums::toString( DateType::created ) );
        CHECK( "issued" == enums::toString( DateType::issued ) );
        CHECK( "submitted" == enums::toString( DateType::submitted ) );
        CHECK( "updated" == enums::toString( DateType::updated ) );
        CHECK( "valid" == enums::toString( DateType::valid ) );
        CHECK( "withdrawn" == enums::toString( DateType::withdrawn ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( DateType::accepted == enums::fromString< DateType >( "accepted" ) );
        CHECK( DateType::available == enums::fromString< DateType >( "available" ) );
        CHECK( DateType::copyrighted == enums::fromString< DateType >( "copyrighted" ) );
        CHECK( DateType::collected == enums::fromString< DateType >( "collected" ) );
        CHECK( DateType::created == enums::fromString< DateType >( "created" ) );
        CHECK( DateType::issued == enums::fromString< DateType >( "issued" ) );
        CHECK( DateType::submitted == enums::fromString< DateType >( "submitted" ) );
        CHECK( DateType::updated == enums::fromString< DateType >( "updated" ) );
        CHECK( DateType::valid == enums::fromString< DateType >( "valid" ) );
        CHECK( DateType::withdrawn == enums::fromString< DateType >( "withdrawn" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< DateType >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << DateType::accepted << ' ' << DateType::available << ' '
            << DateType::copyrighted << ' ' << DateType::collected << ' '
            << DateType::created << ' ' << DateType::issued << ' '
            << DateType::submitted << ' ' << DateType::updated << ' '
            << DateType::valid << ' ' << DateType::withdrawn;

        CHECK( "accepted available copyrighted collected "
               "created issued submitted updated valid withdrawn" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        DateType value;
        std::istringstream in( "accepted available copyrighted collected created issued submitted updated valid withdrawn" );

        in >> value;
        CHECK( DateType::accepted == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::available == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::copyrighted == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::collected == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::created == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::issued == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::submitted == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::updated == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::valid == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DateType::withdrawn == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        DateType value = DateType::accepted;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( DateType::accepted == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isDateType is used" ) {

      THEN( "registered date types return true, "
            "unregistered date types return false" ) {

        CHECK( true == enums::isDateType( "accepted" ) );
        CHECK( true == enums::isDateType( "available" ) );
        CHECK( true == enums::isDateType( "copyrighted" ) );
        CHECK( true == enums::isDateType( "collected" ) );
        CHECK( true == enums::isDateType( "created" ) );
        CHECK( true == enums::isDateType( "issued" ) );
        CHECK( true == enums::isDateType( "submitted" ) );
        CHECK( true == enums::isDateType( "updated" ) );
        CHECK( true == enums::isDateType( "valid" ) );
        CHECK( true == enums::isDateType( "withdrawn" ) );
        CHECK( false == enums::isDateType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
