
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fpy/ElapsedTime.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// ElapsedTime wrapper
void wrapElapsedTime(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fpy::ElapsedTime;
   using _t = std::variant<
      fpy::IncidentEnergies,
      fpy::Yields
   >;

   // create the component
   python::class_<Component> component(
      module,
      "ElapsedTime",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const fpy::Time &,
            const _t &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("time"),
         python::arg("_incident_energiesyields"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "time",
         python::overload_cast<>(&Component::time),
         Component::documentation("time").data()
      )
      .def_property_readonly(
         "incident_energies",
         python::overload_cast<>(&Component::incidentEnergies),
         Component::documentation("incident_energies").data()
      )
      .def_property_readonly(
         "yields",
         python::overload_cast<>(&Component::yields),
         Component::documentation("yields").data()
      )
      .def_property_readonly(
         "_incident_energiesyields",
         python::overload_cast<>(&Component::_incidentEnergiesyields),
         Component::documentation("_incident_energiesyields").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0