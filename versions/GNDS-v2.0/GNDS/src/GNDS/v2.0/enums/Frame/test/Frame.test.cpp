
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Frame.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Frame" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "lab" == enum2string( Frame::lab ) );
        CHECK( "centerOfMass" == enum2string( Frame::centerOfMass ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Frame::lab ==
               string2enum< Frame >( "lab" ) );
        CHECK( Frame::centerOfMass ==
               string2enum< Frame >( "centerOfMass" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Frame >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Frame::lab << ' ' << Frame::centerOfMass;

        CHECK( "lab centerOfMass" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Frame value;
        std::istringstream in( "lab centerOfMass" );

        in >> value;
        CHECK( Frame::lab == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Frame::centerOfMass == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Frame value = Frame::centerOfMass;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Frame::centerOfMass == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isFrame is used" ) {

      THEN( "registered frame values return true, "
            "unregistered frame values return false" ) {

        CHECK( true == isFrame( "lab" ) );
        CHECK( true == isFrame( "centerOfMass" ) );
        CHECK( false == isFrame( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
