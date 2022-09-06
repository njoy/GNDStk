
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/pops/GaugeBosons.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// GaugeBosons wrapper
void wrapGaugeBosons(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = pops::GaugeBosons;

   // create the component
   python::class_<Component> component(
      module,
      "GaugeBosons",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<pops::GaugeBoson>> &
         >(),
         python::arg("gauge_boson") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "gauge_boson",
         [](const Component &self) { return self.gaugeBoson(); },
         Component::documentation("gauge_boson").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0