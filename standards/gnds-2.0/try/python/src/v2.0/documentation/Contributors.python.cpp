
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/documentation/Contributors.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Contributors wrapper
void wrapContributors(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = documentation::Contributors;

   // create the component
   python::class_<Component> component(
      module,
      "Contributors",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<documentation::Author> &
         >(),
         python::arg("contributor"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "contributor",
         [](const Component &self) { return self.contributor(); },
         Component::documentation("contributor").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0
