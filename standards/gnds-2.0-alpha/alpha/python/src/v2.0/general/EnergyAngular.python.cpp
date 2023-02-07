
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/EnergyAngular.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// EnergyAngular wrapper
void wrapEnergyAngular(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::EnergyAngular;

   // create the component
   python::class_<Component> component(
      module, "EnergyAngular",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::optional<general::XYs3d> &
         >(),
         python::arg("label"),
         python::arg("product_frame"),
         python::arg("xys3d") = std::nullopt,
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
         "product_frame",
         [](const Component &self)
         {
            return self.productFrame();
         },
         Component::component_t::documentation("product_frame").data()
      )
      .def_property_readonly(
         "xys3d",
         [](const Component &self)
         {
            return self.XYs3d();
         },
         Component::component_t::documentation("xys3d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
