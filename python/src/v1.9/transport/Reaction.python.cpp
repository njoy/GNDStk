
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
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::Reaction;

   // create the component
   python::class_<Component> component(
      module,
      Component::className(),
      Component::help().c_str()
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
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "ENDF_MT",
         &Component::ENDF_MT,
         Component::help("ENDF_MT").c_str()
      )
      .def_property_readonly(
         "fissionGenre",
         &Component::fissionGenre,
         Component::help("fissionGenre").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label").c_str()
      )
      .def_property_readonly(
         "crossSection",
         &Component::crossSection,
         Component::help("crossSection").c_str()
      )
   ;
}

} // namespace transport
} // namespace v1_9
