
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "multi/v1/multigroup/Foobar.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1 {
namespace python_multigroup {

// Foobar wrapper
void wrapFoobar(python::module &module)
{
   using namespace multi;
   using namespace multi::v1;

   // type aliases
   using Component = multigroup::Foobar;

   // create the component
   python::class_<Component> component(
      module,
      "Foobar",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
         >(),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<double> &
         >(),
         python::arg("doubles"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::documentation("doubles").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_multigroup
} // namespace python_v1