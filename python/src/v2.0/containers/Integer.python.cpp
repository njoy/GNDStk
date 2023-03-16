
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/containers/Integer.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Integer wrapper
void wrapInteger(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = containers::Integer;

   // create the component
   python::class_<Component> component(
      module,
      "Integer",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const Integer32 &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("unit") = std::nullopt,
         python::arg("value"),
         Component::documentation("constructor").data()
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
      .def_property_readonly(
         "value",
         &Component::value,
         Component::documentation("value").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
