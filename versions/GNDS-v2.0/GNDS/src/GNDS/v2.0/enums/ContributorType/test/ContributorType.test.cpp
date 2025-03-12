
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/ContributorType.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "ContributorType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "ContactPerson" == enum2string( ContributorType::ContactPerson ) );
        CHECK( "DataCollector" == enum2string( ContributorType::DataCollector ) );
        CHECK( "DataCurator" == enum2string( ContributorType::DataCurator ) );
        CHECK( "DataManager" == enum2string( ContributorType::DataManager ) );
        CHECK( "Distributor" == enum2string( ContributorType::Distributor ) );
        CHECK( "Editor" == enum2string( ContributorType::Editor ) );
        CHECK( "HostingInstitution" == enum2string( ContributorType::HostingInstitution ) );
        CHECK( "Producer" == enum2string( ContributorType::Producer ) );
        CHECK( "ProjectLeader" == enum2string( ContributorType::ProjectLeader ) );
        CHECK( "ProjectManager" == enum2string( ContributorType::ProjectManager ) );
        CHECK( "ProjectMember" == enum2string( ContributorType::ProjectMember ) );
        CHECK( "RegistrationAgency" == enum2string( ContributorType::RegistrationAgency ) );
        CHECK( "RegistrationAuthority" == enum2string( ContributorType::RegistrationAuthority ) );
        CHECK( "RelatedPerson" == enum2string( ContributorType::RelatedPerson ) );
        CHECK( "Researcher" == enum2string( ContributorType::Researcher ) );
        CHECK( "ResearchGroup" == enum2string( ContributorType::ResearchGroup ) );
        CHECK( "RightsHolder" == enum2string( ContributorType::RightsHolder ) );
        CHECK( "Sponsor" == enum2string( ContributorType::Sponsor ) );
        CHECK( "Supervisor" == enum2string( ContributorType::Supervisor ) );
        CHECK( "WorkPackageLeader" == enum2string( ContributorType::WorkPackageLeader ) );
        CHECK( "Other" == enum2string( ContributorType::Other ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( ContributorType::ContactPerson
               == string2enum< ContributorType >( "ContactPerson" ) );
        CHECK( ContributorType::DataCollector
               == string2enum< ContributorType >( "DataCollector" ) );
        CHECK( ContributorType::DataCurator
               == string2enum< ContributorType >( "DataCurator" ) );
        CHECK( ContributorType::DataManager
               == string2enum< ContributorType >( "DataManager" ) );
        CHECK( ContributorType::Distributor
               == string2enum< ContributorType >( "Distributor" ) );
        CHECK( ContributorType::Editor
               == string2enum< ContributorType >( "Editor" ) );
        CHECK( ContributorType::HostingInstitution
               == string2enum< ContributorType >( "HostingInstitution" ) );
        CHECK( ContributorType::Producer
               == string2enum< ContributorType >( "Producer" ) );
        CHECK( ContributorType::ProjectLeader
               == string2enum< ContributorType >( "ProjectLeader" ) );
        CHECK( ContributorType::ProjectManager
               == string2enum< ContributorType >( "ProjectManager" ) );
        CHECK( ContributorType::ProjectMember
               == string2enum< ContributorType >( "ProjectMember" ) );
        CHECK( ContributorType::RegistrationAgency
               == string2enum< ContributorType >( "RegistrationAgency" ) );
        CHECK( ContributorType::RegistrationAuthority
               == string2enum< ContributorType >( "RegistrationAuthority" ) );
        CHECK( ContributorType::RelatedPerson
               == string2enum< ContributorType >( "RelatedPerson" ) );
        CHECK( ContributorType::Researcher
               == string2enum< ContributorType >( "Researcher" ) );
        CHECK( ContributorType::ResearchGroup
               == string2enum< ContributorType >( "ResearchGroup" ) );
        CHECK( ContributorType::RightsHolder
               == string2enum< ContributorType >( "RightsHolder" ) );
        CHECK( ContributorType::Sponsor
               == string2enum< ContributorType >( "Sponsor" ) );
        CHECK( ContributorType::Supervisor
               == string2enum< ContributorType >( "Supervisor" ) );
        CHECK( ContributorType::WorkPackageLeader
               == string2enum< ContributorType >( "WorkPackageLeader" ) );
        CHECK( ContributorType::Other
               == string2enum< ContributorType >( "Other" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< ContributorType >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << ContributorType::ContactPerson << ' '
            << ContributorType::DataCollector << ' '
            << ContributorType::DataCurator << ' '
            << ContributorType::DataManager << ' '
            << ContributorType::Distributor << ' '
            << ContributorType::Editor << ' '
            << ContributorType::HostingInstitution << ' '
            << ContributorType::Producer << ' '
            << ContributorType::ProjectLeader << ' '
            << ContributorType::ProjectManager << ' '
            << ContributorType::ProjectMember << ' '
            << ContributorType::RegistrationAgency << ' '
            << ContributorType::RegistrationAuthority << ' '
            << ContributorType::RelatedPerson << ' '
            << ContributorType::Researcher << ' '
            << ContributorType::ResearchGroup << ' '
            << ContributorType::RightsHolder << ' '
            << ContributorType::Sponsor << ' '
            << ContributorType::Supervisor << ' '
            << ContributorType::WorkPackageLeader << ' '
            << ContributorType::Other;

        CHECK( "ContactPerson DataCollector DataCurator DataManager "
               "Distributor Editor HostingInstitution Producer "
               "ProjectLeader ProjectManager ProjectMember RegistrationAgency "
               "RegistrationAuthority RelatedPerson Researcher ResearchGroup "
               "RightsHolder Sponsor Supervisor WorkPackageLeader Other"
               == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        ContributorType value;
        std::istringstream in( "ContactPerson DataCollector DataCurator DataManager "
                               "Distributor Editor HostingInstitution Producer "
                               "ProjectLeader ProjectManager ProjectMember RegistrationAgency "
                               "RegistrationAuthority RelatedPerson Researcher ResearchGroup "
                               "RightsHolder Sponsor Supervisor WorkPackageLeader Other" );

        in >> value;
        CHECK( ContributorType::ContactPerson == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::DataCollector == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::DataCurator == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::DataManager == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Distributor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Editor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::HostingInstitution == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Producer == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::ProjectLeader == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::ProjectManager == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::ProjectMember == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::RegistrationAgency == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::RegistrationAuthority == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::RelatedPerson == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Researcher == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::ResearchGroup == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::RightsHolder == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Sponsor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Supervisor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::WorkPackageLeader == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( ContributorType::Other == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        ContributorType value = ContributorType::ContactPerson;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( ContributorType::ContactPerson == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isContributorType is used" ) {

      THEN( "registered date types return true, "
            "unregistered date types return false" ) {

        CHECK( true == isContributorType( "ContactPerson" ) );
        CHECK( true == isContributorType( "DataCollector" ) );
        CHECK( true == isContributorType( "DataCurator" ) );
        CHECK( true == isContributorType( "DataManager" ) );
        CHECK( true == isContributorType( "Distributor" ) );
        CHECK( true == isContributorType( "Editor" ) );
        CHECK( true == isContributorType( "HostingInstitution" ) );
        CHECK( true == isContributorType( "Producer" ) );
        CHECK( true == isContributorType( "ProjectLeader" ) );
        CHECK( true == isContributorType( "ProjectManager" ) );
        CHECK( true == isContributorType( "ProjectMember" ) );
        CHECK( true == isContributorType( "RegistrationAgency" ) );
        CHECK( true == isContributorType( "RegistrationAuthority" ) );
        CHECK( true == isContributorType( "RelatedPerson" ) );
        CHECK( true == isContributorType( "Researcher" ) );
        CHECK( true == isContributorType( "ResearchGroup" ) );
        CHECK( true == isContributorType( "RightsHolder" ) );
        CHECK( true == isContributorType( "Sponsor" ) );
        CHECK( true == isContributorType( "Supervisor" ) );
        CHECK( true == isContributorType( "WorkPackageLeader" ) );
        CHECK( true == isContributorType( "Other" ) );
        CHECK( false == isContributorType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
