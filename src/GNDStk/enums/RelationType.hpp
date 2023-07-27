
#ifndef NJOY_GNDSTK_ENUMS_RELATIONTYPE
#define NJOY_GNDSTK_ENUMS_RELATIONTYPE

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
      return isSymbol<RelationType>(string);
   }

   /**
    *  @brief Template specialisation to convert RelationType to/from strings
    */
   template<>
   struct Map<RelationType> {
      static inline const map2string<RelationType> values {
         { RelationType::IsCitedBy, "IsCitedBy" },
         { RelationType::Cites, "Cites" },
         { RelationType::IsSupplementTo, "IsSupplementTo" },
         { RelationType::IsSupplementedBy, "IsSupplementedBy" },
         { RelationType::IsContinuedBy, "IsContinuedBy" },
         { RelationType::Continues, "Continues" },
         { RelationType::Describes, "Describes" },
         { RelationType::IsDescribedBy, "IsDescribedBy" },
         { RelationType::HasMetadata, "HasMetadata" },
         { RelationType::IsMetadataFor, "IsMetadataFor" },
         { RelationType::HasVersion, "HasVersion" },
         { RelationType::IsVersionOf, "IsVersionOf" },
         { RelationType::IsNewVersionOf, "IsNewVersionOf" },
         { RelationType::IsPreviousVersionOf, "IsPreviousVersionOf" },
         { RelationType::IsPartOf, "IsPartOf" },
         { RelationType::HasPart, "HasPart" },
         { RelationType::IsPublishedIn, "IsPublishedIn" },
         { RelationType::IsReferencedBy, "IsReferencedBy" },
         { RelationType::References, "References" },
         { RelationType::IsDocumentedBy, "IsDocumentedBy" },
         { RelationType::Documents, "Documents" },
         { RelationType::IsCompiledBy, "IsCompiledBy" },
         { RelationType::Compiles, "Compiles" },
         { RelationType::IsVariantFormOf, "IsVariantFormOf" },
         { RelationType::IsOriginalFormOf, "IsOriginalFormOf" },
         { RelationType::IsIdenticalTo, "IsIdenticalTo" },
         { RelationType::IsReviewedBy, "IsReviewedBy" },
         { RelationType::Reviews, "Reviews" },
         { RelationType::IsDerivedFrom, "IsDerivedFrom" },
         { RelationType::IsSourceOf, "IsSourceOf" },
         { RelationType::IsRequiredBy, "IsRequiredBy" },
         { RelationType::Requires, "Requires" },
         { RelationType::Obsoletes, "Obsoletes" },
         { RelationType::IsObsoletedBy, "IsObsoletedBy" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
