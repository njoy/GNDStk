
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Values.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_containers {

// Values wrapper
void wrapValues(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = containers::Values;

   // create the component
   python::class_<Component> component(
      module,
      "Values",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const Integer32 &,
            const UTF8Text &,
            const std::vector<Float64> &
         >(),
         python::arg("length") = std::nullopt,
         python::arg("start") = 0,
         python::arg("value_type") = "Float64",
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "length",
         &Component::length,
         Component::documentation("length").data()
      )
      .def_property_readonly(
         "start",
         &Component::start,
         Component::documentation("start").data()
      )
      .def_property_readonly(
         "value_type",
         &Component::valueType,
         Component::documentation("value_type").data()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::documentation("doubles").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
