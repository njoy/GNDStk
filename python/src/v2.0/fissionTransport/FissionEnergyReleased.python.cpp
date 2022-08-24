
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fissionTransport/FissionEnergyReleased.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// FissionEnergyReleased wrapper
void wrapFissionEnergyReleased(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fissionTransport::FissionEnergyReleased;

   // create the component
   python::class_<Component> component(
      module,
      "FissionEnergyReleased",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
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
         python::arg("label") = std::nullopt,
         python::arg("delayed_beta_energy") = std::nullopt,
         python::arg("delayed_gamma_energy") = std::nullopt,
         python::arg("delayed_neutron_ke") = std::nullopt,
         python::arg("neutrino_energy") = std::nullopt,
         python::arg("non_neutrino_energy") = std::nullopt,
         python::arg("prompt_gamma_energy") = std::nullopt,
         python::arg("prompt_neutron_ke") = std::nullopt,
         python::arg("prompt_product_ke") = std::nullopt,
         python::arg("total_energy") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "delayed_beta_energy",
         python::overload_cast<>(&Component::delayedBetaEnergy),
         Component::documentation("delayed_beta_energy").data()
      )
      .def_property_readonly(
         "delayed_gamma_energy",
         python::overload_cast<>(&Component::delayedGammaEnergy),
         Component::documentation("delayed_gamma_energy").data()
      )
      .def_property_readonly(
         "delayed_neutron_ke",
         python::overload_cast<>(&Component::delayedNeutronKE),
         Component::documentation("delayed_neutron_ke").data()
      )
      .def_property_readonly(
         "neutrino_energy",
         python::overload_cast<>(&Component::neutrinoEnergy),
         Component::documentation("neutrino_energy").data()
      )
      .def_property_readonly(
         "non_neutrino_energy",
         python::overload_cast<>(&Component::nonNeutrinoEnergy),
         Component::documentation("non_neutrino_energy").data()
      )
      .def_property_readonly(
         "prompt_gamma_energy",
         python::overload_cast<>(&Component::promptGammaEnergy),
         Component::documentation("prompt_gamma_energy").data()
      )
      .def_property_readonly(
         "prompt_neutron_ke",
         python::overload_cast<>(&Component::promptNeutronKE),
         Component::documentation("prompt_neutron_ke").data()
      )
      .def_property_readonly(
         "prompt_product_ke",
         python::overload_cast<>(&Component::promptProductKE),
         Component::documentation("prompt_product_ke").data()
      )
      .def_property_readonly(
         "total_energy",
         python::overload_cast<>(&Component::totalEnergy),
         Component::documentation("total_energy").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0