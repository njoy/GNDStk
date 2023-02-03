
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/R.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// R wrapper
void wrapR(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::R;

   // create the component
   python::class_<Component> component(
      module,
      "R",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::XYs2d &
         >(),
         python::arg("xys2d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys2d",
         [](const Component &self) { return self.XYs2d(); },
         Component::documentation("xys2d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
