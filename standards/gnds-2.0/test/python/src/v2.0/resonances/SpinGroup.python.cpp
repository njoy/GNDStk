
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/resonances/SpinGroup.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// SpinGroup wrapper
void wrapSpinGroup(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = resonances::SpinGroup;

   // create the component
   python::class_<Component> component(
      module,
      "SpinGroup",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const Fraction32 &,
            const std::optional<Integer32> &,
            const resonances::Channels &,
            const resonances::ResonanceParameters &
         >(),
         python::arg("label"),
         python::arg("spin"),
         python::arg("parity") = std::nullopt,
         python::arg("channels"),
         python::arg("resonance_parameters"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "spin",
         [](const Component &self) { return self.spin(); },
         Component::documentation("spin").data()
      )
      .def_property_readonly(
         "parity",
         [](const Component &self) { return self.parity().value(); },
         Component::documentation("parity").data()
      )
      .def_property_readonly(
         "channels",
         [](const Component &self) { return self.channels(); },
         Component::documentation("channels").data()
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
