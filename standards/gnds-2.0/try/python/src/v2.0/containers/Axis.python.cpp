
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/containers/Axis.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Axis wrapper
void wrapAxis(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = containers::Axis;

   // create the component
   python::class_<Component> component(
      module,
      "Axis",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const XMLName &,
            const std::optional<XMLName> &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("label"),
         python::arg("unit") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         [](const Component &self) { return self.index(); },
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "unit",
         [](const Component &self) { return self.unit(); },
         Component::documentation("unit").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
