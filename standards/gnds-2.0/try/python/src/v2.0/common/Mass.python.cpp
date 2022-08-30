
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/common/Mass.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Mass wrapper
void wrapMass(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = common::Mass;

   // create the component
   python::class_<Component> component(
      module,
      "Mass",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const std::optional<documentation::Documentation> &,
            const std::optional<pops::Uncertainty> &,
            const std::vector<containers::Double> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("value") = std::nullopt,
         python::arg("documentation") = std::nullopt,
         python::arg("uncertainty") = std::nullopt,
         python::arg("double"),
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
         "double",
         [](const Component &self) { return self.Double(); },
         Component::documentation("double").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
