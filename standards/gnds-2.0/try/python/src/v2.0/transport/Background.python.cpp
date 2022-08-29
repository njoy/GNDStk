
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/Background.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// Background wrapper
void wrapBackground(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::Background;

   // create the component
   python::class_<Component> component(
      module,
      "Background",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<transport::ResolvedRegion> &,
            const std::optional<transport::UnresolvedRegion> &,
            const std::optional<transport::FastRegion> &
         >(),
         python::arg("resolved_region") = std::nullopt,
         python::arg("unresolved_region") = std::nullopt,
         python::arg("fast_region") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "resolved_region",
         [](const Component &self) { return self.resolvedRegion(); },
         Component::documentation("resolved_region").data()
      )
      .def_property_readonly(
         "unresolved_region",
         [](const Component &self) { return self.unresolvedRegion(); },
         Component::documentation("unresolved_region").data()
      )
      .def_property_readonly(
         "fast_region",
         [](const Component &self) { return self.fastRegion(); },
         Component::documentation("fast_region").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
