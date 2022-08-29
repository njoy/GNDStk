
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/tsl/S_table.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// S_table wrapper
void wrapS_table(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = tsl::S_table;

   // create the component
   python::class_<Component> component(
      module,
      "S_table",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const unknownNamespace::Gridded2d &
         >(),
         python::arg("gridded2d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "gridded2d",
         [](const Component &self) { return self.gridded2d(); },
         Component::documentation("gridded2d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0
