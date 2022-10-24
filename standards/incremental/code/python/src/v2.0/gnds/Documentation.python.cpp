
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/gnds/Documentation.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_gnds {

// Documentation wrapper
void wrapDocumentation(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = gnds::Documentation;

   // create the component
   python::class_<Component> component(
      module,
      "Documentation",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const gnds::Authors &,
            const gnds::Dates &,
            const gnds::Title &,
            const gnds::Body &,
            const gnds::EndfCompatible &
         >(),
         python::arg("authors"),
         python::arg("dates"),
         python::arg("title"),
         python::arg("body"),
         python::arg("endf_compatible"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "authors",
         [](const Component &self) { return self.authors(); },
         Component::documentation("authors").data()
      )
      .def_property_readonly(
         "dates",
         [](const Component &self) { return self.dates(); },
         Component::documentation("dates").data()
      )
      .def_property_readonly(
         "title",
         [](const Component &self) { return self.title(); },
         Component::documentation("title").data()
      )
      .def_property_readonly(
         "body",
         [](const Component &self) { return self.body(); },
         Component::documentation("body").data()
      )
      .def_property_readonly(
         "endf_compatible",
         [](const Component &self) { return self.endfCompatible(); },
         Component::documentation("endf_compatible").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_gnds
} // namespace python_v2_0
