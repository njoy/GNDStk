
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/InterpolationQualifier.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "InterpolationQualifier" ) {

  GIVEN( "valid interpolation values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "direct" == enum2string( InterpolationQualifier::direct ) );
        CHECK( "unitBase" == enum2string( InterpolationQualifier::unitBase ) );
        CHECK( "correspondingEnergies"
               == enum2string( InterpolationQualifier::correspondingEnergies ) );
        CHECK( "correspondingPoints"
               == enum2string( InterpolationQualifier::correspondingPoints ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( InterpolationQualifier::direct
               == string2enum< InterpolationQualifier >( "direct" ) );
        CHECK( InterpolationQualifier::unitBase
               == string2enum< InterpolationQualifier >( "unitBase" ) );
        CHECK( InterpolationQualifier::correspondingEnergies
               == string2enum< InterpolationQualifier >( "correspondingEnergies" ) );
        CHECK( InterpolationQualifier::correspondingPoints
               == string2enum< InterpolationQualifier >( "correspondingPoints" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< InterpolationQualifier >( "unregistered" ) );
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

        CHECK( true == isInterpolationQualifier( "direct" ) );
        CHECK( true == isInterpolationQualifier( "unitBase" ) );
        CHECK( true == isInterpolationQualifier( "correspondingEnergies" ) );
        CHECK( true == isInterpolationQualifier( "correspondingPoints" ) );
        CHECK( false == isInterpolationQualifier( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
