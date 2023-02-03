
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Evaluated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Evaluated wrapper
void wrapEvaluated(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Evaluated;

   // create the component
   python::class_<Component> component(
      module,
      "Evaluated",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::string &,
            const std::string &,
            const general::Documentation &,
            const std::optional<general::Temperature> &,
            const std::optional<general::ProjectileEnergyDomain> &
         >(),
         python::arg("label"),
         python::arg("date"),
         python::arg("library"),
         python::arg("version"),
         python::arg("documentation"),
         python::arg("temperature") = std::nullopt,
         python::arg("projectile_energy_domain") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "date",
         [](const Component &self) { return self.date(); },
         Component::documentation("date").data()
      )
      .def_property_readonly(
         "library",
         [](const Component &self) { return self.library(); },
         Component::documentation("library").data()
      )
      .def_property_readonly(
         "version",
         [](const Component &self) { return self.version(); },
         Component::documentation("version").data()
      )
      .def_property_readonly(
         "documentation",
         [](const Component &self) { return self.documentation(); },
         Component::documentation("documentation").data()
      )
      .def_property_readonly(
         "temperature",
         [](const Component &self) { return self.temperature(); },
         Component::documentation("temperature").data()
      )
      .def_property_readonly(
         "projectile_energy_domain",
         [](const Component &self) { return self.projectileEnergyDomain(); },
         Component::documentation("projectile_energy_domain").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
