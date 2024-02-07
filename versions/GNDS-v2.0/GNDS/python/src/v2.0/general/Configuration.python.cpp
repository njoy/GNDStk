
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Configuration.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Configuration
void wrapConfiguration(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Configuration;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Configuration",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const double &,
         const general::BindingEnergy &,
         const std::vector<general::DecayData> &
      >(),
      pybind11::arg("subshell"),
      pybind11::arg("electron_number"),
      pybind11::arg("binding_energy"),
      pybind11::arg("decay_data"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set subshell
   object.def_property(
      "subshell",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.subshell();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.subshell() = value;
      },
      cppCLASS::component_t::documentation("subshell").data()
   );

   // get/set electronNumber
   object.def_property(
      "electron_number",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.electronNumber();
      },
      [](cppCLASS &self, const double &value)
      {
         self.electronNumber() = value;
      },
      cppCLASS::component_t::documentation("electron_number").data()
   );

   // get/set bindingEnergy
   object.def_property(
      "binding_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.bindingEnergy();
      },
      [](cppCLASS &self, const general::BindingEnergy &value)
      {
         self.bindingEnergy() = value;
      },
      cppCLASS::component_t::documentation("binding_energy").data()
   );

   // get/set decayData
   object.def_property(
      "decay_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.decayData();
      },
      [](cppCLASS &self, const std::vector<general::DecayData> &value)
      {
         self.decayData() = value;
      },
      cppCLASS::component_t::documentation("decay_data").data()
   );

   // shortcut: get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.Double())> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS