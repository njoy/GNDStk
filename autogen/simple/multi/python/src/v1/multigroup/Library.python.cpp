
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "multi/v1/multigroup/Library.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1 {
namespace python_multigroup {

// Library wrapper
void wrapLibrary(python::module &module)
{
   using namespace multi;
   using namespace multi::v1;

   // type aliases
   using Component = multigroup::Library;

   // create the component
   python::class_<Component> component(
      module,
      "Library",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::vector<multigroup::Element> &
         >(),
         python::arg("name"),
         python::arg("element"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "name",
         [](const Component &self) { return self.name(); },
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "element",
         [](const Component &self) { return self.element(); },
         Component::documentation("element").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_multigroup
} // namespace python_v1