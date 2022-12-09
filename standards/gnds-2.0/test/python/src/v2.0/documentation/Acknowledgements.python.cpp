
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Acknowledgements.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Acknowledgements wrapper
void wrapAcknowledgements(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = documentation::Acknowledgements;

   // create the component
   python::class_<Component> component(
      module,
      "Acknowledgements",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<documentation::Acknowledgement> &
         >(),
         python::arg("acknowledgement"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "acknowledgement",
         [](const Component &self) { return self.acknowledgement(); },
         Component::documentation("acknowledgement").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0
