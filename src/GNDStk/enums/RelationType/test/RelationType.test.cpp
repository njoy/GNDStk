#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

// other includes

// convenience typedefs
using namespace njoy::GNDStk;
using RelationType = enums::RelationType;

SCENARIO( "RelationType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "toString is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "IsCitedBy" == enums::toString( RelationType::IsCitedBy ) );
        CHECK( "Cites" == enums::toString( RelationType::Cites ) );
        CHECK( "IsSupplementTo" == enums::toString( RelationType::IsSupplementTo ) );
        CHECK( "IsSupplementedBy" == enums::toString( RelationType::IsSupplementedBy ) );
        CHECK( "IsContinuedBy" == enums::toString( RelationType::IsContinuedBy ) );
        CHECK( "Continues" == enums::toString( RelationType::Continues ) );
        CHECK( "Describes" == enums::toString( RelationType::Describes ) );
        CHECK( "IsDescribedBy" == enums::toString( RelationType::IsDescribedBy ) );
        CHECK( "HasMetadata" == enums::toString( RelationType::HasMetadata ) );
        CHECK( "IsMetadataFor" == enums::toString( RelationType::IsMetadataFor ) );
        CHECK( "HasVersion" == enums::toString( RelationType::HasVersion ) );
        CHECK( "IsVersionOf" == enums::toString( RelationType::IsVersionOf ) );
        CHECK( "IsNewVersionOf" == enums::toString( RelationType::IsNewVersionOf ) );
        CHECK( "IsPreviousVersionOf" == enums::toString( RelationType::IsPreviousVersionOf ) );
        CHECK( "IsPartOf" == enums::toString( RelationType::IsPartOf ) );
        CHECK( "HasPart" == enums::toString( RelationType::HasPart ) );
        CHECK( "IsPublishedIn" == enums::toString( RelationType::IsPublishedIn ) );
        CHECK( "IsReferencedBy" == enums::toString( RelationType::IsReferencedBy ) );
        CHECK( "References" == enums::toString( RelationType::References ) );
        CHECK( "IsDocumentedBy" == enums::toString( RelationType::IsDocumentedBy ) );
        CHECK( "Documents" == enums::toString( RelationType::Documents ) );
        CHECK( "IsCompiledBy" == enums::toString( RelationType::IsCompiledBy ) );
        CHECK( "Complies" == enums::toString( RelationType::Complies ) );
        CHECK( "IsVariantFormOf" == enums::toString( RelationType::IsVariantFormOf ) );
        CHECK( "IsOriginalFormOf" == enums::toString( RelationType::IsOriginalFormOf ) );
        CHECK( "IsIdenticalTo" == enums::toString( RelationType::IsIdenticalTo ) );
        CHECK( "IsReviewedBy" == enums::toString( RelationType::IsReviewedBy ) );
        CHECK( "Reviews" == enums::toString( RelationType::Reviews ) );
        CHECK( "IsDerivedFrom" == enums::toString( RelationType::IsDerivedFrom ) );
        CHECK( "IsSourceOf" == enums::toString( RelationType::IsSourceOf ) );
        CHECK( "IsRequiredBy" == enums::toString( RelationType::IsRequiredBy ) );
        CHECK( "Requires" == enums::toString( RelationType::Requires ) );
        CHECK( "Obsoletes" == enums::toString( RelationType::Obsoletes ) );
        CHECK( "IsObsoletedBy" == enums::toString( RelationType::IsObsoletedBy ) );
      } // THEN
    } // WHEN

    WHEN( "fromString is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( RelationType::IsCitedBy == enums::fromString< RelationType >( "IsCitedBy" ) );
        CHECK( RelationType::Cites == enums::fromString< RelationType >( "Cites" ) );
        CHECK( RelationType::IsSupplementTo == enums::fromString< RelationType >( "IsSupplementTo" ) );
        CHECK( RelationType::IsSupplementedBy == enums::fromString< RelationType >( "IsSupplementedBy" ) );
        CHECK( RelationType::IsContinuedBy == enums::fromString< RelationType >( "IsContinuedBy" ) );
        CHECK( RelationType::Continues == enums::fromString< RelationType >( "Continues" ) );
        CHECK( RelationType::Describes == enums::fromString< RelationType >( "Describes" ) );
        CHECK( RelationType::IsDescribedBy == enums::fromString< RelationType >( "IsDescribedBy" ) );
        CHECK( RelationType::HasMetadata == enums::fromString< RelationType >( "HasMetadata" ) );
        CHECK( RelationType::IsMetadataFor == enums::fromString< RelationType >( "IsMetadataFor" ) );
        CHECK( RelationType::HasVersion == enums::fromString< RelationType >( "HasVersion" ) );
        CHECK( RelationType::IsVersionOf == enums::fromString< RelationType >( "IsVersionOf" ) );
        CHECK( RelationType::IsNewVersionOf == enums::fromString< RelationType >( "IsNewVersionOf" ) );
        CHECK( RelationType::IsPreviousVersionOf == enums::fromString< RelationType >( "IsPreviousVersionOf" ) );
        CHECK( RelationType::IsPartOf == enums::fromString< RelationType >( "IsPartOf" ) );
        CHECK( RelationType::HasPart == enums::fromString< RelationType >( "HasPart" ) );
        CHECK( RelationType::IsPublishedIn == enums::fromString< RelationType >( "IsPublishedIn" ) );
        CHECK( RelationType::IsReferencedBy == enums::fromString< RelationType >( "IsReferencedBy" ) );
        CHECK( RelationType::References == enums::fromString< RelationType >( "References" ) );
        CHECK( RelationType::IsDocumentedBy == enums::fromString< RelationType >( "IsDocumentedBy" ) );
        CHECK( RelationType::Documents == enums::fromString< RelationType >( "Documents" ) );
        CHECK( RelationType::IsCompiledBy == enums::fromString< RelationType >( "IsCompiledBy" ) );
        CHECK( RelationType::Complies == enums::fromString< RelationType >( "Complies" ) );
        CHECK( RelationType::IsVariantFormOf == enums::fromString< RelationType >( "IsVariantFormOf" ) );
        CHECK( RelationType::IsOriginalFormOf == enums::fromString< RelationType >( "IsOriginalFormOf" ) );
        CHECK( RelationType::IsIdenticalTo == enums::fromString< RelationType >( "IsIdenticalTo" ) );
        CHECK( RelationType::IsReviewedBy == enums::fromString< RelationType >( "IsReviewedBy" ) );
        CHECK( RelationType::Reviews == enums::fromString< RelationType >( "Reviews" ) );
        CHECK( RelationType::IsDerivedFrom == enums::fromString< RelationType >( "IsDerivedFrom" ) );
        CHECK( RelationType::IsSourceOf == enums::fromString< RelationType >( "IsSourceOf" ) );
        CHECK( RelationType::IsRequiredBy == enums::fromString< RelationType >( "IsRequiredBy" ) );
        CHECK( RelationType::Requires == enums::fromString< RelationType >( "Requires" ) );
        CHECK( RelationType::Obsoletes == enums::fromString< RelationType >( "Obsoletes" ) );
        CHECK( RelationType::IsObsoletedBy == enums::fromString< RelationType >( "IsObsoletedBy" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( enums::fromString< RelationType >( "unregistered" ) );
      } // THEN
    } // WHEN

    WHEN( "operator<< is used" ) {

      THEN( "no exception is thrown and the symbol is written to the stream" ) {

        std::ostringstream out;
        out << RelationType::IsCitedBy << ' '
            << RelationType::Cites << ' '
            << RelationType::IsSupplementTo << ' '
            << RelationType::IsSupplementedBy << ' '
            << RelationType::IsContinuedBy << ' '
            << RelationType::Continues << ' '
            << RelationType::Describes << ' '
            << RelationType::IsDescribedBy << ' '
            << RelationType::HasMetadata << ' '
            << RelationType::IsMetadataFor << ' '
            << RelationType::HasVersion << ' '
            << RelationType::IsVersionOf << ' '
            << RelationType::IsNewVersionOf << ' '
            << RelationType::IsPreviousVersionOf << ' '
            << RelationType::IsPartOf << ' '
            << RelationType::HasPart << ' '
            << RelationType::IsPublishedIn << ' '
            << RelationType::IsReferencedBy << ' '
            << RelationType::References << ' '
            << RelationType::IsDocumentedBy << ' '
            << RelationType::Documents << ' '
            << RelationType::IsCompiledBy << ' '
            << RelationType::Complies << ' '
            << RelationType::IsVariantFormOf << ' '
            << RelationType::IsOriginalFormOf << ' '
            << RelationType::IsIdenticalTo << ' '
            << RelationType::IsReviewedBy << ' '
            << RelationType::Reviews << ' '
            << RelationType::IsDerivedFrom << ' '
            << RelationType::IsSourceOf << ' '
            << RelationType::IsRequiredBy << ' '
            << RelationType::Requires << ' '
            << RelationType::Obsoletes << ' '
            << RelationType::IsObsoletedBy;

        CHECK( "IsCitedBy Cites IsSupplementTo IsSupplementedBy IsContinuedBy "
               "Continues Describes IsDescribedBy HasMetadata IsMetadataFor "
               "HasVersion IsVersionOf IsNewVersionOf IsPreviousVersionOf "
               "IsPartOf HasPart IsPublishedIn IsReferencedBy References "
               "IsDocumentedBy Documents IsCompiledBy Complies IsVariantFormOf "
               "IsOriginalFormOf IsIdenticalTo IsReviewedBy Reviews IsDerivedFrom "
               "IsSourceOf IsRequiredBy Requires Obsoletes IsObsoletedBy"
               == out.str() );
      } // THEN
    } // WHEN

    WHEN( "operator>> is used" ) {

      THEN( "the stream is not in fail() when the symbol is registered" ) {

        RelationType value;
        std::istringstream in( "IsCitedBy Cites IsSupplementTo IsSupplementedBy IsContinuedBy "
                               "Continues Describes IsDescribedBy HasMetadata IsMetadataFor "
                               "HasVersion IsVersionOf IsNewVersionOf IsPreviousVersionOf "
                               "IsPartOf HasPart IsPublishedIn IsReferencedBy References "
                               "IsDocumentedBy Documents IsCompiledBy Complies IsVariantFormOf "
                               "IsOriginalFormOf IsIdenticalTo IsReviewedBy Reviews IsDerivedFrom "
                               "IsSourceOf IsRequiredBy Requires Obsoletes IsObsoletedBy" );

        in >> value;
        CHECK( RelationType::IsCitedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Cites == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsSupplementTo == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsSupplementedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsContinuedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Continues == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Describes == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsDescribedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::HasMetadata == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsMetadataFor == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::HasVersion == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsVersionOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsNewVersionOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsPreviousVersionOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsPartOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::HasPart == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsPublishedIn == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsReferencedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::References == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsDocumentedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Documents == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsCompiledBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Complies == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsVariantFormOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsOriginalFormOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsIdenticalTo == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsReviewedBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Reviews == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsDerivedFrom == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsSourceOf == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsRequiredBy == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Requires == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::Obsoletes == value );
        CHECK( false == in.fail() );
        CHECK( false == in.eof() );

        in >> value;
        CHECK( RelationType::IsObsoletedBy == value );
        CHECK( false == in.fail() );
        CHECK( true == in.eof() );
      } // THEN

      THEN( "the stream is in fail() and the position has not changed when "
            "the symbol is not registered" ) {

        RelationType value = RelationType::IsCitedBy;
        std::istringstream in( "unregistered" );
        in >> value;

        CHECK( RelationType::IsCitedBy == value );
        CHECK( true == in.fail() );
      } // THEN
    } // WHEN

    WHEN( "isRelationType is used" ) {

      THEN( "registered date types return true, "
            "unregistered date types return false" ) {

        CHECK( true == enums::isRelationType( "IsCitedBy" ) );
        CHECK( true == enums::isRelationType( "Cites" ) );
        CHECK( true == enums::isRelationType( "IsSupplementTo" ) );
        CHECK( true == enums::isRelationType( "IsSupplementedBy" ) );
        CHECK( true == enums::isRelationType( "IsContinuedBy" ) );
        CHECK( true == enums::isRelationType( "Continues" ) );
        CHECK( true == enums::isRelationType( "Describes" ) );
        CHECK( true == enums::isRelationType( "IsDescribedBy" ) );
        CHECK( true == enums::isRelationType( "HasMetadata" ) );
        CHECK( true == enums::isRelationType( "IsMetadataFor" ) );
        CHECK( true == enums::isRelationType( "HasVersion" ) );
        CHECK( true == enums::isRelationType( "IsVersionOf" ) );
        CHECK( true == enums::isRelationType( "IsNewVersionOf" ) );
        CHECK( true == enums::isRelationType( "IsPreviousVersionOf" ) );
        CHECK( true == enums::isRelationType( "IsPartOf" ) );
        CHECK( true == enums::isRelationType( "HasPart" ) );
        CHECK( true == enums::isRelationType( "IsPublishedIn" ) );
        CHECK( true == enums::isRelationType( "IsReferencedBy" ) );
        CHECK( true == enums::isRelationType( "References" ) );
        CHECK( true == enums::isRelationType( "IsDocumentedBy" ) );
        CHECK( true == enums::isRelationType( "Documents" ) );
        CHECK( true == enums::isRelationType( "IsCompiledBy" ) );
        CHECK( true == enums::isRelationType( "Complies" ) );
        CHECK( true == enums::isRelationType( "IsVariantFormOf" ) );
        CHECK( true == enums::isRelationType( "IsOriginalFormOf" ) );
        CHECK( true == enums::isRelationType( "IsIdenticalTo" ) );
        CHECK( true == enums::isRelationType( "IsReviewedBy" ) );
        CHECK( true == enums::isRelationType( "Reviews" ) );
        CHECK( true == enums::isRelationType( "IsDerivedFrom" ) );
        CHECK( true == enums::isRelationType( "IsSourceOf" ) );
        CHECK( true == enums::isRelationType( "IsRequiredBy" ) );
        CHECK( true == enums::isRelationType( "Requires" ) );
        CHECK( true == enums::isRelationType( "Obsoletes" ) );
        CHECK( true == enums::isRelationType( "IsObsoletedBy" ) );
        CHECK( false == enums::isRelationType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
