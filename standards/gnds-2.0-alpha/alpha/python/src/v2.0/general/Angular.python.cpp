
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Angular.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Angular wrapper
void wrapAngular(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Angular;

   // create the component
   python::class_<Component> component(
      module,
      "Angular",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<general::Isotropic2d> &,
            const std::optional<general::XYs2d> &
         >(),
         python::arg("isotropic2d") = std::nullopt,
         python::arg("xys2d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "isotropic2d",
         [](const Component &self) { return self.isotropic2d(); },
         Component::documentation("isotropic2d").data()
      )
      .def_property_readonly(
         "xys2d",
         [](const Component &self) { return self.XYs2d(); },
         Component::documentation("xys2d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
