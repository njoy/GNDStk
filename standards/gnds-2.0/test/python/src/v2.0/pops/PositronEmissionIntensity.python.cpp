
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/PositronEmissionIntensity.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// PositronEmissionIntensity wrapper
void wrapPositronEmissionIntensity(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::PositronEmissionIntensity;

   // create the component
   python::class_<Component> component(
      module,
      "PositronEmissionIntensity",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Float64 &,
            const std::optional<pops::Uncertainty> &
         >(),
         python::arg("value"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "value",
         [](const Component &self) { return self.value(); },
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self) { return self.uncertainty(); },
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
