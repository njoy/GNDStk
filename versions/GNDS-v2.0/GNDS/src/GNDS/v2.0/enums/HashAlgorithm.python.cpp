
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

void wrapHashAlgorithm( python::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::HashAlgorithm;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "HashAlgorithm",
    "Enumeration class giving acceptable hash algorithm values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "md5", Component::md5 )
  .value( "sha1", Component::sha1 );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
