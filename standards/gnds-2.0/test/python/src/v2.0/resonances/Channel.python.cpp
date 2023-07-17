
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/resonances/Channel.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// wrapper for resonances::Channel
void wrapChannel(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = resonances::Channel;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Channel",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const std::string &,
         const Integer32 &,
         const Fraction32 &,
         const std::optional<Float64> &,
         const Integer32 &,
         const std::optional<resonances::ExternalRMatrix> &,
         const std::optional<resonances::ScatteringRadius> &,
         const std::optional<resonances::HardSphereRadius> &
      >(),
      py::arg("label"),
      py::arg("resonance_reaction"),
      py::arg("l"),
      py::arg("channel_spin"),
      py::arg("boundary_condition_value") = std::nullopt,
      py::arg("column_index"),
      py::arg("external_rmatrix") = std::nullopt,
      py::arg("scattering_radius") = std::nullopt,
      py::arg("hard_sphere_radius") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set resonanceReaction
   object.def_property(
      "resonance_reaction",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonanceReaction();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.resonanceReaction() = value;
      },
      cppCLASS::component_t::documentation("resonance_reaction").data()
   );

   // get/set L
   object.def_property(
      "l",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.L();
      },
      [](cppCLASS &self, const Integer32 &value)
      {
         self.L() = value;
      },
      cppCLASS::component_t::documentation("l").data()
   );

   // get/set channelSpin
   object.def_property(
      "channel_spin",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.channelSpin();
      },
      [](cppCLASS &self, const Fraction32 &value)
      {
         self.channelSpin() = value;
      },
      cppCLASS::component_t::documentation("channel_spin").data()
   );

   // get/set boundaryConditionValue
   object.def_property(
      "boundary_condition_value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.boundaryConditionValue();
      },
      [](cppCLASS &self, const std::optional<Float64> &value)
      {
         self.boundaryConditionValue() = value;
      },
      cppCLASS::component_t::documentation("boundary_condition_value").data()
   );

   // get/set columnIndex
   object.def_property(
      "column_index",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.columnIndex();
      },
      [](cppCLASS &self, const Integer32 &value)
      {
         self.columnIndex() = value;
      },
      cppCLASS::component_t::documentation("column_index").data()
   );

   // get/set externalRMatrix
   object.def_property(
      "external_rmatrix",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.externalRMatrix();
      },
      [](cppCLASS &self, const std::optional<resonances::ExternalRMatrix> &value)
      {
         self.externalRMatrix() = value;
      },
      cppCLASS::component_t::documentation("external_rmatrix").data()
   );

   // get/set scatteringRadius
   object.def_property(
      "scattering_radius",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.scatteringRadius();
      },
      [](cppCLASS &self, const std::optional<resonances::ScatteringRadius> &value)
      {
         self.scatteringRadius() = value;
      },
      cppCLASS::component_t::documentation("scattering_radius").data()
   );

   // get/set hardSphereRadius
   object.def_property(
      "hard_sphere_radius",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.hardSphereRadius();
      },
      [](cppCLASS &self, const std::optional<resonances::HardSphereRadius> &value)
      {
         self.hardSphereRadius() = value;
      },
      cppCLASS::component_t::documentation("hard_sphere_radius").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_resonances
} // namespace python_v2_0
