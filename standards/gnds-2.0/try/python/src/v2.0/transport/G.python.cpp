
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/G.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// G wrapper
void wrapG(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::G;

   // create the component
   python::class_<Component> component(
      module,
      "G",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<unknownNamespace::XYs1d> &,
            const std::optional<unknownNamespace::Regions1d> &
         >(),
         python::arg("xys1d") = std::nullopt,
         python::arg("regions1d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
      .def_property_readonly(
         "regions1d",
         [](const Component &self) { return self.regions1d(); },
         Component::documentation("regions1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
