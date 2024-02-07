
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/IncidentEnergies.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::IncidentEnergies
void wrapIncidentEnergies(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::IncidentEnergies;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "IncidentEnergies",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::IncidentEnergy> &
      >(),
      pybind11::arg("incident_energy"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set incidentEnergy
   object.def_property(
      "incident_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.incidentEnergy();
      },
      [](cppCLASS &self, const std::vector<general::IncidentEnergy> &value)
      {
         self.incidentEnergy() = value;
      },
      cppCLASS::component_t::documentation("incident_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS