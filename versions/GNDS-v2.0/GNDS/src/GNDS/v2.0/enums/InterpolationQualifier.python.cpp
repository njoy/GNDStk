
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapInterpolationQualifier( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::InterpolationQualifier;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "InterpolationQualifier",
    "Enumeration class giving acceptable interpolation qualifier values",
    pybind11::arithmetic()
  );

  // wrap the component
  component
  .value( "direct", Component::direct )
  .value( "unitBase", Component::unitBase )
  .value( "correspondingEnergies", Component::correspondingEnergies )
  .value( "correspondingPoints", Component::correspondingPoints );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS