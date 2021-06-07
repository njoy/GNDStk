
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/ReactionSuite.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// ReactionSuite wrapper
void wrapReactionSuite(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::ReactionSuite;

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
            const XMLName &,
            const XMLName &,
            const enums::Interaction &,
            const XMLName &,
            const enums::Frame &,
            const XMLName &,
            const std::optional<transport::Reactions> &
         >(),
         python::arg("evaluation"),
         python::arg("format"),
         python::arg("interaction"),
         python::arg("projectile"),
         python::arg("projectileFrame"),
         python::arg("target"),
         python::arg("reactions"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "evaluation",
         &Component::evaluation,
         Component::help("evaluation")
      )
      .def_property_readonly(
         "format",
         &Component::format,
         Component::help("format")
      )
      .def_property_readonly(
         "interaction",
         &Component::interaction,
         Component::help("interaction")
      )
      .def_property_readonly(
         "projectile",
         &Component::projectile,
         Component::help("projectile")
      )
      .def_property_readonly(
         "projectileFrame",
         &Component::projectileFrame,
         Component::help("projectileFrame")
      )
      .def_property_readonly(
         "target",
         &Component::target,
         Component::help("target")
      )
      .def_property_readonly(
         "reactions",
         &Component::reactions,
         Component::help("reactions")
      )
   ;
}

} // namespace transport
} // namespace v1_9
