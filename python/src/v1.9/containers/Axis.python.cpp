
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

namespace v1_9 {
namespace containers {

// Axis wrapper
void wrapAxis(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Axis;

   // create the component
   python::class_<Component> component(
      module,
      "Axis",
      Component::documentation().c_str()
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
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::documentation("index").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").c_str()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::documentation("unit").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
