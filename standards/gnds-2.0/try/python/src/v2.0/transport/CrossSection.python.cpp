
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/CrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// CrossSection wrapper
void wrapCrossSection(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::CrossSection;
   using _t = std::variant<
      containers::XYs1d,
      containers::Regions1d,
      transport::ResonancesWithBackground,
      cpTransport::CoulombPlusNuclearElastic,
      tsl::ThermalNeutronScatteringLaw1d,
      transport::Reference,
      containers::Gridded1d,
      containers::Ys1d,
      transport::URR_probabilityTables1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "CrossSection",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const _t &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("_xys1dregions1dresonances_with_background_coulomb_plus_nuclear_elasticthermal_neutron_scattering_law1dreferencegridded1d_ys1d_urr_probability_tables1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
      .def_property_readonly(
         "regions1d",
         [](const Component &self) { return self.regions1d(); },
         Component::documentation("regions1d").data()
      )
      .def_property_readonly(
         "resonances_with_background",
         [](const Component &self) { return self.resonancesWithBackground(); },
         Component::documentation("resonances_with_background").data()
      )
      .def_property_readonly(
         "coulomb_plus_nuclear_elastic",
         [](const Component &self) { return self.CoulombPlusNuclearElastic(); },
         Component::documentation("coulomb_plus_nuclear_elastic").data()
      )
      .def_property_readonly(
         "thermal_neutron_scattering_law1d",
         [](const Component &self) { return self.thermalNeutronScatteringLaw1d(); },
         Component::documentation("thermal_neutron_scattering_law1d").data()
      )
      .def_property_readonly(
         "reference",
         [](const Component &self) { return self.reference(); },
         Component::documentation("reference").data()
      )
      .def_property_readonly(
         "gridded1d",
         [](const Component &self) { return self.gridded1d(); },
         Component::documentation("gridded1d").data()
      )
      .def_property_readonly(
         "ys1d",
         [](const Component &self) { return self.Ys1d(); },
         Component::documentation("ys1d").data()
      )
      .def_property_readonly(
         "urr_probability_tables1d",
         [](const Component &self) { return self.URR_probabilityTables1d(); },
         Component::documentation("urr_probability_tables1d").data()
      )
      .def_property_readonly(
         "_xys1dregions1dresonances_with_background_coulomb_plus_nuclear_elasticthermal_neutron_scattering_law1dreferencegridded1d_ys1d_urr_probability_tables1d",
         [](const Component &self) { return self._XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d(); },
         Component::documentation("_xys1dregions1dresonances_with_background_coulomb_plus_nuclear_elasticthermal_neutron_scattering_law1dreferencegridded1d_ys1d_urr_probability_tables1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
