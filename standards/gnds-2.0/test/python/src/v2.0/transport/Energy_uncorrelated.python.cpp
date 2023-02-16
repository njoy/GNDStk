
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/Energy_uncorrelated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::Energy_uncorrelated
void wrapEnergy_uncorrelated(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::Energy_uncorrelated;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Energy_uncorrelated",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<containers::XYs2d> &,
         const std::optional<containers::Regions2d> &,
         const std::optional<transport::GeneralEvaporation> &,
         const std::optional<transport::DiscreteGamma> &,
         const std::optional<transport::PrimaryGamma> &,
         const std::optional<transport::NBodyPhaseSpace> &,
         const std::optional<transport::Evaporation> &,
         const std::optional<transport::WeightedFunctionals> &,
         const std::optional<fissionTransport::SimpleMaxwellianFission> &,
         const std::optional<fissionTransport::Watt> &,
         const std::optional<fissionTransport::MadlandNix> &
      >(),
      py::arg("xys2d") = std::nullopt,
      py::arg("regions2d") = std::nullopt,
      py::arg("general_evaporation") = std::nullopt,
      py::arg("discrete_gamma") = std::nullopt,
      py::arg("primary_gamma") = std::nullopt,
      py::arg("nbody_phase_space") = std::nullopt,
      py::arg("evaporation") = std::nullopt,
      py::arg("weighted_functionals") = std::nullopt,
      py::arg("simple_maxwellian_fission") = std::nullopt,
      py::arg("watt") = std::nullopt,
      py::arg("madland_nix") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set XYs2d
   object.def_property(
      "xys2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs2d();
      },
      [](cppCLASS &self, const std::optional<containers::XYs2d> &value)
      {
         self.XYs2d() = value;
      },
      cppCLASS::component_t::documentation("xys2d").data()
   );

   // get/set regions2d
   object.def_property(
      "regions2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions2d();
      },
      [](cppCLASS &self, const std::optional<containers::Regions2d> &value)
      {
         self.regions2d() = value;
      },
      cppCLASS::component_t::documentation("regions2d").data()
   );

   // get/set generalEvaporation
   object.def_property(
      "general_evaporation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.generalEvaporation();
      },
      [](cppCLASS &self, const std::optional<transport::GeneralEvaporation> &value)
      {
         self.generalEvaporation() = value;
      },
      cppCLASS::component_t::documentation("general_evaporation").data()
   );

   // get/set discreteGamma
   object.def_property(
      "discrete_gamma",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.discreteGamma();
      },
      [](cppCLASS &self, const std::optional<transport::DiscreteGamma> &value)
      {
         self.discreteGamma() = value;
      },
      cppCLASS::component_t::documentation("discrete_gamma").data()
   );

   // get/set primaryGamma
   object.def_property(
      "primary_gamma",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.primaryGamma();
      },
      [](cppCLASS &self, const std::optional<transport::PrimaryGamma> &value)
      {
         self.primaryGamma() = value;
      },
      cppCLASS::component_t::documentation("primary_gamma").data()
   );

   // get/set NBodyPhaseSpace
   object.def_property(
      "nbody_phase_space",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.NBodyPhaseSpace();
      },
      [](cppCLASS &self, const std::optional<transport::NBodyPhaseSpace> &value)
      {
         self.NBodyPhaseSpace() = value;
      },
      cppCLASS::component_t::documentation("nbody_phase_space").data()
   );

   // get/set evaporation
   object.def_property(
      "evaporation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaporation();
      },
      [](cppCLASS &self, const std::optional<transport::Evaporation> &value)
      {
         self.evaporation() = value;
      },
      cppCLASS::component_t::documentation("evaporation").data()
   );

   // get/set weightedFunctionals
   object.def_property(
      "weighted_functionals",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.weightedFunctionals();
      },
      [](cppCLASS &self, const std::optional<transport::WeightedFunctionals> &value)
      {
         self.weightedFunctionals() = value;
      },
      cppCLASS::component_t::documentation("weighted_functionals").data()
   );

   // get/set simpleMaxwellianFission
   object.def_property(
      "simple_maxwellian_fission",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.simpleMaxwellianFission();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::SimpleMaxwellianFission> &value)
      {
         self.simpleMaxwellianFission() = value;
      },
      cppCLASS::component_t::documentation("simple_maxwellian_fission").data()
   );

   // get/set Watt
   object.def_property(
      "watt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Watt();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::Watt> &value)
      {
         self.Watt() = value;
      },
      cppCLASS::component_t::documentation("watt").data()
   );

   // get/set MadlandNix
   object.def_property(
      "madland_nix",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.MadlandNix();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::MadlandNix> &value)
      {
         self.MadlandNix() = value;
      },
      cppCLASS::component_t::documentation("madland_nix").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
