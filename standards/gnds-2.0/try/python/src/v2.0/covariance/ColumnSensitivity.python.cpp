
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/covariance/ColumnSensitivity.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// ColumnSensitivity wrapper
void wrapColumnSensitivity(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = covariance::ColumnSensitivity;

   // create the component
   python::class_<Component> component(
      module,
      "ColumnSensitivity",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::Array &
         >(),
         python::arg("array"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "array",
         [](const Component &self) { return self.array(); },
         Component::documentation("array").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0