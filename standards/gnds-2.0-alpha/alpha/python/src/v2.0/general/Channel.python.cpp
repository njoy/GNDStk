
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Channel.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Channel wrapper
void wrapChannel(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Channel;

   // create the component
   python::class_<Component> component(
      module, "Channel",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const int &,
            const int &,
            const int &,
            const std::optional<general::ScatteringRadius> &,
            const std::optional<general::HardSphereRadius> &
         >(),
         python::arg("label"),
         python::arg("resonance_reaction"),
         python::arg("l"),
         python::arg("channel_spin"),
         python::arg("column_index"),
         python::arg("scattering_radius") = std::nullopt,
         python::arg("hard_sphere_radius") = std::nullopt,
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
         "resonance_reaction",
         [](const Component &self)
         {
            return self.resonanceReaction();
         },
         Component::component_t::documentation("resonance_reaction").data()
      )
      .def_property_readonly(
         "l",
         [](const Component &self)
         {
            return self.L();
         },
         Component::component_t::documentation("l").data()
      )
      .def_property_readonly(
         "channel_spin",
         [](const Component &self)
         {
            return self.channelSpin();
         },
         Component::component_t::documentation("channel_spin").data()
      )
      .def_property_readonly(
         "column_index",
         [](const Component &self)
         {
            return self.columnIndex();
         },
         Component::component_t::documentation("column_index").data()
      )
      .def_property_readonly(
         "scattering_radius",
         [](const Component &self)
         {
            return self.scatteringRadius();
         },
         Component::component_t::documentation("scattering_radius").data()
      )
      .def_property_readonly(
         "hard_sphere_radius",
         [](const Component &self)
         {
            return self.hardSphereRadius();
         },
         Component::component_t::documentation("hard_sphere_radius").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
