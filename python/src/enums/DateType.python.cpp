// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_core {

void wrapDateType( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::DateType;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "DateType",
    "Enumeration class giving acceptable date type values",
    python::arithmetic()
  );

  // wrap the component
  component
  .value( "accepted", Component::accepted )
  .value( "available", Component::available )
  .value( "copyrighted", Component::copyrighted )
  .value( "collected", Component::collected )
  .value( "created", Component::created )
  .value( "issued", Component::issued )
  .value( "submitted", Component::submitted )
  .value( "updated", Component::updated )
  .value( "valid", Component::valid )
  .value( "withdrawn", Component::withdrawn );
}

} // namespace python_core
