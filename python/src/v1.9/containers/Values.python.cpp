
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
            const std::vector<Integer32> &
         >(),
         python::arg("length") = std::nullopt,
         python::arg("start") = std::nullopt,
         python::arg("value_type") = std::nullopt,
         python::arg("ints"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<Float64> &
         >(),
         python::arg("length") = std::nullopt,
         python::arg("start") = std::nullopt,
         python::arg("value_type") = std::nullopt,
         python::arg("doubles"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<UTF8Text> &
         >(),
         python::arg("length") = std::nullopt,
         python::arg("start") = std::nullopt,
         python::arg("value_type") = std::nullopt,
         python::arg("strings"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "length",
         &Component::length,
         Component::documentation("length").data()
      )
      .def_property_readonly(
         "start",
         [] ( const Component& self ) { return self.start().value(); },
         Component::documentation("start").data()
      )
      .def_property_readonly(
         "value_type",
         [] ( const Component& self ) { return self.valueType().value(); },
         Component::documentation("value_type").data()
      )
      .def_property_readonly(
         "ints",
         [] (const Component &self) { return self.ints(); },
         Component::documentation("ints").data()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::documentation("doubles").data()
      )
      .def_property_readonly(
         "strings",
         [] (const Component &self) { return self.strings(); },
         Component::documentation("strings").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
