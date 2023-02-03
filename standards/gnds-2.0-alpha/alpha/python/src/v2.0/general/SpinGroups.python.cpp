
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/SpinGroups.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// SpinGroups wrapper
void wrapSpinGroups(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::SpinGroups;

   // create the component
   python::class_<Component> component(
      module,
      "SpinGroups",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::SpinGroup> &
         >(),
         python::arg("spin_group"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "spin_group",
         [](const Component &self) { return self.spinGroup(); },
         Component::documentation("spin_group").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
