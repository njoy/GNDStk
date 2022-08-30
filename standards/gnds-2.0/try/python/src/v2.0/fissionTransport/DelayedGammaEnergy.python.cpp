
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/fissionTransport/DelayedGammaEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// DelayedGammaEnergy wrapper
void wrapDelayedGammaEnergy(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = fissionTransport::DelayedGammaEnergy;

   // create the component
   python::class_<Component> component(
      module,
      "DelayedGammaEnergy",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<containers::Polynomial1d> &
         >(),
         python::arg("polynomial1d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "polynomial1d",
         [](const Component &self) { return self.polynomial1d(); },
         Component::documentation("polynomial1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionTransport
} // namespace python_v2_0
