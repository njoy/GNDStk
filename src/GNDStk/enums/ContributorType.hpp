
#ifndef NJOY_GNDSTK_ENUMS_CONTRIBUTORTYPE
#define NJOY_GNDSTK_ENUMS_CONTRIBUTORTYPE

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for contributor type values
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
    *  @brief Return whether or not a string is a valid contributor type
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isContributorType(const std::string &string)
   {
      return isSymbol<ContributorType>(string);
   }

   /**
    *  @brief Template specialisation to convert ContributorType to/from strings
    */
   template<>
   struct Map<ContributorType>
   {
      static inline const std::map<ContributorType,std::string> values {
         { ContributorType::ContactPerson, "ContactPerson" },
         { ContributorType::DataCollector, "DataCollector" },
         { ContributorType::DataCurator, "DataCurator" },
         { ContributorType::DataManager, "DataManager" },
         { ContributorType::Distributor, "Distributor" },
         { ContributorType::Editor, "Editor" },
         { ContributorType::HostingInstitution, "HostingInstitution" },
         { ContributorType::Producer, "Producer" },
         { ContributorType::ProjectLeader, "ProjectLeader" },
         { ContributorType::ProjectManager, "ProjectManager" },
         { ContributorType::ProjectMember, "ProjectMember" },
         { ContributorType::RegistrationAgency, "RegistrationAgency" },
         { ContributorType::RegistrationAuthority, "RegistrationAuthority" },
         { ContributorType::RelatedPerson, "RelatedPerson" },
         { ContributorType::Researcher, "Researcher" },
         { ContributorType::ResearchGroup, "ResearchGroup" },
         { ContributorType::RightsHolder, "RightsHolder" },
         { ContributorType::Sponsor, "Sponsor" },
         { ContributorType::Supervisor, "Supervisor" },
         { ContributorType::WorkPackageLeader, "WorkPackageLeader" },
         { ContributorType::Other, "Other" }
      };

      static inline const std::map<std::string,ContributorType> symbols {
         { "ContactPerson", ContributorType::ContactPerson },
         { "DataCollector", ContributorType::DataCollector },
         { "DataCurator", ContributorType::DataCurator },
         { "DataManager", ContributorType::DataManager },
         { "Distributor", ContributorType::Distributor },
         { "Editor", ContributorType::Editor },
         { "HostingInstitution", ContributorType::HostingInstitution },
         { "Producer", ContributorType::Producer },
         { "ProjectLeader", ContributorType::ProjectLeader },
         { "ProjectManager", ContributorType::ProjectManager },
         { "ProjectMember", ContributorType::ProjectMember },
         { "RegistrationAgency", ContributorType::RegistrationAgency },
         { "RegistrationAuthority", ContributorType::RegistrationAuthority },
         { "RelatedPerson", ContributorType::RelatedPerson },
         { "Researcher", ContributorType::Researcher },
         { "ResearchGroup", ContributorType::ResearchGroup },
         { "RightsHolder", ContributorType::RightsHolder },
         { "Sponsor", ContributorType::Sponsor },
         { "Supervisor", ContributorType::Supervisor },
         { "WorkPackageLeader", ContributorType::WorkPackageLeader },
         { "Other", ContributorType::Other }
      };
   };

} // namespace enums

#endif
