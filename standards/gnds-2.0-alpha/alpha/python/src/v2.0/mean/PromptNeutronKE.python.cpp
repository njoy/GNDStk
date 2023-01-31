
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/PromptNeutronKE.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// PromptNeutronKE wrapper
void wrapPromptNeutronKE(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::PromptNeutronKE;

   // create the component
   python::class_<Component> component(
      module,
      "PromptNeutronKE",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<common::Polynomial1d> &,
            const std::optional<common::XYs1d> &
         >(),
         python::arg("polynomial1d") = std::nullopt,
         python::arg("xys1d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "polynomial1d",
         [](const Component &self) { return self.polynomial1d(); },
         Component::documentation("polynomial1d").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
