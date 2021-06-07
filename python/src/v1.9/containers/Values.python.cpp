
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Values.hpp"

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
      Component::className(),
      Component::help().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const Defaulted<Integer32> &,
            const Defaulted<UTF8Text> &
         >(),
         python::arg("length"),
         python::arg("start"),
         python::arg("valueType"),
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
         "valueType",
         &Component::valueType,
         Component::help("valueType").c_str()
      )
   ;
}

} // namespace containers
} // namespace v1_9
