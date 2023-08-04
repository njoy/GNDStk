
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Nuclide.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Nuclide
void wrapNuclide(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Nuclide;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Nuclide",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::optional<general::Mass> &,
         const general::Charge &,
         const general::Nucleus &,
         const std::optional<general::DecayData> &,
         const std::optional<top::FissionFragmentData> &
      >(),
      py::arg("id"),
      py::arg("mass") = std::nullopt,
      py::arg("charge"),
      py::arg("nucleus"),
      py::arg("decay_data") = std::nullopt,
      py::arg("fission_fragment_data") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set id
   object.def_property(
      "id",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.id();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.id() = value;
      },
      cppCLASS::component_t::documentation("id").data()
   );

   // get/set mass
   object.def_property(
      "mass",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mass();
      },
      [](cppCLASS &self, const std::optional<general::Mass> &value)
      {
         self.mass() = value;
      },
      cppCLASS::component_t::documentation("mass").data()
   );

   // get/set charge
   object.def_property(
      "charge",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.charge();
      },
      [](cppCLASS &self, const general::Charge &value)
      {
         self.charge() = value;
      },
      cppCLASS::component_t::documentation("charge").data()
   );

   // get/set nucleus
   object.def_property(
      "nucleus",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nucleus();
      },
      [](cppCLASS &self, const general::Nucleus &value)
      {
         self.nucleus() = value;
      },
      cppCLASS::component_t::documentation("nucleus").data()
   );

   // get/set decayData
   object.def_property(
      "decay_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.decayData();
      },
      [](cppCLASS &self, const std::optional<general::DecayData> &value)
      {
         self.decayData() = value;
      },
      cppCLASS::component_t::documentation("decay_data").data()
   );

   // get/set fissionFragmentData
   object.def_property(
      "fission_fragment_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionFragmentData();
      },
      [](cppCLASS &self, const std::optional<top::FissionFragmentData> &value)
      {
         self.fissionFragmentData() = value;
      },
      cppCLASS::component_t::documentation("fission_fragment_data").data()
   );

   // shortcut: get/set MadlandNix
   object.def_property(
      "madland_nix",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.MadlandNix();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.MadlandNix())> &value)
      {
         self.MadlandNix() = value;
      },
      cppCLASS::component_t::documentation("madland_nix").data()
   );

   // shortcut: get/set NBodyPhaseSpace
   object.def_property(
      "nbody_phase_space",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.NBodyPhaseSpace();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.NBodyPhaseSpace())> &value)
      {
         self.NBodyPhaseSpace() = value;
      },
      cppCLASS::component_t::documentation("nbody_phase_space").data()
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

   // shortcut: get/set discreteGamma
   object.def_property(
      "discrete_gamma",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.discreteGamma();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.discreteGamma())> &value)
      {
         self.discreteGamma() = value;
      },
      cppCLASS::component_t::documentation("discrete_gamma").data()
   );

   // shortcut: get/set energy
   object.def_property(
      "energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.energy();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.energy())> &value)
      {
         self.energy() = value;
      },
      cppCLASS::component_t::documentation("energy").data()
   );

   // shortcut: get/set evaporation
   object.def_property(
      "evaporation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaporation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.evaporation())> &value)
      {
         self.evaporation() = value;
      },
      cppCLASS::component_t::documentation("evaporation").data()
   );

   // shortcut: get/set generalEvaporation
   object.def_property(
      "general_evaporation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.generalEvaporation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.generalEvaporation())> &value)
      {
         self.generalEvaporation() = value;
      },
      cppCLASS::component_t::documentation("general_evaporation").data()
   );

   // shortcut: get/set halflife
   object.def_property(
      "halflife",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.halflife();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.halflife())> &value)
      {
         self.halflife() = value;
      },
      cppCLASS::component_t::documentation("halflife").data()
   );

   // shortcut: get/set parity
   object.def_property(
      "parity",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.parity();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.parity())> &value)
      {
         self.parity() = value;
      },
      cppCLASS::component_t::documentation("parity").data()
   );

   // shortcut: get/set primaryGamma
   object.def_property(
      "primary_gamma",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.primaryGamma();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.primaryGamma())> &value)
      {
         self.primaryGamma() = value;
      },
      cppCLASS::component_t::documentation("primary_gamma").data()
   );

   // shortcut: get/set simpleMaxwellianFission
   object.def_property(
      "simple_maxwellian_fission",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.simpleMaxwellianFission();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.simpleMaxwellianFission())> &value)
      {
         self.simpleMaxwellianFission() = value;
      },
      cppCLASS::component_t::documentation("simple_maxwellian_fission").data()
   );

   // shortcut: get/set spin
   object.def_property(
      "spin",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.spin();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.spin())> &value)
      {
         self.spin() = value;
      },
      cppCLASS::component_t::documentation("spin").data()
   );

   // shortcut: get/set weightedFunctionals
   object.def_property(
      "weighted_functionals",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.weightedFunctionals();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.weightedFunctionals())> &value)
      {
         self.weightedFunctionals() = value;
      },
      cppCLASS::component_t::documentation("weighted_functionals").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
