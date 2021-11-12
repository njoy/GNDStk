// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace core {

void wrapInteraction( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::Interaction;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "Interaction",
    "Enumeration class giving acceptable interaction type values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "nuclear", Component::nuclear )
  .value( "atomic", Component::atomic )
  .value( "thermalNeutronScatteringLaw", Component::thermalNeutronScatteringLaw );
}

} // namespace core
