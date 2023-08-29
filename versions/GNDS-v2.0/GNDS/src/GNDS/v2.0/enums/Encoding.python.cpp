
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

void wrapEncoding( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::Encoding;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "Encoding",
    "Enumeration class giving acceptable encoding values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "ascii", Component::ascii )
  .value( "utf8", Component::utf8 );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
