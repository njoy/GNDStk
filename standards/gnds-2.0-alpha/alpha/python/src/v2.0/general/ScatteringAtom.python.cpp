
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ScatteringAtom.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ScatteringAtom
void wrapScatteringAtom(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::ScatteringAtom;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ScatteringAtom",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const std::optional<bool> &,
         const general::Mass &,
         const std::optional<general::E_critical> &,
         const general::E_max &,
         const general::BoundAtomCrossSection &,
         const general::SelfScatteringKernel &,
         const std::optional<general::T_effective> &
      >(),
      py::arg("pid"),
      py::arg("number_per_molecule"),
      py::arg("primary_scatterer") = std::nullopt,
      py::arg("mass"),
      py::arg("e_critical") = std::nullopt,
      py::arg("e_max"),
      py::arg("bound_atom_cross_section"),
      py::arg("self_scattering_kernel"),
      py::arg("t_effective") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set numberPerMolecule
   object.def_property(
      "number_per_molecule",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.numberPerMolecule();
      },
      [](cppCLASS &self, const int &value)
      {
         self.numberPerMolecule() = value;
      },
      cppCLASS::component_t::documentation("number_per_molecule").data()
   );

   // get/set primaryScatterer
   object.def_property(
      "primary_scatterer",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.primaryScatterer();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.primaryScatterer() = value;
      },
      cppCLASS::component_t::documentation("primary_scatterer").data()
   );

   // get/set mass
   object.def_property(
      "mass",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mass();
      },
      [](cppCLASS &self, const general::Mass &value)
      {
         self.mass() = value;
      },
      cppCLASS::component_t::documentation("mass").data()
   );

   // get/set e_critical
   object.def_property(
      "e_critical",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.e_critical();
      },
      [](cppCLASS &self, const std::optional<general::E_critical> &value)
      {
         self.e_critical() = value;
      },
      cppCLASS::component_t::documentation("e_critical").data()
   );

   // get/set e_max
   object.def_property(
      "e_max",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.e_max();
      },
      [](cppCLASS &self, const general::E_max &value)
      {
         self.e_max() = value;
      },
      cppCLASS::component_t::documentation("e_max").data()
   );

   // get/set boundAtomCrossSection
   object.def_property(
      "bound_atom_cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.boundAtomCrossSection();
      },
      [](cppCLASS &self, const general::BoundAtomCrossSection &value)
      {
         self.boundAtomCrossSection() = value;
      },
      cppCLASS::component_t::documentation("bound_atom_cross_section").data()
   );

   // get/set selfScatteringKernel
   object.def_property(
      "self_scattering_kernel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.selfScatteringKernel();
      },
      [](cppCLASS &self, const general::SelfScatteringKernel &value)
      {
         self.selfScatteringKernel() = value;
      },
      cppCLASS::component_t::documentation("self_scattering_kernel").data()
   );

   // get/set T_effective
   object.def_property(
      "t_effective",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.T_effective();
      },
      [](cppCLASS &self, const std::optional<general::T_effective> &value)
      {
         self.T_effective() = value;
      },
      cppCLASS::component_t::documentation("t_effective").data()
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

   // shortcut: get/set SCTApproximation
   object.def_property(
      "sctapproximation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.SCTApproximation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.SCTApproximation())> &value)
      {
         self.SCTApproximation() = value;
      },
      cppCLASS::component_t::documentation("sctapproximation").data()
   );

   // shortcut: get/set freeGasApproximation
   object.def_property(
      "free_gas_approximation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.freeGasApproximation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.freeGasApproximation())> &value)
      {
         self.freeGasApproximation() = value;
      },
      cppCLASS::component_t::documentation("free_gas_approximation").data()
   );

   // shortcut: get/set gridded3d
   object.def_property(
      "gridded3d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gridded3d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.gridded3d())> &value)
      {
         self.gridded3d() = value;
      },
      cppCLASS::component_t::documentation("gridded3d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
