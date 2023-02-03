
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Gridded3d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Gridded3d wrapper
void wrapGridded3d(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Gridded3d;

   // create the component
   python::class_<Component> component(
      module,
      "Gridded3d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::Axes &,
            const g3d::Array &
         >(),
         python::arg("axes"),
         python::arg("array"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self) { return self.axes(); },
         Component::documentation("axes").data()
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

} // namespace python_general
} // namespace python_v2_0
