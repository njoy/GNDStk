
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/resonances/Resolved.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// Resolved wrapper
void wrapResolved(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = resonances::Resolved;
   using _t = std::variant<
      resonances::RMatrix,
      resonances::BreitWigner,
      resonances::EnergyIntervals
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Resolved",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Float64 &,
            const Float64 &,
            const XMLName &,
            const _t &
         >(),
         python::arg("domain_min"),
         python::arg("domain_max"),
         python::arg("domain_unit"),
         python::arg("_rmatrix_breit_wignerenergy_intervals"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self) { return self.domainMin(); },
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self) { return self.domainMax(); },
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_unit",
         [](const Component &self) { return self.domainUnit(); },
         Component::documentation("domain_unit").data()
      )
      .def_property_readonly(
         "rmatrix",
         [](const Component &self) { return self.RMatrix(); },
         Component::documentation("rmatrix").data()
      )
      .def_property_readonly(
         "breit_wigner",
         [](const Component &self) { return self.BreitWigner(); },
         Component::documentation("breit_wigner").data()
      )
      .def_property_readonly(
         "energy_intervals",
         [](const Component &self) { return self.energyIntervals(); },
         Component::documentation("energy_intervals").data()
      )
      .def_property_readonly(
         "_rmatrix_breit_wignerenergy_intervals",
         [](const Component &self) { return self._RMatrixBreitWignerenergyIntervals(); },
         Component::documentation("_rmatrix_breit_wignerenergy_intervals").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0
