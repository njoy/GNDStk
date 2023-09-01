
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapLength( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::Length;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "Length",
    "Enumeration class giving acceptable length values",
    pybind11::arithmetic()
  );

  // wrap the component
  component
  .value( "m", Component::m )
  .value( "cm", Component::cm )
  .value( "fm", Component::fm );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
