
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/ThermalNeutronScatteringLaw_incoherentElastic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// wrapper for tsl::ThermalNeutronScatteringLaw_incoherentElastic
void wrapThermalNeutronScatteringLaw_incoherentElastic(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = tsl::ThermalNeutronScatteringLaw_incoherentElastic;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ThermalNeutronScatteringLaw_incoherentElastic",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const XMLName &,
         const enums::Frame &,
         const tsl::BoundAtomCrossSection &,
         const tsl::DebyeWallerIntegral &
      >(),
      py::arg("label"),
      py::arg("pid"),
      py::arg("product_frame"),
      py::arg("bound_atom_cross_section"),
      py::arg("debye_waller_integral"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.pid() = value;
      },
      cppCLASS::component_t::documentation("pid").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const enums::Frame &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set boundAtomCrossSection
   object.def_property(
      "bound_atom_cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.boundAtomCrossSection();
      },
      [](cppCLASS &self, const tsl::BoundAtomCrossSection &value)
      {
         self.boundAtomCrossSection() = value;
      },
      cppCLASS::component_t::documentation("bound_atom_cross_section").data()
   );

   // get/set DebyeWallerIntegral
   object.def_property(
      "debye_waller_integral",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.DebyeWallerIntegral();
      },
      [](cppCLASS &self, const tsl::DebyeWallerIntegral &value)
      {
         self.DebyeWallerIntegral() = value;
      },
      cppCLASS::component_t::documentation("debye_waller_integral").data()
   );

   // shortcut: get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.XYs1d())> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // shortcut: get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axes())> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // shortcut: get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.values())> &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_tsl
} // namespace python_v2_0
