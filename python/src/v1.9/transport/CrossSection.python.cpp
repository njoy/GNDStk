
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

namespace python_v1_9 {
namespace python_transport {

// CrossSection wrapper
void wrapCrossSection(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = transport::CrossSection;
   using VARIANT = std::variant<
      containers::XYs1d,
      containers::Regions1d
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
         "choice",
         python::overload_cast<>(&Component::choice),
         Component::documentation("choice").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9
