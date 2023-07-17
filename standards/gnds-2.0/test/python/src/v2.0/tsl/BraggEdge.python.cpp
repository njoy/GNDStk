
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/BraggEdge.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// wrapper for tsl::BraggEdge
void wrapBraggEdge(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = tsl::BraggEdge;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "BraggEdge",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const tsl::BraggEnergy &,
         const tsl::StructureFactor &
      >(),
      py::arg("label"),
      py::arg("bragg_energy"),
      py::arg("structure_factor"),
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

   // get/set BraggEnergy
   object.def_property(
      "bragg_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.BraggEnergy();
      },
      [](cppCLASS &self, const tsl::BraggEnergy &value)
      {
         self.BraggEnergy() = value;
      },
      cppCLASS::component_t::documentation("bragg_energy").data()
   );

   // get/set structureFactor
   object.def_property(
      "structure_factor",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.structureFactor();
      },
      [](cppCLASS &self, const tsl::StructureFactor &value)
      {
         self.structureFactor() = value;
      },
      cppCLASS::component_t::documentation("structure_factor").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_tsl
} // namespace python_v2_0
