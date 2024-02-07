
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/Interpolation.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "Interpolation" ) {

  GIVEN( "valid interpolation values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "flat" == enum2string( Interpolation::flat ) );
        CHECK( "lin-lin" == enum2string( Interpolation::linlin ) );
        CHECK( "lin-log" == enum2string( Interpolation::linlog ) );
        CHECK( "log-lin" == enum2string( Interpolation::loglin ) );
        CHECK( "log-log" == enum2string( Interpolation::loglog ) );
        CHECK( "charged-particle" ==
               enum2string( Interpolation::chargedparticle ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Interpolation::flat ==
               string2enum< Interpolation >( "flat" ) );
        CHECK( Interpolation::linlin ==
               string2enum< Interpolation >( "lin-lin" ) );
        CHECK( Interpolation::linlog ==
               string2enum< Interpolation >( "lin-log" ) );
        CHECK( Interpolation::loglin ==
               string2enum< Interpolation >( "log-lin" ) );
        CHECK( Interpolation::loglog ==
               string2enum< Interpolation >( "log-log" ) );
        CHECK( Interpolation::chargedparticle ==
               string2enum< Interpolation >( "charged-particle" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< Interpolation >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Interpolation::flat << ' ' << Interpolation::linlin << ' '
            << Interpolation::linlog << ' ' << Interpolation::loglin << ' '
            << Interpolation::loglog << ' ' << Interpolation::chargedparticle;

        CHECK( "flat lin-lin lin-log log-lin log-log charged-particle" ==
               out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        Interpolation value;
        std::istringstream in( "flat lin-lin lin-log log-lin "
                               "log-log charged-particle" );

        in >> value;
        CHECK( Interpolation::flat == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interpolation::linlin == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interpolation::linlog == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interpolation::loglin == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interpolation::loglog == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( Interpolation::chargedparticle == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        Interpolation value = Interpolation::linlin;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( Interpolation::linlin == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isInterpolation is used" ) {

      THEN( "registered interpolation values return true, "
            "unregistered interpolation values return false" ) {

        CHECK( true == isInterpolation( "flat" ) );
        CHECK( true == isInterpolation( "lin-lin" ) );
        CHECK( true == isInterpolation( "lin-log" ) );
        CHECK( true == isInterpolation( "log-lin" ) );
        CHECK( true == isInterpolation( "log-log" ) );
        CHECK( true == isInterpolation( "charged-particle" ) );
        CHECK( false == isInterpolation( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
