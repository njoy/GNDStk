
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Atomic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Atomic wrapper
void wrapAtomic(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Atomic;

   // create the component
   python::class_<Component> component(
      module, "Atomic",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::Configurations &
         >(),
         python::arg("configurations"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "configurations",
         [](const Component &self)
         {
            return self.configurations();
         },
         Component::documentation("configurations").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
