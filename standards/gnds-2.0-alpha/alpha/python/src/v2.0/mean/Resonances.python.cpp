
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/Resonances.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// Resonances wrapper
void wrapResonances(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::Resonances;

   // create the component
   python::class_<Component> component(
      module,
      "Resonances",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<mean::ScatteringRadius> &,
            const std::optional<mean::Resolved> &,
            const std::optional<mean::Unresolved> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("scattering_radius") = std::nullopt,
         python::arg("resolved") = std::nullopt,
         python::arg("unresolved") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self) { return self.href(); },
         Component::documentation("href").data()
      )
      .def_property_readonly(
         "scattering_radius",
         [](const Component &self) { return self.scatteringRadius(); },
         Component::documentation("scattering_radius").data()
      )
      .def_property_readonly(
         "resolved",
         [](const Component &self) { return self.resolved(); },
         Component::documentation("resolved").data()
      )
      .def_property_readonly(
         "unresolved",
         [](const Component &self) { return self.unresolved(); },
         Component::documentation("unresolved").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
