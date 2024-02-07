
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapEnergy( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::Energy;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "Energy",
    "Enumeration class giving acceptable energy values",
    pybind11::arithmetic()
  );

  // wrap the component
  component
  .value( "eV", Component::eV )
  .value( "MeV", Component::MeV );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
