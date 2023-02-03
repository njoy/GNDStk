
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/GeneralEvaporation.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// GeneralEvaporation wrapper
void wrapGeneralEvaporation(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::GeneralEvaporation;

   // create the component
   python::class_<Component> component(
      module,
      "GeneralEvaporation",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::U &,
            const general::Theta &,
            const general::G &
         >(),
         python::arg("u"),
         python::arg("theta"),
         python::arg("g"),
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
      .def_property_readonly(
         "g",
         [](const Component &self) { return self.g(); },
         Component::documentation("g").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
