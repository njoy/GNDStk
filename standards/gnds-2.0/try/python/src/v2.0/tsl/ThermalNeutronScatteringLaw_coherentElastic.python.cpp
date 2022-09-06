
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/tsl/ThermalNeutronScatteringLaw_coherentElastic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// ThermalNeutronScatteringLaw_coherentElastic wrapper
void wrapThermalNeutronScatteringLaw_coherentElastic(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = tsl::ThermalNeutronScatteringLaw_coherentElastic;
   using _t = std::variant<
      tsl::S_table,
      tsl::BraggEdges
   >;

   // create the component
   python::class_<Component> component(
      module,
      "ThermalNeutronScatteringLaw_coherentElastic",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<XMLName> &,
            const std::optional<enums::Frame> &,
            const _t &
         >(),
         python::arg("label"),
         python::arg("pid") = std::nullopt,
         python::arg("product_frame") = std::nullopt,
         python::arg("_s_table_bragg_edges"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self) { return self.pid().value(); },
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "product_frame",
         [](const Component &self) { return self.productFrame().value(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "s_table",
         [](const Component &self) { return self.S_table(); },
         Component::documentation("s_table").data()
      )
      .def_property_readonly(
         "bragg_edges",
         [](const Component &self) { return self.BraggEdges(); },
         Component::documentation("bragg_edges").data()
      )
      .def_property_readonly(
         "_s_table_bragg_edges",
         [](const Component &self) { return self._S_tableBraggEdges(); },
         Component::documentation("_s_table_bragg_edges").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0