
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/CoulombPlusNuclearElastic.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::CoulombPlusNuclearElastic
void wrapCoulombPlusNuclearElastic(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::CoulombPlusNuclearElastic;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "CoulombPlusNuclearElastic",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<bool> &,
         const std::optional<general::RutherfordScattering> &,
         const std::optional<general::NuclearAmplitudeExpansion> &,
         const std::optional<general::NuclearPlusInterference> &
      >(),
      pybind11::arg("label"),
      pybind11::arg("href") = std::nullopt,
      pybind11::arg("pid") = std::nullopt,
      pybind11::arg("product_frame") = std::nullopt,
      pybind11::arg("identical_particles") = std::nullopt,
      pybind11::arg("rutherford_scattering") = std::nullopt,
      pybind11::arg("nuclear_amplitude_expansion") = std::nullopt,
      pybind11::arg("nuclear_plus_interference") = std::nullopt,
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

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
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
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set identicalParticles
   object.def_property(
      "identical_particles",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.identicalParticles();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.identicalParticles() = value;
      },
      cppCLASS::component_t::documentation("identical_particles").data()
   );

   // get/set RutherfordScattering
   object.def_property(
      "rutherford_scattering",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.RutherfordScattering();
      },
      [](cppCLASS &self, const std::optional<general::RutherfordScattering> &value)
      {
         self.RutherfordScattering() = value;
      },
      cppCLASS::component_t::documentation("rutherford_scattering").data()
   );

   // get/set nuclearAmplitudeExpansion
   object.def_property(
      "nuclear_amplitude_expansion",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclearAmplitudeExpansion();
      },
      [](cppCLASS &self, const std::optional<general::NuclearAmplitudeExpansion> &value)
      {
         self.nuclearAmplitudeExpansion() = value;
      },
      cppCLASS::component_t::documentation("nuclear_amplitude_expansion").data()
   );

   // get/set nuclearPlusInterference
   object.def_property(
      "nuclear_plus_interference",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclearPlusInterference();
      },
      [](cppCLASS &self, const std::optional<general::NuclearPlusInterference> &value)
      {
         self.nuclearPlusInterference() = value;
      },
      cppCLASS::component_t::documentation("nuclear_plus_interference").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
