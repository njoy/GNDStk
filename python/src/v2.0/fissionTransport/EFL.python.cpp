
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fissionTransport/EFL.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// EFL wrapper
void wrapEFL(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fissionTransport::EFL;

   // create the component
   python::class_<Component> component(
      module,
      "EFL",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const Float64 &
         >(),
         python::arg("unit"),
         python::arg("value"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::documentation("unit").data()
      )
      .def_property_readonly(
         "value",
         &Component::value,
         Component::documentation("value").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0
