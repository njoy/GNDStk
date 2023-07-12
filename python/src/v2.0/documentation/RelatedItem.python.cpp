
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/documentation/RelatedItem.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// RelatedItem wrapper
void wrapRelatedItem(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = documentation::RelatedItem;

   // create the component
   python::class_<Component> component(
      module,
      "RelatedItem",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<UTF8Text> &,
            const UTF8Text &,
            const std::optional<enums::RelationType> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("name"),
         python::arg("relation_type") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::documentation("href").data()
      )
      .def_property_readonly(
         "name",
         &Component::name,
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "relation_type",
         &Component::relationType,
         Component::documentation("relation_type").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0
