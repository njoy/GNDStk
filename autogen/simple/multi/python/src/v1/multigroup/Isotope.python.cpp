
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "multi/v1/multigroup/Isotope.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1 {
namespace python_multigroup {

// Isotope wrapper
void wrapIsotope(python::module &module)
{
   using namespace multi;
   using namespace multi::v1;

   // type aliases
   using Component = multigroup::Isotope;

   // create the component
   python::class_<Component> component(
      module,
      "Isotope",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const int &
         >(),
         python::arg("mass_number"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "mass_number",
         [](const Component &self) { return self.mass_number(); },
         Component::documentation("mass_number").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_multigroup
} // namespace python_v1
