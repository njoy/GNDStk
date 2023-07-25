
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/top/ReactionSuite.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_top {

// wrapper for top::ReactionSuite
void wrapReactionSuite(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = top::ReactionSuite;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ReactionSuite",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const general::Styles &,
         const top::PoPs &,
         const general::Reactions &,
         const std::optional<general::ApplicationData> &,
         const std::optional<general::ExternalFiles> &,
         const std::optional<general::Resonances> &,
         const std::optional<general::Sums> &,
         const std::optional<general::Productions> &,
         const std::optional<general::FissionComponents> &,
         const std::optional<general::OrphanProducts> &,
         const std::optional<general::IncompleteReactions> &
      >(),
      py::arg("projectile"),
      py::arg("target"),
      py::arg("evaluation"),
      py::arg("format"),
      py::arg("projectile_frame"),
      py::arg("interaction"),
      py::arg("styles"),
      py::arg("po_ps"),
      py::arg("reactions"),
      py::arg("application_data") = std::nullopt,
      py::arg("external_files") = std::nullopt,
      py::arg("resonances") = std::nullopt,
      py::arg("sums") = std::nullopt,
      py::arg("productions") = std::nullopt,
      py::arg("fission_components") = std::nullopt,
      py::arg("orphan_products") = std::nullopt,
      py::arg("incomplete_reactions") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set projectile
   object.def_property(
      "projectile",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.projectile();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.projectile() = value;
      },
      cppCLASS::component_t::documentation("projectile").data()
   );

   // get/set target
   object.def_property(
      "target",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.target();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.target() = value;
      },
      cppCLASS::component_t::documentation("target").data()
   );

   // get/set evaluation
   object.def_property(
      "evaluation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaluation();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.evaluation() = value;
      },
      cppCLASS::component_t::documentation("evaluation").data()
   );

   // get/set format
   object.def_property(
      "format",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.format();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.format() = value;
      },
      cppCLASS::component_t::documentation("format").data()
   );

   // get/set projectileFrame
   object.def_property(
      "projectile_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.projectileFrame();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.projectileFrame() = value;
      },
      cppCLASS::component_t::documentation("projectile_frame").data()
   );

   // get/set interaction
   object.def_property(
      "interaction",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.interaction();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.interaction() = value;
      },
      cppCLASS::component_t::documentation("interaction").data()
   );

   // get/set styles
   object.def_property(
      "styles",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.styles();
      },
      [](cppCLASS &self, const general::Styles &value)
      {
         self.styles() = value;
      },
      cppCLASS::component_t::documentation("styles").data()
   );

   // get/set PoPs
   object.def_property(
      "po_ps",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.PoPs();
      },
      [](cppCLASS &self, const top::PoPs &value)
      {
         self.PoPs() = value;
      },
      cppCLASS::component_t::documentation("po_ps").data()
   );

   // get/set reactions
   object.def_property(
      "reactions",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.reactions();
      },
      [](cppCLASS &self, const general::Reactions &value)
      {
         self.reactions() = value;
      },
      cppCLASS::component_t::documentation("reactions").data()
   );

   // get/set applicationData
   object.def_property(
      "application_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.applicationData();
      },
      [](cppCLASS &self, const std::optional<general::ApplicationData> &value)
      {
         self.applicationData() = value;
      },
      cppCLASS::component_t::documentation("application_data").data()
   );

   // get/set externalFiles
   object.def_property(
      "external_files",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.externalFiles();
      },
      [](cppCLASS &self, const std::optional<general::ExternalFiles> &value)
      {
         self.externalFiles() = value;
      },
      cppCLASS::component_t::documentation("external_files").data()
   );

   // get/set resonances
   object.def_property(
      "resonances",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonances();
      },
      [](cppCLASS &self, const std::optional<general::Resonances> &value)
      {
         self.resonances() = value;
      },
      cppCLASS::component_t::documentation("resonances").data()
   );

   // get/set sums
   object.def_property(
      "sums",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.sums();
      },
      [](cppCLASS &self, const std::optional<general::Sums> &value)
      {
         self.sums() = value;
      },
      cppCLASS::component_t::documentation("sums").data()
   );

   // get/set productions
   object.def_property(
      "productions",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productions();
      },
      [](cppCLASS &self, const std::optional<general::Productions> &value)
      {
         self.productions() = value;
      },
      cppCLASS::component_t::documentation("productions").data()
   );

   // get/set fissionComponents
   object.def_property(
      "fission_components",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionComponents();
      },
      [](cppCLASS &self, const std::optional<general::FissionComponents> &value)
      {
         self.fissionComponents() = value;
      },
      cppCLASS::component_t::documentation("fission_components").data()
   );

   // get/set orphanProducts
   object.def_property(
      "orphan_products",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.orphanProducts();
      },
      [](cppCLASS &self, const std::optional<general::OrphanProducts> &value)
      {
         self.orphanProducts() = value;
      },
      cppCLASS::component_t::documentation("orphan_products").data()
   );

   // get/set incompleteReactions
   object.def_property(
      "incomplete_reactions",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.incompleteReactions();
      },
      [](cppCLASS &self, const std::optional<general::IncompleteReactions> &value)
      {
         self.incompleteReactions() = value;
      },
      cppCLASS::component_t::documentation("incomplete_reactions").data()
   );

   // shortcut: get/set aliases
   object.def_property(
      "aliases",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.aliases();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.aliases())> &value)
      {
         self.aliases() = value;
      },
      cppCLASS::component_t::documentation("aliases").data()
   );

   // shortcut: get/set baryons
   object.def_property(
      "baryons",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.baryons();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.baryons())> &value)
      {
         self.baryons() = value;
      },
      cppCLASS::component_t::documentation("baryons").data()
   );

   // shortcut: get/set chemicalElements
   object.def_property(
      "chemical_elements",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.chemicalElements();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.chemicalElements())> &value)
      {
         self.chemicalElements() = value;
      },
      cppCLASS::component_t::documentation("chemical_elements").data()
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

   // shortcut: get/set gaugeBosons
   object.def_property(
      "gauge_bosons",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gaugeBosons();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.gaugeBosons())> &value)
      {
         self.gaugeBosons() = value;
      },
      cppCLASS::component_t::documentation("gauge_bosons").data()
   );

   // shortcut: get/set leptons
   object.def_property(
      "leptons",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.leptons();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.leptons())> &value)
      {
         self.leptons() = value;
      },
      cppCLASS::component_t::documentation("leptons").data()
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

   // shortcut: get/set unorthodoxes
   object.def_property(
      "unorthodoxes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unorthodoxes();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.unorthodoxes())> &value)
      {
         self.unorthodoxes() = value;
      },
      cppCLASS::component_t::documentation("unorthodoxes").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_top
} // namespace python_v2_0
