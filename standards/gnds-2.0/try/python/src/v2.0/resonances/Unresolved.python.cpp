
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/resonances/Unresolved.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// Unresolved wrapper
void wrapUnresolved(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = resonances::Unresolved;
   using _t = std::variant<
      resonances::TabulatedWidths
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Unresolved",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Float64 &,
            const Float64 &,
            const XMLName &,
            const _t &
         >(),
         python::arg("domain_min"),
         python::arg("domain_max"),
         python::arg("domain_unit"),
         python::arg("_tabulated_widths"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self) { return self.domainMin(); },
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self) { return self.domainMax(); },
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_unit",
         [](const Component &self) { return self.domainUnit(); },
         Component::documentation("domain_unit").data()
      )
      .def_property_readonly(
         "tabulated_widths",
         [](const Component &self) { return self.tabulatedWidths(); },
         Component::documentation("tabulated_widths").data()
      )
      .def_property_readonly(
         "_tabulated_widths",
         [](const Component &self) { return self._tabulatedWidths(); },
         Component::documentation("_tabulated_widths").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0
