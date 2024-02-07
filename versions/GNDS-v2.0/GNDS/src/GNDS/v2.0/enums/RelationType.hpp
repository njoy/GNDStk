
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for interpolation qualifier values
 */
enum class RelationType {
   IsCitedBy = 1,
   Cites,
   IsSupplementTo,
   IsSupplementedBy,
   IsContinuedBy,
   Continues,
   Describes,
   IsDescribedBy,
   HasMetadata,
   IsMetadataFor,
   HasVersion,
   IsVersionOf,
   IsNewVersionOf,
   IsPreviousVersionOf,
   IsPartOf,
   HasPart,
   IsPublishedIn,
   IsReferencedBy,
   References,
   IsDocumentedBy,
   Documents,
   IsCompiledBy,
   Compiles,
   IsVariantFormOf,
   IsOriginalFormOf,
   IsIdenticalTo,
   IsReviewedBy,
   Reviews,
   IsDerivedFrom,
   IsSourceOf,
   IsRequiredBy,
   Requires,
   Obsoletes,
   IsObsoletedBy
};

/**
 *  @brief Return whether or not a string is a valid relation type
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isRelationType(const std::string &string)
{
   return isSymbolForEnum<RelationType>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert RelationType to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::RelationType> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::IsCitedBy, "IsCitedBy" },
      { T::Cites, "Cites" },
      { T::IsSupplementTo, "IsSupplementTo" },
      { T::IsSupplementedBy, "IsSupplementedBy" },
      { T::IsContinuedBy, "IsContinuedBy" },
      { T::Continues, "Continues" },
      { T::Describes, "Describes" },
      { T::IsDescribedBy, "IsDescribedBy" },
      { T::HasMetadata, "HasMetadata" },
      { T::IsMetadataFor, "IsMetadataFor" },
      { T::HasVersion, "HasVersion" },
      { T::IsVersionOf, "IsVersionOf" },
      { T::IsNewVersionOf, "IsNewVersionOf" },
      { T::IsPreviousVersionOf, "IsPreviousVersionOf" },
      { T::IsPartOf, "IsPartOf" },
      { T::HasPart, "HasPart" },
      { T::IsPublishedIn, "IsPublishedIn" },
      { T::IsReferencedBy, "IsReferencedBy" },
      { T::References, "References" },
      { T::IsDocumentedBy, "IsDocumentedBy" },
      { T::Documents, "Documents" },
      { T::IsCompiledBy, "IsCompiledBy" },
      { T::Compiles, "Compiles" },
      { T::IsVariantFormOf, "IsVariantFormOf" },
      { T::IsOriginalFormOf, "IsOriginalFormOf" },
      { T::IsIdenticalTo, "IsIdenticalTo" },
      { T::IsReviewedBy, "IsReviewedBy" },
      { T::Reviews, "Reviews" },
      { T::IsDerivedFrom, "IsDerivedFrom" },
      { T::IsSourceOf, "IsSourceOf" },
      { T::IsRequiredBy, "IsRequiredBy" },
      { T::Requires, "Requires" },
      { T::Obsoletes, "Obsoletes" },
      { T::IsObsoletedBy, "IsObsoletedBy" }
   };
   static inline const auto symbols = reverseMap(values);
};
