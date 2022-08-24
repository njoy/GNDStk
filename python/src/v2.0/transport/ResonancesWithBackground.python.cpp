
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/ResonancesWithBackground.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// ResonancesWithBackground wrapper
void wrapResonancesWithBackground(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

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
            const transport::Background &,
            const transport::Resonances &,
            const std::optional<unknownNamespace::Uncertainty> &
         >(),
         python::arg("label"),
         python::arg("background"),
         python::arg("resonances"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "background",
         python::overload_cast<>(&Component::background),
         Component::documentation("background").data()
      )
      .def_property_readonly(
         "resonances",
         python::overload_cast<>(&Component::resonances),
         Component::documentation("resonances").data()
      )
      .def_property_readonly(
         "uncertainty",
         python::overload_cast<>(&Component::uncertainty),
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0