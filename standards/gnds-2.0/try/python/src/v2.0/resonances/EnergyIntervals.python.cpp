
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/resonances/EnergyIntervals.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// EnergyIntervals wrapper
void wrapEnergyIntervals(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = resonances::EnergyIntervals;

   // create the component
   python::class_<Component> component(
      module,
      "EnergyIntervals",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::vector<resonances::EnergyInterval> &
         >(),
         python::arg("label"),
         python::arg("energy_interval"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "energy_interval",
         [](const Component &self) { return self.energyInterval(); },
         Component::documentation("energy_interval").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0