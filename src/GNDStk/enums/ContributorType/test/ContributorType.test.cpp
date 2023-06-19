#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using ContributorType = enums::ContributorType;

SCENARIO( "ContributorType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "ContactPerson" == enums::toString( ContributorType::ContactPerson ) );
        CHECK( "DataCollector" == enums::toString( ContributorType::DataCollector ) );
        CHECK( "DataCurator" == enums::toString( ContributorType::DataCurator ) );
        CHECK( "DataManager" == enums::toString( ContributorType::DataManager ) );
        CHECK( "Distributor" == enums::toString( ContributorType::Distributor ) );
        CHECK( "Editor" == enums::toString( ContributorType::Editor ) );
        CHECK( "HostingInstitution" == enums::toString( ContributorType::HostingInstitution ) );
        CHECK( "Producer" == enums::toString( ContributorType::Producer ) );
        CHECK( "ProjectLeader" == enums::toString( ContributorType::ProjectLeader ) );
        CHECK( "ProjectManager" == enums::toString( ContributorType::ProjectManager ) );
        CHECK( "ProjectMember" == enums::toString( ContributorType::ProjectMember ) );
        CHECK( "RegistrationAgency" == enums::toString( ContributorType::RegistrationAgency ) );
        CHECK( "RegistrationAuthority" == enums::toString( ContributorType::RegistrationAuthority ) );
        CHECK( "RelatedPerson" == enums::toString( ContributorType::RelatedPerson ) );
        CHECK( "Researcher" == enums::toString( ContributorType::Researcher ) );
        CHECK( "ResearchGroup" == enums::toString( ContributorType::ResearchGroup ) );
        CHECK( "RightsHolder" == enums::toString( ContributorType::RightsHolder ) );
        CHECK( "Sponsor" == enums::toString( ContributorType::Sponsor ) );
        CHECK( "Supervisor" == enums::toString( ContributorType::Supervisor ) );
        CHECK( "WorkPackageLeader" == enums::toString( ContributorType::WorkPackageLeader ) );
        CHECK( "Other" == enums::toString( ContributorType::Other ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( ContributorType::ContactPerson
               == enums::fromString< ContributorType >( "ContactPerson" ) );
        CHECK( ContributorType::DataCollector
               == enums::fromString< ContributorType >( "DataCollector" ) );
        CHECK( ContributorType::DataCurator
               == enums::fromString< ContributorType >( "DataCurator" ) );
        CHECK( ContributorType::DataManager
               == enums::fromString< ContributorType >( "DataManager" ) );
        CHECK( ContributorType::Distributor
               == enums::fromString< ContributorType >( "Distributor" ) );
        CHECK( ContributorType::Editor
               == enums::fromString< ContributorType >( "Editor" ) );
        CHECK( ContributorType::HostingInstitution
               == enums::fromString< ContributorType >( "HostingInstitution" ) );
        CHECK( ContributorType::Producer
               == enums::fromString< ContributorType >( "Producer" ) );
        CHECK( ContributorType::ProjectLeader
               == enums::fromString< ContributorType >( "ProjectLeader" ) );
        CHECK( ContributorType::ProjectManager
               == enums::fromString< ContributorType >( "ProjectManager" ) );
        CHECK( ContributorType::ProjectMember
               == enums::fromString< ContributorType >( "ProjectMember" ) );
        CHECK( ContributorType::RegistrationAgency
               == enums::fromString< ContributorType >( "RegistrationAgency" ) );
        CHECK( ContributorType::RegistrationAuthority
               == enums::fromString< ContributorType >( "RegistrationAuthority" ) );
        CHECK( ContributorType::RelatedPerson
               == enums::fromString< ContributorType >( "RelatedPerson" ) );
        CHECK( ContributorType::Researcher
               == enums::fromString< ContributorType >( "Researcher" ) );
        CHECK( ContributorType::ResearchGroup
               == enums::fromString< ContributorType >( "ResearchGroup" ) );
        CHECK( ContributorType::RightsHolder
               == enums::fromString< ContributorType >( "RightsHolder" ) );
        CHECK( ContributorType::Sponsor
               == enums::fromString< ContributorType >( "Sponsor" ) );
        CHECK( ContributorType::Supervisor
               == enums::fromString< ContributorType >( "Supervisor" ) );
        CHECK( ContributorType::WorkPackageLeader
               == enums::fromString< ContributorType >( "WorkPackageLeader" ) );
        CHECK( ContributorType::Other
               == enums::fromString< ContributorType >( "Other" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< ContributorType >( "unregistered" ) );
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

        CHECK( true == enums::isContributorType( "ContactPerson" ) );
        CHECK( true == enums::isContributorType( "DataCollector" ) );
        CHECK( true == enums::isContributorType( "DataCurator" ) );
        CHECK( true == enums::isContributorType( "DataManager" ) );
        CHECK( true == enums::isContributorType( "Distributor" ) );
        CHECK( true == enums::isContributorType( "Editor" ) );
        CHECK( true == enums::isContributorType( "HostingInstitution" ) );
        CHECK( true == enums::isContributorType( "Producer" ) );
        CHECK( true == enums::isContributorType( "ProjectLeader" ) );
        CHECK( true == enums::isContributorType( "ProjectManager" ) );
        CHECK( true == enums::isContributorType( "ProjectMember" ) );
        CHECK( true == enums::isContributorType( "RegistrationAgency" ) );
        CHECK( true == enums::isContributorType( "RegistrationAuthority" ) );
        CHECK( true == enums::isContributorType( "RelatedPerson" ) );
        CHECK( true == enums::isContributorType( "Researcher" ) );
        CHECK( true == enums::isContributorType( "ResearchGroup" ) );
        CHECK( true == enums::isContributorType( "RightsHolder" ) );
        CHECK( true == enums::isContributorType( "Sponsor" ) );
        CHECK( true == enums::isContributorType( "Supervisor" ) );
        CHECK( true == enums::isContributorType( "WorkPackageLeader" ) );
        CHECK( true == enums::isContributorType( "Other" ) );
        CHECK( false == enums::isContributorType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
