
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/Angular_uncorrelated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// Angular_uncorrelated wrapper
void wrapAngular_uncorrelated(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::Angular_uncorrelated;

   // create the component
   python::class_<Component> component(
      module,
      "Angular_uncorrelated",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<unknownNamespace::XYs2d> &,
            const std::optional<transport::Isotropic2d> &,
            const std::optional<transport::Forward> &
         >(),
         python::arg("xys2d") = std::nullopt,
         python::arg("isotropic2d") = std::nullopt,
         python::arg("forward") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys2d",
         [](const Component &self) { return self.XYs2d(); },
         Component::documentation("xys2d").data()
      )
      .def_property_readonly(
         "isotropic2d",
         [](const Component &self) { return self.isotropic2d(); },
         Component::documentation("isotropic2d").data()
      )
      .def_property_readonly(
         "forward",
         [](const Component &self) { return self.forward(); },
         Component::documentation("forward").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
