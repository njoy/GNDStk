#ifndef NJOY_GNDSTK_RELATIONTYPE
#define NJOY_GNDSTK_RELATIONTYPE

namespace enums {

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
    Complies,
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
  inline bool isRelationType( const std::string& string ) {

    return isSymbol< RelationType >( string );
  }

  /**
   *  @brief Template specialisation to convert RelationType to/from strings
   */
  template <>
  class Map< GNDStk::enums::RelationType > {
  public:

    static inline const std::map< GNDStk::enums::RelationType,
                                  const std::string > values{

      { GNDStk::enums::RelationType::IsCitedBy, "IsCitedBy" },
      { GNDStk::enums::RelationType::Cites, "Cites" },
      { GNDStk::enums::RelationType::IsSupplementTo, "IsSupplementTo" },
      { GNDStk::enums::RelationType::IsSupplementedBy, "IsSupplementedBy" },
      { GNDStk::enums::RelationType::IsContinuedBy, "IsContinuedBy" },
      { GNDStk::enums::RelationType::Continues, "Continues" },
      { GNDStk::enums::RelationType::Describes, "Describes" },
      { GNDStk::enums::RelationType::IsDescribedBy, "IsDescribedBy" },
      { GNDStk::enums::RelationType::HasMetadata, "HasMetadata" },
      { GNDStk::enums::RelationType::IsMetadataFor, "IsMetadataFor" },
      { GNDStk::enums::RelationType::HasVersion, "HasVersion" },
      { GNDStk::enums::RelationType::IsVersionOf, "IsVersionOf" },
      { GNDStk::enums::RelationType::IsNewVersionOf, "IsNewVersionOf" },
      { GNDStk::enums::RelationType::IsPreviousVersionOf, "IsPreviousVersionOf" },
      { GNDStk::enums::RelationType::IsPartOf, "IsPartOf" },
      { GNDStk::enums::RelationType::HasPart, "HasPart" },
      { GNDStk::enums::RelationType::IsPublishedIn, "IsPublishedIn" },
      { GNDStk::enums::RelationType::IsReferencedBy, "IsReferencedBy" },
      { GNDStk::enums::RelationType::References, "References" },
      { GNDStk::enums::RelationType::IsDocumentedBy, "IsDocumentedBy" },
      { GNDStk::enums::RelationType::Documents, "Documents" },
      { GNDStk::enums::RelationType::IsCompiledBy, "IsCompiledBy" },
      { GNDStk::enums::RelationType::Complies, "Complies" },
      { GNDStk::enums::RelationType::IsVariantFormOf, "IsVariantFormOf" },
      { GNDStk::enums::RelationType::IsOriginalFormOf, "IsOriginalFormOf" },
      { GNDStk::enums::RelationType::IsIdenticalTo, "IsIdenticalTo" },
      { GNDStk::enums::RelationType::IsReviewedBy, "IsReviewedBy" },
      { GNDStk::enums::RelationType::Reviews, "Reviews" },
      { GNDStk::enums::RelationType::IsDerivedFrom, "IsDerivedFrom" },
      { GNDStk::enums::RelationType::IsSourceOf, "IsSourceOf" },
      { GNDStk::enums::RelationType::IsRequiredBy, "IsRequiredBy" },
      { GNDStk::enums::RelationType::Requires, "Requires" },
      { GNDStk::enums::RelationType::Obsoletes, "Obsoletes" },
      { GNDStk::enums::RelationType::IsObsoletedBy, "IsObsoletedBy" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::RelationType > symbols{

      { "IsCitedBy", GNDStk::enums::RelationType::IsCitedBy },
      { "Cites", GNDStk::enums::RelationType::Cites },
      { "IsSupplementTo", GNDStk::enums::RelationType::IsSupplementTo },
      { "IsSupplementedBy", GNDStk::enums::RelationType::IsSupplementedBy },
      { "IsContinuedBy", GNDStk::enums::RelationType::IsContinuedBy },
      { "Continues", GNDStk::enums::RelationType::Continues },
      { "Describes", GNDStk::enums::RelationType::Describes },
      { "IsDescribedBy", GNDStk::enums::RelationType::IsDescribedBy },
      { "HasMetadata", GNDStk::enums::RelationType::HasMetadata },
      { "IsMetadataFor", GNDStk::enums::RelationType::IsMetadataFor },
      { "HasVersion", GNDStk::enums::RelationType::HasVersion },
      { "IsVersionOf", GNDStk::enums::RelationType::IsVersionOf },
      { "IsNewVersionOf", GNDStk::enums::RelationType::IsNewVersionOf },
      { "IsPreviousVersionOf", GNDStk::enums::RelationType::IsPreviousVersionOf },
      { "IsPartOf", GNDStk::enums::RelationType::IsPartOf },
      { "HasPart", GNDStk::enums::RelationType::HasPart },
      { "IsPublishedIn", GNDStk::enums::RelationType::IsPublishedIn },
      { "IsReferencedBy", GNDStk::enums::RelationType::IsReferencedBy },
      { "References", GNDStk::enums::RelationType::References },
      { "IsDocumentedBy", GNDStk::enums::RelationType::IsDocumentedBy },
      { "Documents", GNDStk::enums::RelationType::Documents },
      { "IsCompiledBy", GNDStk::enums::RelationType::IsCompiledBy },
      { "Complies", GNDStk::enums::RelationType::Complies },
      { "IsVariantFormOf", GNDStk::enums::RelationType::IsVariantFormOf },
      { "IsOriginalFormOf", GNDStk::enums::RelationType::IsOriginalFormOf },
      { "IsIdenticalTo", GNDStk::enums::RelationType::IsIdenticalTo },
      { "IsReviewedBy", GNDStk::enums::RelationType::IsReviewedBy },
      { "Reviews", GNDStk::enums::RelationType::Reviews },
      { "IsDerivedFrom", GNDStk::enums::RelationType::IsDerivedFrom },
      { "IsSourceOf", GNDStk::enums::RelationType::IsSourceOf },
      { "IsRequiredBy", GNDStk::enums::RelationType::IsRequiredBy },
      { "Requires", GNDStk::enums::RelationType::Requires },
      { "Obsoletes", GNDStk::enums::RelationType::Obsoletes },
      { "IsObsoletedBy", GNDStk::enums::RelationType::IsObsoletedBy }
    };
  };

} // namespace enums

#endif
