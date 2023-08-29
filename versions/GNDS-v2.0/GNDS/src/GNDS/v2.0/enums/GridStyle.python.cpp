
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

void wrapGridStyle( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::GridStyle;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "GridStyle",
    "Enumeration class giving acceptable grid style values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "none", Component::none )
  .value( "link", Component::link )
  .value( "points", Component::points )
  .value( "boundaries", Component::boundaries )
  .value( "parameters", Component::parameters );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
