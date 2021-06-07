
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/Reactions.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// Reactions wrapper
void wrapReactions(python::module &module)
{
   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::Reactions;

   // create the component
   python::class_<Component> component(
      module,
      Component::className(),
      Component::help()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<transport::Reaction> &
         >(),
         python::arg("reaction"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "reaction",
         &Component::reaction,
         Component::help("reaction")
      )
   ;
}

} // namespace transport
} // namespace v1_9
