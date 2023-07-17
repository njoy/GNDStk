
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/FissionEnergyReleased.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// wrapper for fissionTransport::FissionEnergyReleased
void wrapFissionEnergyReleased(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fissionTransport::FissionEnergyReleased;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "FissionEnergyReleased",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const std::optional<fissionTransport::DelayedBetaEnergy> &,
         const std::optional<fissionTransport::DelayedGammaEnergy> &,
         const std::optional<fissionTransport::DelayedNeutronKE> &,
         const std::optional<fissionTransport::NeutrinoEnergy> &,
         const std::optional<fissionTransport::NonNeutrinoEnergy> &,
         const std::optional<fissionTransport::PromptGammaEnergy> &,
         const std::optional<fissionTransport::PromptNeutronKE> &,
         const std::optional<fissionTransport::PromptProductKE> &,
         const std::optional<fissionTransport::TotalEnergy> &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("delayed_beta_energy") = std::nullopt,
      py::arg("delayed_gamma_energy") = std::nullopt,
      py::arg("delayed_neutron_ke") = std::nullopt,
      py::arg("neutrino_energy") = std::nullopt,
      py::arg("non_neutrino_energy") = std::nullopt,
      py::arg("prompt_gamma_energy") = std::nullopt,
      py::arg("prompt_neutron_ke") = std::nullopt,
      py::arg("prompt_product_ke") = std::nullopt,
      py::arg("total_energy") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set delayedBetaEnergy
   object.def_property(
      "delayed_beta_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedBetaEnergy();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::DelayedBetaEnergy> &value)
      {
         self.delayedBetaEnergy() = value;
      },
      cppCLASS::component_t::documentation("delayed_beta_energy").data()
   );

   // get/set delayedGammaEnergy
   object.def_property(
      "delayed_gamma_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedGammaEnergy();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::DelayedGammaEnergy> &value)
      {
         self.delayedGammaEnergy() = value;
      },
      cppCLASS::component_t::documentation("delayed_gamma_energy").data()
   );

   // get/set delayedNeutronKE
   object.def_property(
      "delayed_neutron_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedNeutronKE();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::DelayedNeutronKE> &value)
      {
         self.delayedNeutronKE() = value;
      },
      cppCLASS::component_t::documentation("delayed_neutron_ke").data()
   );

   // get/set neutrinoEnergy
   object.def_property(
      "neutrino_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.neutrinoEnergy();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::NeutrinoEnergy> &value)
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
      [](cppCLASS &self, const std::optional<fissionTransport::NonNeutrinoEnergy> &value)
      {
         self.nonNeutrinoEnergy() = value;
      },
      cppCLASS::component_t::documentation("non_neutrino_energy").data()
   );

   // get/set promptGammaEnergy
   object.def_property(
      "prompt_gamma_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptGammaEnergy();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::PromptGammaEnergy> &value)
      {
         self.promptGammaEnergy() = value;
      },
      cppCLASS::component_t::documentation("prompt_gamma_energy").data()
   );

   // get/set promptNeutronKE
   object.def_property(
      "prompt_neutron_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptNeutronKE();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::PromptNeutronKE> &value)
      {
         self.promptNeutronKE() = value;
      },
      cppCLASS::component_t::documentation("prompt_neutron_ke").data()
   );

   // get/set promptProductKE
   object.def_property(
      "prompt_product_ke",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.promptProductKE();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::PromptProductKE> &value)
      {
         self.promptProductKE() = value;
      },
      cppCLASS::component_t::documentation("prompt_product_ke").data()
   );

   // get/set totalEnergy
   object.def_property(
      "total_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.totalEnergy();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::TotalEnergy> &value)
      {
         self.totalEnergy() = value;
      },
      cppCLASS::component_t::documentation("total_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fissionTransport
} // namespace python_v2_0
