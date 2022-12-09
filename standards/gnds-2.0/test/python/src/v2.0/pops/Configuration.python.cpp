
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Configuration.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Configuration wrapper
void wrapConfiguration(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::Configuration;

   // create the component
   python::class_<Component> component(
      module,
      "Configuration",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const Float64 &,
            const pops::BindingEnergy &,
            const std::optional<pops::DecayData> &
         >(),
         python::arg("subshell"),
         python::arg("electron_number"),
         python::arg("binding_energy"),
         python::arg("decay_data") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "subshell",
         [](const Component &self) { return self.subshell(); },
         Component::documentation("subshell").data()
      )
      .def_property_readonly(
         "electron_number",
         [](const Component &self) { return self.electronNumber(); },
         Component::documentation("electron_number").data()
      )
      .def_property_readonly(
         "binding_energy",
         [](const Component &self) { return self.bindingEnergy(); },
         Component::documentation("binding_energy").data()
      )
      .def_property_readonly(
         "decay_data",
         [](const Component &self) { return self.decayData(); },
         Component::documentation("decay_data").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
