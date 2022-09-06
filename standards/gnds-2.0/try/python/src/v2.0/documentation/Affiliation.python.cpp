
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/documentation/Affiliation.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Affiliation wrapper
void wrapAffiliation(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = documentation::Affiliation;

   // create the component
   python::class_<Component> component(
      module,
      "Affiliation",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const UTF8Text &,
            const std::optional<UTF8Text> &
         >(),
         python::arg("name"),
         python::arg("href") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "name",
         [](const Component &self) { return self.name(); },
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self) { return self.href(); },
         Component::documentation("href").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0