
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/IncidentEnergies.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// IncidentEnergies wrapper
void wrapIncidentEnergies(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::IncidentEnergies;

   // create the component
   python::class_<Component> component(
      module,
      "IncidentEnergies",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::IncidentEnergy> &
         >(),
         python::arg("incident_energy"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "incident_energy",
         [](const Component &self) { return self.incidentEnergy(); },
         Component::documentation("incident_energy").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
