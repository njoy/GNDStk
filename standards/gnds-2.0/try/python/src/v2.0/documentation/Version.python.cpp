
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/documentation/Version.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Version wrapper
void wrapVersion(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = documentation::Version;

   // create the component
   python::class_<Component> component(
      module,
      "Version",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<std::string> &,
            const std::optional<XMLName> &
         >(),
         python::arg("encoding") = std::nullopt,
         python::arg("markup") = std::nullopt,
         python::arg("label") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<int> &
         >(),
         python::arg("ints"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<double> &
         >(),
         python::arg("doubles"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<std::string> &
         >(),
         python::arg("strings"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "encoding",
         [](const Component &self) { return self.encoding().value(); },
         Component::documentation("encoding").data()
      )
      .def_property_readonly(
         "markup",
         [](const Component &self) { return self.markup().value(); },
         Component::documentation("markup").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "ints",
         [] (const Component &self) { return self.ints(); },
         Component::documentation("ints").data()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::documentation("doubles").data()
      )
      .def_property_readonly(
         "strings",
         [] (const Component &self) { return self.strings(); },
         Component::documentation("strings").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0
