
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Grid.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_containers {

// Grid wrapper
void wrapGrid(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = containers::Grid;
   using LINK_VALUES = std::variant<
      containers::Link,
      containers::Values
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Grid",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const std::optional<enums::Interpolation> &,
            const std::optional<XMLName> &,
            const std::optional<enums::GridStyle> &,
            const std::optional<XMLName> &,
            const LINK_VALUES &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("interpolation") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("style") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("link_values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "interpolation",
         [] ( const Component& self ) { return self.interpolation().value(); },
         Component::documentation("interpolation").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "style",
         &Component::style,
         Component::documentation("style").data()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::documentation("unit").data()
      )
      .def_property_readonly(
         "link",
         python::overload_cast<>(&Component::link),
         Component::documentation("link").data()
      )
      .def_property_readonly(
         "values",
         python::overload_cast<>(&Component::values),
         Component::documentation("values").data()
      )
      .def_property_readonly(
         "link_values",
         python::overload_cast<>(&Component::link_values),
         Component::documentation("link_values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
