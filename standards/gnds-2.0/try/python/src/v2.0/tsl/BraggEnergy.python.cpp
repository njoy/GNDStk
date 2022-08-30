
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/tsl/BraggEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// BraggEnergy wrapper
void wrapBraggEnergy(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = tsl::BraggEnergy;

   // create the component
   python::class_<Component> component(
      module,
      "BraggEnergy",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::XYs1d &
         >(),
         python::arg("xys1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0
