
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
      Component::help().c_str()
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
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::help("index").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label").c_str()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::help("unit").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
