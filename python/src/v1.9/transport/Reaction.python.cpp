
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/Reaction.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_transport {

// Reaction wrapper
void wrapReaction(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = transport::Reaction;

   // create the component
   python::class_<Component> component(
      module,
      "Reaction",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Integer32 &,
            const std::optional<XMLName> &,
            const XMLName &,
            const transport::CrossSection &
         >(),
         python::arg("endf_mt"),
         python::arg("fission_genre") = std::nullopt,
         python::arg("label"),
         python::arg("cross_section"),
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "endf_mt",
         &Component::ENDF_MT,
         Component::documentation("endf_mt").c_str()
      )
      .def_property_readonly(
         "fission_genre",
         &Component::fissionGenre,
         Component::documentation("fission_genre").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").c_str()
      )
      .def_property_readonly(
         "cross_section",
         python::overload_cast<>(&Component::crossSection),
         Component::documentation("cross_section").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9
