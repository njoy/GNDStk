
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Resonances.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Resonances wrapper
void wrapResonances(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Resonances;

   // create the component
   python::class_<Component> component(
      module, "Resonances",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<general::ScatteringRadius> &,
            const std::optional<general::Resolved> &,
            const std::optional<general::Unresolved> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("scattering_radius") = std::nullopt,
         python::arg("resolved") = std::nullopt,
         python::arg("unresolved") = std::nullopt,
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self)
         {
            return self.href();
         },
         Component::component_t::documentation("href").data()
      )
      .def_property_readonly(
         "scattering_radius",
         [](const Component &self)
         {
            return self.scatteringRadius();
         },
         Component::component_t::documentation("scattering_radius").data()
      )
      .def_property_readonly(
         "resolved",
         [](const Component &self)
         {
            return self.resolved();
         },
         Component::component_t::documentation("resolved").data()
      )
      .def_property_readonly(
         "unresolved",
         [](const Component &self)
         {
            return self.unresolved();
         },
         Component::component_t::documentation("unresolved").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
