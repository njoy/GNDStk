
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Configuration.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Configuration wrapper
void wrapConfiguration(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

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
            const Float64 &,
            const std::string &,
            const pops::BindingEnergy &,
            const std::optional<pops::DecayData> &
         >(),
         python::arg("electron_number"),
         python::arg("subshell"),
         python::arg("binding_energy"),
         python::arg("decay_data") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "electron_number",
         &Component::electronNumber,
         Component::documentation("electron_number").data()
      )
      .def_property_readonly(
         "subshell",
         &Component::subshell,
         Component::documentation("subshell").data()
      )
      .def_property_readonly(
         "binding_energy",
         python::overload_cast<>(&Component::bindingEnergy),
         Component::documentation("binding_energy").data()
      )
      .def_property_readonly(
         "decay_data",
         python::overload_cast<>(&Component::decayData),
         Component::documentation("decay_data").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0