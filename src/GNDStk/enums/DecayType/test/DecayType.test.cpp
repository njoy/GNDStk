#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using DecayType = enums::DecayType;

SCENARIO( "DecayType" ) {

  GIVEN( "valid DecayType values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "SF" == enums::toString( DecayType::SpontaneousFission ) );
        CHECK( "beta-" == enums::toString( DecayType::BetaMinus ) );
        CHECK( "beta+" == enums::toString( DecayType::BetaPlus ) );
        CHECK( "EC" == enums::toString( DecayType::ElectronCapture ) );
        CHECK( "electroMagnetic" == enums::toString( DecayType::ElectroMagnetic ) );
        CHECK( "IT" == enums::toString( DecayType::IsomericTransition ) );
        CHECK( "n" == enums::toString( DecayType::Neutron ) );
        CHECK( "p" == enums::toString( DecayType::Proton ) );
        CHECK( "d" == enums::toString( DecayType::Deuteron ) );
        CHECK( "t" == enums::toString( DecayType::Triton ) );
        CHECK( "alpha" == enums::toString( DecayType::Alpha ) );
        CHECK( "atomicRelaxation" == enums::toString( DecayType::AtomicRelaxation ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( DecayType::SpontaneousFission == enums::fromString< DecayType >( "SF" ) );
        CHECK( DecayType::BetaMinus == enums::fromString< DecayType >( "beta-" ) );
        CHECK( DecayType::BetaPlus == enums::fromString< DecayType >( "beta+" ) );
        CHECK( DecayType::ElectronCapture == enums::fromString< DecayType >( "EC" ) );
        CHECK( DecayType::ElectroMagnetic == enums::fromString< DecayType >( "electroMagnetic" ) );
        CHECK( DecayType::IsomericTransition == enums::fromString< DecayType >( "IT" ) );
        CHECK( DecayType::Neutron == enums::fromString< DecayType >( "n" ) );
        CHECK( DecayType::Proton == enums::fromString< DecayType >( "p" ) );
        CHECK( DecayType::Deuteron == enums::fromString< DecayType >( "d" ) );
        CHECK( DecayType::Triton == enums::fromString< DecayType >( "t" ) );
        CHECK( DecayType::Alpha == enums::fromString< DecayType >( "alpha" ) );
        CHECK( DecayType::AtomicRelaxation == enums::fromString< DecayType >( "atomicRelaxation" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< DecayType >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << DecayType::SpontaneousFission << ' '
            << DecayType::BetaMinus << ' '
            << DecayType::BetaPlus << ' '
            << DecayType::ElectronCapture << ' '
            << DecayType::ElectroMagnetic << ' '
            << DecayType::IsomericTransition << ' '
            << DecayType::Neutron << ' '
            << DecayType::Proton << ' '
            << DecayType::Deuteron << ' '
            << DecayType::Triton << ' '
            << DecayType::Alpha << ' '
            << DecayType::AtomicRelaxation;

        CHECK( "SF beta- beta+ EC electroMagnetic IT n p d t alpha atomicRelaxation" == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        DecayType value;
        std::istringstream in( "SF beta- beta+ EC electroMagnetic IT n p d t alpha atomicRelaxation" );

        in >> value;
        CHECK( DecayType::SpontaneousFission == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::BetaMinus == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::BetaPlus == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::ElectronCapture == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::ElectroMagnetic == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::IsomericTransition == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::Neutron == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::Proton == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::Deuteron == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::Triton == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::Alpha == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( DecayType::AtomicRelaxation == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        DecayType value = DecayType::SpontaneousFission;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( DecayType::SpontaneousFission == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isDecayType is used" ) {

      THEN( "registered DecayType values return true, "
            "unregistered DecayType values return false" ) {

        CHECK( true == enums::isDecayType( "SF" ) );
        CHECK( true == enums::isDecayType( "beta-" ) );
        CHECK( true == enums::isDecayType( "beta+" ) );
        CHECK( true == enums::isDecayType( "EC" ) );
        CHECK( true == enums::isDecayType( "electroMagnetic" ) );
        CHECK( true == enums::isDecayType( "IT" ) );
        CHECK( true == enums::isDecayType( "n" ) );
        CHECK( true == enums::isDecayType( "p" ) );
        CHECK( true == enums::isDecayType( "d" ) );
        CHECK( true == enums::isDecayType( "t" ) );
        CHECK( true == enums::isDecayType( "alpha" ) );
        CHECK( true == enums::isDecayType( "atomicRelaxation" ) );
        CHECK( false == enums::isDecayType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
