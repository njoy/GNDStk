
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/styles/HeatedMultiGroup.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// HeatedMultiGroup wrapper
void wrapHeatedMultiGroup(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = styles::HeatedMultiGroup;

   // create the component
   python::class_<Component> component(
      module,
      "HeatedMultiGroup",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const XMLName &,
            const XMLName &,
            const styles::Transportables &,
            const styles::Flux &,
            const styles::InverseSpeed &,
            const std::optional<documentation::Documentation> &
         >(),
         python::arg("date"),
         python::arg("derived_from"),
         python::arg("label"),
         python::arg("transportables"),
         python::arg("flux"),
         python::arg("inverse_speed"),
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
         "transportables",
         [](const Component &self) { return self.transportables(); },
         Component::documentation("transportables").data()
      )
      .def_property_readonly(
         "flux",
         [](const Component &self) { return self.flux(); },
         Component::documentation("flux").data()
      )
      .def_property_readonly(
         "inverse_speed",
         [](const Component &self) { return self.inverseSpeed(); },
         Component::documentation("inverse_speed").data()
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
