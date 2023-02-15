
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ThermalNeutronScatteringLaw_incoherentInelastic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ThermalNeutronScatteringLaw_incoherentInelastic
void wrapThermalNeutronScatteringLaw_incoherentInelastic(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::ThermalNeutronScatteringLaw_incoherentInelastic;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ThermalNeutronScatteringLaw_incoherentInelastic",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const std::optional<bool> &,
         const general::ScatteringAtoms &
      >(),
      py::arg("label"),
      py::arg("pid"),
      py::arg("product_frame"),
      py::arg("primary_scatterer"),
      py::arg("calculated_at_thermal") = std::nullopt,
      py::arg("scattering_atoms"),
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

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const std::string &value)
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
      [](cppCLASS &self, const std::string &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set primaryScatterer
   object.def_property(
      "primary_scatterer",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.primaryScatterer();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.primaryScatterer() = value;
      },
      cppCLASS::component_t::documentation("primary_scatterer").data()
   );

   // get/set calculatedAtThermal
   object.def_property(
      "calculated_at_thermal",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.calculatedAtThermal();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.calculatedAtThermal() = value;
      },
      cppCLASS::component_t::documentation("calculated_at_thermal").data()
   );

   // get/set scatteringAtoms
   object.def_property(
      "scattering_atoms",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.scatteringAtoms();
      },
      [](cppCLASS &self, const general::ScatteringAtoms &value)
      {
         self.scatteringAtoms() = value;
      },
      cppCLASS::component_t::documentation("scattering_atoms").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
