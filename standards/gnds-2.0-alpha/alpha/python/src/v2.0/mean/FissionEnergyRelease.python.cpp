
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/FissionEnergyRelease.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// FissionEnergyRelease wrapper
void wrapFissionEnergyRelease(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::FissionEnergyRelease;

   // create the component
   python::class_<Component> component(
      module,
      "FissionEnergyRelease",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const mean::PromptProductKE &,
            const mean::PromptNeutronKE &,
            const mean::DelayedNeutronKE &,
            const mean::PromptGammaEnergy &,
            const mean::DelayedGammaEnergy &,
            const mean::DelayedBetaEnergy &,
            const mean::NeutrinoEnergy &,
            const mean::NonNeutrinoEnergy &,
            const mean::TotalEnergy &
         >(),
         python::arg("label"),
         python::arg("prompt_product_ke"),
         python::arg("prompt_neutron_ke"),
         python::arg("delayed_neutron_ke"),
         python::arg("prompt_gamma_energy"),
         python::arg("delayed_gamma_energy"),
         python::arg("delayed_beta_energy"),
         python::arg("neutrino_energy"),
         python::arg("non_neutrino_energy"),
         python::arg("total_energy"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "prompt_product_ke",
         [](const Component &self) { return self.promptProductKE(); },
         Component::documentation("prompt_product_ke").data()
      )
      .def_property_readonly(
         "prompt_neutron_ke",
         [](const Component &self) { return self.promptNeutronKE(); },
         Component::documentation("prompt_neutron_ke").data()
      )
      .def_property_readonly(
         "delayed_neutron_ke",
         [](const Component &self) { return self.delayedNeutronKE(); },
         Component::documentation("delayed_neutron_ke").data()
      )
      .def_property_readonly(
         "prompt_gamma_energy",
         [](const Component &self) { return self.promptGammaEnergy(); },
         Component::documentation("prompt_gamma_energy").data()
      )
      .def_property_readonly(
         "delayed_gamma_energy",
         [](const Component &self) { return self.delayedGammaEnergy(); },
         Component::documentation("delayed_gamma_energy").data()
      )
      .def_property_readonly(
         "delayed_beta_energy",
         [](const Component &self) { return self.delayedBetaEnergy(); },
         Component::documentation("delayed_beta_energy").data()
      )
      .def_property_readonly(
         "neutrino_energy",
         [](const Component &self) { return self.neutrinoEnergy(); },
         Component::documentation("neutrino_energy").data()
      )
      .def_property_readonly(
         "non_neutrino_energy",
         [](const Component &self) { return self.nonNeutrinoEnergy(); },
         Component::documentation("non_neutrino_energy").data()
      )
      .def_property_readonly(
         "total_energy",
         [](const Component &self) { return self.totalEnergy(); },
         Component::documentation("total_energy").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
