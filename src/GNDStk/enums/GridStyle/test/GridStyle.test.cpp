#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using GridStyle = enums::GridStyle;

SCENARIO( "GridStyle" ) {

  GIVEN( "valid unit values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "none" == enums::toString( GridStyle::none ) );
        CHECK( "link" == enums::toString( GridStyle::link ) );
        CHECK( "points" == enums::toString( GridStyle::points ) );
        CHECK( "boundaries" == enums::toString( GridStyle::boundaries ) );
        CHECK( "parameters" == enums::toString( GridStyle::parameters ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( GridStyle::none ==
               enums::fromString< GridStyle >( "none" ) );
        CHECK( GridStyle::link ==
               enums::fromString< GridStyle >( "link" ) );
        CHECK( GridStyle::points ==
               enums::fromString< GridStyle >( "points" ) );
        CHECK( GridStyle::boundaries ==
               enums::fromString< GridStyle >( "boundaries" ) );
        CHECK( GridStyle::parameters ==
               enums::fromString< GridStyle >( "parameters" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< GridStyle >( "unregistered" ) );
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

        CHECK( true == enums::isGridStyle( "none" ) );
        CHECK( true == enums::isGridStyle( "link" ) );
        CHECK( true == enums::isGridStyle( "points" ) );
        CHECK( true == enums::isGridStyle( "boundaries" ) );
        CHECK( true == enums::isGridStyle( "parameters" ) );
        CHECK( false == enums::isGridStyle( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
