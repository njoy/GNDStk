#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using Interpolation = enums::Interpolation;

SCENARIO( "Interpolation" ) {

  GIVEN( "valid interpolation values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "flat" == enums::toString( Interpolation::flat ) );
        CHECK( "lin-lin" == enums::toString( Interpolation::linlin ) );
        CHECK( "lin-log" == enums::toString( Interpolation::linlog ) );
        CHECK( "log-lin" == enums::toString( Interpolation::loglin ) );
        CHECK( "log-log" == enums::toString( Interpolation::loglog ) );
        CHECK( "charged-particle" == enums::toString( Interpolation::chargedparticle ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( Interpolation::flat == enums::fromString< Interpolation >( "flat" ) );
        CHECK( Interpolation::linlin == enums::fromString< Interpolation >( "lin-lin" ) );
        CHECK( Interpolation::linlog == enums::fromString< Interpolation >( "lin-log" ) );
        CHECK( Interpolation::loglin == enums::fromString< Interpolation >( "log-lin" ) );
        CHECK( Interpolation::loglog == enums::fromString< Interpolation >( "log-log" ) );
        CHECK( Interpolation::chargedparticle == enums::fromString< Interpolation >( "charged-particle" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< Interpolation >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << Interpolation::flat << ' ' << Interpolation::linlin << ' '
            << Interpolation::linlog << ' ' << Interpolation::loglin << ' '
            << Interpolation::loglog << ' ' << Interpolation::chargedparticle;

        CHECK( "flat lin-lin lin-log log-lin log-log charged-particle" == out.str() );
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

        CHECK( true == enums::isInterpolation( "flat" ) );
        CHECK( true == enums::isInterpolation( "lin-lin" ) );
        CHECK( true == enums::isInterpolation( "lin-log" ) );
        CHECK( true == enums::isInterpolation( "log-lin" ) );
        CHECK( true == enums::isInterpolation( "log-log" ) );
        CHECK( true == enums::isInterpolation( "charged-particle" ) );
        CHECK( false == enums::isInterpolation( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
