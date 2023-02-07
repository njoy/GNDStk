
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/DoubleDifferentialCrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// DoubleDifferentialCrossSection wrapper
void wrapDoubleDifferentialCrossSection(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::DoubleDifferentialCrossSection;

   // create the component
   python::class_<Component> component(
      module, "DoubleDifferentialCrossSection",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<general::CoulombPlusNuclearElastic> &,
            const std::optional<general::CoherentPhotonScattering> &,
            const std::optional<general::IncoherentPhotonScattering> &,
            const std::optional<general::ThermalNeutronScatteringLaw_coherentElastic> &,
            const std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic> &,
            const std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic> &
         >(),
         python::arg("coulomb_plus_nuclear_elastic") = std::nullopt,
         python::arg("coherent_photon_scattering") = std::nullopt,
         python::arg("incoherent_photon_scattering") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_coherent_elastic") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_incoherent_elastic") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_incoherent_inelastic") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "coulomb_plus_nuclear_elastic",
         [](const Component &self)
         {
            return self.CoulombPlusNuclearElastic();
         },
         Component::documentation("coulomb_plus_nuclear_elastic").data()
      )
      .def_property_readonly(
         "coherent_photon_scattering",
         [](const Component &self)
         {
            return self.coherentPhotonScattering();
         },
         Component::documentation("coherent_photon_scattering").data()
      )
      .def_property_readonly(
         "incoherent_photon_scattering",
         [](const Component &self)
         {
            return self.incoherentPhotonScattering();
         },
         Component::documentation("incoherent_photon_scattering").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_coherent_elastic",
         [](const Component &self)
         {
            return self.thermalNeutronScatteringLaw_coherentElastic();
         },
         Component::documentation("thermal_neutron_scattering_law_coherent_elastic").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_incoherent_elastic",
         [](const Component &self)
         {
            return self.thermalNeutronScatteringLaw_incoherentElastic();
         },
         Component::documentation("thermal_neutron_scattering_law_incoherent_elastic").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_incoherent_inelastic",
         [](const Component &self)
         {
            return self.thermalNeutronScatteringLaw_incoherentInelastic();
         },
         Component::documentation("thermal_neutron_scattering_law_incoherent_inelastic").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
