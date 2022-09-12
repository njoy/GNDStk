
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/FissionComponents.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// FissionComponents wrapper
void wrapFissionComponents(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fissionTransport::FissionComponents;

   // create the component
   python::class_<Component> component(
      module,
      "FissionComponents",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<fissionTransport::FissionComponent>> &
         >(),
         python::arg("fission_component") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "fission_component",
         [](const Component &self) { return self.fissionComponent(); },
         Component::documentation("fission_component").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0