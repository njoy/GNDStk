
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/RelatedItems.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// RelatedItems wrapper
void wrapRelatedItems(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = documentation::RelatedItems;

   // create the component
   python::class_<Component> component(
      module,
      "RelatedItems",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<documentation::RelatedItem> &
         >(),
         python::arg("related_item"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "related_item",
         [](const Component &self) { return self.relatedItem(); },
         Component::documentation("related_item").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0
