
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Regions1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Regions1d wrapper
void wrapRegions1d(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Regions1d;

   // create the component
   python::class_<Component> component(
      module, "Regions1d",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<double> &,
            const std::optional<general::Axes> &,
            const std::optional<general::Uncertainty> &,
            const reduced::Function1ds &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("axes") = std::nullopt,
         python::arg("uncertainty") = std::nullopt,
         python::arg("function1ds"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::component_t::documentation("label").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         [](const Component &self)
         {
            return self.outerDomainValue();
         },
         Component::component_t::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self)
         {
            return self.axes();
         },
         Component::component_t::documentation("axes").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self)
         {
            return self.uncertainty();
         },
         Component::component_t::documentation("uncertainty").data()
      )
      .def_property_readonly(
         "function1ds",
         [](const Component &self)
         {
            return self.function1ds();
         },
         Component::component_t::documentation("function1ds").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
