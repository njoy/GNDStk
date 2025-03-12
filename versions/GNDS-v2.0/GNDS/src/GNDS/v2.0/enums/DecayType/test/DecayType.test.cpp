
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/DecayType.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "DecayType" ) {

  GIVEN( "valid DecayType values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "SF" == enum2string( DecayType::SpontaneousFission ) );
        CHECK( "beta-" == enum2string( DecayType::BetaMinus ) );
        CHECK( "beta+" == enum2string( DecayType::BetaPlus ) );
        CHECK( "EC" == enum2string( DecayType::ElectronCapture ) );
        CHECK( "electroMagnetic" == enum2string( DecayType::ElectroMagnetic ) );
        CHECK( "IT" == enum2string( DecayType::IsomericTransition ) );
        CHECK( "n" == enum2string( DecayType::Neutron ) );
        CHECK( "p" == enum2string( DecayType::Proton ) );
        CHECK( "d" == enum2string( DecayType::Deuteron ) );
        CHECK( "t" == enum2string( DecayType::Triton ) );
        CHECK( "alpha" == enum2string( DecayType::Alpha ) );
        CHECK( "atomicRelaxation" == enum2string( DecayType::AtomicRelaxation ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( DecayType::SpontaneousFission == string2enum< DecayType >( "SF" ) );
        CHECK( DecayType::BetaMinus == string2enum< DecayType >( "beta-" ) );
        CHECK( DecayType::BetaPlus == string2enum< DecayType >( "beta+" ) );
        CHECK( DecayType::ElectronCapture == string2enum< DecayType >( "EC" ) );
        CHECK( DecayType::ElectroMagnetic == string2enum< DecayType >( "electroMagnetic" ) );
        CHECK( DecayType::IsomericTransition == string2enum< DecayType >( "IT" ) );
        CHECK( DecayType::Neutron == string2enum< DecayType >( "n" ) );
        CHECK( DecayType::Proton == string2enum< DecayType >( "p" ) );
        CHECK( DecayType::Deuteron == string2enum< DecayType >( "d" ) );
        CHECK( DecayType::Triton == string2enum< DecayType >( "t" ) );
        CHECK( DecayType::Alpha == string2enum< DecayType >( "alpha" ) );
        CHECK( DecayType::AtomicRelaxation == string2enum< DecayType >( "atomicRelaxation" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< DecayType >( "unregistered" ) );
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

        CHECK( true == isDecayType( "SF" ) );
        CHECK( true == isDecayType( "beta-" ) );
        CHECK( true == isDecayType( "beta+" ) );
        CHECK( true == isDecayType( "EC" ) );
        CHECK( true == isDecayType( "electroMagnetic" ) );
        CHECK( true == isDecayType( "IT" ) );
        CHECK( true == isDecayType( "n" ) );
        CHECK( true == isDecayType( "p" ) );
        CHECK( true == isDecayType( "d" ) );
        CHECK( true == isDecayType( "t" ) );
        CHECK( true == isDecayType( "alpha" ) );
        CHECK( true == isDecayType( "atomicRelaxation" ) );
        CHECK( false == isDecayType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
