
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/DelayedNeutron.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::DelayedNeutron
void wrapDelayedNeutron(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::DelayedNeutron;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "DelayedNeutron",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const general::Rate &,
         const reduced::Product &
      >(),
      py::arg("label"),
      py::arg("rate"),
      py::arg("product"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set rate
   object.def_property(
      "rate",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.rate();
      },
      [](cppCLASS &self, const general::Rate &value)
      {
         self.rate() = value;
      },
      cppCLASS::component_t::documentation("rate").data()
   );

   // get/set product
   object.def_property(
      "product",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.product();
      },
      [](cppCLASS &self, const reduced::Product &value)
      {
         self.product() = value;
      },
      cppCLASS::component_t::documentation("product").data()
   );

   // shortcut: get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.Double())> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
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

   // shortcut: get/set XYs2d
   object.def_property(
      "xys2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs2d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.XYs2d())> &value)
      {
         self.XYs2d() = value;
      },
      cppCLASS::component_t::documentation("xys2d").data()
   );

   // shortcut: get/set branching1d
   object.def_property(
      "branching1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.branching1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.branching1d())> &value)
      {
         self.branching1d() = value;
      },
      cppCLASS::component_t::documentation("branching1d").data()
   );

   // shortcut: get/set constant1d
   object.def_property(
      "constant1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.constant1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.constant1d())> &value)
      {
         self.constant1d() = value;
      },
      cppCLASS::component_t::documentation("constant1d").data()
   );

   // shortcut: get/set distribution
   object.def_property(
      "distribution",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.distribution();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.distribution())> &value)
      {
         self.distribution() = value;
      },
      cppCLASS::component_t::documentation("distribution").data()
   );

   // shortcut: get/set multiplicity
   object.def_property(
      "multiplicity",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.multiplicity();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.multiplicity())> &value)
      {
         self.multiplicity() = value;
      },
      cppCLASS::component_t::documentation("multiplicity").data()
   );

   // shortcut: get/set polynomial1d
   object.def_property(
      "polynomial1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.polynomial1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.polynomial1d())> &value)
      {
         self.polynomial1d() = value;
      },
      cppCLASS::component_t::documentation("polynomial1d").data()
   );

   // shortcut: get/set reference
   object.def_property(
      "reference",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.reference();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.reference())> &value)
      {
         self.reference() = value;
      },
      cppCLASS::component_t::documentation("reference").data()
   );

   // shortcut: get/set regions1d
   object.def_property(
      "regions1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.regions1d())> &value)
      {
         self.regions1d() = value;
      },
      cppCLASS::component_t::documentation("regions1d").data()
   );

   // shortcut: get/set thermalNeutronScatteringLaw
   object.def_property(
      "thermal_neutron_scattering_law",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.thermalNeutronScatteringLaw())> &value)
      {
         self.thermalNeutronScatteringLaw() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law").data()
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

   // shortcut: get/set uncorrelated
   object.def_property(
      "uncorrelated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncorrelated();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncorrelated())> &value)
      {
         self.uncorrelated() = value;
      },
      cppCLASS::component_t::documentation("uncorrelated").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0