#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Interaction = enums::Interaction;

SCENARIO( "Interaction" ) {

  GIVEN( "valid interaction values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "nuclear" ==
               enums::toString( Interaction::nuclear ) );
        CHECK( "atomic" ==
               enums::toString( Interaction::atomic ) );
        CHECK( "thermalNeutronScatteringLaw" ==
               enums::toString( Interaction::thermalNeutronScatteringLaw ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Interaction::nuclear ==
               enums::fromString<Interaction>("nuclear"));
        CHECK( Interaction::atomic ==
               enums::fromString<Interaction>("atomic"));
        CHECK( Interaction::thermalNeutronScatteringLaw ==
               enums::fromString<Interaction>("thermalNeutronScatteringLaw"));
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Interaction >( "unregistered" ) );
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

        CHECK( true == enums::isInteraction( "nuclear" ) );
        CHECK( true == enums::isInteraction( "atomic" ) );
        CHECK( true == enums::isInteraction( "thermalNeutronScatteringLaw" ) );
        CHECK( false == enums::isInteraction( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
