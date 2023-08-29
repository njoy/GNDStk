
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Interaction.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Interaction" ) {

  GIVEN( "valid interaction values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "nuclear" ==
               enum2string( Interaction::nuclear ) );
        CHECK( "atomic" ==
               enum2string( Interaction::atomic ) );
        CHECK( "thermalNeutronScatteringLaw" ==
               enum2string( Interaction::thermalNeutronScatteringLaw ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Interaction::nuclear ==
               string2enum<Interaction>("nuclear"));
        CHECK( Interaction::atomic ==
               string2enum<Interaction>("atomic"));
        CHECK( Interaction::thermalNeutronScatteringLaw ==
               string2enum<Interaction>("thermalNeutronScatteringLaw"));
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Interaction >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Interaction::nuclear << ' ' << Interaction::atomic << ' '
            << Interaction::thermalNeutronScatteringLaw;

        CHECK( "nuclear atomic thermalNeutronScatteringLaw" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Interaction value;
        std::istringstream in( "nuclear atomic thermalNeutronScatteringLaw" );

        in >> value;
        CHECK( Interaction::nuclear == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interaction::atomic == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interaction::thermalNeutronScatteringLaw == value );
        CHECK( false == in.fail() );
        CHECK( true  == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Interaction value = Interaction::atomic;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Interaction::atomic == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isInteraction is used" ) {

      THEN( "registered interaction values return true, "
            "unregistered interaction values return false" ) {

        CHECK( true == isInteraction( "nuclear" ) );
        CHECK( true == isInteraction( "atomic" ) );
        CHECK( true == isInteraction( "thermalNeutronScatteringLaw" ) );
        CHECK( false == isInteraction( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
