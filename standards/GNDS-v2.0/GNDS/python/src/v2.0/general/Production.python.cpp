
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Production.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Production
void wrapProduction(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Production;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Production",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const general::CrossSection &,
         const general::OutputChannel &
      >(),
      py::arg("label"),
      py::arg("endf_mt"),
      py::arg("cross_section"),
      py::arg("output_channel"),
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

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MT();
      },
      [](cppCLASS &self, const int &value)
      {
         self.ENDF_MT() = value;
      },
      cppCLASS::component_t::documentation("endf_mt").data()
   );

   // get/set crossSection
   object.def_property(
      "cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSection();
      },
      [](cppCLASS &self, const general::CrossSection &value)
      {
         self.crossSection() = value;
      },
      cppCLASS::component_t::documentation("cross_section").data()
   );

   // get/set outputChannel
   object.def_property(
      "output_channel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.outputChannel();
      },
      [](cppCLASS &self, const general::OutputChannel &value)
      {
         self.outputChannel() = value;
      },
      cppCLASS::component_t::documentation("output_channel").data()
   );

   // shortcut: get/set CoulombPlusNuclearElastic
   object.def_property(
      "coulomb_plus_nuclear_elastic",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.CoulombPlusNuclearElastic();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.CoulombPlusNuclearElastic())> &value)
      {
         self.CoulombPlusNuclearElastic() = value;
      },
      cppCLASS::component_t::documentation("coulomb_plus_nuclear_elastic").data()
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

   // shortcut: get/set Q
   object.def_property(
      "q",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Q();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.Q())> &value)
      {
         self.Q() = value;
      },
      cppCLASS::component_t::documentation("q").data()
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

   // shortcut: get/set fissionFragmentData
   object.def_property(
      "fission_fragment_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionFragmentData();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.fissionFragmentData())> &value)
      {
         self.fissionFragmentData() = value;
      },
      cppCLASS::component_t::documentation("fission_fragment_data").data()
   );

   // shortcut: get/set products
   object.def_property(
      "products",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.products();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.products())> &value)
      {
         self.products() = value;
      },
      cppCLASS::component_t::documentation("products").data()
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

   // shortcut: get/set resonancesWithBackground
   object.def_property(
      "resonances_with_background",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonancesWithBackground();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.resonancesWithBackground())> &value)
      {
         self.resonancesWithBackground() = value;
      },
      cppCLASS::component_t::documentation("resonances_with_background").data()
   );

   // shortcut: get/set thermalNeutronScatteringLaw1d
   object.def_property(
      "thermal_neutron_scattering_law1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.thermalNeutronScatteringLaw1d())> &value)
      {
         self.thermalNeutronScatteringLaw1d() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
