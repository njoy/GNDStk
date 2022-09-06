
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/resonances/J.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// J wrapper
void wrapJ(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = resonances::J;

   // create the component
   python::class_<Component> component(
      module,
      "J",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const Fraction32 &,
            const resonances::LevelSpacing &,
            const resonances::Widths &
         >(),
         python::arg("label"),
         python::arg("value"),
         python::arg("level_spacing"),
         python::arg("widths"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "value",
         [](const Component &self) { return self.value(); },
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "level_spacing",
         [](const Component &self) { return self.levelSpacing(); },
         Component::documentation("level_spacing").data()
      )
      .def_property_readonly(
         "widths",
         [](const Component &self) { return self.widths(); },
         Component::documentation("widths").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0