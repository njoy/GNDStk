
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/WeightedFunctionals.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// WeightedFunctionals wrapper
void wrapWeightedFunctionals(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::WeightedFunctionals;

   // create the component
   python::class_<Component> component(
      module,
      "WeightedFunctionals",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::Weighted> &
         >(),
         python::arg("weighted"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "weighted",
         [](const Component &self) { return self.weighted(); },
         Component::documentation("weighted").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
