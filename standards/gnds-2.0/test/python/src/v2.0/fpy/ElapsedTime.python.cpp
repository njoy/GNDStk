
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fpy/ElapsedTime.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// wrapper for fpy::ElapsedTime
void wrapElapsedTime(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fpy::ElapsedTime;
   using _t = std::variant<
      fpy::Yields,
      fpy::IncidentEnergies
   >;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ElapsedTime",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const fpy::Time &,
         const _t &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("time"),
      py::arg("_yieldsincident_energies"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set time
   object.def_property(
      "time",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.time();
      },
      [](cppCLASS &self, const fpy::Time &value)
      {
         self.time() = value;
      },
      cppCLASS::component_t::documentation("time").data()
   );

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

   object.def_property(
      "incident_energies",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.incidentEnergies();
      },
      [](cppCLASS &self, const fpy::IncidentEnergies &value)
      {
         self.incidentEnergies() = value;
      },
      cppCLASS::component_t::documentation("incident_energies").data()
   );

   object.def_property(
      "_yieldsincident_energies",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self._yieldsincidentEnergies();
      },
      [](cppCLASS &self, const _t &value)
      {
         self._yieldsincidentEnergies() = value;
      },
      cppCLASS::component_t::documentation("_yieldsincident_energies").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fpy
} // namespace python_v2_0
