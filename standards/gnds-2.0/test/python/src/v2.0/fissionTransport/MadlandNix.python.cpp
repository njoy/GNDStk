
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/MadlandNix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// MadlandNix wrapper
void wrapMadlandNix(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fissionTransport::MadlandNix;

   // create the component
   python::class_<Component> component(
      module,
      "MadlandNix",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const fissionTransport::EFH &,
            const fissionTransport::EFL &,
            const fissionTransport::T_M &
         >(),
         python::arg("efh"),
         python::arg("efl"),
         python::arg("t_m"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "efh",
         [](const Component &self) { return self.EFH(); },
         Component::documentation("efh").data()
      )
      .def_property_readonly(
         "efl",
         [](const Component &self) { return self.EFL(); },
         Component::documentation("efl").data()
      )
      .def_property_readonly(
         "t_m",
         [](const Component &self) { return self.T_M(); },
         Component::documentation("t_m").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0
