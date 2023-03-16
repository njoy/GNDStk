
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/resonances/ResonanceReactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// ResonanceReactions wrapper
void wrapResonanceReactions(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = resonances::ResonanceReactions;

   // create the component
   python::class_<Component> component(
      module,
      "ResonanceReactions",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<resonances::ResonanceReaction> &
         >(),
         python::arg("resonance_reaction"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "resonance_reaction",
         python::overload_cast<>(&Component::resonanceReaction),
         Component::documentation("resonance_reaction").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0
