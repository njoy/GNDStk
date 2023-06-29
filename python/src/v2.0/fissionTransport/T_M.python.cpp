
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fissionTransport/T_M.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// T_M wrapper
void wrapT_M(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fissionTransport::T_M;

   // create the component
   python::class_<Component> component(
      module,
      "T_M",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::XYs1d &
         >(),
         python::arg("xys1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         python::overload_cast<>(&Component::XYs1d),
         Component::documentation("xys1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0
