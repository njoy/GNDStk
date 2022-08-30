
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/pops/Spin.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Spin wrapper
void wrapSpin(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = pops::Spin;

   // create the component
   python::class_<Component> component(
      module,
      "Spin",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const XMLName &,
            const std::optional<documentation::Documentation> &,
            const std::optional<pops::Uncertainty> &,
            const std::optional<std::vector<containers::Fraction>> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("value"),
         python::arg("documentation") = std::nullopt,
         python::arg("uncertainty") = std::nullopt,
         python::arg("fraction") = std::nullopt,
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
         "documentation",
         [](const Component &self) { return self.documentation(); },
         Component::documentation("documentation").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self) { return self.uncertainty(); },
         Component::documentation("uncertainty").data()
      )
      .def_property_readonly(
         "fraction",
         [](const Component &self) { return self.fraction(); },
         Component::documentation("fraction").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
