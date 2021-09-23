
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
      Component::documentation().data()
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
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "evaluation",
         &Component::evaluation,
         Component::documentation("evaluation").data()
      )
      .def_property_readonly(
         "format",
         &Component::format,
         Component::documentation("format").data()
      )
      .def_property_readonly(
         "interaction",
         &Component::interaction,
         Component::documentation("interaction").data()
      )
      .def_property_readonly(
         "projectile",
         &Component::projectile,
         Component::documentation("projectile").data()
      )
      .def_property_readonly(
         "projectile_frame",
         &Component::projectileFrame,
         Component::documentation("projectile_frame").data()
      )
      .def_property_readonly(
         "target",
         &Component::target,
         Component::documentation("target").data()
      )
      .def_property_readonly(
         "reactions",
         python::overload_cast<>(&Component::reactions),
         Component::documentation("reactions").data()
      )
      .def_static(

        "from_file",
        [] ( const std::string& filename ) -> Component {

          using namespace njoy::GNDStk::core;
          Tree tree( filename );

          return Component( tree( child::reactionSuite ) );
        },
        python::arg( "filename" ),
        "Read a reaction suite from an XML or json file\n\n"
        "An exception is raised if something goes wrong while reading the\n"
        "component\n\n"
        "Arguments:\n"
        "    filename    the name of the file"
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9
