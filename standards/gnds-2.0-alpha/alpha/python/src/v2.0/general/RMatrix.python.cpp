
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/RMatrix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// RMatrix wrapper
void wrapRMatrix(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::RMatrix;

   // create the component
   python::class_<Component> component(
      module, "RMatrix",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::string &,
            const std::optional<bool> &,
            const std::optional<bool> &,
            const std::optional<top::PoPs> &,
            const general::ResonanceReactions &,
            const general::SpinGroups &
         >(),
         python::arg("label"),
         python::arg("approximation"),
         python::arg("boundary_condition"),
         python::arg("calculate_channel_radius") = std::nullopt,
         python::arg("supports_angular_reconstruction") = std::nullopt,
         python::arg("po_ps") = std::nullopt,
         python::arg("resonance_reactions"),
         python::arg("spin_groups"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::component_t::documentation("label").data()
      )
      .def_property_readonly(
         "approximation",
         [](const Component &self)
         {
            return self.approximation();
         },
         Component::component_t::documentation("approximation").data()
      )
      .def_property_readonly(
         "boundary_condition",
         [](const Component &self)
         {
            return self.boundaryCondition();
         },
         Component::component_t::documentation("boundary_condition").data()
      )
      .def_property_readonly(
         "calculate_channel_radius",
         [](const Component &self)
         {
            return self.calculateChannelRadius();
         },
         Component::component_t::documentation("calculate_channel_radius").data()
      )
      .def_property_readonly(
         "supports_angular_reconstruction",
         [](const Component &self)
         {
            return self.supportsAngularReconstruction();
         },
         Component::component_t::documentation("supports_angular_reconstruction").data()
      )
      .def_property_readonly(
         "po_ps",
         [](const Component &self)
         {
            return self.PoPs();
         },
         Component::component_t::documentation("po_ps").data()
      )
      .def_property_readonly(
         "resonance_reactions",
         [](const Component &self)
         {
            return self.resonanceReactions();
         },
         Component::component_t::documentation("resonance_reactions").data()
      )
      .def_property_readonly(
         "spin_groups",
         [](const Component &self)
         {
            return self.spinGroups();
         },
         Component::component_t::documentation("spin_groups").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
