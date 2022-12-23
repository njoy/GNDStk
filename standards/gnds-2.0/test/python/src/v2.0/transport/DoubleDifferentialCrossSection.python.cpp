
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/DoubleDifferentialCrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// DoubleDifferentialCrossSection wrapper
void wrapDoubleDifferentialCrossSection(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::DoubleDifferentialCrossSection;

   // create the component
   python::class_<Component> component(
      module,
      "DoubleDifferentialCrossSection",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<containers::Regions3d> &,
            const std::optional<containers::XYs3d> &,
            const std::optional<cpTransport::CoulombPlusNuclearElastic> &,
            const std::optional<transport::Reference> &,
            const std::optional<atomic::CoherentPhotonScattering> &,
            const std::optional<atomic::IncoherentPhotonScattering> &,
            const std::optional<tsl::ThermalNeutronScatteringLaw_coherentElastic> &,
            const std::optional<tsl::ThermalNeutronScatteringLaw_incoherentElastic> &,
            const std::optional<tsl::ThermalNeutronScatteringLaw_incoherentInelastic> &
         >(),
         python::arg("regions3d") = std::nullopt,
         python::arg("xys3d") = std::nullopt,
         python::arg("coulomb_plus_nuclear_elastic") = std::nullopt,
         python::arg("reference") = std::nullopt,
         python::arg("coherent_photon_scattering") = std::nullopt,
         python::arg("incoherent_photon_scattering") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_coherent_elastic") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_incoherent_elastic") = std::nullopt,
         python::arg("thermal_neutron_scattering_law_incoherent_inelastic") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "regions3d",
         [](const Component &self) { return self.regions3d(); },
         Component::documentation("regions3d").data()
      )
      .def_property_readonly(
         "xys3d",
         [](const Component &self) { return self.XYs3d(); },
         Component::documentation("xys3d").data()
      )
      .def_property_readonly(
         "coulomb_plus_nuclear_elastic",
         [](const Component &self) { return self.CoulombPlusNuclearElastic(); },
         Component::documentation("coulomb_plus_nuclear_elastic").data()
      )
      .def_property_readonly(
         "reference",
         [](const Component &self) { return self.reference(); },
         Component::documentation("reference").data()
      )
      .def_property_readonly(
         "coherent_photon_scattering",
         [](const Component &self) { return self.coherentPhotonScattering(); },
         Component::documentation("coherent_photon_scattering").data()
      )
      .def_property_readonly(
         "incoherent_photon_scattering",
         [](const Component &self) { return self.incoherentPhotonScattering(); },
         Component::documentation("incoherent_photon_scattering").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_coherent_elastic",
         [](const Component &self) { return self.thermalNeutronScatteringLaw_coherentElastic(); },
         Component::documentation("thermal_neutron_scattering_law_coherent_elastic").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_incoherent_elastic",
         [](const Component &self) { return self.thermalNeutronScatteringLaw_incoherentElastic(); },
         Component::documentation("thermal_neutron_scattering_law_incoherent_elastic").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law_incoherent_inelastic",
         [](const Component &self) { return self.thermalNeutronScatteringLaw_incoherentInelastic(); },
         Component::documentation("thermal_neutron_scattering_law_incoherent_inelastic").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
