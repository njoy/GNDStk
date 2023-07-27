
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
   struct Map<ContributorType> {
      static inline const map2string<ContributorType> values {
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
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
