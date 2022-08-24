
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/tsl/ScatteringAtom.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// ScatteringAtom wrapper
void wrapScatteringAtom(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = tsl::ScatteringAtom;

   // create the component
   python::class_<Component> component(
      module,
      "ScatteringAtom",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Integer32 &,
            const XMLName &,
            const bool &,
            const tsl::BoundAtomCrossSection &,
            const std::optional<tsl::CoherentAtomCrossSection> &,
            const std::optional<tsl::DistinctScatteringKernel> &,
            const std::optional<tsl::E_critical> &,
            const tsl::E_max &,
            const ambiguousNamespace::Mass &,
            const tsl::SelfScatteringKernel &
         >(),
         python::arg("number_per_molecule"),
         python::arg("pid"),
         python::arg("primary_scatterer"),
         python::arg("bound_atom_cross_section"),
         python::arg("coherent_atom_cross_section") = std::nullopt,
         python::arg("distinct_scattering_kernel") = std::nullopt,
         python::arg("e_critical") = std::nullopt,
         python::arg("e_max"),
         python::arg("mass"),
         python::arg("self_scattering_kernel"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "number_per_molecule",
         &Component::numberPerMolecule,
         Component::documentation("number_per_molecule").data()
      )
      .def_property_readonly(
         "pid",
         &Component::pid,
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "primary_scatterer",
         &Component::primaryScatterer,
         Component::documentation("primary_scatterer").data()
      )
      .def_property_readonly(
         "bound_atom_cross_section",
         python::overload_cast<>(&Component::boundAtomCrossSection),
         Component::documentation("bound_atom_cross_section").data()
      )
      .def_property_readonly(
         "coherent_atom_cross_section",
         python::overload_cast<>(&Component::coherentAtomCrossSection),
         Component::documentation("coherent_atom_cross_section").data()
      )
      .def_property_readonly(
         "distinct_scattering_kernel",
         python::overload_cast<>(&Component::distinctScatteringKernel),
         Component::documentation("distinct_scattering_kernel").data()
      )
      .def_property_readonly(
         "e_critical",
         python::overload_cast<>(&Component::e_critical),
         Component::documentation("e_critical").data()
      )
      .def_property_readonly(
         "e_max",
         python::overload_cast<>(&Component::e_max),
         Component::documentation("e_max").data()
      )
      .def_property_readonly(
         "mass",
         python::overload_cast<>(&Component::mass),
         Component::documentation("mass").data()
      )
      .def_property_readonly(
         "self_scattering_kernel",
         python::overload_cast<>(&Component::selfScatteringKernel),
         Component::documentation("self_scattering_kernel").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0