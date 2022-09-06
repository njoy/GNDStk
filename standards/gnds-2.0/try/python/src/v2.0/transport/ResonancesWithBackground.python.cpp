
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/ResonancesWithBackground.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// ResonancesWithBackground wrapper
void wrapResonancesWithBackground(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::ResonancesWithBackground;

   // create the component
   python::class_<Component> component(
      module,
      "ResonancesWithBackground",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const transport::ResonancesLink &,
            const transport::Background &,
            const std::optional<containers::Uncertainty> &
         >(),
         python::arg("label"),
         python::arg("resonances"),
         python::arg("background"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "resonances",
         [](const Component &self) { return self.resonances(); },
         Component::documentation("resonances").data()
      )
      .def_property_readonly(
         "background",
         [](const Component &self) { return self.background(); },
         Component::documentation("background").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self) { return self.uncertainty(); },
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
