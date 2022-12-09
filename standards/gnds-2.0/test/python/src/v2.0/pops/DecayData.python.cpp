
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/DecayData.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// DecayData wrapper
void wrapDecayData(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::DecayData;

   // create the component
   python::class_<Component> component(
      module,
      "DecayData",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<pops::DecayModes> &,
            const std::optional<pops::AverageEnergies> &
         >(),
         python::arg("decay_modes") = std::nullopt,
         python::arg("average_energies") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "decay_modes",
         [](const Component &self) { return self.decayModes(); },
         Component::documentation("decay_modes").data()
      )
      .def_property_readonly(
         "average_energies",
         [](const Component &self) { return self.averageEnergies(); },
         Component::documentation("average_energies").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
