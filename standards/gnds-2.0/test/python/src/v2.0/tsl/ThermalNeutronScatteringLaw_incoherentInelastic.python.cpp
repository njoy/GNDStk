
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/ThermalNeutronScatteringLaw_incoherentInelastic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// ThermalNeutronScatteringLaw_incoherentInelastic wrapper
void wrapThermalNeutronScatteringLaw_incoherentInelastic(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = tsl::ThermalNeutronScatteringLaw_incoherentInelastic;

   // create the component
   python::class_<Component> component(
      module,
      "ThermalNeutronScatteringLaw_incoherentInelastic",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<XMLName> &,
            const std::optional<enums::Frame> &,
            const std::optional<bool> &,
            const std::optional<bool> &,
            const XMLName &,
            const tsl::ScatteringAtoms &
         >(),
         python::arg("label"),
         python::arg("pid") = std::nullopt,
         python::arg("product_frame") = std::nullopt,
         python::arg("calculated_at_thermal") = std::nullopt,
         python::arg("incoherent_approximation") = std::nullopt,
         python::arg("primary_scatterer"),
         python::arg("scattering_atoms"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self) { return self.pid().value(); },
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "product_frame",
         [](const Component &self) { return self.productFrame().value(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "calculated_at_thermal",
         [](const Component &self) { return self.calculatedAtThermal().value(); },
         Component::documentation("calculated_at_thermal").data()
      )
      .def_property_readonly(
         "incoherent_approximation",
         [](const Component &self) { return self.incoherentApproximation().value(); },
         Component::documentation("incoherent_approximation").data()
      )
      .def_property_readonly(
         "primary_scatterer",
         [](const Component &self) { return self.primaryScatterer(); },
         Component::documentation("primary_scatterer").data()
      )
      .def_property_readonly(
         "scattering_atoms",
         [](const Component &self) { return self.scatteringAtoms(); },
         Component::documentation("scattering_atoms").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0
