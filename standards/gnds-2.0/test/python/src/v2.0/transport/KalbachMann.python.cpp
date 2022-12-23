
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/KalbachMann.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// KalbachMann wrapper
void wrapKalbachMann(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::KalbachMann;

   // create the component
   python::class_<Component> component(
      module,
      "KalbachMann",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const XMLName &,
            const transport::F &,
            const transport::R &,
            const std::optional<transport::A> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("product_frame"),
         python::arg("f"),
         python::arg("r"),
         python::arg("a") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "product_frame",
         [](const Component &self) { return self.productFrame(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "f",
         [](const Component &self) { return self.f(); },
         Component::documentation("f").data()
      )
      .def_property_readonly(
         "r",
         [](const Component &self) { return self.r(); },
         Component::documentation("r").data()
      )
      .def_property_readonly(
         "a",
         [](const Component &self) { return self.a(); },
         Component::documentation("a").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
