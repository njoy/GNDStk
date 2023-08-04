
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/reduced/Distribution.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_reduced {

// wrapper for reduced::Distribution
void wrapDistribution(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = reduced::Distribution;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Distribution",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::ThermalNeutronScatteringLaw> &,
         const std::optional<general::Uncorrelated> &,
         const std::optional<general::Unspecified> &,
         const std::optional<general::XYs2d> &,
         const std::optional<general::Branching3d> &
      >(),
      py::arg("thermal_neutron_scattering_law") = std::nullopt,
      py::arg("uncorrelated") = std::nullopt,
      py::arg("unspecified") = std::nullopt,
      py::arg("xys2d") = std::nullopt,
      py::arg("branching3d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set thermalNeutronScatteringLaw
   object.def_property(
      "thermal_neutron_scattering_law",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.thermalNeutronScatteringLaw();
      },
      [](cppCLASS &self, const std::optional<general::ThermalNeutronScatteringLaw> &value)
      {
         self.thermalNeutronScatteringLaw() = value;
      },
      cppCLASS::component_t::documentation("thermal_neutron_scattering_law").data()
   );

   // get/set uncorrelated
   object.def_property(
      "uncorrelated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncorrelated();
      },
      [](cppCLASS &self, const std::optional<general::Uncorrelated> &value)
      {
         self.uncorrelated() = value;
      },
      cppCLASS::component_t::documentation("uncorrelated").data()
   );

   // get/set unspecified
   object.def_property(
      "unspecified",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unspecified();
      },
      [](cppCLASS &self, const std::optional<general::Unspecified> &value)
      {
         self.unspecified() = value;
      },
      cppCLASS::component_t::documentation("unspecified").data()
   );

   // get/set XYs2d
   object.def_property(
      "xys2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs2d();
      },
      [](cppCLASS &self, const std::optional<general::XYs2d> &value)
      {
         self.XYs2d() = value;
      },
      cppCLASS::component_t::documentation("xys2d").data()
   );

   // get/set branching3d
   object.def_property(
      "branching3d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.branching3d();
      },
      [](cppCLASS &self, const std::optional<general::Branching3d> &value)
      {
         self.branching3d() = value;
      },
      cppCLASS::component_t::documentation("branching3d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_reduced
} // namespace python_v2_0
} // namespace python_GNDS
