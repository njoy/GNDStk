
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

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
   return isSymbolForEnum<ContributorType>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert ContributorType to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::ContributorType> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::ContactPerson, "ContactPerson" },
      { T::DataCollector, "DataCollector" },
      { T::DataCurator, "DataCurator" },
      { T::DataManager, "DataManager" },
      { T::Distributor, "Distributor" },
      { T::Editor, "Editor" },
      { T::HostingInstitution, "HostingInstitution" },
      { T::Producer, "Producer" },
      { T::ProjectLeader, "ProjectLeader" },
      { T::ProjectManager, "ProjectManager" },
      { T::ProjectMember, "ProjectMember" },
      { T::RegistrationAgency, "RegistrationAgency" },
      { T::RegistrationAuthority, "RegistrationAuthority" },
      { T::RelatedPerson, "RelatedPerson" },
      { T::Researcher, "Researcher" },
      { T::ResearchGroup, "ResearchGroup" },
      { T::RightsHolder, "RightsHolder" },
      { T::Sponsor, "Sponsor" },
      { T::Supervisor, "Supervisor" },
      { T::WorkPackageLeader, "WorkPackageLeader" },
      { T::Other, "Other" }
   };
   static inline const auto symbols = reverseMap(values);
};
