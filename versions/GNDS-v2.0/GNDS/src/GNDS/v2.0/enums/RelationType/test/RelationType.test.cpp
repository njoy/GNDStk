
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDS/v2.0/enums/RelationType.hpp"
using namespace GNDS::v2_0::enums;

SCENARIO( "RelationType" ) {

  GIVEN( "valid encoding values and symbols" ) {

    WHEN( "enum2string is used" ) {

      THEN( "no exception is thrown and the correct string is returned" ) {

        CHECK( "IsCitedBy" == enum2string( RelationType::IsCitedBy ) );
        CHECK( "Cites" == enum2string( RelationType::Cites ) );
        CHECK( "IsSupplementTo" == enum2string( RelationType::IsSupplementTo ) );
        CHECK( "IsSupplementedBy" == enum2string( RelationType::IsSupplementedBy ) );
        CHECK( "IsContinuedBy" == enum2string( RelationType::IsContinuedBy ) );
        CHECK( "Continues" == enum2string( RelationType::Continues ) );
        CHECK( "Describes" == enum2string( RelationType::Describes ) );
        CHECK( "IsDescribedBy" == enum2string( RelationType::IsDescribedBy ) );
        CHECK( "HasMetadata" == enum2string( RelationType::HasMetadata ) );
        CHECK( "IsMetadataFor" == enum2string( RelationType::IsMetadataFor ) );
        CHECK( "HasVersion" == enum2string( RelationType::HasVersion ) );
        CHECK( "IsVersionOf" == enum2string( RelationType::IsVersionOf ) );
        CHECK( "IsNewVersionOf" == enum2string( RelationType::IsNewVersionOf ) );
        CHECK( "IsPreviousVersionOf" == enum2string( RelationType::IsPreviousVersionOf ) );
        CHECK( "IsPartOf" == enum2string( RelationType::IsPartOf ) );
        CHECK( "HasPart" == enum2string( RelationType::HasPart ) );
        CHECK( "IsPublishedIn" == enum2string( RelationType::IsPublishedIn ) );
        CHECK( "IsReferencedBy" == enum2string( RelationType::IsReferencedBy ) );
        CHECK( "References" == enum2string( RelationType::References ) );
        CHECK( "IsDocumentedBy" == enum2string( RelationType::IsDocumentedBy ) );
        CHECK( "Documents" == enum2string( RelationType::Documents ) );
        CHECK( "IsCompiledBy" == enum2string( RelationType::IsCompiledBy ) );
        CHECK( "Compiles" == enum2string( RelationType::Compiles ) );
        CHECK( "IsVariantFormOf" == enum2string( RelationType::IsVariantFormOf ) );
        CHECK( "IsOriginalFormOf" == enum2string( RelationType::IsOriginalFormOf ) );
        CHECK( "IsIdenticalTo" == enum2string( RelationType::IsIdenticalTo ) );
        CHECK( "IsReviewedBy" == enum2string( RelationType::IsReviewedBy ) );
        CHECK( "Reviews" == enum2string( RelationType::Reviews ) );
        CHECK( "IsDerivedFrom" == enum2string( RelationType::IsDerivedFrom ) );
        CHECK( "IsSourceOf" == enum2string( RelationType::IsSourceOf ) );
        CHECK( "IsRequiredBy" == enum2string( RelationType::IsRequiredBy ) );
        CHECK( "Requires" == enum2string( RelationType::Requires ) );
        CHECK( "Obsoletes" == enum2string( RelationType::Obsoletes ) );
        CHECK( "IsObsoletedBy" == enum2string( RelationType::IsObsoletedBy ) );
      } // THEN
    } // WHEN

    WHEN( "string2enum is used" ) {

      THEN( "no exception is thrown when the symbol is registered" ) {

        CHECK( RelationType::IsCitedBy == string2enum< RelationType >( "IsCitedBy" ) );
        CHECK( RelationType::Cites == string2enum< RelationType >( "Cites" ) );
        CHECK( RelationType::IsSupplementTo == string2enum< RelationType >( "IsSupplementTo" ) );
        CHECK( RelationType::IsSupplementedBy == string2enum< RelationType >( "IsSupplementedBy" ) );
        CHECK( RelationType::IsContinuedBy == string2enum< RelationType >( "IsContinuedBy" ) );
        CHECK( RelationType::Continues == string2enum< RelationType >( "Continues" ) );
        CHECK( RelationType::Describes == string2enum< RelationType >( "Describes" ) );
        CHECK( RelationType::IsDescribedBy == string2enum< RelationType >( "IsDescribedBy" ) );
        CHECK( RelationType::HasMetadata == string2enum< RelationType >( "HasMetadata" ) );
        CHECK( RelationType::IsMetadataFor == string2enum< RelationType >( "IsMetadataFor" ) );
        CHECK( RelationType::HasVersion == string2enum< RelationType >( "HasVersion" ) );
        CHECK( RelationType::IsVersionOf == string2enum< RelationType >( "IsVersionOf" ) );
        CHECK( RelationType::IsNewVersionOf == string2enum< RelationType >( "IsNewVersionOf" ) );
        CHECK( RelationType::IsPreviousVersionOf == string2enum< RelationType >( "IsPreviousVersionOf" ) );
        CHECK( RelationType::IsPartOf == string2enum< RelationType >( "IsPartOf" ) );
        CHECK( RelationType::HasPart == string2enum< RelationType >( "HasPart" ) );
        CHECK( RelationType::IsPublishedIn == string2enum< RelationType >( "IsPublishedIn" ) );
        CHECK( RelationType::IsReferencedBy == string2enum< RelationType >( "IsReferencedBy" ) );
        CHECK( RelationType::References == string2enum< RelationType >( "References" ) );
        CHECK( RelationType::IsDocumentedBy == string2enum< RelationType >( "IsDocumentedBy" ) );
        CHECK( RelationType::Documents == string2enum< RelationType >( "Documents" ) );
        CHECK( RelationType::IsCompiledBy == string2enum< RelationType >( "IsCompiledBy" ) );
        CHECK( RelationType::Compiles == string2enum< RelationType >( "Compiles" ) );
        CHECK( RelationType::IsVariantFormOf == string2enum< RelationType >( "IsVariantFormOf" ) );
        CHECK( RelationType::IsOriginalFormOf == string2enum< RelationType >( "IsOriginalFormOf" ) );
        CHECK( RelationType::IsIdenticalTo == string2enum< RelationType >( "IsIdenticalTo" ) );
        CHECK( RelationType::IsReviewedBy == string2enum< RelationType >( "IsReviewedBy" ) );
        CHECK( RelationType::Reviews == string2enum< RelationType >( "Reviews" ) );
        CHECK( RelationType::IsDerivedFrom == string2enum< RelationType >( "IsDerivedFrom" ) );
        CHECK( RelationType::IsSourceOf == string2enum< RelationType >( "IsSourceOf" ) );
        CHECK( RelationType::IsRequiredBy == string2enum< RelationType >( "IsRequiredBy" ) );
        CHECK( RelationType::Requires == string2enum< RelationType >( "Requires" ) );
        CHECK( RelationType::Obsoletes == string2enum< RelationType >( "Obsoletes" ) );
        CHECK( RelationType::IsObsoletedBy == string2enum< RelationType >( "IsObsoletedBy" ) );
      } // THEN

      THEN( "an exception is thrown when the symbol is not registered" ) {

        CHECK_THROWS( string2enum< RelationType >( "unregistered" ) );
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
            << RelationType::Compiles << ' '
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
               "IsDocumentedBy Documents IsCompiledBy Compiles IsVariantFormOf "
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
                               "IsDocumentedBy Documents IsCompiledBy Compiles IsVariantFormOf "
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
        CHECK( RelationType::Compiles == value );
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

        CHECK( true == isRelationType( "IsCitedBy" ) );
        CHECK( true == isRelationType( "Cites" ) );
        CHECK( true == isRelationType( "IsSupplementTo" ) );
        CHECK( true == isRelationType( "IsSupplementedBy" ) );
        CHECK( true == isRelationType( "IsContinuedBy" ) );
        CHECK( true == isRelationType( "Continues" ) );
        CHECK( true == isRelationType( "Describes" ) );
        CHECK( true == isRelationType( "IsDescribedBy" ) );
        CHECK( true == isRelationType( "HasMetadata" ) );
        CHECK( true == isRelationType( "IsMetadataFor" ) );
        CHECK( true == isRelationType( "HasVersion" ) );
        CHECK( true == isRelationType( "IsVersionOf" ) );
        CHECK( true == isRelationType( "IsNewVersionOf" ) );
        CHECK( true == isRelationType( "IsPreviousVersionOf" ) );
        CHECK( true == isRelationType( "IsPartOf" ) );
        CHECK( true == isRelationType( "HasPart" ) );
        CHECK( true == isRelationType( "IsPublishedIn" ) );
        CHECK( true == isRelationType( "IsReferencedBy" ) );
        CHECK( true == isRelationType( "References" ) );
        CHECK( true == isRelationType( "IsDocumentedBy" ) );
        CHECK( true == isRelationType( "Documents" ) );
        CHECK( true == isRelationType( "IsCompiledBy" ) );
        CHECK( true == isRelationType( "Compiles" ) );
        CHECK( true == isRelationType( "IsVariantFormOf" ) );
        CHECK( true == isRelationType( "IsOriginalFormOf" ) );
        CHECK( true == isRelationType( "IsIdenticalTo" ) );
        CHECK( true == isRelationType( "IsReviewedBy" ) );
        CHECK( true == isRelationType( "Reviews" ) );
        CHECK( true == isRelationType( "IsDerivedFrom" ) );
        CHECK( true == isRelationType( "IsSourceOf" ) );
        CHECK( true == isRelationType( "IsRequiredBy" ) );
        CHECK( true == isRelationType( "Requires" ) );
        CHECK( true == isRelationType( "Obsoletes" ) );
        CHECK( true == isRelationType( "IsObsoletedBy" ) );
        CHECK( false == isRelationType( "unregistered" ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
