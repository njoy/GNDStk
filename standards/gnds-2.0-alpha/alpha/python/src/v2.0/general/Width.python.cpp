
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Width.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Width wrapper
void wrapWidth(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Width;

   // create the component
   python::class_<Component> component(
      module, "Width",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const int &,
            const std::optional<general::XYs1d> &,
            const std::optional<general::Constant1d> &,
            const std::optional<general::Regions1d> &
         >(),
         python::arg("label"),
         python::arg("resonance_reaction"),
         python::arg("degrees_of_freedom"),
         python::arg("xys1d") = std::nullopt,
         python::arg("constant1d") = std::nullopt,
         python::arg("regions1d") = std::nullopt,
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
         "degrees_of_freedom",
         [](const Component &self)
         {
            return self.degreesOfFreedom();
         },
         Component::component_t::documentation("degrees_of_freedom").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self)
         {
            return self.XYs1d();
         },
         Component::component_t::documentation("xys1d").data()
      )
      .def_property_readonly(
         "constant1d",
         [](const Component &self)
         {
            return self.constant1d();
         },
         Component::component_t::documentation("constant1d").data()
      )
      .def_property_readonly(
         "regions1d",
         [](const Component &self)
         {
            return self.regions1d();
         },
         Component::component_t::documentation("regions1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
