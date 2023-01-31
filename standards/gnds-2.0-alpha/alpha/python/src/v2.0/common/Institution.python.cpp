
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/common/Institution.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Institution wrapper
void wrapInstitution(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = common::Institution;

   // create the component
   python::class_<Component> component(
      module,
      "Institution",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const common::ENDFconversionFlags &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("endfconversion_flags"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "endfconversion_flags",
         [](const Component &self) { return self.ENDFconversionFlags(); },
         Component::documentation("endfconversion_flags").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
