
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/SimpleMaxwellianFission.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// SimpleMaxwellianFission wrapper
void wrapSimpleMaxwellianFission(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::SimpleMaxwellianFission;

   // create the component
   python::class_<Component> component(
      module,
      "SimpleMaxwellianFission",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::U &,
            const general::Theta &
         >(),
         python::arg("u"),
         python::arg("theta"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "u",
         [](const Component &self) { return self.U(); },
         Component::documentation("u").data()
      )
      .def_property_readonly(
         "theta",
         [](const Component &self) { return self.theta(); },
         Component::documentation("theta").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
