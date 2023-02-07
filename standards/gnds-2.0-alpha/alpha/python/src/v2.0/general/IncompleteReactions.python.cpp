
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/IncompleteReactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// IncompleteReactions wrapper
void wrapIncompleteReactions(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::IncompleteReactions;

   // create the component
   python::class_<Component> component(
      module, "IncompleteReactions",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::Reaction> &
         >(),
         python::arg("reaction"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "reaction",
         [](const Component &self)
         {
            return self.reaction();
         },
         Component::component_t::documentation("reaction").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
