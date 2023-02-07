
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Unresolved.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Unresolved wrapper
void wrapUnresolved(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Unresolved;

   // create the component
   python::class_<Component> component(
      module, "Unresolved",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const double &,
            const double &,
            const std::string &,
            const general::TabulatedWidths &
         >(),
         python::arg("domain_min"),
         python::arg("domain_max"),
         python::arg("domain_unit"),
         python::arg("tabulated_widths"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self)
         {
            return self.domainMin();
         },
         Component::component_t::documentation("domain_min").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self)
         {
            return self.domainMax();
         },
         Component::component_t::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_unit",
         [](const Component &self)
         {
            return self.domainUnit();
         },
         Component::component_t::documentation("domain_unit").data()
      )
      .def_property_readonly(
         "tabulated_widths",
         [](const Component &self)
         {
            return self.tabulatedWidths();
         },
         Component::component_t::documentation("tabulated_widths").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
