
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/BreitWigner.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// BreitWigner wrapper
void wrapBreitWigner(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::BreitWigner;

   // create the component
   python::class_<Component> component(
      module, "BreitWigner",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::optional<bool> &,
            const general::ResonanceParameters &,
            const std::optional<top::PoPs> &,
            const std::optional<general::ScatteringRadius> &
         >(),
         python::arg("label"),
         python::arg("approximation"),
         python::arg("calculate_channel_radius") = std::nullopt,
         python::arg("resonance_parameters"),
         python::arg("po_ps") = std::nullopt,
         python::arg("scattering_radius") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "approximation",
         [](const Component &self)
         {
            return self.approximation();
         },
         Component::documentation("approximation").data()
      )
      .def_property_readonly(
         "calculate_channel_radius",
         [](const Component &self)
         {
            return self.calculateChannelRadius();
         },
         Component::documentation("calculate_channel_radius").data()
      )
      .def_property_readonly(
         "resonance_parameters",
         [](const Component &self)
         {
            return self.resonanceParameters();
         },
         Component::documentation("resonance_parameters").data()
      )
      .def_property_readonly(
         "po_ps",
         [](const Component &self)
         {
            return self.PoPs();
         },
         Component::documentation("po_ps").data()
      )
      .def_property_readonly(
         "scattering_radius",
         [](const Component &self)
         {
            return self.scatteringRadius();
         },
         Component::documentation("scattering_radius").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
