
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/styles/Transportables.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// Transportables wrapper
void wrapTransportables(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = styles::Transportables;

   // create the component
   python::class_<Component> component(
      module,
      "Transportables",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::vector<styles::Transportable> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("transportable"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "transportable",
         [](const Component &self) { return self.transportable(); },
         Component::documentation("transportable").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0
