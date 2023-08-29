
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapInterpolation( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::Interpolation;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "Interpolation",
    "Enumeration class giving acceptable interpolation values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "flat", Component::flat )
  .value( "linlin", Component::linlin )
  .value( "linlog", Component::linlog )
  .value( "loglin", Component::loglin )
  .value( "loglog", Component::loglog )
  .value( "chargedparticle", Component::chargedparticle );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
