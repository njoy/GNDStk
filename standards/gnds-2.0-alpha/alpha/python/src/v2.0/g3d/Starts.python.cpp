
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/g3d/Starts.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_g3d {

// Starts wrapper
void wrapStarts(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = g3d::Starts;

   // create the component
   python::class_<Component> component(
      module,
      "Starts",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &
         >(),
         python::arg("value_type"),
         python::arg("label"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<int> &
         >(),
         python::arg("ints"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "value_type",
         [](const Component &self) { return self.valueType(); },
         Component::documentation("value_type").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "ints",
         [] (const Component &self) { return self.ints(); },
         Component::documentation("ints").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_g3d
} // namespace python_v2_0
