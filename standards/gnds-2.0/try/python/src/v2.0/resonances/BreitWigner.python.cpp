
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/resonances/BreitWigner.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// BreitWigner wrapper
void wrapBreitWigner(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = resonances::BreitWigner;

   // create the component
   python::class_<Component> component(
      module,
      "BreitWigner",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const std::optional<bool> &,
            const std::optional<bool> &,
            const std::optional<unknownNamespace::PoPs> &,
            const std::optional<resonances::ScatteringRadius> &,
            const std::optional<resonances::HardSphereRadius> &,
            const std::optional<resonances::ResonanceParameters> &
         >(),
         python::arg("label"),
         python::arg("approximation"),
         python::arg("calculate_channel_radius") = std::nullopt,
         python::arg("use_for_self_shielding_only") = std::nullopt,
         python::arg("po_ps") = std::nullopt,
         python::arg("scattering_radius") = std::nullopt,
         python::arg("hard_sphere_radius") = std::nullopt,
         python::arg("resonance_parameters") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "approximation",
         [](const Component &self) { return self.approximation(); },
         Component::documentation("approximation").data()
      )
      .def_property_readonly(
         "calculate_channel_radius",
         [](const Component &self) { return self.calculateChannelRadius().value(); },
         Component::documentation("calculate_channel_radius").data()
      )
      .def_property_readonly(
         "use_for_self_shielding_only",
         [](const Component &self) { return self.useForSelfShieldingOnly().value(); },
         Component::documentation("use_for_self_shielding_only").data()
      )
      .def_property_readonly(
         "po_ps",
         [](const Component &self) { return self.PoPs(); },
         Component::documentation("po_ps").data()
      )
      .def_property_readonly(
         "scattering_radius",
         [](const Component &self) { return self.scatteringRadius(); },
         Component::documentation("scattering_radius").data()
      )
      .def_property_readonly(
         "hard_sphere_radius",
         [](const Component &self) { return self.hardSphereRadius(); },
         Component::documentation("hard_sphere_radius").data()
      )
      .def_property_readonly(
         "resonance_parameters",
         [](const Component &self) { return self.resonanceParameters(); },
         Component::documentation("resonance_parameters").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0