
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ColumnHeaders.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// ColumnHeaders wrapper
void wrapColumnHeaders(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::ColumnHeaders;

   // create the component
   python::class_<Component> component(
      module,
      "ColumnHeaders",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::Column> &
         >(),
         python::arg("column"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "column",
         [](const Component &self) { return self.column(); },
         Component::documentation("column").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
