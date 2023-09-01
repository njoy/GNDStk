
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapBoundaryCondition( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::BoundaryCondition;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "BoundaryCondition",
    "Enumeration class giving acceptable boundary condition values",
    pybind11::arithmetic()
  );

  // wrap the component
  component
  .value( "EliminateShiftFunction", Component::EliminateShiftFunction )
  .value( "NegativeOrbitalMomentum", Component::NegativeOrbitalMomentum )
  .value( "Brune", Component::Brune )
  .value( "Given", Component::Given );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
