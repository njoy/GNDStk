
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/GridStyle.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "GridStyle" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "none" == enum2string( GridStyle::none ) );
        CHECK( "link" == enum2string( GridStyle::link ) );
        CHECK( "points" == enum2string( GridStyle::points ) );
        CHECK( "boundaries" == enum2string( GridStyle::boundaries ) );
        CHECK( "parameters" == enum2string( GridStyle::parameters ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( GridStyle::none ==
               string2enum< GridStyle >( "none" ) );
        CHECK( GridStyle::link ==
               string2enum< GridStyle >( "link" ) );
        CHECK( GridStyle::points ==
               string2enum< GridStyle >( "points" ) );
        CHECK( GridStyle::boundaries ==
               string2enum< GridStyle >( "boundaries" ) );
        CHECK( GridStyle::parameters ==
               string2enum< GridStyle >( "parameters" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< GridStyle >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << GridStyle::none << ' ' << GridStyle::link << ' '
            << GridStyle::points << ' ' << GridStyle::boundaries << ' '
            << GridStyle::parameters;

        CHECK( "none link points boundaries parameters" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        GridStyle value;
        std::istringstream in( "none link points boundaries parameters" );

        in >> value;
        CHECK( GridStyle::none == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( GridStyle::link == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( GridStyle::points == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( GridStyle::boundaries == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( GridStyle::parameters == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        GridStyle value = GridStyle::points;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( GridStyle::points == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isGridStyle is used" ) {

      THEN( "registered units return true, unregistered units return false" ) {

        CHECK( true == isGridStyle( "none" ) );
        CHECK( true == isGridStyle( "link" ) );
        CHECK( true == isGridStyle( "points" ) );
        CHECK( true == isGridStyle( "boundaries" ) );
        CHECK( true == isGridStyle( "parameters" ) );
        CHECK( false == isGridStyle( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
