
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/common/Product.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Product wrapper
void wrapProduct(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = common::Product;

   // create the component
   python::class_<Component> component(
      module,
      "Product",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const transport::Multiplicity &,
            const transport::Distribution &
         >(),
         python::arg("label"),
         python::arg("pid"),
         python::arg("multiplicity"),
         python::arg("distribution"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self) { return self.pid(); },
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "multiplicity",
         [](const Component &self) { return self.multiplicity(); },
         Component::documentation("multiplicity").data()
      )
      .def_property_readonly(
         "distribution",
         [](const Component &self) { return self.distribution(); },
         Component::documentation("distribution").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
