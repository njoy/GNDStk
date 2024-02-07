
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ResonancesWithBackground.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ResonancesWithBackground
void wrapResonancesWithBackground(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ResonancesWithBackground;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ResonancesWithBackground",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const general::Resonances &,
         const general::Background &,
         const std::optional<general::Uncertainty> &
      >(),
      pybind11::arg("label"),
      pybind11::arg("resonances"),
      pybind11::arg("background"),
      pybind11::arg("uncertainty") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set resonances
   object.def_property(
      "resonances",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonances();
      },
      [](cppCLASS &self, const general::Resonances &value)
      {
         self.resonances() = value;
      },
      cppCLASS::component_t::documentation("resonances").data()
   );

   // get/set background
   object.def_property(
      "background",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.background();
      },
      [](cppCLASS &self, const general::Background &value)
      {
         self.background() = value;
      },
      cppCLASS::component_t::documentation("background").data()
   );

   // get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::optional<general::Uncertainty> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // shortcut: get/set fastRegion
   object.def_property(
      "fast_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fastRegion();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.fastRegion())> &value)
      {
         self.fastRegion() = value;
      },
      cppCLASS::component_t::documentation("fast_region").data()
   );

   // shortcut: get/set resolved
   object.def_property(
      "resolved",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resolved();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.resolved())> &value)
      {
         self.resolved() = value;
      },
      cppCLASS::component_t::documentation("resolved").data()
   );

   // shortcut: get/set resolvedRegion
   object.def_property(
      "resolved_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resolvedRegion();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.resolvedRegion())> &value)
      {
         self.resolvedRegion() = value;
      },
      cppCLASS::component_t::documentation("resolved_region").data()
   );

   // shortcut: get/set scatteringRadius
   object.def_property(
      "scattering_radius",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.scatteringRadius();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.scatteringRadius())> &value)
      {
         self.scatteringRadius() = value;
      },
      cppCLASS::component_t::documentation("scattering_radius").data()
   );

   // shortcut: get/set unresolved
   object.def_property(
      "unresolved",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unresolved();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.unresolved())> &value)
      {
         self.unresolved() = value;
      },
      cppCLASS::component_t::documentation("unresolved").data()
   );

   // shortcut: get/set unresolvedRegion
   object.def_property(
      "unresolved_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unresolvedRegion();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.unresolvedRegion())> &value)
      {
         self.unresolvedRegion() = value;
      },
      cppCLASS::component_t::documentation("unresolved_region").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
