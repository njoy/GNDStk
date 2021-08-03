
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

namespace python_v1_9 {
namespace python_containers {

// Axes wrapper
void wrapAxes(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = containers::Axes;
   using AXIS_GRID = std::variant<
      containers::Axis,
      containers::Grid
   >;

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
            const std::vector<AXIS_GRID> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("axis_grid"),
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::documentation("href").c_str()
      )
      .def_property_readonly(
         "axis_grid",
         python::overload_cast<>(&Component::axis_grid),
         Component::documentation("axis_grid").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
