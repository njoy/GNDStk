
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/IncompleteReactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// IncompleteReactions wrapper
void wrapIncompleteReactions(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::IncompleteReactions;

   // create the component
   python::class_<Component> component(
      module,
      "IncompleteReactions",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<transport::Reaction> &
         >(),
         python::arg("reaction") = std::nullopt,
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
} // namespace python_v2_0
