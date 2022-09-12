
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Double.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Double wrapper
void wrapDouble(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::Double;

   // create the component
   python::class_<Component> component(
      module,
      "Double",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const Float64 &,
            const std::optional<containers::Uncertainty> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("value"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "unit",
         [](const Component &self) { return self.unit(); },
         Component::documentation("unit").data()
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

} // namespace python_containers
} // namespace python_v2_0