
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Axis.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_containers {

// Axis wrapper
void wrapAxis(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

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
            const std::optional<XMLName> &,
            const std::optional<XMLName> &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("unit") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::documentation("unit").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
