
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "proto/v1.9/transport/Reactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_transport {

// Reactions wrapper
void wrapReactions(python::module &module)
{
   using namespace proto;
   using namespace proto::v1_9;

   // type aliases
   using Component = transport::Reactions;

   // create the component
   python::class_<Component> component(
      module,
      "Reactions",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<transport::Reaction> &
         >(),
         python::arg("reaction"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "reaction",
         [](const Component &self) { return self.reaction(); },
         Component::documentation("reaction").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9