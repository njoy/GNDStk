
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/Reactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// Reactions wrapper
void wrapReactions(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::Reactions;

   // create the component
   python::class_<Component> component(
      module,
      "Reactions",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<transport::Reaction> &
         >(),
         python::arg("reaction"),
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "reaction",
         &Component::reaction,
         Component::documentation("reaction").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace transport
} // namespace v1_9
