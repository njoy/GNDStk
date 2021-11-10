#ifndef NJOY_GNDSTK_CONTRIBUTORTYPE
#define NJOY_GNDSTK_CONTRIBUTORTYPE

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for interpolation qualifier values
   */
  enum class ContributorType {

    ContactPerson = 1,
    DataCollector,
    DataCurator,
    DataManager,
    Distributor,
    Editor,
    HostingInstitution,
    Producer,
    ProjectLeader,
    ProjectManager,
    ProjectMember,
    RegistrationAgency,
    RegistrationAuthority,
    RelatedPerson,
    Researcher,
    ResearchGroup,
    RightsHolder,
    Sponsor,
    Supervisor,
    WorkPackageLeader,
    Other
  };

  /**
   *  @brief Return whether or not a string is a valid parity
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isContributorType( const std::string& string ) {

    return isSymbol< ContributorType >( string );
  }

  /**
   *  @brief Template specialisation to convert ContributorType to/from strings
   */
  template <>
  class Map< GNDStk::enums::ContributorType > {
  public:

    static inline const std::map< GNDStk::enums::ContributorType,
                                  const std::string > values{

      { GNDStk::enums::ContributorType::ContactPerson, "ContactPerson" },
      { GNDStk::enums::ContributorType::DataCollector, "DataCollector" },
      { GNDStk::enums::ContributorType::DataCurator, "DataCurator" },
      { GNDStk::enums::ContributorType::DataManager, "DataManager" },
      { GNDStk::enums::ContributorType::Distributor, "Distributor" },
      { GNDStk::enums::ContributorType::Editor, "Editor" },
      { GNDStk::enums::ContributorType::HostingInstitution, "HostingInstitution" },
      { GNDStk::enums::ContributorType::Producer, "Producer" },
      { GNDStk::enums::ContributorType::ProjectLeader, "ProjectLeader" },
      { GNDStk::enums::ContributorType::ProjectManager, "ProjectManager" },
      { GNDStk::enums::ContributorType::ProjectMember, "ProjectMember" },
      { GNDStk::enums::ContributorType::RegistrationAgency, "RegistrationAgency" },
      { GNDStk::enums::ContributorType::RegistrationAuthority, "RegistrationAuthority" },
      { GNDStk::enums::ContributorType::RelatedPerson, "RelatedPerson" },
      { GNDStk::enums::ContributorType::Researcher, "Researcher" },
      { GNDStk::enums::ContributorType::ResearchGroup, "ResearchGroup" },
      { GNDStk::enums::ContributorType::RightsHolder, "RightsHolder" },
      { GNDStk::enums::ContributorType::Sponsor, "Sponsor" },
      { GNDStk::enums::ContributorType::Supervisor, "Supervisor" },
      { GNDStk::enums::ContributorType::WorkPackageLeader, "WorkPackageLeader" },
      { GNDStk::enums::ContributorType::Other, "Other" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::ContributorType > symbols{

      { "ContactPerson", GNDStk::enums::ContributorType::ContactPerson },
      { "DataCollector", GNDStk::enums::ContributorType::DataCollector },
      { "DataCurator", GNDStk::enums::ContributorType::DataCurator },
      { "DataManager", GNDStk::enums::ContributorType::DataManager },
      { "Distributor", GNDStk::enums::ContributorType::Distributor },
      { "Editor", GNDStk::enums::ContributorType::Editor },
      { "HostingInstitution", GNDStk::enums::ContributorType::HostingInstitution },
      { "Producer", GNDStk::enums::ContributorType::Producer },
      { "ProjectLeader", GNDStk::enums::ContributorType::ProjectLeader },
      { "ProjectManager", GNDStk::enums::ContributorType::ProjectManager },
      { "ProjectMember", GNDStk::enums::ContributorType::ProjectMember },
      { "RegistrationAgency", GNDStk::enums::ContributorType::RegistrationAgency },
      { "RegistrationAuthority", GNDStk::enums::ContributorType::RegistrationAuthority },
      { "RelatedPerson", GNDStk::enums::ContributorType::RelatedPerson },
      { "Researcher", GNDStk::enums::ContributorType::Researcher },
      { "ResearchGroup", GNDStk::enums::ContributorType::ResearchGroup },
      { "RightsHolder", GNDStk::enums::ContributorType::RightsHolder },
      { "Sponsor", GNDStk::enums::ContributorType::Sponsor },
      { "Supervisor", GNDStk::enums::ContributorType::Supervisor },
      { "WorkPackageLeader", GNDStk::enums::ContributorType::WorkPackageLeader },
      { "Other", GNDStk::enums::ContributorType::Other }
    };
  };

} // namespace enums

#endif
