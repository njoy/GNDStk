// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace core {

void wrapInterpolationQualifier( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::InterpolationQualifier;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "InterpolationQualifier",
    "Enumeration class giving acceptable interpolation qualifier values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "direct", Component::direct )
  .value( "unitBase", Component::unitBase )
  .value( "correspondingEnergies", Component::correspondingEnergies )
  .value( "correspondingPoints", Component::correspondingPoints );
}

} // namespace core
