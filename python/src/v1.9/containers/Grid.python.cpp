
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

namespace v1_9 {
namespace containers {

// Grid wrapper
void wrapGrid(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Grid;

   // create the component
   python::class_<Component> component(
      module,
      "Grid",
      Component::help().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const enums::Interpolation &,
            const std::optional<XMLName> &,
            const std::optional<UTF8Text> &,
            const std::optional<XMLName> &,
            const std::optional<containers::Link> &,
            const std::optional<containers::Values> &,
            const VARIANT &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("interpolation") = enums::Interpolation::linlin,
         python::arg("label") = std::nullopt,
         python::arg("style") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("link") = std::nullopt,
         python::arg("values") = std::nullopt,
         python::arg("choice"),
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::help("index").c_str()
      )
      .def_property_readonly(
         "interpolation",
         &Component::interpolation,
         Component::help("interpolation").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label").c_str()
      )
      .def_property_readonly(
         "style",
         &Component::style,
         Component::help("style").c_str()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::help("unit").c_str()
      )
      .def_property_readonly(
         "link",
         &Component::link,
         Component::help("link").c_str()
      )
      .def_property_readonly(
         "values",
         &Component::values,
         Component::help("values").c_str()
      )
      .def_property_readonly(
         "choice",
         &Component::choice,
         Component::help("choice").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
