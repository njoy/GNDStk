
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Distribution.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Distribution
void wrapDistribution(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Distribution;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Distribution",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::ThermalNeutronScatteringLaw> &,
         const std::optional<general::Uncorrelated> &,
         const std::optional<general::Unspecified> &,
         const std::optional<general::Branching3d> &,
         const std::optional<general::AngularTwoBody> &,
         const std::optional<general::EnergyAngular> &,
         const std::optional<general::KalbachMann> &,
         const std::optional<general::AngularEnergy> &,
         const std::optional<general::CoulombPlusNuclearElastic> &,
         const std::optional<general::CoherentPhotonScattering> &,
         const std::optional<general::IncoherentPhotonScattering> &
      >(),
      py::arg("thermal_neutron_scattering_law") = std::nullopt,
      py::arg("uncorrelated") = std::nullopt,
      py::arg("unspecified") = std::nullopt,
      py::arg("branching3d") = std::nullopt,
      py::arg("angular_two_body") = std::nullopt,
      py::arg("energy_angular") = std::nullopt,
      py::arg("kalbach_mann") = std::nullopt,
      py::arg("angular_energy") = std::nullopt,
      py::arg("coulomb_plus_nuclear_elastic") = std::nullopt,
      py::arg("coherent_photon_scattering") = std::nullopt,
      py::arg("incoherent_photon_scattering") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set thermalNeutronScatteringLaw
   object.def_property(
      "thermal_neutron_scattering_law",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw();
      },
      [](cppCLASS &self, const std::optional<general::ThermalNeutronScatteringLaw> &value)
      {
         self.thermalNeutronScatteringLaw() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law").data()
   );

   // get/set uncorrelated
   object.def_property(
      "uncorrelated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncorrelated();
      },
      [](cppCLASS &self, const std::optional<general::Uncorrelated> &value)
      {
         self.uncorrelated() = value;
      },
      cppCLASS::component_t::documentation("uncorrelated").data()
   );

   // get/set unspecified
   object.def_property(
      "unspecified",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unspecified();
      },
      [](cppCLASS &self, const std::optional<general::Unspecified> &value)
      {
         self.unspecified() = value;
      },
      cppCLASS::component_t::documentation("unspecified").data()
   );

   // get/set branching3d
   object.def_property(
      "branching3d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.branching3d();
      },
      [](cppCLASS &self, const std::optional<general::Branching3d> &value)
      {
         self.branching3d() = value;
      },
      cppCLASS::component_t::documentation("branching3d").data()
   );

   // get/set angularTwoBody
   object.def_property(
      "angular_two_body",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.angularTwoBody();
      },
      [](cppCLASS &self, const std::optional<general::AngularTwoBody> &value)
      {
         self.angularTwoBody() = value;
      },
      cppCLASS::component_t::documentation("angular_two_body").data()
   );

   // get/set energyAngular
   object.def_property(
      "energy_angular",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.energyAngular();
      },
      [](cppCLASS &self, const std::optional<general::EnergyAngular> &value)
      {
         self.energyAngular() = value;
      },
      cppCLASS::component_t::documentation("energy_angular").data()
   );

   // get/set KalbachMann
   object.def_property(
      "kalbach_mann",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.KalbachMann();
      },
      [](cppCLASS &self, const std::optional<general::KalbachMann> &value)
      {
         self.KalbachMann() = value;
      },
      cppCLASS::component_t::documentation("kalbach_mann").data()
   );

   // get/set angularEnergy
   object.def_property(
      "angular_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.angularEnergy();
      },
      [](cppCLASS &self, const std::optional<general::AngularEnergy> &value)
      {
         self.angularEnergy() = value;
      },
      cppCLASS::component_t::documentation("angular_energy").data()
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

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0