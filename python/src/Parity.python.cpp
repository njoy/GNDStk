// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_core {

void wrapParity( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::Parity;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "Parity",
    "Enumeration class giving acceptable parity values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "minus", Component::minus )
  .value( "plus", Component::plus );
}

} // namespace python_core
