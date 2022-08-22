
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Discrete.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Discrete wrapper
void wrapDiscrete(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Discrete;

   // create the component
   python::class_<Component> component(
      module,
      "Discrete",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const pops::Energy &,
            const pops::Intensity &,
            const std::optional<pops::InternalConversionCoefficients> &,
            const std::optional<pops::InternalPairFormationCoefficient> &,
            const std::optional<pops::PhotonEmissionProbabilities> &
         >(),
         python::arg("type") = std::nullopt,
         python::arg("energy"),
         python::arg("intensity"),
         python::arg("internal_conversion_coefficients") = std::nullopt,
         python::arg("internal_pair_formation_coefficient") = std::nullopt,
         python::arg("photon_emission_probabilities") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "type",
         &Component::type,
         Component::documentation("type").data()
      )
      .def_property_readonly(
         "energy",
         python::overload_cast<>(&Component::energy),
         Component::documentation("energy").data()
      )
      .def_property_readonly(
         "intensity",
         python::overload_cast<>(&Component::intensity),
         Component::documentation("intensity").data()
      )
      .def_property_readonly(
         "internal_conversion_coefficients",
         python::overload_cast<>(&Component::internalConversionCoefficients),
         Component::documentation("internal_conversion_coefficients").data()
      )
      .def_property_readonly(
         "internal_pair_formation_coefficient",
         python::overload_cast<>(&Component::internalPairFormationCoefficient),
         Component::documentation("internal_pair_formation_coefficient").data()
      )
      .def_property_readonly(
         "photon_emission_probabilities",
         python::overload_cast<>(&Component::photonEmissionProbabilities),
         Component::documentation("photon_emission_probabilities").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
