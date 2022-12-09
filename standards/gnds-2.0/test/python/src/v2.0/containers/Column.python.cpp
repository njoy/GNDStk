
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Column.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Column wrapper
void wrapColumn(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::Column;

   // create the component
   python::class_<Component> component(
      module,
      "Column",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Integer32 &,
            const XMLName &,
            const std::optional<XMLName> &,
            const std::optional<XMLName> &
         >(),
         python::arg("index"),
         python::arg("name"),
         python::arg("unit") = std::nullopt,
         python::arg("types") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         [](const Component &self) { return self.index(); },
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "name",
         [](const Component &self) { return self.name(); },
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "unit",
         [](const Component &self) { return self.unit(); },
         Component::documentation("unit").data()
      )
      .def_property_readonly(
         "types",
         [](const Component &self) { return self.types(); },
         Component::documentation("types").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
