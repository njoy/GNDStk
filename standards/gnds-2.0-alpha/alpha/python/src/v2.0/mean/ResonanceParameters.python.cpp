
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/ResonanceParameters.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// ResonanceParameters wrapper
void wrapResonanceParameters(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::ResonanceParameters;

   // create the component
   python::class_<Component> component(
      module,
      "ResonanceParameters",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const mean::Table &
         >(),
         python::arg("table"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "table",
         [](const Component &self) { return self.table(); },
         Component::documentation("table").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
