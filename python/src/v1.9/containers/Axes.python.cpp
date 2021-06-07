
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Axes.hpp"

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
      Component::className(),
      Component::help().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<UTF8Text> &,
            const std::optional<std::vector<containers::Axis>> &,
            const std::optional<std::vector<containers::Grid>> &
         >(),
         python::arg("href"),
         python::arg("axis"),
         python::arg("grid"),
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::help("href").c_str()
      )
      .def_property_readonly(
         "axis",
         &Component::axis,
         Component::help("axis").c_str()
      )
      .def_property_readonly(
         "grid",
         &Component::grid,
         Component::help("grid").c_str()
      )
   ;
}

} // namespace containers
} // namespace v1_9
