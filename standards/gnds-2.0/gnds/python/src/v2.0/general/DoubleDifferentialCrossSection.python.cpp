
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/DoubleDifferentialCrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::DoubleDifferentialCrossSection
void wrapDoubleDifferentialCrossSection(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::DoubleDifferentialCrossSection;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "DoubleDifferentialCrossSection",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::CoulombPlusNuclearElastic> &,
         const std::optional<general::CoherentPhotonScattering> &,
         const std::optional<general::IncoherentPhotonScattering> &,
         const std::optional<general::ThermalNeutronScatteringLaw_coherentElastic> &,
         const std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic> &,
         const std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic> &
      >(),
      py::arg("coulomb_plus_nuclear_elastic") = std::nullopt,
      py::arg("coherent_photon_scattering") = std::nullopt,
      py::arg("incoherent_photon_scattering") = std::nullopt,
      py::arg("thermal_neutron_scattering_law_coherent_elastic") = std::nullopt,
      py::arg("thermal_neutron_scattering_law_incoherent_elastic") = std::nullopt,
      py::arg("thermal_neutron_scattering_law_incoherent_inelastic") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set CoulombPlusNuclearElastic
   object.def_property(
      "coulomb_plus_nuclear_elastic",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.CoulombPlusNuclearElastic();
      },
      [](cppCLASS &self, const std::optional<general::CoulombPlusNuclearElastic> &value)
      {
         self.CoulombPlusNuclearElastic() = value;
      },
      cppCLASS::component_t::documentation("coulomb_plus_nuclear_elastic").data()
   );

   // get/set coherentPhotonScattering
   object.def_property(
      "coherent_photon_scattering",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.coherentPhotonScattering();
      },
      [](cppCLASS &self, const std::optional<general::CoherentPhotonScattering> &value)
      {
         self.coherentPhotonScattering() = value;
      },
      cppCLASS::component_t::documentation("coherent_photon_scattering").data()
   );

   // get/set incoherentPhotonScattering
   object.def_property(
      "incoherent_photon_scattering",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.incoherentPhotonScattering();
      },
      [](cppCLASS &self, const std::optional<general::IncoherentPhotonScattering> &value)
      {
         self.incoherentPhotonScattering() = value;
      },
      cppCLASS::component_t::documentation("incoherent_photon_scattering").data()
   );

   // get/set thermalNeutronScatteringLaw_coherentElastic
   object.def_property(
      "thermal_neutron_scattering_law_coherent_elastic",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw_coherentElastic();
      },
      [](cppCLASS &self, const std::optional<general::ThermalNeutronScatteringLaw_coherentElastic> &value)
      {
         self.thermalNeutronScatteringLaw_coherentElastic() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law_coherent_elastic").data()
   );

   // get/set thermalNeutronScatteringLaw_incoherentElastic
   object.def_property(
      "thermal_neutron_scattering_law_incoherent_elastic",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw_incoherentElastic();
      },
      [](cppCLASS &self, const std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic> &value)
      {
         self.thermalNeutronScatteringLaw_incoherentElastic() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law_incoherent_elastic").data()
   );

   // get/set thermalNeutronScatteringLaw_incoherentInelastic
   object.def_property(
      "thermal_neutron_scattering_law_incoherent_inelastic",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw_incoherentInelastic();
      },
      [](cppCLASS &self, const std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic> &value)
      {
         self.thermalNeutronScatteringLaw_incoherentInelastic() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law_incoherent_inelastic").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
