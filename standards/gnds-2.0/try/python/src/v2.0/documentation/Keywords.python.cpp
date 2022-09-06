
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/documentation/Keywords.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Keywords wrapper
void wrapKeywords(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = documentation::Keywords;

   // create the component
   python::class_<Component> component(
      module,
      "Keywords",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<documentation::Keyword> &
         >(),
         python::arg("keyword"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "keyword",
         [](const Component &self) { return self.keyword(); },
         Component::documentation("keyword").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0