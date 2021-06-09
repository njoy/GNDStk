
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

namespace v1_9 {
namespace containers {

// Values wrapper
void wrapValues(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Values;

   // create the component
   python::class_<Component> component(
      module,
      "Values",
      Component::help().c_str()
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
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "length",
         &Component::length,
         Component::help("length").c_str()
      )
      .def_property_readonly(
         "start",
         &Component::start,
         Component::help("start").c_str()
      )
      .def_property_readonly(
         "value_type",
         &Component::valueType,
         Component::help("value_type").c_str()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::help("doubles").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
