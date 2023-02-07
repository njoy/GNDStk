
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ProductYield.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// ProductYield wrapper
void wrapProductYield(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::ProductYield;

   // create the component
   python::class_<Component> component(
      module, "ProductYield",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<reduced::Nuclides> &,
            const general::ElapsedTimes &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("nuclides") = std::nullopt,
         python::arg("elapsed_times"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::component_t::documentation("label").data()
      )
      .def_property_readonly(
         "nuclides",
         [](const Component &self)
         {
            return self.nuclides();
         },
         Component::component_t::documentation("nuclides").data()
      )
      .def_property_readonly(
         "elapsed_times",
         [](const Component &self)
         {
            return self.elapsedTimes();
         },
         Component::component_t::documentation("elapsed_times").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
