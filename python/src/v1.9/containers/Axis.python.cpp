
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Axis.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace containers {

// Axis wrapper
void wrapAxis(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = v1_9::containers::Axis;

   // create the component
   python::class_<Component> component(
      module,
      Component::className(),
      Component::help()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const std::optional<XMLName> &,
            const std::optional<XMLName> &
         >(),
         python::arg("index"),
         python::arg("label"),
         python::arg("unit"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::help("index")
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label")
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::help("unit")
      )
   ;
}

} // namespace containers
} // namespace v1_9
