
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/DateType.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "DateType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "accepted" == enum2string( DateType::accepted ) );
        CHECK( "available" == enum2string( DateType::available ) );
        CHECK( "copyrighted" == enum2string( DateType::copyrighted ) );
        CHECK( "collected" == enum2string( DateType::collected ) );
        CHECK( "created" == enum2string( DateType::created ) );
        CHECK( "issued" == enum2string( DateType::issued ) );
        CHECK( "submitted" == enum2string( DateType::submitted ) );
        CHECK( "updated" == enum2string( DateType::updated ) );
        CHECK( "valid" == enum2string( DateType::valid ) );
        CHECK( "withdrawn" == enum2string( DateType::withdrawn ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( DateType::accepted == string2enum< DateType >( "accepted" ) );
        CHECK( DateType::available == string2enum< DateType >( "available" ) );
        CHECK( DateType::copyrighted == string2enum< DateType >( "copyrighted" ) );
        CHECK( DateType::collected == string2enum< DateType >( "collected" ) );
        CHECK( DateType::created == string2enum< DateType >( "created" ) );
        CHECK( DateType::issued == string2enum< DateType >( "issued" ) );
        CHECK( DateType::submitted == string2enum< DateType >( "submitted" ) );
        CHECK( DateType::updated == string2enum< DateType >( "updated" ) );
        CHECK( DateType::valid == string2enum< DateType >( "valid" ) );
        CHECK( DateType::withdrawn == string2enum< DateType >( "withdrawn" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< DateType >( "unregistered" ) );
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

        CHECK( true == isDateType( "accepted" ) );
        CHECK( true == isDateType( "available" ) );
        CHECK( true == isDateType( "copyrighted" ) );
        CHECK( true == isDateType( "collected" ) );
        CHECK( true == isDateType( "created" ) );
        CHECK( true == isDateType( "issued" ) );
        CHECK( true == isDateType( "submitted" ) );
        CHECK( true == isDateType( "updated" ) );
        CHECK( true == isDateType( "valid" ) );
        CHECK( true == isDateType( "withdrawn" ) );
        CHECK( false == isDateType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
