
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapRelationType( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::RelationType;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "RelationType",
    "Enumeration class giving acceptable relation type values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "IsCitedBy", Component::IsCitedBy )
  .value( "Cites", Component::Cites )
  .value( "IsSupplementTo", Component::IsSupplementTo )
  .value( "IsSupplementedBy", Component::IsSupplementedBy )
  .value( "IsContinuedBy", Component::IsContinuedBy )
  .value( "Continues", Component::Continues )
  .value( "Describes", Component::Describes )
  .value( "IsDescribedBy", Component::IsDescribedBy )
  .value( "HasMetadata", Component::HasMetadata )
  .value( "IsMetadataFor", Component::IsMetadataFor )
  .value( "HasVersion", Component::HasVersion )
  .value( "IsVersionOf", Component::IsVersionOf )
  .value( "IsNewVersionOf", Component::IsNewVersionOf )
  .value( "IsPreviousVersionOf", Component::IsPreviousVersionOf )
  .value( "IsPartOf", Component::IsPartOf )
  .value( "HasPart", Component::HasPart )
  .value( "IsPublishedIn", Component::IsPublishedIn )
  .value( "IsReferencedBy", Component::IsReferencedBy )
  .value( "References", Component::References )
  .value( "IsDocumentedBy", Component::IsDocumentedBy )
  .value( "Documents", Component::Documents )
  .value( "IsCompiledBy", Component::IsCompiledBy )
  .value( "Compiles", Component::Compiles )
  .value( "IsVariantFormOf", Component::IsVariantFormOf )
  .value( "IsOriginalFormOf", Component::IsOriginalFormOf )
  .value( "IsIdenticalTo", Component::IsIdenticalTo )
  .value( "IsReviewedBy", Component::IsReviewedBy )
  .value( "Reviews", Component::Reviews )
  .value( "IsDerivedFrom", Component::IsDerivedFrom )
  .value( "IsSourceOf", Component::IsSourceOf )
  .value( "IsRequiredBy", Component::IsRequiredBy )
  .value( "Requires", Component::Requires )
  .value( "Obsoletes", Component::Obsoletes )
  .value( "IsObsoletedBy", Component::IsObsoletedBy );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
