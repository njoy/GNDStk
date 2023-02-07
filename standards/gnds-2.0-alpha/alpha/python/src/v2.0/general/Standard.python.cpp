
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Standard.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Standard wrapper
void wrapStandard(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Standard;

   // create the component
   python::class_<Component> component(
      module, "Standard",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const reduced::Double &
         >(),
         python::arg("double"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "double",
         [](const Component &self)
         {
            return self.Double();
         },
         Component::documentation("double").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
