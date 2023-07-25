
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/FissionEnergyRelease.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::FissionEnergyRelease
void wrapFissionEnergyRelease(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::FissionEnergyRelease;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "FissionEnergyRelease",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const general::PromptProductKE &,
         const general::PromptNeutronKE &,
         const general::DelayedNeutronKE &,
         const general::PromptGammaEnergy &,
         const general::DelayedGammaEnergy &,
         const general::DelayedBetaEnergy &,
         const general::NeutrinoEnergy &,
         const general::NonNeutrinoEnergy &,
         const general::TotalEnergy &
      >(),
      py::arg("label"),
      py::arg("prompt_product_ke"),
      py::arg("prompt_neutron_ke"),
      py::arg("delayed_neutron_ke"),
      py::arg("prompt_gamma_energy"),
      py::arg("delayed_gamma_energy"),
      py::arg("delayed_beta_energy"),
      py::arg("neutrino_energy"),
      py::arg("non_neutrino_energy"),
      py::arg("total_energy"),
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

   // get/set promptProductKE
   object.def_property(
      "prompt_product_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptProductKE();
      },
      [](cppCLASS &self, const general::PromptProductKE &value)
      {
         self.promptProductKE() = value;
      },
      cppCLASS::component_t::documentation("prompt_product_ke").data()
   );

   // get/set promptNeutronKE
   object.def_property(
      "prompt_neutron_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptNeutronKE();
      },
      [](cppCLASS &self, const general::PromptNeutronKE &value)
      {
         self.promptNeutronKE() = value;
      },
      cppCLASS::component_t::documentation("prompt_neutron_ke").data()
   );

   // get/set delayedNeutronKE
   object.def_property(
      "delayed_neutron_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedNeutronKE();
      },
      [](cppCLASS &self, const general::DelayedNeutronKE &value)
      {
         self.delayedNeutronKE() = value;
      },
      cppCLASS::component_t::documentation("delayed_neutron_ke").data()
   );

   // get/set promptGammaEnergy
   object.def_property(
      "prompt_gamma_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptGammaEnergy();
      },
      [](cppCLASS &self, const general::PromptGammaEnergy &value)
      {
         self.promptGammaEnergy() = value;
      },
      cppCLASS::component_t::documentation("prompt_gamma_energy").data()
   );

   // get/set delayedGammaEnergy
   object.def_property(
      "delayed_gamma_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedGammaEnergy();
      },
      [](cppCLASS &self, const general::DelayedGammaEnergy &value)
      {
         self.delayedGammaEnergy() = value;
      },
      cppCLASS::component_t::documentation("delayed_gamma_energy").data()
   );

   // get/set delayedBetaEnergy
   object.def_property(
      "delayed_beta_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedBetaEnergy();
      },
      [](cppCLASS &self, const general::DelayedBetaEnergy &value)
      {
         self.delayedBetaEnergy() = value;
      },
      cppCLASS::component_t::documentation("delayed_beta_energy").data()
   );

   // get/set neutrinoEnergy
   object.def_property(
      "neutrino_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.neutrinoEnergy();
      },
      [](cppCLASS &self, const general::NeutrinoEnergy &value)
      {
         self.neutrinoEnergy() = value;
      },
      cppCLASS::component_t::documentation("neutrino_energy").data()
   );

   // get/set nonNeutrinoEnergy
   object.def_property(
      "non_neutrino_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nonNeutrinoEnergy();
      },
      [](cppCLASS &self, const general::NonNeutrinoEnergy &value)
      {
         self.nonNeutrinoEnergy() = value;
      },
      cppCLASS::component_t::documentation("non_neutrino_energy").data()
   );

   // get/set totalEnergy
   object.def_property(
      "total_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.totalEnergy();
      },
      [](cppCLASS &self, const general::TotalEnergy &value)
      {
         self.totalEnergy() = value;
      },
      cppCLASS::component_t::documentation("total_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
