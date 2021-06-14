
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/CrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// CrossSection wrapper
void wrapCrossSection(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::CrossSection;
   using VARIANT = std::variant<
      njoy::GNDStk::v1_9::containers::XYs1d,
      njoy::GNDStk::v1_9::containers::Regions1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "CrossSection",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<VARIANT> &
         >(),
         python::arg("choice"),
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "xys1d",
         &Component::XYs1d,
         Component::documentation("xys1d").c_str()
      )
      .def_property_readonly(
         "regions1d",
         &Component::regions1d,
         Component::documentation("regions1d").c_str()
      )
      .def_property_readonly(
         "choice",
         &Component::choice,
         Component::documentation("choice").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace transport
} // namespace v1_9
