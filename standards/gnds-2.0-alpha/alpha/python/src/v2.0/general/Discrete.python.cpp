
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Discrete.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Discrete
void wrapDiscrete(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Discrete;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Discrete",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<std::string> &,
         const general::Intensity &,
         const general::Energy &,
         const std::optional<general::InternalConversionCoefficients> &,
         const std::optional<general::PositronEmissionIntensity> &
      >(),
      py::arg("type") = std::nullopt,
      py::arg("intensity"),
      py::arg("energy"),
      py::arg("internal_conversion_coefficients") = std::nullopt,
      py::arg("positron_emission_intensity") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set type
   object.def_property(
      "type",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.type();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.type() = value;
      },
      cppCLASS::component_t::documentation("type").data()
   );

   // get/set intensity
   object.def_property(
      "intensity",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.intensity();
      },
      [](cppCLASS &self, const general::Intensity &value)
      {
         self.intensity() = value;
      },
      cppCLASS::component_t::documentation("intensity").data()
   );

   // get/set energy
   object.def_property(
      "energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.energy();
      },
      [](cppCLASS &self, const general::Energy &value)
      {
         self.energy() = value;
      },
      cppCLASS::component_t::documentation("energy").data()
   );

   // get/set internalConversionCoefficients
   object.def_property(
      "internal_conversion_coefficients",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.internalConversionCoefficients();
      },
      [](cppCLASS &self, const std::optional<general::InternalConversionCoefficients> &value)
      {
         self.internalConversionCoefficients() = value;
      },
      cppCLASS::component_t::documentation("internal_conversion_coefficients").data()
   );

   // get/set positronEmissionIntensity
   object.def_property(
      "positron_emission_intensity",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.positronEmissionIntensity();
      },
      [](cppCLASS &self, const std::optional<general::PositronEmissionIntensity> &value)
      {
         self.positronEmissionIntensity() = value;
      },
      cppCLASS::component_t::documentation("positron_emission_intensity").data()
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
