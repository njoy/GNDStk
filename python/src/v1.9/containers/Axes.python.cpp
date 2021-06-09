
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Axes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace containers {

// Axes wrapper
void wrapAxes(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Axes;

   // create the component
   python::class_<Component> component(
      module,
      "Axes",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<UTF8Text> &,
            const std::optional<std::vector<containers::Axis>> &,
            const std::optional<std::vector<containers::Grid>> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("axis") = std::nullopt,
         python::arg("grid") = std::nullopt,
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::documentation("href").c_str()
      )
      .def_property_readonly(
         "axis",
         &Component::axis,
         Component::documentation("axis").c_str()
      )
      .def_property_readonly(
         "grid",
         &Component::grid,
         Component::documentation("grid").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
