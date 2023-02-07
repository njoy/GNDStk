
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Intensity.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Intensity wrapper
void wrapIntensity(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Intensity;

   // create the component
   python::class_<Component> component(
      module, "Intensity",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const double &,
            const std::optional<general::Uncertainty> &
         >(),
         python::arg("value"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "value",
         [](const Component &self)
         {
            return self.value();
         },
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self)
         {
            return self.uncertainty();
         },
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
