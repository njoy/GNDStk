
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/Reaction.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// Reaction wrapper
void wrapReaction(python::module &module)
{
   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::Reaction;

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
            const Integer32 &,
            const std::optional<XMLName> &,
            const XMLName &,
            const transport::CrossSection &
         >(),
         python::arg("ENDF_MT"),
         python::arg("fissionGenre"),
         python::arg("label"),
         python::arg("crossSection"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "ENDF_MT",
         &Component::ENDF_MT,
         Component::help("ENDF_MT")
      )
      .def_property_readonly(
         "fissionGenre",
         &Component::fissionGenre,
         Component::help("fissionGenre")
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label")
      )
      .def_property_readonly(
         "crossSection",
         &Component::crossSection,
         Component::help("crossSection")
      )
   ;
}

} // namespace transport
} // namespace v1_9
