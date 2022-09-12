
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/resonances/Widths.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// Widths wrapper
void wrapWidths(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = resonances::Widths;

   // create the component
   python::class_<Component> component(
      module,
      "Widths",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<resonances::Width> &
         >(),
         python::arg("width"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "width",
         [](const Component &self) { return self.width(); },
         Component::documentation("width").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0