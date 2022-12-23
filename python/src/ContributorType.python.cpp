// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace core {

void wrapContributorType( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::ContributorType;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "ContributorType",
    "Enumeration class giving acceptable contributor type values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "ContactPerson", Component::ContactPerson )
  .value( "DataCollector", Component::DataCollector )
  .value( "DataCurator", Component::DataCurator )
  .value( "DataManager", Component::DataManager )
  .value( "Distributor", Component::Distributor )
  .value( "Editor", Component::Editor )
  .value( "HostingInstitution", Component::HostingInstitution )
  .value( "Producer", Component::Producer )
  .value( "ProjectLeader", Component::ProjectLeader )
  .value( "ProjectManager", Component::ProjectManager )
  .value( "ProjectMember", Component::ProjectMember )
  .value( "RegistrationAgency", Component::RegistrationAgency )
  .value( "RegistrationAuthority", Component::RegistrationAuthority )
  .value( "RelatedPerson", Component::RelatedPerson )
  .value( "Researcher", Component::Researcher )
  .value( "ResearchGroup", Component::ResearchGroup )
  .value( "RightsHolder", Component::RightsHolder )
  .value( "Sponsor", Component::Sponsor )
  .value( "Supervisor", Component::Supervisor )
  .value( "WorkPackageLeader", Component::WorkPackageLeader )
  .value( "Other", Component::Other );
}

} // namespace core
