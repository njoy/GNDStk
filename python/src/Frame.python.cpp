// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_core {

void wrapFrame( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::Frame;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "Frame",
    "Enumeration class giving acceptable reference frame values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "lab", Component::lab )
  .value( "centerOfMass", Component::centerOfMass );
}

} // namespace python_core
