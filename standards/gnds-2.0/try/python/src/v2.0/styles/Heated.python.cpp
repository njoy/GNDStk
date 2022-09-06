
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/styles/Heated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// Heated wrapper
void wrapHeated(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = styles::Heated;

   // create the component
   python::class_<Component> component(
      module,
      "Heated",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const XMLName &,
            const XMLName &,
            const styles::Temperature &,
            const std::optional<documentation::Documentation> &
         >(),
         python::arg("date"),
         python::arg("derived_from"),
         python::arg("label"),
         python::arg("temperature"),
         python::arg("documentation") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "date",
         [](const Component &self) { return self.date(); },
         Component::documentation("date").data()
      )
      .def_property_readonly(
         "derived_from",
         [](const Component &self) { return self.derivedFrom(); },
         Component::documentation("derived_from").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "temperature",
         [](const Component &self) { return self.temperature(); },
         Component::documentation("temperature").data()
      )
      .def_property_readonly(
         "documentation",
         [](const Component &self) { return self.documentation(); },
         Component::documentation("documentation").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0