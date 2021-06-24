
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/ReactionSuite.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_transport {

// ReactionSuite wrapper
void wrapReactionSuite(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = transport::ReactionSuite;

   // create the component
   python::class_<Component> component(
      module,
      "ReactionSuite",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const std::optional<enums::Interaction> &,
            const XMLName &,
            const enums::Frame &,
            const XMLName &,
            const std::optional<transport::Reactions> &
         >(),
         python::arg("evaluation"),
         python::arg("format"),
         python::arg("interaction") = std::nullopt,
         python::arg("projectile"),
         python::arg("projectile_frame"),
         python::arg("target"),
         python::arg("reactions") = std::nullopt,
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "evaluation",
         &Component::evaluation,
         Component::documentation("evaluation").c_str()
      )
      .def_property_readonly(
         "format",
         &Component::format,
         Component::documentation("format").c_str()
      )
      .def_property_readonly(
         "interaction",
         &Component::interaction,
         Component::documentation("interaction").c_str()
      )
      .def_property_readonly(
         "projectile",
         &Component::projectile,
         Component::documentation("projectile").c_str()
      )
      .def_property_readonly(
         "projectile_frame",
         &Component::projectileFrame,
         Component::documentation("projectile_frame").c_str()
      )
      .def_property_readonly(
         "target",
         &Component::target,
         Component::documentation("target").c_str()
      )
      .def_property_readonly(
         "reactions",
         python::overload_cast<>(&Component::reactions),
         Component::documentation("reactions").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9
