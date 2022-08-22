#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using InterpolationQualifier = enums::InterpolationQualifier;

SCENARIO( "InterpolationQualifier" ) {

  GIVEN( "valid interpolation values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "direct" == enums::toString( InterpolationQualifier::direct ) );
        CHECK( "unitBase" == enums::toString( InterpolationQualifier::unitBase ) );
        CHECK( "correspondingEnergies"
               == enums::toString( InterpolationQualifier::correspondingEnergies ) );
        CHECK( "correspondingPoints"
               == enums::toString( InterpolationQualifier::correspondingPoints ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( InterpolationQualifier::direct
               == enums::fromString< InterpolationQualifier >( "direct" ) );
        CHECK( InterpolationQualifier::unitBase
               == enums::fromString< InterpolationQualifier >( "unitBase" ) );
        CHECK( InterpolationQualifier::correspondingEnergies
               == enums::fromString< InterpolationQualifier >( "correspondingEnergies" ) );
        CHECK( InterpolationQualifier::correspondingPoints
               == enums::fromString< InterpolationQualifier >( "correspondingPoints" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< InterpolationQualifier >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << InterpolationQualifier::direct << ' '
            << InterpolationQualifier::unitBase << ' '
            << InterpolationQualifier::correspondingEnergies << ' '
            << InterpolationQualifier::correspondingPoints;

        CHECK( "direct unitBase correspondingEnergies correspondingPoints"
               == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        InterpolationQualifier value;
        std::istringstream in( "direct unitBase correspondingEnergies "
                               "correspondingPoints" );

        in >> value;
        CHECK( InterpolationQualifier::direct == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( InterpolationQualifier::unitBase == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( InterpolationQualifier::correspondingEnergies == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( InterpolationQualifier::correspondingPoints == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        InterpolationQualifier value = InterpolationQualifier::unitBase;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( InterpolationQualifier::unitBase == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isInterpolationQualifier is used" ) {

      THEN( "registered interpolation qualifier values return true, "
            "unregistered interpolation values return false" ) {

        CHECK( true == enums::isInterpolationQualifier( "direct" ) );
        CHECK( true == enums::isInterpolationQualifier( "unitBase" ) );
        CHECK( true == enums::isInterpolationQualifier( "correspondingEnergies" ) );
        CHECK( true == enums::isInterpolationQualifier( "correspondingPoints" ) );
        CHECK( false == enums::isInterpolationQualifier( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
