
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapDateType( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::DateType;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "DateType",
    "Enumeration class giving acceptable date type values",
    pybind11::arithmetic()
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

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
