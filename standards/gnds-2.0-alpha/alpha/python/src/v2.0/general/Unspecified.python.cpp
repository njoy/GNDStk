
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Unspecified.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Unspecified wrapper
void wrapUnspecified(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Unspecified;

   // create the component
   python::class_<Component> component(
      module,
      "Unspecified",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::optional<std::string> &
         >(),
         python::arg("label"),
         python::arg("product_frame") = std::nullopt,
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
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
