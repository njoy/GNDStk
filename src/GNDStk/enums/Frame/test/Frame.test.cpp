#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Frame = enums::Frame;

SCENARIO( "Frame" ) {

  GIVEN( "valid frame values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "lab" == enums::toString( Frame::lab ) );
        CHECK( "centerOfMass" == enums::toString( Frame::centerOfMass ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Frame::lab == enums::fromString< Frame >( "lab" ) );
        CHECK( Frame::centerOfMass == enums::fromString< Frame >( "centerOfMass" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Frame >( "unregistered" ) );
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

    WHEN( "isFrameScheme is used" ) {

      THEN( "registered frame values return true, unregistered frame values return false" ) {

        CHECK( true == enums::isFrameScheme( "lab" ) );
        CHECK( true == enums::isFrameScheme( "centerOfMass" ) );
        CHECK( false == enums::isFrameScheme( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
