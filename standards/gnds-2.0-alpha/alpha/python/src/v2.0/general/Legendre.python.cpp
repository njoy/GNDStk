
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Legendre.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Legendre wrapper
void wrapLegendre(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Legendre;

   // create the component
   python::class_<Component> component(
      module, "Legendre",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const double &,
            const general::Values &
         >(),
         python::arg("outer_domain_value"),
         python::arg("values"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         [](const Component &self)
         {
            return self.outerDomainValue();
         },
         Component::component_t::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "values",
         [](const Component &self)
         {
            return self.values();
         },
         Component::component_t::documentation("values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
