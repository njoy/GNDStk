
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Styles.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Styles
void wrapStyles(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Styles;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Styles",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Evaluated &,
         const std::optional<general::CrossSectionReconstructed> &
      >(),
      py::arg("evaluated"),
      py::arg("cross_section_reconstructed") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set evaluated
   object.def_property(
      "evaluated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaluated();
      },
      [](cppCLASS &self, const general::Evaluated &value)
      {
         self.evaluated() = value;
      },
      cppCLASS::component_t::documentation("evaluated").data()
   );

   // get/set crossSectionReconstructed
   object.def_property(
      "cross_section_reconstructed",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSectionReconstructed();
      },
      [](cppCLASS &self, const std::optional<general::CrossSectionReconstructed> &value)
      {
         self.crossSectionReconstructed() = value;
      },
      cppCLASS::component_t::documentation("cross_section_reconstructed").data()
   );

   // shortcut: get/set authors
   object.def_property(
      "authors",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.authors();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.authors())> &value)
      {
         self.authors() = value;
      },
      cppCLASS::component_t::documentation("authors").data()
   );

   // shortcut: get/set body
   object.def_property(
      "body",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.body();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.body())> &value)
      {
         self.body() = value;
      },
      cppCLASS::component_t::documentation("body").data()
   );

   // shortcut: get/set dates
   object.def_property(
      "dates",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dates();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.dates())> &value)
      {
         self.dates() = value;
      },
      cppCLASS::component_t::documentation("dates").data()
   );

   // shortcut: get/set documentation
   object.def_property(
      "documentation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.documentation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.documentation())> &value)
      {
         self.documentation() = value;
      },
      cppCLASS::component_t::documentation("documentation").data()
   );

   // shortcut: get/set endfCompatible
   object.def_property(
      "endf_compatible",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.endfCompatible();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.endfCompatible())> &value)
      {
         self.endfCompatible() = value;
      },
      cppCLASS::component_t::documentation("endf_compatible").data()
   );

   // shortcut: get/set projectileEnergyDomain
   object.def_property(
      "projectile_energy_domain",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.projectileEnergyDomain();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.projectileEnergyDomain())> &value)
      {
         self.projectileEnergyDomain() = value;
      },
      cppCLASS::component_t::documentation("projectile_energy_domain").data()
   );

   // shortcut: get/set temperature
   object.def_property(
      "temperature",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.temperature();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.temperature())> &value)
      {
         self.temperature() = value;
      },
      cppCLASS::component_t::documentation("temperature").data()
   );

   // shortcut: get/set title
   object.def_property(
      "title",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.title();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.title())> &value)
      {
         self.title() = value;
      },
      cppCLASS::component_t::documentation("title").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
