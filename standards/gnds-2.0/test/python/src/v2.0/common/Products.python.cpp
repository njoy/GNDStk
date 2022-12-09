
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/common/Products.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Products wrapper
void wrapProducts(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = common::Products;

   // create the component
   python::class_<Component> component(
      module,
      "Products",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<common::Product>> &
         >(),
         python::arg("product") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "product",
         [](const Component &self) { return self.product(); },
         Component::documentation("product").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
