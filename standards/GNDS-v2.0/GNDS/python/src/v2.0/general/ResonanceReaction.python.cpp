
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ResonanceReaction.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ResonanceReaction
void wrapResonanceReaction(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ResonanceReaction;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ResonanceReaction",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::optional<std::string> &,
         const std::optional<bool> &,
         const general::Link &,
         const std::optional<general::HardSphereRadius> &,
         const std::optional<general::Q> &,
         const std::optional<general::ScatteringRadius> &
      >(),
      py::arg("label"),
      py::arg("ejectile") = std::nullopt,
      py::arg("eliminated") = std::nullopt,
      py::arg("link"),
      py::arg("hard_sphere_radius") = std::nullopt,
      py::arg("q") = std::nullopt,
      py::arg("scattering_radius") = std::nullopt,
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

   // get/set ejectile
   object.def_property(
      "ejectile",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ejectile();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.ejectile() = value;
      },
      cppCLASS::component_t::documentation("ejectile").data()
   );

   // get/set eliminated
   object.def_property(
      "eliminated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.eliminated();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.eliminated() = value;
      },
      cppCLASS::component_t::documentation("eliminated").data()
   );

   // get/set link
   object.def_property(
      "link",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.link();
      },
      [](cppCLASS &self, const general::Link &value)
      {
         self.link() = value;
      },
      cppCLASS::component_t::documentation("link").data()
   );

   // get/set hardSphereRadius
   object.def_property(
      "hard_sphere_radius",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.hardSphereRadius();
      },
      [](cppCLASS &self, const std::optional<general::HardSphereRadius> &value)
      {
         self.hardSphereRadius() = value;
      },
      cppCLASS::component_t::documentation("hard_sphere_radius").data()
   );

   // get/set Q
   object.def_property(
      "q",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Q();
      },
      [](cppCLASS &self, const std::optional<general::Q> &value)
      {
         self.Q() = value;
      },
      cppCLASS::component_t::documentation("q").data()
   );

   // get/set scatteringRadius
   object.def_property(
      "scattering_radius",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.scatteringRadius();
      },
      [](cppCLASS &self, const std::optional<general::ScatteringRadius> &value)
      {
         self.scatteringRadius() = value;
      },
      cppCLASS::component_t::documentation("scattering_radius").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0