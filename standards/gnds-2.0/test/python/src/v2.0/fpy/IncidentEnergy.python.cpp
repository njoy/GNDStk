
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fpy/IncidentEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// wrapper for fpy::IncidentEnergy
void wrapIncidentEnergy(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fpy::IncidentEnergy;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "IncidentEnergy",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const fpy::Energy &,
         const fpy::Yields &
      >(),
      py::arg("label"),
      py::arg("energy"),
      py::arg("yields"),
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

   // get/set energy
   object.def_property(
      "energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.energy();
      },
      [](cppCLASS &self, const fpy::Energy &value)
      {
         self.energy() = value;
      },
      cppCLASS::component_t::documentation("energy").data()
   );

   // get/set yields
   object.def_property(
      "yields",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.yields();
      },
      [](cppCLASS &self, const fpy::Yields &value)
      {
         self.yields() = value;
      },
      cppCLASS::component_t::documentation("yields").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fpy
} // namespace python_v2_0
