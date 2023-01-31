
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/common/Charge.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Charge wrapper
void wrapCharge(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = common::Charge;

   // create the component
   python::class_<Component> component(
      module,
      "Charge",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const common::Integer &
         >(),
         python::arg("integer"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "integer",
         [](const Component &self) { return self.integer(); },
         Component::documentation("integer").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
