
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

void wrapBoundaryCondition( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::BoundaryCondition;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "BoundaryCondition",
    "Enumeration class giving acceptable boundary condition values",
    python::arithmetic()
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
