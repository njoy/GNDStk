
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Regions2d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Regions2d wrapper
void wrapRegions2d(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::Regions2d;

   // create the component
   python::class_<Component> component(
      module,
      "Regions2d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<containers::Axes> &,
            const containers::Function2ds &,
            const std::optional<containers::Uncertainty> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("axes") = std::nullopt,
         python::arg("function2ds"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         [](const Component &self) { return self.outerDomainValue(); },
         Component::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self) { return self.axes(); },
         Component::documentation("axes").data()
      )
      .def_property_readonly(
         "function2ds",
         [](const Component &self) { return self.function2ds(); },
         Component::documentation("function2ds").data()
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
